/*
  ==============================================================================

    EQ.h
    Created: 17 Apr 2023 8:11:40am
    Author:  nocturnal

  ==============================================================================
*/

#pragma once

#include <memory>
#include "Biquad.h"
#include <JuceHeader.h>

class EQ {
  public:
    
    EQ(double fs, juce::AudioProcessorValueTreeState * treeState);
    ~EQ();;

    float process(float samp);

    void toggleOnOff();

    std::unique_ptr<Notch []> notchArr;
    std::unique_ptr<Shelf []> shelfArr;

  private:
    int notchCnt;
    int shelfCnt;

    bool m_isOn;

    double m_sampleRate;

    juce::String notchParamIDs[2][4] = {{"notch1_q", "notch1_fc", "notch1_gain","notch1_toggle"},
                                      {"notch2_q", "notch2_fc", "notch2_gain","notch2_toggle"}};
    
    juce::String shelfParamIDs[2][4] = {{"shelf1_s", "shelf1_fc", "shelf1_gain","shelf1_toggle"},
                                      {"shelf2_s", "shelf2_fc", "shelf2_gain","shelf2_toggle"}};
};