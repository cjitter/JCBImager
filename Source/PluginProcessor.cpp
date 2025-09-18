#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
JCBImagerAudioProcessor::JCBImagerAudioProcessor()
: apvts(*this, nullptr, "PARAMETERS", createParameterLayout())
, m_CurrentBufferSize(0)
{
    // 1) Estado Gen~ (SR/VS por defecto; se reajusta en prepareToPlay)
    m_PluginState = (CommonState*) JCBImager::create(44100, 64);
    JCBImager::reset(m_PluginState);

    // 2) Buffers de entrada/salida para Gen~
    m_InputBuffers  = new t_sample*[JCBImager::num_inputs()];
    m_OutputBuffers = new t_sample*[JCBImager::num_outputs()];

    for (int i = 0; i < JCBImager::num_inputs(); ++i)  m_InputBuffers[i]  = nullptr;
    for (int i = 0; i < JCBImager::num_outputs(); ++i) m_OutputBuffers[i] = nullptr;

    // 3) Vincular listeners APVTS ↔ Gen~
    for (int i = 0; i < JCBImager::num_params(); ++i)
    {
        auto name = juce::String(JCBImager::getparametername(m_PluginState, i));
        if (apvts.getParameter(name) != nullptr)
            apvts.addParameterListener(name, this);
    }

    // 4) Sincronizar valores iniciales APVTS → Gen~ (clamps hardcodeados y alias Dry/Wet)
    for (int i = 0; i < JCBImager::num_params(); ++i)
    {
        auto paramName = juce::String(JCBImager::getparametername(m_PluginState, i));

        if (auto* rp = apvts.getRawParameterValue(paramName))
        {
            float v = rp->load();

            // --- CLAMPS hardcodeados según el export actual de Gen ---
            if (paramName == "a_FREQ1")
                v = juce::jlimit(20.0f, 1000.0f, v);
            else if (paramName == "b_FREQ2")
                v = juce::jlimit(1000.0f, 20000.0f, v);

            else if (paramName == "c_LOW" || paramName == "d_MED" || paramName == "e_HIGH")
                v = juce::jlimit(0.5f, 1.5f, v);

            else if (paramName == "k_LOW_bal" || paramName == "l_MED_bal" || paramName == "m_HIGH_bal"
                  || paramName == "x_DRYWET"  || paramName == "j_input"
                  || paramName == "i_BYPASS"  || paramName == "f_SOLOLOW"
                  || paramName == "g_SOLOMED" || paramName == "h_SOLOHIGH"
                  || paramName == "n_MUTLOW"  || paramName == "o_MUTMED" || paramName == "p_MUTHIGH")
                v = juce::jlimit(0.0f, 1.0f, v);

            // Nota: Gen también expone "freq_high"/"freq_low" internos (idx 6 y 7). No hay control en APVTS.
            // Si el APVTS no tiene ese ID, este if no entra y Gen mantiene sus defaults.

            JCBImager::setparameter(m_PluginState, i, v, nullptr);
        }
    }
}

JCBImagerAudioProcessor::~JCBImagerAudioProcessor()
{
//    JCBImager::destroy(m_PluginState);
//
//    // destruir parámetros del apvts
//    for (int i = 0; i < JCBImager::num_params(); i++)
//    {
//    auto name = juce::String (JCBImager::getparametername(m_PluginState, i));
//    apvts.removeParameterListener(name, this);
//    }
//
    
    // Destruir listeners de parámetros del apvts
        for (int i = 0; i < JCBImager::num_params(); ++i)
        {
            auto name = juce::String(JCBImager::getparametername(m_PluginState, i));
            if (apvts.getParameter(name) != nullptr)
                apvts.removeParameterListener(name, this);
        }

        // Limpiar buffers con protección nullptr
        if (m_InputBuffers != nullptr) {
            for (int i = 0; i < JCBImager::num_inputs(); i++) {
                if (m_InputBuffers[i] != nullptr) {
                    delete[] m_InputBuffers[i];
                    m_InputBuffers[i] = nullptr;
                }
            }
            delete[] m_InputBuffers;
            m_InputBuffers = nullptr;
        }

        if (m_OutputBuffers != nullptr) {
            for (int i = 0; i < JCBImager::num_outputs(); i++) {
                if (m_OutputBuffers[i] != nullptr) {
                    delete[] m_OutputBuffers[i];
                    m_OutputBuffers[i] = nullptr;
                }
            }
            delete[] m_OutputBuffers;
            m_OutputBuffers = nullptr;
        }

        // Destruir Gen~ state al final
        if (m_PluginState != nullptr) {
            JCBImager::destroy(m_PluginState);
            m_PluginState = nullptr;
        }

    
}

