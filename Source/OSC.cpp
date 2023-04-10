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

    env->process(output);
  
    //increment the current phase
    m_currentPhase += m_phaseIncrement;
    
    if(m_currentPhase > 2.0*PI)
        m_currentPhase -= 2.0*PI;
    
    return output;
}

void OSC::reset(){
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
    //reset();
}

void OSC::setDepth(float depth){
    m_depth = depth;
}

void OSC::setWaveshape(int shape){
    m_shape = (waveshapes)shape;
    reset();
}

void OSC::setDepthCoef(float coef){
    m_depthCoef = coef;
}

void OSC::setFS(double fs){
    m_fs = fs;

    env->setFS(m_fs);

    m_phaseIncrement = (2*PI*m_frequency)/m_fs;
    m_currentPhase = 0.0;
}


//do we need any of these gets??

//gets current waveshape, used for painting
waveshapes OSC::getWaveshape(){
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


//master defs
Master::Master(double fs){
    //defaults
    setMidiNote(69);
    m_depth = 0.0;
    m_shape = kSine;

    env = new ADSR;

    reset();

    setFS(fs);

    //unique
    m_depthCoef = 1.0;
}

//Harmonic defs

Harmonic::Harmonic(OSC * master, int offset, double fs){
    //defaults
    setMidiNote(69);
    m_depth = 0.0;
    m_shape = kSine;

    env = new ADSR;

    reset();

    setFS(fs);

    //unique
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