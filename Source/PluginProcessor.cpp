//==============================================================================
//
//  Copyright 2025 Juan Carlos Blancas
//  This file is part of JCBImager and is licensed under the GNU General Public License v3.0 or later.
//
//==============================================================================

//==============================================================================
// INCLUDES
//==============================================================================
// Archivos del proyecto
#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Helpers/UTF8Helper.h"

#//define JCB_DEBUG_METERS
#//define JCB_DEBUG_AUDIO_WATCH
#//define JCB_DEBUG_WATCHDOG
#//define JCB_DEBUG_TRACE_SILENCE
#//define JCB_DISABLE_SANITIZER

[[maybe_unused]] static inline float blockMaxAbs (const float* x, int n) noexcept
{
    float m = 0.f;
    for (int i = 0; i < n; ++i) { float a = std::abs(x[i]); if (a > m) m = a; }
    return m;
}

// Overload for Gen's t_sample* (usually double*)
[[maybe_unused]] static inline float blockMaxAbs (const t_sample* x, int n) noexcept
{
    double m = 0.0;
    for (int i = 0; i < n; ++i) { double a = std::abs(x[i]); if (a > m) m = a; }
    return static_cast<float>(m);
}

//==============================================================================
// CONSTRUCTOR Y DESTRUCTOR
//==============================================================================
JCBImagerAudioProcessor::JCBImagerAudioProcessor()
    : juce::AudioProcessor(createBusesProperties()),
      apvts(*this, nullptr, "PARAMETERS", createParameterLayout()),  // nullptr = no automatic undo (proven solution tested on jr-granular)
      m_CurrentBufferSize(0),
      editorSize(1260, 360),
      lastPreset(0),
      currentProgram(-1)
{
    // Configurar límites del guiUndoManager para optimizar rendimiento
    guiUndoManager.setMaxNumberOfStoredUnits(0, 20); // Solo 20 transacciones exactas (ahorro de memoria)


    // Inicializar Gen~ state
    m_PluginState = (CommonState *)JCBImager::create(44100, 64);
    JCBImager::reset(m_PluginState);

    // Inicializar buffers de Gen~
    m_InputBuffers = new t_sample *[JCBImager::num_inputs()];
    m_OutputBuffers = new t_sample *[JCBImager::num_outputs()];

    for (int i = 0; i < JCBImager::num_inputs(); i++) {
        m_InputBuffers[i] = nullptr;
    }
    for (int i = 0; i < JCBImager::num_outputs(); i++) {
        m_OutputBuffers[i] = nullptr;
    }

    // Vincular listeners de parámetros de gen~ a APVTS
    for (int i = 0; i < JCBImager::num_params(); i++)
    {
        auto name = juce::String(JCBImager::getparametername(m_PluginState, i));
        apvts.addParameterListener(name, this);
    }

    // IMPORTANTE: Sincronizar valores iniciales con Gen~ usando valores REALES del APVTS
    for (int i = 0; i < JCBImager::num_params(); i++)
    {
        auto paramName = juce::String(JCBImager::getparametername(m_PluginState, i));
        if (auto* p = apvts.getParameter(paramName))
        {
            float v = 0.0f;
            if (auto* pf = dynamic_cast<juce::AudioParameterFloat*>(p))      v = pf->get();
            else if (auto* pb = dynamic_cast<juce::AudioParameterBool*>(p))   v = pb->get() ? 1.0f : 0.0f;
            else                                                             v = apvts.getRawParameterValue(paramName)->load();
            JCBImager::setparameter(m_PluginState, i, v, nullptr);
        }
    }
}

JCBImagerAudioProcessor::~JCBImagerAudioProcessor()
{
    // CRÍTICO: Primero indicar que estamos destruyendo para evitar race conditions
    isBeingDestroyed = true;

    // Detener timer AAX inmediatamente (antes que cualquier otra cosa)
    #if JucePlugin_Build_AAX
    stopTimer();
    // Pequeña espera para asegurar que el timer callback no esté ejecutándose
    juce::Thread::sleep(10);
    #endif

    // Destruir listeners de parámetros del apvts
    for (int i = 0; i < JCBImager::num_params(); i++)
    {
        auto name = juce::String(JCBImager::getparametername(m_PluginState, i));
        apvts.removeParameterListener(name, this);
    }

    // Limpiar buffers con protección nullptr
    if (m_InputBuffers != nullptr) {
        for (int i = 0; i < JCBImager::num_inputs(); i++) {
            if (m_InputBuffers[i] != nullptr) {
                delete[] m_InputBuffers[i];
                m_InputBuffers[i] = nullptr;
            }
        }
        delete[] m_InputBuffers;
        m_InputBuffers = nullptr;
    }

    if (m_OutputBuffers != nullptr) {
        for (int i = 0; i < JCBImager::num_outputs(); i++) {
            if (m_OutputBuffers[i] != nullptr) {
                delete[] m_OutputBuffers[i];
                m_OutputBuffers[i] = nullptr;
            }
        }
        delete[] m_OutputBuffers;
        m_OutputBuffers = nullptr;
    }

    // Destruir Gen~ state al final
    if (m_PluginState != nullptr) {
        JCBImager::destroy(m_PluginState);
        m_PluginState = nullptr;
    }
}

//==============================================================================
// MÉTODOS PRINCIPALES DEL AUDIOPROCESSOR
//==============================================================================
void JCBImagerAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    // Configuración de canales en modo debug eliminada para release

    // Inicializar sample rate y vector size
    m_PluginState->sr = sampleRate;
    m_PluginState->vs = samplesPerBlock;

    // Callbacks para visualización se añadirán cuando se implemente el display de reverb

    // Pre-asignar buffers con tamaño máximo esperado para evitar allocations en audio thread
    // Usar un tamaño seguro que cubra la mayoría de casos (16384 samples es común máximo para hosts modernos)
    const long maxExpectedBufferSize = juce::jmax(static_cast<long>(samplesPerBlock), 16384L);
    assureBufferSize(maxExpectedBufferSize);

    // Pre-asignar vectors de waveform data para evitar resize en audio thread
    {
        std::lock_guard<std::mutex> lock(waveformMutex);
        const size_t maxWaveformSize = static_cast<size_t>(juce::jmax<int>(maxExpectedBufferSize, 16384));
        currentInputSamples.assign(maxWaveformSize, 0.0f);
        currentProcessedSamples.assign(maxWaveformSize, 0.0f);
    }

    // 3) ***Clave***: sincroniza SR/VS con Gen y re-dimensiona sus delays/constantes
    //    Esto asegura que Gen use el sampleRate real del host (48k si el proyecto es 48k)
    JCBImager::reset (m_PluginState);

    // Cachear indices de gen para evitar bucles por nombre
    genIdxZBypass = -1;
    genIdxDryWet  = -1;
    genIdxFreeze  = -1;
    genIdxMuteLow = genIdxMuteMid = genIdxMuteHigh = -1;
    genIdxSoloLow = genIdxSoloMid = genIdxSoloHigh = -1;
    genIndexByName.clear();
    for (int i = 0; i < JCBImager::num_params(); ++i)
    {
        const char* raw = JCBImager::getparametername(m_PluginState, i);
        juce::String name(raw ? raw : "");
        genIndexByName[name] = i;
        if (name == "i_BYPASS") genIdxZBypass = i;
        if (name == "x_DRYWET") genIdxDryWet  = i;
        if (name == "g_FREEZE") genIdxFreeze  = i; // may not exist in Imager
        if      (name == "n_MUTLOW")   genIdxMuteLow  = i;
        else if (name == "o_MUTMED")   genIdxMuteMid  = i;
        else if (name == "p_MUTHIGH")  genIdxMuteHigh = i;
        else if (name == "f_SOLOLOW")  genIdxSoloLow  = i;
        else if (name == "g_SOLOMED")  genIdxSoloMid  = i;
        else if (name == "h_SOLOHIGH") genIdxSoloHigh = i;
    }

    // Reverb: latencia fija (no tiene lookahead)
    setLatencySamples(0);

    // === INICIALIZACIÓN DEL SISTEMA DE BYPASS SUAVE ===
    // Pre-asignar scratch buffers para evitar allocations en audio thread
    ensureScratchCapacity(juce::jmax(static_cast<int>(samplesPerBlock), 4096));

    // Configurar longitud del fade desde bypassFadeMs (7ms por defecto)
    {
        const int lenFromMs = juce::roundToInt(bypassFadeMs * static_cast<float>(sampleRate) / 1000.0f);
        bypassFadeLen = juce::jlimit(128, 512, lenFromMs > 0 ? lenFromMs : 128);
    }
    bypassFadePos = 0;

    // Estado inicial coherente con el host
    const bool hb = isHostBypassed();
    hostBypassMirror.store(hb, std::memory_order_relaxed);
    bypassState = hb ? BypassState::Bypassed : BypassState::Active;
    lastWantsBypass = hb;

    // Initialize atomic meter values
    // CRITICAL: Changed from SmoothedValue to atomic - no reset() needed
    leftInputRMS.store(-100.0f, std::memory_order_relaxed);
    rightInputRMS.store(-100.0f, std::memory_order_relaxed);

    leftOutputRMS.store(-100.0f, std::memory_order_relaxed);
    rightOutputRMS.store(-100.0f, std::memory_order_relaxed);

    // Configurar buffers auxiliares
    trimInputBuffer.setSize(2, juce::jmax(samplesPerBlock, 16384), false, false, true);
    trimInputBuffer.clear();


    // IMPORTANTE: Re-sincronizar todos los parámetros con Gen~ en prepareToPlay
    // Esto asegura que los valores estén correctos cuando el DAW comienza a reproducir
    for (int i = 0; i < JCBImager::num_params(); i++)
    {
        auto paramName = juce::String(JCBImager::getparametername(m_PluginState, i));
        if (auto* param = apvts.getRawParameterValue(paramName)) {
            float value = param->load();
            JCBImager::setparameter(m_PluginState, i, value, nullptr);
        }
    }
    
    // Notify spectrum analyzer of sample rate change
    if (sampleRateChangedCallback) {
        sampleRateChangedCallback(sampleRate);
    }

}

