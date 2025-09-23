//==============================================================================
//
//  Copyright 2025 Juan Carlos Blancas
//  This file is part of JCBImager and is licensed under the GNU General Public License v3.0 or later.
//
//==============================================================================

//==============================================================================
// INCLUDES
//==============================================================================
// Módulos JUCE
#include <juce_graphics/juce_graphics.h>

// Librerías estándar C++
#include <mutex>
#include <algorithm>

// Archivos del proyecto
#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "Components/Windows/CreditsWindow.h"
#include "Components/Windows/CodeWindow.h"
#include "Helpers/UTF8Helper.h"
#include "BinaryData.h"

//==============================================================================
// LISTENER CLASSES IMPLEMENTATION
//==============================================================================

// Base class for parameter listeners with thread-safe GUI updates
class ParameterListenerBase : public juce::AudioProcessorValueTreeState::Listener
{
public:
    explicit ParameterListenerBase(JCBImagerAudioProcessorEditor* e) : editor(e) {}
    virtual ~ParameterListenerBase() = default;
    
protected:
    JCBImagerAudioProcessorEditor* editor;
};

// Listener legacy (no usado en Imager) - mantenido pero desactivado
class JCBImagerAudioProcessorEditor::SidechainParameterListener : public ParameterListenerBase
{
public:
    explicit SidechainParameterListener(JCBImagerAudioProcessorEditor* e) : ParameterListenerBase(e) {}
    void parameterChanged(const juce::String& parameterID, float newValue) override
    {
        juce::ignoreUnused(newValue);
        juce::MessageManager::callAsync([safeEditor = juce::Component::SafePointer(editor), parameterID]() {
            if (! safeEditor) return;
            if (parameterID == "y_FILTERS")
                safeEditor->updateSidechainComponentStates();
            else if (parameterID == "q_ONOFFEQ")
                safeEditor->updateEqComponentStates();
            else if (parameterID == "r_ONOFFCOMP")
                safeEditor->updateCompComponentStates();
        });
    }
};


//==============================================================================
// CONSTRUCTOR Y DESTRUCTOR
//==============================================================================
JCBImagerAudioProcessorEditor::JCBImagerAudioProcessorEditor (JCBImagerAudioProcessor& p, juce::UndoManager& um)
    : AudioProcessorEditor (&p), 
      processor (p), 
      undoManager (um),
      spectrumAnalyzer(processor.apvts),          // Inicializar spectrum analyzer
      inputMeterL([]() { return -100.0f; }),      // Safe dummy value for input meters  
      inputMeterR([]() { return -100.0f; }),      // Safe dummy value for input meters
      outputMeterL([]() { return -100.0f; }),     // Safe dummy value for output meters
      outputMeterR([]() { return -100.0f; })      // Safe dummy value for output meters
{
    // Inicializar LookAndFeel personalizado para botones
    soloButtonLAF = std::make_unique<SoloButtonLookAndFeel>();
    muteButtonLAF = std::make_unique<MuteButtonLookAndFeel>();
    modeButtonLAF = std::make_unique<ModeButtonLookAndFeel>();
    reversedGradientButtonLAF = std::make_unique<ReversedGradientButtonLookAndFeel>();
    tealGradientButtonLAF = std::make_unique<TealGradientButtonLookAndFeel>();
    coralGradientButtonLAF = std::make_unique<CoralGradientButtonLookAndFeel>();
    
    // Configurar todos los componentes
    setupBackground();
    setupKnobs();
    setupMeters();
    // setupSidechainControls();
    setupPresetArea();
    setupUtilityButtons();
    setupParameterButtons();
    // No right-side tabs for Imager (EQ/COMP removed)
    setupRightTabs();

    // Agregar título y versión - mismo estilo que ExpansorGate
    auto titleFont = juce::Font(juce::FontOptions(22.0f));
    titleLink.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    titleLink.setColour(juce::TextButton::buttonOnColourId, juce::Colours::transparentBlack);
    titleLink.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.7f));
    titleLink.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    
    // Detectar si estamos en Logic Pro para mostrar solo la versión
    juce::String titleText;
    
    // Verificar si el host es Logic Pro
    juce::PluginHostType hostInfo;
    if (hostInfo.isLogic()) {
        titleText = "v1.0.0-alpha.1";  // Solo versión para Logic Pro
    } else {
        titleText = "JCBImager v1.0.0-alpha.1";  // Nombre completo para otros DAWs
    }

#if defined(JCB_DEBUG_MUTE_OUTPUT)
    titleText += " [MUTE]";
#elif defined(JCB_DEBUG_PASSTHROUGH)
    titleText += " [PT]";
#endif
    
    titleLink.setButtonText(titleText);
    // NO agregar tooltip individual - solo usar la ventana general de tooltips
    // El tooltip se actualiza dinámicamente en updateTooltips() usando getTooltipText("title")
    titleLink.setTooltip("");
    
    // Configurar el click para mostrar créditos
    titleLink.onClick = [this]() {
        showCredits();
    };
    
    addAndMakeVisible(titleLink);
    
    // Agregar analizador de espectro
    addAndMakeVisible(spectrumAnalyzer);
    spectrumAnalyzer.setVisible(true);

    // Agregar goniometer (vectorscope)
    addAndMakeVisible(goniometerDisplay);
    goniometerDisplay.setVisible(true);

    // Agregar tooltip
    addAndMakeVisible(tooltipComponent);
    tooltipComponent.setAlwaysOnTop(true);
    tooltipComponent.showTip(JUCE_UTF8("Pasa el mouse sobre los controles\npara ver ayuda detallada"));

    // Establecer tamaño inicial con restricciones
    auto savedSize = processor.getSavedSize();
    int initialWidth = savedSize.x > 0 ? savedSize.x : DEFAULT_WIDTH;
    int initialHeight = savedSize.y > 0 ? savedSize.y : DEFAULT_HEIGHT;
    
    setSize(initialWidth, initialHeight);
    setResizable(true, true);
    
    // Inicializar el estado del tamaño basado en las dimensiones iniciales
    if (initialWidth == DEFAULT_WIDTH && initialHeight == DEFAULT_HEIGHT) {
        currentSizeState = GuiSizeState::Current;
    } else if (initialWidth == MIN_WIDTH && initialHeight == MIN_HEIGHT) {
        currentSizeState = GuiSizeState::Minimum;
    } else if (initialWidth == MAX_WIDTH && initialHeight == MAX_HEIGHT) {
        currentSizeState = GuiSizeState::Maximum;
    } else {
        // Para tamaños personalizados, usar estado Current por defecto
        currentSizeState = GuiSizeState::Current;
        lastCustomSize = {initialWidth, initialHeight};
    }

    // Establecer límites de redimensionado - valores exactos de JCBExpansorGate
    setResizeLimits(MIN_WIDTH, MIN_HEIGHT, MAX_WIDTH, MAX_HEIGHT);
    getConstrainer()->setFixedAspectRatio(ASPECT_RATIO);
    
    // Inicializar cache de contenido de código para thread safety
    initializeCodeContentCache();
    
    // Timer para resetear indicadores de clip cada cierto tiempo
    clipResetCounter = 0;

    // Configurar estado inicial del idioma
    if (processor.getTooltipLanguageEnglish()) {
        currentLanguage = TooltipLanguage::English;
        utilityButtons.tooltipLangButton.setButtonText("eng");
        utilityButtons.tooltipLangButton.setColour(juce::TextButton::textColourOffId, DarkTheme::accentSecondary);
    } else {
        currentLanguage = TooltipLanguage::Spanish;
        utilityButtons.tooltipLangButton.setButtonText("esp");
        utilityButtons.tooltipLangButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    }

    // Actualizar todos los tooltips basado en idioma inicial
    updateAllTooltips();

    // Configurar estados iniciales
    updateButtonStates();
    updateFilterButtonText();  // Establecer texto inicial de botones de filtro

    // Actualizar valores de sliders desde APVTS para evitar problemas al cargar sesión
    // Usar MessageManager::callAsync para ejecución thread-safe sin delay
    juce::MessageManager::callAsync([safeThis = juce::Component::SafePointer<JCBImagerAudioProcessorEditor>(this)]() {
        if (safeThis) {
            safeThis->updateSliderValues();
        }
    });
    
    // Configurar estado inicial del tooltip toggle y language button
    bool initialTooltipState = processor.getTooltipEnabled();
    tooltipsEnabled = initialTooltipState;
    tooltipComponent.setTooltipsEnabled(tooltipsEnabled);
    utilityButtons.tooltipToggleButton.setToggleState(tooltipsEnabled, juce::dontSendNotification);
    
    // Habilitar/deshabilitar botón de idioma según estado de tooltips
    utilityButtons.tooltipLangButton.setEnabled(tooltipsEnabled);
    utilityButtons.tooltipLangButton.setAlpha(tooltipsEnabled ? 1.0f : 0.25f);
    
    // Aplicar estados iniciales de todos los modos en el orden correcto
    //updateButtonStates();

    // CRASH FIX: Configurar las funciones reales de los medidores DESPUÉS de toda la inicialización
    // Esto evita accesos prematuros a valores atómicos del processor durante la construcción
    inputMeterL.setValueFunction([this](){ return processor.isInitialized() ? processor.getRmsInputValue(0) : -100.0f; });
    inputMeterR.setValueFunction([this](){ return processor.isInitialized() ? processor.getRmsInputValue(1) : -100.0f; });
    outputMeterL.setValueFunction([this](){ return processor.isInitialized() ? processor.getRmsOutputValue(0) : -100.0f; });
    outputMeterR.setValueFunction([this](){ return processor.isInitialized() ? processor.getRmsOutputValue(1) : -100.0f; });

    // No registrar listeners de parámetros legacy (y_FILTERS, q_ONOFFEQ, r_ONOFFCOMP) en Imager
    
    // Connect spectrum analyzer callback to processor
    processor.setSpectrumAnalyzerCallbackStereo([this](float l, float r) {
        spectrumAnalyzer.pushNextStereoSample(l, r);
    });
    
    // Connect sample rate change callback
    processor.setSampleRateChangedCallback([this](double newSampleRate) {
        spectrumAnalyzer.setSampleRate(newSampleRate);
    });
    
    // Initialize spectrum analyzer with current sample rate
    spectrumAnalyzer.setSampleRate(processor.getCurrentSampleRate());

    // Iniciar helper timer seguro (usa WeakReference)
    uiTimer = std::make_unique<UiTimer>(*this);
    // No right-side tabs in Imager; ensure panel content stays hidden
    updateRightPanelVisibility();

    spectrumAnalyzer.setBandSoloCallback([this](int bandIndex)
    {
        bool low  = imager.soloLow.getToggleState();
        bool mid  = imager.soloMid.getToggleState();
        bool high = imager.soloHigh.getToggleState();

        switch (bandIndex)
        {
            case 0:
            {
                bool newState = !low;
                low = newState;
                if (newState)
                {
                    mid = false;
                    high = false;
                }
                break;
            }
            case 1:
            {
                bool newState = !mid;
                mid = newState;
                if (newState)
                {
                    low = false;
                    high = false;
                }
                break;
            }
            case 2:
            {
                bool newState = !high;
                high = newState;
                if (newState)
                {
                    low = false;
                    mid = false;
                }
                break;
            }
            default:
                return;
        }

        setSoloState(low, mid, high);
    });

    setGoniometerHold(false, true);
}

//==============================================================================
// IMPLEMENTACIÓN DE SOLOBUTTONLOOKANDFEEL
//==============================================================================
void JCBImagerAudioProcessorEditor::SoloButtonLookAndFeel::drawButtonBackground(
    juce::Graphics& g, juce::Button& button,
    const juce::Colour& backgroundColour,
    bool shouldDrawButtonAsHighlighted,
    bool shouldDrawButtonAsDown)
{
    auto bounds = button.getLocalBounds().toFloat();
    
    // Si el botón está activado (toggle ON), dibujar gradiente invertido basado en banda Mid
    if (auto* toggleButton = dynamic_cast<juce::TextButton*>(&button))
    {
        auto baseColour = getBandColour(button);
        auto brighter = baseColour.brighter(shouldDrawButtonAsDown ? 0.4f : 0.25f);
        auto darker   = baseColour.darker(0.3f);

        const float onAlpha  = 0.28f;
        const float offAlpha = shouldDrawButtonAsHighlighted ? 0.16f : 0.08f;
        const float alpha    = toggleButton->getToggleState() ? onAlpha : offAlpha;

        juce::ColourGradient gradient(
            brighter.withAlpha(alpha),
            bounds.getX(), bounds.getCentreY(),
            darker.withAlpha(alpha * 0.9f),
            bounds.getRight(), bounds.getCentreY(),
            false
        );

        gradient.addColour(0.5, baseColour.withAlpha(alpha));

        g.setGradientFill(gradient);
        g.fillRoundedRectangle(bounds, 4.0f);

        auto borderColour = baseColour.brighter(0.6f);
        g.setColour(borderColour.withAlpha(toggleButton->getToggleState() ? 0.5f : 0.25f));
        g.drawRoundedRectangle(bounds.reduced(0.5f), 4.0f, 1.2f);
    }
    else
    {
        // Fallback para otros tipos de botones
        g.setColour(backgroundColour);
        g.fillRoundedRectangle(bounds, 3.0f);
    }
}

juce::Colour JCBImagerAudioProcessorEditor::SoloButtonLookAndFeel::getBandColour(const juce::Button& button) const noexcept
{
    const auto& id = button.getComponentID();
    if (id == "soloLow")
        return lowBandColour;
    if (id == "soloHigh")
        return highBandColour;
    if (id == "soloMid")
        return midBandColour;
    return midBandColour;
}

//==============================================================================
// IMPLEMENTACIÓN DE MUTEBUTTONLOOKANDFEEL
//==============================================================================
void JCBImagerAudioProcessorEditor::MuteButtonLookAndFeel::drawButtonBackground(
    juce::Graphics& g,
    juce::Button& button,
    const juce::Colour& backgroundColour,
    bool shouldDrawButtonAsHighlighted,
    bool shouldDrawButtonAsDown)
{
    juce::ignoreUnused(backgroundColour);

    auto bounds = button.getLocalBounds().toFloat().reduced(0.5f);
    auto offColour = button.findColour(juce::TextButton::textColourOffId);
    auto onColour  = button.findColour(juce::TextButton::textColourOnId);

    auto outline = button.getToggleState() ? onColour.withAlpha(0.35f)
                                           : offColour.withAlpha(0.22f);

    if (shouldDrawButtonAsHighlighted)
        outline = outline.withAlpha(juce::jlimit(0.0f, 1.0f, outline.getFloatAlpha() + 0.12f));

    if (shouldDrawButtonAsDown)
        outline = outline.brighter(0.15f);

    g.setColour(juce::Colours::transparentBlack);
    g.fillRoundedRectangle(bounds, 3.0f);

    if (outline.getAlpha() > 0)
    {
        g.setColour(outline);
        g.drawRoundedRectangle(bounds, 3.0f, 1.0f);
    }
}

void JCBImagerAudioProcessorEditor::ModeButtonLookAndFeel::drawButtonBackground(
    juce::Graphics& g,
    juce::Button& button,
    const juce::Colour& backgroundColour,
    bool shouldDrawButtonAsHighlighted,
    bool shouldDrawButtonAsDown)
{
    juce::ignoreUnused(backgroundColour);

    auto bounds = button.getLocalBounds().toFloat();

    if (auto* toggleButton = dynamic_cast<juce::TextButton*>(&button))
    {
        auto baseColour = juce::Colours::white;
        auto brighter = baseColour.brighter(shouldDrawButtonAsDown ? 0.35f : 0.2f);
        auto darker   = baseColour.darker(0.25f);

        const float onAlpha  = 0.35f;
        const float offAlpha = shouldDrawButtonAsHighlighted ? 0.18f : 0.10f;
        const float alpha    = toggleButton->getToggleState() ? onAlpha : offAlpha;

        juce::ColourGradient gradient(
            brighter.withAlpha(alpha),
            bounds.getX(), bounds.getCentreY(),
            darker.withAlpha(alpha * 0.85f),
            bounds.getRight(), bounds.getCentreY(),
            false);

        gradient.addColour(0.5f, baseColour.withAlpha(alpha));

        g.setGradientFill(gradient);
        g.fillRoundedRectangle(bounds, 4.0f);

        auto outline = juce::Colours::white.withAlpha(toggleButton->getToggleState() ? 0.5f : 0.25f);
        if (shouldDrawButtonAsHighlighted)
            outline = outline.withAlpha(juce::jlimit(0.0f, 1.0f, outline.getFloatAlpha() + 0.1f));

        g.setColour(outline);
        g.drawRoundedRectangle(bounds.reduced(0.5f), 4.0f, 1.1f);
    }
    else
    {
        g.setColour(juce::Colours::white.withAlpha(0.15f));
        g.fillRoundedRectangle(bounds, 3.0f);
    }
}

//==============================================================================
// IMPLEMENTACIÓN DE REVERSEDGRADIENTBUTTONLOOKANDFEEL
//==============================================================================

void JCBImagerAudioProcessorEditor::ReversedGradientButtonLookAndFeel::drawButtonBackground(
    juce::Graphics& g, juce::Button& button,
    const juce::Colour& backgroundColour,
    bool shouldDrawButtonAsHighlighted,
    bool shouldDrawButtonAsDown)
{
    auto bounds = button.getLocalBounds().toFloat();
    
    // Si el botón está activado (toggle ON), dibujar gradiente invertido
    if (auto* toggleButton = dynamic_cast<juce::TextButton*>(&button))
    {
        if (toggleButton->getToggleState())
        {
            // Crear gradiente invertido: púrpura a la izquierda, azul a la derecha
            juce::ColourGradient gradient(
                lowBandColour.withAlpha(0.0f),   // Púrpura a la izquierda - completamente transparente
                bounds.getX(), bounds.getCentreY(),
                highBandColour.withAlpha(0.0f),  // Azul a la derecha - completamente transparente
                bounds.getRight(), bounds.getCentreY(),
                false
            );
            
            // Añadir punto intermedio para transición más suave
            gradient.addColour(0.5, 
                highBandColour.interpolatedWith(lowBandColour, 0.5f).withAlpha(0.0f));
            
            g.setGradientFill(gradient);
            g.fillRoundedRectangle(bounds, 2.0f);
            
            // Añadir borde sutil como DOWNSAMPLE y SOLO BAND
            juce::Colour borderColour = lowBandColour.interpolatedWith(highBandColour, 0.5f);
            g.setColour(borderColour.withAlpha(0.15f));  // Borde muy sutil
            g.drawRoundedRectangle(bounds.reduced(0.5f), 2.0f, 1.0f);
        }
    }
}

//==============================================================================
// IMPLEMENTACIÓN DE TEALGRADIENTBUTTONLOOKANDFEEL
//==============================================================================

void JCBImagerAudioProcessorEditor::TealGradientButtonLookAndFeel::drawButtonBackground(
    juce::Graphics& g, juce::Button& button,
    const juce::Colour& backgroundColour,
    bool shouldDrawButtonAsHighlighted,
    bool shouldDrawButtonAsDown)
{
    auto bounds = button.getLocalBounds().toFloat();
    
    // Para el botón TILT PRE/POST usar gradiente de verde agua pálido
    const juce::Colour tealColour{0xFFA6DAD5};
    
    // Siempre dibujar gradiente, independientemente del estado del toggle
    // Crear gradiente de teal: oscuro a la izquierda, claro a la derecha
    juce::ColourGradient gradient(
        tealColour.darker(0.2f).withAlpha(0.25f),   // Teal oscuro a la izquierda - más transparente
        bounds.getX(), bounds.getCentreY(),
        tealColour.brighter(0.2f).withAlpha(0.25f),  // Teal claro a la derecha - más transparente
        bounds.getRight(), bounds.getCentreY(),
        false
    );
    
    // Añadir punto intermedio para transición más suave
    gradient.addColour(0.5, 
        tealColour.withAlpha(0.20f));
    
    g.setGradientFill(gradient);
    g.fillRoundedRectangle(bounds, 2.0f);
}

//==============================================================================
// IMPLEMENTACIÓN DE CORALGRADIENTBUTTONLOOKANDFEEL
//==============================================================================

void JCBImagerAudioProcessorEditor::CoralGradientButtonLookAndFeel::drawButtonBackground(
    juce::Graphics& g, juce::Button& button,
    const juce::Colour& backgroundColour,
    bool shouldDrawButtonAsHighlighted,
    bool shouldDrawButtonAsDown)
{
    auto bounds = button.getLocalBounds().toFloat();
    
    // Si el botón está activado (toggle ON), dibujar gradiente rojo coral
    if (auto* toggleButton = dynamic_cast<juce::TextButton*>(&button))
    {
        if (toggleButton->getToggleState())
        {
            // Crear gradiente de rojo coral: oscuro a la izquierda, claro a la derecha
            juce::ColourGradient gradient(
                coralColour.darker(0.2f).withAlpha(0.15f),   // Coral oscuro a la izquierda - más transparente
                bounds.getX(), bounds.getCentreY(),
                coralColour.brighter(0.2f).withAlpha(0.15f),  // Coral claro a la derecha - más transparente
                bounds.getRight(), bounds.getCentreY(),
                false
            );
            
            // Añadir punto intermedio para transición más suave
            gradient.addColour(0.5, 
                coralColour.withAlpha(0.13f));
            
            g.setGradientFill(gradient);
            g.fillRoundedRectangle(bounds, 2.0f);
        }
    }
}


JCBImagerAudioProcessorEditor::~JCBImagerAudioProcessorEditor()
{
    // CRÍTICO: Destruir helper timer primero para evitar callbacks en objetos ya destruidos
    uiTimer.reset();

    // Desconectar callbacks del processor que capturan este editor
    processor.setSpectrumAnalyzerCallbackStereo({});
    processor.setSpectrumAnalyzerCallback({});
    processor.setSampleRateChangedCallback({});
    
    // Desregistrar listeners de parámetros antes de destruir
    if (sidechainParameterListener) {
        processor.apvts.removeParameterListener("y_FILTERS", sidechainParameterListener.get());
        processor.apvts.removeParameterListener("q_ONOFFEQ", sidechainParameterListener.get());
        processor.apvts.removeParameterListener("r_ONOFFCOMP", sidechainParameterListener.get());
    }

    sidechainControls.hpfSlider.setLookAndFeel(nullptr);
    sidechainControls.lpfSlider.setLookAndFeel(nullptr);
    sidechainControls.scButton.setLookAndFeel(nullptr);

    leftKnobs.reflectSlider.setLookAndFeel(nullptr);
    leftKnobs.dampSlider.setLookAndFeel(nullptr);
    leftKnobs.sizeSlider.setLookAndFeel(nullptr);
    leftKnobs.drywetSlider.setLookAndFeel(nullptr);
    leftKnobs.stSlider.setLookAndFeel(nullptr);
    leftKnobs.freezeButton.setLookAndFeel(nullptr);

    imager.soloLow.setLookAndFeel(nullptr);
    imager.soloMid.setLookAndFeel(nullptr);
    imager.soloHigh.setLookAndFeel(nullptr);
    imager.inputMode.setLookAndFeel(nullptr);
    imager.outputMode.setLookAndFeel(nullptr);

    // Reset LAF for newly added right-side controls
    eqControls.lsfSlider.setLookAndFeel(nullptr);
    eqControls.pfSlider.setLookAndFeel(nullptr);
    eqControls.hsfSlider.setLookAndFeel(nullptr);
    eqControls.lsgSlider.setLookAndFeel(nullptr);
    eqControls.pgSlider.setLookAndFeel(nullptr);
    eqControls.hsgSlider.setLookAndFeel(nullptr);
    eqControls.eqOnButton.setLookAndFeel(nullptr);

    compControls.thdSlider.setLookAndFeel(nullptr);
    compControls.ratioSlider.setLookAndFeel(nullptr);
    compControls.atkSlider.setLookAndFeel(nullptr);
    compControls.relSlider.setLookAndFeel(nullptr);
    compControls.gainSlider.setLookAndFeel(nullptr);
    compControls.compOnButton.setLookAndFeel(nullptr);
    compControls.pumpButton.setLookAndFeel(nullptr);

    // Tabs (EQ/COMP)
    rightTabs.eqTab.setLookAndFeel(nullptr);
    rightTabs.compTab.setLookAndFeel(nullptr);

    // Limpiar LookAndFeel del editor principal
    setLookAndFeel(nullptr);
}

//==============================================================================
// OVERRIDES DE JUCE
//==============================================================================
void JCBImagerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // El background se maneja por el componente backgroundImage
}

void JCBImagerAudioProcessorEditor::paintOverChildren (juce::Graphics& g)
{
    // Usar las mismas coordenadas que la transfer function display
    float x = 460.0f * 700.0f / 1247.0f;  // ≈ 258
    float y = 73.0f * 200.0f / 353.0f + 4.0f;    // ≈ 41 + 4 píxeles
    float w = 335.0f * 700.0f / 1247.0f;  // ≈ 188
    float h = 205.0f * 200.0f / 353.0f - 5.0f;   // ≈ 116 - 5 píxeles
    auto transferBounds = getScaledBounds(x, y, w, h).toFloat();

    // Texto BYPASS
    if (isBypassed && bypassTextVisible) {
        g.setColour(juce::Colours::transparentWhite.withAlpha(0.85f));
        g.setFont(juce::Font(juce::FontOptions(transferBounds.getHeight() * 0.4f))
                  .withStyle(juce::Font::bold));
        g.drawText("BYPASS", transferBounds, juce::Justification::centred);
    }

    // Las etiquetas de BAND ahora se manejan con componentes Label separados
}

