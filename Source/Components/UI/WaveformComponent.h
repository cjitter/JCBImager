#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_graphics/juce_graphics.h>

//==============================================================================
/**
 * Componente de visualización de forma de onda para reverb
 * Muestra la señal seca (input) y la señal con reverb (output) superpuestas
 */
class WaveformComponent : public juce::Component,
                         private juce::Timer
{
public:
    WaveformComponent();
    ~WaveformComponent() override;

    //==============================================================================
    void paint(juce::Graphics& g) override;
    void resized() override;
    
    //==============================================================================
    // Actualizar datos de forma de onda
    void updateWaveformData(const std::vector<float>& inputSamples, 
                           const std::vector<float>& processedSamples);
    
    // Control de zoom vertical
    void setZoomEnabled(bool shouldZoom);
    bool getZoomEnabled() const noexcept { return zoomEnabled; }
    
    // Establecer el nivel de dry/wet para ajustar visualización
    void setDryWetMix(float mix) { dryWetMix = juce::jlimit(0.0f, 1.0f, mix); }
    
    // Establecer el tamaño de reverb para controlar el fade
    void setReverbSize(float size) { reverbSize = juce::jlimit(0.0f, 1.0f, size); }
    
    // Establecer la cantidad de reflexiones para controlar intensidad del fade
    void setReflectAmount(float amount) { reflectAmount = juce::jlimit(0.0f, 1.0f, amount); }

    // DAMP (0..1): amortiguación de agudos en el tanque
    void setDampAmount(float amount) { dampAmount = juce::jlimit(0.0f, 1.0f, amount); }

    // Anchura estéreo (M/S). 0 = estrecho, 1 = máxima apertura visual
    void setStereoWidth(float w) { stereoWidth = juce::jlimit(0.0f, 1.0f, w); }

    // Estado de FREEZE para resaltar la visualización de cola
    void setFreeze(bool on) {
        if (on && !freezeOn) freezeJustActivated = true;
        freezeOn = on;
        if (!freezeOn) freezeDryCaps.clear();
    }

private:
    void timerCallback() override;
    
    //==============================================================================
    // Buffers para historia de niveles RMS
    static constexpr int levelHistorySize = 120;  // Puntos de historia de niveles
    std::vector<float> inputLevels;              // Historia de niveles de entrada
    std::vector<float> outputLevels;             // Historia de niveles de salida  
    std::vector<float> tailLevels;               // Historia de cola (WET - DRY, >= 0)
    int writePos = 0;                             // Posición de escritura
    
    // Niveles actuales suavizados
    float currentInputLevel = 0.0f;
    float currentOutputLevel = 0.0f;
    float peakReverbLevel = 0.0f;  // Peak de diferencia para visualización
    float tailScaleSmoothed = 1.0f; // Escala suavizada para evitar blow-ups con silencio
    float activitySmoothed = 0.0f;  // Actividad global para decaimiento
    
    // Mutex para thread safety
    std::mutex dataLock;
    
    // Estado de visualización
    bool zoomEnabled = false;
    float dryWetMix = 0.5f;
    float reverbSize = 0.5f;
    float reflectAmount = 0.5f;  // Para controlar intensidad del fade
    float dampAmount = 0.0f;     // DAMP (mata brillo => cola más corta visualmente)
    float stereoWidth = 0.5f;    // M/S visual width
    bool freezeOn = false;       // FREEZE activo
    bool freezeJustActivated = false; // flanco de subida
    std::vector<float> freezeDryCaps; // snapshot de DRY por columna al activar FREEZE
    float freezeTailScale = 1.0f;   // escala para casar niveles al entrar en FREEZE
    float freezeBlend = 0.0f;       // progreso 0..1 para acercar escala a 1
    std::vector<float> smoothedBand; // suavizado temporal por columna
    
    // Colores del tema
    struct Colours
    {
        inline static const juce::Colour background{0xFF1A1A1A};
        inline static const juce::Colour gridLines{0xFF303030};
        inline static const juce::Colour inputWaveform{0x66FFFFFF};  // Gris semi-transparente
        inline static const juce::Colour outputWaveform{0xFF9E35B0}; // Púrpura principal
        inline static const juce::Colour reverbTail{0x669E35B0};     // Púrpura semi-transparente para área
        inline static const juce::Colour freezeAccent{0xFF2BC0A4};   // Acento para FREEZE
    };

    // Animación leve para simular densidad de reflexiones
    float shimmerPhase = 0.0f;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveformComponent)
};