void JCBImagerAudioProcessor::releaseResources()
{
    // Limpiar buffers auxiliares
    trimInputBuffer.setSize(0, 0);
}

//==============================================================================
// PROCESAMIENTO DE AUDIO
//==============================================================================
void JCBImagerAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    juce::ignoreUnused(midiMessages);
    processBlockCommon(buffer, /*hostWantsBypass*/ false);
}

void JCBImagerAudioProcessor::processBlockBypassed(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    juce::ignoreUnused(midiMessages);
    processBlockCommon(buffer, /*hostWantsBypass*/ true);
}

void JCBImagerAudioProcessor::processBlockCommon(juce::AudioBuffer<float>& buffer, bool hostWantsBypass)
{
    juce::ScopedNoDenormals noDenormals;
    const int numSamples = buffer.getNumSamples();
    const int numChannels = buffer.getNumChannels();

    #if defined(JCB_DEBUG_TRACE_SILENCE)
    {
        static int prevNs = -1, prevTrim = -1, prevOuts = -1;
        const int trimCap = trimInputBuffer.getNumSamples();
        const int outs    = JCBImager::num_outputs();
        if (numSamples != prevNs || trimCap != prevTrim || outs != prevOuts)
        {
            DBG("[JCBImager] blk ns=" << numSamples << " trimCap=" << trimCap << " outs=" << outs);
            prevNs = numSamples; prevTrim = trimCap; prevOuts = outs;
        }
        static int prevHostBy = -1, prevState = -1;
        if (prevHostBy != (hostWantsBypass?1:0) || prevState != (int)bypassState)
        {
            DBG("[JCBImager] bypass host=" << (hostWantsBypass?1:0) << " state=" << (int)bypassState);
            prevHostBy = (hostWantsBypass?1:0); prevState = (int)bypassState;
        }
    }
    #endif

    // Si el host manda bloques vacíos (p.ej., al parar), evita alterar estados
    if (numSamples <= 0)
        return;


    // No forzar reset en arranque de reproducción; dejar que el motor continúe suavemente

    // Ajustar buffers auxiliares si es necesario
    assureBufferSize(numSamples);

    if (m_PluginState->vs != numSamples)
        m_PluginState->vs = numSamples;  // sin reset; solo reflejar el vector size actual

    // === 1. SIEMPRE capturar entrada ANTES de procesar (crítico para bypass) ===
    // Importante: usar el número de canales de ENTRADA del bus principal para leer correctamente en layouts 1->2
    ensureScratchCapacity(numSamples);
    float* inL = scratchIn.getWritePointer(0);
    float* inR = scratchIn.getWritePointer(1);
    {
        const int mainInputChannels = getMainBusNumInputChannels();
        const float* srcL = buffer.getReadPointer(0);
        const float* srcR = (mainInputChannels > 1) ? buffer.getReadPointer(1) : srcL;
        std::memcpy(inL, srcL, sizeof(float) * static_cast<size_t>(numSamples));
        // Copiar R de la fuente correcta; si entrada mono, duplicar L
        std::memcpy(inR, srcR, sizeof(float) * static_cast<size_t>(numSamples));
    }
    
    // Capturar la señal de entrada SECA antes de cualquier procesamiento
    captureInputWaveformData(scratchIn, numSamples);


    // === 1.b APLICAR AQUÍ: drenar cambios de parámetros pendientes ===
    drainPendingParamsToGen();

    // Host bypass handled via FSM mix below. No early return.

    // === 2. (reserved) bus layout sync ===

#ifdef JCB_DEBUG_PASSTHROUGH
    // === DEBUG: Passthrough total (no Gen) para aislar host vs Gen ===
    {
        // Rellenar trimInputBuffer desde la entrada capturada para medidores
        trimInputBuffer.setSize(2, numSamples, false, false, true);
        {
            float* tL = trimInputBuffer.getWritePointer(0);
            float* tR = trimInputBuffer.getWritePointer(1);
            std::memcpy(tL, inL, sizeof(float) * static_cast<size_t>(numSamples));
            std::memcpy(tR, inR, sizeof(float) * static_cast<size_t>(numSamples));
        }

        // Copiar entrada a salida respetando layout 1->2 o 2->2
        float* outL = buffer.getWritePointer(0);
        float* outR = (numChannels > 1 ? buffer.getWritePointer(1) : nullptr);
        for (int n = 0; n < numSamples; ++n)
        {
            outL[n] = inL[n];
            if (outR) outR[n] = inR[n];
        }
        

        // Métricas y salida
        updateClipDetection(buffer, buffer);
        updateInputMeters(buffer);
        updateOutputMeters(buffer);
        return;
    }
#endif

    // === 3. Procesar WET con Gen~ (siempre activo) ===
#ifdef JCB_DEBUG_FORCE_WET
    if (genIdxDryWet >= 0)
        JCBImager::setparameter(m_PluginState, genIdxDryWet, 1.0f, nullptr);
#endif
#ifdef JCB_DEBUG_MUTE_OUTPUT
    // Fuerza silencio total para aislar el host
    buffer.clear();
    trimInputBuffer.setSize(2, numSamples, false, false, true);
    {
        float* tL = trimInputBuffer.getWritePointer(0);
        float* tR = trimInputBuffer.getWritePointer(1);
        std::memcpy(tL, inL, sizeof(float) * static_cast<size_t>(numSamples));
        std::memcpy(tR, inR, sizeof(float) * static_cast<size_t>(numSamples));
    }
    updateClipDetection(buffer, buffer);
    updateInputMeters(buffer);
    updateOutputMeters(buffer);
    return;
#endif

    // Preparar entrada -> Procesar Gen
    fillGenInputBuffers(buffer);
    processGenAudio(numSamples);

#if defined(JCB_DEBUG_TRACE_SILENCE)
    {
        // Entrada (capturada en scratchIn)
        const float inMaxL_pre = blockMaxAbs(inL, numSamples);
        const float inMaxR_pre = (getMainBusNumInputChannels() > 1 ? blockMaxAbs(inR, numSamples) : inMaxL_pre);

        // Salidas directas de Gen (main L/R)
        const float gen01L = blockMaxAbs(m_OutputBuffers[0], numSamples);
        const float gen01R = blockMaxAbs(m_OutputBuffers[1], numSamples);

        // Salidas POST-TRIM si existen (outs 3/4 => idx 2/3)
    const bool havePostTrim = (JCBImager::num_outputs() >= 4 && m_OutputBuffers[2] && m_OutputBuffers[3]);
        const float gen23L = havePostTrim ? blockMaxAbs(m_OutputBuffers[2], numSamples) : -1.0f;
        const float gen23R = havePostTrim ? blockMaxAbs(m_OutputBuffers[3], numSamples) : -1.0f;

        static int phase = -1;
        int newPhase = 0; // 0 = ok, 1 = gen main ~0, 2 = gen post-trim ~0
        const bool hasIn = (inMaxL_pre > 1.0e-6f) || (inMaxR_pre > 1.0e-6f);
        const bool gen01Zero = (gen01L < 1.0e-9f) && (gen01R < 1.0e-9f);
        const bool gen23Zero = havePostTrim && (gen23L < 1.0e-9f) && (gen23R < 1.0e-9f);

        if (hasIn)
        {
            if (gen01Zero) newPhase = 1;
            if (gen23Zero) newPhase = 2; // prioridad a post-trim si ambos son cero
        }

        if (newPhase != phase)
        {
            phase = newPhase;
            DBG("[JCBImager] TRACE gen phase=" << phase
                << " inL=" << inMaxL_pre << " inR=" << inMaxR_pre
                << " gen01L=" << gen01L << " gen01R=" << gen01R
                << " gen23L=" << gen23L << " gen23R=" << gen23R);
        }
    }
#endif

    // --- Sonda: máximos en salida de Gen ANTES del copiado a buffer (solo debug) ---
    #if defined(JCB_DEBUG_AUDIO_WATCH) || defined(JCB_DEBUG_WATCHDOG)
    float genMaxL_pre = 0.f, genMaxR_pre = 0.f;
    if (JCBImager::num_outputs() >= 4 && m_OutputBuffers[2] && m_OutputBuffers[3])
    {
        // Preferir POST-TRIM (outs 3/4 => idx 2/3) si existen
        genMaxL_pre = blockMaxAbs(m_OutputBuffers[2], numSamples);
        genMaxR_pre = blockMaxAbs(m_OutputBuffers[3], numSamples);
    }
    else
    {
        // Fallback: outs principales L/R
        genMaxL_pre = blockMaxAbs(m_OutputBuffers[0], numSamples);
        genMaxR_pre = blockMaxAbs(m_OutputBuffers[1], numSamples);
    }
    #endif

    // Volcar salida de Gen al buffer del host
    fillOutputBuffers(buffer); // buffer = WET procesado

    auto* wetL = buffer.getWritePointer(0);
    auto* wetR = (numChannels > 1) ? buffer.getWritePointer(1) : wetL;

    // Sanitizer is applied after bypass mixing below

#if defined(JCB_DEBUG_AUDIO_WATCH)
    {
        const float inMaxL_dbg  = blockMaxAbs(inL, numSamples);
        const float inMaxR_dbg  = (getMainBusNumInputChannels() > 1 ? blockMaxAbs(inR, numSamples) : inMaxL_dbg);
        const float wetMaxL_dbg = blockMaxAbs(wetL, numSamples);
        const float wetMaxR_dbg = (numChannels > 1 ? blockMaxAbs(wetR, numSamples) : wetMaxL_dbg);

        static int hardZeroBlocks = 0;
        const bool hasInput = (inMaxL_dbg > 1.0e-6f) || (inMaxR_dbg > 1.0e-6f);
        const bool wetIsHardZero = (wetMaxL_dbg < 1.0e-10f) && (wetMaxR_dbg < 1.0e-10f);

        if (hasInput && wetIsHardZero)
        {
            hardZeroBlocks++;
        }
        else
        {
            hardZeroBlocks = 0;
        }

        if (hardZeroBlocks >= 2)
        {
            // Failsafe audible so we can keep monitoring while investigating
            for (int n = 0; n < numSamples; ++n) {
                wetL[n] = inL[n];
                if (numChannels > 1) wetR[n] = (getMainBusNumInputChannels() > 1 ? inR[n] : inL[n]);
            }

            // Dump a detailed state snapshot once and reset the counter
            hardZeroBlocks = 0;

            float dw = 0.f, by = 0.f;
            if (genIdxDryWet >= 0) { t_param v = 0; JCBImager::getparameter(m_PluginState, genIdxDryWet, &v); dw = (float)v; }
            if (genIdxZBypass >= 0){ t_param v = 0; JCBImager::getparameter(m_PluginState, genIdxZBypass, &v); by = (float)v; }

            DBG("[JCBImager] HARDZERO: inL=" << inMaxL_dbg
                << " inR=" << inMaxR_dbg
                << " wetL=" << wetMaxL_dbg
                << " wetR=" << wetMaxR_dbg
                << " genMaxL_pre=" << genMaxL_pre
                << " genMaxR_pre=" << genMaxR_pre
                << " DRYWET=" << dw
                << " i_BYPASS=" << by
                << " hostBypass=" << (hostWantsBypass?1:0)
                << " state=" << (int)bypassState);

            // Removed legacy Reverb-specific param dump
        }
    }
#endif

    // Leer FREEZE de Gen (solo para watchdog de silencio)
    #if defined(JCB_DEBUG_WATCHDOG)
    bool freezeOn = false;
    if (genIdxFreeze >= 0)
    {
        t_param fv = 0.0;
        JCBImager::getparameter(m_PluginState, genIdxFreeze, &fv);
        freezeOn = (fv >= 0.5);
    }
    #endif

#if defined(JCB_DEBUG_WATCHDOG)
    // --- Watchdog relativo por canal (guardado por FREEZE) ---
    if (!freezeOn)
    {
        const float inMax = juce::jmax(blockMaxAbs(inL, numSamples),
                                       (getMainBusNumInputChannels() > 1 ? blockMaxAbs(inR, numSamples)
                                                                         : blockMaxAbs(inL, numSamples)));

        // Umbral relativo al nivel de entrada (si no hay entrada, no disparamos)
        const float rel = juce::jmax(1.0e-4f * inMax, 1.0e-9f);
        const float wetMaxL = blockMaxAbs(wetL, numSamples);
        const float wetMaxR = (numChannels > 1 ? blockMaxAbs(wetR, numSamples) : wetMaxL);

        if (inMax > 1.0e-5f)  // hay señal de entrada
        {
            // L
            if (wetMaxL < rel)
            {
                const int cL = silentL.fetch_add(1, std::memory_order_relaxed) + 1;
                if (cL >= 3 && genMaxL_pre < rel) // 3 bloques + confirmar que Gen ya venía bajo
                {
                    silentL.store(0, std::memory_order_relaxed);
                    silentR.store(0, std::memory_order_relaxed);

                    // Reset suave de Gen + reaplicar parámetros
                    JCBImager::reset(m_PluginState);
                    for (int i = 0; i < JCBImager::num_params(); ++i)
                    {
                        const char* raw = JCBImager::getparametername(m_PluginState, i);
                        if (auto* p = apvts.getRawParameterValue(juce::String(raw ? raw : "")))
                            JCBImager::setparameter(m_PluginState, i, p->load(), nullptr);
                    }

                    // Failsafe para este bloque: copiar el canal sano si existe
                    if (numChannels > 1)
                        for (int n = 0; n < numSamples; ++n) wetL[n] = wetR[n];

                    // Removed legacy Reverb-specific param dump
                }
            }
            else silentL.store(0, std::memory_order_relaxed);

            // R
            if (wetMaxR < rel)
            {
                const int cR = silentR.fetch_add(1, std::memory_order_relaxed) + 1;
                if (cR >= 3 && genMaxR_pre < rel)
                {
                    silentL.store(0, std::memory_order_relaxed);
                    silentR.store(0, std::memory_order_relaxed);

                    JCBImager::reset(m_PluginState);
                    for (int i = 0; i < JCBImager::num_params(); ++i)
                    {
                        const char* raw = JCBImager::getparametername(m_PluginState, i);
                        if (auto* p = apvts.getRawParameterValue(juce::String(raw ? raw : "")))
                            JCBImager::setparameter(m_PluginState, i, p->load(), nullptr);
                    }

                    if (numChannels > 1)
                        for (int n = 0; n < numSamples; ++n) wetR[n] = wetL[n];

                    // Removed legacy Reverb-specific param dump
                }
            }
            else silentR.store(0, std::memory_order_relaxed);
        }
        else
        {
            // sin entrada: no contamos
            silentL.store(0, std::memory_order_relaxed);
            silentR.store(0, std::memory_order_relaxed);
        }
    }
    else
    {
        // FREEZE activo: no vigilar ni acumular contadores
        silentL.store(0, std::memory_order_relaxed);
        silentR.store(0, std::memory_order_relaxed);
    }
#endif

    // === 4. DRY sin compensación (JCBImager no tiene latencia/lookahead) ===
    float* dryL = scratchDry.getWritePointer(0);
    float* dryR = scratchDry.getWritePointer(1);
    // DRY = entrada capturada (sin delay porque no hay latencia)
    // Si el layout es 1->2, duplicar L en R para el mix
    {
        const int mainInputChannels = getMainBusNumInputChannels();
        for (int n = 0; n < numSamples; ++n) {
            dryL[n] = inL[n];
            dryR[n] = (mainInputChannels > 1 ? inR[n] : inL[n]);
        }
    }

    // === 5. FSM de Bypass y mezcla equal-power ===
    const bool wantsBypass = hostWantsBypass;
    hostBypassMirror.store(wantsBypass, std::memory_order_relaxed);
    const bool bypassEdge = (wantsBypass != lastWantsBypass);
    lastWantsBypass = wantsBypass;

    switch (bypassState)
    {
        case BypassState::Active:
            if (bypassEdge && wantsBypass) {
                bypassState = BypassState::FadingToBypass;
                bypassFadePos = 0;
            }
            break;

        case BypassState::Bypassed:
            if (bypassEdge && !wantsBypass) {
                bypassState = BypassState::FadingToActive;
                bypassFadePos = 0;
            }
            break;

        case BypassState::FadingToBypass:
            if (bypassEdge && !wantsBypass) {
                bypassState = BypassState::FadingToActive;
                bypassFadePos = juce::jmax(0, bypassFadeLen - bypassFadePos);
            }
            break;

        case BypassState::FadingToActive:
            if (bypassEdge && wantsBypass) {
                bypassState = BypassState::FadingToBypass;
                bypassFadePos = juce::jmax(0, bypassFadeLen - bypassFadePos);
            }
            break;
    }

    const bool fading = (bypassState == BypassState::FadingToBypass ||
                         bypassState == BypassState::FadingToActive);

    if (!fading)
    {
        if (bypassState == BypassState::Active)
        {
            // WET tal cual (ya está en buffer)
        }
        else // Bypassed
        {
            for (int n = 0; n < numSamples; ++n) {
                wetL[n] = dryL[n];
                if (numChannels > 1) wetR[n] = dryR[n];
            }
        }
    }
    else
    {
        int fadeStartOffset = 0;
        const bool startingFadeThisBlock =
            ((bypassEdge && wantsBypass && bypassState == BypassState::FadingToBypass) ||
             (bypassEdge && !wantsBypass && bypassState == BypassState::FadingToActive)) &&
            (bypassFadePos == 0);

        if (startingFadeThisBlock)
        {
            const float* refL = (bypassState == BypassState::FadingToBypass) ? dryL : wetL;
            const float* refR = (numChannels > 1) ?
                               ((bypassState == BypassState::FadingToBypass) ? dryR : wetR) : refL;

            auto nearZero = [](float x) noexcept { return std::abs(x) < 1.0e-5f; };
            const int searchMax = juce::jmin(32, numSamples - 1);

            for (int i = 1; i <= searchMax; ++i)
            {
                const float l0 = refL[i-1], l1 = refL[i];
                const float r0 = refR[i-1], r1 = refR[i];
                const bool zcL = (nearZero(l0) || nearZero(l1) || (l0 * l1 <= 0.0f));
                const bool zcR = (nearZero(r0) || nearZero(r1) || (r0 * r1 <= 0.0f));
                if (zcL || zcR) { fadeStartOffset = i; break; }
            }
        }

        for (int n = 0; n < numSamples; ++n)
        {
            float wWet = 0.0f, wDry = 0.0f;

            if (n < fadeStartOffset)
            {
                if (bypassState == BypassState::FadingToBypass) { wWet = 1.0f; wDry = 0.0f; }
                else                                            { wWet = 0.0f; wDry = 1.0f; }
                const float outL = wWet * wetL[n] + wDry * dryL[n];
                const float outR = wWet * wetR[n] + wDry * (numChannels > 1 ? dryR[n] : dryL[n]);
                wetL[n] = outL; if (numChannels > 1) wetR[n] = outR;
                continue;
            }

            const float t = juce::jlimit(0.0f, 1.0f,
                                         static_cast<float>(bypassFadePos) /
                                         static_cast<float>(juce::jmax(1, bypassFadeLen)));

            const float s = std::sin(t * juce::MathConstants<float>::halfPi);
            const float c = std::cos(t * juce::MathConstants<float>::halfPi);

            if (bypassState == BypassState::FadingToBypass) { wWet = c * c; wDry = s * s; }
            else                                            { wWet = s * s; wDry = c * c; }

            const float outL = wWet * wetL[n] + wDry * dryL[n];
            const float outR = wWet * wetR[n] + wDry * (numChannels > 1 ? dryR[n] : dryL[n]);
            wetL[n] = outL; if (numChannels > 1) wetR[n] = outR;

            ++bypassFadePos;
            if (bypassFadePos >= bypassFadeLen)
            {
                bypassState = (bypassState == BypassState::FadingToBypass) ? BypassState::Bypassed : BypassState::Active;
                if (bypassState == BypassState::Bypassed)
                {
                    for (int k = n + 1; k < numSamples; ++k) {
                        wetL[k] = dryL[k]; if (numChannels > 1) wetR[k] = dryR[k];
                    }
                }
                break;
            }
        }
    }

    // Safety: sanitize final output and react to trips
    #if !defined(JCB_DISABLE_SANITIZER)
    sanitizeStereo(wetL, (numChannels > 1 ? wetR : nullptr), numSamples, nanTripped);
    #endif

    if (nanTripped.exchange(false, std::memory_order_acq_rel))
    {
        // 1) Resetear estado interno de Gen
        JCBImager::reset(m_PluginState);

        // 2) Reaplicar TODOS los parámetros actuales de APVTS a Gen (estado consistente)
        for (int i = 0; i < JCBImager::num_params(); ++i)
        {
            const char* raw = JCBImager::getparametername(m_PluginState, i);
            if (auto* p = apvts.getRawParameterValue(juce::String(raw ? raw : "")))
                JCBImager::setparameter(m_PluginState, i, p->load(), nullptr);
        }

        // (Opcional) contador/flag para que lo vea el editor
        diagGenResets.fetch_add(1, std::memory_order_relaxed);
    }

    // === 6. Análisis y medición post-procesamiento ===

    // Feed spectrum analyzer: preferir estéreo si está disponible
    if (buffer.getNumChannels() > 0)
    {
        auto* outL = buffer.getReadPointer(0);
        const float* outR = (buffer.getNumChannels() > 1) ? buffer.getReadPointer(1) : nullptr;
        if (spectrumAnalyzerCallbackStereo)
        {
            for (int sample = 0; sample < numSamples; ++sample)
            {
                spectrumAnalyzerCallbackStereo(outL[sample], outR ? outR[sample] : outL[sample]);
            }
        }
        else if (spectrumAnalyzerCallback)
        {
            for (int sample = 0; sample < numSamples; ++sample)
            {
                spectrumAnalyzerCallback(outL[sample]);
            }
        }
    }

    // Capturar forma de onda de salida (señal procesada con reverb)
    captureOutputWaveformData(buffer, numSamples);

    // Actualizar detección de clipping
    updateClipDetection(buffer, buffer);

    // Actualizar medidores
    updateInputMeters(buffer);
    updateOutputMeters(buffer);
}

