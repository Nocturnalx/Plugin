/*
  ==============================================================================

    Delay.h
    Created: 11 Apr 2023 1:51:37pm
    Author:  nocturnal

  ==============================================================================
*/

#pragma once

#include "DelayLine.h"
#include <memory>
#include <JuceHeader.h>

class Delay{
  public:
    Delay(double fs, juce::AudioProcessorValueTreeState * treeState);
    ~Delay();

    float process(float samp);

    //set functions

    void setFeedforward(int tap, float feedforward);
    void setFeedback(int tap, float feedback);
    void setDelay(int tap, float delay);
    void setWetness(float wetness);

    //get functions

    float getFeedforward(int tap);
    float getFeedback(int tap);
    float getDelay(int tap);
    float getWetness();

    void toggleOnOff();

  private:
    std::unique_ptr <DelayLine []> tapArr;
    int tapCnt;

    char m_isOn;

    double m_sampleRate;
    float m_wetness;
};