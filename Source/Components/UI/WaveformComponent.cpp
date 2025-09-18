#include "WaveformComponent.h"

//==============================================================================
WaveformComponent::WaveformComponent()
{
    // Iniciar timer para actualización suave a 30fps
    startTimerHz(30);
    
    // Inicializar buffers de historia de niveles
    inputLevels.resize(levelHistorySize, 0.0f);
    outputLevels.resize(levelHistorySize, 0.0f);
    tailLevels.resize(levelHistorySize, 0.0f);
}

WaveformComponent::~WaveformComponent()
{
    stopTimer();
}

//==============================================================================
void WaveformComponent::paint(juce::Graphics& g)
{
    auto bounds = getLocalBounds();
    const float width = static_cast<float>(bounds.getWidth());
    const float height = static_cast<float>(bounds.getHeight());
    // Ganancia de zoom vertical: x2 cuando está activo (fija)
    const float zoomGain = zoomEnabled ? 2.0f : 1.0f;
    // Mapeo simple de amplitud: ON = 1.0x, OFF = 0.5x
    // Con zoom ON: 2.0 * 0.5 = 1.0 (tamaño "normal")
    // Con zoom OFF: 1.0 * 0.5 = 0.5 (la mitad del tamaño)
    const float ampScale = 0.5f;
    
    // No dibujar fondo - dejar transparente
    // Grid sutil y línea media
    g.setColour(Colours::gridLines.withAlpha(0.06f));
    g.drawHorizontalLine(static_cast<int>(height * 0.5f), 0.0f, width);
    g.setColour(Colours::gridLines.withAlpha(0.1f));
    g.drawHorizontalLine(static_cast<int>(height - 1), 0.0f, width);

    const float stepX = (levelHistorySize > 1) ? (width / static_cast<float>(levelHistorySize - 1)) : width;
    const float yCenter = height * 0.5f;

    // Estrategia: visualizar solo la ENERGÍA DE REVERB (diferencia WET-DRY), centrada y amplificada.
    // Esto evita ambigüedad entre curvas y hace clara la cola.
    {
        std::lock_guard<std::mutex> lock(dataLock);
        // Máscara oval horizontal para recortar extremos (evitar artefactos en inicios/paradas)
        const float edgeTaper = 0.15f; // 15% a cada lado (más recorte en extremos)
        auto maskAt = [&](int idx) noexcept {
            const float xn = (float) idx / (float) juce::jmax(1, levelHistorySize - 1);
            if (xn < edgeTaper) {
                const float t = xn / edgeTaper; return t * t * (3.0f - 2.0f * t);
            }
            if (xn > 1.0f - edgeTaper) {
                const float t = (1.0f - xn) / edgeTaper; return t * t * (3.0f - 2.0f * t);
            }
            return 1.0f;
        };

        // 1) Calcular media móvil (5 ptos) para DRY y TAIL + generar una cola "excitada" por transientes
        float maxTail = 0.0f;
        float localTail[levelHistorySize];   // cola medida (WET-DRY) suavizada
        float localDry[levelHistorySize];    // DRY suavizado
        for (int i = 0; i < levelHistorySize; ++i)
        {
            const int idxm2 = (writePos - levelHistorySize + i - 2 + levelHistorySize*10) % levelHistorySize;
            const int idxm1 = (writePos - levelHistorySize + i - 1 + levelHistorySize*10) % levelHistorySize;
            const int idx0  = (writePos - levelHistorySize + i +     levelHistorySize*10) % levelHistorySize;
            const int idxp1 = (writePos - levelHistorySize + i + 1 + levelHistorySize*10) % levelHistorySize;
            const int idxp2 = (writePos - levelHistorySize + i + 2 + levelHistorySize*10) % levelHistorySize;
            const float t = (tailLevels[idxm2] + tailLevels[idxm1] + tailLevels[idx0] + tailLevels[idxp1] + tailLevels[idxp2]) * 0.2f;
            const float d = (inputLevels[idxm2] + inputLevels[idxm1] + inputLevels[idx0] + inputLevels[idxp1] + inputLevels[idxp2]) * 0.2f;
            // Remapeo visual para realzar colas pequeñas y comprimir picos
            const float remapGamma = 0.80f; // <1.0 agranda valores pequeños
            const float tRemap = std::pow(juce::jmax(0.0f, t), remapGamma);
            localTail[i] = tRemap;
            localDry[i]  = d;
            if (tRemap > maxTail) maxTail = tRemap;
        }

        // --- DRY FILL (debajo del WET): dibujar primero para que quede por debajo ---
        {
            const float dryMix = juce::jlimit(0.0f, 1.0f, 1.0f - dryWetMix);
            const float sDry = (dryMix * dryMix) * (3.0f - 2.0f * dryMix);
            const float dryBoost = dryMix + 0.4f * (1.0f - reverbSize) + 0.3f * (1.0f - reflectAmount);
            const float dryAlpha = juce::jlimit(0.20f, 1.0f, (0.50f + dryBoost * 0.35f) * (0.15f + 0.85f * sDry));
            const float dryFillAlpha = dryAlpha * 0.22f; // blanco translúcido, un poco menos
            if (dryFillAlpha > 0.01f)
            {
                g.setColour(juce::Colours::white.withAlpha(dryFillAlpha));
                const float colW = juce::jmax(1.0f, stepX);
                for (int i = 0; i < levelHistorySize; ++i)
                {
                    const float x = i * stepX;
                    const float amp = localDry[i];
                    const float rectH = amp * 2.0f;
                    if (rectH <= 0.5f) continue;
                    g.setOpacity(maskAt(i));
                    g.fillRect(x - 0.5f * colW, yCenter - amp, colW, rectH);
                }
                g.setOpacity(1.0f);
            }
        }

        // Capturar snapshot de DRY para FREEZE en el flanco de subida
        if (freezeJustActivated || (freezeOn && (int)freezeDryCaps.size() != levelHistorySize))
        {
            freezeDryCaps.assign(levelHistorySize, 0.0f);
            for (int i = 0; i < levelHistorySize; ++i)
                freezeDryCaps[i] = localDry[i];
            freezeJustActivated = false;
        }

        // Generar cola excitada: propaga energía a la derecha con decaimiento
        float excitedTail[levelHistorySize]{}; // inicializado a 0
        // parámetros de decaimiento en pasos (ajustados por SIZE/REFLECT/DAMP)
        const float sizeFactor = juce::jlimit(0.05f, 1.0f, reverbSize);
        const float reflectFactor = juce::jlimit(0.0f, 1.0f, reflectAmount);
        const float dampFactor = juce::jlimit(0.0f, 1.0f, dampAmount);
        const float baseTailLen = 20.0f + sizeFactor * 120.0f + reflectFactor * 60.0f; // pasos de historia
        const float dampCut = 1.0f - 0.80f * dampFactor; // más damp => cola más corta
        const float tailLen = baseTailLen * dampCut;
        const float gamma = std::exp(-1.0f / juce::jmax(1.0f, tailLen)); // factor por paso
        const float exciteGain = (2.0f + 3.0f * reflectFactor) * (0.7f + 0.6f * sizeFactor); // más reflexiones/size => más excitación
        const float jitterAmt = 0.18f * (0.5f + reflectFactor * 0.5f); // densidad visual

        for (int i = 1; i < levelHistorySize; ++i)
        {
            // Onset aproximado del DRY
            const float onset = juce::jmax(0.0f, localDry[i] - localDry[i-1]);
            if (onset <= 1.0e-6f) continue;
            float energy = onset * exciteGain;
            // Propagar hacia la derecha (tiempos más recientes)
            float g = 1.0f;
            for (int j = i; j < levelHistorySize && energy * g > 1.0e-4f; ++j)
            {
                // Pequeño shimmer determinista
                const float phase = shimmerPhase + 0.35f * static_cast<float>(j);
                const float jitter = 1.0f + jitterAmt * std::sin(phase);
                excitedTail[j] += energy * g * jitter;
                g *= gamma;
            }
        }

        // Combinar medición y simulación para dar sensación de tanque real
        // Evitar crecimiento direccional: usar solo la medición local (WET-DRY) suavizada
        float combinedTail[levelHistorySize];
        for (int i = 0; i < levelHistorySize; ++i)
            combinedTail[i] = localTail[i];

        // 2) Auto-escalado estabilizado: objetivo fijo para consistencia (evita cambiar con zoom)
        const float targetHalf = height * 0.85f;
        const float eps = 1.0e-4f;
        float targetScale = (maxTail > eps) ? (targetHalf / maxTail) : tailScaleSmoothed;
        // Limitar escala
        targetScale = juce::jlimit(0.6f, 14.0f, targetScale);
        // Suavizado asimétrico: subir lento, bajar rápido
        const float up = 0.10f;
        const float dn = 0.35f;
        if (targetScale > tailScaleSmoothed)
            tailScaleSmoothed = tailScaleSmoothed + (targetScale - tailScaleSmoothed) * up;
        else
            tailScaleSmoothed = tailScaleSmoothed + (targetScale - tailScaleSmoothed) * dn;

        // Si no hay actividad, amortiguar la escala para que la cola no crezca
        if (activitySmoothed < 0.02f)
            tailScaleSmoothed *= 0.995f; // decaimiento muy suave

        // 3) Construir área WET (cola) y las envolventes DRY superior/inferior

        // Envolventes DRY superior/inferior (espejo negativo)
        juce::Path dryUpper, dryLower;
        bool dryStarted = false;
        // Escala base de DRY; el zoom aplica multiplicador explícito x2
        const float dryScale = height * 0.82f;
        float dryVals[levelHistorySize];
        for (int i = 0; i < levelHistorySize; ++i)
        {
            const int idx1 = (writePos - levelHistorySize + i +     levelHistorySize*10) % levelHistorySize;
            // Usar valor central para seguir más fielmente el contorno de entrada
            const float inAvg = inputLevels[idx1];
            float dAmp = inAvg * dryScale;
            dAmp *= zoomGain; // aplicar zoom x2 a la envolvente DRY
            dAmp *= ampScale; // reducir amplitud visual para mejor percepción
            // Clamp para evitar desbordes verticales en zoom
            const float maxDryAmp = height * 0.42f;
            dAmp = juce::jmin(dAmp, maxDryAmp);
            dryVals[i] = dAmp;
            const float x = i * stepX;
            const float yU = yCenter - dAmp;
            const float yL = yCenter + dAmp;
            if (!dryStarted) { dryUpper.startNewSubPath(x, yU); dryLower.startNewSubPath(x, yL); dryStarted = true; }
            else            { dryUpper.lineTo(x, yU);          dryLower.lineTo(x, yL); }
        }

        // Sin difusión horizontal: usar directamente la cola combinada por columna
        float smear[levelHistorySize];
        for (int i = 0; i < levelHistorySize; ++i) smear[i] = combinedTail[i];

        // Área WET: límites = DRY +- TAIL (cola) SIN ángulo (M/S ignorado)
        // Construir amplitud simétrica para TODAS las operaciones (base + ecos)
        float bandAmp[levelHistorySize];
        // No escalado horizontal dependiente de SIZE: controlar difusión con ecos, no con crecimiento por columna
        const float overflowBase = 1.0f;
        const float sizeGain = 1.0f + reverbSize * 3.2f; // agrandar moderado (sin cuña)
        for (int i = 0; i < levelHistorySize; ++i)
        {
            float ampLin = juce::jmax(0.0f, smear[i] * tailScaleSmoothed * overflowBase);
            // Remapeo visual consistente con localTail
            ampLin = std::pow(ampLin, 0.80f);
            bandAmp[i] = ampLin * sizeGain * zoomGain * ampScale; // reducir amplitud visual
        }

        juce::Path wetUpper, wetLower;
        bool wetStarted = false;
        for (int i = 0; i < levelHistorySize; ++i)
        {
            const float x = i * stepX;
            const float yU = yCenter - bandAmp[i];
            const float yL = yCenter + bandAmp[i];
            if (!wetStarted) { wetUpper.startNewSubPath(x, yU); wetLower.startNewSubPath(x, yL); wetStarted = true; }
            else            { wetUpper.lineTo(x, yU);          wetLower.lineTo(x, yL); }
        }

        juce::Path wetArea = wetUpper;
        juce::Path wetLowerRev;
        for (int i = levelHistorySize - 1; i >= 0; --i)
        {
            const float x = i * stepX;
            const float yL = yCenter + bandAmp[i];
            if (i == levelHistorySize - 1) wetLowerRev.startNewSubPath(x, yL);
            else wetLowerRev.lineTo(x, yL);
        }
        wetArea.addPath(wetLowerRev);
        wetArea.closeSubPath();

        // Relleno difuminado: múltiple pasada con leves offsets verticales
        // Coloreado: verde freeze, desaturado por DAMP (M/S no afecta)
        const float dampVis = juce::jlimit(0.0f, 1.0f, dampAmount);
        juce::Colour baseWet = Colours::freezeAccent;
        juce::Colour topCol    = baseWet.interpolatedWith(Colours::inputWaveform, 0.65f * dampVis);
        juce::Colour bottomCol = topCol; // mismo color arriba/abajo (sin M/S)
        // Nota: el área WET NO depende del control DRY/WET (solo afecta al contorno DRY)
        {
            const float wetAlphaBase = juce::jlimit(0.25f, 0.95f, 0.50f + (maxTail > eps ? 0.40f : 0.0f));
            float wetAlpha = juce::jlimit(0.0f, 0.95f,
                                          wetAlphaBase * (0.7f + 0.3f * (1.0f - dampVis)));
                // Base por columnas (evita cuñas): pintar rectángulos simétricos
                juce::ColourGradient grad(topCol.withAlpha(wetAlpha), 0.0f, 0.0f,
                                          bottomCol.withAlpha(wetAlpha), 0.0f, height, false);
                g.setGradientFill(grad);
                const float colW = juce::jmax(1.0f, stepX);
                const float minHeightPx = 1.2f;                             // raya mínima
                const float maxAmpPx   = height * (freezeOn ? 0.52f : 0.70f); // freeze contenido / normal abierto
                // Máscara oval para extremos (suavizado horizontal)
                const float edgeTaper = 0.20f; // 20% a cada lado (cierra más extremos)
                auto maskAt = [&](int idx) noexcept {
                    const float xn = (float) idx / (float) juce::jmax(1, levelHistorySize - 1);
                    if (xn < edgeTaper) {
                        const float t = xn / edgeTaper; return t * t * (3.0f - 2.0f * t);
                    }
                    if (xn > 1.0f - edgeTaper) {
                        const float t = (1.0f - xn) / edgeTaper; return t * t * (3.0f - 2.0f * t);
                    }
                    return 1.0f;
                };
                for (int i = 0; i < levelHistorySize; ++i)
                {
                    const float x = i * stepX;
                    float amp = bandAmp[i];
                    amp = juce::jmin(amp, maxAmpPx);
                    float rectH = amp * 2.0f;
                    if (rectH < minHeightPx) { rectH = minHeightPx; amp = rectH * 0.5f; }
                    g.setOpacity(maskAt(i));
                    g.fillRect(x - 0.5f * colW, yCenter - amp, colW, rectH);
                }
                g.setOpacity(1.0f);
            // sin bordes extra: evitar bandas internas

            // No extensiones horizontales: evitar cualquier ángulo visual

            // Ecos superpuestos SIN desplazamiento en X: aumentando grosor (expansión vertical) de forma simétrica
            const int echoCount = juce::jlimit(0, 20, (int)std::round(3 + reflectAmount * 9 + reverbSize * 7));
            const float spreadBase = 0.06f + 0.18f * reverbSize + 0.10f * reflectAmount; // incremento relativo por eco
            for (int e = 1; e <= echoCount; ++e)
            {
                const float a = std::max(0.0f, (float)
                                   (juce::jlimit(0.0f, 0.95f,
                                      (0.50f + (maxTail > eps ? 0.40f : 0.0f)) * (0.7f + 0.3f * (1.0f - dampVis))))
                                   ) * std::pow(0.82f - 0.15f * dampVis, (float)e) * (0.80f + 0.20f * reflectAmount);
                if (a < 0.02f) break;
                // Ecos por columnas: expansión vertical sin conectar en X
                const float colW2 = juce::jmax(1.0f, stepX);
                const float factor = 1.0f + spreadBase * (float)e;
                const float maxAmpPx = height * (freezeOn ? 0.52f : 0.70f);
                juce::ColourGradient gradE(topCol.withAlpha(a), 0.0f, 0.0f,
                                           bottomCol.withAlpha(a), 0.0f, height, false);
                g.setGradientFill(gradE);
                for (int i2 = 0; i2 < levelHistorySize; ++i2)
                {
                    const float x2 = i2 * stepX;
                    float amp2 = bandAmp[i2] * factor;
                    amp2 = juce::jmin(amp2, maxAmpPx);
                    float rectH2 = amp2 * 2.0f;
                    if (rectH2 <= 0.5f) continue;
                    g.setOpacity(maskAt(i2));
                    g.fillRect(x2 - 0.5f * colW2, yCenter - amp2, colW2, rectH2);
                }
                g.setOpacity(1.0f);
                // Difuminado suave adicional para disimular bandas de ecos
                const float aSoft = a * 0.25f;
                juce::ColourGradient gradE2(topCol.withAlpha(aSoft), 0.0f, 0.0f,
                                            bottomCol.withAlpha(aSoft), 0.0f, height, false);
                g.setGradientFill(gradE2);
                const float factorSoft = 1.0f + spreadBase * (float)e * 0.96f;
                for (int i2 = 0; i2 < levelHistorySize; ++i2)
                {
                    const float x2 = i2 * stepX;
                    float amp2 = bandAmp[i2] * factorSoft;
                    amp2 = juce::jmin(amp2, maxAmpPx);
                    float rectH2 = amp2 * 2.0f;
                    if (rectH2 <= 0.5f) continue;
                    g.setOpacity(maskAt(i2));
                    g.fillRect(x2 - 0.5f * colW2, yCenter - amp2, colW2, rectH2);
                }
                g.setOpacity(1.0f);
            }

            // Trazo de la envolvente de reverb (superpuesto a la DRY) si hay alpha
            // Sin trazos de borde WET para evitar franjas internas
        }

        // Trazos DRY superior/inferior (alpha suavizada por DRY/WET)
        {
            const float dryMix = juce::jlimit(0.0f, 1.0f, 1.0f - dryWetMix);
            const float sDry = (dryMix * dryMix) * (3.0f - 2.0f * dryMix);
            const float dryBoost = dryMix + 0.4f * (1.0f - reverbSize) + 0.3f * (1.0f - reflectAmount);
            const float dryAlpha = juce::jlimit(0.20f, 1.0f, (0.50f + dryBoost * 0.35f) * (0.15f + 0.85f * sDry));

            g.setColour(Colours::inputWaveform.withAlpha(dryAlpha));
            g.strokePath(dryUpper, juce::PathStrokeType(1.6f));
            g.strokePath(dryLower, juce::PathStrokeType(1.6f));
        }

        // En DRY puro, ya no se dibuja WET; en WET puro, ya no se traza DRY (gestionado arriba)
    }
}