//==============================================================================
// INTEGRACIÓN GEN~
//==============================================================================

/**
 * Asegurar que los buffers de Gen~ tengan el tamaño correcto
 * CRÍTICO: Esta función gestiona la memoria dinámica para la comunicación con el motor DSP Gen~
 * AUDIO-THREAD SAFE: Solo redimensiona si es absolutamente necesario para evitar RT violations
 */
void JCBImagerAudioProcessor::assureBufferSize(long bufferSize)
{
    if (bufferSize > m_CurrentBufferSize) {
        // NOTA: RT-safe porque prepareToPlay() pre-asigna hasta 4096 samples
        // Solo se ejecuta este bloque si el DAW solicita > 4096 samples (muy raro)

        // Redimensionar buffers de entrada
        for (int i = 0; i < JCBImager::num_inputs(); i++) {
            delete[] m_InputBuffers[i];
            m_InputBuffers[i] = new t_sample[bufferSize];
        }

        // Redimensionar buffers de salida
        for (int i = 0; i < JCBImager::num_outputs(); i++) {
            delete[] m_OutputBuffers[i];
            m_OutputBuffers[i] = new t_sample[bufferSize];
        }

        m_CurrentBufferSize = bufferSize;
    }
}

void JCBImagerAudioProcessor::fillGenInputBuffers(const juce::AudioBuffer<float>& buffer)
{
    const auto mainInputChannels = getMainBusNumInputChannels();
    const int numSamples = buffer.getNumSamples();

    if (mainInputChannels > 1) {
        // Modo estéreo - fill main L/R inputs (inputs 0 and 1)
        for (int j = 0; j < numSamples; j++) {
            m_InputBuffers[0][j] = buffer.getReadPointer(0)[j];  // L
            m_InputBuffers[1][j] = buffer.getReadPointer(1)[j];  // R
        }
    } else {
        // Modo mono - duplicar señal mono a ambos canales L/R para procesamiento stereo-linked
        if (mainInputChannels == 1) {
            for (int j = 0; j < numSamples; j++) {
                m_InputBuffers[0][j] = buffer.getReadPointer(0)[j];  // L = mono
                m_InputBuffers[1][j] = buffer.getReadPointer(0)[j];  // R = mono (duplicado)
            }
        }
    }
}