void JCBImagerAudioProcessorEditor::resized()
{
    // Guardar tamaño de ventana
    processor.setSavedSize({getWidth(), getHeight()});

    // guardar como tamaño personalizado para poder volver a él
    int currentWidth = getWidth();
    int currentHeight = getHeight();

    if (currentWidth != DEFAULT_WIDTH && currentWidth != MIN_WIDTH && currentWidth != MAX_WIDTH &&
        currentHeight != DEFAULT_HEIGHT && currentHeight != MIN_HEIGHT && currentHeight != MAX_HEIGHT) {
        // Es un tamaño personalizado - guardarlo
        lastCustomSize = {currentWidth, currentHeight};
    }

    // El background llena toda el área
    backgroundImage.setBounds(getLocalBounds());

    // === METERS CON SLIDERS DE TRIM/MAKEUP ===
    // Meters de entrada (lado izquierdo)
    inputMeterL.setBounds(getScaledBounds(2, 42, 12, 117));
    inputMeterR.setBounds(getScaledBounds(12, 42, 12, 117));

    // Copia exacta de JCBReverb
    trimSlider.setBounds  (getScaledBounds(2,   40, 22, 130));
    makeupSlider.setBounds(getScaledBounds(677, 40, 22, 130));

    // Medidores de salida (lado derecho)
    outputMeterL.setBounds(getScaledBounds(677, 42, 12, 117));
    outputMeterR.setBounds(getScaledBounds(687, 42, 12, 117));
    
    // === VISUALIZACIÓN CENTRAL (SPECTRUM ANALYZER) ===
    // Zona central para controles del Imager con columna reservada derecha
    auto full = getLocalBounds();
    auto topBar = getScaledBounds(0,0,700,30); juce::ignoreUnused(topBar);
    auto work = getLocalBounds().reduced(20);
    auto rightReserve = work.removeFromRight(work.getWidth() / 4); juce::ignoreUnused(rightReserve); // 1/4 para FFT/gonio

    // Fila 1: crossovers centrados
    auto row1 = work.removeFromTop(60);
    auto r1 = row1.reduced(120);
    auto r1w = r1.getWidth()/2;
    imager.freq1.setBounds(r1.removeFromLeft(r1w).reduced(10));
    imager.freq2.setBounds(r1.reduced(10));

    // Fila 2: disponer bandas Low/Mid/High alrededor del centro manteniendo simetría
    const int widthKnobSize = 53;
    const int widthKnobY = 52;
    const int balanceWidth = 70;
    const int balanceY = 104;
    const int balanceLabelY = 120;
    const int balanceLabelWidth = 16;
    const int buttonWidth = 44;
    const int buttonHeight = 14;
    const int buttonGap = 6;
    const int buttonsY = 136;

    const int midCenterX = 352;
    const int bandSpacing = 118;
    const int lowCenterX = midCenterX - bandSpacing;
    const int highCenterX = midCenterX + bandSpacing;


    auto placeBand = [&](int centerX,
                          CustomSlider& widthKnob,
                          CustomSlider& balanceSlider,
                          juce::Label& labelL,
                          juce::Label& labelC,
                          juce::Label& labelR,
                          juce::TextButton& soloButton,
                          juce::TextButton& muteButton)
    {
        widthKnob.setBounds(getScaledBounds(centerX - widthKnobSize / 2, widthKnobY, widthKnobSize, widthKnobSize));

        balanceSlider.setBounds(getScaledBounds(centerX - balanceWidth / 2, balanceY, balanceWidth, 16));
        labelL.setBounds(getScaledBounds(centerX - balanceWidth / 2, balanceLabelY, balanceLabelWidth, 14));
        labelC.setBounds(getScaledBounds(centerX - balanceLabelWidth / 2, balanceLabelY, balanceLabelWidth, 14));
        labelR.setBounds(getScaledBounds(centerX + balanceWidth / 2 - balanceLabelWidth, balanceLabelY, balanceLabelWidth, 14));

        soloButton.setBounds(getScaledBounds(centerX - buttonGap / 2 - buttonWidth, buttonsY, buttonWidth, buttonHeight));
        muteButton.setBounds(getScaledBounds(centerX + buttonGap / 2, buttonsY, buttonWidth, buttonHeight));
    };

    placeBand(lowCenterX,
              imager.lowGain,
              imager.lowBal,
              imager.lowBalL,
              imager.lowBalC,
              imager.lowBalR,
              imager.soloLow,
              imager.muteLow);

    placeBand(midCenterX,
              imager.midGain,
              imager.midBal,
              imager.midBalL,
              imager.midBalC,
              imager.midBalR,
              imager.soloMid,
              imager.muteMid);

    placeBand(highCenterX,
              imager.highGain,
              imager.highBal,
              imager.highBalL,
              imager.highBalC,
              imager.highBalR,
              imager.soloHigh,
              imager.muteHigh);

    // WIDTH knobs: doble‑clic a 1.0
    imager.lowGain   .setDoubleClickReturnValue(true, 1.0);
    imager.midGain   .setDoubleClickReturnValue(true, 1.0);
    imager.highGain  .setDoubleClickReturnValue(true, 1.0);

    // BAL sliders: estilizados en setupKnobs (colores por banda con fondo homogéneo)
    // Fila 3: Dry/Wet, Trim, Makeup
    auto row3 = work.removeFromTop(70).reduced(60);
    auto seg = row3.getWidth()/3;
    imager.drywet.setBounds(row3.removeFromLeft(seg).reduced(10));
    imager.trim.setBounds  (row3.removeFromLeft(seg).reduced(10));
    imager.makeup.setBounds(row3.reduced(10));

    // Visualizaciones: FFT a la izquierda, goniometer a la derecha con margen antes de los meters
    spectrumAnalyzer.setBounds(getScaledBounds(27, 42, 145, 114));
    goniometerDisplay.setBounds(getScaledBounds(538, 42, 140, 116));
    imager.inputMode.setBounds(getScaledBounds(165, 45, 36, 12));
    imager.outputMode.setBounds(getScaledBounds(500, 45, 36, 12));

    // Posicionar HPF/LPF en la parte superior central + botón FILTERS - 285, 5, 36, 36
    sidechainControls.hpfSlider.setBounds(getScaledBounds(285, 3, 39, 39));
    sidechainControls.lpfSlider.setBounds(getScaledBounds(383, 3, 39, 39));
    {
        const int buttonWidth = 50;
        const int centerX = 355;
        sidechainControls.scButton.setBounds(getScaledBounds(centerX - buttonWidth/2, 14, buttonWidth, 15));
    }

    // Posición leftKnobs
    leftKnobs.reflectSlider.setBounds(getScaledBounds(44, 47, 53, 53));
    leftKnobs.sizeSlider.setBounds(getScaledBounds(92, 47, 53, 53));
    leftKnobs.dampSlider.setBounds(getScaledBounds(142, 47, 53, 53));

    leftKnobs.drywetSlider.setBounds(getScaledBounds(65, 102, 53, 53));
    leftKnobs.stSlider.setBounds(getScaledBounds(120, 102, 53, 53));
    leftKnobs.freezeButton.setBounds(getScaledBounds(200, 93, 55, 16));

    // Right panel (EQ/COMP) removed for Imager; area reserved for future meters

    // === PRESET AREA (TOP LEFT) ===
    presetArea.saveButton.setBounds(getScaledBounds(5, 15, 20, 12));  // Alineado con undo
    presetArea.saveAsButton.setBounds(getScaledBounds(27, 15, 25, 12));
    presetArea.deleteButton.setBounds(getScaledBounds(54, 15, 25, 12));
    presetArea.backButton.setBounds(getScaledBounds(81, 15, 14, 12));
    presetArea.nextButton.setBounds(getScaledBounds(98, 15, 14, 12));
    presetArea.presetMenu.setBounds(getScaledBounds(114, 15, 95, 12));

    // Botones A/B junto al menú de preset
    topButtons.abStateButton.setBounds(getScaledBounds(213, 15, 18, 12));
    topButtons.abCopyButton.setBounds(getScaledBounds(233, 15, 22, 12));

    // === BOTONES DE UTILIDAD (INFERIOR IZQUIERDA) ===
    utilityButtons.undoButton.setBounds(getScaledBounds(30, 175, 22, 12));
    utilityButtons.redoButton.setBounds(getScaledBounds(52, 175, 22, 12));
    utilityButtons.resetGuiButton.setBounds(getScaledBounds(76, 175, 30, 12));
    utilityButtons.runGraphicsButton.setBounds(getScaledBounds(108, 175, 30, 12));
    utilityButtons.tooltipToggleButton.setBounds(getScaledBounds(140, 175, 30, 12));
    utilityButtons.tooltipLangButton.setBounds(getScaledBounds(172, 175, 22, 12));

    // Botones DIAGRAM y BYPASS centrados en la fila inferior
    const int bottomButtonsY = 165;  // Fila superior del rectángulo inferior
    const int bottomCenterX = 358;   // Centro horizontal del plugin
    const int totalButtonWidth = 44 + 10 + 50;  // DIAGRAM + gap + BYPASS
    const int buttonsStartX = bottomCenterX - (totalButtonWidth / 2);
    centerButtons.diagramButton.setBounds(getScaledBounds(buttonsStartX, bottomButtonsY, 44, 12));
    parameterButtons.bypassButton.setBounds(getScaledBounds(buttonsStartX + 58, bottomButtonsY, 38, 12));

    // Calcular posición central para el grupo de botones "POR HACER"
    const int todoStartX = 503;    // Movido a la derecha para mejor centrado en el rectángulo
    const int todoY = 175;       // Mismo Y que botones de utilidad
    utilityButtons.hqButton.setBounds(getScaledBounds(todoStartX, todoY, 18, 12));
    utilityButtons.dualMonoButton.setBounds(getScaledBounds(todoStartX + 20, todoY, 23, 12));
    utilityButtons.stereoLinkedButton.setBounds(getScaledBounds(todoStartX + 45, todoY, 23, 12));
    utilityButtons.msButton.setBounds(getScaledBounds(todoStartX + 70, todoY, 18, 12));
    // Botón MIDI posicionado a la derecha del botón M/S
    utilityButtons.midiLearnButton.setBounds(getScaledBounds(todoStartX + 90, todoY, 23, 12));

    // === TÍTULO Y VERSIÓN (CENTRO INFERIOR) ===
    // Centrado debajo de los botones DIAGRAM y BYPASS
    const int titleY = 180;  // Desplazado hacia abajo para dar espacio
    const int centerX = 353;  // Centro del plugin
    titleLink.setBounds(getScaledBounds(centerX - 48, titleY, 98, 15));

    // Tooltip en esquina superior derecha - ajustado al rectángulo visible
    tooltipComponent.setBounds(getScaledBounds(448, 0, 230, 42));

    // Actualizar factor de escala del tooltip basado en el tamaño de la ventana
    float scaleFactor = (float)getWidth() / (float)DEFAULT_WIDTH;
    tooltipComponent.setScaleFactor(scaleFactor);

    // Redimensionar el overlay del diagrama si está visible
    if (diagramOverlay != nullptr)
    {
        diagramOverlay->setBounds(getLocalBounds());
        diagramOverlay->invalidateClickableAreasCache(); // Invalidar cache para regenerar con nuevas coordenadas escaladas
    }

    // Redimensionar el overlay de créditos si está visible
    if (creditsOverlay != nullptr)
    {
        creditsOverlay->setBounds(getLocalBounds());
    }

    // Redimensionar y reposicionar la ventana de código si está visible
    if (codeWindow != nullptr && codeWindow->isVisible())
    {
        // Recalcular tamaño responsivo
        int windowWidth = static_cast<int>(getWidth() * 0.35f);
        int windowHeight = static_cast<int>(getHeight() * 0.50f);

        // Limitar tamaños
        windowWidth = juce::jlimit(350, 600, windowWidth);
        windowHeight = juce::jlimit(250, 450, windowHeight);

        // Recentrar la ventana
        int x = getWidth() / 2 - windowWidth / 2;
        int y = getHeight() / 2 - windowHeight / 2;

        codeWindow->setBounds(x, y, windowWidth, windowHeight);
    }
}

void JCBImagerAudioProcessorEditor::onUiTick()
{
    // CRASH FIX: Verificar que el processor esté completamente inicializado
    // antes de acceder a valores atómicos
    if (!processor.isInitialized()) {
        return;
    }

    // Sistema universal de decay para todos los DAWs
    applyMeterDecayIfNeeded();
    
    if (!goniometerDisplay.isHoldEnabled())
    {
        std::vector<juce::Point<float>> scopeSamples;
        processor.getGoniometerData(scopeSamples);
        goniometerDisplay.setSamples(scopeSamples);
    }

    updateMeters();

    // Actualizar estado visual de botones undo/redo
    bool canUndo = undoManager.canUndo();
    bool canRedo = undoManager.canRedo();

    // Actualizar apariencia del botón undo
    utilityButtons.undoButton.setEnabled(canUndo);
    utilityButtons.undoButton.setAlpha(canUndo ? 1.0f : 0.3f);
    utilityButtons.undoButton.setColour(juce::TextButton::textColourOffId,
                                       canUndo ? DarkTheme::textPrimary : DarkTheme::textSecondary);

    // Actualizar apariencia del botón redo
    utilityButtons.redoButton.setEnabled(canRedo);
    utilityButtons.redoButton.setAlpha(canRedo ? 1.0f : 0.3f);
    utilityButtons.redoButton.setColour(juce::TextButton::textColourOffId,
                                       canRedo ? DarkTheme::textPrimary : DarkTheme::textSecondary);

    // Actualizar texto y tooltip del botón A/B copy dinámicamente
    if (processor.getIsStateA()) {
        topButtons.abCopyButton.setButtonText("A-B");
        topButtons.abCopyButton.setTooltip(getTooltipText("abcopyatob"));
    } else {
        topButtons.abCopyButton.setButtonText("B-A");
        topButtons.abCopyButton.setTooltip(getTooltipText("abcopybtoa"));
    }

    // Resetear indicadores de clip cada 3 segundos (180 frames a 60Hz)
    clipResetCounter++;
    if (clipResetCounter >= 180) {
        processor.resetClipIndicators();
        clipResetCounter = 0;
    }

    // Pasar el estado de Logic parado al display
    // Determinar si el procesamiento está inactivo
    // Usar sistema híbrido optimizado (timestamp + playhead + audio tail)
    bool isProcessingInactive = !processor.isPlaybackActive();

    // bool isProcessingInactive = processor.getIsLogicStopped();

    // Imager no calcula gain reduction; mantener placeholder para compatibilidad
    if (!isBypassed && !isProcessingInactive)
    {
            // DISTORTION: No hay gain reduction - eliminar else branch
    }
    else
    {
        // Si está en bypass o Logic está parado, no hay reducción
        maxGainReductionFromBuffer = 0.0f;
    }

    // Debug overlay: update counters each frame (lightweight atomics)
    //{
        //const int fs = processor.getDiagFailsafeCount();
        //const int rs = processor.getDiagGenResets();
        //debugLabel.setText(juce::String::formatted("FS:%d  RS:%d", fs, rs), juce::dontSendNotification);
    //}
}

void JCBImagerAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    if (button == &utilityButtons.undoButton)
    {
        undoManager.undo();
    }
    else if (button == &utilityButtons.redoButton)
    {
        undoManager.redo();
    }
    else if (button == &utilityButtons.resetGuiButton)
    {
        // Resetear tamaño de GUI, no parámetros
        resetGuiSize();
    }
    else if (button == &parameterButtons.bypassButton)
    {
        const bool bypassActive = parameterButtons.bypassButton.getToggleState();
        if (bypassActive) {
            // // BYPASS desactiva SOLO SC y DIAGRAM
            // if (centerButtons.diagramButton.getToggleState()) {
            //     centerButtons.diagramButton.setToggleState(false, juce::dontSendNotification);
            //     hideDiagram();
            // }
        }
        updateButtonStates();

        // Reactivar control de bypass interno de Gen: i_BYPASS (sin smoothing en Gen)
        if (auto* st = processor.getPluginState())
        {
            for (int i = 0; i < JCBImager::num_params(); ++i)
            {
                if (juce::String(JCBImager::getparametername(st, i)) == "i_BYPASS")
                {
                    JCBImager::setparameter(st, i, bypassActive ? 1.f : 0.f, nullptr);
                    break;
                }
            }
        }

        // UI: actualizar estado visual de medidores en modo bypass
        outputMeterL.setBypassMode(bypassActive);
        outputMeterR.setBypassMode(bypassActive);
    }
    else if (button == &sidechainControls.scButton)
    {
        // Actualizar estado visual de sliders HPF/LPF inmediatamente para clicks manuales
        updateSidechainComponentStates();
    }
    else if (button == &rightTabs.eqTab)
    {
        currentRightTab = RightPanelTab::EQ;
        updateRightPanelVisibility();
        processor.apvts.state.setProperty("ui_right_tab", 0, nullptr);
    }
    else if (button == &rightTabs.compTab)
    {
        currentRightTab = RightPanelTab::COMP;
        updateRightPanelVisibility();
        processor.apvts.state.setProperty("ui_right_tab", 1, nullptr);
    }
    else if (button == &eqControls.eqOnButton)
    {
        updateEqComponentStates();
    }
    else if (button == &compControls.compOnButton)
    {
        updateCompComponentStates();
    }
    else if (button == &imager.soloLow || button == &imager.soloMid || button == &imager.soloHigh)
    {
        // Exclusividad SOLO (UI-only). Si se enciende uno, apagar los otros dos
        bool low  = (button == &imager.soloLow)  ? button->getToggleState() : imager.soloLow.getToggleState();
        bool mid  = (button == &imager.soloMid)  ? button->getToggleState() : imager.soloMid.getToggleState();
        bool high = (button == &imager.soloHigh) ? button->getToggleState() : imager.soloHigh.getToggleState();

        if (button->getToggleState())
        {
            if (button == &imager.soloLow)  { mid = false; high = false; }
            if (button == &imager.soloMid)  { low = false; high = false; }
            if (button == &imager.soloHigh) { low = false; mid = false; }
        }
        setSoloState(low, mid, high);
        // Al activar SOLO, desactivar todos los MUTE (APVTS + RT)
        if (low || mid || high)
        {
            if (auto* p = dynamic_cast<juce::AudioParameterBool*>(processor.apvts.getParameter("n_MUTLOW")))  p->setValueNotifyingHost(0.0f);
            if (auto* p = dynamic_cast<juce::AudioParameterBool*>(processor.apvts.getParameter("o_MUTMED")))  p->setValueNotifyingHost(0.0f);
            if (auto* p = dynamic_cast<juce::AudioParameterBool*>(processor.apvts.getParameter("p_MUTHIGH"))) p->setValueNotifyingHost(0.0f);
            imager.muteLow .setToggleState(false, juce::dontSendNotification);
            imager.muteMid .setToggleState(false, juce::dontSendNotification);
            imager.muteHigh.setToggleState(false, juce::dontSendNotification);
            processor.pushGenParamByName("n_MUTLOW", 0.f);
            processor.pushGenParamByName("o_MUTMED", 0.f);
            processor.pushGenParamByName("p_MUTHIGH",0.f);
        }
    }
    else if (button == &compControls.pumpButton)
    {
        // Sincronizar explícitamente el parámetro x_PUMP con el estado del botón
        if (auto* pumpParam = processor.apvts.getParameter("x_PUMP"))
        {
            if (auto* boolParam = dynamic_cast<juce::AudioParameterBool*>(pumpParam))
                boolParam->setValueNotifyingHost(compControls.pumpButton.getToggleState() ? 1.0f : 0.0f);
        }
    }
    else if (button == &leftKnobs.freezeButton)
    {
        // No se requiere acción adicional, el attachment maneja el parámetro
    }
    else if (button == &utilityButtons.runGraphicsButton)
    {
        const bool hold = utilityButtons.runGraphicsButton.getToggleState();
        setGoniometerHold(hold, false);
    }
    // Botones de gestión de presets
    else if (button == &presetArea.saveButton)
    {
        // Desactivar botones momentáneos antes de guardar
        parameterButtons.bypassButton.setToggleState(false, juce::sendNotification);
            // sidechainControls.soloScButton.setToggleState(false, juce::sendNotification);
        savePresetFile();
    }
    else if (button == &presetArea.saveAsButton)
    {
        // Desactivar botones momentáneos antes de guardar
        parameterButtons.bypassButton.setToggleState(false, juce::sendNotification);
            // sidechainControls.soloScButton.setToggleState(false, juce::sendNotification);
        saveAsPresetFile();
    }
    else if (button == &presetArea.deleteButton)
    {
        // Desactivar botones momentáneos antes de mostrar el diálogo
        parameterButtons.bypassButton.setToggleState(false, juce::sendNotification);
            // sidechainControls.soloScButton.setToggleState(false, juce::sendNotification);
        deletePresetFile();
    }
    else if (button == &presetArea.backButton)
    {
        // Desactivar botones momentáneos antes de cambiar preset
        parameterButtons.bypassButton.setToggleState(false, juce::sendNotification);
            // sidechainControls.soloScButton.setToggleState(false, juce::sendNotification);
        selectPreviousPreset();
    }
    else if (button == &presetArea.nextButton)
    {
        // Desactivar botones momentáneos antes de cambiar preset
        parameterButtons.bypassButton.setToggleState(false, juce::sendNotification);
            // sidechainControls.soloScButton.setToggleState(false, juce::sendNotification);
        selectNextPreset();
    }
    else if (button == &utilityButtons.tooltipToggleButton)
    {
        // Alternar visibilidad del tooltip
        tooltipsEnabled = utilityButtons.tooltipToggleButton.getToggleState();
        tooltipComponent.setTooltipsEnabled(tooltipsEnabled);

        // Guardar estado del tooltip al processor
        processor.setTooltipEnabled(tooltipsEnabled);

        // Habilitar/deshabilitar botón de idioma basado en estado del tooltip
        utilityButtons.tooltipLangButton.setEnabled(tooltipsEnabled);
        utilityButtons.tooltipLangButton.setAlpha(tooltipsEnabled ? 1.0f : 0.25f);
    }
    else if (button == &utilityButtons.tooltipLangButton)
    {
        // Alternar idioma
        currentLanguage = (currentLanguage == TooltipLanguage::Spanish) ?
                         TooltipLanguage::English : TooltipLanguage::Spanish;

        // Actualizar texto del botón
        utilityButtons.tooltipLangButton.setButtonText(
            currentLanguage == TooltipLanguage::Spanish ? "esp" : "eng");

        // Actualizar color del botón basado en el idioma
        if (currentLanguage == TooltipLanguage::English) {
            // Color azul para inglés
            utilityButtons.tooltipLangButton.setColour(juce::TextButton::textColourOffId, DarkTheme::accentSecondary);
        } else {
            // Color por defecto para español
            utilityButtons.tooltipLangButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
        }

        // Guardar preferencia de idioma
        processor.setTooltipLanguageEnglish(currentLanguage == TooltipLanguage::English);

        // Actualizar todos los tooltips con el nuevo idioma
        updateAllTooltips();
        // Por botones "por hacer"
        updateTodoButtonTexts();
    }
    else if (button == &utilityButtons.hqButton)
    {
        // POR HACER: Implementar oversampling HQ
    }
    else if (button == &utilityButtons.dualMonoButton)
    {
        // Manejar exclusividad de botones de modo estéreo
        if (utilityButtons.dualMonoButton.getToggleState())
        {
            // utilityButtons.stereoLinkedButton.setToggleState(false, juce::dontSendNotification); // LINK siempre está activo
            utilityButtons.msButton.setToggleState(false, juce::dontSendNotification);
        }
    }
    /* Botón LINK siempre está ON y deshabilitado - no necesita manejador
    else if (button == &utilityButtons.stereoLinkedButton)
    {
        // Manejar exclusividad de botones de modo estéreo
        if (utilityButtons.stereoLinkedButton.getToggleState())
        {
            utilityButtons.dualMonoButton.setToggleState(false, juce::dontSendNotification);
            utilityButtons.msButton.setToggleState(false, juce::dontSendNotification);
        }
    }
    */
    else if (button == &utilityButtons.msButton)
    {

        // Manejar exclusividad de botones de modo estéreo
        if (utilityButtons.msButton.getToggleState())
        {
            utilityButtons.dualMonoButton.setToggleState(false, juce::dontSendNotification);
            // utilityButtons.stereoLinkedButton.setToggleState(false, juce::dontSendNotification); // LINK siempre está activo
        }
    }
    else if (button == &topButtons.abStateButton)
    {

        // Alternar estado A/B
        processor.toggleAB();

        // Actualizar texto del botón para mostrar estado actual
        topButtons.abStateButton.setButtonText(processor.getIsStateA() ? "A" : "B");

        // Retroalimentación visual con colores más evidentes
        if (processor.getIsStateA()) {
            // A = Púrpura/Violeta
            topButtons.abStateButton.setColour(juce::TextButton::buttonColourId, juce::Colour(0xff9E35B0));  // Purple
            topButtons.abStateButton.setColour(juce::TextButton::buttonOnColourId, juce::Colour(0xff9E35B0));  // Mismo color para evitar brillo
            topButtons.abStateButton.setColour(juce::TextButton::textColourOffId, juce::Colours::white);
        } else {
            // B = Azul
            topButtons.abStateButton.setColour(juce::TextButton::buttonColourId, juce::Colour(0xff2196f3));  // Blue
            topButtons.abStateButton.setColour(juce::TextButton::buttonOnColourId, juce::Colour(0xff2196f3));  // Mismo color para evitar brillo
            topButtons.abStateButton.setColour(juce::TextButton::textColourOffId, juce::Colours::white);
        }

        repaint();
    }
    else if (button == &topButtons.abCopyButton)
    {
        // Copiar estado actual al otro
        if (processor.getIsStateA()) {
            processor.copyAtoB();
            // Retroalimentación visual - destello púrpura a azul
            topButtons.abCopyButton.setColour(juce::TextButton::buttonColourId, juce::Colour(0xff2196f3));  // Destello azul
            topButtons.abCopyButton.setColour(juce::TextButton::textColourOffId, juce::Colours::white);
            // Usar SafePointer para prevenir crashes si el editor se destruye antes de que se dispare el timer
            juce::Component::SafePointer<JCBImagerAudioProcessorEditor> safeThis(this);
            juce::Timer::callAfterDelay(300, [safeThis]() {
                if (safeThis) {
                    safeThis->topButtons.abCopyButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
                    safeThis->topButtons.abCopyButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
                }
            });
        } else {
            processor.copyBtoA();
            // Retroalimentación visual - destello azul a púrpura
            topButtons.abCopyButton.setColour(juce::TextButton::buttonColourId, juce::Colour(0xff9E35B0));  // Destello púrpura
            topButtons.abCopyButton.setColour(juce::TextButton::textColourOffId, juce::Colours::white);
            // Usar SafePointer para prevenir crashes si el editor se destruye antes de que se dispare el timer
            juce::Component::SafePointer<JCBImagerAudioProcessorEditor> safeThis(this);
            juce::Timer::callAfterDelay(300, [safeThis]() {
                if (safeThis) {
                    safeThis->topButtons.abCopyButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
                    safeThis->topButtons.abCopyButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
                }
            });
        }
    }
    else if (button == &utilityButtons.midiLearnButton)
    {
        //POR HACER: Implementar modo MIDI learn
    }
    else if (button == &centerButtons.diagramButton)
    {
        // Anti-rebote para evitar clicks múltiples
        juce::uint32 currentTime = juce::Time::getMillisecondCounter();
        if (currentTime - lastDiagramButtonTime < DIAGRAM_BUTTON_DEBOUNCE_MS)
        {
            return;  // Ignorar clicks muy rápidos
        }
        lastDiagramButtonTime = currentTime;

        // Alternar diagrama basado en visibilidad actual
        bool diagramWillBeActivated = (diagramOverlay == nullptr || !diagramOverlay->isVisible());

        // Comportamiento exclusivo: solo desactivar otros cuando DIAGRAM se va a activar
        if (diagramWillBeActivated) {
            // DIAGRAM desactiva BYPASS y SOLO SC cuando se activa
            parameterButtons.bypassButton.setToggleState(false, juce::sendNotification);
                        // sidechainControls.soloScButton.setToggleState(false, juce::sendNotification);
        }

        // Ejecutar el alternado
        if (diagramOverlay != nullptr && diagramOverlay->isVisible())
        {
            hideDiagram();
        }
        else
        {
            showDiagram();
        }
    }
}

