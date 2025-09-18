#include "SpectrumAnalyzerComponent.h"

SpectrumAnalyzerComponent::SpectrumAnalyzerComponent(juce::AudioProcessorValueTreeState& apvts)
    : valueTreeState(apvts),
      forwardFFT(fftOrder),
      window(fftSize, juce::dsp::WindowingFunction<float>::hann)
{
    // Inicializar buffers (diseño lock-free)
    fifoL.fill(0.0f); fifoR.fill(0.0f);
    fftCopyL.fill(0.0f); fftCopyR.fill(0.0f);
    fftData.fill(0.0f);
    scopeDataL.fill(0.0f); scopeDataR.fill(0.0f);
    copyScopeDataL.fill(0.0f); copyScopeDataR.fill(0.0f);
    peakHoldDataL.fill(0.0f); peakHoldDataR.fill(0.0f);
    
    // Añadir listeners para parámetros del crossover (Imager)
    apvts.addParameterListener("a_FREQ1", this);    // XLow frequency
    apvts.addParameterListener("b_FREQ2", this);    // XHigh frequency
    
    // Inicializar valores desde APVTS
    if (auto* param = apvts.getRawParameterValue("a_FREQ1"))
        crossoverLowFreq.store(param->load());
    if (auto* param = apvts.getRawParameterValue("b_FREQ2"))
        crossoverHighFreq.store(param->load());

    // En Imager no hay toggle de filtros ni selector de banda; mantenerlos activos por defecto
    filtersEnabled.store(true);
    selectedBand.store(1.0f);
    tiltValue.store(0.0f);
    
    // Iniciar timer para actualizaciones de display (30 FPS estable)
    startTimerHz(30);
    
    setOpaque(false);
}