void JCBImagerAudioProcessor::processGenAudio(int numSamples)
{
    // Simplificado: sin verificación de errores
    JCBImager::perform(m_PluginState,
                      m_InputBuffers,
                      JCBImager::num_inputs(),
                      m_OutputBuffers,
                      JCBImager::num_outputs(),
                      numSamples);
}

void JCBImagerAudioProcessor::fillOutputBuffers(juce::AudioBuffer<float>& buffer)
{
    const int numSamples = buffer.getNumSamples();
    const auto mainOutputChannels = getMainBusNumOutputChannels();

#if defined(JCB_DEBUG_TRACE_SILENCE)
    const float genMainL_dbg = blockMaxAbs(m_OutputBuffers[0], numSamples);
    const float genMainR_dbg = blockMaxAbs(m_OutputBuffers[1], numSamples);
    const bool havePostTrim_dbg = (JCBImager::num_outputs() >= 4 && m_OutputBuffers[2] && m_OutputBuffers[3]);
    const float genPostL_dbg = havePostTrim_dbg ? blockMaxAbs(m_OutputBuffers[2], numSamples) : -1.0f;
    const float genPostR_dbg = havePostTrim_dbg ? blockMaxAbs(m_OutputBuffers[3], numSamples) : -1.0f;
#endif

    // Llenar buffers de salida principales - conversión double a float
    for (int i = 0; i < mainOutputChannels; i++) {
        float* destPtr = buffer.getWritePointer(i);
        const t_sample* srcPtr = m_OutputBuffers[i];
        for (int j = 0; j < numSamples; j++) {
            destPtr[j] = static_cast<float>(srcPtr[j]);
        }
    }

#if defined(JCB_DEBUG_TRACE_SILENCE)
    {
        const float hostMaxL = blockMaxAbs(buffer.getReadPointer(0), numSamples);
        const float hostMaxR = (mainOutputChannels > 1) ? blockMaxAbs(buffer.getReadPointer(1), numSamples) : hostMaxL;
        const bool hostZero = (hostMaxL < 1.0e-8f) && (hostMaxR < 1.0e-8f);
        const bool genHad   = (genMainL_dbg > 1.0e-8f) || (genMainR_dbg > 1.0e-8f) || (genPostL_dbg > 1.0e-8f) || (genPostR_dbg > 1.0e-8f);
        static int lastReport = -1; // 0=ok,1=hostZeroWhileGenHad
        const int now = hostZero && genHad ? 1 : 0;
        if (now != lastReport)
        {
            lastReport = now;
            if (now == 1)
                DBG("[JCBImager] TRACE copy anomaly: host ~0 but Gen had signal - mainL=" << genMainL_dbg
                    << " mainR=" << genMainR_dbg << " postL=" << genPostL_dbg << " postR=" << genPostR_dbg);
            else
                DBG("[JCBImager] TRACE copy ok: mainL=" << genMainL_dbg << " mainR=" << genMainR_dbg
                    << " postL=" << genPostL_dbg << " postR=" << genPostR_dbg);
        }
    }
#endif

    // Preparar buffer para medidores a partir de POST-TRIM si el patch los expone (outs 3/4 -> idx 2/3)
    if (JCBImager::num_outputs() >= 4)
    {
        // No RT reallocs: cap copy length to current capacity
        const int trimCapacity = trimInputBuffer.getNumSamples();
        const int copyCount = juce::jmin(numSamples, trimCapacity);
        if (trimInputBuffer.getNumChannels() >= 2 && copyCount > 0)
        {
            float* trimL = trimInputBuffer.getWritePointer(0);
            float* trimR = trimInputBuffer.getWritePointer(1);
            const t_sample* srcL = m_OutputBuffers[2];
            const t_sample* srcR = m_OutputBuffers[3];
            for (int j = 0; j < copyCount; ++j)
            {
                trimL[j] = static_cast<float>(srcL[j]);
                trimR[j] = static_cast<float>(srcR[j]);
            }
            if (copyCount < trimCapacity)
            {
                juce::FloatVectorOperations::clear(trimL + copyCount, trimCapacity - copyCount);
                juce::FloatVectorOperations::clear(trimR + copyCount, trimCapacity - copyCount);
            }
        }
    }
    else
    {
        // No RT reallocs: cap copy length to current capacity
        const int trimCapacity = trimInputBuffer.getNumSamples();
        const int copyCount = juce::jmin(numSamples, trimCapacity);
        if (trimInputBuffer.getNumChannels() >= 2 && copyCount > 0)
        {
            for (int ch = 0; ch < 2; ++ch)
            {
                float* trimDest = trimInputBuffer.getWritePointer(ch);
                const float* mainSrc = buffer.getReadPointer(juce::jmin(ch, buffer.getNumChannels() - 1));
                std::memcpy(trimDest, mainSrc, sizeof(float) * static_cast<size_t>(copyCount));
            }
            if (copyCount < trimCapacity)
            {
                float* trimDest0 = trimInputBuffer.getWritePointer(0);
                float* trimDest1 = trimInputBuffer.getWritePointer(1);
                juce::FloatVectorOperations::clear(trimDest0 + copyCount, trimCapacity - copyCount);
                juce::FloatVectorOperations::clear(trimDest1 + copyCount, trimCapacity - copyCount);
            }
        }
    }

#if defined(JCB_DEBUG_METERS)
    {
        static int lastPath = -1; // 0=main, 1=post-trim
        const int path = (JCBImager::num_outputs() >= 4 && m_OutputBuffers[2] && m_OutputBuffers[3]) ? 1 : 0;
        if (path != lastPath)
        {
            if (path == 1) DBG("[JCBImager] meters: using POST-TRIM outs 3/4");
            else           DBG("[JCBImager] meters: using MAIN outs 0/1 (fallback)");
            lastPath = path;
        }
    }
#endif
}

