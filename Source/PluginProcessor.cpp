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

//==============================================================================
// CALLBACK SETTERS (THREAD-SAFE)
//==============================================================================

void JCBImagerAudioProcessor::setSpectrumAnalyzerCallback(SpectrumCallback callback)
{
    if (callback)
    {
        auto holder = std::make_shared<SpectrumCallback>(std::move(callback));
        std::atomic_store_explicit(&spectrumAnalyzerCallbackShared, holder, std::memory_order_release);
    }
    else
    {
        std::shared_ptr<SpectrumCallback> empty;
        std::atomic_store_explicit(&spectrumAnalyzerCallbackShared, empty, std::memory_order_release);
    }
}

void JCBImagerAudioProcessor::setSpectrumAnalyzerCallbackStereo(SpectrumStereoCallback callback)
{
    if (callback)
    {
        auto holder = std::make_shared<SpectrumStereoCallback>(std::move(callback));
        std::atomic_store_explicit(&spectrumAnalyzerCallbackStereoShared, holder, std::memory_order_release);
    }
    else
    {
        std::shared_ptr<SpectrumStereoCallback> empty;
        std::atomic_store_explicit(&spectrumAnalyzerCallbackStereoShared, empty, std::memory_order_release);
    }
}

void JCBImagerAudioProcessor::setSampleRateChangedCallback(SampleRateCallback callback)
{
    if (callback)
    {
        auto holder = std::make_shared<SampleRateCallback>(std::move(callback));
        std::atomic_store_explicit(&sampleRateChangedCallbackShared, holder, std::memory_order_release);
    }
    else
    {
        std::shared_ptr<SampleRateCallback> empty;
        std::atomic_store_explicit(&sampleRateChangedCallbackShared, empty, std::memory_order_release);
    }
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

    setSpectrumAnalyzerCallback({});
    setSpectrumAnalyzerCallbackStereo({});
    setSampleRateChangedCallback({});

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

    // Callbacks para visualización se añadirán cuando se exponga el display del Imager

    // Pre-asignar buffers con tamaño máximo esperado para evitar allocations en audio thread
    // Usar un tamaño seguro que cubra la mayoría de casos (16384 samples es común máximo para hosts modernos)
    const long maxExpectedBufferSize = juce::jmax(static_cast<long>(samplesPerBlock), 16384L);
    assureBufferSize(maxExpectedBufferSize);

    // Pre-asignar buffer para el goniometer (vectorescope) y resetear estado
    {
        std::lock_guard<std::mutex> lock(goniometerMutex);
        const size_t goniometerCapacity = 2048;
        goniometerBuffer.assign(goniometerCapacity, juce::Point<float>{});
        goniometerWriteIndex = 0;
        goniometerValidSamples = 0;
        goniometerDecimationCounter = 0;
    }

    // 3) ***Clave***: sincroniza SR/VS con Gen y re-dimensiona sus delays/constantes
    //    Esto asegura que Gen use el sampleRate real del host
    JCBImager::reset (m_PluginState);

    // Cachear indices de gen para evitar bucles por nombre
    genIdxZBypass = -1;
    genIdxDryWet  = -1;
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
        if      (name == "n_MUTLOW")   genIdxMuteLow  = i;
        else if (name == "o_MUTMED")   genIdxMuteMid  = i;
        else if (name == "p_MUTHIGH")  genIdxMuteHigh = i;
        else if (name == "f_SOLOLOW")  genIdxSoloLow  = i;
        else if (name == "g_SOLOMED")  genIdxSoloMid  = i;
        else if (name == "h_SOLOHIGH") genIdxSoloHigh = i;
    }

    // Imager: latencia fija (sin lookahead)
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
    if (auto callback = std::atomic_load_explicit(&sampleRateChangedCallbackShared, std::memory_order_acquire))
    {
        (*callback)(sampleRate);
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
    
    // === 1.b APLICAR AQUÍ: drenar cambios de parámetros pendientes ===
    drainPendingParamsToGen();

    // Host bypass handled via FSM mix below. No early return.

    // === 2. (reserved) bus layout sync ===

    // === 3. Procesar WET con Gen~ (siempre activo) ===
    // Preparar entrada -> Procesar Gen
    fillGenInputBuffers(buffer);
    processGenAudio(numSamples);

    // --- Sonda: máximos en salida de Gen ANTES del copiado a buffer (solo debug) ---
    // Volcar salida de Gen al buffer del host
    fillOutputBuffers(buffer); // buffer = WET procesado

    auto* wetL = buffer.getWritePointer(0);
    auto* wetR = (numChannels > 1) ? buffer.getWritePointer(1) : wetL;

    // Sanitizer is applied after bypass mixing below
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
        auto stereoCallback = std::atomic_load_explicit(&spectrumAnalyzerCallbackStereoShared, std::memory_order_acquire);
        auto monoCallback   = std::atomic_load_explicit(&spectrumAnalyzerCallbackShared, std::memory_order_acquire);

        if (stereoCallback || monoCallback)
        {
            auto* outL = buffer.getReadPointer(0);
            const float* outR = (buffer.getNumChannels() > 1) ? buffer.getReadPointer(1) : nullptr;

            if (stereoCallback)
            {
                auto& cb = *stereoCallback;
                for (int sample = 0; sample < numSamples; ++sample)
                {
                    cb(outL[sample], outR ? outR[sample] : outL[sample]);
                }
            }
            else
            {
                auto& cb = *monoCallback;
                for (int sample = 0; sample < numSamples; ++sample)
                {
                    cb(outL[sample]);
                }
            }
        }
    }

    // Capturar datos para el goniometer desde la salida procesada
    captureGoniometerData(buffer, numSamples);

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

    // Llenar buffers de salida principales - conversión double a float
    for (int i = 0; i < mainOutputChannels; i++) {
        float* destPtr = buffer.getWritePointer(i);
        const t_sample* srcPtr = m_OutputBuffers[i];
        for (int j = 0; j < numSamples; j++) {
            destPtr[j] = static_cast<float>(srcPtr[j]);
        }
    }

    // Preparar buffer para medidores a partir de POST-TRIM si el patch los expone (outs 3/4 -> idx 2/3)
    if (JCBImager::num_outputs() >= 4)
    {
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
   auto freq1 = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("a_FREQ1", versionHint),
                                                           "Freq 1",
                                                           juce::NormalisableRange<float>(20.f, 1000.f, 1.f, 0.4f),
                                                           250.f,
                                                           "Hz");

   auto freq2 = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("b_FREQ2", versionHint),
                                                           "Freq 2",
                                                           juce::NormalisableRange<float>(2500.f, 10000.f, 1.f, 0.4f),
                                                           5000.f,
                                                           "Hz");

   // Ganancias por banda (1.0 = unidad) mostrando valores lineales 0..2
   auto widthToText = [](float v, int)
   {
       auto clamped = juce::jlimit(0.0f, 2.0f, v);
       return juce::String(clamped, 2);
   };

   auto widthFromText = [](const juce::String& t)
   {
       auto s = t.trim();
       s = s.replaceCharacter(',', '.');
       double value = juce::jlimit(0.0, 2.0, s.getDoubleValue());
       return static_cast<float>(value);
   };

   // Empty unit label to let valueToText provide the formatted string (e.g., "1.20")
   auto lowWidth = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("c_LOW", versionHint),
                                                              "Low Width",
                                                              juce::NormalisableRange<float>(0.f, 2.f, 0.001f),
                                                              1.0f,
                                                              "",
                                                              juce::AudioParameterFloat::genericParameter,
                                                              widthToText,
                                                              widthFromText);

   auto midWidth = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("d_MED", versionHint),
                                                              "Mid Width",
                                                              juce::NormalisableRange<float>(0.f, 2.f, 0.001f),
                                                              1.0f,
                                                              "",
                                                              juce::AudioParameterFloat::genericParameter,
                                                              widthToText,
                                                              widthFromText);

   auto highWidth = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("e_HIGH", versionHint),
                                                               "High Width",
                                                               juce::NormalisableRange<float>(0.f, 2.f, 0.001f),
                                                               1.0f,
                                                               "",
                                                               juce::AudioParameterFloat::genericParameter,
                                                               widthToText,
                                                               widthFromText);

   // Controles SOLO: gestionados solo por UI (no en APVTS)
   auto bypass = std::make_unique<juce::AudioParameterBool>(juce::ParameterID("i_BYPASS", versionHint),
                                                           "Bypass",
                                                           false);

   auto inputMode = std::make_unique<juce::AudioParameterBool>(juce::ParameterID("j_input", versionHint),
                                                              "Input Mode",
                                                              false);

   auto outputMode = std::make_unique<juce::AudioParameterBool>(juce::ParameterID("q_output", versionHint),
                                                               "Output Mode",
                                                               false);

   // Balances por banda (0..1)
   auto lowBal = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("k_LOW_bal", versionHint),
                                                            "Low Bal",
                                                            juce::NormalisableRange<float>(0.f, 1.f, 0.001f),
                                                            0.5f);

   auto midBal = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("l_MED_bal", versionHint),
                                                            "Mid Bal",
                                                            juce::NormalisableRange<float>(0.f, 1.f, 0.001f),
                                                            0.5f);

   auto highBal = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("m_HIGH_bal", versionHint),
                                                             "High Bal",
                                                             juce::NormalisableRange<float>(0.f, 1.f, 0.001f),
                                                             0.5f);

   // Mute por banda (APVTS, automatizable si el host lo permite)
   auto muteLow = std::make_unique<juce::AudioParameterBool>(juce::ParameterID("n_MUTLOW", versionHint),
                                                            "Mute Low",
                                                            false);

   auto muteMid = std::make_unique<juce::AudioParameterBool>(juce::ParameterID("o_MUTMED", versionHint),
                                                            "Mute Mid",
                                                            false);

   auto muteHigh = std::make_unique<juce::AudioParameterBool>(juce::ParameterID("p_MUTHIGH", versionHint),
                                                             "Mute High",
                                                             false);

   // Dry/Wet + Trim + Makeup
   auto dryWet = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("x_DRYWET", versionHint),
                                                            "Dry/Wet",
                                                            juce::NormalisableRange<float>(0.f, 1.f, 0.001f),
                                                            1.0f,
                                                            "%",
                                                            juce::AudioParameterFloat::genericParameter,
                                                            [](float v, int)
                                                            {
                                                                return juce::String(static_cast<int>(v * 100)) + "%";
                                                            },
                                                            nullptr);

   auto trim = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("v_TRIM", versionHint),
                                                          "Trim",
                                                          juce::NormalisableRange<float>(-12.f, 12.f, 0.1f),
                                                          0.f,
                                                          "dB");

   auto makeup = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("w_MAKEUP", versionHint),
                                                             "Makeup",
                                                             juce::NormalisableRange<float>(-12.f, 12.f, 0.1f),
                                                             0.f,
                                                             "dB");

   params.push_back(std::move(freq1));         // a_FREQ1
   params.push_back(std::move(freq2));         // b_FREQ2
   params.push_back(std::move(lowWidth));      // c_LOW
   params.push_back(std::move(midWidth));      // d_MED
   params.push_back(std::move(highWidth));     // e_HIGH
   params.push_back(std::move(bypass));        // i_BYPASS
   params.push_back(std::move(inputMode));     // j_input
   params.push_back(std::move(outputMode));    // q_output
   params.push_back(std::move(lowBal));        // k_LOW_bal
   params.push_back(std::move(midBal));        // l_MED_bal
   params.push_back(std::move(highBal));       // m_HIGH_bal
   params.push_back(std::move(muteLow));       // n_MUTLOW
   params.push_back(std::move(muteMid));       // o_MUTMED
   params.push_back(std::move(muteHigh));      // p_MUTHIGH
   params.push_back(std::move(dryWet));        // x_DRYWET
   params.push_back(std::move(trim));          // v_TRIM
   params.push_back(std::move(makeup));        // w_MAKEUP

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

    if (parameterID == "q_output")
        uiOutputModeMS.store(v >= 0.5f ? 1 : 0, std::memory_order_release);
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