//==============================================================================
// PARAMETER LISTENER - Sincronización con automatización del HOST
//==============================================================================

void JCBImagerAudioProcessorEditor::parameterChanged(const juce::String& parameterID, float newValue)
{
}

//==============================================================================
// MANEJO DE PARÁMETROS Y EVENTOS
//==============================================================================
//==============================================================================
// GESTIÓN DE ESTADO DE PARÁMETROS
//==============================================================================
void JCBImagerAudioProcessorEditor::handleParameterChange()
{
    // No hacer nada si estamos cargando un preset
    if (isLoadingPreset) {
        return;
    }

    if (presetArea.presetMenu.getSelectedId() > 0) {
        // Un preset está seleccionado del menú - deseleccionar y mostrar con asterisco
        juce::String currentPresetName = presetArea.presetMenu.getText();

        presetArea.presetMenu.setSelectedId(0);
        processor.setLastPreset(0);

        // Mostrar el nombre del preset con asterisco en cursiva
        auto modifiedText = currentPresetName + "*";
        presetArea.presetMenu.setTextWhenNothingSelected(modifiedText);
        presetArea.presetMenu.setTextItalic(true);

        // Guardar el estado visual en el processor
        processor.setPresetDisplayText(modifiedText);
        processor.setPresetTextItalic(true);

    } else {
        // No hay preset seleccionado - verificar el texto actual
        juce::String currentText = presetArea.presetMenu.getTextWhenNothingSelected();

        // Si está vacío, no hacer nada
        if (currentText.isEmpty()) {
            presetArea.presetMenu.setTextWhenNothingSelected("");
            presetArea.presetMenu.setTextItalic(false);
            processor.setPresetDisplayText("");
            processor.setPresetTextItalic(false);
        }
        // Si es DEFAULT, permitir que se marque como modificado
        else if (currentText == "DEFAULT") {
            auto modifiedText = "DEFAULT*";
            presetArea.presetMenu.setTextWhenNothingSelected(modifiedText);
            presetArea.presetMenu.setTextItalic(true);
            processor.setPresetDisplayText(modifiedText);
            processor.setPresetTextItalic(true);
        }
        // Si ya tiene asterisco, no hacer nada más
        else if (!currentText.endsWith("*")) {
            // Agregar asterisco al preset no seleccionado
            auto modifiedText = currentText + "*";
            presetArea.presetMenu.setTextWhenNothingSelected(modifiedText);
            presetArea.presetMenu.setTextItalic(true);

            // Guardar el estado visual en el processor
            processor.setPresetDisplayText(modifiedText);
            processor.setPresetTextItalic(true);
        }
    }

    // No crear UI aquí. Solo actualizar estados visuales si es necesario.
}