//==============================================================================
// MEDIDORES DE AUDIO
//==============================================================================
void JCBImagerAudioProcessor::updateInputMeters(const juce::AudioBuffer<float>& buffer)
{
    const int numSamples = juce::jmin(buffer.getNumSamples(), trimInputBuffer.getNumSamples());
    const auto mainInputChannels = getMainBusNumInputChannels();

    // Calcular valores RMS
    const auto rmsValueL = juce::Decibels::gainToDecibels(trimInputBuffer.getRMSLevel(0, 0, numSamples));
    const auto rmsValueR = (trimInputBuffer.getNumChannels() > 1) ?
    juce::Decibels::gainToDecibels(trimInputBuffer.getRMSLevel(1, 0, numSamples)) : rmsValueL;

    // Calcular valores de pico reales
    const auto peakValueL = juce::Decibels::gainToDecibels(trimInputBuffer.getMagnitude(0, 0, numSamples));
    const auto peakValueR = (trimInputBuffer.getNumChannels() > 1) ?
    juce::Decibels::gainToDecibels(trimInputBuffer.getMagnitude(1, 0, numSamples)) : peakValueL;

    // Usar combinación ponderada 70% peak + 30% RMS
    const auto displayValueL = (peakValueL * 0.7f) + (rmsValueL * 0.3f);
    const auto displayValueR = (peakValueR * 0.7f) + (rmsValueR * 0.3f);

    // Si estamos cerca del clipping (> -3dB), mostrar el valor de pico puro
    const auto inputValueL = (peakValueL > -3.0f) ? peakValueL : displayValueL;
    const auto inputValueR = (peakValueR > -3.0f) ? peakValueR : displayValueR;

    // CRÍTICO: Usar atomic store para thread safety
    // No smoothing is done here - just direct atomic updates
    if (mainInputChannels < 2) {
        // Modo mono - ambos medidores muestran el mismo valor
        leftInputRMS.store(inputValueL, std::memory_order_relaxed);
        rightInputRMS.store(inputValueL, std::memory_order_relaxed);
    } else {
        // Modo estéreo - medidores independientes
        leftInputRMS.store(inputValueL, std::memory_order_relaxed);
        rightInputRMS.store(inputValueR, std::memory_order_relaxed);
    }
}

void JCBImagerAudioProcessor::updateOutputMeters(const juce::AudioBuffer<float>& buffer)
{
    const int numSamples = buffer.getNumSamples();
    const auto mainOutputChannels = getMainBusNumOutputChannels();

    // Calcular valores RMS para el medidor (promedio de potencia)
    const auto rmsValueL = juce::Decibels::gainToDecibels(buffer.getRMSLevel(0, 0, numSamples));
    const auto rmsValueR = (mainOutputChannels > 1) ?
    juce::Decibels::gainToDecibels(buffer.getRMSLevel(1, 0, numSamples)) : rmsValueL;

    // Calcular valores de pico reales (máximo absoluto en el buffer)
    const auto peakValueL = juce::Decibels::gainToDecibels(buffer.getMagnitude(0, 0, numSamples));
    const auto peakValueR = (mainOutputChannels > 1) ?
    juce::Decibels::gainToDecibels(buffer.getMagnitude(1, 0, numSamples)) : peakValueL;

    // Usar una combinación ponderada de RMS y Peak para mejor visualización
    // 70% peak + 30% RMS da una representación más precisa similar a medidores profesionales
    const auto displayValueL = (peakValueL * 0.7f) + (rmsValueL * 0.3f);
    const auto displayValueR = (peakValueR * 0.7f) + (rmsValueR * 0.3f);

    // Si estamos cerca del clipping (> -3dB), mostrar el valor de pico puro
    const auto finalValueL = (peakValueL > -3.0f) ? peakValueL : displayValueL;
    const auto finalValueR = (peakValueR > -3.0f) ? peakValueR : displayValueR;

    // CRÍTICO: Usar atomic store para thread safety
    if (mainOutputChannels > 1) {
        // Modo estéreo
        leftOutputRMS.store(finalValueL, std::memory_order_relaxed);
        rightOutputRMS.store(finalValueR, std::memory_order_relaxed);
    } else {
        // Modo mono
        leftOutputRMS.store(finalValueL, std::memory_order_relaxed);
        rightOutputRMS.store(finalValueL, std::memory_order_relaxed);
    }
}

//==============================================================================
// CONFIGURACIÓN DE BUSES Y PARÁMETROS
//==============================================================================
juce::AudioProcessor::BusesProperties JCBImagerAudioProcessor::createBusesProperties()
{
    auto propBuses = juce::AudioProcessor::BusesProperties()
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
        .withInput("Input", juce::AudioChannelSet::stereo(), true);

    return propBuses;
}

// Validación de configuraciones de canales - define qué layouts acepta el plugin
bool JCBImagerAudioProcessor::isBusesLayoutSupported(const juce::AudioProcessor::BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
    juce::ignoreUnused(layouts);
    return true;
#else
    // Verificar bus principal de salida
    auto mainOut = layouts.getMainOutputChannelSet();
    if (mainOut != juce::AudioChannelSet::mono()
        && mainOut != juce::AudioChannelSet::stereo())
        return false;

    // Verificar bus principal de entrada
    auto mainIn = layouts.getMainInputChannelSet();
    if (mainIn != juce::AudioChannelSet::mono()
        && mainIn != juce::AudioChannelSet::stereo())
        return false;

    // Pro Tools AAX: Rechazar específicamente stereo input → mono output
    // Solo permitir: 1→1, 2→2, 1→2. NO permitir: 2→1
#if JucePlugin_Build_AAX
    // En formato AAX, rechazar siempre stereo input → mono output
    if (mainIn == juce::AudioChannelSet::stereo() && mainOut == juce::AudioChannelSet::mono())
        return false;
#endif

    return true;
#endif
}

/**
 * Crear el layout de parámetros del plugin
 * CRÍTICO: Define todos los parámetros del compresor en orden alfabético
 * Incluye configuración de rangos, valores por defecto y metadata para cada parámetro
 * Version hint 21 fuerza re-escaneo en hosts para parámetros renombrados
 */
