/*
  ==============================================================================

    LFO.h
    Created: 24 Oct 2017 12:58:50pm
    Author: Matthew Stephenson (m.r.stephenson@hud.ac.uk
 
    Simple oscillator class implements four basic oscillator types:
        Sine
        Square
        Saw
        Triangle

    These are not band limited, but should be fine in an LFO.
 
    Also note that the frequency and depth values can be abruptly changed, so
    please handle any interpolation yourself.
 
    Each oscillator will provide an outptu sample when process is called - this
    sample is in the range +/-m_depth.
 
    As this is for an LFO, a default frequency of 1Hz is defined. There is also
    a defaut sampling frequency of 44.1KHz, but please initialise this as necessary
 
    This class does have a dependancy on JUCE - but only for the value of double_Pi
    and the sine function in renderSine. These can easilly be replaced with your
    own definition on PI and the standard c math header for sin.

  ==============================================================================
*/

#pragma once

#include "ADSR.h"
#include <memory>
#include <JuceHeader.h>

class OSC{
  public:
    
    OSC();
    ~OSC();
    
    float process(); //will output the next LFO value in the range +/-depth
    
    void setMidiNote(float note);
    void setDepth(float depth);
    void setDepthCoef(float coef);
    void setWaveshape(int shape); //use one of the four shapes in the enum above
    void setFS(double fs);
    
    int getMidiNote();
    int getWaveshape();

    void turnOff();
    
    void reset(bool noteOn);
    void resetPhase();

    // ADSR * env;
    std::unique_ptr<ADSR> env;
    
  protected:
    
    double renderSine(double phase);
    double renderSquare(double phase);
    double renderSaw(double phase);
    double renderTriangle(double phase);
    
    double m_fs;
    double m_frequency;
    double m_phaseIncrement;
    double m_currentPhase;
    float  m_depth;
    float m_depthCoef;
    int m_midiNote;
    int m_shape;

    int m_storedNote;

    bool m_noteOn = false;

    int m_runOffPointer = 0;
    int m_runOffLength;
    bool m_runningOff = false;
    float m_runOffCoef = 1;

    int m_runUpPointer = 0;
    int m_runUpLength;
    bool m_runningUp = false;
    float m_runUpCoef = 1;;

    int noteToBePlayed;
};

class Master : public OSC{
  public:
    Master(double fs, juce::AudioProcessorValueTreeState * treeState);
};

class Harmonic : public OSC{

  public: 
    Harmonic();

    void init(double fs, int harm, juce::AudioProcessorValueTreeState * treeState);

    void setHarmonicOffset(int offset);
    void updateNote(int midiNote);
    int getOffset();

  private:
    std::unique_ptr<Master> m_master;

    int m_harmEnum;
    int m_offset;

    juce::String harmParamIDs[4][8] = {{"harm1_depth_coef", "harm1_waveform", "harm1_offset",
                                "harm1_attack", "harm1_decay", "harm1_sustain", "harm1_sus_height", "harm1_release"},
                                {"harm2_depth_coef", "harm2_waveform", "harm2_offset",
                                "harm2_attack", "harm2_decay", "harm2_sustain", "harm2_sus_height", "harm2_release"},
                                {"harm3_depth_coef", "harm3_waveform", "harm3_offset",
                                "harm3_attack", "harm3_decay", "harm3_sustain", "harm3_sus_height", "harm3_release"},
                                {"harm4_depth_coef", "harm4_waveform", "harm4_offset",
                                "harm4_attack", "harm4_decay", "harm4_sustain", "harm4_sus_height", "harm4_release"}};
};