//==============================================================================
// MÉTODOS DE SETUP Y CONFIGURACIÓN
//==============================================================================
void JCBImagerAudioProcessorEditor::setupKnobs()
{
    // Ocultar todos los grupos heredados (Reverb/EQ/COMP/Filters)
    // Mantener visibles los knobs superiores de crossover (HPF/LPF → FREQ1/FREQ2)
    sidechainControls.scButton.setVisible(false);
    leftKnobs.reflectSlider.setVisible(false);
    leftKnobs.sizeSlider.setVisible(false);
    leftKnobs.drywetSlider.setVisible(false);
    leftKnobs.dampSlider.setVisible(false);
    leftKnobs.stSlider.setVisible(false);
    leftKnobs.freezeButton.setVisible(false);
    eqControls.eqOnButton.setVisible(false);
    eqControls.lsfSlider.setVisible(false);
    eqControls.pfSlider.setVisible(false);
    eqControls.hsfSlider.setVisible(false);
    eqControls.lsgSlider.setVisible(false);
    eqControls.pgSlider.setVisible(false);
    eqControls.hsgSlider.setVisible(false);
    compControls.compOnButton.setVisible(false);
    compControls.thdSlider.setVisible(false);
    compControls.ratioSlider.setVisible(false);
    compControls.atkSlider.setVisible(false);
    compControls.relSlider.setVisible(false);
    compControls.gainSlider.setVisible(false);
    compControls.pumpButton.setVisible(false);
    rightTabs.eqTab.setVisible(false);
    rightTabs.compTab.setVisible(false);

    auto& apvts = processor.apvts;

    const auto lowBandColour  = juce::Colour(0xFF9C27B0);
    const auto midBandColour  = juce::Colour(0xFF7C4DFF);
    const auto highBandColour = juce::Colour(0xFF2196F3);

    auto addKnob = [&](CustomSlider& s, const char* id,
                       std::unique_ptr<CustomSliderAttachment>& att,
                       const char* name)
    {
        s.setName(name);
        s.setComponentID(name);
        s.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        s.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 16);
        s.setLookAndFeel(&sliderLAFBig);
        s.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
        addAndMakeVisible(s);
        if (auto* p = apvts.getParameter(id))
            att = std::make_unique<CustomSliderAttachment>(*p, s, &undoManager);
        else { s.setEnabled(false); s.setAlpha(0.35f); }
    };

    auto addBtn = [&](juce::TextButton& b, const char* id,
                      std::unique_ptr<UndoableButtonAttachment>& att,
                      const char* label,
                      bool updateVisualState)
    {
        b.setButtonText(label);
        b.setClickingTogglesState(true);
        b.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
        b.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.8f));
        b.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
        addAndMakeVisible(b);
        if (auto* p = apvts.getParameter(id))
        {
            att = std::make_unique<UndoableButtonAttachment>(*p, b, &undoManager);
            if (updateVisualState)
            {
               att->onStateChange = [this, &b](bool isOn)
               {
                    juce::ignoreUnused(isOn);
                    b.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
                    updateBandVisualStates();
                };
            }
        }
        else { b.setVisible(false); }
    };

    auto addModeButton = [&](juce::TextButton& b, const char* id,
                             std::unique_ptr<UndoableButtonAttachment>& att,
                             const juce::String& componentId,
                             const juce::String& tooltip)
    {
        b.setClickingTogglesState(true);
        b.setComponentID(componentId);
        b.setLookAndFeel(modeButtonLAF.get());
        b.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
        b.setColour(juce::TextButton::textColourOffId, juce::Colours::white.withAlpha(0.78f));
        b.setColour(juce::TextButton::textColourOnId, juce::Colours::white);
        b.setTooltip(tooltip);
        b.onStateChange = [this]() { updateModeButtonLabels(); };
        addAndMakeVisible(b);

        if (auto* p = apvts.getParameter(id))
        {
            att = std::make_unique<UndoableButtonAttachment>(*p, b, &undoManager);
            att->onStateChange = [this](bool) { updateModeButtonLabels(); };
        }
        else
        {
            b.setEnabled(false);
            b.setAlpha(0.35f);
        }
    };

    // Sliders principales
    addKnob(imager.freq1,   "a_FREQ1", imager.freq1Att,   "freq1");
    addKnob(imager.freq2,   "b_FREQ2", imager.freq2Att,   "freq2");
    addKnob(imager.lowGain, "c_LOW",   imager.lowGainAtt, "low");
    addKnob(imager.midGain, "d_MED",   imager.midGainAtt, "mid");
    addKnob(imager.highGain,"e_HIGH",  imager.highGainAtt,"high");
    addKnob(imager.lowBal,  "k_LOW_bal",  imager.lowBalAtt,  "lowBal");
    addKnob(imager.midBal,  "l_MED_bal",  imager.midBalAtt,  "midBal");
    addKnob(imager.highBal, "m_HIGH_bal", imager.highBalAtt, "highBal");
    addKnob(imager.drywet,  "x_DRYWET",   imager.drywetAtt,  "drywet");
    addKnob(imager.trim,    "v_TRIM",     imager.trimAtt,    "trim");
    addKnob(imager.makeup,  "w_MAKEUP",   imager.makeupAtt,  "makeup");

    // Botones
    // SOLO buttons (UI-only, no APVTS attachment)
    auto setupSoloBtn = [&](juce::TextButton& b, const char* label, const juce::Colour& baseColour, const juce::String& componentId)
    {
        b.setButtonText(label);
        b.setClickingTogglesState(true);
        b.setComponentID(componentId);
        b.setLookAndFeel(soloButtonLAF.get());
        b.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
        b.setColour(juce::TextButton::textColourOffId, baseColour.brighter(1.4f));
        b.setColour(juce::TextButton::textColourOnId, juce::Colours::white);
        b.addListener(this);
        addAndMakeVisible(b);
    };
    setupSoloBtn(imager.soloLow,  "SOLO LOW",  juce::Colour(0xFF9C27B0), "soloLow");
    setupSoloBtn(imager.soloMid,  "SOLO MID",  juce::Colour(0xFF7C4DFF), "soloMid");
    setupSoloBtn(imager.soloHigh, "SOLO HIGH", juce::Colour(0xFF2196F3), "soloHigh");

    // MUTES con APVTS (attachments)
    addBtn(imager.muteLow,  "n_MUTLOW",   imager.muteLowAtt,  "MUTE LOW",  true);
    addBtn(imager.muteMid,  "o_MUTMED",   imager.muteMidAtt,  "MUTE MID",  true);
    addBtn(imager.muteHigh, "p_MUTHIGH",  imager.muteHighAtt, "MUTE HIGH", true);

    auto styleMuteButton = [&](juce::TextButton& b, const juce::Colour& baseColour, const juce::String& componentId)
    {
        b.setComponentID(componentId);
        b.setLookAndFeel(muteButtonLAF.get());
        b.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
        auto offColour = baseColour.interpolatedWith(juce::Colours::white, 0.45f).withAlpha(0.9f);
        b.setColour(juce::TextButton::textColourOffId, offColour);
        b.setColour(juce::TextButton::textColourOnId, juce::Colours::white);
    };

    styleMuteButton(imager.muteLow,  juce::Colour(0xFF9C27B0), "muteLow");
    styleMuteButton(imager.muteMid,  juce::Colour(0xFF7C4DFF), "muteMid");
    styleMuteButton(imager.muteHigh, juce::Colour(0xFF2196F3), "muteHigh");
    if (imager.muteLowAtt)
        imager.muteLowAtt->onStateChange = [this](bool){ updateBandVisualStates(); };
    if (imager.muteMidAtt)
        imager.muteMidAtt->onStateChange = [this](bool){ updateBandVisualStates(); };
    if (imager.muteHighAtt)
        imager.muteHighAtt->onStateChange = [this](bool){ updateBandVisualStates(); };
    addModeButton(imager.inputMode,  "j_input",  imager.inputModeAtt,  "inputMode",  JUCE_UTF8("Alterna modo de entrada XY/MS (OFF=XY, ON=MS)"));
    addModeButton(imager.outputMode, "q_output", imager.outputModeAtt, "outputMode", JUCE_UTF8("Alterna modo de salida XY/MS (OFF=XY, ON=MS)"));

    updateModeButtonLabels();

    // Cargar estado inicial de SOLO desde UISettings (MUTE lo gestiona APVTS)
    loadSoloStateFromUISettings();

    // WIDTH knobs: TextBoxAbove con valores lineales 0.00 ... 2.00 (1.00 por defecto)
    auto setupWidthKnob = [](CustomSlider& s)
    {
        s.setTextBoxStyle(juce::Slider::TextBoxAbove, true, 60, 16);
        s.setTextBoxIsEditable(true);
        s.textFromValueFunction = [](double v)
        {
            auto clamped = juce::jlimit(0.0, 2.0, v);
            return juce::String(clamped, 2);
        };
        s.valueFromTextFunction = [](const juce::String& text)
        {
            auto cleaned = text.trim().replaceCharacter(',', '.');
            double value = juce::jlimit(0.0, 2.0, cleaned.getDoubleValue());
            return value;
        };
    };
    setupWidthKnob(imager.lowGain);
    setupWidthKnob(imager.midGain);
    setupWidthKnob(imager.highGain);

    auto styleWidthKnob = [&](CustomSlider& slider, const juce::Colour& accent)
    {
        auto brightAccent = accent.interpolatedWith(juce::Colours::white, 0.55f);
        slider.setColour(juce::Slider::textBoxBackgroundColourId, juce::Colours::transparentBlack);
        slider.setColour(juce::Slider::textBoxOutlineColourId, brightAccent.withAlpha(0.18f));
        slider.setColour(juce::Slider::textBoxTextColourId, brightAccent);
        slider.setColour(juce::Slider::textBoxHighlightColourId, brightAccent.withAlpha(0.4f));
        slider.setColour(juce::Slider::rotarySliderOutlineColourId, brightAccent);
        slider.setTextBoxIsEditable(true);
    };

    styleWidthKnob(imager.lowGain,  lowBandColour);
    styleWidthKnob(imager.midGain,  midBandColour);
    styleWidthKnob(imager.highGain, highBandColour);
    // Forzar actualización visible inmediata del TextBox con el mapeo %
    imager.lowGain .setValue(imager.lowGain .getValue(), juce::sendNotificationSync);
    imager.midGain .setValue(imager.midGain .getValue(), juce::sendNotificationSync);
    imager.highGain.setValue(imager.highGain.getValue(), juce::sendNotificationSync);

    // Ocultar knobs grandes de frecuencia (usamos XLow/XHigh arriba)
    imager.freq1.setVisible(false);
    imager.freq2.setVisible(false);

    // Configurar sliders de BALANCE como horizontales con centrado en C (0.5)
    auto setupBalance = [&](CustomSlider& slider,
                            juce::Label& labelL,
                            juce::Label& labelC,
                            juce::Label& labelR,
                            const juce::Colour& accent)
    {
        slider.setSliderStyle(juce::Slider::LinearHorizontal);
        slider.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
        slider.setRange(0.0, 1.0, 0.001);
        slider.setDoubleClickReturnValue(true, 0.5);
        const auto trackColour = juce::Colour(0xFF2E222E);
        slider.setColour(juce::Slider::backgroundColourId, trackColour);
        slider.setColour(juce::Slider::trackColourId, trackColour);
        auto thumbColour = accent.interpolatedWith(juce::Colours::white, 0.55f);
        slider.setColour(juce::Slider::thumbColourId, thumbColour);

        // Labels L C R
        labelL.setText("L", juce::dontSendNotification);
        labelC.setText("C", juce::dontSendNotification);
        labelR.setText("R", juce::dontSendNotification);
        auto leftColour  = juce::Colour(0xFF2196F3).withAlpha(0.8f);
        auto rightColour = juce::Colour(0xFF7C4DFF).withAlpha(0.8f);
        auto centreColour = leftColour.interpolatedWith(rightColour, 0.5f).withAlpha(0.85f);
        labelL.setColour(juce::Label::textColourId, leftColour);
        labelC.setColour(juce::Label::textColourId, centreColour);
        labelR.setColour(juce::Label::textColourId, rightColour);
        labelL.setJustificationType(juce::Justification::centredLeft);
        labelC.setJustificationType(juce::Justification::centred);
        labelR.setJustificationType(juce::Justification::centredRight);
        addAndMakeVisible(labelL); addAndMakeVisible(labelC); addAndMakeVisible(labelR);
    };
    setupBalance(imager.lowBal,  imager.lowBalL,  imager.lowBalC,  imager.lowBalR,  lowBandColour);
    setupBalance(imager.midBal,  imager.midBalL,  imager.midBalC,  imager.midBalR,  midBandColour);
    setupBalance(imager.highBal, imager.highBalL, imager.highBalC, imager.highBalR, highBandColour);

    // === CROSSOVER KNOBS (HPF/LPF) EN LA PARTE SUPERIOR ===
    // HPF → a_FREQ1
    sidechainControls.hpfSlider.setName("xlow");
    sidechainControls.hpfSlider.setComponentID("xlow");
    sidechainControls.hpfSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    sidechainControls.hpfSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 60, 16);
    sidechainControls.hpfSlider.setLookAndFeel(&sliderLAFBig);
    sidechainControls.hpfSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::white);
    sidechainControls.hpfSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colours::white);
    sidechainControls.hpfSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
    sidechainControls.hpfSlider.setTextBoxIsEditable(true);
    sidechainControls.hpfSlider.setDoubleClickReturnValue(true, 250.0);  // default a_FREQ1
    sidechainControls.hpfSlider.setPopupDisplayEnabled(false, false, this);
    sidechainControls.hpfSlider.setNumDecimalPlacesToDisplay(0);
    sidechainControls.hpfSlider.textFromValueFunction = [](double value){
        return value < 1000.0 ? juce::String(static_cast<int>(value))
                              : juce::String(value/1000.0, 1) + "k"; };
    sidechainControls.hpfSlider.setTextValueSuffix(" Hz");
    sidechainControls.hpfSlider.setRange(20.0, 1000.0, 1.0);
    sidechainControls.hpfSlider.setSkewFactorFromMidPoint(250.0);
    addAndMakeVisible(sidechainControls.hpfSlider);
    if (auto* paramF1 = apvts.getParameter("a_FREQ1"))
    {
        sidechainControls.hpfAttachment = std::make_unique<CustomSliderAttachment>(
            *paramF1, sidechainControls.hpfSlider, &undoManager);
        sidechainControls.hpfAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    // LPF → b_FREQ2
    sidechainControls.lpfSlider.setName("xhigh");
    sidechainControls.lpfSlider.setComponentID("xhigh");
    sidechainControls.lpfSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    sidechainControls.lpfSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 60, 16);
    sidechainControls.lpfSlider.setLookAndFeel(&sliderLAFBig);
    sidechainControls.lpfSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::white);
    sidechainControls.lpfSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colours::white);
    sidechainControls.lpfSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
    sidechainControls.lpfSlider.setTextBoxIsEditable(true);
    sidechainControls.lpfSlider.setDoubleClickReturnValue(true, 5000.0);
    sidechainControls.lpfSlider.setPopupDisplayEnabled(false, false, this);
    sidechainControls.lpfSlider.setNumDecimalPlacesToDisplay(0);
    sidechainControls.lpfSlider.textFromValueFunction = [](double value){
        return value < 1000.0 ? juce::String(static_cast<int>(value))
                              : juce::String(value/1000.0, 1) + "k"; };
    sidechainControls.lpfSlider.setTextValueSuffix(" Hz");
    sidechainControls.lpfSlider.setRange(2500.0, 10000.0, 1.0);
    sidechainControls.lpfSlider.setSkewFactorFromMidPoint(5000.0);
    addAndMakeVisible(sidechainControls.lpfSlider);
    if (auto* paramF2 = apvts.getParameter("b_FREQ2"))
    {
        sidechainControls.lpfAttachment = std::make_unique<CustomSliderAttachment>(
            *paramF2, sidechainControls.lpfSlider, &undoManager);
        sidechainControls.lpfAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    // No usar el botón FILTERS en Imager
    sidechainControls.scButton.setVisible(false);

    // Importante: omitir el resto del código heredado de setupKnobs()
    return;
    // === FILTROS DE ENTRADA ===
    // Slider HPF
    sidechainControls.hpfSlider.setName("hpf");
    sidechainControls.hpfSlider.setComponentID("hpf");
    sidechainControls.hpfSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    sidechainControls.hpfSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 60, 16);
    sidechainControls.hpfSlider.setLookAndFeel(&sliderLAFBig);  // Usar LAF grande como ExpansorGate
    sidechainControls.hpfSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::white);  // Blanco fijo
    sidechainControls.hpfSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colours::white);  // Blanco fijo
    sidechainControls.hpfSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
    sidechainControls.hpfSlider.setTextBoxIsEditable(true);
    sidechainControls.hpfSlider.setEnabled(true);  // Inicialmente habilitado
    sidechainControls.hpfSlider.setAlpha(1.0f);  // Inicialmente visible
    sidechainControls.hpfSlider.setDoubleClickReturnValue(true, 100.0f);  // Default 100 Hz
    sidechainControls.hpfSlider.setPopupDisplayEnabled(false, false, this);
    sidechainControls.hpfSlider.setNumDecimalPlacesToDisplay(0);
    // Formato de texto personalizado para frecuencia
    sidechainControls.hpfSlider.textFromValueFunction = [](double value) {
        if (value < 1000.0)
            return juce::String(static_cast<int>(value));
        else
            return juce::String(value / 1000.0, 1) + "k";
    };
    sidechainControls.hpfSlider.setTextValueSuffix(" Hz");
    sidechainControls.hpfSlider.setRange(20.0, 5000.0, 1.0);
    sidechainControls.hpfSlider.setSkewFactorFromMidPoint(500.0);  // 500 Hz en el centro visual
    addAndMakeVisible(sidechainControls.hpfSlider);
    if (auto* param = processor.apvts.getParameter("l_HPF"))
    {
        sidechainControls.hpfAttachment = std::make_unique<CustomSliderAttachment>(
            *param, sidechainControls.hpfSlider, &undoManager);
        sidechainControls.hpfAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    // Slider LPF
    sidechainControls.lpfSlider.setName("lpf");
    sidechainControls.lpfSlider.setComponentID("lpf");
    sidechainControls.lpfSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    sidechainControls.lpfSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 60, 16);
    sidechainControls.lpfSlider.setLookAndFeel(&sliderLAFBig);  // Usar LAF grande como ExpansorGate
    sidechainControls.lpfSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::white);  // Blanco fijo
    sidechainControls.lpfSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colours::white);  // Blanco fijo
    sidechainControls.lpfSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
    sidechainControls.lpfSlider.setTextBoxIsEditable(true);
    sidechainControls.lpfSlider.setEnabled(true);  // Inicialmente habilitado
    sidechainControls.lpfSlider.setAlpha(1.0f);  // Inicialmente visible
    sidechainControls.lpfSlider.setDoubleClickReturnValue(true, 5000.0f);
    sidechainControls.lpfSlider.setPopupDisplayEnabled(false, false, this);
    sidechainControls.lpfSlider.setNumDecimalPlacesToDisplay(0);
    // Formato de texto personalizado para frecuencia
    sidechainControls.lpfSlider.textFromValueFunction = [](double value) {
        if (value < 1000.0)
            return juce::String(static_cast<int>(value));
        else
            return juce::String(value / 1000.0, 1) + "k";
    };
    sidechainControls.lpfSlider.setTextValueSuffix(" Hz");
    sidechainControls.lpfSlider.setRange(2500.0, 10000.0, 1.0);
    sidechainControls.lpfSlider.setSkewFactorFromMidPoint(5000.0);  // 5kHz en el centro
    addAndMakeVisible(sidechainControls.lpfSlider);
    if (auto* param = processor.apvts.getParameter("k_LPF"))
    {
        sidechainControls.lpfAttachment = std::make_unique<CustomSliderAttachment>(
            *param, sidechainControls.lpfSlider, &undoManager);
        sidechainControls.lpfAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    // Botón FILTERS (antes SC) - VISIBLE para activar/desactivar filtros
    sidechainControls.scButton.setClickingTogglesState(true);
    sidechainControls.scButton.setLookAndFeel(&smallButtonLAF);  // Usar LAF básico
    sidechainControls.scButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    sidechainControls.scButton.setColour(juce::TextButton::buttonOnColourId, juce::Colours::transparentBlack);  // Ahora manejado por LAF
    sidechainControls.scButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.7f));
    sidechainControls.scButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    sidechainControls.scButton.addListener(this);
    addAndMakeVisible(sidechainControls.scButton);
    if (auto* paramFilters = processor.apvts.getParameter("y_FILTERS"))
    {
        sidechainControls.scAttachment = std::make_unique<UndoableButtonAttachment>(
            *paramFilters, sidechainControls.scButton, &undoManager);
        sidechainControls.scAttachment->onParameterChange = [this]()
        {
            handleParameterChange();
        };
    }
    else
    {
        sidechainControls.scButton.setVisible(false);
    }

    // Establecer estado inicial de los filtros
    updateSidechainComponentStates();

    // === PARTE IZQUIERDA ===
    // === REFLECT (c_REFLECT) === (exact MODE styling with new range and % display)
    leftKnobs.reflectSlider.setComponentID("reflect");
    leftKnobs.reflectSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    leftKnobs.reflectSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 100, 16);
    leftKnobs.reflectSlider.setLookAndFeel(&sliderLAFBig);
    leftKnobs.reflectSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
    leftKnobs.reflectSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::white);
    leftKnobs.reflectSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFFFFFFF));
    leftKnobs.reflectSlider.setRange(0.1, 1.0, 0.01);
    leftKnobs.reflectSlider.setSkewFactorFromMidPoint(0.77);  // 0.77 aparece en la mitad del knob
    leftKnobs.reflectSlider.setDoubleClickReturnValue(true, 0.766); // 74 % visual
    leftKnobs.reflectSlider.setPopupDisplayEnabled(false, false, this);
    leftKnobs.reflectSlider.setTextBoxIsEditable(true);
    leftKnobs.reflectSlider.setNumDecimalPlacesToDisplay(0);
    leftKnobs.reflectSlider.textFromValueFunction = [](double value) {
        const double pct = juce::jlimit(0.0, 1.0, (value - 0.1) / (1.0 - 0.1));
        const int p = juce::roundToInt(pct * 100.0);
        return juce::String(p) + " %";
    };
    leftKnobs.reflectSlider.valueFromTextFunction = [](const juce::String& text) {
        auto t = text.trim();
        if (t.endsWith("%")) t = t.dropLastCharacters(1).trim();
        const double p = juce::jlimit(0.0, 100.0, t.getDoubleValue());
        return 0.1 + (p / 100.0) * (1.0 - 0.1);
    };
    leftKnobs.reflectSlider.setTooltip(getTooltipText("reflect"));
    addAndMakeVisible(leftKnobs.reflectSlider);
    if (auto* paramReflect = processor.apvts.getParameter("c_REFLECT"))
    {
        leftKnobs.reflectAttachment = std::make_unique<CustomSliderAttachment>(
            *paramReflect, leftKnobs.reflectSlider, &undoManager);
        leftKnobs.reflectAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    leftKnobs.sizeSlider.setComponentID("size");
    leftKnobs.sizeSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    leftKnobs.sizeSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 70, 16);
    leftKnobs.sizeSlider.setLookAndFeel(&sliderLAFBig);
    leftKnobs.sizeSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
    leftKnobs.sizeSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFFFFFFF));    leftKnobs.sizeSlider.setDoubleClickReturnValue(true, 1.5);  // Valor por defecto 1.5
    leftKnobs.sizeSlider.setPopupDisplayEnabled(false, false, this);
    leftKnobs.sizeSlider.setTextBoxIsEditable(true);
    leftKnobs.sizeSlider.setNumDecimalPlacesToDisplay(1);
    leftKnobs.sizeSlider.setRange(0.1, 4.0, 0.01);
    leftKnobs.sizeSlider.setSkewFactorFromMidPoint(1.0); // Concentrar rango útil en valores bajos
    addAndMakeVisible(leftKnobs.sizeSlider);
    if (auto* param = processor.apvts.getParameter("e_SIZE"))
    {
        leftKnobs.sizeAttachment = std::make_unique<CustomSliderAttachment>(
            *param, leftKnobs.sizeSlider, &undoManager);
        leftKnobs.sizeAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    leftKnobs.drywetSlider.setComponentID("drywet");
    leftKnobs.drywetSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    leftKnobs.drywetSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 70, 16);
    leftKnobs.drywetSlider.setLookAndFeel(&sliderLAFBig);
    leftKnobs.drywetSlider.setTextBoxIsEditable(true);
    leftKnobs.drywetSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
    leftKnobs.drywetSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFB1CAF6));  // Azul pálido como output
    leftKnobs.drywetSlider.setDoubleClickReturnValue(true, 0.5);  // Default: 100% (o_DRYWET = 1.0)
    leftKnobs.drywetSlider.setPopupDisplayEnabled(false, false, this);
    leftKnobs.drywetSlider.setRange(0.0, 1.0, 0.01);  // Rango interno 0.0-1.0
    leftKnobs.drywetSlider.textFromValueFunction = [](double value) {
        return juce::String(static_cast<int>(value * 101)) + " %";
    };
    leftKnobs.drywetSlider.valueFromTextFunction = [](const juce::String& text) {
        auto trimmed = text.trim();
        // Eliminar símbolo de porcentaje si existe
        if (trimmed.endsWith("%"))
            trimmed = trimmed.dropLastCharacters(1).trim();

        // Convertir a número y normalizar de 0-100 a 0-1
        auto percentage = trimmed.getDoubleValue();
        return juce::jlimit(0.0, 1.0, percentage / 100.0);
    };
    addAndMakeVisible(leftKnobs.drywetSlider);
    if (auto* param = processor.apvts.getParameter("b_DRYWET"))
    {
        leftKnobs.drywetAttachment = std::make_unique<CustomSliderAttachment>(
            *param, leftKnobs.drywetSlider, &undoManager);
        leftKnobs.drywetAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    leftKnobs.dampSlider.setComponentID("damp");
    leftKnobs.dampSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    leftKnobs.dampSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 70, 16);
    leftKnobs.dampSlider.setLookAndFeel(&sliderLAFBig);
    leftKnobs.dampSlider.setTextBoxIsEditable(true);
    leftKnobs.dampSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
    leftKnobs.dampSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFFFFFFF));
    leftKnobs.dampSlider.setRange(0.1, 0.95, 0.01);
    leftKnobs.dampSlider.setDoubleClickReturnValue(true, 0.10);    // 0% visual (Gen 0.1)
    leftKnobs.dampSlider.setPopupDisplayEnabled(false, false, this);
    // Funciones de conversión para mostrar porcentajes
    leftKnobs.dampSlider.textFromValueFunction = [](double value) {
        const double pct = juce::jlimit(0.0, 1.0, (value - 0.1) / (0.95 - 0.1));
        const int p = juce::roundToInt(pct * 100.0);
        return juce::String(p) + " %";
    };
    leftKnobs.dampSlider.valueFromTextFunction = [](const juce::String& text) {
        juce::String cleanText = text.trimEnd().upToLastOccurrenceOf("%", false, false);
        double pct = juce::jlimit(0.0, 100.0, cleanText.getDoubleValue()) / 100.0;
        return 0.1 + pct * (0.95 - 0.1);
    };

    addAndMakeVisible(leftKnobs.dampSlider);
    if (auto* param = processor.apvts.getParameter("d_DAMP"))
    {
        leftKnobs.dampAttachment = std::make_unique<CustomSliderAttachment>(
            *param, leftKnobs.dampSlider, &undoManager);
        leftKnobs.dampAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    leftKnobs.stSlider.setComponentID("stereo");
    leftKnobs.stSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    leftKnobs.stSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 16);
    leftKnobs.stSlider.setLookAndFeel(&sliderLAFBig);

    leftKnobs.stSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
    leftKnobs.stSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFB1CAF6));  // Azul pálido como output

    leftKnobs.stSlider.setTextBoxIsEditable(true);
    leftKnobs.stSlider.setEnabled(true);
    leftKnobs.stSlider.setDoubleClickReturnValue(true, 0.425f);
    leftKnobs.stSlider.setPopupDisplayEnabled(false, false, this);
    // Range aligned to parameter: 0..0.85. Paso 0.005 permite 0.425 exacto
    leftKnobs.stSlider.setRange(0.0, 0.85, 0.005);
    //leftKnobs.stSlider.setSkewFactorFromMidPoint(0.5);
    // Funciones de conversión para mostrar porcentajes
    leftKnobs.stSlider.setTextValueSuffix({}); // sin sufijo; lo añadimos nosotros
    leftKnobs.stSlider.textFromValueFunction = [](double v)
    {
        const double maxV = 0.85;
        // Snap al 50% para evitar mostrar 51% por redondeos
        if (std::abs(v - 0.425) < 1.0e-3) {
            return juce::String(50) + " %";
        }
        double pct = (v / maxV) * 100.0;
        int ipct = juce::roundToInt(pct + 1.0e-6);
        ipct = juce::jlimit(0, 100, ipct);
        return juce::String(ipct) + " %";
    };
    leftKnobs.stSlider.valueFromTextFunction = [](const juce::String& text)
    {
        // extraer número de "42 %" o "42"
        double pct = text.retainCharacters("0123456789.-").getDoubleValue();
        pct = juce::jlimit(0.0, 100.0, pct);
        return (pct / 100.0) * 0.85; // devolvemos 0..0.85
    };


    addAndMakeVisible(leftKnobs.stSlider);
    if (auto* param = processor.apvts.getParameter("f_ST"))
    {
        leftKnobs.stAttachment = std::make_unique<CustomSliderAttachment>(
            *param, leftKnobs.stSlider, &undoManager);
        leftKnobs.stAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    leftKnobs.freezeButton.setClickingTogglesState(true);
    leftKnobs.freezeButton.setLookAndFeel(&smallButtonLAF);  // Usar LAF básico
    leftKnobs.freezeButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    leftKnobs.freezeButton.setColour(juce::TextButton::buttonOnColourId, juce::Colours::transparentBlack);
    leftKnobs.freezeButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.7f));
    // Cuando FREEZE está activo, colorear el texto en #36C0A6
    leftKnobs.freezeButton.setColour(juce::TextButton::textColourOnId, juce::Colour(0xFF36C0A6));
    leftKnobs.freezeButton.addListener(this);
    addAndMakeVisible(leftKnobs.freezeButton);
    if (auto* paramFreeze = processor.apvts.getParameter("g_FREEZE"))
    {
        leftKnobs.freezeAttachment = std::make_unique<UndoableButtonAttachment>(
            *paramFreeze, leftKnobs.freezeButton, &undoManager);
    }
    else
    {
        leftKnobs.freezeButton.setVisible(false);
    }
    leftKnobs.freezeAttachment->onParameterChange = [this]() { handleParameterChange(); };

    // === EQ CONTROLS (top-right) ===
    // EQ ON button (q_ONOFFEQ)
    eqControls.eqOnButton.setClickingTogglesState(true);
    eqControls.eqOnButton.setLookAndFeel(&smallButtonLAF);
    eqControls.eqOnButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    eqControls.eqOnButton.setColour(juce::TextButton::buttonOnColourId, juce::Colours::transparentBlack);
    // Texto del activador EQ: ON morado #8F86D0; OFF blanco pálido (alfa 0.5)
    eqControls.eqOnButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.5f));
    eqControls.eqOnButton.setColour(juce::TextButton::textColourOnId,  juce::Colour(0xFF8F86D0));
    eqControls.eqOnButton.addListener(this);
    addAndMakeVisible(eqControls.eqOnButton);
    if (auto* paramEQ = processor.apvts.getParameter("q_ONOFFEQ"))
    {
        eqControls.eqOnAttachment = std::make_unique<UndoableButtonAttachment>(*paramEQ, eqControls.eqOnButton, &undoManager);
        eqControls.eqOnAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }
    // Asegurar que el botón quede por encima de la malla FFT para clics
    eqControls.eqOnButton.toFront(true);

    auto setupHzSlider = [this](CustomSlider& s, const char* paramID, double dblClick, std::unique_ptr<CustomSliderAttachment>& outAtt) {
        s.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        s.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 16);
        s.setLookAndFeel(&sliderLAFBig);
        s.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
        s.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFFFFFFF));
        s.setDoubleClickReturnValue(true, dblClick);
        s.setPopupDisplayEnabled(false, false, this);
        s.setNumDecimalPlacesToDisplay(0);
        s.textFromValueFunction = [](double value) {
            if (value < 1000.0) return juce::String(static_cast<int>(value));
            return juce::String(value / 1000.0, 1) + "k";
        };
        s.setTextValueSuffix(" Hz");
        addAndMakeVisible(s);
        if (auto* param = processor.apvts.getParameter(paramID))
        {
            outAtt = std::make_unique<CustomSliderAttachment>(*param, s, &undoManager);
            outAtt->onParameterChange = [this]() { handleParameterChange(); };
        }
    };

    auto setupDbSlider = [this](CustomSlider& s, const char* paramID, double dblClick, std::unique_ptr<CustomSliderAttachment>& outAtt) {
        s.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        s.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 60, 16);
        s.setLookAndFeel(&sliderLAFBig);
        s.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
        s.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFFFFFFF));
        s.setDoubleClickReturnValue(true, dblClick);
        s.setPopupDisplayEnabled(false, false, this);
        s.setNumDecimalPlacesToDisplay(0);
        s.setTextValueSuffix(" dB");
        addAndMakeVisible(s);
        if (auto* param = processor.apvts.getParameter(paramID))
        {
            outAtt = std::make_unique<CustomSliderAttachment>(*param, s, &undoManager);
            outAtt->onParameterChange = [this]() { handleParameterChange(); };
        }
    };

    // EQ frequencies
    setupHzSlider(eqControls.lsfSlider, "n_LOWFREQ", 250.0, eqControls.lsfAttachment);
    setupHzSlider(eqControls.pfSlider,  "o_PEAKFREQ", 1500.0, eqControls.pfAttachment);
    setupHzSlider(eqControls.hsfSlider, "p_HIFREQ",  8600.0, eqControls.hsfAttachment);
    // Colorear cajas de texto de EQ en #7F78A2 (más claro)
    eqControls.lsfSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFF7F78A2));
    eqControls.pfSlider .setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFF7F78A2));
    eqControls.hsfSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFF7F78A2));
    // EQ gains
    setupDbSlider(eqControls.lsgSlider, "h_LOWGAIN", 0.0, eqControls.lsgAttachment);
    setupDbSlider(eqControls.pgSlider,  "i_PEAKGAIN", 0.0, eqControls.pgAttachment);
    setupDbSlider(eqControls.hsgSlider, "j_HIGAIN", 0.0, eqControls.hsgAttachment);
    // Colorear cajas de texto de gains EQ en #7F78A2
    eqControls.lsgSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFF7F78A2));
    eqControls.pgSlider .setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFF7F78A2));
    eqControls.hsgSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFF7F78A2));
    // Ensanchar la caja de texto para que quepa "+12.34 dB" sin constricción
    eqControls.lsgSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 64, 16);
    eqControls.pgSlider.setTextBoxStyle (juce::Slider::TextBoxAbove, false, 64, 16);
    eqControls.hsgSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 64, 16);
    // Mostrar signo + en ganancias positivas de EQ
    // Mostrar con 2 decimales; evitar "-0.00" usando umbral de cero
    auto plusDb2 = [](double v) {
        const double eps = 0.005; // ~0.5 centésimas
        double vv = (std::abs(v) < eps) ? 0.0 : v;
        if (vv == 0.0)
            return juce::String("0.00");
        return juce::String::formatted("%+0.2f", vv);
    };
    // Asegurar sufijo visible desde el inicio
    eqControls.lsgSlider.setTextValueSuffix(" dB");
    eqControls.pgSlider.setTextValueSuffix(" dB");
    eqControls.hsgSlider.setTextValueSuffix(" dB");
    eqControls.lsgSlider.setNumDecimalPlacesToDisplay(2);
    eqControls.pgSlider.setNumDecimalPlacesToDisplay(2);
    eqControls.hsgSlider.setNumDecimalPlacesToDisplay(2);
    eqControls.lsgSlider.textFromValueFunction = plusDb2;
    eqControls.pgSlider.textFromValueFunction  = plusDb2;
    eqControls.hsgSlider.textFromValueFunction = plusDb2;
    // Forzar refresco del texto inicial para mostrar "dB" desde el principio
    eqControls.lsgSlider.setValue(eqControls.lsgSlider.getValue(), juce::dontSendNotification);
    eqControls.pgSlider.setValue (eqControls.pgSlider.getValue(),  juce::dontSendNotification);
    eqControls.hsgSlider.setValue(eqControls.hsgSlider.getValue(), juce::dontSendNotification);

    // === COMP CONTROLS (bottom-right) ===
    // COMP ON button (r_ONOFFCOMP)
    compControls.compOnButton.setClickingTogglesState(true);
    compControls.compOnButton.setLookAndFeel(&smallButtonLAF);
    compControls.compOnButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    compControls.compOnButton.setColour(juce::TextButton::buttonOnColourId, juce::Colours::transparentBlack);
    // Texto del activador COMP: ON amarillo suave; OFF blanco pálido más tenue
    compControls.compOnButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.5f));
    compControls.compOnButton.setColour(juce::TextButton::textColourOnId,  juce::Colour(0xFFDCCF6E));
    compControls.compOnButton.addListener(this);
    addAndMakeVisible(compControls.compOnButton);
    if (auto* paramC = processor.apvts.getParameter("r_ONOFFCOMP"))
    {
        compControls.compOnAttachment = std::make_unique<UndoableButtonAttachment>(*paramC, compControls.compOnButton, &undoManager);
        compControls.compOnAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    // THD (dB)
    setupDbSlider(compControls.thdSlider, "s_THD", -18.0, compControls.thdAttachment);

    // RATIO (t_RATIO)
    compControls.ratioSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    compControls.ratioSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 60, 16);
    compControls.ratioSlider.setLookAndFeel(&sliderLAFBig);
    compControls.ratioSlider.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
    compControls.ratioSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFDCCF6E));
    compControls.ratioSlider.setDoubleClickReturnValue(true, 4.0);
    compControls.ratioSlider.setPopupDisplayEnabled(false, false, this);
    compControls.ratioSlider.setNumDecimalPlacesToDisplay(1);
    compControls.ratioSlider.textFromValueFunction = [](double v) { return juce::String(v, v < 10.0 ? 1 : 0) + ":1"; };
    addAndMakeVisible(compControls.ratioSlider);
    if (auto* paramR = processor.apvts.getParameter("t_RATIO"))
    {
        compControls.ratioAttachment = std::make_unique<CustomSliderAttachment>(*paramR, compControls.ratioSlider, &undoManager);
        compControls.ratioAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    // ATK, REL (ms)
    auto setupMsSlider = [this](CustomSlider& s, const char* paramID, double dblClick, std::unique_ptr<CustomSliderAttachment>& outAtt) {
        s.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
        s.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 16);
        s.setLookAndFeel(&sliderLAFBig);
        s.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentBlack);
        s.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFFFFFFF));
        s.setDoubleClickReturnValue(true, dblClick);
        s.setPopupDisplayEnabled(false, false, this);
        s.setNumDecimalPlacesToDisplay(0);
        s.setTextValueSuffix(" ms");
    addAndMakeVisible(s);
        if (auto* param = processor.apvts.getParameter(paramID))
        {
            outAtt = std::make_unique<CustomSliderAttachment>(*param, s, &undoManager);
            outAtt->onParameterChange = [this]() { handleParameterChange(); };
        }
    };
    setupMsSlider(compControls.atkSlider, "u_ATK", 110.0,   compControls.atkAttachment);
    setupMsSlider(compControls.relSlider, "v_REL", 750.0, compControls.relAttachment);
    // Ajustar skews/decimales: ATK centro 110 ms; REL centro 250 ms; ambos 1 decimal
    compControls.atkSlider.setSkewFactorFromMidPoint(110.0);
    compControls.atkSlider.setNumDecimalPlacesToDisplay(1);
    compControls.relSlider.setSkewFactorFromMidPoint(250.0);
    compControls.relSlider.setNumDecimalPlacesToDisplay(1);
    // Colorear cajas de texto de COMP en amarillo suave
    compControls.thdSlider  .setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFDCCF6E));
    compControls.atkSlider  .setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFDCCF6E));
    compControls.relSlider  .setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFDCCF6E));
    compControls.gainSlider .setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFDCCF6E));

    // GAIN (dB) — 2 decimales, sin sufijo duplicado
    setupDbSlider(compControls.gainSlider, "w_MAKEUP", 0.0, compControls.gainAttachment);
    // Ensanchar caja de texto
    compControls.gainSlider.setTextBoxStyle(juce::Slider::TextBoxAbove, false, 64, 16);
    // Asegurar sufijo visible desde el inicio
    compControls.gainSlider.setTextValueSuffix(" dB");
    compControls.gainSlider.setNumDecimalPlacesToDisplay(2);
    compControls.gainSlider.textFromValueFunction = [](double v) {
        const double eps = 0.005;
        double vv = (std::abs(v) < eps) ? 0.0 : v;
        if (vv == 0.0)
            return juce::String("0.00");
        return juce::String::formatted("%+0.2f", vv);
    };
    // Refrescar texto inicial
    compControls.gainSlider.setValue(compControls.gainSlider.getValue(), juce::dontSendNotification);
    // Asegurar color de texto amarillo (puede ser sobrescrito por setupDbSlider)
    compControls.gainSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colour(0xFFDCCF6E));

    // PUMP toggle (x_PUMP)
    compControls.pumpButton.setClickingTogglesState(true);
    compControls.pumpButton.setLookAndFeel(&smallButtonLAF);
    // Asegurar captura de clicks (por si algún overlay interfiere)
    compControls.pumpButton.setInterceptsMouseClicks(true, true);
    compControls.pumpButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    compControls.pumpButton.setColour(juce::TextButton::buttonOnColourId, juce::Colours::transparentBlack);
    // Estado visual del PUMP: OFF más pálido, ON amarillo
    compControls.pumpButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.5f));
    compControls.pumpButton.setColour(juce::TextButton::textColourOnId,  juce::Colour(0xFFDCCF6E));
    compControls.pumpButton.addListener(this);
    addAndMakeVisible(compControls.pumpButton);
    if (auto* paramPump = processor.apvts.getParameter("x_PUMP"))
    {
        compControls.pumpAttachment = std::make_unique<UndoableButtonAttachment>(*paramPump, compControls.pumpButton, &undoManager);
        compControls.pumpAttachment->onParameterChange = [this]() { handleParameterChange(); };
        // Refrescar texto/estado visual si cambia por automation/preset
        // (No se necesita acceso a 'this' en este momento)
        compControls.pumpAttachment->onStateChange = [](bool /*isOn*/) {
            // El color del texto ya depende del toggle y está configurado
        };
    }

    // Asegurar estados iniciales coherentes (habilitación de PUMP según COMP)
    updateCompComponentStates();
}

void JCBImagerAudioProcessorEditor::setupRightTabs()
{
    // Imager: no usamos pestañas derechas (EQ/COMP).
    // Asegurar que no aparezcan ni capturen clics.
    rightTabs.eqTab.setVisible(false);
    rightTabs.compTab.setVisible(false);
}

void JCBImagerAudioProcessorEditor::setupMeters()
{
    // Medidores de entrada
    addAndMakeVisible(inputMeterL);
    addAndMakeVisible(inputMeterR);
    // Medidor GR

    // Medidores de salida
    addAndMakeVisible(outputMeterL);
    addAndMakeVisible(outputMeterR);

    // Sliders de trim/makeup (Imager): v_TRIM y w_MAKEUP
    trimSlider.setComponentID("v_TRIM");
    addAndMakeVisible(trimSlider);
    if (auto* param = processor.apvts.getParameter("v_TRIM"))
    {
        trimAttachment = std::make_unique<CustomSliderAttachment>(*param, trimSlider, &undoManager);
        trimAttachment->onParameterChange = [this]() { handleParameterChange(); };
    }

    // Slider de makeup (salida)
    makeupSlider.setComponentID("w_MAKEUP");
    addAndMakeVisible(makeupSlider);
    if (auto* param = processor.apvts.getParameter("w_MAKEUP"))
    {
        makeupAttachment = std::make_unique<CustomSliderAttachment>(*param, makeupSlider, &undoManager);
        makeupAttachment->onParameterChange = [this]() { handleParameterChange(); };
        makeupSlider.setSkewFactorFromMidPoint(0.0);  // Centrar 0 dB visualmente
    }
}

