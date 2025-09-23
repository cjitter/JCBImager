#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_graphics/juce_graphics.h>
#include <mutex>
#include <vector>

#include "../Windows/DarkThemeColors.h"

/**
 * Componente de goniometer (vectorscope) para visualizar la relación estéreo
 * de la señal procesada. Muestra la trama L/R en un plano cartesiano y un
 * indicador rápido de correlación.
 */
class GoniometerComponent : public juce::Component,
                            public juce::TooltipClient
{
public:
    GoniometerComponent();
    ~GoniometerComponent() override = default;

    void paint(juce::Graphics& g) override;
    void resized() override;

    juce::String getTooltip() override;

    // Actualiza los puntos a dibujar. Se espera que provengan del message thread.
    void setSamples(const std::vector<juce::Point<float>>& newSamples);

    // Permite congelar la visualización para inspección.
    void setHoldEnabled(bool shouldHold) noexcept;
    bool isHoldEnabled() const noexcept { return holdEnabled; }

    // Define si el display muestra referencias XY (L/R) o MS (M/S).
    void setDisplayAsXY(bool shouldDisplayXY) noexcept;
    bool isDisplayingXY() const noexcept { return displayAsXY; }

private:
    void updateCorrelation(const std::vector<juce::Point<float>>& samples) noexcept;

    std::vector<juce::Point<float>> displaySamples;
    mutable std::mutex dataMutex;

    bool holdEnabled{false};
    float correlation{0.0f};
    bool hasCorrelation{false};
    float correlationSmoothed{0.0f};
    bool correlationSmoothedInitialised{false};
    bool displayAsXY{true};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GoniometerComponent)
};
