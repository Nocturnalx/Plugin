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

    harmCnt = 4;
    selectedHarm = 0;

    notesPressed = 0;

    harmArr[0].init(&m_OSCInstance, 4);
    harmArr[1].init(&m_OSCInstance, 7);
    harmArr[2].init(&m_OSCInstance, 10);
    harmArr[3].init(&m_OSCInstance, 11);

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

    // int triggerOn = false;
    midiPitchBend = 0;

    if (midiMessages.isEmpty() == false){
        for (const auto metadata : midiMessages){
            auto message = metadata.getMessage();
            // const auto time = metadata.samplePosition;
            if (message.isNoteOn()){

                midiNotenumber = message.getNoteNumber();
                midiVelocity = message.getVelocity();
                m_OSCInstance.reset();

                notesPressed++;

                // triggerOn = true;
            }
            if (message.isNoteOff()){

                //issue #1
                //need to check for if two notes are being pressed 
                //- have note pressed buffer that pushes and pops

                notesPressed--;

                if(notesPressed == 0){
                    m_OSCInstance.setDepth(0);
                    for (int i = 0; i < harmCnt; i++){
                        harmArr[i].setDepth(0);
                    }

                    midiVelocity = 0;
                }
                
                // triggerOn = false;
            }
            if (message.isPitchWheel()){

                midiPitchBend = ((float)message.getPitchWheelValue()-8191.0)/682.66;
                
                // triggerOn = true;
            }
        }
    }

    if (notesPressed > 0){

        m_OSCInstance.setMidiNote(midiNotenumber+midiPitchBend);
        m_OSCInstance.setDepth((float)midiVelocity/127.0);

        for (int i = 0; i < harmCnt; i++){
            harmArr[i].update();
            harmArr[i].setDepth((float)midiVelocity/127.0);
        }
    }

    //output signal
    for (int i = 0; i < buffer.getNumSamples(); i++){
        
        float samp;
        samp = m_OSCInstance.process();

        //why would this not work??? memory access takes longer in loop?? time to proc is too long???
        // for (int i = 0; i < harmCnt; i++){
        //     samp += harmArr[i].process();
        // }

        samp += harmArr[0].process();
        samp += harmArr[1].process();
        samp += harmArr[2].process();
        samp += harmArr[3].process();

        samp /= harmCnt + 1;

        leftData[i] = samp;
        rightData[i] = samp;
        m_PanInstance.process(leftData[i], rightData[i]);
        m_GainInstance.process(leftData[i], rightData[i]);
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
void JoeProjectAudioProcessor::updateGlobalParameters(int param, float value){

    if (param == kGain){
        m_GainInstance.setGain(value);
    }

    if (param == kPan){
        m_PanInstance.setPan(value);
    }

    if (param == kDepth){
        m_OSCInstance.setDepthCoef(value);
    }

    if (param == kWaveform){
        m_OSCInstance.setWaveshape((int)value);
    }
}

//overload, if no specific harmonic passed use selected harmonic
void JoeProjectAudioProcessor::updateHarmParameters(int param, float value){

    if (param == kWaveform){
        harmArr[selectedHarm].setWaveshape((int)value);
    }

    if (param == kOffset){
        harmArr[selectedHarm].setHarmonicOffset((int)value);
    }
}

void JoeProjectAudioProcessor::updateHarmParameters(int harm, int param, float value){
    
    if (param == kDepth){
        harmArr[harm].setDepthCoef(value);
    }

    if (param == kPan){

    }
}

//sets active harmonic class instance
void JoeProjectAudioProcessor::setHarm(int h){
    selectedHarm = h;
}

int JoeProjectAudioProcessor::getSelectedHarm(){
    return selectedHarm;
}

//gets harmonic class instance using index
Harmonic JoeProjectAudioProcessor::getHarm(int h){
    return harmArr[h];
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter(){
    return new JoeProjectAudioProcessor();
}