// El Imager no requiere función getGainReductionValue

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
void JCBImagerAudioProcessor::captureGoniometerData(const juce::AudioBuffer<float>& outputBuffer, int numSamples)
{
    // AUDIO-THREAD SAFE: intentar capturar sin bloquear el audio thread
    std::unique_lock<std::mutex> lock(goniometerMutex, std::try_to_lock);
    if (!lock.owns_lock())
        return;

    const int bufferCapacity = (int) goniometerBuffer.size();
    if (bufferCapacity == 0 || numSamples <= 0)
        return;

    const int chs = outputBuffer.getNumChannels();
    if (chs == 0)
        return;

    const float* L = outputBuffer.getReadPointer(0);
    const float* R = (chs > 1) ? outputBuffer.getReadPointer(1) : L;
    const bool outputIsMS = getUiOutputModeMS();

    constexpr int decimation = 4; // tomar una de cada N muestras para reducir carga

    for (int i = 0; i < numSamples; ++i)
    {
        if (++goniometerDecimationCounter < decimation)
            continue;

        goniometerDecimationCounter = 0;

        float mid;
        float side;

        if (outputIsMS)
        {
            mid  = L[i];
            side = R[i];
        }
        else
        {
            mid  = (L[i] + R[i]) * 0.70710678f;   // componente en fase (vertical)
            side = (L[i] - R[i]) * 0.70710678f;  // componente fuera de fase (horizontal)
        }

        auto& slot = goniometerBuffer[goniometerWriteIndex];
        slot.x = juce::jlimit(-1.2f, 1.2f, side);
        slot.y = juce::jlimit(-1.2f, 1.2f, mid);

        goniometerWriteIndex = (goniometerWriteIndex + 1) % bufferCapacity;
        if (goniometerValidSamples < bufferCapacity)
            ++goniometerValidSamples;
    }
}

void JCBImagerAudioProcessor::getGoniometerData(std::vector<juce::Point<float>>& samples) const
{
    std::lock_guard<std::mutex> lock(goniometerMutex);
    if (goniometerBuffer.empty() || goniometerValidSamples <= 0)
    {
        samples.clear();
        return;
    }

    const int capacity = (int) goniometerBuffer.size();
    const int count = juce::jmin(goniometerValidSamples, capacity);
    samples.resize((size_t) count);

    int start = goniometerWriteIndex - count;
    while (start < 0)
        start += capacity;

    for (int i = 0; i < count; ++i)
    {
        samples[(size_t) i] = goniometerBuffer[(start + i) % capacity];
    }
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

        // Imager: plugin sin parámetros legacy
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

                // Mantén las mismas correcciones si aplican al Imager
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

// El Imager no reporta gain reduction al host

//==============================================================================
// Timer implementation

//==============================================================================
// Format-specific implementations

// El Imager no incorpora medidores de gain reduction AAX

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
    // Actualizar latencia de forma thread-safe (reservado para futuros cambios)
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
    // El Imager no requiere lógica de gain reduction adicional
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
