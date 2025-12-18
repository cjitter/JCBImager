# Layout notes (buses)

- Change made in `Source/PluginProcessor.cpp` (`JCBImagerAudioProcessor::isBusesLayoutSupported`).
- Current supported layouts:
  - Input: `mono` or `stereo`
  - Output: `stereo` only
  - Effective allowed pairs: `1->2` and `2->2` (rejects any `*->1` / non-stereo output).
- Reason: forcing `2->2` (rejecting mono input) caused issues in Logic; allowing `1->2` avoids those host problems while keeping the plugin as “stereo-out only”.