void JCBImagerAudioProcessorEditor::setupPresetArea()
{
    // Botón Save - estilo transparente
    presetArea.saveButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    presetArea.saveButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    presetArea.saveButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    presetArea.saveButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    presetArea.saveButton.addListener(this);
    addAndMakeVisible(presetArea.saveButton);
    // Tooltip actualizado via getTooltipText("save") en updateAllTooltips()

    // Botón Save As - estilo transparente
    presetArea.saveAsButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    presetArea.saveAsButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    presetArea.saveAsButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    presetArea.saveAsButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    presetArea.saveAsButton.addListener(this);
    addAndMakeVisible(presetArea.saveAsButton);
    // Tooltip actualizado via getTooltipText("saveas") en updateAllTooltips()

    // Botón Delete - estilo transparente
    presetArea.deleteButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    presetArea.deleteButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    presetArea.deleteButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    presetArea.deleteButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    presetArea.deleteButton.addListener(this);
    addAndMakeVisible(presetArea.deleteButton);
    // Tooltip actualizado via getTooltipText("delete") en updateAllTooltips()

    // Botón Back - estilo transparente
    presetArea.backButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    presetArea.backButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    presetArea.backButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    presetArea.backButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    presetArea.backButton.addListener(this);
    addAndMakeVisible(presetArea.backButton);
    // Tooltip actualizado via getTooltipText("back") en updateAllTooltips()

    // Botón Next - estilo transparente
    presetArea.nextButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    presetArea.nextButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    presetArea.nextButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    presetArea.nextButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    presetArea.nextButton.addListener(this);
    addAndMakeVisible(presetArea.nextButton);
    // Tooltip actualizado via getTooltipText("next") en updateAllTooltips()

    // Menú de preset - usando CustomComboBox como en JCBExpansorGate
    presetArea.presetMenu.setJustificationType(juce::Justification::centred);
    presetArea.presetMenu.setTextWhenNothingSelected("");
    presetArea.presetMenu.setTextWhenNoChoicesAvailable("No presets");

    // Configurar onChange para cargar presets
    presetArea.presetMenu.onChange = [this]() {
        int selectedId = presetArea.presetMenu.getSelectedId();
        if (selectedId == 0) return;

        // CRÍTICO: Establecer flag de carga PRIMERO para prevenir transacciones de undo
        isLoadingPreset = true;

        // Guard de scope para asegurar que el flag siempre se resetea
        struct LoadingGuard {
            bool& flag;
            LoadingGuard(bool& f) : flag(f) { flag = true; }
            ~LoadingGuard() { flag = false; }
        } guard(isLoadingPreset);

        // NOTA: El historial de undo se borrará al final para evitar grabar cambios de parámetros

        // Buscar el nombre real del preset usando el mapeo
        juce::String presetName;
        if (presetIdToNameMap.find(selectedId) != presetIdToNameMap.end()) {
            presetName = presetIdToNameMap[selectedId];
        } else {
            // Si no está en el mapeo, intentar obtenerlo del texto del menú (fallback)
            presetName = presetArea.presetMenu.getText();
            if (presetName.isEmpty()) {
                presetArea.presetMenu.setSelectedId(0);
                return;
            }
        }

        // Ignorar separadores
        if (presetName.startsWith("---")) {
            presetArea.presetMenu.setSelectedId(0);
            return;
        }

        if (presetName == "DEFAULT") {
            // Preset DEFAULT: Resetear todos los parámetros a sus valores por defecto definidos
            // Usar acceso directo a parámetros para actualizaciones inmediatas y confiables

            // Deshabilitar undo durante la carga de preset
            isLoadingPreset = true;

            // 1) Resetear TODOS los parámetros del APVTS a sus valores por defecto
            {
                auto& params = processor.getParameters();
                for (auto* p : params)
                {
                    if (auto* withID = dynamic_cast<juce::AudioProcessorParameterWithID*>(p))
                    {
                        if (auto* ranged = processor.apvts.getParameter(withID->paramID))
                        {
                            float def = ranged->getDefaultValue(); // normalizado 0..1
                            ranged->beginChangeGesture();
                            ranged->setValueNotifyingHost(def);
                            ranged->endChangeGesture();
                        }
                    }
                }
            }

            // Establecer todos los parámetros a sus valores por defecto usando gesture mechanism
            // Esto replica el mismo mecanismo usado por CustomSliderAttachment (doble-click)
            // COMENTADO: Reset de sliders de distorsión que no existen
            /*
            if (auto* param = processor.apvts.getParameter("k_INPUT")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                trimSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("a_DRYWET")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                leftBottomKnobs.drywetSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("e_CEILING")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                leftKnobs.ceilingSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("b_DRIVE")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                rightBottomKnobs.driveSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("d_MODE")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                reflectControls.reflectSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("l_OUTPUT")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                makeupSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("j_HPF")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                sidechainControls.hpfSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("k_LPF")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                sidechainControls.lpfSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("l_SC")) {
                float defaultValue = param->getDefaultValue();
                bool toggleState = defaultValue >= 0.5f;
                sidechainControls.scButton.setToggleState(toggleState, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("o_BAND")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                sidechainControls.bandSlider.setValue(realValue, juce::sendNotificationSync);
            }
            */
            // SIEMPRE salir de bypass al cargar DEFAULT
            parameterButtons.bypassButton.setToggleState(false, juce::sendNotificationSync);
            // COMENTADO: Más resets de controles de distorsión que no existen
            /*
            if (auto* param = processor.apvts.getParameter("h_BITSON")) {
                float defaultValue = param->getDefaultValue();
                bool toggleState = defaultValue >= 0.5f;
                rightBottomKnobs.bitButton.setToggleState(toggleState, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("i_TILT")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                rightTopControls.tiltSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("c_DC")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                rightBottomKnobs.dcSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("g_BITS")) {
                float defaultValue = param->getDefaultValue();
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                rightTopControls.bitsSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("n_DOWNSAMPLEON")) {
                float defaultValue = param->getDefaultValue(); // defaultValue = 0 (OFF)
                bool toggleState = defaultValue >= 0.5f; // false = OFF
                rightTopControls.downsampleButton.setToggleState(toggleState, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("p_TILTPOS")) {
                float defaultValue = param->getDefaultValue(); // defaultValue = 0 (PRE)
                bool toggleState = defaultValue >= 0.5f; // false = PRE
                rightTopControls.tiltPosButton.setToggleState(toggleState, juce::sendNotificationSync);
                rightTopControls.tiltPosButton.setButtonText(toggleState ? "POST" : "PRE");
            }
            if (auto* param = processor.apvts.getParameter("p_DISTON")) {
                float defaultValue = param->getDefaultValue(); // defaultValue = 1 (ON)
                bool toggleState = defaultValue >= 0.5f; // true = ON
                rightBottomKnobs.distOnButton.setToggleState(toggleState, juce::sendNotificationSync);
                rightBottomKnobs.distOnButton.setButtonText(toggleState ? "ON" : "OFF");
            }
            if (auto* param = processor.apvts.getParameter("m_DOWNSAMPLE")) {
                float defaultValue = param->getDefaultValue(); // defaultValue = 0 (0%)
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                rightTopControls.downsampleSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("p_BANDSOLO")) {
                float defaultValue = param->getDefaultValue(); // defaultValue = 0 (SOLO off)
                bool toggleState = defaultValue >= 0.5f; // false = SOLO off
                sidechainControls.bandSoloButton.setToggleState(toggleState, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("p_SAFELIMITON")) {
                float defaultValue = param->getDefaultValue(); // defaultValue = 0 (OFF)
                bool toggleState = defaultValue >= 0.5f; // false = OFF
                rightTopControls.safeLimitButton.setToggleState(toggleState, juce::sendNotificationSync);
                rightTopControls.safeLimitButton.setButtonText("LIM");
            }
            */
            // COMENTADO: Más resets de controles de distorsión
            /*
            if (auto* param = processor.apvts.getParameter("q_TONEON")) {
                float defaultValue = param->getDefaultValue(); // defaultValue = 0 (OFF)
                bool toggleState = defaultValue >= 0.5f; // false = OFF
                leftBottomKnobs.toneLpfButton.setToggleState(toggleState, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("r_TONEFREQ")) {
                float defaultValue = param->getDefaultValue(); // defaultValue = 12000 Hz
                float realValue = param->getNormalisableRange().convertFrom0to1(defaultValue);
                leftBottomKnobs.toneFreqSlider.setValue(realValue, juce::sendNotificationSync);
            }
            if (auto* param = processor.apvts.getParameter("s_TILTON")) {
                float defaultValue = param->getDefaultValue(); // defaultValue = 1 (ON)
                bool toggleState = defaultValue >= 0.5f; // true = ON
                rightTopControls.tiltOnButton.setToggleState(toggleState, juce::sendNotificationSync);
            }
            */

            // Reactivar undo después carga de preset
            isLoadingPreset = false;

            // IMPORTANTE: Forzar la sincronización directa de Gen~ para asegurar valores correctos de los parámetros
            // Esto replica la misma sincronización realizada durante la instanciación del plugin
            for (int i = 0; i < JCBImager::num_params(); i++) {
                auto paramName = juce::String(JCBImager::getparametername(processor.getPluginState(), i));
                if (auto* param = processor.apvts.getRawParameterValue(paramName)) {
                    float value = param->load();

                    // Aplicar la misma validación que en parameterChanged()
                    if (paramName == "b_DRIVE" && value < 1.0f) {
                        value = 1.0f;  // Drive mínimo 1x
                    }
                    if (paramName == "d_MODE" && value > 7.0f) {
                        value = 7.0f;   // Mode máximo 7
                    }

                    JCBImager::setparameter(processor.getPluginState(), i, value, nullptr);
                }
            }
        }
        else if (presetName.startsWith("Rooms_") || presetName.startsWith("Bass_") || presetName.startsWith("Drums_") ||
                 presetName.startsWith("Guitars_") || presetName.startsWith("Voces_") ||
                 presetName.startsWith("Fx_") || presetName.startsWith("Synth_") ||
                 presetName.startsWith("General_")) {
            // Es un factory preset con prefijo de categoría - cargar desde BinaryData
            juce::String resourceName = presetName + "_preset";

            // Buscar el recurso en BinaryData
            for (int i = 0; i < BinaryData::namedResourceListSize; ++i) {
                if (resourceName == BinaryData::namedResourceList[i]) {
                    // Cargar el preset desde BinaryData
                    int dataSize = 0;
                    const char* data = BinaryData::getNamedResource(BinaryData::namedResourceList[i], dataSize);

                    if (data != nullptr && dataSize > 0) {
                        // Parsear el XML desde memoria
                        juce::String xmlContent(data, dataSize);
                        juce::XmlDocument xmlDoc(xmlContent);
                        std::unique_ptr<juce::XmlElement> xmlState(xmlDoc.getDocumentElement());

                        if (xmlState != nullptr && xmlState->hasTagName(processor.apvts.state.getType())) {
                            auto stateTree = juce::ValueTree::fromXml(*xmlState);
                            processor.apvts.replaceState(stateTree);

                            // Restaurar estado de HOLD del goniometer si está presente
                            auto uiSettings = stateTree.getChildWithName("UISettings");
                            if (uiSettings.isValid()) {
                                bool hold = uiSettings.getProperty("goniometerHold", false);
                                setGoniometerHold(hold, true);
                            }

                            // SIEMPRE salir de bypass al cargar factory preset
                            parameterButtons.bypassButton.setToggleState(false, juce::sendNotification);
                        }
                    }
                    break;
                }
            }
        }
        else {
            // Es un user preset - cargar desde archivo
            juce::File presetFile = getPresetsFolder().getChildFile(presetName + ".preset");

            if (presetFile.existsAsFile()) {
                juce::XmlDocument xmlDoc(presetFile);
                std::unique_ptr<juce::XmlElement> xmlState(xmlDoc.getDocumentElement());

                if (xmlState != nullptr && xmlState->hasTagName(processor.apvts.state.getType())) {
                    auto stateTree = juce::ValueTree::fromXml(*xmlState);
                    processor.apvts.replaceState(stateTree);

                    // Restaurar estado de HOLD del goniometer si está presente
                    auto uiSettings = stateTree.getChildWithName("UISettings");
                    if (uiSettings.isValid()) {
                        bool hold = uiSettings.getProperty("goniometerHold", false);
                        setGoniometerHold(hold, true);
                    }

                    // SIEMPRE salir de bypass al cargar user preset
                    parameterButtons.bypassButton.setToggleState(false, juce::sendNotification);
                            // MAXIMIZER: No tiene m_SOLOSC
                }
            }
        }

        // Actualizar estado en processor
        processor.setLastPreset(selectedId);

        // Para mostrar en el menú, usar nombre limpio sin prefijos
        juce::String displayName = presetName;
        if (presetName.startsWith("Rooms_")) {
            displayName = "[F] " + presetName.substring(6).replace("_", " ");
        } else if (presetName.startsWith("Bass_")) {
            displayName = "[F] " + presetName.substring(5).replace("_", " ");
        } else if (presetName.startsWith("Drums_")) {
            displayName = "[F] " + presetName.substring(6).replace("_", " ");
        } else if (presetName.startsWith("Guitars_")) {
            displayName = "[F] " + presetName.substring(8).replace("_", " ");
        } else if (presetName.startsWith("Voces_")) {
            displayName = "[F] " + presetName.substring(6).replace("_", " ");
        } else if (presetName.startsWith("Fx_")) {
            displayName = "[F] " + presetName.substring(3).replace("_", " ");
        } else if (presetName.startsWith("Synth_")) {
            displayName = "[F] " + presetName.substring(6).replace("_", " ");
        } else if (presetName.startsWith("General_")) {
            displayName = "[F] " + presetName.substring(8).replace("_", " ");
        }

        processor.setPresetDisplayText(displayName);
        processor.setPresetTextItalic(false);
        presetArea.presetMenu.setTextItalic(false);

        // Actualizar sliders desde APVTS
        updateSliderValues();

        // IMPORTANTE: Actualizar también los botones desde APVTS (fix para presets Factory/User)
        updateButtonValues();

        // Actualizar la gráfica de transferencia con los valores actuales

        // Borrar el historial de undos DESPUÉS de haber establecido todos los valores.
        // Esto previene que los cambios de parámetros se registren en el historial de undo
        undoManager.clearUndoHistory();

        // Nota: el flag isLoadingPreset se resetea automáticamente por el destructor LoadingGuard
    };

    addAndMakeVisible(presetArea.presetMenu);

    // Inicializar menú de presets
    refreshPresetMenu();

    // Configurar el texto inicial del menú según el estado guardado
    auto savedText = processor.getPresetDisplayText();
    auto isItalic = processor.getPresetTextItalic();
    if (!savedText.isEmpty()) {
        presetArea.presetMenu.setTextWhenNothingSelected(savedText);
        presetArea.presetMenu.setTextItalic(isItalic);
    }
}

void JCBImagerAudioProcessorEditor::setupUtilityButtons()
{
    // Undo - estilo transparente
    utilityButtons.undoButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    utilityButtons.undoButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    utilityButtons.undoButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    utilityButtons.undoButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    utilityButtons.undoButton.addListener(this);
    addAndMakeVisible(utilityButtons.undoButton);

    // Redo - estilo transparente
    utilityButtons.redoButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    utilityButtons.redoButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    utilityButtons.redoButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    utilityButtons.redoButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    utilityButtons.redoButton.addListener(this);
    addAndMakeVisible(utilityButtons.redoButton);

    // Establecer el estado inicial de los botones de undo/redo (normalmente desactivados al inicio)
    utilityButtons.undoButton.setAlpha(0.3f);
    utilityButtons.undoButton.setEnabled(false);
    utilityButtons.redoButton.setAlpha(0.3f);
    utilityButtons.redoButton.setEnabled(false);

    // Reiniciar GUI - estilo transparente
    utilityButtons.resetGuiButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    utilityButtons.resetGuiButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    utilityButtons.resetGuiButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    utilityButtons.resetGuiButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    utilityButtons.resetGuiButton.addListener(this);
    addAndMakeVisible(utilityButtons.resetGuiButton);
    // Tooltip actualizado via getTooltipText("resetgui") en updateAllTooltips()

    // El botón de bypass se ha movido a parameterButtons

    // Ejecutar gráficos - botón normal (no toggle) para control manual completo
    utilityButtons.runGraphicsButton.setClickingTogglesState(true);
    utilityButtons.runGraphicsButton.setToggleState(false, juce::dontSendNotification);
    utilityButtons.runGraphicsButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    utilityButtons.runGraphicsButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    utilityButtons.runGraphicsButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    utilityButtons.runGraphicsButton.setButtonText("live");
    utilityButtons.runGraphicsButton.addListener(this);
    addAndMakeVisible(utilityButtons.runGraphicsButton);
    // Tooltip actualizado via getTooltipText("graphics") en updateAllTooltips()

    // Botón toggle de tooltip - estilo transparente
    utilityButtons.tooltipToggleButton.setClickingTogglesState(true);
    utilityButtons.tooltipToggleButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    utilityButtons.tooltipToggleButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    utilityButtons.tooltipToggleButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    utilityButtons.tooltipToggleButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    utilityButtons.tooltipToggleButton.setToggleState(true, juce::dontSendNotification); // ON por defecto
    utilityButtons.tooltipToggleButton.addListener(this);
    addAndMakeVisible(utilityButtons.tooltipToggleButton);
    // Tooltip actualizado via getTooltipText("tooltiptoggle") en updateAllTooltips()

    // Botón de idioma - estilo transparente
    utilityButtons.tooltipLangButton.setClickingTogglesState(false);  // No toggle, solo botón normal
    utilityButtons.tooltipLangButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    utilityButtons.tooltipLangButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    utilityButtons.tooltipLangButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    utilityButtons.tooltipLangButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    utilityButtons.tooltipLangButton.setButtonText("esp");  // Texto inicial para español
    utilityButtons.tooltipLangButton.addListener(this);
    addAndMakeVisible(utilityButtons.tooltipLangButton);
    // Tooltip actualizado via getTooltipText("tooltiplang") en updateAllTooltips()

    // Botón HQ - oversampling
    utilityButtons.hqButton.setClickingTogglesState(true);
    utilityButtons.hqButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    utilityButtons.hqButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    utilityButtons.hqButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.7f));
    utilityButtons.hqButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    utilityButtons.hqButton.addListener(this);
    addAndMakeVisible(utilityButtons.hqButton);
    utilityButtons.hqButton.setEnabled(false);  // TODO: Implementar

    // Dual Mono button
    utilityButtons.dualMonoButton.setClickingTogglesState(true);
    utilityButtons.dualMonoButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    utilityButtons.dualMonoButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    utilityButtons.dualMonoButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.7f));
    utilityButtons.dualMonoButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    utilityButtons.dualMonoButton.addListener(this);
    addAndMakeVisible(utilityButtons.dualMonoButton);
    utilityButtons.dualMonoButton.setEnabled(false);  // TODO: Implementar

    // Stereo Linked button (ALWAYS ON - plugin only works in stereo linked mode)
    utilityButtons.stereoLinkedButton.setClickingTogglesState(false);  // No toggle
    utilityButtons.stereoLinkedButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    utilityButtons.stereoLinkedButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    utilityButtons.stereoLinkedButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);  // Siempre texto blanco
    utilityButtons.stereoLinkedButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    utilityButtons.stereoLinkedButton.setToggleState(true, juce::dontSendNotification); // Siempre ON
    // No listener necesario ya que siempre está activo
    addAndMakeVisible(utilityButtons.stereoLinkedButton);
    // Tooltip actualizado via getTooltipText("link") en updateAllTooltips()
    utilityButtons.stereoLinkedButton.setEnabled(false);  // Disabled - can't be changed

    // Botón M/S
    utilityButtons.msButton.setClickingTogglesState(true);
    utilityButtons.msButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    utilityButtons.msButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    utilityButtons.msButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.7f));
    utilityButtons.msButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    utilityButtons.msButton.addListener(this);
    addAndMakeVisible(utilityButtons.msButton);
    utilityButtons.msButton.setEnabled(false);  // TODO: Implementar

    // A/B State button
    topButtons.abStateButton.setClickingTogglesState(false);  // No es toggle, es un indicador
    topButtons.abStateButton.setColour(juce::TextButton::buttonColourId, 
        processor.getIsStateA() ? juce::Colour(0xff9E35B0) : juce::Colour(0xff2196f3));  // Color según estado actual
    topButtons.abStateButton.setColour(juce::TextButton::buttonOnColourId, 
        processor.getIsStateA() ? juce::Colour(0xff9E35B0) : juce::Colour(0xff2196f3));  // Mismo color para evitar brillo
    topButtons.abStateButton.setColour(juce::TextButton::textColourOffId, juce::Colours::white);
    topButtons.abStateButton.setColour(juce::TextButton::textColourOnId, juce::Colours::white);
    topButtons.abStateButton.addListener(this);
    topButtons.abStateButton.setButtonText(processor.getIsStateA() ? "A" : "B");  // Texto según estado actual
    addAndMakeVisible(topButtons.abStateButton);
    topButtons.abStateButton.setEnabled(true);  // Now implemented!

    // Botón copiar A/B
    topButtons.abCopyButton.setClickingTogglesState(false);
    topButtons.abCopyButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    topButtons.abCopyButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textPrimary);
    topButtons.abCopyButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    topButtons.abCopyButton.addListener(this);
    topButtons.abCopyButton.setButtonText(processor.getIsStateA() ? "A-B" : "B-A");  // Texto según estado actual
    addAndMakeVisible(topButtons.abCopyButton);
    // Tooltip actualizado dinámicamente en updateAbButtonState()

    // MIDI Learn button
    utilityButtons.midiLearnButton.setClickingTogglesState(true);
    utilityButtons.midiLearnButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    utilityButtons.midiLearnButton.setColour(juce::TextButton::buttonOnColourId, juce::Colours::purple.withAlpha(0.3f));
    utilityButtons.midiLearnButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.7f));
    utilityButtons.midiLearnButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    utilityButtons.midiLearnButton.addListener(this);
    addAndMakeVisible(utilityButtons.midiLearnButton);
    utilityButtons.midiLearnButton.setEnabled(false);  // TODO: Implementar

    // Botón Diagram
    centerButtons.diagramButton.setClickingTogglesState(true);
    centerButtons.diagramButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    centerButtons.diagramButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    centerButtons.diagramButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.7f));
    centerButtons.diagramButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    centerButtons.diagramButton.addListener(this);
    addAndMakeVisible(centerButtons.diagramButton);

}

void JCBImagerAudioProcessorEditor::setupParameterButtons()
{

    // Botón BYPASS - movido desde utilityButtons
    parameterButtons.bypassButton.setClickingTogglesState(true);
    parameterButtons.bypassButton.setColour(juce::TextButton::buttonColourId, juce::Colours::transparentBlack);
    parameterButtons.bypassButton.setColour(juce::TextButton::buttonOnColourId, DarkTheme::accent.withAlpha(0.3f));
    parameterButtons.bypassButton.setColour(juce::TextButton::textColourOffId, DarkTheme::textSecondary.withAlpha(0.7f));
    parameterButtons.bypassButton.setColour(juce::TextButton::textColourOnId, DarkTheme::textPrimary);
    parameterButtons.bypassButton.addListener(this);
    addAndMakeVisible(parameterButtons.bypassButton);
    // Bypass interno (Gen) no está en APVTS → no crear attachment al host
    // El estado se sincroniza en updateButtonValues() y buttonClicked()
}

void JCBImagerAudioProcessorEditor::setupBackground()
{
    try {
        // Cargar imágenes de fondo con validación
        normalBackground = juce::ImageCache::getFromMemory(BinaryData::fondo_png, BinaryData::fondo_pngSize);
        bypassBackground = juce::ImageCache::getFromMemory(BinaryData::bypass_png, BinaryData::bypass_pngSize);
        // Diagrama temporalmente sin imagen de fondo
        diagramBackground = juce::Image();

        // Establecer background inicial solo si es válido
        if (normalBackground.isValid())
        {
            backgroundImage.setImage(normalBackground, juce::RectanglePlacement::stretchToFit);
            addAndMakeVisible(backgroundImage);
            backgroundImage.toBack();
        }
    }
    catch (const std::exception& e) {
        // En caso de error, continuar sin imagen de fondo
        DBG("Error loading background images: " << e.what());
    }
}

//==============================================================================
// MÉTODOS DE UPDATE Y REFRESH
//==============================================================================

void JCBImagerAudioProcessorEditor::updateButtonStates()
{
    // Función maestra que actualiza todos los estados de UI
    updateBasicButtonStates();
    updateSidechainComponentStates(); // legacy filters hidden; keep safe state
    /*
    // Actualizar estados de componentes de distorsión
    updateDistortionComponentStates();
    // Actualizar estados de componentes de bit crusher
    updateBitCrusherComponentStates();
    // Actualizar estados de componentes de downsample
    updateDownsampleComponentStates();
    // Actualizar estados de componentes de tone LPF
    updateToneLpfComponentStates();
    // Actualizar estados de componentes de tilt
    updateTiltComponentStates();
    */
    updateBackgroundState();
    updateMeterStates();

    // MEJORADO: Estado inicial aplicado
}

void JCBImagerAudioProcessorEditor::updateBasicButtonStates()
{
    // Obtener estados actuales
    const bool bypassActive = parameterButtons.bypassButton.getToggleState();

    // Actualizar estados visuales básicos
    isBypassed = bypassActive;
    bypassTextVisible = bypassActive;  // Siempre mostrar texto cuando bypass está activo
}

void JCBImagerAudioProcessorEditor::updateSidechainComponentStates()
{
    // Imager: HPF/LPF (Freq1/Freq2) siempre activos y con alpha completa
    sidechainControls.hpfSlider.setVisible(true);
    sidechainControls.lpfSlider.setVisible(true);
    sidechainControls.hpfSlider.setAlpha(1.0f);
    sidechainControls.lpfSlider.setAlpha(1.0f);
}

void JCBImagerAudioProcessorEditor::updateEqComponentStates()
{
    bool eqOn = false;
    if (auto* p = processor.apvts.getRawParameterValue("q_ONOFFEQ"))
        eqOn = p->load() > 0.5f;
    auto set = [&](juce::Component& c){ c.setEnabled(eqOn); c.setAlpha(eqOn ? 1.0f : 0.35f); };
    set(eqControls.lsfSlider); set(eqControls.pfSlider); set(eqControls.hsfSlider);
    set(eqControls.lsgSlider); set(eqControls.pgSlider); set(eqControls.hsgSlider);
    eqControls.eqOnButton.setButtonText(eqOn ? "ON" : "OFF");
}

void JCBImagerAudioProcessorEditor::updateCompComponentStates()
{
    bool compOn = false;
    if (auto* p = processor.apvts.getRawParameterValue("r_ONOFFCOMP"))
        compOn = p->load() > 0.5f;
    auto set = [&](juce::Component& c){ c.setEnabled(compOn); c.setAlpha(compOn ? 1.0f : 0.35f); };
    set(compControls.thdSlider);
    set(compControls.ratioSlider);
    set(compControls.atkSlider);
    set(compControls.relSlider);
    set(compControls.gainSlider);
    set(compControls.pumpButton);
    compControls.compOnButton.setButtonText(compOn ? "ON" : "OFF");

    // Política: cuando COMP está OFF, PUMP queda deshabilitado visualmente
    // pero su estado (ON/OFF) se conserva para restaurarlo al reactivar COMP.
}

void JCBImagerAudioProcessorEditor::setGoniometerHold(bool hold, bool updateButtonToggle)
{
    goniometerDisplay.setHoldEnabled(hold);
    spectrumAnalyzer.setHoldEnabled(hold);

    if (updateButtonToggle)
        utilityButtons.runGraphicsButton.setToggleState(hold, juce::dontSendNotification);

    utilityButtons.runGraphicsButton.setButtonText(hold ? "hold" : "live");
    utilityButtons.runGraphicsButton.setColour(juce::TextButton::buttonColourId,
                                              hold ? DarkTheme::accent.withAlpha(0.3f)
                                                   : juce::Colours::transparentBlack);
}

