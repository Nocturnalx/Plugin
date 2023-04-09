/*
  ==============================================================================

    LFO.cpp

  ==============================================================================
*/

#include "OSC.h"
#include <math.h>
#include <iostream>
#define PI 3.141592654

OSC::OSC()
{
    m_fs = 44100; //make dyn
    m_frequency = 440;
    m_midiNote = 69;
    m_phaseIncrement = (2*PI*m_frequency)/m_fs;
    m_currentPhase = 0.0;
    m_depth = 0.0;
    m_depthCoef = 1.0;
    m_shape = kSine;
    reset();
}

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

    output *= m_depth * m_depthCoef;
  
    //increment the current phase
    m_currentPhase += m_phaseIncrement;
    
    if(m_currentPhase > 2.0*PI)
        m_currentPhase -= 2.0*PI;
    
    return output;
}

void OSC::reset(){
    m_currentPhase = 0.0f;
}

void OSC::setSamplingFrequency(float fs)
{
    m_fs = fs;
}

// void OSC::setFrequency(float frequency)
// {
//     m_frequency = frequency;
//     m_phaseIncrement = (2*PI*m_frequency)/m_fs;
//     //reset();
// }

void OSC::setMidiNote(float note){
    m_midiNote = note;

    float a = 440;
    float f;
    f = (a/32)*pow(2,((note-9)/12));
    
    //set frequency
    m_frequency = f;
    m_phaseIncrement = (2*PI*m_frequency)/m_fs;
    //reset();
}

void OSC::setDepth(float depth){
    m_depth = depth;
}

void OSC::setWaveshape(int shape){
    m_shape = (Waveshape)shape;
    reset();
}

void OSC::setDepthCoef(float coef){
    m_depthCoef = coef;
}


//do we need any of these gets??

// float OSC::getFrequency(){
//     return m_frequency;
// }

float OSC::getDepth(){
    return m_depth;
}

//gets current waveshape, used for painting
Waveshape OSC::getWaveshape(){
    return m_shape;
}

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



Harmonic::Harmonic(){
    m_offset = 0;
}

void Harmonic::init(OSC * master, int offset){
    m_master = master;
    m_offset = offset;
    m_depthCoef = 0.0;

    update();
}

//takes offset in semi tones (midi val) and sets midi note + freq val
void Harmonic::setHarmonicOffset(int offset){
    m_offset = offset;

    update();
}

int Harmonic::getOffset(){
    return m_offset;
}

void Harmonic::update(){
    m_midiNote = m_master->getMidiNote() + m_offset;
    
    setMidiNote(m_midiNote);
}