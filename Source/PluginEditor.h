#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class JCBImagerAudioProcessorEditor : public AudioProcessorEditor,
                                      public juce::Slider::Listener
{
public:
    JCBImagerAudioProcessorEditor (JCBImagerAudioProcessor&);
   ~JCBImagerAudioProcessorEditor();

    // =============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (juce::Slider* slider) override
    {
        if (slider == &soloLowSlider)
        {
            soloMedSlider.setValue(0);
            soloHighSlider.setValue(0);
        
        } else if (slider == &soloMedSlider)
        {
                soloLowSlider.setValue(0);
                soloHighSlider.setValue(0);
            
        } else if (slider == &soloHighSlider)
        {
                    soloLowSlider.setValue(0);
                    soloMedSlider.setValue(0);

        }
    }
    
private:
    
    juce::TooltipWindow tooltipVentana;
    
    // Declarar variables
    int const ancho {700};
    int const alto  {200};
    
    juce::Label labelFreq1;
    juce::Label labelFreq2;
    juce::Label labelLow;
    juce::Label labelMed;
    juce::Label labelHigh;
    juce::Label labelSoloLow;
    juce::Label labelSoloMed;
    juce::Label labelSoloHigh;
    juce::Label labelBypass;
    
    juce::Label labelInput;
    juce::Label labelLowBal;
    juce::Label labelMedBal;
    juce::Label labelHighBal;
    
;
   // Texto adicional 
    juce::DrawableText txtExtra;
    // Link

    juce::HyperlinkButton titleLink;
    
    // Imagen de fondo como componente
    juce::ImageComponent mFondo;

    // Sliders

    juce::Slider freq1Slider;
    juce::Slider freq2Slider;
    juce::Slider lowSlider;
    juce::Slider medSlider;
    juce::Slider highSlider;
    juce::Slider soloLowSlider;
    juce::Slider soloMedSlider;
    juce::Slider soloHighSlider;
    juce::Slider bypassSlider;
    
    juce::Slider inputSlider;
    juce::Slider lowBalSlider;
    juce::Slider medBalSlider;
    juce::Slider highBalSlider;
    
    // --- Band mute buttons ---
    juce::ToggleButton muteLowButton { "Mute Low" };
    juce::ToggleButton muteMidButton { "Mute Mid" };
    juce::ToggleButton muteHighButton{ "Mute High" };

    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> muteLowAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> muteMidAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> muteHighAttach;
    
    // Sliders attachments
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> freq1SliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> freq2SliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> lowSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> medSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> highSliderttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> soloLowSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> soloMedSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> soloHighSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> bypassSliderAttachment;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> inputSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> lowBalSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> medBalSliderAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> highBalSliderAttachment;
    
 
   JCBImagerAudioProcessor& processor;
;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JCBImagerAudioProcessorEditor)
};

#endif  // PLUGINEDITOR_H_INCLUDED