void JCBImagerAudioProcessorEditor::updateRightPanelVisibility()
{
    // Imager: ocultar completamente el panel derecho heredado (EQ/COMP) y sus tabs
    auto setEqVis = [&](bool v){ juce::ignoreUnused(v);
        eqControls.eqOnButton.setVisible(false);
        eqControls.lsfSlider.setVisible(false);
        eqControls.pfSlider.setVisible(false);
        eqControls.hsfSlider.setVisible(false);
        eqControls.lsgSlider.setVisible(false);
        eqControls.pgSlider.setVisible(false);
        eqControls.hsgSlider.setVisible(false);
    };
    auto setCompVis = [&](bool v){ juce::ignoreUnused(v);
        compControls.compOnButton.setVisible(false);
        compControls.thdSlider.setVisible(false);
        compControls.ratioSlider.setVisible(false);
        compControls.atkSlider.setVisible(false);
        compControls.relSlider.setVisible(false);
        compControls.gainSlider.setVisible(false);
        compControls.pumpButton.setVisible(false);
    };

    setEqVis(false);
    setCompVis(false);

    rightTabs.eqTab.setVisible(false);
    rightTabs.compTab.setVisible(false);
}


// void JCBImagerAudioProcessorEditor::updateDistortionComponentStates()
// {
//     // Obtener estado del botón distOnButton (p_DISTON)
//     const bool distortionActive = rightBottomKnobs.distOnButton.getToggleState();
//
//     // REFLECT slider always enabled for reverb
//     leftKnobs.reflectSlider.setEnabled(true);
//     leftKnobs.reflectSlider.setAlpha(1.0f);
//
//     // EVEN (DC) slider - activo solo cuando distorsión está ON
//     rightBottomKnobs.dcSlider.setEnabled(distortionActive);
//     rightBottomKnobs.dcSlider.setAlpha(distortionActive ? 1.0f : 0.5f);
//
//     // DRIVE slider - activo solo cuando distorsión está ON
//     rightBottomKnobs.driveSlider.setEnabled(distortionActive);
//     rightBottomKnobs.driveSlider.setAlpha(distortionActive ? 1.0f : 0.5f);
//
//     // CEIL slider - activo solo cuando distorsión está ON
//     leftKnobs.ceilingSlider.setEnabled(distortionActive);
//     leftKnobs.ceilingSlider.setAlpha(distortionActive ? 1.0f : 0.5f);
//
//     // TILT POS button (PRE/POST) - activo solo cuando distorsión está ON
//     rightTopControls.tiltPosButton.setEnabled(distortionActive);
//     rightTopControls.tiltPosButton.setAlpha(distortionActive ? 1.0f : 0.5f);
//
//     // Actualizar alpha del texto del botón tiltPos según estado de distorsión
//     // PRE y POST deben verse igual (no hay diferencia entre los dos estados)
//     rightTopControls.tiltPosButton.setColour(
//         juce::TextButton::textColourOffId,
//         juce::Colour(0xFFA6DAD5).withAlpha(distortionActive ? 1.0f : 0.5f)  // Verde agua pálido como tiltSlider
//     );
//     rightTopControls.tiltPosButton.setColour(
//         juce::TextButton::textColourOnId,
//         juce::Colour(0xFFA6DAD5).withAlpha(distortionActive ? 1.0f : 0.5f)  // Verde agua pálido como tiltSlider
//     );
//
//     // Actualizar alpha del texto del botón distOn según estado
//     rightBottomKnobs.distOnButton.setColour(
//         juce::TextButton::textColourOffId,
//         DarkTheme::textSecondary.withAlpha(0.7f)
//     );
//     rightBottomKnobs.distOnButton.setColour(
//         juce::TextButton::textColourOnId,
//         juce::Colour(0xFFFEB2B2)  // Rosa pálido como los sliders de distorsión
//     );
//
//     // Actualizar estado de la curva de distorsión
//     // distortionCurveDisplay.setDistortionEnabled(distortionActive);
// }

// void JCBImagerAudioProcessorEditor::updateBitCrusherComponentStates()
// {
//     // Obtener estado del botón BIT CRUSHER (h_BITSON)
//     const bool bitCrusherActive = rightBottomKnobs.bitButton.getToggleState();
//
//     // BIT slider - siempre interactivo pero con alpha reducido cuando BIT CRUSHER está OFF
//     rightTopControls.bitsSlider.setEnabled(true);  // Siempre habilitado para pre-configuración
//     rightTopControls.bitsSlider.setAlpha(bitCrusherActive ? 1.0f : 0.5f);
//
//     // Actualizar alpha del texto del botón BIT CRUSHER según estado
//     rightBottomKnobs.bitButton.setColour(
//         juce::TextButton::textColourOffId,
//         juce::Colour(0xFFB2FFB3).withAlpha(bitCrusherActive ? 0.7f : 0.4f)  // Verde pálido
//     );
//     rightBottomKnobs.bitButton.setColour(
//         juce::TextButton::textColourOnId,
//         juce::Colour(0xFFB2FFB3).withAlpha(bitCrusherActive ? 1.0f : 0.5f)  // Verde pálido
//     );
// }

// void JCBImagerAudioProcessorEditor::updateDownsampleComponentStates()
// {
//     // Obtener estado del botón DOWNSAMPLE (n_DOWNSAMPLEON)
//     const bool downsampleActive = rightTopControls.downsampleButton.getToggleState();
//
//     // DECI slider - siempre interactivo pero con alpha reducido cuando DOWNSAMPLE está OFF
//     rightTopControls.downsampleSlider.setEnabled(true);  // Siempre habilitado para pre-configuración
//     rightTopControls.downsampleSlider.setAlpha(downsampleActive ? 1.0f : 0.5f);
//
//     // Actualizar alpha del texto del botón DOWNSAMPLE según estado
//     rightTopControls.downsampleButton.setColour(
//         juce::TextButton::textColourOffId,
//         juce::Colour(0xFFD9B2FF).withAlpha(downsampleActive ? 0.7f : 0.4f)  // Púrpura pálido
//     );
//     rightTopControls.downsampleButton.setColour(
//         juce::TextButton::textColourOnId,
//         juce::Colour(0xFFD9B2FF).withAlpha(downsampleActive ? 1.0f : 0.5f)  // Púrpura pálido
//     );
// }

// void JCBImagerAudioProcessorEditor::updateTiltComponentStates()
// {
//     // Obtener estado del botón TILT (s_TILTON)
//     const bool tiltActive = rightTopControls.tiltOnButton.getToggleState();
//
//     // TILT slider - siempre interactivo pero con alpha reducido cuando TILT está OFF
//     rightTopControls.tiltSlider.setEnabled(true);  // Siempre habilitado para pre-configuración
//     rightTopControls.tiltSlider.setAlpha(tiltActive ? 1.0f : 0.5f);
//
//     // TILT POS button - siempre interactivo pero con alpha reducido cuando TILT está OFF
//     rightTopControls.tiltPosButton.setEnabled(true);  // Siempre habilitado para pre-configuración
//     rightTopControls.tiltPosButton.setAlpha(tiltActive ? 1.0f : 0.5f);
//     rightTopControls.tiltPosButton.setColour(
//         juce::TextButton::textColourOffId,
//         juce::Colour(0xFFA6DAD5).withAlpha(tiltActive ? 1.0f : 0.5f)  // Verde agua pálido
//     );
//     rightTopControls.tiltPosButton.setColour(
//         juce::TextButton::textColourOnId,
//         juce::Colour(0xFFA6DAD5).withAlpha(tiltActive ? 1.0f : 0.5f)  // Verde agua pálido
//     );
//
//     // Actualizar alpha del texto del botón TILT según estado
//     rightTopControls.tiltOnButton.setColour(
//         juce::TextButton::textColourOffId,
//         juce::Colour(0xFFA6DAD5).withAlpha(tiltActive ? 0.7f : 0.3f)  // Verde agua pálido
//     );
//     rightTopControls.tiltOnButton.setColour(
//         juce::TextButton::textColourOnId,
//         juce::Colour(0xFFA6DAD5).withAlpha(tiltActive ? 1.0f : 0.4f)  // Verde agua pálido
//     );
// }

// void JCBImagerAudioProcessorEditor::updateToneLpfComponentStates()
// {
//     // Obtener estado del botón TONE LPF (q_TONEON)
//     const bool toneLpfActive = leftBottomKnobs.toneLpfButton.getToggleState();
//
//     // TONE FREQ slider - siempre interactivo pero con alpha reducido cuando TONE LPF está OFF
//     leftBottomKnobs.toneFreqSlider.setEnabled(true);  // Siempre habilitado para pre-configuración
//     leftBottomKnobs.toneFreqSlider.setAlpha(toneLpfActive ? 1.0f : 0.5f);
//
//     // TONE Q slider - siempre interactivo pero con alpha reducido cuando TONE LPF está OFF
//     leftBottomKnobs.toneQSlider.setEnabled(true);  // Siempre habilitado para pre-configuración
//     leftBottomKnobs.toneQSlider.setAlpha(toneLpfActive ? 1.0f : 0.5f);
//
//     // TONE POS button - siempre interactivo pero con alpha reducido cuando TONE LPF está OFF
//     leftBottomKnobs.tonePosButton.setEnabled(true);  // Siempre habilitado para pre-configuración
//     leftBottomKnobs.tonePosButton.setAlpha(toneLpfActive ? 1.0f : 0.5f);
//     leftBottomKnobs.tonePosButton.setColour(
//         juce::TextButton::textColourOffId,
//         juce::Colour(0xFF6EB8F6).withAlpha(toneLpfActive ? 1.0f : 0.5f)  // Azul claro TONE
//     );
//     leftBottomKnobs.tonePosButton.setColour(
//         juce::TextButton::textColourOnId,
//         juce::Colour(0xFF6EB8F6).withAlpha(toneLpfActive ? 1.0f : 0.5f)  // Azul claro TONE
//     );
//
//     // Actualizar alpha del texto del botón TONE LPF según estado
//     leftBottomKnobs.toneLpfButton.setColour(
//         juce::TextButton::textColourOffId,
//         juce::Colour(0xFF6EB8F6).withAlpha(toneLpfActive ? 0.7f : 0.3f)  // Azul claro TONE
//     );
//     leftBottomKnobs.toneLpfButton.setColour(
//         juce::TextButton::textColourOnId,
//         juce::Colour(0xFF6EB8F6).withAlpha(toneLpfActive ? 1.0f : 0.4f)  // Azul claro TONE
//     );
// }

void JCBImagerAudioProcessorEditor::updateBackgroundState()
{
    // Obtener estados actuales
    const bool bypassActive = parameterButtons.bypassButton.getToggleState();

    // Actualizar fondo según prioridad: bypass > normal
    if (bypassActive) {
        backgroundImage.setImage(bypassBackground, juce::RectanglePlacement::stretchToFit);
    }
    else {
        backgroundImage.setImage(normalBackground, juce::RectanglePlacement::stretchToFit);
    }
}

void JCBImagerAudioProcessorEditor::updateFilterButtonText()
{
    /*
    // Actualizar texto del botón HPF Order
    if (auto* hpfParam = processor.apvts.getParameter("j_HPFORDER"))
    {
        float normalized = hpfParam->getValue();
        float denormalized = hpfParam->convertFrom0to1(normalized);
        int value = static_cast<int>(denormalized + 0.5f);

        switch (value)
        {
            case 0: sidechainControls.hpfOrderButton.setButtonText("12"); break;
            case 1: sidechainControls.hpfOrderButton.setButtonText("24"); break;
            default: sidechainControls.hpfOrderButton.setButtonText("12"); break;
        }
    }
    */

    /*
    // Actualizar texto del botón LPF Order
    if (auto* lpfParam = processor.apvts.getParameter("k_LPFORDER"))
    {
        float normalized = lpfParam->getValue();
        float denormalized = lpfParam->convertFrom0to1(normalized);
        int value = static_cast<int>(denormalized + 0.5f);

        switch (value)
        {
            case 0: sidechainControls.lpfOrderButton.setButtonText("12"); break;
            case 1: sidechainControls.lpfOrderButton.setButtonText("24"); break;
            default: sidechainControls.lpfOrderButton.setButtonText("12"); break;
        }
    }
    */
}

void JCBImagerAudioProcessorEditor::updateMeterStates()
{
    // Obtener estados actuales
    const bool bypassActive = parameterButtons.bypassButton.getToggleState();
    // MAXIMIZER: No sidechain controls - commenting out
    // const bool soloScActive = sidechainControls.soloScButton.getToggleState();
    const bool soloScActive = false;  // No sidechain in this processor

    // Actualizar colores de medidores
    // Si bypass está activo, no cambiar colores (mantener normales)
    // Si solo SC está activo, usar colores rojos
    bool soloMode = soloScActive && !bypassActive;
    // scMeterL.setSoloScMode(soloMode);
    // scMeterR.setSoloScMode(soloMode);

    inputMeterL.setSoloScMode(soloMode);
    inputMeterR.setSoloScMode(soloMode);
    outputMeterL.setSoloScMode(soloMode);
    outputMeterR.setSoloScMode(soloMode);
    // scMeterL.setSoloScMode(soloMode);
    // scMeterR.setSoloScMode(soloMode);

    // Ocultar gain reduction meter cuando SOLO SC está activo (no hay compresión activa)
    // NUEVO: También ocultar cuando BYPASS está activo

    // Actualizar gradiente de salida para modo bypass
    outputMeterL.setBypassMode(bypassActive);
    outputMeterR.setBypassMode(bypassActive);

    // CORRECCIÓN: Asegurar sincronización estado BYPASS al reabrir plugin
    // Esto resuelve el problema de la función de transferencia que reaparece incorrectamente
    // distortionCurveDisplay.setBypassMode(bypassActive);
}

void JCBImagerAudioProcessorEditor::updateMeters()
{
    // CORRECCIÓN CRÍTICA: Cachear estados de visibilidad para evitar llamadas repetidas a setVisible
    static bool lastSoloScActive = false;
    static bool lastExtKeyActive = false;

    // Verificar si SOLO SC está activo
    // MAXIMIZER: No sidechain controls - commenting out
    // const bool soloScActive = sidechainControls.soloScButton.getToggleState();
    // const bool extKeyActive = sidechainControls.keyButton.getToggleState();
    const bool soloScActive = false;  // No sidechain
    const bool extKeyActive = false;  // No external key

    // Solo actualizar visibilidad cuando el estado realmente cambia
    if (soloScActive != lastSoloScActive || extKeyActive != lastExtKeyActive) {
        if (soloScActive) {
            // SOLO SC activo - mostrar meters apropiados basados en EXT KEY
            if (extKeyActive) {
                // Ocultar medidores principales de entrada
                inputMeterL.setVisible(false);
                inputMeterR.setVisible(false);
                            // Hacer visibles los medidores de sidechain
                // scMeterL.setVisible(true);
                // scMeterR.setVisible(true);
            } else {
                // Mostrar medidores principales de entrada en modo SOLO SC (sidechain interno)
                inputMeterL.setVisible(true);
                inputMeterR.setVisible(true);
                            // scMeterL.setVisible(true);
                // scMeterR.setVisible(true);
            }
        } else {
            // Modo normal - mostrar todos los medidores normalmente
            inputMeterL.setVisible(true);
            inputMeterR.setVisible(true);
                    // scMeterL.setVisible(true);
            // scMeterR.setVisible(true);
        }

        lastSoloScActive = soloScActive;
        lastExtKeyActive = extKeyActive;
    }

    // Actualizar medidores con control centralizado a 60 Hz
    // Llamar a updateLevel() de cada medidor para procesar valores y animaciones
    if (inputMeterL.isVisible()) {
        inputMeterL.updateLevel();
        inputMeterR.updateLevel();
        inputMeterL.repaint();
        inputMeterR.repaint();
    }

    /*
    if (scMeterL.isVisible()) {
        scMeterL.updateLevel();
        scMeterR.updateLevel();
        scMeterL.repaint();
        scMeterR.repaint();
    }
    */

    /*
    // Siempre actualizar detección de clip de sidechain
    scMeterL.setClipDetected(processor.getSidechainClipDetected(0));
    scMeterR.setClipDetected(processor.getSidechainClipDetected(1));
    */

    // Siempre actualizar medidores de salida y reducción de ganancia

    outputMeterL.updateLevel();
    outputMeterR.updateLevel();
    outputMeterL.repaint();
    outputMeterR.repaint();
}

void JCBImagerAudioProcessorEditor::updateSliderValues()
{
    // Actualizar todos los sliders con los valores actuales del APVTS
    // Esto soluciona el problema de que los valores no se actualizan al cargar sesión
    // FIXED: Los comentarios anteriores eran incorrectos - todos los sliders usan CustomSliderAttachment

    // COMENTADO: Actualización de sliders de distorsión que no existen
    /*
    // Left top knobs - Todos usan CustomSliderAttachment
    if (auto* param = processor.apvts.getRawParameterValue("a_DRYWET"))
        leftBottomKnobs.drywetSlider.setValue(param->load(), juce::dontSendNotification);

    if (auto* param = processor.apvts.getRawParameterValue("e_CEILING"))
        leftKnobs.ceilingSlider.setValue(param->load(), juce::dontSendNotification);
    */

    // if (auto* param = processor.apvts.getRawParameterValue("c_RATIO"))
    //     leftKnobs.ratioSlider.setValue(param->load(), juce::dontSendNotification);


    // if (auto* param = processor.apvts.getRawParameterValue("q_KNEE"))
    //     leftKnobs.kneeSlider.setValue(param->load(), juce::dontSendNotification);


    // n_LOOKAHEAD no existe en este procesador



    // Right top controls

    // MAXIMIZER: g_REACT no existe - parámetro eliminado según CONTEXTO.txt
    // if (auto* param = processor.apvts.getRawParameterValue("g_REACT"))
    //     rightTopControls.reactSlider.setValue(param->load(), juce::dontSendNotification);

    // COMENTADO: Más sliders de distorsión
    /*
    // Right bottom knobs - Todos usan CustomSliderAttachment
    if (auto* param = processor.apvts.getRawParameterValue("b_DRIVE"))
        rightBottomKnobs.driveSlider.setValue(param->load(), juce::dontSendNotification);

    if (auto* param = processor.apvts.getRawParameterValue("c_REFLECT"))
        leftKnobs.reflectSlider.setValue(param->load(), juce::dontSendNotification);
    */

    // COMENTADO: Más controles de distorsión inexistentes
    /*
    if (auto* param = processor.apvts.getRawParameterValue("i_TILT"))
        rightTopControls.tiltSlider.setValue(param->load(), juce::dontSendNotification);


    if (auto* param = processor.apvts.getRawParameterValue("c_DC"))
        rightBottomKnobs.dcSlider.setValue(param->load(), juce::dontSendNotification);

    // MAXIMIZER: z_SMOOTH no existe - parámetro eliminado según CONTEXTO.txt
    // if (auto* param = processor.apvts.getRawParameterValue("z_SMOOTH"))
    //     rightTopControls.smoothSlider.setValue(param->load(), juce::dontSendNotification);

    // Controles de sidechain - Todos usan CustomSliderAttachment
    if (auto* param = processor.apvts.getRawParameterValue("j_HPF"))
        sidechainControls.hpfSlider.setValue(param->load(), juce::dontSendNotification);

    if (auto* param = processor.apvts.getRawParameterValue("k_LPF"))
        sidechainControls.lpfSlider.setValue(param->load(), juce::dontSendNotification);

    if (auto* param = processor.apvts.getRawParameterValue("o_BAND"))
        sidechainControls.bandSlider.setValue(param->load(), juce::dontSendNotification);
    */


    // COMENTADO: Sliders de trim y makeup que no existen
    /*
    // Slider de trims (both linked to the same parameter)
    if (auto* param = processor.apvts.getRawParameterValue("k_INPUT")) {
        float trimValue = param->load();
        trimSlider.setValue(trimValue, juce::dontSendNotification);
    }

    // make-up se tomará de w_MAKEUP en el nuevo layout
    */

    /*
    // Slider de trim de sidechain
    if (auto* param = processor.apvts.getRawParameterValue("y_SCTRIM")) {
        float scTrimValue = param->load();
        scTrimSlider.setValue(scTrimValue, juce::dontSendNotification);
    }
    */

    // NUEVO: Actualizar alpha del REL slider basado en estado inicial de AUTOREL
}

void JCBImagerAudioProcessorEditor::updateButtonValues()
{
    // Actualizar todos los botones con los valores actuales del APVTS
    // Esta función es crucial para que los presets Factory/User actualicen correctamente los botones

    // Bypass button (interno Gen: i_BYPASS)
    {
        bool toggleState = false;
        if (auto* st = processor.getPluginState())
        {
            for (int i = 0; i < JCBImager::num_params(); ++i)
            {
                if (juce::String(JCBImager::getparametername(st, i)) == "i_BYPASS")
                {
                    t_param v = 0;
                    JCBImager::getparameter(st, i, &v);
                    toggleState = (v >= 0.5f);
                    break;
                }
            }
        }
        parameterButtons.bypassButton.setToggleState(toggleState, juce::dontSendNotification);
    }
    updateModeButtonLabels();
    // El resto de controles pertenece al plugin de origen (Distortion) y no existen aquí.
    // Evitar referencias a controles no declarados hasta que la UI de reverb esté completa.
    return;
}

void JCBImagerAudioProcessorEditor::resetGuiSize()
{
    // Ciclar al siguiente estado: Current -> Maximum -> Minimum -> Current
    switch (currentSizeState) {
        case GuiSizeState::Current:
            // Current -> Maximum
            processor.setSavedSize({MAX_WIDTH, MAX_HEIGHT});
            setSize(MAX_WIDTH, MAX_HEIGHT);
            currentSizeState = GuiSizeState::Maximum;
            break;

        case GuiSizeState::Maximum:
            // Maximum -> Minimum
            processor.setSavedSize({MIN_WIDTH, MIN_HEIGHT});
            setSize(MIN_WIDTH, MIN_HEIGHT);
            currentSizeState = GuiSizeState::Minimum;
            break;

        case GuiSizeState::Minimum:
            // Minimum -> Current (back to default)
            processor.setSavedSize({DEFAULT_WIDTH, DEFAULT_HEIGHT});
            setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
            currentSizeState = GuiSizeState::Current;
            break;
    }

    // Forzar repaint para asegurar que se actualice correctamente
    repaint();
}

//==============================================================================
// GESTIÓN DE PRESETS
//==============================================================================
juce::File JCBImagerAudioProcessorEditor::getPresetsFolder()
{
    juce::File folder = juce::File::getSpecialLocation(juce::File::SpecialLocationType::userApplicationDataDirectory)
        .getChildFile("Audio")
        .getChildFile("Presets")
        .getChildFile("Coeval")
        .getChildFile("JCBImager");

    if (!folder.isDirectory() && !folder.existsAsFile()) {
        folder.createDirectory();
    }

    return folder;
}

juce::Array<juce::File> JCBImagerAudioProcessorEditor::populatePresetFolder()
{
    return getPresetsFolder().findChildFiles(2, false, "*.preset");
}

void JCBImagerAudioProcessorEditor::refreshPresetMenu()
{
    presetArea.presetMenu.clear();
    presetIdToNameMap.clear();  // Limpiar mapeo anterior

    // Añadir DEFAULT como primer preset siempre
    presetArea.presetMenu.addItem("DEFAULT", 1);
    presetIdToNameMap[1] = "DEFAULT";

    // Añadir separador
    presetArea.presetMenu.addItem("---", 2);

    // Organizar factory presets por categoría
    std::map<juce::String, juce::StringArray> categorizedPresets;
    std::map<juce::String, juce::StringArray> categorizedFullNames;  // Nombres completos con prefijos
    int nextId = 100;

    // Procesar factory presets desde BinaryData
    for (int i = 0; i < BinaryData::namedResourceListSize; ++i)
    {
        juce::String resourceName(BinaryData::namedResourceList[i]);

        // Buscar archivos que terminen en "_preset"
        if (resourceName.endsWith("_preset"))
        {
            juce::String cleanName = resourceName.replace("_preset", "");

            // Detectar categoría del prefijo
            juce::String category = "General";
            juce::String presetName = cleanName;

            if (cleanName.startsWith("Bass_"))
            {
                category = "Bass";
                presetName = cleanName.substring(5).replace("_", " ");
            }
            else if (cleanName.startsWith("Drums_"))
            {
                category = "Drums";
                presetName = cleanName.substring(6).replace("_", " ");
            }
            else if (cleanName.startsWith("Rooms_"))
            {
                category = "Rooms";
                presetName = cleanName.substring(6).replace("_", " ");
            }
            else if (cleanName.startsWith("Guitars_"))
            {
                category = "Guitars";
                presetName = cleanName.substring(8).replace("_", " ");
            }
            else if (cleanName.startsWith("Voces_"))
            {
                category = "Voces";
                presetName = cleanName.substring(6).replace("_", " ");
            }
            else if (cleanName.startsWith("Fx_"))
            {
                category = "Fx";
                presetName = cleanName.substring(3).replace("_", " ");
            }
            else if (cleanName.startsWith("Synth_"))
            {
                category = "Synth";
                presetName = cleanName.substring(6).replace("_", " ");
            }
            else if (cleanName.startsWith("General_"))
            {
                category = "General";
                presetName = cleanName.substring(8).replace("_", " ");
            }

            categorizedPresets[category].add("[F] " + presetName);
            categorizedFullNames[category].add(cleanName);  // Guardar nombre completo con prefijo
        }
    }

    // Añadir categorías al menú
    juce::StringArray categoryOrder = {"Rooms", "Bass", "Drums", "Fx", "Guitars"};

    for (const auto& category : categoryOrder)
    {
        if (categorizedPresets.find(category) != categorizedPresets.end())
        {
            auto& presets = categorizedPresets[category];
            auto& fullNames = categorizedFullNames[category];
            presets.sort(true);
            fullNames.sort(true);

            // Añadir categoría con sus subitems
            presetArea.presetMenu.addCategoryItem(category, presets, nextId);

            // Mapear IDs a nombres de presets
            for (int j = 0; j < presets.size(); ++j)
            {
                int presetId = nextId + j + 1;  // +1 porque el ID de la categoría es nextId
                presetIdToNameMap[presetId] = fullNames[j];  // Usar nombre completo con prefijo de categoría para BinaryData
            }

            nextId += static_cast<int>(presets.size()) + 1;
        }
    }

    // Añadir separador
    presetArea.presetMenu.addItem("---", nextId++);

    // Añadir user presets
    juce::StringArray userPresets;
    for (int i = 0; i < getUpdatedNumPresets(); i++) {
        userPresets.add(populatePresetFolder()[i].getFileNameWithoutExtension());
    }

    userPresets.sort(true);
    for (const auto& preset : userPresets)
    {
        presetArea.presetMenu.addItem(preset, nextId);
        presetIdToNameMap[nextId] = preset;  // Mapear user presets también
        nextId++;
    }

    // Restaurar selección previa si existe
    if (processor.getLastPreset() > 0) {
        presetArea.presetMenu.setSelectedId(processor.getLastPreset());
    }
}

