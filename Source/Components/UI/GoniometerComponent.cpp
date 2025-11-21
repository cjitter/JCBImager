#include "GoniometerComponent.h"

#include <algorithm>
#include <cmath>
#include <cstddef>

namespace
{
    constexpr float kCornerRadius = 6.0f;
    constexpr size_t kMaxPointsToDraw = 2048;
    constexpr float kCorrelationPanelWidth = 32.0f;
}

GoniometerComponent::GoniometerComponent()
{
    setOpaque(false);
}

juce::String GoniometerComponent::getTooltip()
{
    return getHelpText();
}

void GoniometerComponent::setSamples(const std::vector<juce::Point<float>>& newSamples)
{
    if (holdEnabled)
        return;

    const size_t count = std::min(newSamples.size(), kMaxPointsToDraw);

    {
        std::lock_guard<std::mutex> lock(dataMutex);
        displaySamples.clear();
        if (count > 0)
        {
            displaySamples.insert(displaySamples.end(),
                                  newSamples.end() - static_cast<std::ptrdiff_t>(count),
                                  newSamples.end());
        }

        updateCorrelation(displaySamples);
    }
    repaint();
}

void GoniometerComponent::setHoldEnabled(bool shouldHold) noexcept
{
    if (holdEnabled != shouldHold)
    {
        holdEnabled = shouldHold;
        if (!holdEnabled)
            repaint();
    }
}

void GoniometerComponent::setDisplayAsXY(bool shouldDisplayXY) noexcept
{
    if (displayAsXY != shouldDisplayXY)
    {
        displayAsXY = shouldDisplayXY;
        repaint();
    }
}

void GoniometerComponent::updateCorrelation(const std::vector<juce::Point<float>>& samples) noexcept
{
    if (samples.empty())
    {
        correlation = 1.0f;
        hasCorrelation = true;
        balance = 0.0f;
        hasBalance = false;
        if (!correlationSmoothedInitialised)
        {
            correlationSmoothed = correlation;
            correlationSmoothedInitialised = true;
        }
        else
        {
            const float smoothing = 0.2f;
            correlationSmoothed += smoothing * (correlation - correlationSmoothed);
        }

        if (!balanceSmoothedInitialised)
        {
            balanceSmoothed = balance;
            balanceSmoothedInitialised = true;
        }
        else
        {
            const float smoothing = 0.2f;
            balanceSmoothed += smoothing * (balance - balanceSmoothed);
        }
        return;
    }

    double sumLR = 0.0;
    double sumLL = 0.0;
    double sumRR = 0.0;

    for (const auto& s : samples)
    {
        const double mid = static_cast<double>(s.y);
        const double side = static_cast<double>(s.x);
        const double left = (mid + side) * 0.7071067811865476;  // (mid + side) / sqrt(2)
        const double right = (mid - side) * 0.7071067811865476; // (mid - side) / sqrt(2)

        sumLR += left * right;
        sumLL += left * left;
        sumRR += right * right;
    }

    const double denom = std::sqrt(sumLL * sumRR);
    if (denom > 1.0e-6)
    {
        correlation = static_cast<float>(juce::jlimit(-1.0, 1.0, sumLR / denom));
        hasCorrelation = true;
    }
    else
    {
        correlation = 1.0f;
        hasCorrelation = true;
    }

    const double energySum = sumLL + sumRR;
    if (energySum > 1.0e-6)
    {
        balance = static_cast<float>(juce::jlimit(-1.0, 1.0, (sumRR - sumLL) / energySum));
        hasBalance = true;
    }
    else
    {
        balance = 0.0f;
        hasBalance = false;
    }

    if (!correlationSmoothedInitialised)
    {
        correlationSmoothed = correlation;
        correlationSmoothedInitialised = true;
    }
    else
    {
        const float smoothing = 0.2f;
        correlationSmoothed += smoothing * (correlation - correlationSmoothed);
    }

    if (!balanceSmoothedInitialised)
    {
        balanceSmoothed = balance;
        balanceSmoothedInitialised = true;
    }
    else
    {
        const float smoothing = 0.2f;
        balanceSmoothed += smoothing * (balance - balanceSmoothed);
    }
}

