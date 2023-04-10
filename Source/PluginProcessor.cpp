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
                       )
#endif
{}

JoeProjectAudioProcessor::~JoeProjectAudioProcessor(){}

//==============================================================================
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

    m_GainInstance = new Gain;

    m_PanInstance = new Pan;

    m_OSCMaster = new Master(sampleRate);

    harmCnt = 4;
    selectedHarm = 0;
    
    Harmonic * harmPointer;
    
    harmPointer = new Harmonic(m_OSCMaster, 4, sampleRate);
    harmArr[0] = harmPointer;
    harmPointer = new Harmonic(m_OSCMaster, 7, sampleRate);
    harmArr[1] = harmPointer;
    harmPointer = new Harmonic(m_OSCMaster, 10, sampleRate);
    harmArr[2] = harmPointer;
    harmPointer = new Harmonic(m_OSCMaster, 11, sampleRate);
    harmArr[3] = harmPointer;
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
                    harmArr[i]->env->reset();
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
                        harmArr[i]->setDepth(0);
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
            harmArr[i]->update();
            harmArr[i]->setDepth((float)midiVelocity/127.0);
        }
    }

    //output signal
    for (int i = 0; i < buffer.getNumSamples(); i++){
        
        float samp = 0;
        samp += m_OSCMaster->process();

        for (int i = 0; i < harmCnt; i++){
            samp += harmArr[i]->process();
        }

        samp /= harmCnt + 1;

        // std::cout << "samp: " << samp << std::endl;

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

//global gain, pan etc. and master osc control
void JoeProjectAudioProcessor::updateGlobalParameters(parameters param, float value){

    //mix values
    if (param == kGain){
        m_GainInstance->setGain(value);
    }

    if (param == kPan){
        m_PanInstance->setPan(value);
    }

    //master OSC values
    if (param == kDepth){
        m_OSCMaster->setDepthCoef(value);
    }
}

//overload: waveshapes
void JoeProjectAudioProcessor::updateGlobalParameters(parameters param, waveshapes value){

    if (param == kWaveform){
        m_OSCMaster->setWaveshape(value);
    }
}

//overload for two specifiers and a value (ADSR)
void JoeProjectAudioProcessor::updateGlobalParameters(parameters param, ADSRParams param2, float value){

    if (param == kADSR){
        if (param2 == kAttack){
            m_OSCMaster->env->setAttack(value);
        }
        if (param2 == kDecay){
            m_OSCMaster->env->setDecay(value);
        }
        if (param2 == kSustain){
            m_OSCMaster->env->setSustainTime(value);
        }
        if (param2 == kSustainHeight){
            m_OSCMaster->env->setSustainHeight(value);
        }
        if (param2 == kRelease){
            m_OSCMaster->env->setRelease(value);
        }
    }
}

//overload: change params on passed harm instance
void JoeProjectAudioProcessor::updateHarmParameters(harmonics harm, parameters param, float value){
    
    if (param == kDepth){
        harmArr[harm]->setDepthCoef(value);
    }
}

//overload: if no specific harmonic passed use selected harmonic
void JoeProjectAudioProcessor::updateHarmParameters(parameters param, float value){
    if (param == kOffset){
        harmArr[selectedHarm]->setHarmonicOffset((int)value);
    }
}

//overload: waveshapes
void JoeProjectAudioProcessor::updateHarmParameters(parameters param, waveshapes value){

    if (param == kWaveform){
        harmArr[selectedHarm]->setWaveshape(value);
    }
}

//overload: for two specifiers and a value (ADSR)
void JoeProjectAudioProcessor::updateHarmParameters(parameters param, ADSRParams param2, float value){

    if (param == kADSR){
        if (param2 == kAttack){
            harmArr[selectedHarm]->env->setAttack(value);
        }
        if (param2 == kDecay){
            harmArr[selectedHarm]->env->setDecay(value);
        }
        if (param2 == kSustain){
            harmArr[selectedHarm]->env->setSustainTime(value);
        }
        if (param2 == kSustainHeight){
            harmArr[selectedHarm]->env->setSustainHeight(value);
        }
        if (param2 == kRelease){
            harmArr[selectedHarm]->env->setRelease(value);
        }
    }
}

//returns ADSR info for master osc
float JoeProjectAudioProcessor::getOscADSR(ADSRParams param){
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

float JoeProjectAudioProcessor::getOscADSR(ADSRParams param, harmonics harm){
    if (param == kAttack){
        return harmArr[harm]->env->getAttack();
    }
    if (param == kDecay){
        return harmArr[harm]->env->getDecay();
    }
    if (param == kSustain){
        return harmArr[harm]->env->getSustain();
    }
    if (param == kSustainHeight){
        return harmArr[harm]->env->getSustainHeight();
    }
    if (param == kRelease){
        return harmArr[harm]->env->getRelease();
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

//gets harmonic class instance using index
int JoeProjectAudioProcessor::getHarmOffset(harmonics harm){
    return harmArr[harm]->getOffset();
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter(){
    return new JoeProjectAudioProcessor();
}