void JCBImagerAudioProcessorEditor::savePresetFile()
{
    // Obtener estado del menú de presets y del processor
    juce::String currentText = presetArea.presetMenu.getText();
    juce::String processorText = processor.getPresetDisplayText();

    // Si no hay texto en el menú, usar el texto del processor
    if (currentText.isEmpty() && !processorText.isEmpty()) {
        currentText = processorText;
    }

    // Extraer el nombre del preset sin asterisco
    juce::String currentPresetName = currentText.endsWith("*") ?
        currentText.dropLastCharacters(1).trimEnd() : currentText;

    // Si no hay preset o es DEFAULT, ir a Save As
    if (currentPresetName.isEmpty() || currentPresetName == "DEFAULT") {
        saveAsPresetFile();
        return;
    }

    // Verificar si es un factory preset
    bool isFactoryPreset = currentPresetName.startsWith("[F] ");
    if (isFactoryPreset) {
        // Quitar el prefijo [F] para mostrar el nombre limpio
        juce::String cleanName = currentPresetName.substring(4);
        showCustomAlertDialog(JUCE_UTF8("Cannot overwrite"),
                            JUCE_UTF8("Factory Presets are read-only.\nUse 'Save As' to create a copy."));
        return;
    }

    // Si hay un preset cargado (modificado o no), ofrecer opciones
    // Mostrar diálogo si hay un preset cargado (modificado O no modificado)
    if (!currentPresetName.isEmpty()) {
        overwritePresetDialog = std::make_unique<CustomThreeButtonDialog>(
            "Overwrite \"" + currentPresetName + "\"",
            "",  // No mensaje adicional, el título es suficiente
            "Overwrite",
            "Save As",
            "Cancel"
        );

        overwritePresetDialog->onDialogClosed = [this, currentPresetName](bool wasAccepted) {
            if (wasAccepted) {
                int result = overwritePresetDialog->getSelectedButton();
                if (result == 1) { // Overwrite
                // Guardar directamente en el archivo existente
                auto presetFile = getPresetsFolder().getChildFile(currentPresetName + ".preset");
                auto state = processor.apvts.copyState();

                // Añadir estado de hold del goniometer
                auto uiSettings = state.getOrCreateChildWithName("UISettings", nullptr);
                uiSettings.setProperty("goniometerHold", goniometerDisplay.isHoldEnabled(), nullptr);

                std::unique_ptr<juce::XmlElement> xml(state.createXml());

                if (xml != nullptr) {
                    xml->writeTo(presetFile);

                    // Actualizar menú primero
                    refreshPresetMenu();

                    // No seleccionar el preset, solo mostrar su nombre
                    // Esto evita problemas con handleParameterChange
                    presetArea.presetMenu.setSelectedId(0);
                    presetArea.presetMenu.setTextWhenNothingSelected(currentPresetName);
                    presetArea.presetMenu.setTextItalic(false);

                    // Actualizar estado en el processor
                    processor.setPresetDisplayText(currentPresetName);
                    processor.setPresetTextItalic(false);
                    processor.setLastPreset(0);
                }
                } else if (result == 2) { // Guardar como...
                    saveAsPresetFile();
                }
                // result == 3 is Cancel, do nothing
            }

            // Limpiar el diálogo después de usarlo
            overwritePresetDialog.reset();
        };

        addChildComponent(overwritePresetDialog.get());
        overwritePresetDialog->showDialog();
    } else {
        // No hay preset cargado, ir directamente a "Save As..."
        saveAsPresetFile();
    }
}

void JCBImagerAudioProcessorEditor::saveAsPresetFile()
{
    // Crear y mostrar el diálogo personalizado
    savePresetDialog = std::make_unique<SavePresetDialog>("");
    savePresetDialog->onDialogClosed = [this](bool shouldSave) {
        if (shouldSave) {
            juce::String presetName = savePresetDialog->getPresetName();

            // No permitir usar el nombre DEFAULT
            if (presetName.toUpperCase() == "DEFAULT") {
                showCustomAlertDialog("Error",
                                    "Cannot use the name DEFAULT for a preset.");
                return;
            }

            // Verificar si el nombre coincide con algún factory preset
            for (const auto& factoryName : factoryPresetNames) {
                if (presetName.compareIgnoreCase(factoryName) == 0) {
                    showCustomAlertDialog(JUCE_UTF8("Reserved name"),
                                        JUCE_UTF8("Name reserved for Factory Preset.\nPlease choose another name."));
                    return;
                }
            }

            // Crear archivo con el nombre del preset
            juce::File presetFile = getPresetsFolder().getChildFile(presetName + ".preset");

            // Si el archivo ya existe, preguntar si sobrescribir
            if (presetFile.existsAsFile()) {
                showCustomConfirmDialog(JUCE_UTF8("Preset already exists"),
                                      JUCE_UTF8("Do you want to overwrite the existing preset?"),
                                      [this, presetFile, presetName](bool shouldOverwrite) {
                    if (shouldOverwrite) {
                        // Guardar el preset
                        auto state = processor.apvts.copyState();

                        // Añadir estado de hold del goniometer
                        auto uiSettings = state.getOrCreateChildWithName("UISettings", nullptr);
                        uiSettings.setProperty("goniometerHold", goniometerDisplay.isHoldEnabled(), nullptr);

                        std::unique_ptr<juce::XmlElement> xml(state.createXml());

                        if (xml != nullptr) {
                            xml->writeTo(presetFile);

                            // Actualizar el menú
                            refreshPresetMenu();

                            // No seleccionar el preset, solo mostrar su nombre
                            // Esto evita problemas con handleParameterChange
                            presetArea.presetMenu.setSelectedId(0);
                            presetArea.presetMenu.setTextWhenNothingSelected(presetName);
                            presetArea.presetMenu.setTextItalic(false);

                            // Actualizar estado en el processor
                            processor.setPresetDisplayText(presetName);
                            processor.setPresetTextItalic(false);
                            processor.setLastPreset(0);
                        }
                    }
                });
            } else {
                // Guardar directamente si no existe
                auto state = processor.apvts.copyState();

                // Añadir estado de hold del goniometer
                auto uiSettings = state.getOrCreateChildWithName("UISettings", nullptr);
                uiSettings.setProperty("goniometerHold", goniometerDisplay.isHoldEnabled(), nullptr);

                std::unique_ptr<juce::XmlElement> xml(state.createXml());

                if (xml != nullptr) {
                    xml->writeTo(presetFile);

                    // Actualizar el menú
                    refreshPresetMenu();

                    // No seleccionar el preset, solo mostrar su nombre
                    // Esto evita problemas con handleParameterChange
                    presetArea.presetMenu.setSelectedId(0);
                    presetArea.presetMenu.setTextWhenNothingSelected(presetName);
                    presetArea.presetMenu.setTextItalic(false);

                    // Actualizar estado en el processor
                    processor.setPresetDisplayText(presetName);
                    processor.setPresetTextItalic(false);
                    processor.setLastPreset(0);
                }
            }
        }

        // Limpiar el diálogo
        savePresetDialog.reset();
    };

    addChildComponent(savePresetDialog.get());
    savePresetDialog->showDialog();
}

void JCBImagerAudioProcessorEditor::deletePresetFile()
{
    int selectedId = presetArea.presetMenu.getSelectedId();
    juce::String presetName;

    if (selectedId > 0) {
        // Hay un preset seleccionado en el menú
        // Usar el mapeo que ya tiene el nombre correcto con "[F] " para factory presets
        if (presetIdToNameMap.find(selectedId) != presetIdToNameMap.end()) {
            presetName = presetIdToNameMap[selectedId];
        } else {
            presetName = presetArea.presetMenu.getItemText(selectedId - 1);
        }
    } else {
        // No hay selección, verificar si hay un preset modificado
        juce::String displayText = presetArea.presetMenu.getTextWhenNothingSelected();
        if (displayText.isEmpty()) {
            displayText = processor.getPresetDisplayText();
        }

        if (displayText.isEmpty()) {
            showCustomAlertDialog(JUCE_UTF8("Error"),
                                JUCE_UTF8("Ningún preset seleccionado."));
            return;
        }

        // Quitar asterisco si lo tiene
        presetName = displayText.endsWith("*") ?
            displayText.dropLastCharacters(1).trimEnd() : displayText;
    }

    // No permitir borrar DEFAULT ni factory presets
    if (presetName == "DEFAULT" || presetName.startsWith("[F] ")) {
        juce::String errorMsg = presetName == "DEFAULT" ?
            JUCE_UTF8("The DEFAULT preset cannot be deleted.") :
            JUCE_UTF8("Factory presets cannot be deleted.");
        showCustomAlertDialog(JUCE_UTF8("Error"), errorMsg);
        return;
    }

    showCustomConfirmDialog(JUCE_UTF8("Delete Preset"),
                            JUCE_UTF8("The preset \"") + presetName + JUCE_UTF8("\" will be moved to trash."),
                            [this, presetName](bool confirmed) {
        if (confirmed) {
            juce::File presetFile = getPresetsFolder().getChildFile(presetName + ".preset");

            if (presetFile.existsAsFile()) {
                presetFile.moveToTrash();

                // Actualizar el menú
                refreshPresetMenu();

                // Dejar el menú sin selección y sin texto
                presetArea.presetMenu.setSelectedId(0);
                presetArea.presetMenu.setTextWhenNothingSelected("");
                presetArea.presetMenu.setTextItalic(false);
                processor.setPresetDisplayText("");
                processor.setPresetTextItalic(false);
                processor.setLastPreset(0);

                // NO cargar DEFAULT - dejar los parámetros como están
            }
        }
    });
}

void JCBImagerAudioProcessorEditor::selectNextPreset()
{
    // Obtener todos los IDs seleccionables (excluyendo separadores y categorías)
    auto selectableIds = presetArea.presetMenu.getAllSelectableIds();

    if (selectableIds.empty()) return;

    int currentId = presetArea.presetMenu.getSelectedId();

    // Encontrar el índice actual en la lista de IDs seleccionables
    auto currentIt = std::find(selectableIds.begin(), selectableIds.end(), currentId);

    int nextId;
    if (currentIt == selectableIds.end() || currentIt == selectableIds.end() - 1) {
        // Si no se encuentra o es el último, ir al primero
        nextId = selectableIds.front();
    } else {
        // Ir al siguiente
        nextId = *(++currentIt);
    }

    presetArea.presetMenu.setSelectedId(nextId);

    // Trigger onChange para cargar el preset
    if (presetArea.presetMenu.onChange) {
        presetArea.presetMenu.onChange();
    }
}

void JCBImagerAudioProcessorEditor::selectPreviousPreset()
{
    // Obtener todos los IDs seleccionables (excluyendo separadores y categorías)
    auto selectableIds = presetArea.presetMenu.getAllSelectableIds();

    if (selectableIds.empty()) return;

    int currentId = presetArea.presetMenu.getSelectedId();

    // Encontrar el índice actual en la lista de IDs seleccionables
    auto currentIt = std::find(selectableIds.begin(), selectableIds.end(), currentId);

    int prevId;
    if (currentIt == selectableIds.end() || currentIt == selectableIds.begin()) {
        // Si no se encuentra o es el primero, ir al último
        prevId = selectableIds.back();
    } else {
        // Ir al anterior
        prevId = *(--currentIt);
    }

    presetArea.presetMenu.setSelectedId(prevId);

    // Trigger onChange para cargar el preset
    if (presetArea.presetMenu.onChange) {
        presetArea.presetMenu.onChange();
    }
}

//==============================================================================
// DIÁLOGOS Y OVERLAYS
//==============================================================================
void JCBImagerAudioProcessorEditor::showCustomConfirmDialog(const juce::String& message,
                                                          const juce::String& subMessage,
                                                          std::function<void(bool)> callback,
                                                          const juce::String& confirmText,
                                                          const juce::String& cancelText)
{
    // Combinar mensaje principal y submensaje si existe
    juce::String fullMessage = message;
    if (subMessage.isNotEmpty()) {
        fullMessage += "\n\n" + subMessage;
    }

    // Usar el nuevo diálogo personalizado
    deleteConfirmDialog = std::make_unique<CustomConfirmDialog>("Confirmation", fullMessage, confirmText, cancelText);
    deleteConfirmDialog->onDialogClosed = callback;
    addChildComponent(deleteConfirmDialog.get());
    deleteConfirmDialog->showDialog();
}

void JCBImagerAudioProcessorEditor::showCustomAlertDialog(const juce::String& title, const juce::String& message)
{
    // Crear un diálogo de alerta simple con solo OK
    alertDialog = std::make_unique<CustomAlertDialog>(title, message);
    alertDialog->onDialogClosed = [](bool) {}; // Callback vacío
    addChildComponent(alertDialog.get());
    alertDialog->showDialog();
}

void JCBImagerAudioProcessorEditor::showCredits()
{
    // Desactivar estados operacionales antes de mostrar créditos (consistencia con DIAGRAM)
    parameterButtons.bypassButton.setToggleState(false, juce::sendNotification);
    // sidechainControls.soloScButton.setToggleState(false, juce::sendNotification);

    if (creditsOverlay == nullptr)
    {
        // Obtener el formato del plugin desde el processor
        juce::String format = processor.getPluginFormat();

        creditsOverlay = std::make_unique<CreditsOverlay>(format);
        creditsOverlay->setBounds(getLocalBounds());
        creditsOverlay->onClose = [this]() {
            hideCredits();
        };

        addAndMakeVisible(creditsOverlay.get());
        creditsOverlay->grabKeyboardFocus();
    }
}

void JCBImagerAudioProcessorEditor::hideCredits()
{
    if (creditsOverlay != nullptr)
    {
        removeChildComponent(creditsOverlay.get());
        creditsOverlay.reset();
    }
}

//==============================================================================
// SISTEMA DE TOOLTIPS
//==============================================================================
void JCBImagerAudioProcessorEditor::updateTodoButtonTexts()
{
    // Actualizar tooltips de botones por hacer para consistencia
    utilityButtons.hqButton.setTooltip(getTooltipText("hq"));
    utilityButtons.dualMonoButton.setTooltip(getTooltipText("dualmono"));
    utilityButtons.msButton.setTooltip(getTooltipText("ms"));
    topButtons.abStateButton.setTooltip(getTooltipText("abstate"));
    utilityButtons.midiLearnButton.setTooltip(getTooltipText("midilearn"));
    // Stereo Linked button - se maneja en updateAllTooltips()
}

void JCBImagerAudioProcessorEditor::updateAllTooltips()
{
    // Título
    titleLink.setTooltip(getTooltipText("title"));

    trimSlider.setTooltip(getTooltipText("trim"));
    makeupSlider.setTooltip(getTooltipText("makeup"));

    sidechainControls.hpfSlider.setTooltip(getTooltipText("hpf"));
    sidechainControls.lpfSlider.setTooltip(getTooltipText("lpf"));
    sidechainControls.scButton.setTooltip(getTooltipText("sc"));

    leftKnobs.reflectSlider.setTooltip(getTooltipText("reflect"));
    leftKnobs.sizeSlider.setTooltip(getTooltipText("size"));
    leftKnobs.dampSlider.setTooltip(getTooltipText("damp"));
    leftKnobs.drywetSlider.setTooltip(getTooltipText("drywet"));
    leftKnobs.stSlider.setTooltip(getTooltipText("stereo"));
    leftKnobs.freezeButton.setTooltip(getTooltipText("freeze"));


    // Área de presets
    presetArea.saveButton.setTooltip(getTooltipText("save"));
    presetArea.saveAsButton.setTooltip(getTooltipText("saveas"));
    presetArea.deleteButton.setTooltip(getTooltipText("delete"));
    presetArea.backButton.setTooltip(getTooltipText("back"));
    presetArea.nextButton.setTooltip(getTooltipText("next"));

    // Utility buttons
    utilityButtons.undoButton.setTooltip(getTooltipText("undo"));
    utilityButtons.redoButton.setTooltip(getTooltipText("redo"));
    utilityButtons.resetGuiButton.setTooltip(getTooltipText("resetgui"));
    utilityButtons.runGraphicsButton.setTooltip(getTooltipText("graphics"));
    centerButtons.diagramButton.setTooltip(getTooltipText("diagram"));
    utilityButtons.tooltipToggleButton.setTooltip(getTooltipText("tooltiptoggle"));
    utilityButtons.tooltipLangButton.setTooltip(getTooltipText("tooltiplang"));

    // Botones de parámetros
    parameterButtons.bypassButton.setTooltip(getTooltipText("bypass"));

    // Tabs y controles de la derecha (EQ / COMP)
    rightTabs.eqTab.setTooltip(getTooltipText("eqtab"));
    rightTabs.compTab.setTooltip(getTooltipText("comptab"));

    eqControls.eqOnButton.setTooltip(getTooltipText("eqon"));
    eqControls.lsgSlider.setTooltip(getTooltipText("lsg"));
    eqControls.pgSlider.setTooltip(getTooltipText("pg"));
    eqControls.hsgSlider.setTooltip(getTooltipText("hsg"));
    eqControls.lsfSlider.setTooltip(getTooltipText("lsf"));
    eqControls.pfSlider.setTooltip(getTooltipText("pf"));
    eqControls.hsfSlider.setTooltip(getTooltipText("hsf"));

    compControls.compOnButton.setTooltip(getTooltipText("compon"));
    compControls.pumpButton.setTooltip(getTooltipText("pump"));
    compControls.thdSlider.setTooltip(getTooltipText("thd"));
    compControls.ratioSlider.setTooltip(getTooltipText("ratio"));
    compControls.atkSlider.setTooltip(getTooltipText("atk"));
    compControls.relSlider.setTooltip(getTooltipText("rel"));
    compControls.gainSlider.setTooltip(getTooltipText("compgain"));

    // Actualizar tooltips de botones "por hacer"
    updateTodoButtonTexts();

    // Botones de utilidad - fila inferior
    utilityButtons.stereoLinkedButton.setTooltip(getTooltipText("link"));
}