void WaveformComponent::resized()
{
    // No hay componentes hijos que posicionar
}

//==============================================================================
void WaveformComponent::updateWaveformData(const std::vector<float>& inputSamples, 
                                          const std::vector<float>& processedSamples)
{
    // Usar try_lock para evitar bloquear el audio thread
    std::unique_lock<std::mutex> lock(dataLock, std::try_to_lock);
    if (!lock.owns_lock())
        return;
    
    // Calcular RMS de las muestras
    float inputRMS = 0.0f;
    float outputRMS = 0.0f;
    
    if (!inputSamples.empty())
    {
        for (const auto& sample : inputSamples)
            inputRMS += sample * sample;
        inputRMS = std::sqrt(inputRMS / static_cast<float>(inputSamples.size()));
    }
    
    if (!processedSamples.empty())
    {
        for (const auto& sample : processedSamples)
            outputRMS += sample * sample;
        outputRMS = std::sqrt(outputRMS / static_cast<float>(processedSamples.size()));
    }
    
    // Amplificar señales para mejor visualización
    const float visualGain = 8.0f;
    inputRMS *= visualGain;
    outputRMS *= visualGain;
    
    // Aplicar curva logarítmica para mejor respuesta visual
    inputRMS = std::log10(1.0f + inputRMS * 9.0f);  // Mapea a rango ~0-1
    outputRMS = std::log10(1.0f + outputRMS * 9.0f);
    
    // Suavizar niveles con constantes diferenciadas para entrada y salida
    const float inAttack = 0.35f;   // Entrada: respuesta más rápida
    const float inRelease = 0.80f;  // Entrada: liberación más rápida para seguir transitorios
    const float outAttack = 0.12f;  // Salida: mantener algo de suavidad
    const float outRelease = 0.92f; // Salida: cola más estable

    if (inputRMS > currentInputLevel)
        currentInputLevel = currentInputLevel * (1.0f - inAttack) + inputRMS * inAttack;
    else
        currentInputLevel = currentInputLevel * inRelease + inputRMS * (1.0f - inRelease);

    if (outputRMS > currentOutputLevel)
        currentOutputLevel = currentOutputLevel * (1.0f - outAttack) + outputRMS * outAttack;
    else
        currentOutputLevel = currentOutputLevel * outRelease + outputRMS * (1.0f - outRelease);
    
    // Calcular nivel de reverb para visualización
    // Desacoplar de TRIM: usar salida post-cadena directamente (no restar input)
    float reverbLevel = juce::jmax(0.0f, currentOutputLevel);
    peakReverbLevel = peakReverbLevel * 0.9f + reverbLevel * 0.1f;
    activitySmoothed = activitySmoothed * 0.9f + juce::jmax(currentInputLevel, currentOutputLevel) * 0.1f;

    // FREEZE (modo follow-post con compensación de salto): usar SOLO salida del plugin
    if (freezeOn)
    {
        const float frozenLevel = currentOutputLevel; // post-cadena (EQ/COMP/M/S)
        // Ajustar escala en el flanco de activación para casar niveles
        if (freezeJustActivated)
        {
            const int prev = (writePos - 1 + levelHistorySize) % levelHistorySize;
            const float prevTail = juce::jmax(1.0e-6f, tailLevels[prev]);
            freezeTailScale = prevTail / juce::jmax(1.0e-6f, frozenLevel);
            freezeTailScale = juce::jlimit(0.2f, 1.5f, freezeTailScale);
            freezeBlend = 0.0f;
            freezeJustActivated = false;
        }
        // Relajar suavemente la escala hacia 1.0 (evita saltos)
        freezeBlend = juce::jmin(1.0f, freezeBlend + 0.06f);
        const float scale = freezeTailScale + (1.0f - freezeTailScale) * freezeBlend;
        const float adjusted = frozenLevel * scale;

        peakReverbLevel = peakReverbLevel * 0.9f + adjusted * 0.1f;

        // No considerar la entrada; la cola sigue cambios post-FREEZE
        inputLevels[writePos]  = 0.0f;
        outputLevels[writePos] = adjusted;
        tailLevels[writePos]   = adjusted; // pintar como cola directa

        writePos = (writePos + 1) % levelHistorySize;
        return;
    }
    
    // Guardar en historia
    inputLevels[writePos] = currentInputLevel;
    outputLevels[writePos] = currentOutputLevel;
    tailLevels[writePos] = reverbLevel;
    
    // Avanzar posición de escritura
    writePos = (writePos + 1) % levelHistorySize;
}

void WaveformComponent::setZoomEnabled(bool shouldZoom)
{
    if (zoomEnabled != shouldZoom)
    {
        zoomEnabled = shouldZoom;
        repaint();
    }
}

void WaveformComponent::timerCallback()
{
    // Repintar para actualizar visualización
    // Avanzar fase del shimmer (densidad de reflexiones)
    shimmerPhase += 0.12f; if (shimmerPhase > juce::MathConstants<float>::twoPi) shimmerPhase -= juce::MathConstants<float>::twoPi;
    repaint();
}