juce::AudioProcessorValueTreeState::ParameterLayout JCBImagerAudioProcessor::createParameterLayout()
{
   const int versionHint = 3;  // Bump to refresh host-cached ranges
   std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;

   // === PARÁMETROS DEL IMAGER ===

   // Frecuencias de cruce
   params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("a_FREQ1", versionHint), "Freq 1", juce::NormalisableRange<float>(20.f, 1000.f, 1.f, 0.4f), 250.f, "Hz"));
   params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("b_FREQ2", versionHint), "Freq 2", juce::NormalisableRange<float>(1000.f, 20000.f, 1.f, 0.4f), 5000.f, "Hz"));

   // Ganancias por banda (1.0 = unidad) con mapeo textual -100..+100 %
   auto widthToText = [](float v, int) {
       // Map 0.5..1.5 -> -100..+100 and format with % (center at 0)
       int pct = juce::roundToInt((v - 1.0f) * 200.0f);
       if (pct == 0) return juce::String("0%");
       juce::String sgn = (pct > 0 ? "+" : "");
        return sgn + juce::String(pct) + "%";
   };
   auto widthFromText = [](const juce::String& t) {
       auto s = t.trim();
       if (s.endsWithChar('%')) s = s.dropLastCharacters(1).trim();
       double pct = juce::jlimit(-100.0, 100.0, s.getDoubleValue());
       return (float)(1.0 + pct / 200.0); // 0.5..1.5
   };
   // Empty unit label to let valueToText provide the full string (e.g., "-25%")
   params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("c_LOW", versionHint),  "Low Width",  juce::NormalisableRange<float>(0.5f, 1.5f, 0.001f), 1.0f, "", juce::AudioParameterFloat::genericParameter, widthToText, widthFromText));
   params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("d_MED", versionHint),  "Mid Width",  juce::NormalisableRange<float>(0.5f, 1.5f, 0.001f), 1.0f, "", juce::AudioParameterFloat::genericParameter, widthToText, widthFromText));
   params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("e_HIGH", versionHint), "High Width", juce::NormalisableRange<float>(0.5f, 1.5f, 0.001f), 1.0f, "", juce::AudioParameterFloat::genericParameter, widthToText, widthFromText));

   // Controles SOLO: gestionados solo por UI (no en APVTS)
   params.push_back(std::make_unique<juce::AudioParameterBool>(juce::ParameterID("i_BYPASS", versionHint),   "Bypass",    false));
   params.push_back(std::make_unique<juce::AudioParameterBool>(juce::ParameterID("j_input", versionHint),    "Input On",  true));

   // Balances por banda (0..1)
   params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("k_LOW_bal", versionHint),  "Low Bal",  juce::NormalisableRange<float>(0.f, 1.f, 0.001f), 0.5f));
   params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("l_MED_bal", versionHint),  "Mid Bal",  juce::NormalisableRange<float>(0.f, 1.f, 0.001f), 0.5f));
   params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("m_HIGH_bal", versionHint), "High Bal", juce::NormalisableRange<float>(0.f, 1.f, 0.001f), 0.5f));

   // Mute por banda (APVTS, automatizable si el host lo permite)
   params.push_back(std::make_unique<juce::AudioParameterBool>(juce::ParameterID("n_MUTLOW", versionHint),  "Mute Low",  false));
   params.push_back(std::make_unique<juce::AudioParameterBool>(juce::ParameterID("o_MUTMED", versionHint),  "Mute Mid",  false));
   params.push_back(std::make_unique<juce::AudioParameterBool>(juce::ParameterID("p_MUTHIGH", versionHint), "Mute High", false));

   // Dry/Wet + Trim + Makeup
   params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("x_DRYWET", versionHint), "Dry/Wet", juce::NormalisableRange<float>(0.f, 1.f, 0.001f), 1.0f, "%", juce::AudioParameterFloat::genericParameter, [](float v,int){return juce::String(static_cast<int>(v*100))+"%";}, nullptr));
   params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("v_TRIM", versionHint),   "Trim",    juce::NormalisableRange<float>(-12.f, 12.f, 0.1f), 0.f, "dB"));
   params.push_back(std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("w_MAKEUP", versionHint), "Makeup",  juce::NormalisableRange<float>(-12.f, 12.f, 0.1f), 0.f, "dB"));

   return { params.begin(), params.end() };
}

//==============================================================================
// GESTIÓN DE PARÁMETROS
//==============================================================================

void JCBImagerAudioProcessor::parameterChanged(const juce::String& parameterID, float newValue)
{
    // newValue YA VIENE EN UNIDADES REALES desde APVTS::Listener
    // Para bool usar 0/1, para float usar newValue tal cual
    float v = newValue;
    if (auto* p = apvts.getParameter(parameterID))
    {
        if (auto* pb = dynamic_cast<juce::AudioParameterBool*>(p))
            v = pb->get() ? 1.0f : 0.0f;
    }
    // Encolar por nombre (resuelve índice y evita carreras con prepareToPlay)
    pushGenParamByName(parameterID, v);
    // No hagas callAsync ni toques UI aquí.
}
//==============================================================================
// Métodos de programa (presets)
int JCBImagerAudioProcessor::getNumPrograms()
{
    return 0; // 3 antes, añadir 1 por comportamiento extraño algunos hosts
}

int JCBImagerAudioProcessor::getCurrentProgram()
{
    return currentProgram;
}

void JCBImagerAudioProcessor::setCurrentProgram(int index)
{
    currentProgram = index;
}

const juce::String JCBImagerAudioProcessor::getProgramName(int index)
{
    return juce::String();
}

void JCBImagerAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
    // No implementado - los nombres de preset son fijos
}

//==============================================================================
// Métodos de medidores
float JCBImagerAudioProcessor::getRmsInputValue(const int channel) const noexcept
{
    // CRASH FIX: Safety check - return safe value if not initialized
    if (!isInitialized()) {
        return -100.0f;  // Safe default value
    }

    jassert(channel == 0 || channel == 1);
    if (channel == 0)
        return leftInputRMS.load(std::memory_order_relaxed);
    if (channel == 1)
        return rightInputRMS.load(std::memory_order_relaxed);
    return -100.0f;  // Return -100dB for invalid channels
}

float JCBImagerAudioProcessor::getRmsOutputValue(const int channel) const noexcept
{
    // CRASH FIX: Safety check - return safe value if not initialized
    if (!isInitialized()) {
        return -100.0f;  // Safe default value
    }

    jassert(channel == 0 || channel == 1);
    if (channel == 0)
        return leftOutputRMS.load(std::memory_order_relaxed);
    if (channel == 1)
        return rightOutputRMS.load(std::memory_order_relaxed);
    return -100.0f;  // Return -100dB for invalid channels
}

// Reverb no requiere función getGainReductionValue

//==============================================================================
// Utilidades
bool JCBImagerAudioProcessor::isProTools() const noexcept
{
    juce::PluginHostType daw;
    return daw.isProTools();
}

juce::String JCBImagerAudioProcessor::getPluginFormat() const noexcept
{
    // Detectar el formato del plugin en tiempo de ejecución
    const auto format = juce::PluginHostType().getPluginLoadedAs();

    switch (format)
    {
        case juce::AudioProcessor::wrapperType_VST3:
            return "VST3";
        case juce::AudioProcessor::wrapperType_AudioUnit:
            return "AU";
        case juce::AudioProcessor::wrapperType_AudioUnitv3:
            return "AUv3";
        case juce::AudioProcessor::wrapperType_AAX:
            return "AAX";
        case juce::AudioProcessor::wrapperType_VST:
            return "VST2";
        case juce::AudioProcessor::wrapperType_Standalone:
            return "Standalone";
        default:
            return "";
    }
}

//==============================================================================
// CAPTURA DE DATOS PARA VISUALIZACIÓN DE ENVOLVENTES
//==============================================================================
void JCBImagerAudioProcessor::captureInputWaveformData(const juce::AudioBuffer<float>& inputBuffer, int numSamples)
{
    // AUDIO-THREAD SAFE: Usar try_lock para evitar bloquear el audio thread
    std::unique_lock<std::mutex> lock(waveformMutex, std::try_to_lock);
    if (!lock.owns_lock()) {
        // Si no puede obtener el lock, salir inmediatamente para evitar RT violations
        return;
    }

    // AUDIO-THREAD SAFE: Usar tamaño fijo pre-asignado, no resize() dinámico
    const int capIn = (int) currentInputSamples.size();
    const int countIn = juce::jmin(numSamples, capIn);
    if (countIn <= 0) return;

    // Preferir el tap post‑TRIM copiado a trimInputBuffer (thread‑safe),
    // y si no está disponible, hacer fallback al buffer de entrada del host.
    const int trimCh = trimInputBuffer.getNumChannels();
    const int trimNs = trimInputBuffer.getNumSamples();
    if (trimCh >= 1 && trimNs >= countIn)
    {
        const float* tL = trimInputBuffer.getReadPointer(0);
        if (trimCh >= 2)
        {
            const float* tR = trimInputBuffer.getReadPointer(1);
            const float k = 0.70710678f; // 1/sqrt(2)
            for (int i = 0; i < countIn; ++i)
            {
                const float l = tL[i];
                const float r = tR[i];
                currentInputSamples[i] = k * std::sqrt(l*l + r*r);
            }
        }
        else
        {
            std::memcpy(currentInputSamples.data(), tL, sizeof(float) * static_cast<size_t>(countIn));
        }
    }
    else
    {
        // Fallback: usar el buffer de entrada del host
        const int chs = inputBuffer.getNumChannels();
        if (chs > 1)
        {
            const float* inL = inputBuffer.getReadPointer(0);
            const float* inR = inputBuffer.getReadPointer(1);
            const float k2 = 0.70710678f;
            for (int i = 0; i < countIn; ++i)
            {
                const float l = inL[i];
                const float r = inR[i];
                currentInputSamples[i] = k2 * std::sqrt(l*l + r*r);
            }
        }
        else if (chs == 1)
        {
            const float* src = inputBuffer.getReadPointer(0);
            std::memcpy(currentInputSamples.data(), src, sizeof(float) * static_cast<size_t>(countIn));
        }
    }
}