//==============================================================================
const String JCBImagerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

#if 0 // Legacy JUCE parameter API disabled: expose only APVTS params to hosts
int JCBImagerAudioProcessor::getNumParameters()
{
    // Disable legacy parameter enumeration: rely on APVTS exclusively
    return 0;
}

////////////////////////////////

float JCBImagerAudioProcessor::getParameter (int index)
{
    juce::ignoreUnused(index);
    // No legacy parameters exposed
    return 0.0f;
}

void JCBImagerAudioProcessor::setParameter (int index, float newValue)
{
    juce::ignoreUnused(index, newValue);
    // No-op: legacy API disabled. All automation must go through APVTS.
}

////////////////////////////////

const String JCBImagerAudioProcessor::getParameterName (int index)
{
    juce::ignoreUnused(index);
    return {};
}

const String JCBImagerAudioProcessor::getParameterText (int index)
{
    juce::ignoreUnused(index);
    return {};
}
#endif

const String JCBImagerAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String JCBImagerAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool JCBImagerAudioProcessor::isInputChannelStereoPair (int index) const
{
    return JCBImager::num_inputs() == 2;
}

bool JCBImagerAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return JCBImager::num_outputs() == 2;
}

bool JCBImagerAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool JCBImagerAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

bool JCBImagerAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double JCBImagerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int JCBImagerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
    // so this should be at least 1, even if you're not really implementing programs.
}

int JCBImagerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void JCBImagerAudioProcessor::setCurrentProgram (int index)
{
}

const String JCBImagerAudioProcessor::getProgramName (int index)
{
    return String();
}

void JCBImagerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void JCBImagerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    // initialize samplerate and vectorsize with the correct values
    m_PluginState->sr = sampleRate;
    m_PluginState->vs = samplesPerBlock;
    
    assureBufferSize(samplesPerBlock);
    //setLatencySamples(mLatencia*sampleRate);
}

void JCBImagerAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}


void JCBImagerAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    //processBlockBypassed(buffer, midiMessages);

    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    
    assureBufferSize(buffer.getNumSamples());
    

    // fill input buffers
    for (int i = 0; i < JCBImager::num_inputs(); i++) {
        if (i < totalNumInputChannels) {
            for (int j = 0; j < m_CurrentBufferSize; j++) {
                m_InputBuffers[i][j] = buffer.getReadPointer(i)[j];
            }
        } else {
            memset(m_InputBuffers[i], 0, m_CurrentBufferSize *  sizeof(double));
        }
    }
    
    // process audio
    JCBImager::perform(m_PluginState,
                           m_InputBuffers,
                           JCBImager::num_inputs(),
                           m_OutputBuffers,
                           JCBImager::num_outputs(),
                           buffer.getNumSamples());
    
    // fill output buffers
    for (int i = 0; i < totalNumOutputChannels; i++) {
        if (i < JCBImager::num_outputs()) {
            for (int j = 0; j < buffer.getNumSamples(); j++) {
                buffer.getWritePointer(i)[j] = m_OutputBuffers[i][j];
            }
        } else {
            buffer.clear (i, 0, buffer.getNumSamples());
        }
    }
}

//==============================================================================
bool JCBImagerAudioProcessor::hasEditor() const
{
    return true; // (change this to true if you choose to supply an editor)
}

AudioProcessorEditor* JCBImagerAudioProcessor::createEditor()
{
    return new JCBImagerAudioProcessorEditor (*this);
    //return new GenericAudioProcessorEditor (*this);
}

//==============================================================================
void JCBImagerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    juce::MemoryOutputStream memoria (destData, true);
    apvts.state.writeToStream (memoria);
}

void JCBImagerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    auto tree = juce::ValueTree::readFromData (data, sizeInBytes);
    if (tree.isValid()) {
        apvts.state = tree;
    }
}

Point<int> JCBImagerAudioProcessor::getSavedSize() const
{
    return editorSize;
}

