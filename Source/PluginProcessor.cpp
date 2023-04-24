/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JoeProjectAudioProcessor::JoeProjectAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
                    treeState(*this, nullptr, "PARAMETERS", createParameterLayout())
#endif
{}

JoeProjectAudioProcessor::~JoeProjectAudioProcessor(){}

//==============================================================================

juce::AudioProcessorValueTreeState::ParameterLayout JoeProjectAudioProcessor::createParameterLayout(){
    juce::AudioProcessorValueTreeState::ParameterLayout layout;

    layout.add(std::make_unique<juce::AudioParameterFloat>("gain", "Gain", 0.0f, 1.0f, 1.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("pan", "Pan", -1.0f, 1.0f, 0.0f));

    //OSC params
    layout.add(std::make_unique<juce::AudioParameterFloat>("master_attack", "Master Attack", 0.0f, 0.5f, 0.1f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("master_decay", "Master Decay", 0.0f, 0.5f, 0.3f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("master_sustain", "Master Sustain", 0.0f, 2.0f, 0.5f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("master_sus_height", "Master Sus Height", 0.0f, 1.0f, 0.4f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("master_release", "Master Release", 0.0f, 0.5f, 0.3f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("master_depth_coef", "Master Depth Coef", 0.0f, 1.0f, 1.0f));
    layout.add(std::make_unique<juce::AudioParameterInt>("master_waveform", "Master Waveform", 0, 3, kSine));

    layout.add(std::make_unique<juce::AudioParameterFloat>("harm1_attack", "harm1 Attack", 0.0f, 0.5f, 0.1f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm1_decay", "harm1 Decay", 0.0f, 0.5f, 0.3f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm1_sustain", "harm1 Sustain", 0.0f, 2.0f, 0.5f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm1_sus_height", "harm1 Sus Height", 0.0f, 1.0f, 0.4f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm1_release", "harm1 Release", 0.0f, 0.5f, 0.3f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm1_depth_coef", "harm1 Depth Coef", 0.0f, 1.0f, 0.0f));
    layout.add(std::make_unique<juce::AudioParameterInt>("harm1_waveform", "harm1 Waveform", 0, 3, kSine));
    layout.add(std::make_unique<juce::AudioParameterInt>("harm1_offset", "harm1 Offset", 0, 12, 5));

    layout.add(std::make_unique<juce::AudioParameterFloat>("harm2_attack", "harm2 Attack", 0.0f, 0.5f, 0.1f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm2_decay", "harm2 Decay", 0.0f, 0.5f, 0.3f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm2_sustain", "harm2 Sustain", 0.0f, 2.0f, 0.5f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm2_sus_height", "harm2 Sus Height", 0.0f, 1.0f, 0.4f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm2_release", "harm2 Release", 0.0f, 0.5f, 0.3f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm2_depth_coef", "harm2 Depth Coef", 0.0f, 1.0f, 0.0f));
    layout.add(std::make_unique<juce::AudioParameterInt>("harm2_waveform", "harm2 Waveform", 0, 3, kSine));
    layout.add(std::make_unique<juce::AudioParameterInt>("harm2_offset", "harm2 Offset", 0, 12, 7));

    layout.add(std::make_unique<juce::AudioParameterFloat>("harm3_attack", "harm3 Attack", 0.0f, 0.5f, 0.1f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm3_decay", "harm3 Decay", 0.0f, 0.5f, 0.3f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm3_sustain", "harm3 Sustain", 0.0f, 2.0f, 0.5f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm3_sus_height", "harm3 Sus Height", 0.0f, 1.0f, 0.4f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm3_release", "harm3 Release", 0.0f, 0.5f, 0.3f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm3_depth_coef", "harm3 Depth Coef", 0.0f, 1.0f, 0.0f));
    layout.add(std::make_unique<juce::AudioParameterInt>("harm3_waveform", "harm3 Waveform", 0, 3, kSine));
    layout.add(std::make_unique<juce::AudioParameterInt>("harm3_offset", "harm3 Offset", 0, 12, 10));

    layout.add(std::make_unique<juce::AudioParameterFloat>("harm4_attack", "harm4 Attack", 0.0f, 0.5f, 0.1f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm4_decay", "harm4 Decay", 0.0f, 0.5f, 0.3f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm4_sustain", "harm4 Sustain", 0.0f, 2.0f, 0.5f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm4_sus_height", "harm4 Sus Height", 0.0f, 1.0f, 0.4f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm4_release", "harm4 Release", 0.0f, 0.5f, 0.3f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm4_depth_coef", "harm4 Depth Coef", 0.0f, 1.0f, 0.0f));
    layout.add(std::make_unique<juce::AudioParameterInt>("harm4_waveform", "harm4 Waveform", 0, 3, kSine));
    layout.add(std::make_unique<juce::AudioParameterInt>("harm4_offset", "harm4 Offset", 0, 12, 12));

    //delay params
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap1_feedback", "Tap1 Feedback", 0.0f, 1.0f, 0.5f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap1_feedforward", "Tap1 Feedforward", 0.0f, 1.0f, 0.5f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap1_delay_time", "Tap1 Delay Time", 0.0f, 2.0f, 0.1f));    

    layout.add(std::make_unique<juce::AudioParameterFloat>("tap2_feedback", "tap2 Feedback", 0.0f, 1.0f, 0.4f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap2_feedforward", "tap2 Feedforward", 0.0f, 1.0f, 0.4f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap2_delay_time", "tap2 Delay Time", 0.0f, 2.0f, 0.3f));    

    layout.add(std::make_unique<juce::AudioParameterFloat>("tap3_feedback", "tap3 Feedback", 0.0f, 1.0f, 0.3f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap3_feedforward", "tap3 Feedforward", 0.0f, 1.0f, 0.3f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap3_delay_time", "tap3 Delay Time", 0.0f, 2.0f, 0.5f));    

    layout.add(std::make_unique<juce::AudioParameterFloat>("delay_wetness", "Delay Wetness", 0.0f, 1.0f, 1.0f));    
    layout.add(std::make_unique<juce::AudioParameterBool>("delay_toggle", "Delay toggle", true));    
    
    //EQ params  
    layout.add(std::make_unique<juce::AudioParameterBool>("eq_toggle", "EQ Toggle", false));    

    layout.add(std::make_unique<juce::AudioParameterFloat>("notch1_fc", "Notch 1 Cutoff", 20.0f, 20000.0f, 500.0f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("notch1_q", "Notch 1 Q", 0.0f, 100.0f, 30.0f));  
    layout.add(std::make_unique<juce::AudioParameterFloat>("notch1_gain", "Notch 1 Gain", 0.0f, 2.0f, 0.1f));  
    layout.add(std::make_unique<juce::AudioParameterBool>("notch1_toggle", "Notch 1 Toggle", false));

    layout.add(std::make_unique<juce::AudioParameterFloat>("notch2_fc", "Notch 2 Cutoff", 20.0f, 20000.0f, 5000.0f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("notch2_q", "Notch 2 Q", 0.0f, 100.0f, 30.0f));  
    layout.add(std::make_unique<juce::AudioParameterFloat>("notch2_gain", "Notch 2 Gain", 0.0f, 2.0f, 2.0f));  
    layout.add(std::make_unique<juce::AudioParameterBool>("notch2_toggle", "Notch 2 Toggle", false));

    layout.add(std::make_unique<juce::AudioParameterFloat>("shelf1_fc", "Shelf 1 Cutoff", 20.0f, 20000.0f, 60.0f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("shelf1_s", "Shelf 1 S", 0.0f, 100.0f, 30.0f));  
    layout.add(std::make_unique<juce::AudioParameterFloat>("shelf1_gain", "Shelf 1 Gain", 0.0f, 2.0f, 0.6f));  
    layout.add(std::make_unique<juce::AudioParameterBool>("shelf1_toggle", "Shelf 1 Toggle", false));

    layout.add(std::make_unique<juce::AudioParameterFloat>("shelf2_fc", "Shelf 2 Cutoff", 20.0f, 20000.0f, 16000.0f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("shelf2_s", "Shelf 2 S", 0.0f, 100.0f, 30.0f));  
    layout.add(std::make_unique<juce::AudioParameterFloat>("shelf2_gain", "Shelf 2 Gain", 0.0f, 2.0f, 0.1f));  
    layout.add(std::make_unique<juce::AudioParameterBool>("shelf2_toggle", "Shelf 2 Toggle", false));

    return layout;
}

const juce::String JoeProjectAudioProcessor::getName() const{
    return JucePlugin_Name;
}

bool JoeProjectAudioProcessor::acceptsMidi() const{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool JoeProjectAudioProcessor::producesMidi() const{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool JoeProjectAudioProcessor::isMidiEffect() const{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double JoeProjectAudioProcessor::getTailLengthSeconds() const{
    return 0.0;
}

int JoeProjectAudioProcessor::getNumPrograms(){
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int JoeProjectAudioProcessor::getCurrentProgram(){
    return 0;
}

void JoeProjectAudioProcessor::setCurrentProgram (int index){}

const juce::String JoeProjectAudioProcessor::getProgramName (int index){
    return {};
}

void JoeProjectAudioProcessor::changeProgramName (int index, const juce::String& newName){}

//==============================================================================
void JoeProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock){
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    std::cout << "Praise the Omnissiah!" << std::endl;

    notesPressed = 0;

    m_GainInstance = std::unique_ptr<Gain>(new Gain(&treeState));

    m_PanInstance = std::unique_ptr<Pan>(new Pan(&treeState));

    m_OSCMaster = std::unique_ptr<Master>(new Master(sampleRate, &treeState));
    
    //defining harmonics
    harmCnt = 4;

    harmArr = std::unique_ptr <Harmonic []>(new Harmonic[harmCnt]);
    harmArr[0].init(sampleRate, kHarm1, &treeState);
    harmArr[1].init(sampleRate, kHarm2, &treeState);
    harmArr[2].init(sampleRate, kHarm3, &treeState);
    harmArr[3].init(sampleRate, kHarm4, &treeState);

    //delay definition
    m_DelayInstance = std::unique_ptr<Delay>(new Delay(sampleRate, &treeState));

    //eq deffinition
    m_EQInstance = std::unique_ptr<EQ>(new EQ(sampleRate, &treeState));

}

void JoeProjectAudioProcessor::releaseResources(){
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool JoeProjectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif


void JoeProjectAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages){
    
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    float* leftData = buffer.getWritePointer(0);
    float* rightData = buffer.getWritePointer(1);

    midiPitchBend = 0;

    if (midiMessages.isEmpty() == false){
        for (const auto metadata : midiMessages){
            auto message = metadata.getMessage();
            // const auto time = metadata.samplePosition;
            if (message.isNoteOn()){

                //reset osc phase, envs and on smoothing
                //if notes pressed = 0 pass noteOn = false 
                m_OSCMaster->reset(notesPressed != 0);
                for (int i = 0; i < harmCnt; i++){
                    harmArr[i].reset(notesPressed != 0);
                }

                //set midi
                midiNotenumber = message.getNoteNumber();
                midiVelocity = message.getVelocity();

                notesPressed++;

            }

            if (message.isNoteOff()){

                notesPressed--;

                //if no more held down turn it all off
                if(notesPressed == 0){

                    m_OSCMaster->turnOff();
                    for (int i = 0; i < harmCnt; i++){
                        harmArr[i].turnOff();
                    }

                    midiVelocity = 0;
                }
            }

            if (message.isPitchWheel()){
                midiPitchBend = ((float)message.getPitchWheelValue()-8191.0)/682.66;
            }
        }
    }

    if (notesPressed > 0){
        //update note and turn up osc depth
        m_OSCMaster->setMidiNote(midiNotenumber+midiPitchBend);
        m_OSCMaster->setDepth((float)midiVelocity/127.0);

        for (int i = 0; i < harmCnt; i++){
            harmArr[i].updateNote(midiNotenumber+midiPitchBend);
            harmArr[i].setDepth((float)midiVelocity/127.0);
        }
    }

    //output signal
    for (int i = 0; i < buffer.getNumSamples(); i++){
        
        //osc output
        float samp = 0;
        samp += m_OSCMaster->process();

        for (int i = 0; i < harmCnt; i++){
            samp += harmArr[i].process();
        }

        samp /= harmCnt + 1;

        //delay proc
        samp = m_DelayInstance->process(samp);

        //eq proc
        samp = m_EQInstance->process(samp);

        //split to stereo
        leftData[i] = samp;
        rightData[i] = samp;

        //global pan
        m_PanInstance->process(leftData[i], rightData[i]);
        m_GainInstance->process(leftData[i], rightData[i]);
    }
}

//==============================================================================
bool JoeProjectAudioProcessor::hasEditor() const{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* JoeProjectAudioProcessor::createEditor(){
    return new JoeProjectAudioProcessorEditor (*this);
}

//==============================================================================
void JoeProjectAudioProcessor::getStateInformation (juce::MemoryBlock& destData){
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    auto state = treeState.copyState();
    std::unique_ptr<juce::XmlElement> xml (state.createXml());
    copyXmlToBinary (*xml, destData);
}

void JoeProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes){
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.

    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
 
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName (treeState.state.getType()))
            treeState.replaceState (juce::ValueTree::fromXml(*xmlState));
}

//this whole section below needs fixing

//overload: global gain, pan etc. and master osc control
void JoeProjectAudioProcessor::updateGlobalParameters(int param, float value){

    //mix values
    if (param == kGain){
        m_GainInstance->setGain(value);
    }

    if (param == kPan){
        m_PanInstance->setPan(value);
    }

    //master OSC values
    if (param == kDepthCoef){
        m_OSCMaster->setDepthCoef(value);
    }

    if (param == kWaveform){
        m_OSCMaster->setWaveshape((int)value);
    }

    if (param == kAttack){
        m_OSCMaster->env->setAttack(value);
    }
    if (param == kDecay){
        m_OSCMaster->env->setDecay(value);
    }
    if (param == kSustain){
        m_OSCMaster->env->setSustainTime(value);
    }
    if (param == kSustainHeight){
        m_OSCMaster->env->setSustainHeight(value);
    }
    if (param == kRelease){
        m_OSCMaster->env->setRelease(value);
    }

    if (param == kWetness){
        m_DelayInstance->setWetness(value);
    }
}


//change params on passed harm instance
void JoeProjectAudioProcessor::updateHarmParameters(int harm, int param, float value){
    
    if (param == kDepthCoef){
        harmArr[harm].setDepthCoef(value);
    }
    if (param == kOffset){
        harmArr[harm].setHarmonicOffset((int)value);
    }
    if (param == kAttack){
        harmArr[harm].env->setAttack(value);
    }
    if (param == kDecay){
        harmArr[harm].env->setDecay(value);
    }
    if (param == kSustain){
        harmArr[harm].env->setSustainTime(value);
    }
    if (param == kSustainHeight){
        harmArr[harm].env->setSustainHeight(value);
    }
    if (param == kRelease){
        harmArr[harm].env->setRelease(value);
    }
    if (param == kWaveform){
        harmArr[harm].setWaveshape((int)value);
    }
}


//for updating specifically delay parameters
void JoeProjectAudioProcessor::updateDelayParameters(int tap, int param, float value){
    if (param == kDelayTime){
        m_DelayInstance->setDelay(tap, value);    
    }

    if (param == kFeedback){
        m_DelayInstance->setFeedback(tap, value);
    }

    if (param == kFeedforward){
        m_DelayInstance->setFeedforward(tap, value);
    }
}


void JoeProjectAudioProcessor::updateNotchParameters(notches notch, int param, float value){
    
    if (kEQControl){
        m_EQInstance->notchArr[notch].setQ(value);
    }

    if (kEQFreq){
        m_EQInstance->notchArr[notch].setFreq(value);
    }

    if (kEQGain) {
        m_EQInstance->notchArr[notch].setGain(value);
    }

    if (kFilterOnOff){
        m_EQInstance->notchArr[notch].toggleOnOff();
    }
}

void JoeProjectAudioProcessor::updateShelfParameters(shelfs shelf, int param, float value){
    
    if (kEQControl){
        m_EQInstance->shelfArr[shelf].setS(value);
    }

    if (kEQFreq){
        m_EQInstance->shelfArr[shelf].setFreq(value);
    }

    if (kEQGain) {
        m_EQInstance->shelfArr[shelf].setGain(value);
    }

    if (kFilterOnOff){
        m_EQInstance->shelfArr[shelf].toggleOnOff();
    }
}

//used to turn effects on or off
void JoeProjectAudioProcessor::toggleOnOff(parameters param){
    if (param == kDelayOnOff){
        m_DelayInstance->toggleOnOff();
    }

    if (param == kEQOnOff){
        m_EQInstance->toggleOnOff();
    }
}
//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter(){
    return new JoeProjectAudioProcessor();
}
