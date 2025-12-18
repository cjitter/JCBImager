# Layout notes (buses)

- Change made in `Source/PluginProcessor.cpp` (`JCBImagerAudioProcessor::isBusesLayoutSupported`).
- Current supported layouts:
  - Input: `mono` or `stereo`
  - Output: `stereo` only
  - Effective allowed pairs: `1->2` and `2->2` (rejects any `*->1` / non-stereo output).
- Reason: forcing `2->2` (rejecting mono input) caused issues in Logic; allowing `1->2` avoids those host problems while keeping the plugin as “stereo-out only”.

## Logic AU (mono / dual-mono)

- Logic puede instanciar el AU como `1->1` (incluyendo “Dual Mono”), aunque el plugin esté pensado como “stereo out”.
- Se permite `1->1` solo en Logic/AU para evitar mute/clicks.
- En `1->1` se procesa **por Gen** en estéreo interno y se hace downmix al final: `mono = 0.5 * (L + R)`.
- En `1->1` se bloquean controles de imagen estéreo (XY/MS IN/OUT y balances) para evitar variaciones de nivel por matriz/centrado, y la UI los deshabilita/opaca.
- En `1->1` la UI muestra el sufijo `(... MONO)` en el título y usa `Assets/fondoM.png` como fondo.
- En `1->1` el medidor de salida se calcula desde la salida final (post-makeup) ya colapsada a mono, no desde las salidas auxiliares de Gen.
