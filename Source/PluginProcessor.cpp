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
    layout.add(std::make_unique<juce::AudioParameterFloat>("harm1_sustain", "harm1 Sustain", 0.0f, 0.5f, 0.1f));
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
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap1_delay_time", "Tap1 Delay Time", 0.0f, 1.0f, 0.1f));    

    layout.add(std::make_unique<juce::AudioParameterFloat>("tap2_feedback", "tap2 Feedback", 0.0f, 1.0f, 0.4f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap2_feedforward", "tap2 Feedforward", 0.0f, 1.0f, 0.4f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap2_delay_time", "tap2 Delay Time", 0.0f, 1.0f, 0.3f));    

    layout.add(std::make_unique<juce::AudioParameterFloat>("tap3_feedback", "tap3 Feedback", 0.0f, 1.0f, 0.3f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap3_feedforward", "tap3 Feedforward", 0.0f, 1.0f, 0.3f));    
    layout.add(std::make_unique<juce::AudioParameterFloat>("tap3_delay_time", "tap3 Delay Time", 0.0f, 1.0f, 0.5f));    

    layout.add(std::make_unique<juce::AudioParameterFloat>("delay_wetness", "Delay Wetness", 0.0f, 1.0f, 1.0f));    
    layout.add(std::make_unique<juce::AudioParameterBool>("delay_toggle", "Delay toggle", true));    

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
    selectedHarm = 0;

    harmArr = std::unique_ptr <Harmonic []>(new Harmonic[harmCnt]);

    int offset;
    int waveform;
    float attack;
    float decay;
    float sustain;
    float susHeight;
    float release;

    offset = *treeState.getRawParameterValue("harm1_offset");
    waveform = *treeState.getRawParameterValue("harm1_waveform");
    attack = *treeState.getRawParameterValue("harm1_attack");
    decay = *treeState.getRawParameterValue("harm1_decay");
    sustain = *treeState.getRawParameterValue("harm1_sustain");
    susHeight = *treeState.getRawParameterValue("harm1_sus_height");
    release = *treeState.getRawParameterValue("harm1_release");

    harmArr[0].init(offset, waveform, sampleRate);
    harmArr[0].env->setAttack(attack);
    harmArr[0].env->setDecay(decay);
    harmArr[0].env->setSustainTime(sustain);
    harmArr[0].env->setSustainHeight(susHeight);
    harmArr[0].env->setRelease(release);

    offset = *treeState.getRawParameterValue("harm2_offset");
    waveform = *treeState.getRawParameterValue("harm2_waveform");
    attack = *treeState.getRawParameterValue("harm2_attack");
    decay = *treeState.getRawParameterValue("harm2_decay");
    sustain = *treeState.getRawParameterValue("harm2_sustain");
    susHeight = *treeState.getRawParameterValue("harm2_sus_height");
    release = *treeState.getRawParameterValue("harm2_release");

    harmArr[1].init(offset, waveform, sampleRate);
    harmArr[1].env->setAttack(attack);
    harmArr[1].env->setDecay(decay);
    harmArr[1].env->setSustainTime(sustain);
    harmArr[1].env->setSustainHeight(susHeight);
    harmArr[1].env->setRelease(release);

    offset = *treeState.getRawParameterValue("harm3_offset");
    waveform = *treeState.getRawParameterValue("harm3_waveform");
    attack = *treeState.getRawParameterValue("harm3_attack");
    decay = *treeState.getRawParameterValue("harm3_decay");
    sustain = *treeState.getRawParameterValue("harm3_sustain");
    susHeight = *treeState.getRawParameterValue("harm3_sus_height");
    release = *treeState.getRawParameterValue("harm3_release");

    harmArr[2].init(offset, waveform, sampleRate);
    harmArr[2].env->setAttack(attack);
    harmArr[2].env->setDecay(decay);
    harmArr[2].env->setSustainTime(sustain);
    harmArr[2].env->setSustainHeight(susHeight);
    harmArr[2].env->setRelease(release);

    offset = *treeState.getRawParameterValue("harm4_offset");
    waveform = *treeState.getRawParameterValue("harm4_waveform");
    attack = *treeState.getRawParameterValue("harm4_attack");
    decay = *treeState.getRawParameterValue("harm4_decay");
    sustain = *treeState.getRawParameterValue("harm4_sustain");
    susHeight = *treeState.getRawParameterValue("harm4_sus_height");
    release = *treeState.getRawParameterValue("harm4_release");

    harmArr[3].init(offset, waveform, sampleRate);
    harmArr[3].env->setAttack(attack);
    harmArr[3].env->setDecay(decay);
    harmArr[3].env->setSustainTime(sustain);
    harmArr[3].env->setSustainHeight(susHeight);
    harmArr[3].env->setRelease(release);

    //delay definition
    selectedTap = 0;
    m_DelayInstance = std::unique_ptr<Delay>(new Delay(sampleRate, &treeState));
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

                //reset osc envs
                m_OSCMaster->env->reset();
                for (int i = 0; i < harmCnt; i++){
                    harmArr[i].env->reset();
                }

                //set midi
                midiNotenumber = message.getNoteNumber();
                midiVelocity = message.getVelocity();

                //reset osc phase
                m_OSCMaster->reset();

                notesPressed++;

            }
            if (message.isNoteOff()){

                notesPressed--;

                //if no more held down turn it all off
                if(notesPressed == 0){
                    m_OSCMaster->setDepth(0);
                    for (int i = 0; i < harmCnt; i++){
                        harmArr[i].setDepth(0);
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

        m_OSCMaster->setMidiNote(midiNotenumber+midiPitchBend);
        m_OSCMaster->setDepth((float)midiVelocity/127.0);

        for (int i = 0; i < harmCnt; i++){
            harmArr[i].updateNote(m_OSCMaster->getMidiNote());
            harmArr[i].setDepth((float)midiVelocity/127.0);
        }
    }

    //output signal
    for (int i = 0; i < buffer.getNumSamples(); i++){
        
        float samp = 0;
        samp += m_OSCMaster->process();

        for (int i = 0; i < harmCnt; i++){
            samp += harmArr[i].process();
        }

        samp /= harmCnt + 1;

        // std::cout << "proc " << std::endl;

        samp = m_DelayInstance->process(samp);

        leftData[i] = samp;
        rightData[i] = samp;

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
}

void JoeProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes){
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
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

        // juce::RangedAudioParameter * param = treeState.getParameter("master_waveform");
        // param->setValueNotifyingHost(param->convertTo0to1(value));
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


//overload: change params on passed harm instance
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


//DEPRECATED??????
//overload: if no specific harmonic passed use selected harmonic
void JoeProjectAudioProcessor::updateHarmParameters(int param, float value){
    if (param == kOffset){
        harmArr[selectedHarm].setHarmonicOffset((int)value);
    }
    if (param == kAttack){
        harmArr[selectedHarm].env->setAttack(value);
    }
    if (param == kDecay){
        harmArr[selectedHarm].env->setDecay(value);
    }
    if (param == kSustain){
        harmArr[selectedHarm].env->setSustainTime(value);
    }
    if (param == kSustainHeight){
        harmArr[selectedHarm].env->setSustainHeight(value);
    }
    if (param == kRelease){
        harmArr[selectedHarm].env->setRelease(value);
    }
    if (param == kWaveform){
        harmArr[selectedHarm].setWaveshape((int)value);
    }
}


//for updating specifically delay parameters
void JoeProjectAudioProcessor::updateDelayParameters( int tap, int delayParam, float value){
    if (delayParam == kDelayTime){
        m_DelayInstance->setDelay(tap, value);    
    }

    if (delayParam == kFeedback){
        m_DelayInstance->setFeedback(tap, value);
    }

    if (delayParam == kFeedforward){
        m_DelayInstance->setFeedforward(tap, value);
    }
}


//returns ADSR info for master osc
float JoeProjectAudioProcessor::getOscADSR(parameters param){
    if (param == kAttack){
        return m_OSCMaster->env->getAttack();
    }
    if (param == kDecay){
        return m_OSCMaster->env->getDecay();
    }
    if (param == kSustain){
        return m_OSCMaster->env->getSustain();
    }
    if (param == kSustainHeight){
        return m_OSCMaster->env->getSustainHeight();
    }
    if (param == kRelease){
        return m_OSCMaster->env->getRelease();
    }
    //if none send -1
    return -1;
}

//returns ADSR info for given harmonic
float JoeProjectAudioProcessor::getOscADSR(parameters param, harmonics harm){
    if (param == kAttack){
        return harmArr[harm].env->getAttack();
    }
    if (param == kDecay){
        return harmArr[harm].env->getDecay();
    }
    if (param == kSustain){
        return harmArr[harm].env->getSustain();
    }
    if (param == kSustainHeight){
        return harmArr[harm].env->getSustainHeight();
    }
    if (param == kRelease){
        return harmArr[harm].env->getRelease();
    }
    //if none send -1
    return -1;
}


//sets active harmonic class instance
void JoeProjectAudioProcessor::setHarm(harmonics harm){
    selectedHarm = harm;
}

int JoeProjectAudioProcessor::getSelectedHarm(){
    return selectedHarm;
}

//gets offset from selected harm.
int JoeProjectAudioProcessor::getHarmOffset(){
    return harmArr[selectedHarm].getOffset();
}


void JoeProjectAudioProcessor::setTap(taps tap){
    selectedTap = tap;
}

int JoeProjectAudioProcessor::getSelectedTap(){
    return selectedTap;
}


float JoeProjectAudioProcessor::getDelay(){
    return m_DelayInstance->getDelay(selectedTap);
}

float JoeProjectAudioProcessor::getFeedback(){
    return m_DelayInstance->getFeedback(selectedTap);
}

float JoeProjectAudioProcessor::getFeedforward(){
    return m_DelayInstance->getFeedforward(selectedTap);
}

//used to turn effects on or off
void JoeProjectAudioProcessor::toggleOnOff(parameters param){
    if (param == kDelayOnOff){
        m_DelayInstance->toggleOnOff();
    }
}
//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter(){
    return new JoeProjectAudioProcessor();
}
