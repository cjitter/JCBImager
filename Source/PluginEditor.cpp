#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JCBImagerAudioProcessorEditor::JCBImagerAudioProcessorEditor (JCBImagerAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
    
    // --- Band mutes ---
    muteLowButton.setClickingTogglesState(true);
    muteMidButton.setClickingTogglesState(true);
    muteHighButton.setClickingTogglesState(true);

    addAndMakeVisible(muteLowButton);
    addAndMakeVisible(muteMidButton);
    addAndMakeVisible(muteHighButton);

    muteLowAttach  = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(processor.apvts, "n_MUTLOW",  muteLowButton);
    muteMidAttach  = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(processor.apvts, "o_MUTMED",  muteMidButton);
    muteHighAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(processor.apvts, "p_MUTHIGH", muteHighButton);
    auto backgroundImage = ImageCache::getFromMemory(BinaryData::morado_jpg,
                                                     BinaryData::morado_jpgSize);
    
    if (!backgroundImage.isNull())
    mFondo.setImage(backgroundImage, RectanglePlacement::stretchToFit);
    else
        jassert(!backgroundImage.isNull());
    
    addAndMakeVisible(mFondo);
    mFondo.toBack();

    addAndMakeVisible (titleLink);
    titleLink.setURL(juce::URL("https://github.com/cjitter"));
    titleLink.setColour (juce::HyperlinkButton::textColourId, juce::Colours::azure);
    titleLink.changeWidthToFitText();
    titleLink.setFont(juce::Font(4.f), true);
    titleLink.setTooltip (TRANS("https://github.com/cjitter"));
    titleLink.setButtonText (TRANS("JCBImager 0.0.4"));
    

    // IMAGER
    addAndMakeVisible(lowSlider);
    lowSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    lowSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    lowSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    lowSlider.setTextValueSuffix(" WIDE");
    lowSlider.setTextBoxIsEditable(true);
    lowSlider.setPopupDisplayEnabled(true, true, this);
    lowSlider.setColour (juce::Slider::thumbColourId, juce::Colours::red);
    lowSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::red);
    lowSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
    lowSlider.setDoubleClickReturnValue (true, 1.0);
    lowSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                 "c_LOW",
                                                                                                 lowSlider);
    
    addAndMakeVisible(freq1Slider);
    freq1Slider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    freq1Slider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 20);
    freq1Slider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));
    
    freq1Slider.setTextValueSuffix(" Hz");
    freq1Slider.setTextBoxIsEditable(true);
    freq1Slider.setPopupDisplayEnabled(true, true, this);
    freq1Slider.setColour (juce::Slider::thumbColourId, juce::Colours::green);
    freq1Slider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::red);
    freq1Slider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::green);
    freq1Slider.setDoubleClickReturnValue (true, 250.0);
    freq1SliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                   "a_FREQ1",
                                                                                                   freq1Slider);
    
    
    addAndMakeVisible(medSlider);
    medSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    medSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    medSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));
    
    medSlider.setTextValueSuffix(" WIDE");
    medSlider.setTextBoxIsEditable(true);
    medSlider.setPopupDisplayEnabled(true, true, this);
    medSlider.setColour (juce::Slider::thumbColourId, juce::Colours::green);
    medSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::green);
    medSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
    medSlider.setDoubleClickReturnValue (true, 1.0);
    medSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                 "d_MED",
                                                                                                 medSlider);
    
    
    addAndMakeVisible(freq2Slider);
    freq2Slider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    freq2Slider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 75, 20);
    freq2Slider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    freq2Slider.setTextValueSuffix(" Hz");
    freq2Slider.setTextBoxIsEditable(true);
    freq2Slider.setPopupDisplayEnabled(true, true, this);
    freq2Slider.setColour (juce::Slider::thumbColourId, juce::Colours::green);
    freq2Slider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::green);
    freq2Slider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::blue);
    freq2Slider.setDoubleClickReturnValue (true, 5000.0);
    freq2SliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                 "b_FREQ2",
                                                                                                   freq2Slider);
    
    
    addAndMakeVisible(highSlider);
    highSlider.setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    highSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    highSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    highSlider.setTextValueSuffix(" WIDE");
    highSlider.setTextBoxIsEditable(true);
    highSlider.setPopupDisplayEnabled(true, true, this);
    highSlider.setColour (juce::Slider::thumbColourId, juce::Colours::blue);
    highSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::blue);
    highSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::whitesmoke);
    highSlider.setDoubleClickReturnValue (true, 1.0);
    highSliderttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                  "e_HIGH",
                                                                                                   highSlider);
    
    // Solo Sliders
    addAndMakeVisible(soloLowSlider);
    soloLowSlider.setSliderStyle (juce::Slider::LinearHorizontal);
    soloLowSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    soloLowSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    soloLowSlider.setColour (juce::Slider::thumbColourId, juce::Colours::red);
    soloLowSlider.setColour(juce::Slider::trackColourId, juce::Colours::red);
    soloLowSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::whitesmoke);
    soloLowSlider.setDoubleClickReturnValue (true, 0);
    
    soloLowSlider.addListener(this);
    
    soloLowSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                    "f_SOLOLOW",
                                                                                                     soloLowSlider);
    addAndMakeVisible(soloMedSlider);
    soloMedSlider.setSliderStyle (juce::Slider::LinearHorizontal);
    soloMedSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    soloMedSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    soloMedSlider.setColour (juce::Slider::thumbColourId, juce::Colours::green);
    soloMedSlider.setColour(juce::Slider::trackColourId, juce::Colours::green);
    soloMedSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::whitesmoke);
    soloMedSlider.setDoubleClickReturnValue (true, 0);
    
    soloMedSlider.addListener(this);

    soloMedSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                    "g_SOLOMED",
                                                                                                     soloMedSlider);
    
    addAndMakeVisible(soloHighSlider);
    soloHighSlider.setSliderStyle (juce::Slider::LinearHorizontal);
    soloHighSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    soloHighSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    soloHighSlider.setColour (juce::Slider::thumbColourId, juce::Colours::blue);
    soloHighSlider.setColour(juce::Slider::trackColourId, juce::Colours::blue);
    soloHighSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::whitesmoke);
    soloHighSlider.setDoubleClickReturnValue (true, 0);
    
    soloHighSlider.addListener(this);

    soloHighSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                      "h_SOLOHIGH",
                                                                                                      soloHighSlider);
    
    // Bypass
    addAndMakeVisible(bypassSlider);
    bypassSlider.setSliderStyle (juce::Slider::LinearHorizontal);
    bypassSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    bypassSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    bypassSlider.setColour (juce::Slider::thumbColourId, juce::Colours::darkviolet);
    bypassSlider.setColour(juce::Slider::trackColourId, juce::Colours::darkviolet);
    bypassSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::whitesmoke);
    bypassSlider.setDoubleClickReturnValue (true, 0);
    bypassSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                    "i_BYPASS",
                                                                                                    bypassSlider);
    
    // Balances
    addAndMakeVisible(lowBalSlider);
    lowBalSlider.setSliderStyle (juce::Slider::LinearHorizontal);
    lowBalSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    lowBalSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    lowBalSlider.setColour (juce::Slider::thumbColourId, juce::Colours::whitesmoke);
    lowBalSlider.setColour(juce::Slider::trackColourId, juce::Colours::red);
    lowBalSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::red);
    lowBalSlider.setDoubleClickReturnValue (true, 0);
    
    lowBalSlider.addListener(this);

    lowBalSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                    "k_LOW_bal",
                                                                                                    lowBalSlider);
    
    addAndMakeVisible(medBalSlider);
    medBalSlider.setSliderStyle (juce::Slider::LinearHorizontal);
    medBalSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    medBalSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    medBalSlider.setColour (juce::Slider::thumbColourId, juce::Colours::whitesmoke);
    medBalSlider.setColour(juce::Slider::trackColourId, juce::Colours::darkgreen);
    medBalSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::darkgreen);
    medBalSlider.setDoubleClickReturnValue (true, 0);
    
    medBalSlider.addListener(this);

    medBalSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                    "l_MED_bal",
                                                                                                    medBalSlider);
    
    addAndMakeVisible(highBalSlider);
    highBalSlider.setSliderStyle (juce::Slider::LinearHorizontal);
    highBalSlider.setTextBoxStyle (juce::Slider::NoTextBox, false, 75, 20);
    highBalSlider.setColour(juce::Slider::textBoxOutlineColourId, Colour(0,0,0));

    highBalSlider.setColour (juce::Slider::thumbColourId, juce::Colours::whitesmoke);
    highBalSlider.setColour(juce::Slider::trackColourId, juce::Colours::blue);
    highBalSlider.setColour(juce::Slider::backgroundColourId, juce::Colours::blue);
    highBalSlider.setDoubleClickReturnValue (true, 0);
    
    highBalSlider.addListener(this);

    highBalSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts,
                                                                                                     "m_HIGH_bal",
                                                                                                     highBalSlider);
    
    

    // Labels
    addAndMakeVisible(labelFreq1);
    labelFreq1.setText(juce::CharPointer_UTF8("X1 FREQ"), juce::dontSendNotification);
    labelFreq1.attachToComponent(&freq1Slider, false);
    labelFreq1.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelFreq2);
    labelFreq2.setText(juce::CharPointer_UTF8("X2 FREQ"), juce::dontSendNotification);
    labelFreq2.attachToComponent(&freq2Slider, false);
    labelFreq2.setJustificationType(juce::Justification(36));

    
    addAndMakeVisible(labelLow);
    labelLow.setText(juce::CharPointer_UTF8("LOW WIDTH"), juce::dontSendNotification);
    labelLow.attachToComponent(&lowSlider, false);
    labelLow.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelMed);
    labelMed.setText(juce::CharPointer_UTF8("MID WIDTH"), juce::dontSendNotification);
    labelMed.attachToComponent(&medSlider, false);
    labelMed.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelHigh);
    labelHigh.setText(juce::CharPointer_UTF8("HIGH WIDTH"), juce::dontSendNotification);
    labelHigh.attachToComponent(&highSlider, false);
    labelHigh.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelSoloLow);
    labelSoloLow.setText(juce::CharPointer_UTF8("SOLO"), juce::dontSendNotification);
    labelSoloLow.attachToComponent(&soloLowSlider, false);
    labelSoloLow.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelSoloMed);
    labelSoloMed.setText(juce::CharPointer_UTF8("SOLO"), juce::dontSendNotification);
    labelSoloMed.attachToComponent(&soloMedSlider, false);
    labelSoloMed.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelSoloHigh);
    labelSoloHigh.setText(juce::CharPointer_UTF8("SOLO"), juce::dontSendNotification);
    labelSoloHigh.attachToComponent(&soloHighSlider, false);
    labelSoloHigh.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelLowBal);
    labelLowBal.setText(juce::CharPointer_UTF8("LOW BAL"), juce::dontSendNotification);
    labelLowBal.attachToComponent(&lowBalSlider, false);
    labelLowBal.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelMedBal);
    labelMedBal.setText(juce::CharPointer_UTF8("MID BAL"), juce::dontSendNotification);
    labelMedBal.attachToComponent(&medBalSlider, false);
    labelMedBal.setJustificationType(juce::Justification(36));
    
    addAndMakeVisible(labelHighBal);
    labelHighBal.setText(juce::CharPointer_UTF8("HIGH BAL"), juce::dontSendNotification);
    labelHighBal.attachToComponent(&highBalSlider, false);
    labelHighBal.setJustificationType(juce::Justification(36));

    // Bypass
    addAndMakeVisible(labelBypass);
    labelBypass.setText(juce::CharPointer_UTF8("BYPASS"), juce::dontSendNotification);
    labelBypass.attachToComponent(&bypassSlider, false);
    labelBypass.setJustificationType(juce::Justification(36));
    
    // Tamaño reajustable
    auto size = processor.getSavedSize();
    setResizable(true, true);
    setSize(size.x, size.y);
    setResizeLimits(1050, 350, ancho*2.75, alto*2.75);
    getConstrainer()->setFixedAspectRatio(ancho/alto);
}

