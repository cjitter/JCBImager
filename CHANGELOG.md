# Changelog

## 1.0.2
### Added
- (Logic/AU) Soporte de instancia `1->1` (incl. Dual Mono) SOLO en Logic/AU para evitar mute/clicks.
- (UI) En modo `1->1` se deshabilitan/opacan controles de imagen estéreo (XY/MS IN/OUT y balances), se muestra sufijo `(... MONO)` y se usa fondo `Assets/fondoM.png`.

### Changed
- (Buses/layouts) Salida forzada a estéreo: `1->2` y `2->2` (rechaza cualquier `*->1` / salida no estéreo).
- (DSP) En `1->1` se procesa en estéreo interno y se hace downmix al final: `mono = 0.5 * (L + R)`.
- (Meters) En `1->1` el medidor de salida se calcula desde la salida final ya colapsada a mono (post-makeup), no desde salidas auxiliares.

### Fixed
- (UI) El fondo del estado bypass no se restauraba al cerrar la ventana del plugin.
- (Audio) Ajuste de niveles de salida post-downmix (JUCE 0.5).

### Removed
- —

## 1.0.1
### Added
- (Mantenimiento) Alineación de versión y metadatos visibles a v1.0.1.

### Changed
- Sin cambios funcionales: actualización centrada en coherencia de versión y textos en UI.

### Removed
- —

## 1.0.0
- Versión inicial.