void JCBImagerAudioProcessor::captureOutputWaveformData(const juce::AudioBuffer<float>& outputBuffer, int numSamples)
{
    // AUDIO-THREAD SAFE: Usar try_lock para evitar bloquear el audio thread
    std::unique_lock<std::mutex> lock(waveformMutex, std::try_to_lock);
    if (!lock.owns_lock()) {
        // Si no puede obtener el lock, salir inmediatamente para evitar RT violations
        return;
    }

    // AUDIO-THREAD SAFE: Usar tamaño fijo pre-asignado, no resize() dinámico
    const int capOut = (int) currentProcessedSamples.size();
    const int countOut = juce::jmin(numSamples, capOut);
    if (countOut <= 0) return;

    // Copiar salida procesada evitando cancelación M/S: mezclar por energía (RMS por muestra)
    const int chs = outputBuffer.getNumChannels();
    if (chs > 1)
    {
        const float* L = outputBuffer.getReadPointer(0);
        const float* R = outputBuffer.getReadPointer(1);
        const float k = 0.70710678f; // 1/sqrt(2)
        for (int i = 0; i < countOut; ++i)
        {
            const float l = L[i];
            const float r = R[i];
            currentProcessedSamples[i] = k * std::sqrt(l*l + r*r);
        }
    }
    else
    {
        const float* src = outputBuffer.getReadPointer(0);
        std::memcpy(currentProcessedSamples.data(), src, sizeof(float) * static_cast<size_t>(countOut));
    }
}

void JCBImagerAudioProcessor::getWaveformData(std::vector<float>& inputSamples, std::vector<float>& processedSamples) const
{
    std::lock_guard<std::mutex> lock(waveformMutex);
    inputSamples = currentInputSamples;
    processedSamples = currentProcessedSamples;
}

bool JCBImagerAudioProcessor::isPlaybackActive() const noexcept
{
    // Siempre activo para decay permanente como plugins profesionales
    return true;
}


//==============================================================================
// GESTIÓN DEL EDITOR
//==============================================================================
juce::AudioProcessorEditor* JCBImagerAudioProcessor::createEditor()
{
    return new JCBImagerAudioProcessorEditor(*this, guiUndoManager);
}


//==============================================================================
// SERIALIZACIÓN DEL ESTADO
//==============================================================================
void JCBImagerAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    // Crear una copia del state para no modificar el original
    auto stateCopy = apvts.state.createCopy();

    // Remover parámetros momentáneos antes de guardar
    // Estos botones no deben persistir entre sesiones
    auto paramsNode = stateCopy.getChildWithName("PARAMETERS");
    if (paramsNode.isValid()) {
        // No persistir el bypass del host en el estado
        auto param = paramsNode.getChildWithProperty("id", "bypass");
        if (param.isValid())
            param.setProperty("value", 0.0f, nullptr);

        // Reverb: plugin limpio de parámetros legacy
    }

    auto preset = stateCopy.getOrCreateChildWithName("Presets", nullptr);
    preset.setProperty("currentPresetID", lastPreset, nullptr);
    preset.setProperty("tooltipEnabled", tooltipEnabled, nullptr);
    preset.setProperty("presetDisplayText", presetDisplayText, nullptr);
    preset.setProperty("presetTextItalic", presetTextItalic, nullptr);
    preset.setProperty("envelopeVisualEnabled", envelopeVisualEnabled, nullptr);
    preset.setProperty("tooltipLanguageEnglish", tooltipLanguageEnglish, nullptr);

    // Guardar tamaño del editor
    preset.setProperty("editorWidth", editorSize.x, nullptr);
    preset.setProperty("editorHeight", editorSize.y, nullptr);

    // Guardar estado del modo de visualización (no automatizable)
    preset.setProperty("displayModeIsFFT", displayModeIsFFT, nullptr);

    // Save A/B states
    auto abNode = stateCopy.getOrCreateChildWithName("ABStates", nullptr);
    abNode.setProperty("isStateA", isStateA, nullptr);

    // Save state A
    auto stateANode = abNode.getOrCreateChildWithName("StateA", nullptr);
    stateANode.removeAllChildren(nullptr);
    for (const auto& [paramId, value] : stateA.values) {
        stateANode.setProperty(paramId, value, nullptr);
    }

    // Save state B
    auto stateBNode = abNode.getOrCreateChildWithName("StateB", nullptr);
    stateBNode.removeAllChildren(nullptr);
    for (const auto& [paramId, value] : stateB.values) {
        stateBNode.setProperty(paramId, value, nullptr);
    }

    juce::MemoryOutputStream memoria(destData, true);
    stateCopy.writeToStream(memoria);
}

void JCBImagerAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    auto tree = juce::ValueTree::readFromData(data, sizeInBytes);
    if (tree.isValid()) {
        apvts.state = tree;

        // Forzar parámetros momentáneos a OFF después de cargar
        if (auto* pBypass = apvts.getParameter("bypass"))
            pBypass->setValueNotifyingHost(0.0f);

        // Re-sincronización completa desactivada: encolamos al audio thread abajo

        // Encolar todos los parámetros para que se apliquen en el audio thread
        if (m_PluginState)
        {
            for (int i = 0; i < JCBImager::num_params(); ++i)
            {
                const char* raw = JCBImager::getparametername(m_PluginState, i);
                auto id = juce::String(raw ? raw : "");
                if (auto* p = apvts.getRawParameterValue(id))
                    pushParamToAudioThread(i, p->load());
            }
        }

        // Clear undo history AFTER all values have been set
        // This prevents any parameter changes from being recorded in undo history
        guiUndoManager.clearUndoHistory();

        auto preset = apvts.state.getChildWithName("Presets");
        if (preset.isValid()) {
            lastPreset = preset.getProperty("currentPresetID");
            tooltipEnabled = preset.getProperty("tooltipEnabled");
            presetDisplayText = preset.getProperty("presetDisplayText", "DEFAULT");
            presetTextItalic = preset.getProperty("presetTextItalic", false);
            envelopeVisualEnabled = preset.getProperty("envelopeVisualEnabled", true);
            tooltipLanguageEnglish = preset.getProperty("tooltipLanguageEnglish", false);

            // Restaurar tamaño del editor
            int savedWidth = preset.getProperty("editorWidth", 1250);
            int savedHeight = preset.getProperty("editorHeight", 350);
            editorSize = {savedWidth, savedHeight};

            // Restaurar estado del modo de visualización (no automatizable)
            displayModeIsFFT = preset.getProperty("displayModeIsFFT", false);
        }

        // Restore A/B states
        auto abNode = apvts.state.getChildWithName("ABStates");
        if (abNode.isValid()) {
            isStateA = abNode.getProperty("isStateA", true);

            // Restore state A
            auto stateANode = abNode.getChildWithName("StateA");
            if (stateANode.isValid()) {
                stateA.values.clear();
                for (int i = 0; i < stateANode.getNumProperties(); ++i) {
                    auto propName = stateANode.getPropertyName(i);
                    stateA.values[propName.toString()] = stateANode[propName];
                }
            }

            // Restore state B
            auto stateBNode = abNode.getChildWithName("StateB");
            if (stateBNode.isValid()) {
                stateB.values.clear();
                for (int i = 0; i < stateBNode.getNumProperties(); ++i) {
                    auto propName = stateBNode.getPropertyName(i);
                    stateB.values[propName.toString()] = stateBNode[propName];
                }
            }
        }

        // IMPORTANTE: Sincronizar todos los parámetros con Gen~ después de cargar el estado (enqueue)
        for (int i = 0; i < JCBImager::num_params(); ++i)
        {
            const char* raw = JCBImager::getparametername(m_PluginState, i);
            auto paramName = juce::String(raw ? raw : "");
            if (auto* param = apvts.getRawParameterValue(paramName))
            {
                float value = param->load();

                // Mantén las mismas correcciones si aplican a tu reverb
                if (paramName == "d_ATK" && value < 0.1f) {
                    value = 0.1f;
                    if (auto* audioParam = apvts.getParameter(paramName))
                        audioParam->setValueNotifyingHost(audioParam->convertTo0to1(value));
                }
                if (paramName == "e_REL" && value < 0.1f) {
                    value = 0.1f;
                    if (auto* audioParam = apvts.getParameter(paramName))
                        audioParam->setValueNotifyingHost(audioParam->convertTo0to1(value));
                }

                // En vez de llamar a parameterChanged() (que ya encola),
                // podemos encolar directamente con el índice i:
                pushParamToAudioThread(i, value);
            }
        }

        // // Forzar actualización del editor de forma thread-safe
        // // Usar MessageManager para evitar llamadas directas a getActiveEditor()
        // juce::MessageManager::callAsync([this]() {
        //     if (auto* editor = dynamic_cast<JCBImagerAudioProcessorEditor*>(getActiveEditor())) {
        //         // El editor necesita actualizar la función de transferencia
        //         editor->updateTransferFunctionFromProcessor();
        //     }
        // });
    }
}

