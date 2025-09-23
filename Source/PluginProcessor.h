//==============================================================================
//
//  Copyright 2025 Juan Carlos Blancas
//  This file is part of JCBImager and is licensed under the GNU General Public License v3.0 or later.
//
//==============================================================================
#pragma once

//==============================================================================
// INCLUDES
//==============================================================================
// Módulos JUCE
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_core/juce_core.h>

// Librerías estándar C++
#include <mutex>
#include <vector>
#include <unordered_map>
#include <array>
#include <atomic>
#include <functional>
#include <cmath>

// Archivos del proyecto
#include "JCBImager.h"
#include "Helpers/MovingAverage4800.h"

using namespace juce;

//==============================================================================
// CLASE PRINCIPAL DEL PROCESADOR
//==============================================================================
class JCBImagerAudioProcessor : public juce::AudioProcessor,
                                    public juce::AudioProcessorValueTreeState::Listener,
                                    private juce::Timer,
                                    private juce::AsyncUpdater
{
public:
    //==============================================================================
    // Constructor y destructor
    JCBImagerAudioProcessor();
    ~JCBImagerAudioProcessor() override;
    
    //==============================================================================
    // Métodos principales del AudioProcessor
    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    
    bool isBusesLayoutSupported(const juce::AudioProcessor::BusesLayout& layouts) const override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    void processBlockBypassed(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    
    //==============================================================================
    // Gestión del editor
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const noexcept override { return true; }
    
    //==============================================================================
    // Propiedades básicas del plugin
    const juce::String getName() const noexcept override { return JucePlugin_Name; }
    
    bool acceptsMidi() const noexcept override { return false; }
    bool producesMidi() const noexcept override { return false; }
    bool silenceInProducesSilenceOut() const noexcept override { return false; }
    double getTailLengthSeconds() const noexcept override { return 5.0; }
    
    //==============================================================================
    // Gestión de presets/programs
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String& newName) override;
    
    //==============================================================================
    // Serialización del estado
    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;
    
    //==============================================================================
    // FFT Spectrum Analyzer Support
    std::function<void(float)> spectrumAnalyzerCallback;
    std::function<void(float,float)> spectrumAnalyzerCallbackStereo;
    std::function<void(double)> sampleRateChangedCallback;
    void setSpectrumAnalyzerCallback(std::function<void(float)> callback) { spectrumAnalyzerCallback = callback; }
    void setSpectrumAnalyzerCallbackStereo(std::function<void(float,float)> callback) { spectrumAnalyzerCallbackStereo = callback; }
    void setSampleRateChangedCallback(std::function<void(double)> callback) { sampleRateChangedCallback = callback; }
    double getCurrentSampleRate() const noexcept { return m_PluginState ? m_PluginState->sr : 44100.0; }
    
    //==============================================================================
    // Reverb: no requiere reportes de gain reduction
    
    #if JucePlugin_Build_VST3
    void updateVST3GainReduction();
    #endif
    
    #if JucePlugin_Build_AU
    // AU: reducción de ganancia expuesta a través del wrapper
    #endif
    
    //==============================================================================
    // APVTS y gestión de parámetros
    juce::AudioProcessorValueTreeState apvts;
    void parameterChanged(const juce::String& parameterID, float newValue) override;
    
    //==============================================================================
    // Gestión de estado de la interfaz
    juce::Point<int> getSavedSize() const noexcept { return editorSize; }
    void setSavedSize(const juce::Point<int>& size) noexcept { editorSize = size; }
    
    int getLastPreset() const noexcept { return lastPreset; }
    void setLastPreset(const int& presetID) noexcept { lastPreset = presetID; }
    
    // Estado del menú de presets
    juce::String getPresetDisplayText() const noexcept { return presetDisplayText; }
    void setPresetDisplayText(const juce::String& text) noexcept { presetDisplayText = text; }
    bool getPresetTextItalic() const noexcept { return presetTextItalic; }
    void setPresetTextItalic(bool italic) noexcept { presetTextItalic = italic; }
    
    // Detección de formato del DAW
    bool isProTools() const noexcept;
    juce::String getPluginFormat() const noexcept;
    
    // Estado de tooltips e idioma
    bool getTooltipEnabled() const noexcept { return tooltipEnabled; }
    void setTooltipEnabled(bool enabled) noexcept { tooltipEnabled = enabled; }
    bool getEnvelopeVisualEnabled() const noexcept { return envelopeVisualEnabled; }
    void setEnvelopeVisualEnabled(bool enabled) noexcept { envelopeVisualEnabled = enabled; }
    bool getTooltipLanguageEnglish() const noexcept { return tooltipLanguageEnglish; }
    void setTooltipLanguageEnglish(bool english) noexcept { tooltipLanguageEnglish = english; }

    void setUiOutputModeMS(bool enabled) noexcept { uiOutputModeMS.store(enabled ? 1 : 0, std::memory_order_release); }
    bool getUiOutputModeMS() const noexcept { return uiOutputModeMS.load(std::memory_order_acquire) != 0; }
    
    // Métodos de comparación A/B
    void saveCurrentStateToActive();
    void toggleAB();
    void copyAtoB();
    void copyBtoA();
    bool getIsStateA() const noexcept { return isStateA; }
    
    // Acceso al UndoManager de GUI
    juce::UndoManager& getGuiUndoManager() noexcept { return guiUndoManager; }
    
    //==============================================================================
    // Medidores de audio
    float getRmsInputValue(const int channel) const noexcept;
    float getRmsOutputValue(const int channel) const noexcept;
    
    // Detección de clipping
    bool getInputClipDetected(const int channel) const noexcept;
    bool getOutputClipDetected(const int channel) const noexcept;
    void resetClipIndicators();

    // Datos para visualización de goniometer
    void getGoniometerData(std::vector<juce::Point<float>>& samples) const;

    // Sistema híbrido: timestamp + playhead para detección más robusta
    bool isPlaybackActive() const noexcept;
    
    //==============================================================================
    // Métodos de parámetros legacy
    int getNumParameters() override;
    float getParameter(int index) override;
    void setParameter(int index, float newValue) override;
    const juce::String getParameterName(int index) override;
    const juce::String getParameterText(int index) override;
    
    //==============================================================================
    // Métodos de canales
    const juce::String getInputChannelName(int channelIndex) const override;
    const juce::String getOutputChannelName(int channelIndex) const override;
    bool isInputChannelStereoPair(int index) const override;
    bool isOutputChannelStereoPair(int index) const override;
    
    // Acceso al estado de Gen~ (para sincronización directa)
    CommonState* getPluginState() const { return m_PluginState; }
    
    // Verificar si el processor está completamente inicializado
    bool isInitialized() const noexcept { return m_PluginState != nullptr; }
    
private:
    //==============================================================================
    // UndoManager separado para GUI
    juce::UndoManager guiUndoManager;
    
    //==============================================================================
    // Integración Gen~
    void assureBufferSize(long bufferSize);
    void fillGenInputBuffers(const juce::AudioBuffer<float>& buffer);
    void processGenAudio(int numSamples);
    void fillOutputBuffers(juce::AudioBuffer<float>& buffer);

    //==============================================================================
    void processBlockCommon(juce::AudioBuffer<float>& buffer, bool hostWantsBypass);

    // Safety: sanitize audio to avoid NaN/Inf blasts (hard limiter + finite check)
    // COMMENTED OUT - Gen~ issue fixed, no longer needed
    /*
    inline void sanitizeStereo(float* left, float* right, int numSamples) noexcept
    {
        // Replace non‑finite with 0; clamp to safe headroom just below 0 dBFS
        constexpr float absKillThreshold = 8.0f;  // anything above is likely runaway -> kill to 0.0f
        constexpr float hardLimit = 0.99f;        // final hard ceiling to prevent host blast
        for (int i = 0; i < numSamples; ++i)
        {
            float l = left[i];
            float r = right ? right[i] : l;

            // Non‑finite -> mute sample
            if (!std::isfinite(l)) l = 0.0f;
            if (!std::isfinite(r)) r = 0.0f;

            // Kill outrageous spikes (likely unstable state)
            if (std::abs(l) > absKillThreshold) l = 0.0f;
            if (std::abs(r) > absKillThreshold) r = 0.0f;

            // Final hard ceiling
            if (l > hardLimit) l = hardLimit;
            else if (l < -hardLimit) l = -hardLimit;

            if (r > hardLimit) r = hardLimit;
            else if (r < -hardLimit) r = -hardLimit;

            left[i] = l;
            if (right) right[i] = r;
        }
    }
    */

    inline void sanitizeStereo (float* L, float* R, int n, std::atomic<bool>& tripped) noexcept
    {
        bool localTrip = false;
        for (int i = 0; i < n; ++i)
        {
            float xL = L[i];
            float xR = R ? R[i] : xL;

            if (!std::isfinite(xL) || xL > 8.f || xL < -8.f) { xL = 0.f; localTrip = true; }
            if (!std::isfinite(xR) || xR > 8.f || xR < -8.f) { xR = 0.f; localTrip = true; }

            L[i] = xL; if (R) R[i] = xR;
        }
        if (localTrip) tripped.store(true, std::memory_order_release);
    }

    // Actualizaciones de medidores
    void updateInputMeters(const juce::AudioBuffer<float>& buffer);
    void updateOutputMeters(const juce::AudioBuffer<float>& buffer);

    void captureGoniometerData(const juce::AudioBuffer<float>& outputBuffer, int numSamples);
    
    // Detección de clipping
    void updateClipDetection(const juce::AudioBuffer<float>& inputBuffer, const juce::AudioBuffer<float>& outputBuffer);
    
    // Gestión de layout y buses
    juce::AudioProcessor::BusesProperties createBusesProperties();
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();
    
    //==============================================================================
    // Estado Gen~
    CommonState* m_PluginState;
    long m_CurrentBufferSize;
    t_sample** m_InputBuffers;
    t_sample** m_OutputBuffers;
    
    // Valores de medidores thread-safe
    std::atomic<float> leftInputRMS{-100.0f};
    std::atomic<float> rightInputRMS{-100.0f};
    std::atomic<float> leftOutputRMS{-100.0f};
    std::atomic<float> rightOutputRMS{-100.0f};

    // Buffers auxiliares
    juce::AudioBuffer<float> trimInputBuffer;
    
    // Buffers para goniometer (vectorescope)
    mutable std::vector<juce::Point<float>> goniometerBuffer;
    mutable std::mutex goniometerMutex;
    int goniometerWriteIndex{0};
    int goniometerValidSamples{0};
    int goniometerDecimationCounter{0};
    
    // Gestión de estado
    juce::Point<int> editorSize{1250, 350};
    int lastPreset{0};
    int currentProgram{-1};
    
    // Estado del menú de presets
    juce::String presetDisplayText{"DEFAULT"};
    bool presetTextItalic{false};
    
    bool tooltipEnabled{true};
    bool envelopeVisualEnabled{true};
    bool tooltipLanguageEnglish{false};
    
    // Estado de detección de clipping
    std::atomic<bool> inputClipDetected[2] = {false, false};
    std::atomic<bool> outputClipDetected[2] = {false, false};

    // Flag para indicar destrucción del plugin
    std::atomic<bool> isBeingDestroyed{false};

    //==============================================================================
    // Timer callback para actualizaciones fuera del audio thread
    void timerCallback() override;
    
    // Sistema de comparación A/B
    struct ParameterState {
        std::unordered_map<juce::String, float> values;
        
        void captureFrom(const juce::AudioProcessorValueTreeState& apvts) {
            values.clear();
            auto& params = apvts.processor.getParameters();
            for (auto* param : params) {
                if (auto* p = dynamic_cast<juce::AudioProcessorParameterWithID*>(param)) {
                    values[p->paramID] = p->getValue();
                }
            }
        }
        
        void applyTo(juce::AudioProcessorValueTreeState& apvts) const {
            for (const auto& [id, value] : values) {
                if (auto* param = apvts.getParameter(id)) {
                    param->setValueNotifyingHost(value);
                }
            }
        }
    };
    
    ParameterState stateA;
    ParameterState stateB;
    bool isStateA{true};
    
    //==============================================================================
    // SISTEMA DE BYPASS SUAVE - Implementación sin lookahead/latencia
    //==============================================================================
    
    // --- Scratch Buffers RT-safe ---
    juce::AudioBuffer<float> scratchIn;          // Buffer temporal para entrada (2ch: L/R)
    juce::AudioBuffer<float> scratchDry;         // Buffer temporal para DRY (2ch: L/R)
    int scratchCapacitySamples { 0 };            // Capacidad actual de los scratch buffers
    
    // Helper: asegura capacidad de scratch sin allocations en audio thread
    inline void ensureScratchCapacity(int numSamples)
    {
        if (numSamples > scratchCapacitySamples)
        {
            scratchIn.setSize(2, numSamples, false, false, true);
            scratchDry.setSize(2, numSamples, false, false, true);
            scratchIn.clear();
            scratchDry.clear();
            scratchCapacitySamples = numSamples;
        }
    }
    
    // --- FSM de Bypass con Fade ---
    enum class BypassState { Active, FadingToBypass, Bypassed, FadingToActive };
    BypassState bypassState { BypassState::Active };  // Estado actual del bypass
    int bypassFadeLen  { 384 };                        // Longitud del fade en samples (~7ms @ 48kHz)
    float bypassFadeMs { 7.0f };                      // Duración del fade en ms
    int bypassFadePos  { 0 };                          // Posición actual del fade (0 a bypassFadeLen)
    
    // --- Control y sincronización ---
    std::atomic<bool> hostBypassMirror { false };   // Espejo atómico del estado de bypass del host
    bool lastWantsBypass { false };                   // Estado anterior para detección de flancos
    //int consecutiveWetSilent { 0 };                   // Contador de bloques con WET ~0 y entrada con señal
    bool lastHostIsPlaying { false };                 // Estado previo del transporte
    int playStartWarmupBlocks { 0 };                  // Ventana breve tras start

    // Diagnóstico: contadores de failsafe y resets
    std::atomic<int> diagFailsafeCount { 0 };
    std::atomic<int> diagGenResets { 0 };
    std::atomic<int> silentL{0}, silentR{0};
public:
    int getDiagFailsafeCount() const noexcept { return diagFailsafeCount.load(std::memory_order_relaxed); }
    int getDiagGenResets() const noexcept { return diagGenResets.load(std::memory_order_relaxed); }
    void resetDiagnostics() noexcept { diagFailsafeCount.store(0); diagGenResets.store(0); }
    
    // Helper para leer el parámetro de bypass del host
    inline bool isHostBypassed() const noexcept
    {
        if (auto* p = getBypassParameter())  // JUCE crea un parámetro estándar de bypass
            return p->getValue() >= 0.5f;            // 0..1
        return false;
    }
    
    // Método común de procesamiento con bypass suave
    //void processBlockCommon(juce::AudioBuffer<float>& buffer, bool hostWantsBypass);
    //void processBlockBypassed(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    // Override de AsyncUpdater para actualizaciones thread-safe
    void handleAsyncUpdate() override;
    
    // Sistema de latencia (aunque reverb normalmente no tiene)
    std::atomic<int> pendingLatency { 0 };
    int currentLatency = 0;

    // Cachear índices de gen (evitar bubles por nombre)
    int genIdxZBypass  { -1 }; // i_BYPASS index in Gen (internal)
    int genIdxDryWet   { -1 }; // x_DRYWET index in Gen (debug force wet)
    int genIdxFreeze   { -1 }; // optional param in some patches
    // Fast lookup for UI-only controls
    int genIdxMuteLow  { -1 };
    int genIdxMuteMid  { -1 };
    int genIdxMuteHigh { -1 };
    int genIdxSoloLow  { -1 };
    int genIdxSoloMid  { -1 };
    int genIdxSoloHigh { -1 };
    std::unordered_map<juce::String, int> genIndexByName; // lookup seguro para UI→AT
    // Mirror UI-only states (atomics, written by UI, consumed by AT)
    std::atomic<int> uiSoloLow  { 0 }, uiSoloMid  { 0 }, uiSoloHigh { 0 };
    std::atomic<int> uiMuteLow  { 0 }, uiMuteMid  { 0 }, uiMuteHigh { 0 };
    std::atomic<int> uiOutputModeMS { 0 };

public:
    // UI-safe: encolar cambio de parámetro por nombre para aplicarlo en audio thread
    void pushGenParamByName(const juce::String& name, float value) noexcept
    {
        auto it = genIndexByName.find(name);
        if (it != genIndexByName.end()) { pushParamToAudioThread(it->second, value); return; }
        // Fallback: buscar por nombre y cachear (RT-safe: no se llama en audio thread)
        if (m_PluginState != nullptr)
        {
            for (int i = 0; i < JCBImager::num_params(); ++i)
            {
                const char* raw = JCBImager::getparametername(m_PluginState, i);
                if (raw && name == juce::String(raw)) { genIndexByName[name] = i; pushParamToAudioThread(i, value); return; }
            }
        }
    }

    // UI-safe: encolar por índice (si ya está cacheado)
    void pushGenParamByIndex(int idx, float value) noexcept
    {
        if (idx >= 0) pushParamToAudioThread(idx, value);
    }


    // Especial para la reverb

    // --- Cola lock-free de cambios de parámetro (SP/MP -> AudioThread) ---
    struct PendingParam { int idx; float v; };

    static constexpr uint32_t kQSize = 256;           // potencia de 2
    static constexpr uint32_t kQMask = kQSize - 1;

    std::atomic<uint32_t> paramQHead { 0 };           // escribe MT
    std::atomic<uint32_t> paramQTail { 0 };           // consume AT
    PendingParam          paramQ[kQSize];             // buffer circular

    inline void pushParamToAudioThread (int idx, float v) noexcept
    {
        uint32_t h  = paramQHead.load(std::memory_order_relaxed);
        uint32_t nh = (h + 1u) & kQMask;

        // Si está llena, descarta el más viejo (avanza tail) para no bloquear
        if (nh == paramQTail.load(std::memory_order_acquire))
            paramQTail.store((paramQTail.load(std::memory_order_relaxed) + 1u) & kQMask,
                             std::memory_order_release);

        paramQ[h] = { idx, v };
        paramQHead.store(nh, std::memory_order_release);
    }

    inline void drainPendingParamsToGen() noexcept
    {
        uint32_t t = paramQTail.load(std::memory_order_relaxed);
        const uint32_t h = paramQHead.load(std::memory_order_acquire);

        while (t != h)
        {
            const PendingParam pp = paramQ[t];
            // Aplicar de forma atómica en el audio thread
            JCBImager::setparameter(m_PluginState, pp.idx, pp.v, nullptr);
            t = (t + 1u) & kQMask;
        }
        paramQTail.store(t, std::memory_order_release);
    }

    std::atomic<bool> nanTripped { false };
    std::atomic<int> consecutiveWetSilent { 0 };
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(JCBImagerAudioProcessor)
};