void JCBImagerAudioProcessor::setSavedSize (const Point<int>& size)
{
    editorSize = size;
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new JCBImagerAudioProcessor();
}

//==============================================================================
// C74 added methods

void JCBImagerAudioProcessor::assureBufferSize(long bufferSize)
{
    if (bufferSize > m_CurrentBufferSize) {
        for (int i = 0; i < JCBImager::num_inputs(); i++) {
            if (m_InputBuffers[i]) delete m_InputBuffers[i];
            m_InputBuffers[i] = new t_sample[bufferSize];
        }
        for (int i = 0; i < JCBImager::num_outputs(); i++) {
            if (m_OutputBuffers[i]) delete m_OutputBuffers[i];
            m_OutputBuffers[i] = new t_sample[bufferSize];
        }
        
        m_CurrentBufferSize = bufferSize;
    }
}

//==============================================================================
// Implementación  para APVTS: createParameterLayout y parameterChanged

juce::AudioProcessorValueTreeState::ParameterLayout JCBImagerAudioProcessor::createParameterLayout()
{
    const int versionHint = 6;

    std::vector <std::unique_ptr<juce::RangedAudioParameter>> params;
    
    
    auto img_freq1 = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("a_FREQ1", versionHint),
                                                              juce::CharPointer_UTF8("Freq X1"),
                                                              NormalisableRange<float>(20.f,
                                                                                       1000.f,
                                                                                       0.1f,
                                                                                       0.5f),
                                                              250.f);
    
    auto img_freq2 = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("b_FREQ2", versionHint),
                                                              juce::CharPointer_UTF8("Freq X2"),
                                                              NormalisableRange<float>(1000.f,
                                                                                       20000.f,
                                                                                       1.0f,
                                                                                       0.25f),
                                                              5000.f);
    
    
    // Helper: width param (interno 0.5..1.5) mostrado como -100..+100
    auto makeWidthParam = [&](const char* id, const char* name)
    {
        auto range = juce::NormalisableRange<float>(0.5f, 1.5f, 0.001f);
        range.setSkewForCentre(1.0f); // más resolución cerca de 1.0

        return std::make_unique<juce::AudioParameterFloat>(
            juce::ParameterID(id, versionHint),
            juce::CharPointer_UTF8(name),
            range,
            1.0f,
            juce::AudioParameterFloatAttributes()
                // 0.5..1.5 -> -100..+100 (0 = neutro)
                .withStringFromValueFunction([](float v, int)
                {
                    const float d = (v - 1.0f) * 200.0f; // -100..+100
                    return juce::String(juce::roundToInt(d));
                })
                // -100..+100 -> 0.5..1.5
                .withValueFromStringFunction([](const juce::String& s)
                {
                    float d = s.getFloatValue();                // -100..+100
                    d = juce::jlimit(-100.0f, 100.0f, d);
                    return 1.0f + 0.5f * (d / 100.0f);          // 0.5..1.5
                })
        );
    };

    auto img_low  = makeWidthParam("c_LOW",  "Low Width");
    auto img_med  = makeWidthParam("d_MED",  "Med Width");
    auto img_high = makeWidthParam("e_HIGH", "High Width");
    
    
    auto img_sololow = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("f_SOLOLOW", versionHint),
                                                               juce::CharPointer_UTF8("Solo Low"),
                                                               0,
                                                               1,
                                                               0);
    
    auto img_solomed = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("g_SOLOMED", versionHint),
                                                               juce::CharPointer_UTF8("Solo Med"),
                                                               0,
                                                               1,
                                                               0);
    
    auto img_solohigh = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("h_SOLOHIGH", versionHint),
                                                               juce::CharPointer_UTF8("Solo High"),
                                                               0,
                                                               1,
                                                               0);
    
    
    auto img_bypass = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("i_BYPASS", versionHint),
                                                               juce::CharPointer_UTF8("Bypass"),
                                                               0,
                                                               1,
                                                               0);
    
    
    
    auto img_input = std::make_unique<juce::AudioParameterInt>(juce::ParameterID("j_input", versionHint),
                                                               juce::CharPointer_UTF8("Input XY-MS"),
                                                               0,
                                                               1,
                                                               1);
    
    auto img_lowbal = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("k_LOW_bal", versionHint),
                                                              juce::CharPointer_UTF8("Low Balance"),
                                                              NormalisableRange<float>(0.f,
                                                                                       1.f,
                                                                                       0.01f,
                                                                                       1.f),
                                                              0.5f);
    
    auto img_medbal = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("l_MED_bal", versionHint),
                                                              juce::CharPointer_UTF8("Med Balance"),
                                                              NormalisableRange<float>(0.f,
                                                                                       1.f,
                                                                                       0.01f,
                                                                                       1.f),
                                                              0.5f);
    
    auto img_highbal = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("m_HIGH_bal", versionHint),
                                                              juce::CharPointer_UTF8("High Balance"),
                                                              NormalisableRange<float>(0.f,
                                                                                       1.f,
                                                                                       0.01f,
                                                                                       1.f),
                                                              0.5f);
    
    auto drywet = std::make_unique<juce::AudioParameterFloat>(juce::ParameterID("x_DRYWET", versionHint),
                                                              juce::CharPointer_UTF8("Dry Wet"),
                                                              NormalisableRange<float>(0.f,
                                                                                       1.f,
                                                                                       0.01f,
                                                                                       1.f),
                                                              1.f);
    
    // --- Band mutes ---
    auto mute_low  = std::make_unique<juce::AudioParameterBool>(
        juce::ParameterID("n_MUTLOW",  versionHint), juce::CharPointer_UTF8("Mute Low"),  false);
    auto mute_mid  = std::make_unique<juce::AudioParameterBool>(
        juce::ParameterID("o_MUTMED",  versionHint), juce::CharPointer_UTF8("Mute Mid"),  false);
    auto mute_high = std::make_unique<juce::AudioParameterBool>(
        juce::ParameterID("p_MUTHIGH", versionHint), juce::CharPointer_UTF8("Mute High"), false);
    
    params.push_back(std::move(img_freq1));
    params.push_back(std::move(img_freq2));
    params.push_back(std::move(img_low));
    params.push_back(std::move(img_med));
    params.push_back(std::move(img_high));
    params.push_back(std::move(img_sololow));
    params.push_back(std::move(img_solomed));
    params.push_back(std::move(img_solohigh));
    params.push_back(std::move(img_bypass));
    
    params.push_back(std::move(img_input));
    params.push_back(std::move(img_lowbal));
    params.push_back(std::move(img_medbal));
    params.push_back(std::move(img_highbal));
    
    params.push_back(std::move(drywet));
    
    params.push_back(std::move(drywet));
    params.push_back(std::move(mute_low));
    params.push_back(std::move(mute_mid));
    params.push_back(std::move(mute_high));

    return { params.begin(), params.end() };
}