//==============================================================================
// COMPARACIÓN A/B
//==============================================================================
void JCBImagerAudioProcessor::saveCurrentStateToActive()
{
    if (isStateA) {
        stateA.captureFrom(apvts);
    } else {
        stateB.captureFrom(apvts);
    }
}

void JCBImagerAudioProcessor::toggleAB()
{
    // Save current state before switching
    saveCurrentStateToActive();

    // Switch state
    isStateA = !isStateA;

    // Load the other state
    if (isStateA) {
        stateA.applyTo(apvts);
    } else {
        stateB.applyTo(apvts);
    }
}

void JCBImagerAudioProcessor::copyAtoB()
{
    stateA.captureFrom(apvts);
    stateB = stateA;
}

void JCBImagerAudioProcessor::copyBtoA()
{
    stateB.captureFrom(apvts);
    stateA = stateB;
}


//==============================================================================
// MÉTODOS LEGACY
//==============================================================================
int JCBImagerAudioProcessor::getNumParameters()
{
    // Retornar el número real de parámetros del juce::AudioProcessor
    // que incluye los de Gen~ más cualquier parámetro adicional (como AAX gain reduction)
    return static_cast<int>(getParameters().size());
}

float JCBImagerAudioProcessor::getParameter(int index)
{
    // Verificar si el índice está dentro del rango de Gen~
    if (index < JCBImager::num_params())
    {
        t_param value;
        t_param min = JCBImager::getparametermin(m_PluginState, index);
        t_param range = fabs(JCBImager::getparametermax(m_PluginState, index) - min);

        JCBImager::getparameter(m_PluginState, index, &value);

        value = (value - min) / range;

        return value;
    }
    else
    {
        // Manejar parámetros adicionales (como AAX gain reduction)
        // Para el parámetro de gain reduction, devolver 0.0 (sin reducción)
        return 0.0f;
    }
}

void JCBImagerAudioProcessor::setParameter(int index, float newValue)
{
    // Verificar si el índice está dentro del rango de Gen~
    if (index < JCBImager::num_params())
    {
        t_param min = JCBImager::getparametermin(m_PluginState, index);
        t_param range = fabs(JCBImager::getparametermax(m_PluginState, index) - min);
        t_param value = newValue * range + min;

        JCBImager::setparameter(m_PluginState, index, value, nullptr);
    }
    else
    {
        // Manejar parámetros adicionales (como AAX gain reduction)
        // El parámetro de gain reduction es de solo lectura, no hacer nada
    }
}

const juce::String JCBImagerAudioProcessor::getParameterName(int index)
{
    // Verificar si el índice está dentro del rango de Gen~
    if (index < JCBImager::num_params())
    {
        return juce::String(JCBImager::getparametername(m_PluginState, index));
    }
    else
    {
        // Manejar parámetros adicionales (como AAX gain reduction)
        #if JucePlugin_Build_AAX
        if (index == JCBImager::num_params()) // Índice 25 para AAX
        {
            return "Gain Reduction";
        }
        #endif
        return "";
    }
}

const juce::String JCBImagerAudioProcessor::getParameterText(int index)
{
    // Método legacy para compatibilidad con hosts - algunos DAWs pueden llamarlo
    if (index >= 0 && index < JCBImager::num_params())
    {
        juce::String text = juce::String(getParameter(index));
        text += juce::String(" ");
        text += juce::String(JCBImager::getparameterunits(m_PluginState, index));
        return text;
    }

    // Retornar string vacío para índices inválidos
    return "";
}

const juce::String JCBImagerAudioProcessor::getInputChannelName(int channelIndex) const
{
    return juce::String(channelIndex + 1);
}

const juce::String JCBImagerAudioProcessor::getOutputChannelName(int channelIndex) const
{
    return juce::String(channelIndex + 1);
}

bool JCBImagerAudioProcessor::isInputChannelStereoPair(int index) const
{
    juce::ignoreUnused(index);
    // Report stereo pairing based on the input bus layout that the host actually sees.
    return getMainBusNumInputChannels() == 2;
}

bool JCBImagerAudioProcessor::isOutputChannelStereoPair(int index) const
{
    juce::ignoreUnused(index);
    // Base the stereo-pair decision on the actual bus layout exposed to the host,
    // not on the internal Gen~ number of outputs (which may be 4 when POST-TRIM meters are present).
    return getMainBusNumOutputChannels() == 2;
}


//==============================================================================
// Clip Detection Methods
//==============================================================================

void JCBImagerAudioProcessor::updateClipDetection(const juce::AudioBuffer<float>& inputBuffer, const juce::AudioBuffer<float>& outputBuffer)
{
    const int numSamples = inputBuffer.getNumSamples();
    const auto mainInputChannels = getMainBusNumInputChannels();
    const auto mainOutputChannels = getMainBusNumOutputChannels();

    // NOTA: El compresor no tiene soft clip, siempre detectar clips en salida
    bool isSoftClipActive = false; // Compresor no tiene soft clip

    // Reset clip flags for this buffer
    bool inputClip[2] = {false, false};
    bool outputClip[2] = {false, false};

    // Detectar clips en entrada (usando trimInputBuffer para consistencia con medidores)
    for (int channel = 0; channel < juce::jmin(2, mainInputChannels); ++channel) {
        for (int sample = 0; sample < numSamples; ++sample) {
            if (channel < trimInputBuffer.getNumChannels()) {
                float value = std::abs(trimInputBuffer.getSample(channel, sample));
                if (value >= 0.999f) {  // Umbral de clip ligeramente por debajo de 1.0
                    inputClip[channel] = true;
                    break;  // Solo necesitamos detectar un clip por buffer
                }
            }
        }
    }

    // Detectar clips en salida solo si soft clip NO está activo
    if (!isSoftClipActive) {
        for (int channel = 0; channel < juce::jmin(2, mainOutputChannels); ++channel) {
            for (int sample = 0; sample < numSamples; ++sample) {
                float value = std::abs(outputBuffer.getSample(channel, sample));
                if (value >= 0.999f) {  // Umbral de clip ligeramente por debajo de 1.0
                    outputClip[channel] = true;
                    break;  // Solo necesitamos detectar un clip por buffer
                }
            }
        }
    }

    // Actualizar flags atómicos
    for (int channel = 0; channel < 2; ++channel) {
        if (inputClip[channel]) {
            inputClipDetected[channel] = true;
        }
        if (outputClip[channel]) {
            outputClipDetected[channel] = true;
        }
    }
}

bool JCBImagerAudioProcessor::getInputClipDetected(const int channel) const noexcept
{
    jassert(channel == 0 || channel == 1);
    if (channel >= 0 && channel < 2) {
        return inputClipDetected[channel].load();
    }
    return false;
}

bool JCBImagerAudioProcessor::getOutputClipDetected(const int channel) const noexcept
{
    jassert(channel == 0 || channel == 1);
    if (channel >= 0 && channel < 2) {
        return outputClipDetected[channel].load();
    }
    return false;
}


void JCBImagerAudioProcessor::resetClipIndicators()
{
    for (int channel = 0; channel < 2; ++channel) {
        inputClipDetected[channel] = false;
        outputClipDetected[channel] = false;
        
    }
}

// Reverb no tiene gain reduction para reportar al host

//==============================================================================
// Timer implementation

//==============================================================================
// Format-specific implementations

// Reverb no tiene medidores de gain reduction AAX

#if JucePlugin_Build_VST3
void JCBImagerAudioProcessor::updateVST3GainReduction()
{
    // Para VST3, necesitaríamos acceso al IEditController
    // Esto se haría típicamente en el wrapper VST3
    // Por ahora solo preparamos el método
}
#endif

//==============================================================================
// ASYNC UPDATER - Actualización de latencia fuera del audio thread
//==============================================================================
void JCBImagerAudioProcessor::handleAsyncUpdate()
{
    // Actualizar latencia de forma thread-safe (si el reverb tuviera latencia)
    const int newLatency = pendingLatency.load(std::memory_order_relaxed);
    if (newLatency >= 0 && newLatency != currentLatency)
    {
        setLatencySamples(newLatency);
        currentLatency = newLatency;
        pendingLatency.store(-1, std::memory_order_relaxed);
    }
}

//==============================================================================
// TIMER CALLBACK
//==============================================================================
void JCBImagerAudioProcessor::timerCallback()
{
    // Timer callback para tareas que requieren ejecución fuera del audio thread
    // Para distorsión, mantenemos funcionalidad mínima necesaria

    // Verificar si el processor está siendo destruido
    if (isBeingDestroyed.load()) {
        return;
    }

    // Actualizar estado de playback para medidores
    // En distorsión no necesitamos lógica compleja de gain reduction
}


// (removed) fillGenInputBuffersFromScratch: unified to fillGenInputBuffers(buffer)

//==============================================================================
// FACTORY FUNCTION DEL PLUGIN
//==============================================================================

/**
 * Función factory requerida por JUCE
 * CRÍTICO: Punto de entrada que utilizan los hosts (DAWs) para crear instancias del plugin
 * Esta función es llamada automáticamente por el framework JUCE cuando:
 * - El DAW carga el plugin por primera vez
 * - Se crea una nueva instancia del plugin en el proyecto
 * - Se duplica una pista que contiene el plugin
 */
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new JCBImagerAudioProcessor();
}