juce::String JCBImagerAudioProcessorEditor::getTooltipText(const juce::String& key)
{
    if (currentLanguage == TooltipLanguage::Spanish)
    {
        // Spanish tooltips
        if (key == "trim") return JUCE_UTF8("TRIM: ganancia de entrada a la reverb\nAjusta el nivel antes del procesamiento\nRango: -12 a +12 dB | Por defecto: 0 dB");
        if (key == "makeup") return JUCE_UTF8("OUTPUT: ganancia de salida (sólo WET)\nNo afecta la rama DRY/Dry-Wet\nRango: -24 a +12 dB | Por defecto: 0 dB");

        if (key == "hpf") return JUCE_UTF8("HPF: filtro paso alto 12 dB/oct\nAtenúa frecuencias por debajo del corte\nRango: 20 a 5000 Hz | Por defecto: 100 Hz");
        if (key == "lpf") return JUCE_UTF8("LPF: filtro paso bajo 12 dB/oct\nAtenúa frecuencias por encima del corte\nRango: 100 Hz a 20 kHz | Por defecto: 20 kHz");
        if (key == "sc") return JUCE_UTF8("FILTERS: activa/desactiva los filtros HPF/LPF (12 dB/oct).\nHPF y LPF se aplican según sus controles dedicados.\nValor por defecto: OFF");

        if (key == "reflect") return JUCE_UTF8("REFLECT: cantidad de reflexiones\nControla la retroalimentación/densidad de la reverb\nRango: 0% a 100% | Por defecto: 74 %");
        if (key == "size") return JUCE_UTF8("SIZE: tamaño del tanque de filtros peine\nSimula el tamaño del espacio\nRango: 0.1 a 4 | Por defecto: 1.5");

        if (key == "drywet") return JUCE_UTF8("DRY/WET: mezcla entre señal original y procesada\nControla el balance final de salida\nRango: 0 a 100% | Por defecto: 100%");
        //if (key == "lookahead") return JUCE_UTF8("LOOKAHEAD: anticipación para evitar distorsión\nEvita overshooting en transitorios rápidos\nRango: 0 a 5 ms | Por defecto: 0 ms");

        if (key == "damp") return JUCE_UTF8("DAMP: filtro en los feedback de los tanques de comb\nLPF 1er orden dentro del feedback\nRango: 0 a 100% | Por defecto: 0 %");
        if (key == "stereo") return JUCE_UTF8("STEREO: stereo image width\nMS matrix with delay on right channel\nRange: 0% to 100% | Default: 50%");
        if (key == "freeze") return JUCE_UTF8("FREEZE: congela el tanque de combs\nActivado silencia la entrada y la cadena DRY\nRango: OFF/ON | Por defecto: OFF");

        // Tabs y EQ (derecha)
        if (key == "eqtab") return JUCE_UTF8("Pestaña EQ: muestra controles de ecualización\nAjusta frecuencias y ganancias");
        if (key == "comptab") return JUCE_UTF8("Pestaña COMP: muestra controles del compresor\nConfigura dinámica y PUMP");
        if (key == "eqon") return JUCE_UTF8("EQ ON/OFF: activa o desactiva la EQ\nAl OFF, los controles quedan atenuados");
        if (key == "lsf") return JUCE_UTF8("LSF: frecuencia del Low Shelf\nPunto de giro de graves\nRango: 20 a 500 Hz");
        if (key == "pf")  return JUCE_UTF8("PF: frecuencia del filtro Peak (campana)\nCentro de realce/atenuación en medios\nRango: 500 a 2500 Hz");
        if (key == "hsf") return JUCE_UTF8("HSF: frecuencia del High Shelf\nPunto de giro de agudos\nRango: 2.5 a 15 kHz");
        if (key == "lsg") return JUCE_UTF8("LSG: ganancia del Low Shelf\nAjuste de graves en dB\nRango: -24 a +24 dB");
        if (key == "pg")  return JUCE_UTF8("PG: ganancia del filtro Peak\nRealce/atenuación en medios\nRango: -24 a +24 dB");
        if (key == "hsg") return JUCE_UTF8("HSG: ganancia del High Shelf\nAjuste de agudos en dB\nRango: -24 a +24 dB");

        // Compresor (derecha)
        if (key == "compon") return JUCE_UTF8("COMP ON/OFF: activa o desactiva el compresor\nAl OFF se bloquea PUMP y los controles quedan atenuados");
        if (key == "thd")   return JUCE_UTF8("THD: umbral del compresor\nNivel a partir del cual comprime\nRango: -60 a 0 dB");
        if (key == "ratio") return JUCE_UTF8("RATIO: relación de compresión\nCuánto reduce por encima del umbral\nRango: 1:1 a 20:1");
        if (key == "atk")   return JUCE_UTF8("ATK: tiempo de ataque\nVelocidad de reacción al superar el umbral\nRango: 1 a 750 ms");
        if (key == "rel")   return JUCE_UTF8("REL: tiempo de relajación\nVelocidad de retorno tras compresión\nRango: 15 a 2000 ms");
        if (key == "compgain") return JUCE_UTF8("GAIN: ganancia de compensación del compresor\nAjusta el nivel tras comprimir\nRango: -6 a +6 dB");
        if (key == "pump")  return JUCE_UTF8("PUMP: modo de bombeo/ducking\nRealza el efecto de bombeo impulsado por el compresor\nSolo disponible cuando COMP está ON");


        if (key == "title") return JUCE_UTF8("JCBImager v1.0.0-alpha.1\nPlugin de audio open source\nClick para créditos");
        if (key == "save") return JUCE_UTF8("SAVE: guarda el preset actual\nSobrescribe el preset seleccionado con valores actuales\nNo funciona con DEFAULT");
        if (key == "saveas") return JUCE_UTF8("SAVE AS: guarda como nuevo preset\nCrea un nuevo archivo de preset con los valores actuales\nPermite crear presets personalizados");
        if (key == "delete") return JUCE_UTF8("BORRAR: elimina el preset seleccionado\nRequiere confirmación antes de borrar");
        if (key == "back") return JUCE_UTF8("ANTERIOR: selecciona el preset previo\nNavega hacia atrás en la lista de presets");
        if (key == "next") return JUCE_UTF8("SIGUIENTE: selecciona el próximo preset\nNavega hacia adelante en la lista de presets");
        if (key == "undo") return JUCE_UTF8("DESHACER: revierte el último cambio\nDeshace modificación realizada manualmente por el usuario\nHistorial: hasta 20 pasos");
        if (key == "redo") return JUCE_UTF8("REHACER: aplica el cambio deshecho\nRehace modificación manual previamente revertida\nHistorial: hasta 20 pasos");
        if (key == "resetgui") return JUCE_UTF8("SIZE: cicla entre tamaños de ventana\nActual → Máximo → Mínimo → Actual\nAjuste rápido del tamaño del plugin");
        if (key == "bypass") return JUCE_UTF8("BYPASS: desactiva el procesamiento del plugin\nParámetro global, no automatizable. Transición suave\nRango: OFF/ON | Por defecto: OFF");
        if (key == "graphics") return JUCE_UTF8("GRAPHICS: alterna el hold del analizador y goniometer\nLive: actualización continua | Hold: congela ambas visualizaciones");
        if (key == "diagram") return JUCE_UTF8("DIAGRAM: muestra diagrama de bloques del procesador\nSolo visual; bloquea clics al fondo");
        if (key == "tooltiptoggle") return JUCE_UTF8("TOOLTIP: muestra/oculta los tooltips de ayuda\nActiva o desactiva las ventanas de ayuda emergentes");
        if (key == "tooltiplang") return JUCE_UTF8("IDIOMA: cambia entre español e inglés.\nAlterna el idioma de los tooltips.");
        if (key == "link") return JUCE_UTF8("STEREO LINKED: siempre activo.\nEl plugin solo funciona en modo stereo linked.\nAmbos canales siempre están vinculados");
        if (key == "hq") return JUCE_UTF8("POR HACER: Habilita oversampling para mayor calidad.");
        if (key == "dualmono") return JUCE_UTF8("POR HACER: Procesa canales L/R independientemente.");
        if (key == "ms") return JUCE_UTF8("POR HACER: Procesa en formato Mid/Side.");
        if (key == "abstate") return JUCE_UTF8("Alterna entre dos configuraciones A/B para comparar ajustes.");
        if (key == "midilearn") return JUCE_UTF8("POR HACER: Asigna control MIDI.");
        if (key == "abcopyatob") return JUCE_UTF8("Copiar A a B");
        if (key == "abcopybtoa") return JUCE_UTF8("Copiar B a A");
    }
    else
    {
        // English tooltips
        if (key == "trim") return JUCE_UTF8("TRIM: input gain to the reverb\nAdjusts the level before processing\nRange: -12 to +12 dB | Default: 0 dB");
        if (key == "makeup") return JUCE_UTF8("OUTPUT: output gain (WET only)\nDoes not affect the DRY/Dry-Wet path\nRange: -24 to +12 dB | Default: 0 dB");

        if (key == "hpf") return JUCE_UTF8("HPF: high-pass filter 12 dB/oct\nAttenuates frequencies below the cutoff\nRange: 20 to 5000 Hz | Default: 100 Hz");
        if (key == "lpf") return JUCE_UTF8("LPF: low-pass filter 12 dB/oct\nAttenuates frequencies above the cutoff\nRange: 100 Hz to 20 kHz | Default: 20 kHz");
        if (key == "sc") return JUCE_UTF8("FILTERS: enable/disable HPF/LPF (12 dB/oct)\nHPF and LPF are applied according to their dedicated controls\nDefault: OFF");

        if (key == "reflect") return JUCE_UTF8("REFLECT: amount of reflections\nControls reverb feedback/density\nRange: 0% to 100% | Default: 74 %");
        if (key == "size") return JUCE_UTF8("SIZE: comb filter tank size\nSimulates the size of the space\nRange: 0.1 to 4 | Default: 1.5");

        if (key == "drywet") return JUCE_UTF8("DRY/WET: mix between original and processed signal\nControls the final output balance\nRange: 0 to 100% | Default: 100%");
        if (key == "damp") return JUCE_UTF8("DAMP: damping filter in the comb tank feedback\n1st-order LPF inside the feedback loop\nRange: 0 to 100% | Default: 0 %");
        if (key == "stereo") return JUCE_UTF8("STEREO: stereo image width\nMS matrix with delay on right channel\nRange: 0% to 100% | Default: 50%");
        if (key == "freeze") return JUCE_UTF8("FREEZE: freezes the comb tank\nWhen enabled, input and DRY chain are muted\nRange: OFF/ON | Default: OFF");

        // Tabs & EQ (right)
        if (key == "eqtab") return JUCE_UTF8("EQ tab: shows equalizer controls\nAdjust frequencies and gains");
        if (key == "comptab") return JUCE_UTF8("COMP tab: shows compressor controls\nSet dynamics and PUMP");
        if (key == "eqon") return JUCE_UTF8("EQ ON/OFF: enable or disable the EQ\nWhen OFF, controls are dimmed");
        if (key == "lsf") return JUCE_UTF8("LSF: Low Shelf frequency\nShelf pivot for lows\nRange: 20 to 500 Hz");
        if (key == "pf")  return JUCE_UTF8("PF: Peak filter frequency\nCenter frequency for mid boost/cut\nRange: 500 to 2500 Hz");
        if (key == "hsf") return JUCE_UTF8("HSF: High Shelf frequency\nShelf pivot for highs\nRange: 2.5 to 15 kHz");
        if (key == "lsg") return JUCE_UTF8("LSG: Low Shelf gain\nBass adjustment in dB\nRange: -24 to +24 dB");
        if (key == "pg")  return JUCE_UTF8("PG: Peak gain\nMidrange boost/cut in dB\nRange: -24 to +24 dB");
        if (key == "hsg") return JUCE_UTF8("HSG: High Shelf gain\nHighs adjustment in dB\nRange: -24 to +24 dB");

        // Compressor (right)
        if (key == "compon") return JUCE_UTF8("COMP ON/OFF: enable or disable the compressor\nWhen OFF, PUMP is blocked and controls are dimmed");
        if (key == "thd")   return JUCE_UTF8("THD: compressor threshold\nLevel above which compression occurs\nRange: -60 to 0 dB");
        if (key == "ratio") return JUCE_UTF8("RATIO: compression ratio\nHow much reduction above threshold\nRange: 1:1 to 20:1");
        if (key == "atk")   return JUCE_UTF8("ATK: attack time\nHow fast it reacts above threshold\nRange: 1 to 750 ms");
        if (key == "rel")   return JUCE_UTF8("REL: release time\nHow fast it recovers after compression\nRange: 15 to 2000 ms");
        if (key == "compgain") return JUCE_UTF8("GAIN: compressor makeup gain\nAdjusts level after compression\nRange: -6 to +6 dB");
        if (key == "pump")  return JUCE_UTF8("PUMP: pumping/ducking mode\nEnhances compressor-driven pumping effect\nOnly available when COMP is ON");



        if (key == "title") return JUCE_UTF8("JCBImager v1.0.0-alpha.1\nOpen source audio plugin\nClick for credits");
        if (key == "save") return JUCE_UTF8("SAVE: overwrite current preset\nReplaces the selected preset with current values\nNot available for DEFAULT");
        if (key == "saveas") return JUCE_UTF8("SAVE AS: save as new preset\nCreates a new preset file with current values\nAllows creating custom presets");
        if (key == "delete") return JUCE_UTF8("DELETE: remove selected preset\nRequires confirmation before deletion");
        if (key == "back") return JUCE_UTF8("PREVIOUS: select previous preset\nNavigate backwards in preset list");
        if (key == "next") return JUCE_UTF8("NEXT: select next preset\nNavigate forwards in preset list");
        if (key == "undo") return JUCE_UTF8("UNDO: revert last change\nUndoes manual user modification\nHistory: up to 20 steps");
        if (key == "redo") return JUCE_UTF8("REDO: apply reverted change\nReapplies previously undone modification\nHistory: up to 20 steps");
        if (key == "resetgui") return JUCE_UTF8("SIZE: cycle window size\nCurrent → Maximum → Minimum → Current\nQuick adjustment of plugin window size");
        if (key == "bypass") return JUCE_UTF8("BYPASS: disables plugin processing\nGlobal parameter, not automatable. Smooth transition\nRange: OFF/ON | Default: OFF");
        if (key == "graphics") return JUCE_UTF8("GRAPHICS: toggle hold for both analyzer and goniometer\nLive: continuous updates | Hold: freezes both displays");
        if (key == "diagram") return JUCE_UTF8("DIAGRAM: show processor block diagram\nVisual only; blocks clicks to the background");
        if (key == "tooltiptoggle") return JUCE_UTF8("TOOLTIP: show/hide help tooltips\nEnable or disable popup help windows");
        if (key == "tooltiplang") return JUCE_UTF8("LANGUAGE: switch between Spanish and English\nToggles tooltip language");
        if (key == "link") return JUCE_UTF8("STEREO LINKED: always active\nThe plugin only works in stereo linked mode\nBoth channels are always coupled");
        if (key == "hq") return JUCE_UTF8("TODO: Enable oversampling for higher quality");
        if (key == "dualmono") return JUCE_UTF8("TODO: Process L/R channels independently");
        if (key == "ms") return JUCE_UTF8("TODO: Process in Mid/Side format");
        if (key == "abstate") return JUCE_UTF8("Toggle between two A/B states to compare settings");
        if (key == "midilearn") return JUCE_UTF8("TODO: Assign MIDI control");
        if (key == "abcopyatob") return JUCE_UTF8("Copy A to B");
        if (key == "abcopybtoa") return JUCE_UTF8("Copy B to A");
    }

    return "";
}


//==============================================================================
// HELPERS DE UI
//==============================================================================
void JCBImagerAudioProcessorEditor::applyAlphaToMainControls(float alpha)
{
    juce::ignoreUnused(alpha);
}


// Nota: La funcionalidad de visualización de código ahora se maneja por CodeWindow desde DIAGRAM



//==============================================================================
// THREAD SAFETY Y AUTOMATIZACIÓN
//==============================================================================
void JCBImagerAudioProcessorEditor::queueParameterUpdate(const juce::String& paramID, float normalizedValue)
{
    {
        std::lock_guard<std::mutex> lock(parameterUpdateMutex);

        // Check if this parameter is already queued
        auto it = std::ranges::find_if(pendingParameterUpdates,
                               [&paramID](const DeferredParameterUpdate& update) {
                                   return update.paramID == paramID;
                               });

        if (it != pendingParameterUpdates.end()) {
            // Actualizar entrada existente
            it->normalizedValue = normalizedValue;
        } else {
            // Add new entry
            pendingParameterUpdates.push_back({paramID, normalizedValue});
        }
    }

    hasPendingParameterUpdates.store(true);
}

void JCBImagerAudioProcessorEditor::processPendingParameterUpdates()
{
    if (!hasPendingParameterUpdates.exchange(false)) {
        return;
    }

    std::vector<DeferredParameterUpdate> updates;
    {
        std::lock_guard<std::mutex> lock(parameterUpdateMutex);
        updates = std::move(pendingParameterUpdates);
        pendingParameterUpdates.clear();
    }

    // Establecer flag para prevenir transacciones de undo durante procesamiento de queue
    isProcessingQueue = true;

    // Process all updates on the message thread
    for (const auto& update : updates) {
        if (auto* param = processor.apvts.getParameter(update.paramID)) {
            // Usar beginChangeGesture/endChangeGesture para prevenir transacciones de undo
            param->beginChangeGesture();
            param->setValueNotifyingHost(update.normalizedValue);
            param->endChangeGesture();

            // CRÍTICO: Sincronización directa con Gen~ DSP
            // Esto asegura que los valores del DEFAULT button lleguen al DSP
            // Convertir valor normalizado a valor real usando el rango del parámetro
            if (auto* floatParam = dynamic_cast<juce::AudioParameterFloat*>(param)) {
                float realValue = floatParam->getNormalisableRange().convertFrom0to1(update.normalizedValue);

                if (update.paramID == "d_ATK" || update.paramID == "e_REL") {
                    // Debug info for DEFAULT preset parameter updates
                }

                // Llamar al método parameterChanged del processor para sincronizar con Gen~
                processor.parameterChanged(update.paramID, realValue);
            }

            // Manejo de AudioParameterBool para sincronización con Gen~
            if (dynamic_cast<juce::AudioParameterBool*>(param)) {
                float realValue = update.normalizedValue >= 0.5f ? 1.0f : 0.0f;


                // Llamar al método parameterChanged del processor para sincronizar con Gen~
                processor.parameterChanged(update.paramID, realValue);
            }
        }
    }

    // Visual feedback (cambios de alpha) se maneja en timerCallback() para updates consistentes

    // Limpiar flag después del procesamiento
    isProcessingQueue = false;
}

//==============================================================================
// DIAGRAM Y CODE WINDOW
//==============================================================================

void JCBImagerAudioProcessorEditor::showDiagram()
{
    // Thread-safe: usar MessageManager::callAsync para UI pesadas
    juce::Component::SafePointer<JCBImagerAudioProcessorEditor> safeThis(this);

    juce::MessageManager::callAsync([safeThis]() {
        if (!safeThis) return;

        // Crear overlay si no existe
        if (!safeThis->diagramOverlay)
        {
            safeThis->diagramOverlay = std::make_unique<DiagramOverlay>(*safeThis);
        }

        // Configurar y mostrar
        safeThis->addChildComponent(safeThis->diagramOverlay.get());
        safeThis->diagramOverlay->setBounds(safeThis->getLocalBounds());
        safeThis->diagramOverlay->setVisible(true);
        safeThis->diagramOverlay->toFront(true);
        safeThis->centerButtons.diagramButton.setToggleState(true, juce::dontSendNotification);
    });
}

void JCBImagerAudioProcessorEditor::hideDiagram()
{
    if (diagramOverlay && diagramOverlay->isVisible())
    {
        diagramOverlay->setVisible(false);
        removeChildComponent(diagramOverlay.get());
    }
    centerButtons.diagramButton.setToggleState(false, juce::dontSendNotification);
}

void JCBImagerAudioProcessorEditor::hideCodeWindow()
{
    if (codeWindow && codeWindow->isVisible())
    {
        codeWindow->setVisible(false);
        removeChildComponent(codeWindow.get());
    }
}

juce::String JCBImagerAudioProcessorEditor::loadCodeFromFile(const juce::String& blockName)
{
    // Thread-safe: usar cache pre-cargado en lugar de leer BinaryData cada vez
    if (codeContentCacheInitialized && codeContentCache.contains(blockName)) {
        return codeContentCache[blockName];
    }

    // Fallback si el cache no está inicializado o no se encuentra el bloque
    return "// Code for " + blockName + "\n\n// Content not found in cache.\n// Please report this issue.\n\n// Basic functionality:\n" + getBasicBlockDescription(blockName);
}

void JCBImagerAudioProcessorEditor::initializeCodeContentCache()
{
    // Code windows for DIAGRAM have been removed; keep an empty cache to satisfy calls.
    codeContentCache.clear();
    codeContentCacheInitialized = true;
}

juce::String JCBImagerAudioProcessorEditor::getBasicBlockDescription(const juce::String& blockName)
{
    if (blockName == "TRIM IN") {
        return "// Input trim gain applied to main signal\ninput_trimmed = input * dbtoa(trim_db);";
    } else if (blockName == "OUTPUT") {
        return "// Final output with any additional processing\nfinal_output = output_stage(processed_signal);";
    } else {
        return "// Generic Gen~ block processing\n// See Max patch for detailed implementation";
    }
}

// Función helper para obtener índice de parámetro por ID (robusta, compatible con el futuro)
int JCBImagerAudioProcessorEditor::getParameterIndexByID(const juce::String& parameterID)
{
    auto& params = processor.getParameters();
    for (int i = 0; i < params.size(); ++i) {
        if (auto* param = dynamic_cast<juce::AudioProcessorParameterWithID*>(params[i])) {
            if (param->paramID == parameterID) {
                return i;
            }
        }
    }
    return -1; // Parámetro no encontrado
}

int JCBImagerAudioProcessorEditor::getControlParameterIndex(juce::Component& control)
{
    // Mapear componentes UI a sus IDs de parámetro (robusta, compatible con el futuro)
    // Retornar -1 para componentes que no representan parámetros automatizables

    juce::String parameterID;

    // COMENTADO: Referencias a controles inexistentes en getParameterIndexFromControl
    /*
    // Perillas Superiores Izquierdas (threshold, ratio, knee)
    if (&control == &leftBottomKnobs.drywetSlider) parameterID = "a_DRYWET";
    else if (&control == &leftKnobs.ceilingSlider) parameterID = "e_CEILING";  // NUEVO - ceiling slider
    */
    // MAXIMIZER: c_RATIO no existe - comentado según CONTEXTO.txt
    // else if (&control == &leftKnobs.ratioSlider) parameterID = "c_RATIO";
    // MAXIMIZER: q_KNEE no existe - comentado según CONTEXTO.txt
    // else if (&control == &leftKnobs.kneeSlider) parameterID = "q_KNEE";

    // DISTORTION: n_LOOKAHEAD eliminado - no existe en distorsionador
    // else if (&control == &rightTopControls.lookaheadSlider) parameterID = "n_LOOKAHEAD";

    // Controles Superiores Derechos (range, react, smooth)
    // MAXIMIZER: h_RANGE no existe - comentado según CONTEXTO.txt
    // else if (&control == &rightTopControls.rangeSlider) parameterID = "h_RANGE";
    // MAXIMIZER: g_REACT no existe - comentado según CONTEXTO.txt
    // else if (&control == &rightTopControls.reactSlider) parameterID = "g_REACT";
    // MAXIMIZER: z_SMOOTH no existe - comentado según CONTEXTO.txt
    // else if (&control == &rightTopControls.smoothSlider) parameterID = "z_SMOOTH";
    // COMENTADO: Más referencias en getParameterIndexFromControl
    /*
    else if (&control == &rightTopControls.tiltSlider) parameterID = "i_TILT";  // NUEVO - tilt EQ slider
    else if (&control == &rightTopControls.bitsSlider) parameterID = "g_BITS";  // NUEVO - bit crusher resolution

    // Perillas Inferiores Derechas (attack, release, hold)
    else if (&control == &rightBottomKnobs.driveSlider) parameterID = "b_DRIVE";
    else if (&control == &leftKnobs.reflectSlider) parameterID = "c_REFLECT";
    // else if (&control == &rightBottomKnobs.holdSlider) parameterID = "f_HOLD";
    
    // Controles de filtro de entrada
    else if (&control == &sidechainControls.hpfSlider) parameterID = "l_HPF";
    else if (&control == &sidechainControls.bandSlider) parameterID = "o_BAND";
    else if (&control == &sidechainControls.lpfSlider) parameterID = "k_LPF";
    // else if (&control == &sidechainControls.keyButton) parameterID = "r_KEY";
    
    // Sliders de Trim
    else if (&control == &trimSlider) parameterID = "a_INPUT";
    else if (&control == &makeupSlider) parameterID = "m_OUTPUT";
    // else if (&control == &scTrimSlider) parameterID = "y_SCTRIM";
    
    // Botones Automatizables
    else if (&control == &sidechainControls.scButton) parameterID = "y_FILTERS";
    
    // Parámetros no automatizables (retornar -1)
    // Estos son parámetros globales/utility que no deberían mostrar carriles de automatización
    // else if (&control == &sidechainControls.soloScButton) return -1;  // m_SOLOSC (no automatizable)
    else if (&control == &rightBottomKnobs.bitButton) return -1;      // g_DITHER (no automatizable)
    else if (&control == &rightBottomKnobs.dcSlider) parameterID = "c_DC";  // c_DC (continuo 0-1)
    */
    // else if (&control == &parameterButtons.bypassButton) return -1;     // h_BYPASS (no automatizable)
    
    // Obtener índice dinámico de parámetro
    if (parameterID.isNotEmpty()) {
        return getParameterIndexByID(parameterID);
    }
    
    // Cualquier otro componente que no representa un parámetro
    return -1;
}

void JCBImagerAudioProcessorEditor::applyMeterDecayIfNeeded()
{
    // Sistema universal de decay para todos los DAWs
    // Basado en la solución recomendada en los foros de JUCE
    // Implementación profesional: decay siempre activo
    
    // Los medidores decaen naturalmente por inactividad
    // Los repaints se manejan automáticamente por el timer normal del editor
}

void JCBImagerAudioProcessorEditor::updateARButtonText()
{
    // En el original ExpansorGate manejaba el texto dinámico AR OFF/AR ON
    // En este procesador no hay AUTOREL independiente
}


void JCBImagerAudioProcessorEditor::setSoloState(bool low, bool mid, bool high)
{
    // Actualizar UI
    imager.soloLow .setToggleState(low,  juce::dontSendNotification);
    imager.soloMid .setToggleState(mid,  juce::dontSendNotification);
    imager.soloHigh.setToggleState(high, juce::dontSendNotification);

    // Guardar en UISettings del APVTS
    auto ui = processor.apvts.state.getOrCreateChildWithName("UISettings", nullptr);
    ui.setProperty("ui_solo_low",  low,  nullptr);
    ui.setProperty("ui_solo_mid",  mid,  nullptr);
    ui.setProperty("ui_solo_high", high, nullptr);

    // Espejo UI → AT (atomics) + encolar cambios para RT
    processor.uiSoloLow .store(low  ? 1 : 0, std::memory_order_release);
    processor.uiSoloMid .store(mid  ? 1 : 0, std::memory_order_release);
    processor.uiSoloHigh.store(high ? 1 : 0, std::memory_order_release);
    processor.pushGenParamByName("f_SOLOLOW",  low  ? 1.f : 0.f);
    processor.pushGenParamByName("g_SOLOMED",  mid  ? 1.f : 0.f);
    processor.pushGenParamByName("h_SOLOHIGH", high ? 1.f : 0.f);

    int selectedBand = -1;
    if (low)      selectedBand = 0;
    else if (mid) selectedBand = 1;
    else if (high)selectedBand = 2;

    spectrumAnalyzer.setSelectedBand(selectedBand);

    updateBandVisualStates();
}

void JCBImagerAudioProcessorEditor::loadSoloStateFromUISettings()
{
    auto ui = processor.apvts.state.getChildWithName("UISettings");
    bool low = false, mid = false, high = false;
    if (ui.isValid())
    {
        low  = (bool) ui.getProperty("ui_solo_low",  false);
        mid  = (bool) ui.getProperty("ui_solo_mid",  false);
        high = (bool) ui.getProperty("ui_solo_high", false);
    }
    // Enforce exclusivity if multiple were true
    if ((int)low + (int)mid + (int)high > 1)
    {
        // Si hay conflicto, priorizar LOW > MID > HIGH
        if (low) { mid = high = false; }
        else if (mid) { high = false; }
    }
    setSoloState(low, mid, high);
}

void JCBImagerAudioProcessorEditor::setMuteState(bool low, bool mid, bool high)
{
    // Actualizar UI
    imager.muteLow .setToggleState(low,  juce::dontSendNotification);
    imager.muteMid .setToggleState(mid,  juce::dontSendNotification);
    imager.muteHigh.setToggleState(high, juce::dontSendNotification);

    // Guardar en UISettings del APVTS
    auto ui = processor.apvts.state.getOrCreateChildWithName("UISettings", nullptr);
    ui.setProperty("ui_mute_low",  low,  nullptr);
    ui.setProperty("ui_mute_mid",  mid,  nullptr);
    ui.setProperty("ui_mute_high", high, nullptr);

    // Espejo UI → AT (atomics) + encolar cambios para RT
    processor.uiMuteLow .store(low  ? 1 : 0, std::memory_order_release);
    processor.uiMuteMid .store(mid  ? 1 : 0, std::memory_order_release);
    processor.uiMuteHigh.store(high ? 1 : 0, std::memory_order_release);
    processor.pushGenParamByName("n_MUTLOW",  low  ? 1.f : 0.f);
    processor.pushGenParamByName("o_MUTMED",  mid  ? 1.f : 0.f);
    processor.pushGenParamByName("p_MUTHIGH", high ? 1.f : 0.f);

    updateBandVisualStates();
}

void JCBImagerAudioProcessorEditor::loadMuteStateFromUISettings()
{
    auto ui = processor.apvts.state.getChildWithName("UISettings");
    bool low = false, mid = false, high = false;
    if (ui.isValid())
    {
        low  = (bool) ui.getProperty("ui_mute_low",  false);
        mid  = (bool) ui.getProperty("ui_mute_mid",  false);
        high = (bool) ui.getProperty("ui_mute_high", false);
    }
    setMuteState(low, mid, high);
}

void JCBImagerAudioProcessorEditor::updateBandVisualStates()
{
    const bool soloLow  = imager.soloLow.getToggleState();
    const bool soloMid  = imager.soloMid.getToggleState();
    const bool soloHigh = imager.soloHigh.getToggleState();

    const bool muteLow  = imager.muteLow.getToggleState();
    const bool muteMid  = imager.muteMid.getToggleState();
    const bool muteHigh = imager.muteHigh.getToggleState();

    const bool anySolo = (soloLow || soloMid || soloHigh);

    auto applyBand = [&](auto& widthSlider,
                         auto& balanceSlider,
                         auto& labelL,
                         auto& labelC,
                         auto& labelR,
                         auto& soloButton,
                         auto& muteButton,
                         bool soloState,
                         bool muteState)
    {
        const float soloAlpha = (!anySolo || soloState) ? 1.0f : 0.35f;
        const float controlAlpha = muteState ? 0.25f : soloAlpha;

        widthSlider.setAlpha(controlAlpha);
        balanceSlider.setAlpha(controlAlpha);
        labelL.setAlpha(controlAlpha);
        labelC.setAlpha(controlAlpha);
        labelR.setAlpha(controlAlpha);

        soloButton.setAlpha(soloAlpha);
        muteButton.setAlpha(muteState ? 1.0f : soloAlpha);
    };

    applyBand(imager.lowGain,  imager.lowBal,  imager.lowBalL,  imager.lowBalC,  imager.lowBalR,  imager.soloLow,  imager.muteLow,  soloLow,  muteLow);
    applyBand(imager.midGain,  imager.midBal,  imager.midBalL,  imager.midBalC,  imager.midBalR,  imager.soloMid,  imager.muteMid,  soloMid,  muteMid);
    applyBand(imager.highGain, imager.highBal, imager.highBalL, imager.highBalC, imager.highBalR, imager.soloHigh, imager.muteHigh, soloHigh, muteHigh);

    int mask = (muteLow ? 0b001 : 0) | (muteMid ? 0b010 : 0) | (muteHigh ? 0b100 : 0);
    spectrumAnalyzer.setMutedBands(mask);
}

void JCBImagerAudioProcessorEditor::updateModeButtonLabels()
{
    auto updateButton = [](juce::TextButton& button, bool isInput)
    {
        const bool isXY = !button.getToggleState();
        const char* modeText = isXY ? "XY" : "MS";
        button.setButtonText(juce::String(modeText) + (isInput ? " INPUT" : " OUTPUT"));
    };

    updateButton(imager.inputMode,  true);
    updateButton(imager.outputMode, false);

    goniometerDisplay.setDisplayAsXY(!imager.outputMode.getToggleState());
}