JCBImagerAudioProcessorEditor::~JCBImagerAudioProcessorEditor()
{
}

//==============================================================================
void JCBImagerAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (juce::Colours::black);
}

void JCBImagerAudioProcessorEditor::resized()
{
    // MAXI
    auto correctX = 0;
    auto correctY = 0;
    
    auto xLow = (correctX+getWidth())    * 65/ancho;
    auto yLow = (correctY+getHeight())   * 70/alto;
    auto wLow = (correctX+getWidth())    * 70/ancho;
    auto hLow = (correctY+getHeight())   * 70/alto;

    auto xFreq1 = (correctX+getWidth())  * 170/ancho;
    auto yFreq1 = (correctY+getHeight()) * 70/alto;
    auto wFreq1 = (correctX+getWidth())  * 70/ancho;
    auto hFreq1 = (correctY+getHeight()) * 70/alto;
    
    auto xMed = (correctX+getWidth())    * 315/ancho;
    auto yMed = (correctY+getHeight())   * 70/alto;
    auto wMed = (correctX+getWidth())    * 70/ancho;
    auto hMed = (correctY+getHeight())   * 70/alto;
    
    auto xFreq2 = (correctX+getWidth())  * 450/ancho;
    auto yFreq2 = (correctY+getHeight()) * 70/alto;
    auto wFreq2 = (correctX+getWidth())  * 70/ancho;
    auto hFreq2 = (correctY+getHeight()) * 70/alto;
    
    auto xHigh = (correctX+getWidth())   * 568/ancho;
    auto yHigh = (correctY+getHeight())  * 70/alto;
    auto wHigh = (correctX+getWidth())   * 70/ancho;
    auto hHigh = (correctY+getHeight())  * 70/alto;
    
    // Horizontal Sliders
    auto xSoloLow =  (correctX+getWidth())  * 88/ancho;
    auto ySoloLow =  (correctY+getHeight()) * 105/alto;
    auto wSoloLow =  (correctX+getWidth())  * 25/ancho;
    auto hSoloLow =  (correctY+getHeight()) * 10/alto;
    
    auto xSoloMed =  (correctX+getWidth())  * 338/ancho;
    auto ySoloMed =  (correctY+getHeight()) * 105/alto;
    auto wSoloMed =  (correctX+getWidth())  * 25/ancho;
    auto hSoloMed =  (correctY+getHeight()) * 10/alto;
    
    auto xSoloHigh =  (correctX+getWidth())  * 591/ancho;
    auto ySoloHigh =  (correctY+getHeight()) * 105/alto;
    auto wSoloHigh =  (correctX+getWidth())  * 25/ancho;
    auto hSoloHigh =  (correctY+getHeight()) * 10/alto;
    
    // Balances
    auto xBalLow =  (correctX+getWidth())  * 62/ancho;
    auto yBalLow =  (correctY+getHeight()) * 145/alto;
    auto wBalLow =  (correctX+getWidth())  * 75/ancho;
    auto hBalLow =  (correctY+getHeight()) * 10/alto;
    
    auto xBalMed =  (correctX+getWidth())  * 312/ancho;
    auto yBalMed =  (correctY+getHeight()) * 145/alto;
    auto wBalMed =  (correctX+getWidth())  * 75/ancho;
    auto hBalMed =  (correctY+getHeight()) * 10/alto;
    
    auto xBalHigh =  (correctX+getWidth())  * 565/ancho;
    auto yBalHigh =  (correctY+getHeight()) * 145/alto;
    auto wBalHigh =  (correctX+getWidth())  * 75/ancho;
    auto hBalHigh =  (correctY+getHeight()) * 10/alto;

    // Bypass
    auto xBypa    =  (correctX+getWidth())  * 463/ancho;
    auto yBypa    =  (correctY+getHeight()) * 185/alto;
    auto wBypa    =  (correctX+getWidth())  * 50/ancho;
    auto hBypa    =  (correctY+getHeight()) * 10/alto;
    
    // URL
    auto xUrl   = (correctX+getWidth())  * 250/ancho;
    auto yUrl   = (correctY+getHeight()) * 170/alto;
    auto wUrl   = (correctX+getHeight()) * 600/ancho;
    auto hUrl   = (correctY+getHeight()) * 25/alto;
    
    // set Bounds
    processor.setSavedSize( {getWidth(), getHeight()} );
    mFondo.setBoundsRelative(0.f, 0.f, 1.f, 1.f);
    
    lowSlider.setBounds       (xLow,     yLow,   wLow,   hLow);
    freq1Slider.setBounds     (xFreq1, yFreq1, wFreq1, hFreq1);
    medSlider.setBounds       (xMed,     yMed,   wMed,   hMed);
    freq2Slider.setBounds     (xFreq2, yFreq2, wFreq2, hFreq2);
    highSlider.setBounds      (xHigh,   yHigh,  wHigh,  hHigh);
    
    soloLowSlider.setBounds   (xSoloLow,   ySoloLow,  wSoloLow,  hSoloLow);
    soloMedSlider.setBounds   (xSoloMed,   ySoloMed,  wSoloMed,  hSoloMed);
    soloHighSlider.setBounds  (xSoloHigh, ySoloHigh, wSoloHigh, hSoloHigh);

    bypassSlider.setBounds    (xBypa, yBypa, wBypa, hBypa);
    
    lowBalSlider.setBounds    (xBalLow,   yBalLow,  wBalLow,  hBalLow);
    medBalSlider.setBounds    (xBalMed,   yBalMed,  wBalMed,  hBalMed);
    highBalSlider.setBounds   (xBalHigh, yBalHigh, wBalHigh, hBalHigh);

    
    // Band mutes (bottom row)
    {
        auto xMuteLow  = (correctX + getWidth())  *  70 / ancho;
        auto yMuteLow  = (correctY + getHeight()) *  43 / alto;
        auto wMuteLow  = (correctX + getWidth())  *  75 / ancho;
        auto hMuteLow  = (correctY + getHeight()) *  15 / alto;

        auto xMuteMid  = (correctX + getWidth())  * 320 / ancho;
        auto yMuteMid  = (correctY + getHeight()) *  43 / alto;
        auto wMuteMid  = (correctX + getWidth())  *  75 / ancho;
        auto hMuteMid  = (correctY + getHeight()) *  15 / alto;

        auto xMuteHigh = (correctX + getWidth())  * 573 / ancho;
        auto yMuteHigh = (correctY + getHeight()) *  43 / alto;
        auto wMuteHigh = (correctX + getWidth())  *  75 / ancho;
        auto hMuteHigh = (correctY + getHeight()) *  15 / alto;

        muteLowButton .setBounds(xMuteLow,  yMuteLow,  wMuteLow,  hMuteLow);
        muteMidButton .setBounds(xMuteMid,  yMuteMid,  wMuteMid,  hMuteMid);
        muteHighButton.setBounds(xMuteHigh, yMuteHigh, wMuteHigh, hMuteHigh);
    }

    titleLink.setBounds       (xUrl, yUrl, wUrl, hUrl);
    
//    txtExtra.setFontHeight (getHeight()/8.f);
//    txtExtra.setBoundingBox(juce::Parallelogram<float>(juce::Rectangle<float>(getWidth()/2.150f,
//                                                                                  getHeight()/9.f,
//                                                                                  getWidth(),
//                                                                                  getHeight()/23.f)));

}