void JCBImagerAudioProcessor::parameterChanged(const juce::String& parameterID, float newValue)
{

    // Buscar índice real en Gen por nombre (hardcode style, sin tablas globales)
    int genIndex = -1;
    for (int i = 0; i < JCBImager::num_params(); ++i)
    {
        if (parameterID == juce::String(JCBImager::getparametername(m_PluginState, i)))
        {
            genIndex = i;
            break;
        }
    }
    if (genIndex < 0)
        return; // no existe en Gen (p.ej. controles UI puramente gráficos)

    // Clamps hardcodeados (mismos del constructor)
    float v = newValue;
    if (parameterID == "a_FREQ1")
        v = juce::jlimit(20.0f, 1000.0f, v);
    else if (parameterID == "b_FREQ2")
        v = juce::jlimit(1000.0f, 20000.0f, v);
    else if (parameterID == "c_LOW" || parameterID == "d_MED" || parameterID == "e_HIGH")
        v = juce::jlimit(0.5f, 1.5f, v);
    else if (parameterID == "k_LOW_bal" || parameterID == "l_MED_bal" || parameterID == "m_HIGH_bal"
          || parameterID == "x_DRYWET"  || parameterID == "j_input"
          || parameterID == "i_BYPASS"  || parameterID == "f_SOLOLOW"
          || parameterID == "g_SOLOMED" || parameterID == "h_SOLOHIGH"
          || parameterID == "n_MUTLOW"  || parameterID == "o_MUTMED" || parameterID == "p_MUTHIGH")
        v = juce::jlimit(0.0f, 1.0f, v);

    JCBImager::setparameter(m_PluginState, genIndex, v, nullptr);
}