SpectrumAnalyzerComponent::~SpectrumAnalyzerComponent()
{
    // Establecer flag de destrucción PRIMERO para prevenir nuevo procesamiento de audio
    isDestroying.store(true, std::memory_order_release);
    
    // Detener timer ANTES de destruir cualquier dato
    stopTimer();
    
    // Remover listeners de parámetros
    valueTreeState.removeParameterListener("a_FREQ1", this);
    valueTreeState.removeParameterListener("b_FREQ2", this);
    
    // Pequeña demora para asegurar que callbacks de audio en curso terminen
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

void SpectrumAnalyzerComponent::setSampleRate(double newSampleRate) noexcept
{
    currentSampleRate.store(newSampleRate);
}

void SpectrumAnalyzerComponent::pushNextSampleIntoFifo(float sample) noexcept
{
    // Verificar si el componente está siendo destruido - abortar inmediatamente
    if (isDestroying.load(std::memory_order_acquire))
        return;
    
    // Implementación lock-free para thread de audio - NUNCA USAR MUTEX
    auto currentIndex = fifoIndex.load(std::memory_order_relaxed);
    
    if (currentIndex >= 0 && currentIndex < fftSize)
    {
        fifoL[(size_t)currentIndex] = sample;
        fifoR[(size_t)currentIndex] = sample; // mono compat: duplicar a R
    }
    auto newIndex = currentIndex + 1;
    if (newIndex >= fftSize)
    {
        // Bloque listo, intentar establecer flag atómicamente con ordenamiento de memoria correcto
        bool expected = false;
        if (nextFFTBlockReady.compare_exchange_weak(expected, true, std::memory_order_release, std::memory_order_relaxed))
        {
            // Copy lock-free de ambos canales
            std::copy(fifoL.begin(), fifoL.end(), fftCopyL.begin());
            std::copy(fifoR.begin(), fifoR.end(), fftCopyR.begin());
        }
        newIndex = 0;
    }
    
    fifoIndex.store(newIndex, std::memory_order_relaxed);
}

void SpectrumAnalyzerComponent::pushNextStereoSample(float left, float right) noexcept
{
    if (isDestroying.load(std::memory_order_acquire)) return;
    auto currentIndex = fifoIndex.load(std::memory_order_relaxed);
    if (currentIndex >= 0 && currentIndex < fftSize)
    {
        fifoL[(size_t)currentIndex] = left;
        fifoR[(size_t)currentIndex] = right;
    }
    auto newIndex = currentIndex + 1;
    if (newIndex >= fftSize)
    {
        bool expected = false;
        if (nextFFTBlockReady.compare_exchange_weak(expected, true, std::memory_order_release, std::memory_order_relaxed))
        {
            std::copy(fifoL.begin(), fifoL.end(), fftCopyL.begin());
            std::copy(fifoR.begin(), fifoR.end(), fftCopyR.begin());
        }
        newIndex = 0;
    }
    fifoIndex.store(newIndex, std::memory_order_relaxed);
}

void SpectrumAnalyzerComponent::timerCallback()
{
    // Verificar si el componente está siendo destruido
    if (isDestroying.load(std::memory_order_acquire))
        return;
    
    // Verificar si hay nuevos datos FFT listos usando operación atómica con ordenamiento de memoria correcto
    bool expected = true;
    if (nextFFTBlockReady.compare_exchange_weak(expected, false, std::memory_order_acquire, std::memory_order_relaxed))
    {
        // Flag adquirido exitosamente, copiar de buffer intermedio a buffer de procesamiento
        {
            std::lock_guard<std::mutex> lock(guiMutex);
            juce::zeromem(fftData.data(), sizeof(fftData));
        }
        
        // Procesar L y R
        drawNextFrameOfSpectrum(scopeDataL, peakHoldDataL, fftCopyL);
        drawNextFrameOfSpectrum(scopeDataR, peakHoldDataR, fftCopyR);
        
        {
            std::lock_guard<std::mutex> lock(guiMutex);
            std::copy(scopeDataL.begin(), scopeDataL.end(), copyScopeDataL.begin());
            std::copy(scopeDataR.begin(), scopeDataR.end(), copyScopeDataR.begin());
            scopeDataReady.store(true, std::memory_order_release);
        }
        
        repaint();
    }
}

void SpectrumAnalyzerComponent::drawNextFrameOfSpectrum(std::array<float, scopeSize>& scopeData,
                                                        std::array<float, scopeSize>& peakHoldData,
                                                        const std::array<float, fftSize>& fftCopySrc)
{
    // Procesar datos FFT (mutex ya manejado en timerCallback)
    // Aplicar función de ventana
    {
        std::lock_guard<std::mutex> lock(guiMutex);
        std::copy(fftCopySrc.begin(), fftCopySrc.end(), fftData.begin());
    }
    window.multiplyWithWindowingTable(fftData.data(), fftSize);
    
    // Ejecutar FFT
    forwardFFT.performFrequencyOnlyForwardTransform(fftData.data());
    
    // Rango dinámico de display del espectro basado en estado de zoom
    auto mindB = zoomEnabled.load() ? zoomedMinDB : defaultMinDB;
    auto maxdB = zoomEnabled.load() ? zoomedMaxDB : defaultMaxDB;
    
    for (int i = 0; i < scopeSize; ++i)
    {
        
        // Mapeo de frecuencia de 3 segmentos con mejor simetría visual
        // 250Hz al 17.5%, 1kHz al 50%, mejor distribución visual
        float normalizedPosition = (float)i / (float)scopeSize;
        
        const float log20 = std::log10(20.0f);
        const float log250 = std::log10(250.0f);
        const float log1k = std::log10(1000.0f);
        const float log20k = std::log10(20000.0f);
        
        float logFreq;
        if (normalizedPosition <= 0.25f) {
            // Primer segmento: 0-25% mapea a 20Hz-250Hz
            logFreq = log20 + (normalizedPosition / 0.25f) * (log250 - log20);
        } else if (normalizedPosition <= 0.5f) {
            // Segundo segmento: 25%-50% mapea a 250Hz-1kHz
            logFreq = log250 + ((normalizedPosition - 0.25f) / 0.25f) * (log1k - log250);
        } else {
            // Tercer segmento: 50%-100% mapea a 1kHz-20kHz
            logFreq = log1k + ((normalizedPosition - 0.5f) / 0.5f) * (log20k - log1k);
        }
        float freq = std::pow(10.0f, logFreq);
        
        // Convertir frecuencia a índice de bin FFT usando sample rate dinámico
        auto sampleRate = currentSampleRate.load();
        
        // Verificación de límites por seguridad
        if (sampleRate <= 0.0)
        {
            continue; // Saltar sample rate inválido
        }
        
        auto exactBinIndex = freq * (float)fftSize / (float)sampleRate;
        
        // Lógica de interpolación inteligente para frecuencias bajas
        int binIndex1, binIndex2;
        float fraction;
        
        if (exactBinIndex < 1.0f)
        {
            // Debajo del bin 1: sin datos espectrales válidos (bajo resolución de frecuencia fundamental)
            binIndex1 = 1;
            binIndex2 = 1;
            fraction = 0.0f;  // Usar valor de bin 1 sin interpolación
        }
        else if (exactBinIndex < 2.0f)
        {
            // Entre bins 1 y 2: interpolación correcta en rango fundamental
            binIndex1 = 1;
            binIndex2 = 2;
            fraction = exactBinIndex - 1.0f;
        }
        else
        {
            // Caso normal: interpolación estándar para frecuencias más altas
            binIndex1 = (int)exactBinIndex;
            binIndex2 = binIndex1 + 1;
            fraction = exactBinIndex - (float)binIndex1;
            
            // Límites estándar para frecuencias más altas
            binIndex1 = juce::jlimit(1, (int)(fftSize / 2 - 2), binIndex1);
            binIndex2 = juce::jlimit(2, (int)(fftSize / 2 - 1), binIndex2);
        }
        
        // Acceso seguro a array con verificación de límites
        auto magnitude1 = 0.0f;
        auto magnitude2 = 0.0f;
        
        if (binIndex1 >= 1 && binIndex1 < (fftSize / 2))
        {
            magnitude1 = fftData[binIndex1];
        }
        if (binIndex2 >= 1 && binIndex2 < (fftSize / 2))
        {
            magnitude2 = fftData[binIndex2];
        }
        
        // Interpolación mejorada: precisión dependiente de frecuencia para mejor detalle en agudos
        float interpolatedMagnitude;
        
        if (binIndex1 == binIndex2) 
        {
            interpolatedMagnitude = magnitude1;
        }
        else if (freq >= 2000.0f && magnitude1 > 1e-8f && magnitude2 > 1e-8f)  
        {
            // Precisión en altas frecuencias: usar interpolación geométrica para mejor precisión en agudos
            auto logMag1 = std::log(magnitude1 + 1e-10f);
            auto logMag2 = std::log(magnitude2 + 1e-10f);
            auto logInterpolated = logMag1 + fraction * (logMag2 - logMag1);
            interpolatedMagnitude = std::exp(logInterpolated);
        }
        else 
        {
            // Interpolación lineal estándar para frecuencias más bajas
            interpolatedMagnitude = magnitude1 + fraction * (magnitude2 - magnitude1);
        }
        
        // Calcular nivel en dB con normalización FFT correcta y corrección de ventana
        auto clampedMagnitude = juce::jmax(interpolatedMagnitude, 1e-10f);
        
        // Normalización correcta de magnitud FFT: -20*log10(fftSize/2) en lugar de -20*log10(fftSize)
        // Esto corrige el error de ~6dB en el cálculo anterior
        auto fftNormalizationdB = 20.0f * std::log10((float)fftSize / 2.0f);
        
        // Corrección de ventana Hann: ELIMINADA - causaba offset de +6dB vs analizadores profesionales
        // auto hannWindowCorrection = 6.0f;  // DESHABILITADO: causa exceso de +6dB
        
        auto dbValue = juce::Decibels::gainToDecibels(clampedMagnitude) - fftNormalizationdB;  // Sin corrección de ventana
        
        // Usar valores dB crudos sin NINGUNA compensación de frecuencia para espectro natural
        auto clampedDbValue = juce::jlimit(mindB, maxdB, dbValue);
        
        // Convertir dB a posición de display (0.0 = abajo, 1.0 = arriba)
        // Esto da escalado logarítmico correcto donde -24dB aparece en el medio
        auto level = (clampedDbValue - mindB) / (maxdB - mindB);
        
        // Suavizado adaptativo dependiente de frecuencia para mejor visibilidad en agudos
        auto difference = std::abs(level - scopeData[i]);
        
        // Determinar factor de suavizado basado en frecuencia
        float baseSmoothingFactor;
        if (freq >= 4000.0f)  // Frecuencias altas (4kHz+): Menos suavizado, preservar transitorios
        {
            baseSmoothingFactor = 0.35f;  // Mayor respuesta para detalle en agudos
        }
        else if (freq >= 1000.0f)  // Frecuencias medias (1-4kHz): Suavizado moderado
        {
            baseSmoothingFactor = 0.25f;  // Suavizado balanceado
        }
        else  // Frecuencias bajas (<1kHz): Más suavizado para estabilidad
        {
            baseSmoothingFactor = 0.15f;  // Más estabilidad en graves
        }
        
        auto adaptiveSmoothing = juce::jlimit(0.1f, 0.5f, baseSmoothingFactor + difference * 0.3f);
        scopeData[i] = scopeData[i] * (1.0f - adaptiveSmoothing) + level * adaptiveSmoothing;
        
        // Actualizar datos de peak hold (thread-safe)
        if (level > peakHoldData[i])
        {
            peakHoldData[i] = level;
            peakHoldCounter.store(0);  // Reiniciar contador atómicamente cuando se encuentra nuevo pico
        }
    }
    
    // Decaimiento de peak hold dependiente de frecuencia con contador atómico
    auto currentCounter = peakHoldCounter.fetch_add(1);
    if (currentCounter > peakHoldFrames)
    {
        for (int i = 0; i < scopeSize; ++i)
        {
            {
                // Calcular frecuencia para este punto de display para tasa de decaimiento
                float normalizedPosition = (float)i / (float)scopeSize;
                const float log20 = std::log10(20.0f);
                const float log250 = std::log10(250.0f);
                const float log1k = std::log10(1000.0f);
                const float log20k = std::log10(20000.0f);
                
                float logFreq;
                if (normalizedPosition <= 0.25f) {
                    logFreq = log20 + (normalizedPosition / 0.25f) * (log250 - log20);
                } else if (normalizedPosition <= 0.5f) {
                    logFreq = log250 + ((normalizedPosition - 0.25f) / 0.25f) * (log1k - log250);
                } else {
                    logFreq = log1k + ((normalizedPosition - 0.5f) / 0.5f) * (log20k - log1k);
                }
                auto freq = std::pow(10.0f, logFreq);
                
                // Tasa de decaimiento dependiente de frecuencia: agudos se mantienen más, graves decaen más rápido
                float decayRate;
                if (freq >= 2000.0f)  // Frecuencias altas: decaimiento más lento para visibilidad
                {
                    decayRate = 0.985f;  // Decaimiento lento preserva picos de agudos más tiempo
                }
                else if (freq >= 500.0f)  // Frecuencias medias: decaimiento moderado
                {
                    decayRate = 0.98f;   // Decaimiento estándar
                }
                else  // Frecuencias bajas: decaimiento más rápido para display más limpio
                {
                    decayRate = 0.975f;  // Decaimiento rápido previene acumulación en graves
                }
                
                peakHoldData[i] *= decayRate;
            }
        }
    }
}

void SpectrumAnalyzerComponent::paint(juce::Graphics& g)
{
    drawFrame(g, getLocalBounds());
}

// Helper function para mapeo de frecuencia a posición X (movida fuera de drawFrame para reutilización)
float SpectrumAnalyzerComponent::mapFrequencyToX(float freq, float width) const noexcept
{
    const float log20 = std::log10(20.0f);
    const float log250 = std::log10(250.0f);
    const float log1k = std::log10(1000.0f);
    const float log20k = std::log10(20000.0f);
    
    float position;
    if (freq <= 250.0f) {
        // Primer segmento: 20Hz-250Hz mapea a 0-0.25 (25%)
        position = (std::log10(freq) - log20) / (log250 - log20) * 0.25f;
    } else if (freq <= 1000.0f) {
        // Segundo segmento: 250Hz-1kHz mapea a 0.25-0.5 (25%)
        position = 0.25f + (std::log10(freq) - log250) / (log1k - log250) * 0.25f;
    } else {
        // Tercer segmento: 1kHz-20kHz mapea a 0.5-1.0 (50%)
        position = 0.5f + (std::log10(freq) - log1k) / (log20k - log1k) * 0.5f;
    }
    return width * position;
}

// Helper function para mapeo inverso: posición X a frecuencia
float SpectrumAnalyzerComponent::mapXToFrequency(float xPos, float width) const noexcept
{
    const float log20 = std::log10(20.0f);
    const float log250 = std::log10(250.0f);
    const float log1k = std::log10(1000.0f);
    const float log20k = std::log10(20000.0f);
    
    float normalizedPos = xPos / width;
    normalizedPos = juce::jlimit(0.0f, 1.0f, normalizedPos);
    
    float logFreq;
    if (normalizedPos <= 0.25f) {
        // Inverso del primer segmento: 0-0.25 mapea a 20Hz-250Hz
        logFreq = log20 + (normalizedPos / 0.25f) * (log250 - log20);
    } else if (normalizedPos <= 0.5f) {
        // Inverso del segundo segmento: 0.25-0.5 mapea a 250Hz-1kHz
        logFreq = log250 + ((normalizedPos - 0.25f) / 0.25f) * (log1k - log250);
    } else {
        // Inverso del tercer segmento: 0.5-1.0 mapea a 1kHz-20kHz
        logFreq = log1k + ((normalizedPos - 0.5f) / 0.5f) * (log20k - log1k);
    }
    
    return std::pow(10.0f, logFreq);
}

void SpectrumAnalyzerComponent::drawFrame(juce::Graphics& g, const juce::Rectangle<int>& bounds)
{
    // Helper lambda local que usa la función miembro
    auto mapFrequencyToX = [this](float freq, float width) -> float {
        return this->mapFrequencyToX(freq, width);
    };
    
    // Fondo oscuro
    g.fillAll(juce::Colour(0x001a1a1a));
    
    // === COLORES DE FONDO DEL CROSSOVER ===
    // Dibujar antes del espectro para que quede de fondo
    if (filtersEnabled.load())
    {
        // Obtener frecuencias y banda seleccionada
        float xLowFreq = crossoverLowFreq.load();
        float xHighFreq = crossoverHighFreq.load();
        float bandValue = selectedBand.load();
        
        // Calcular posiciones X usando mapeo bilineal
        auto xLowPixel = mapFrequencyToX(xLowFreq, bounds.getWidth());
        auto xHighPixel = mapFrequencyToX(xHighFreq, bounds.getWidth());
        
        // Colores base para cada banda (muy sutiles)
        const float baseAlpha = 0.03f;
        const float glowAlpha = 0.08f;  // Alpha adicional para banda seleccionada
        
        // Calcular intensidad de glow para cada banda basado en interpolación
        float lowGlow = 0.0f;
        float midGlow = 0.0f;
        float highGlow = 0.0f;
        
        if (bandValue <= 1.0f) {
            // Interpolación entre Low (0) y Mid (1)
            lowGlow = 1.0f - bandValue;
            midGlow = bandValue;
        } else {
            // Interpolación entre Mid (1) y High (2)
            midGlow = 2.0f - bandValue;
            highGlow = bandValue - 1.0f;
        }
        
        // Obtener banda en hover para brillo adicional
        int hoveredBand = hoveringBandIndex.load();
        const float hoverAlpha = 0.04f; // Alpha adicional para hover
        
        // Banda Low (púrpura - graves)
        float lowAlpha = baseAlpha + (lowGlow * glowAlpha);
        if (hoveredBand == 0) lowAlpha += hoverAlpha; // Añadir brillo si está en hover
        juce::Colour lowColour = juce::Colour(0xFF9C27B0).withAlpha(lowAlpha);
        g.setColour(lowColour);
        g.fillRect(0.0f, 0.0f, xLowPixel, (float)bounds.getHeight());
        
        // Banda Mid (intermedio púrpura-azul)
        float midAlpha = baseAlpha + (midGlow * glowAlpha);
        if (hoveredBand == 1) midAlpha += hoverAlpha; // Añadir brillo si está en hover
        juce::Colour midColour = juce::Colour(0xFF9C27B0).interpolatedWith(juce::Colour(0xFF2196F3), 0.5f).withAlpha(midAlpha);
        g.setColour(midColour);
        g.fillRect(xLowPixel, 0.0f, xHighPixel - xLowPixel, (float)bounds.getHeight());
        
        // Banda High (azul - agudos)
        float highAlpha = baseAlpha + (highGlow * glowAlpha);
        if (hoveredBand == 2) highAlpha += hoverAlpha; // Añadir brillo si está en hover
        juce::Colour highColour = juce::Colour(0xFF2196F3).withAlpha(highAlpha);
        g.setColour(highColour);
        g.fillRect(xHighPixel, 0.0f, (float)bounds.getWidth() - xHighPixel, (float)bounds.getHeight());
    }
    
    // === VISUALIZACIÓN DEL TILT ===
    // Dibujar gradiente de color según el valor del tilt
    float tilt = tiltValue.load();
    if (std::abs(tilt) > 0.1f)  // Solo si tilt es significativo
    {
        // Posición de 1kHz (centro del tilt)
        auto x1k = mapFrequencyToX(1000.0f, bounds.getWidth());
        
        if (tilt > 0)  // Más agudos (azul/púrpura)
        {
            // Gradiente de transparente a azul-púrpura hacia la derecha
            juce::ColourGradient tiltGradient(
                juce::Colours::transparentBlack,
                x1k, 0,
                juce::Colour(0xFF2196F3).withAlpha(0.05f + 0.1f * std::abs(tilt) / 6.0f),
                bounds.getWidth(), 0,
                false
            );
            g.setGradientFill(tiltGradient);
            g.fillRect(x1k, 0.0f, bounds.getWidth() - x1k, (float)bounds.getHeight());
        }
        else  // Más graves (púrpura)
        {
            // Gradiente de púrpura a transparente hacia la derecha
            juce::ColourGradient tiltGradient(
                juce::Colour(0xFF8434AD).withAlpha(0.05f + 0.1f * std::abs(tilt) / 6.0f),
                0, 0,
                juce::Colours::transparentBlack,
                x1k, 0,
                false
            );
            g.setGradientFill(tiltGradient);
            g.fillRect(0.0f, 0.0f, x1k, (float)bounds.getHeight());
        }
    }
    
    // Dibujar línea de espectro con codificación de color basada en frecuencia (dos canales)
    if (!bypassMode.load())
    {
        auto width = bounds.getWidth();
        auto height = bounds.getHeight();
        
        // Paths L y R
        juce::Path pathL, pathR;
        if (scopeDataReady.load(std::memory_order_acquire))
        {
            for (int i = 0; i < scopeSize; ++i)
            {
                float x = juce::jmap((float)i, 0.0f, (float)scopeSize, 0.0f, (float)width);
                float yL = juce::jmap(copyScopeDataL[i], 0.0f, 1.0f, (float)height, 0.0f);
                float yR = juce::jmap(copyScopeDataR[i], 0.0f, 1.0f, (float)height, 0.0f);
                yL = juce::jlimit(0.0f, (float)height, yL);
                yR = juce::jlimit(0.0f, (float)height, yR);
                if (i == 0) { pathL.startNewSubPath(x, yL); pathR.startNewSubPath(x, yR); }
                else { pathL.lineTo(x, yL); pathR.lineTo(x, yR); }
            }
        }
        g.setColour(juce::Colour(0xFF9C27B0).withAlpha(0.9f));
        g.strokePath(pathL, juce::PathStrokeType(1.6f));
        g.setColour(juce::Colour(0xFF2196F3).withAlpha(0.9f));
        g.strokePath(pathR, juce::PathStrokeType(1.6f));
    }
    
    // Dibujar grilla
    g.setColour(juce::Colours::white.withAlpha(0.1f));
    
    // Grilla logarítmica con espaciado correcto
    std::vector<float> gridFrequencies = {50.0f, 100.0f, 250.0f, 500.0f, 1000.0f, 2000.0f, 5000.0f, 10000.0f};
    
    for (float freq : gridFrequencies)
    {
        // Calcular posición usando mapeo bilineal (igual que datos del espectro)
        auto x = mapFrequencyToX(freq, bounds.getWidth());
        g.drawVerticalLine(x, 0.0f, (float)bounds.getHeight());
    }
    
    // Líneas horizontales de amplitud dinámicas basadas en estado de zoom
    auto currentMinDB = zoomEnabled.load() ? zoomedMinDB : defaultMinDB;
    auto currentMaxDB = zoomEnabled.load() ? zoomedMaxDB : defaultMaxDB;
    
    // Elegir líneas de grilla basadas en nivel de zoom
    std::vector<float> gridAmplitudes;
    if (zoomEnabled.load())
    {
        // Modo con zoom: enfoque en niveles más altos
        gridAmplitudes = {-6.0f, -12.0f, -18.0f, -24.0f, -30.0f, -36.0f, -42.0f};
    }
    else
    {
        // Modo rango completo: cobertura más amplia
        gridAmplitudes = {-6.0f, -12.0f, -18.0f, -24.0f, -36.0f, -48.0f, -60.0f};
    }
    
    for (float ampDB : gridAmplitudes)
    {
        // Calcular posición usando rango dinámico actual
        float position = (ampDB - currentMinDB) / (currentMaxDB - currentMinDB);
        auto y = bounds.getHeight() * (1.0f - position); // Invertir Y (0 = arriba)
        
        // Solo dibujar si está dentro de los límites del rango actual
        if (ampDB >= currentMinDB && ampDB <= currentMaxDB && y >= 0.0f && y <= bounds.getHeight())
        {
            g.drawHorizontalLine(y, 0.0f, (float)bounds.getWidth());
        }
    }
    
    // Etiquetas
    g.setColour(juce::Colours::white.withAlpha(0.6f));
    g.setFont(9.0f);
    
    // Etiquetas de frecuencia en líneas clave de grilla (espaciado logarítmico)
    std::vector<std::pair<float, juce::String>> frequencyLabels = {
        {100.0f, "100"},
        {250.0f, "250"},
        {500.0f, "500"},
        {1000.0f, "1k"},
        {2000.0f, "2k"},
        {5000.0f, "5k"},
        {10000.0f, "10k"}
    };
    
    for (auto& label : frequencyLabels)
    {
        float freq = label.first;
        juce::String text = label.second;
        
        // Calcular posición usando mapeo bilineal (igual que datos del espectro)
        auto x = mapFrequencyToX(freq, bounds.getWidth());
        g.drawText(text, x - 15, bounds.getBottom() - 15, 30, 12, juce::Justification::centred);
    }
    
    // Etiquetas de rango (esquinas)
    g.setFont(8.0f);
    g.drawText("50Hz", bounds.getX() + 22, bounds.getBottom() - 15, 25, 12, juce::Justification::left);
    g.drawText("20kHz", bounds.getRight() - 27, bounds.getBottom() - 15, 25, 12, juce::Justification::right);
    
    // Etiquetas de amplitud dinámicas basadas en estado de zoom actual
    g.setFont(8.0f);
    
    // Usar mismas amplitudes de grilla que las líneas
    for (float ampDB : gridAmplitudes)
    {
        // Calcular posición Y usando rango dinámico actual
        float position = (ampDB - currentMinDB) / (currentMaxDB - currentMinDB);
        auto y = bounds.getHeight() * (1.0f - position); // Invertir Y (0 = arriba)
        
        // Solo dibujar etiqueta si está dentro del rango actual y límites de pantalla
        if (ampDB >= currentMinDB && ampDB <= currentMaxDB && 
            y >= 12.0f && y <= bounds.getHeight() - 12.0f)
        {
            juce::String dbText = juce::String((int)ampDB);
            g.drawText(dbText, bounds.getX() + 2, y - 6, 20, 12, juce::Justification::right);
        }
    }
    
    // Etiquetas dinámicas de dB superior e inferior basadas en rango actual
    g.drawText(juce::String((int)currentMaxDB), bounds.getX() + 2, bounds.getY() + 2, 20, 12, juce::Justification::right);
    g.drawText(juce::String((int)currentMinDB), bounds.getX() + 2, bounds.getBottom() - 25, 20, 12, juce::Justification::right);
    
    // Etiquetas de amplitud en el lado derecho (simetría visual)
    for (float ampDB : gridAmplitudes)
    {
        float position = (ampDB - currentMinDB) / (currentMaxDB - currentMinDB);
        auto y = bounds.getHeight() * (1.0f - position);
        
        if (ampDB >= currentMinDB && ampDB <= currentMaxDB && 
            y >= 12.0f && y <= bounds.getHeight() - 12.0f)
        {
            juce::String dbText = juce::String((int)ampDB);
            int xOffset;
            if (dbText.length() == 1) {
                xOffset = 16;  // Para "0"
            } else if (dbText == "-6") {
                xOffset = 19;  // Ajuste especial para "-6"
            } else {
                xOffset = 22;  // Para "-12", "-24", etc.
            }
            g.drawText(dbText, bounds.getRight() - xOffset, y - 6, 20, 12, juce::Justification::left);
        }
    }
    
    // Etiquetas superior e inferior en el lado derecho
    juce::String topText = juce::String((int)currentMaxDB);
    juce::String bottomText = juce::String((int)currentMinDB);
    int topOffset = (topText.length() == 1) ? 16 : (topText == "-6" ? 19 : 22);
    int bottomOffset = (bottomText.length() == 1) ? 16 : (bottomText == "-6" ? 19 : 22);
    g.drawText(topText, bounds.getRight() - topOffset, bounds.getY() + 2, 20, 12, juce::Justification::left);
    g.drawText(bottomText, bounds.getRight() - bottomOffset, bounds.getBottom() - 25, 20, 12, juce::Justification::left);
    
    // === VISUALIZACIÓN DEL CROSSOVER ===
    // Solo dibujar si los filtros están activos
    if (filtersEnabled.load())
    {
        // Obtener frecuencias del crossover
        float xLowFreq = crossoverLowFreq.load();
        float xHighFreq = crossoverHighFreq.load();
        
        // Calcular posiciones X usando el mismo mapeo bilineal que el espectro
        auto xLowPixel = mapFrequencyToX(xLowFreq, bounds.getWidth());
        auto xHighPixel = mapFrequencyToX(xHighFreq, bounds.getWidth());
        
        // Obtener estados de interacción
        bool hoveringLow = isHoveringLowFreq.load();
        bool hoveringHigh = isHoveringHighFreq.load();
        bool draggingLow = isDraggingLowFreq.load();
        bool draggingHigh = isDraggingHighFreq.load();
        
        // Dibujar líneas verticales con highlighting
        float dashPattern[] = {4.0f, 4.0f};
        
        // Línea XLow
        if (draggingLow)
        {
            // Línea siendo arrastrada - más brillante y gruesa
            g.setColour(juce::Colours::white.withAlpha(0.9f));
            g.drawDashedLine(juce::Line<float>(xLowPixel, 0, xLowPixel, bounds.getHeight()),
                            dashPattern, 2, 2.0f);
        }
        else if (hoveringLow)
        {
            // Línea con hover - moderadamente brillante
            g.setColour(juce::Colours::white.withAlpha(0.7f));
            g.drawDashedLine(juce::Line<float>(xLowPixel, 0, xLowPixel, bounds.getHeight()),
                            dashPattern, 2, 1.5f);
        }
        else
        {
            // Línea normal
            g.setColour(juce::Colours::white.withAlpha(0.4f));
            g.drawDashedLine(juce::Line<float>(xLowPixel, 0, xLowPixel, bounds.getHeight()),
                            dashPattern, 2, 1.0f);
        }
        
        // Línea XHigh
        if (draggingHigh)
        {
            // Línea siendo arrastrada - más brillante y gruesa
            g.setColour(juce::Colours::white.withAlpha(0.9f));
            g.drawDashedLine(juce::Line<float>(xHighPixel, 0, xHighPixel, bounds.getHeight()),
                            dashPattern, 2, 2.0f);
        }
        else if (hoveringHigh)
        {
            // Línea con hover - moderadamente brillante
            g.setColour(juce::Colours::white.withAlpha(0.7f));
            g.drawDashedLine(juce::Line<float>(xHighPixel, 0, xHighPixel, bounds.getHeight()),
                            dashPattern, 2, 1.5f);
        }
        else
        {
            // Línea normal
            g.setColour(juce::Colours::white.withAlpha(0.4f));
            g.drawDashedLine(juce::Line<float>(xHighPixel, 0, xHighPixel, bounds.getHeight()),
                            dashPattern, 2, 1.0f);
        }
        
        // Etiquetas de frecuencia en las líneas
        g.setFont(8.0f);
        
        // Etiqueta XLow - más brillante si está activa
        g.setColour(juce::Colours::white.withAlpha(draggingLow ? 0.9f : (hoveringLow ? 0.8f : 0.7f)));
        juce::String xLowText = xLowFreq < 1000.0f ? 
            juce::String((int)xLowFreq) + "Hz" : 
            juce::String(xLowFreq/1000.0f, 1) + "kHz";
        g.drawText(xLowText, xLowPixel - 20, 2, 40, 12, juce::Justification::centred);
        
        // Etiqueta XHigh - más brillante si está activa
        g.setColour(juce::Colours::white.withAlpha(draggingHigh ? 0.9f : (hoveringHigh ? 0.8f : 0.7f)));
        juce::String xHighText = xHighFreq < 1000.0f ? 
            juce::String((int)xHighFreq) + "Hz" : 
            juce::String(xHighFreq/1000.0f, 1) + "kHz";
        g.drawText(xHighText, xHighPixel - 20, 2, 40, 12, juce::Justification::centred);
    }
}

void SpectrumAnalyzerComponent::setBypassMode(bool enabled) noexcept
{
    bypassMode.store(enabled);
}

void SpectrumAnalyzerComponent::setFrequencyScale(FrequencyScale scale) noexcept
{
    currentScale = scale;
    repaint();
}

void SpectrumAnalyzerComponent::setZoomEnabled(bool enabled) noexcept
{
    zoomEnabled.store(enabled);
    repaint(); // Trigger redraw with new range
}

void SpectrumAnalyzerComponent::parameterChanged(const juce::String& parameterID, float newValue)
{
    // Reaccionar al bypass (ID válido en Imager)
    if (parameterID == "i_BYPASS")
    {
        setBypassMode(newValue > 0.5f);
    }
    // Actualizar frecuencias del crossover (IDs de Imager)
    else if (parameterID == "a_FREQ1")
    {
        crossoverLowFreq.store(newValue);
        juce::MessageManager::callAsync([safeThis = juce::Component::SafePointer(this)]() { if (safeThis) safeThis->repaint(); });
    }
    else if (parameterID == "b_FREQ2")
    {
        crossoverHighFreq.store(newValue);
        juce::MessageManager::callAsync([safeThis = juce::Component::SafePointer(this)]() { if (safeThis) safeThis->repaint(); });
    }
    // Soportar IDs legacy (por compatibilidad)
    else if (parameterID == "j_HPF")
    {
        crossoverLowFreq.store(newValue);
        juce::MessageManager::callAsync([safeThis = juce::Component::SafePointer(this)]() { if (safeThis) safeThis->repaint(); });
    }
    else if (parameterID == "k_LPF")
    {
        crossoverHighFreq.store(newValue);
        juce::MessageManager::callAsync([safeThis = juce::Component::SafePointer(this)]() { if (safeThis) safeThis->repaint(); });
    }
    // Ignorar o_BAND, l_SC, i_TILT en Imager
}

void SpectrumAnalyzerComponent::mouseMove(const juce::MouseEvent& event)
{
    if (filtersEnabled.load() && !isDraggingLowFreq.load() && !isDraggingHighFreq.load())
    {
        const float mouseX = event.position.x;
        const float width = getWidth();
        const float tolerance = 5.0f; // Misma tolerancia que en mouseDown
        
        // Obtener posiciones actuales de las líneas
        float xLowFreq = crossoverLowFreq.load();
        float xHighFreq = crossoverHighFreq.load();
        float xLowPixel = mapFrequencyToX(xLowFreq, width);
        float xHighPixel = mapFrequencyToX(xHighFreq, width);
        
        // Actualizar estado de hovering de líneas
        bool wasHoveringLow = isHoveringLowFreq.load();
        bool wasHoveringHigh = isHoveringHighFreq.load();
        
        bool nowHoveringLow = std::abs(mouseX - xLowPixel) <= tolerance;
        bool nowHoveringHigh = std::abs(mouseX - xHighPixel) <= tolerance;
        
        isHoveringLowFreq.store(nowHoveringLow);
        isHoveringHighFreq.store(nowHoveringHigh);
        
        // Detectar qué banda está bajo el cursor
        int wasHoveringBand = hoveringBandIndex.load();
        int nowHoveringBand = -1;
        
        // Solo detectar banda si no está sobre una línea
        if (!nowHoveringLow && !nowHoveringHigh)
        {
            if (mouseX < xLowPixel)
            {
                nowHoveringBand = 0; // Banda Low
            }
            else if (mouseX < xHighPixel)
            {
                nowHoveringBand = 1; // Banda Mid
            }
            else
            {
                nowHoveringBand = 2; // Banda High
            }
        }
        
        hoveringBandIndex.store(nowHoveringBand);
        
        // Establecer cursor apropiado
        if (nowHoveringLow || nowHoveringHigh)
        {
            // Cursor de redimensionar para líneas
            setMouseCursor(juce::MouseCursor::LeftRightResizeCursor);
        }
        else if (nowHoveringBand >= 0)
        {
            // Cursor de mano para bandas clickeables
            setMouseCursor(juce::MouseCursor::PointingHandCursor);
        }
        else
        {
            setMouseCursor(juce::MouseCursor::NormalCursor);
        }
        
        // Repintar si cambió el estado de hovering (líneas o bandas)
        if (wasHoveringLow != nowHoveringLow || 
            wasHoveringHigh != nowHoveringHigh ||
            wasHoveringBand != nowHoveringBand)
        {
            repaint();
        }
    }
    else if (!filtersEnabled.load())
    {
        // Si los filtros no están activos, limpiar todos los estados de hovering
        if (isHoveringLowFreq.load() || isHoveringHighFreq.load() || hoveringBandIndex.load() >= 0)
        {
            isHoveringLowFreq.store(false);
            isHoveringHighFreq.store(false);
            hoveringBandIndex.store(-1);
            setMouseCursor(juce::MouseCursor::NormalCursor);
            repaint();
        }
    }
    
    // Tooltip es manejado por el método getTooltip()
}

void SpectrumAnalyzerComponent::mouseDown(const juce::MouseEvent& event)
{
    // Solo permitir interacción con líneas si los filtros están activos
    if (filtersEnabled.load())
    {
        const float clickX = event.position.x;
        const float width = getWidth();
        const float tolerance = 5.0f; // Tolerancia en pixels para detectar click en línea
        
        // Obtener posiciones actuales de las líneas
        float xLowFreq = crossoverLowFreq.load();
        float xHighFreq = crossoverHighFreq.load();
        float xLowPixel = mapFrequencyToX(xLowFreq, width);
        float xHighPixel = mapFrequencyToX(xHighFreq, width);
        
        // Verificar si el click está cerca de la línea XLow
        if (std::abs(clickX - xLowPixel) <= tolerance)
        {
            // Iniciar arrastre de frecuencia baja
            if (auto* param = valueTreeState.getParameter("a_FREQ1"))
            {
                isDraggingLowFreq.store(true);
                currentDragParameter = param;
                dragStartValue = param->getValue();
                param->beginChangeGesture();
                setMouseCursor(juce::MouseCursor::LeftRightResizeCursor);
                return; // No procesar toggle de escala si estamos arrastrando
            }
        }
        // Verificar si el click está cerca de la línea XHigh
        else if (std::abs(clickX - xHighPixel) <= tolerance)
        {
            // Iniciar arrastre de frecuencia alta
            if (auto* param = valueTreeState.getParameter("b_FREQ2"))
            {
                isDraggingHighFreq.store(true);
                currentDragParameter = param;
                dragStartValue = param->getValue();
                param->beginChangeGesture();
                setMouseCursor(juce::MouseCursor::LeftRightResizeCursor);
                return; // No procesar toggle de escala si estamos arrastrando
            }
        }
    }
    
    // No selector de banda en Imager: sin acción adicional aquí
    
    // Si no estamos interactuando con filtros, alternar escala de frecuencia
    if (!isDraggingLowFreq.load() && !isDraggingHighFreq.load() && !filtersEnabled.load())
    {
        setFrequencyScale(currentScale == FrequencyScale::Linear ? 
                         FrequencyScale::Logarithmic : 
                         FrequencyScale::Linear);
    }
}

void SpectrumAnalyzerComponent::mouseDrag(const juce::MouseEvent& event)
{
    // Solo procesar si estamos arrastrando una línea
    if (currentDragParameter && (isDraggingLowFreq.load() || isDraggingHighFreq.load()))
    {
        const float dragX = event.position.x;
        const float width = getWidth();
        
        // Convertir posición X a frecuencia
        float newFreq = mapXToFrequency(dragX, width);
        
        // Aplicar límites según el parámetro
        if (isDraggingLowFreq.load())
        {
            // XLow: limitar entre 20Hz y 1000Hz
            newFreq = juce::jlimit(20.0f, 1000.0f, newFreq);
        }
        else if (isDraggingHighFreq.load())
        {
            // XHigh: limitar entre 1000Hz y 20000Hz
            newFreq = juce::jlimit(1000.0f, 20000.0f, newFreq);
        }
        
        // Convertir frecuencia a valor normalizado y actualizar parámetro
        auto range = currentDragParameter->getNormalisableRange();
        float normalizedValue = range.convertTo0to1(newFreq);
        currentDragParameter->setValueNotifyingHost(normalizedValue);
    }
}

void SpectrumAnalyzerComponent::mouseUp(const juce::MouseEvent& event)
{
    // Completar gesto de arrastre si estaba activo
    if (currentDragParameter && (isDraggingLowFreq.load() || isDraggingHighFreq.load()))
    {
        currentDragParameter->endChangeGesture();
        
        // TODO: Registrar cambio en UndoManager si está disponible
        // Por ahora solo limpiar estado
        
        // Limpiar flags y restaurar cursor
        isDraggingLowFreq.store(false);
        isDraggingHighFreq.store(false);
        currentDragParameter = nullptr;
        setMouseCursor(juce::MouseCursor::NormalCursor);
    }
}

void SpectrumAnalyzerComponent::mouseDoubleClick(const juce::MouseEvent& event)
{
    // Doble-click en líneas de crossover para resetear a valores por defecto
    if (filtersEnabled.load())
    {
        const float clickX = event.position.x;
        const float width = getWidth();
        const float tolerance = 5.0f; // Misma tolerancia que para arrastre
        
        // Obtener posiciones actuales de las líneas
        float xLowFreq = crossoverLowFreq.load();
        float xHighFreq = crossoverHighFreq.load();
        float xLowPixel = mapFrequencyToX(xLowFreq, width);
        float xHighPixel = mapFrequencyToX(xHighFreq, width);
        
        // Verificar si el doble-click está sobre la línea XLow
        if (std::abs(clickX - xLowPixel) <= tolerance)
        {
            // Resetear XLow a 250 Hz (valor por defecto)
            if (auto* param = valueTreeState.getParameter("a_FREQ1"))
            {
                param->beginChangeGesture();
                auto range = param->getNormalisableRange();
                float normalizedValue = range.convertTo0to1(250.0f); // 250 Hz por defecto
                param->setValueNotifyingHost(normalizedValue);
                param->endChangeGesture();
                return;
            }
        }
        // Verificar si el doble-click está sobre la línea XHigh
        else if (std::abs(clickX - xHighPixel) <= tolerance)
        {
            // Resetear XHigh a 5000 Hz (valor por defecto)
            if (auto* param = valueTreeState.getParameter("b_FREQ2"))
            {
                param->beginChangeGesture();
                auto range = param->getNormalisableRange();
                float normalizedValue = range.convertTo0to1(5000.0f); // 5000 Hz por defecto
                param->setValueNotifyingHost(normalizedValue);
                param->endChangeGesture();
                return;
            }
        }
    }
}

juce::String SpectrumAnalyzerComponent::getTooltip()
{
    // El tooltip se establece desde PluginEditor usando setHelpText()
    // Este método debe retornar el helpText establecido por el componente padre
    return getHelpText();
}
