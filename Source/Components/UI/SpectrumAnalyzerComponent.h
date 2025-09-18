#pragma once
#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_core/juce_core.h>
#include <juce_graphics/juce_graphics.h>
#include <juce_dsp/juce_dsp.h>
#include <array>
#include <atomic>
#include <mutex>
#include <thread>
#include <chrono>

class SpectrumAnalyzerComponent : public juce::Component,
                                  public juce::Timer,
                                  public juce::TooltipClient,
                                  private juce::AudioProcessorValueTreeState::Listener
{
public:
    SpectrumAnalyzerComponent(juce::AudioProcessorValueTreeState& apvts);
    
    // Actualiza sample rate para mapeo de frecuencia correcto
    void setSampleRate(double newSampleRate) noexcept;
    ~SpectrumAnalyzerComponent() override;
    
    void paint(juce::Graphics& g) override;
    void timerCallback() override;
    void mouseMove(const juce::MouseEvent& event) override;
    void mouseDown(const juce::MouseEvent& event) override;
    void mouseDrag(const juce::MouseEvent& event) override;
    void mouseUp(const juce::MouseEvent& event) override;
    void mouseDoubleClick(const juce::MouseEvent& event) override;
    
    // Interfaz TooltipClient
    juce::String getTooltip() override;
    
    // Mono (compat) y estéreo
    void pushNextSampleIntoFifo(float sample) noexcept;
    void pushNextStereoSample(float left, float right) noexcept;
    void setBypassMode(bool enabled) noexcept;
    
    // Alternador de escala de frecuencia
    enum class FrequencyScale {
        Linear,
        Logarithmic
    };
    
    void setFrequencyScale(FrequencyScale scale) noexcept;
    FrequencyScale getFrequencyScale() const noexcept { return currentScale; }
    
    // Control de zoom para modo FFT
    void setZoomEnabled(bool enabled) noexcept;
    bool getZoomEnabled() const noexcept { return zoomEnabled; }
    
private:
    // Referencia a APVTS para gestión de parámetros
    juce::AudioProcessorValueTreeState& valueTreeState;
    
    // Configuración FFT - Alta resolución para análisis profesional
    static constexpr auto fftOrder = 11;  // 2048 puntos (resolución aumentada)
    static constexpr auto fftSize = 1 << fftOrder;
    static constexpr auto scopeSize = 512;  // Resolución visual
    
    // Configuración de rango de display - Fácil de modificar
    static constexpr float defaultMinDB = -80.0f;  // Límite inferior rango completo
    static constexpr float defaultMaxDB = 0.0f;    // Límite superior rango completo
    static constexpr float zoomedMinDB = -48.0f;   // Límite inferior con zoom
    static constexpr float zoomedMaxDB = 0.0f;     // Límite superior con zoom
    
    // Componentes FFT
    juce::dsp::FFT forwardFFT;
    juce::dsp::WindowingFunction<float> window;
    
    // Buffers de datos - Diseño lock-free
    // Buffers L/R
    std::array<float, fftSize> fifoL, fifoR;
    std::array<float, fftSize> fftCopyL, fftCopyR;  // Buffers intermedios para thread de audio
    std::array<float, fftSize * 2> fftData;         // Buffer de procesamiento reutilizable
    std::array<float, scopeSize> scopeDataL, scopeDataR;
    std::array<float, scopeSize> copyScopeDataL, copyScopeDataR;  // Copias thread-safe para pintar
    std::array<float, scopeSize> peakHoldDataL, peakHoldDataR;
    
    // Gestión de estado thread-safe
    std::atomic<int> fifoIndex{0};
    std::atomic<bool> nextFFTBlockReady{false};
    std::atomic<bool> bypassMode{false};
    std::atomic<bool> zoomEnabled{false};
    FrequencyScale currentScale = FrequencyScale::Logarithmic;
    std::atomic<double> currentSampleRate{44100.0};
    std::atomic<int> peakHoldCounter{0};
    static constexpr int peakHoldFrames = 60;  // Mantener picos por ~2 segundos a 30 FPS
    
    // Variables para visualización del crossover
    std::atomic<float> crossoverLowFreq{250.0f};   // Frecuencia XLow (j_HPF)
    std::atomic<float> crossoverHighFreq{5000.0f}; // Frecuencia XHigh (k_LPF)
    std::atomic<float> selectedBand{1.0f};         // Banda seleccionada (o_BAND: 0=low, 1=mid, 2=high)
    std::atomic<bool> filtersEnabled{false};       // Estado del botón FILTERS (l_SC)
    std::atomic<float> tiltValue{0.0f};            // Valor del tilt EQ (-6 a +6 dB)
    
    // Flags de seguridad de threads (sin mutex en thread de audio)
    std::atomic<bool> scopeDataReady{false};
    std::atomic<bool> isDestroying{false};
    
    // Variables para interacción con líneas de crossover
    std::atomic<bool> isDraggingLowFreq{false};
    std::atomic<bool> isDraggingHighFreq{false};
    std::atomic<bool> isHoveringLowFreq{false};
    std::atomic<bool> isHoveringHighFreq{false};
    std::atomic<int> hoveringBandIndex{-1};  // -1=ninguna, 0=low, 1=mid, 2=high
    float dragStartValue{0.0f};  // Para undo/redo
    juce::RangedAudioParameter* currentDragParameter{nullptr};  // Parámetro siendo arrastrado
    
    // Mutex para thread GUI (nunca usado en thread de audio)
    mutable std::mutex guiMutex;
    
    
    // Métodos internos
    void parameterChanged(const juce::String& parameterID, float newValue) override;
    void drawNextFrameOfSpectrum(std::array<float, scopeSize>& scopeDest,
                                 std::array<float, scopeSize>& peakHoldDest,
                                 const std::array<float, fftSize>& fftCopySrc);
    void drawFrame(juce::Graphics& g, const juce::Rectangle<int>& bounds);
    
    // Helpers para líneas interactivas
    float mapXToFrequency(float xPos, float width) const noexcept;
    float mapFrequencyToX(float freq, float width) const noexcept;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SpectrumAnalyzerComponent)
};