void GoniometerComponent::paint(juce::Graphics& g)
{
    auto bounds = getLocalBounds().toFloat();
    if (bounds.isEmpty())
        return;

    // Fondo principal: solo borde para que sea translúcido
    g.setColour(DarkTheme::border.withAlpha(0.25f));
    g.drawRoundedRectangle(bounds.reduced(0.5f), kCornerRadius, 1.0f);

    auto inner = bounds.reduced(6.0f, 5.0f);
    auto corrArea = inner.removeFromRight(std::min(kCorrelationPanelWidth, inner.getWidth() * 0.25f));
    corrArea.reduce(2.0f, 4.0f);

    const float reservedBalanceHeight = 26.0f;
    auto availableHeight = std::max(0.0f, inner.getHeight() - reservedBalanceHeight);
    auto scopeSize = std::min(inner.getWidth(), std::max(16.0f, availableHeight));
    const float scopeX = inner.getCentreX() - scopeSize * 0.5f;
    const float scopeY = inner.getY();
    juce::Rectangle<float> scopeArea(scopeX, scopeY, scopeSize, scopeSize);
    if (scopeArea.getBottom() > inner.getBottom())
        scopeArea.setBottom(inner.getBottom());

    juce::Rectangle<float> balanceArea(scopeArea.getX(), scopeArea.getBottom() + 6.0f,
                                       scopeArea.getWidth(), inner.getBottom() - (scopeArea.getBottom() + 6.0f));
    if (balanceArea.getHeight() < 12.0f)
    {
        balanceArea.setHeight(12.0f);
        balanceArea.setY(scopeArea.getBottom() + 6.0f);
        if (balanceArea.getBottom() > bounds.getBottom() - 6.0f)
            balanceArea.setBottom(bounds.getBottom() - 6.0f);
    }
    if (balanceArea.getHeight() <= 0.0f)
        balanceArea = {};

    const auto centre = scopeArea.getCentre();
    const float radius = scopeArea.getWidth() * 0.5f;
    const bool showXY = displayAsXY;

    // Grid
    g.setColour(DarkTheme::border.withAlpha(0.22f));
    g.drawEllipse(scopeArea, 1.0f);
    g.drawLine(scopeArea.getCentreX(), scopeArea.getY(), scopeArea.getCentreX(), scopeArea.getBottom(), 0.6f);
    g.drawLine(scopeArea.getX(), scopeArea.getCentreY(), scopeArea.getRight(), scopeArea.getCentreY(), 0.6f);
    g.drawLine(scopeArea.getX(), scopeArea.getBottom(), scopeArea.getRight(), scopeArea.getY(), 0.5f);
    g.drawLine(scopeArea.getX(), scopeArea.getY(), scopeArea.getRight(), scopeArea.getBottom(), 0.5f);

    std::vector<juce::Point<float>> samplesCopy;
    float localCorr = 0.0f;
    bool localHasCorr = false;
    float localCorrSmoothed = 0.0f;
    float localBalance = 0.0f;
    bool localHasBalance = false;
    float localBalanceSmoothed = 0.0f;
    {
        std::lock_guard<std::mutex> lock(dataMutex);
        samplesCopy = displaySamples;
        localCorr = correlation;
        localHasCorr = hasCorrelation;
        localCorrSmoothed = correlationSmoothed;
        localBalance = balance;
        localHasBalance = hasBalance;
        localBalanceSmoothed = balanceSmoothed;
    }

    if (!localHasBalance)
        localBalanceSmoothed = 0.0f;

    if (!samplesCopy.empty())
    {
        float maxComponent = 0.0f;
        for (const auto& sample : samplesCopy)
            maxComponent = std::max(maxComponent, std::max(std::abs(sample.x), std::abs(sample.y)));

        const float normalise = (maxComponent > 1.0f) ? 1.0f / maxComponent : 1.0f;

        const auto toScreen = [centre, radius, showXY](juce::Point<float> sample) noexcept -> juce::Point<float>
        {
            juce::Point<float> mapped = sample;
            if (!showXY)
            {
                const float mid = sample.y;
                const float side = sample.x;
                constexpr float invSqrt2 = 0.70710678f;
                mapped.x = (mid - side) * invSqrt2;
                mapped.y = (mid + side) * invSqrt2;
            }

            const float x = juce::jlimit(-1.2f, 1.2f, -mapped.x);
            const float y = juce::jlimit(-1.2f, 1.2f, mapped.y);
            return {
                centre.x + x * radius,
                centre.y - y * radius
            };
        };

        auto scaleSample = [normalise](juce::Point<float> sample) noexcept
        {
            return juce::Point<float>(sample.x * normalise, sample.y * normalise);
        };

        juce::Point<float> previous = toScreen(scaleSample(samplesCopy.front()));
        for (size_t i = 1; i < samplesCopy.size(); ++i)
        {
            auto current = toScreen(scaleSample(samplesCopy[i]));
            const float age = static_cast<float>(i) / static_cast<float>(samplesCopy.size());
            const float alpha = juce::jlimit(0.04f, 0.75f, std::pow(std::max(age, 0.0001f), 0.8f));
            g.setColour(DarkTheme::accentSecondary.brighter(0.15f).withAlpha(alpha));
            g.drawLine({previous.x, previous.y, current.x, current.y}, 1.0f);
            previous = current;
        }
    }
    else
    {
        g.setColour(DarkTheme::textMuted.withAlpha(0.35f));
        g.drawFittedText("no signal", scopeArea.toNearestInt(), juce::Justification::centred, 1);
    }

    // Etiquetas de referencia
    auto drawLabel = [&](const juce::String& text, juce::Rectangle<float> area, juce::Justification just, float alpha = 0.6f)
    {
        g.setColour(DarkTheme::textSecondary.withAlpha(alpha));
        g.drawFittedText(text, area.toNearestInt(), just, 1);
    };

    const float diagOffset = scopeArea.getWidth() * 0.32f;

    if (showXY)
    {
        drawLabel("L", juce::Rectangle<float>(28.0f, 14.0f).withCentre({centre.x - diagOffset, centre.y - diagOffset}), juce::Justification::centred, 0.65f);
        drawLabel("R", juce::Rectangle<float>(28.0f, 14.0f).withCentre({centre.x + diagOffset, centre.y - diagOffset}), juce::Justification::centred, 0.65f);
        drawLabel("+S", juce::Rectangle<float>(30.0f, 16.0f).withCentre({centre.x - radius + 18.0f, centre.y}), juce::Justification::centred, 0.6f);
        drawLabel("-S", juce::Rectangle<float>(30.0f, 16.0f).withCentre({centre.x + radius - 18.0f, centre.y}), juce::Justification::centred, 0.6f);
        drawLabel("+M", juce::Rectangle<float>(32.0f, 14.0f).withCentre({centre.x, centre.y - radius + 16.0f}), juce::Justification::centred, 0.65f);
        drawLabel("-M", juce::Rectangle<float>(32.0f, 14.0f).withCentre({centre.x, centre.y + radius - 16.0f}), juce::Justification::centred, 0.6f);
    }
    else
    {
        drawLabel("M+", juce::Rectangle<float>(32.0f, 14.0f).withCentre({centre.x - diagOffset, centre.y - diagOffset}), juce::Justification::centred, 0.65f);
        drawLabel("M-", juce::Rectangle<float>(32.0f, 14.0f).withCentre({centre.x + diagOffset, centre.y + diagOffset}), juce::Justification::centred, 0.65f);
        drawLabel("+S", juce::Rectangle<float>(30.0f, 16.0f).withCentre({centre.x + diagOffset, centre.y - diagOffset}), juce::Justification::centred, 0.6f);
        drawLabel("-S", juce::Rectangle<float>(30.0f, 16.0f).withCentre({centre.x - diagOffset, centre.y + diagOffset}), juce::Justification::centred, 0.6f);
    }

    // Indicador horizontal de balance L/R
    if (!balanceArea.isEmpty())
    {
        auto balanceBounds = balanceArea.reduced(8.0f, 4.0f);
        if (balanceBounds.getWidth() > 0.0f && balanceBounds.getHeight() > 0.0f)
        {
            const float trackY = balanceBounds.getCentreY();
            g.setColour(juce::Colours::white.withAlpha(0.12f));
            g.drawLine(balanceBounds.getX(), trackY, balanceBounds.getRight(), trackY, 1.0f);

            const float mappedX = juce::jmap(localBalanceSmoothed, -1.0f, 1.0f,
                                             balanceBounds.getX(), balanceBounds.getRight());
            juce::Rectangle<float> balanceIndicator(mappedX - 11.0f, trackY - 0.6f, 22.0f, 1.2f);
            g.setColour(juce::Colours::white.withAlpha(0.85f));
            g.fillRoundedRectangle(balanceIndicator, 0.8f);

            g.setColour(DarkTheme::textSecondary.withAlpha(0.5f));

            float labelY = trackY + 6.0f;
            if (labelY + 10.0f > balanceBounds.getBottom())
                labelY = balanceBounds.getY() - 12.0f;

            auto leftLabelArea = juce::Rectangle<float>(balanceBounds.getX() - 4.0f, labelY, 30.0f, 10.0f);
            auto rightLabelArea = juce::Rectangle<float>(balanceBounds.getRight() - 26.0f, labelY, 30.0f, 10.0f);

            g.drawFittedText("L", leftLabelArea.toNearestInt(), juce::Justification::centred, 1);
            g.drawFittedText("R", rightLabelArea.toNearestInt(), juce::Justification::centred, 1);
        }
    }

    // Indicador vertical de correlación
    auto sliderArea = corrArea.reduced(8.0f, 20.0f);
    if (sliderArea.getHeight() <= 0.0f)
        sliderArea.setHeight(1.0f);
    if (sliderArea.getWidth() <= 0.0f)
        sliderArea.setWidth(1.0f);

    const float trackX = sliderArea.getCentreX();
    g.setColour(juce::Colours::white.withAlpha(0.12f));
    g.drawLine(trackX, sliderArea.getY(), trackX, sliderArea.getBottom(), 1.0f);

    const float mappedY = juce::jmap(localCorrSmoothed, 1.0f, -1.0f, sliderArea.getY(), sliderArea.getBottom());
    juce::Rectangle<float> indicator(trackX - 0.6f, mappedY - 11.0f, 1.2f, 22.0f);
    g.setColour(juce::Colours::white.withAlpha(0.85f));
    g.fillRoundedRectangle(indicator, 0.8f);

    auto labelColour = DarkTheme::textSecondary.withAlpha(0.5f);
    g.setColour(labelColour);

    auto mapValueToY = [&](float value)
    {
        return juce::jmap(value, 1.0f, -1.0f, sliderArea.getY(), sliderArea.getBottom());
    };

    auto topLabelArea = juce::Rectangle<float>(trackX - 30.0f, sliderArea.getY() - 12.0f, 24.0f, 10.0f);
    g.drawFittedText("+1", topLabelArea.toNearestInt(), juce::Justification::centredRight, 1);

    auto midY = mapValueToY(0.0f);
    auto midLabelArea = juce::Rectangle<float>(trackX - 30.0f, midY - 5.0f, 24.0f, 10.0f);
    g.drawFittedText("0", midLabelArea.toNearestInt(), juce::Justification::centredRight, 1);

    auto bottomLabelArea = juce::Rectangle<float>(trackX - 30.0f, sliderArea.getBottom() - 10.0f, 24.0f, 10.0f);
    g.drawFittedText("-1", bottomLabelArea.toNearestInt(), juce::Justification::centredRight, 1);

    juce::ignoreUnused(localHasCorr, localCorr, localHasBalance, localBalance);
}

void GoniometerComponent::resized()
{
    // Nada adicional: se recalcula todo en paint()
}
