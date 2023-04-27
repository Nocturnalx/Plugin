/*
  ==============================================================================

    LFO.cpp

  ==============================================================================
*/

#include "OSC.h"
#include <math.h>
#include "PluginProcessor.h"
#define PI 3.141592654

OSC::OSC(){
    env = std::unique_ptr<ADSR>(new ADSR);

    resetPhase();
}

OSC::~OSC(){}

float OSC::process()
{
    float output = 0.0f;
    
    //get the next sample based on waveshape and depth
    //change this to function pointer?? 
    switch(m_shape)
    {
        case kSine:
            output = renderSine(m_currentPhase); break;
        case kSquare:
            output = renderSquare(m_currentPhase); break;
        case kSaw:
            output = renderSaw(m_currentPhase); break;
        case kTriangle:
            output = renderTriangle(m_currentPhase); break;
        default:
            output = 0.0; break;   
    }

    //gain coefs - velocity, set volume, smoothing
    output *= m_depth * m_depthCoef * m_runOffCoef * m_runUpCoef;

    //note change smoothing

    //note off smoothing
    if (m_runningOff){ //if running off dont do up, otherwise do running up if true
        //lower level gradually
        m_runOffCoef = (-((float)m_runOffPointer/m_runOffLength))+1.0;

        m_runOffPointer++;

        //if coef reaches 0 stop running off reset coef and pointer
        if (m_runOffCoef < 0){

            m_runningOff = false;
            m_runOffCoef = 1;
            m_runOffPointer = 0;

            //if another note is on change note to the stored note
            //else if all other notes are off make sure velocity is 0
            if (!m_noteOn){
                m_depth = 0;
            }
        }

    } else if (m_runningUp){ 
        m_runUpCoef = ((float)m_runUpPointer/m_runUpLength);
        m_runUpPointer++;

        // std::cout << "runup " << m_runUpCoef << std::endl;

        //when at 1 reset everything
        if (m_runUpCoef > 1){
            m_runningUp = false;
            m_runUpCoef = 1;
            m_runUpPointer = 0;
        }
    }

    env->process(output);
  
    //increment the current phase
    m_currentPhase += m_phaseIncrement;
    
    if(m_currentPhase > 2.0*PI)
        m_currentPhase -= 2.0*PI;
    
    return output;
}

void OSC::turnOff(){
    m_noteOn = false; //this only gets called if all are off so will be false
    m_runningOff = true;
    m_runningUp = false;
    m_runOffPointer = 0;
}

void OSC::setDepth(float depth){
    m_depth = depth;
}

//reset smoothing
void OSC::reset(bool noteOn){

    env->reset();
    resetPhase();

    m_noteOn = noteOn;

    //if note on do run off first
    if (noteOn){
        m_runningOff = true;
        m_runOffPointer = 0;
    } 

    //running off here to put runoff before every runup 
    m_runningUp = true;
    m_runUpPointer = 0;
}

void OSC::resetPhase(){
    m_currentPhase = 0.0f;
}

void OSC::setMidiNote(float note){
    m_midiNote = note;

    float a = 440;
    float f;
    f = (a/32)*pow(2,((note-9)/12));
    
    //set frequency
    m_frequency = f;
    m_phaseIncrement = (2*PI*m_frequency)/m_fs;
}

void OSC::setWaveshape(int shape){
    m_shape = shape;
    resetPhase();
}

void OSC::setDepthCoef(float coef){
    m_depthCoef = coef;
}

void OSC::setFS(double fs){
    m_fs = fs;

    env->setFS(m_fs);

    m_phaseIncrement = (2*PI*m_frequency)/m_fs;
    m_currentPhase = 0.0;
    m_runOffLength = 0.05 * fs;
    m_runUpLength = 0.05 * fs;
}


//gets current waveshape, used for painting
int OSC::getWaveshape(){
    return m_shape;
}

//get by harm update()
int OSC::getMidiNote(){
    return m_midiNote;
}


//render different waveforms
double OSC::renderSine(double phase)
{
    return sin(phase); //simple rendering, but fine for current applications
}

double OSC::renderSquare(double phase)
{
    return phase < PI ? -1.0 : 1.0;
}

double OSC::renderSaw(double phase)
{
    return (1.0 / PI) * phase - 1.0;
}

double OSC::renderTriangle(double phase)
{
    return (phase < PI   ? -1.0 + (2.0 / PI) * phase
                                :  3.0 - (2.0 / PI) * phase);
}




//master class
Master::Master(double fs, juce::AudioProcessorValueTreeState * treeState){

    //defaults
    setMidiNote(69);
    m_depth = 0.0;

    setFS(fs);

    setWaveshape(*treeState->getRawParameterValue("master_waveform"));
    m_depthCoef = *treeState->getRawParameterValue("master_depth_coef");

    env->setAttack(*treeState->getRawParameterValue("master_attack"));
    env->setDecay(*treeState->getRawParameterValue("master_decay"));
    env->setSustainTime(*treeState->getRawParameterValue("master_sustain"));
    env->setSustainHeight(*treeState->getRawParameterValue("master_sus_height"));
    env->setRelease(*treeState->getRawParameterValue("master_release"));
}





//Harmonic class

Harmonic::Harmonic(){

    //defaults
    setMidiNote(69);
    m_depth = 0.0;
    m_shape = kSine;
    m_depthCoef = 0.0;
}

void Harmonic::init(double fs, int harm, juce::AudioProcessorValueTreeState * treeState){
    m_harmEnum = harm;

    setFS(fs);

    setDepthCoef(*treeState->getRawParameterValue(harmParamIDs[m_harmEnum][kDepthID]));
    setHarmonicOffset(*treeState->getRawParameterValue(harmParamIDs[m_harmEnum][kOffsetID]));
    setWaveshape(*treeState->getRawParameterValue(harmParamIDs[m_harmEnum][kWaveformID]));

    env->setAttack(*treeState->getRawParameterValue(harmParamIDs[m_harmEnum][kAttackID]));
    env->setDecay(*treeState->getRawParameterValue(harmParamIDs[m_harmEnum][kDecayID]));
    env->setSustainTime(*treeState->getRawParameterValue(harmParamIDs[m_harmEnum][kSustainID]));
    env->setSustainHeight(*treeState->getRawParameterValue(harmParamIDs[m_harmEnum][kSusHeightID]));
    env->setRelease(*treeState->getRawParameterValue(harmParamIDs[m_harmEnum][kReleaseID]));

    resetPhase();
}

void Harmonic::setHarmonicOffset(int offset){
    m_offset = offset;

    setMidiNote(m_midiNote + m_offset);
}

int Harmonic::getOffset(){
    return m_offset;
}

void Harmonic::updateNote(int midiNote){
    
    setMidiNote(midiNote + m_offset);
}