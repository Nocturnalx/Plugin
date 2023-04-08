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

enum Waveshape {
    kSine,
    kTriangle,
    kSaw,
    kSquare
};

class OSC
{
public:
    
    OSC();
    
    float process(); //will output the next LFO value in the range +/-depth
    
    void setSamplingFrequency(float fs);
    // void setFrequency(float frequency);
    void setMidiNote(float note);
    void setDepth(float depth);
    void setDepthCoef(float coef);
    void setWaveshape(int shape); //use one of the four shapes in the enum above
    
    // float getFrequency();
    float getDepth();
    int getMidiNote();
    Waveshape getWaveshape();
    
    void reset();
    
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
    Waveshape m_shape;
};


class Harmonic : public OSC{

  public: 
    Harmonic();

    void init(OSC * master, int offset);

    void setHarmonicOffset(int offset);
    void update();
    int getOffset();

  private:
    OSC * m_master;

    int m_offset;
    
};