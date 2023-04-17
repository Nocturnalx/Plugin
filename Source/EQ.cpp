/*
  ==============================================================================

    EQ.cpp
    Created: 17 Apr 2023 8:11:40am
    Author:  nocturnal

  ==============================================================================
*/

#include "EQ.h"
#include "PluginProcessor.h"

EQ::EQ(double fs, juce::AudioProcessorValueTreeState * treeState){

  m_isOn = *treeState->getRawParameterValue("eq_toggle");

  m_sampleRate = fs;

  notchCnt = 2;
  shelfCnt = 2;
  notchArr = std::unique_ptr<Notch []>(new Notch[notchCnt]);
  shelfArr = std::unique_ptr<Shelf []>(new Shelf[shelfCnt]);

  //needs updating to use juce params
  for (int i = 0; i < notchCnt; i++){

    float Q = *treeState->getRawParameterValue(notchParamIDs[i][kControllID]);
    float freq = *treeState->getRawParameterValue(notchParamIDs[i][kFilterFreqID]);
    float gain = *treeState->getRawParameterValue(notchParamIDs[i][kFilterGainID]);
    bool isOn = *treeState->getRawParameterValue(notchParamIDs[i][kFilterOnOffID]);

    notchArr[i].init(fs, Q, freq, gain, isOn);
  }

  for (int i = 0; i < shelfCnt; i++){

    float S = *treeState->getRawParameterValue(shelfParamIDs[i][kControllID]);
    float freq = *treeState->getRawParameterValue(shelfParamIDs[i][kFilterFreqID]);
    float gain = *treeState->getRawParameterValue(shelfParamIDs[i][kFilterGainID]);
    bool isOn = *treeState->getRawParameterValue(shelfParamIDs[i][kFilterOnOffID]);

    shelfArr[i].init(fs, S, freq, gain, isOn);
  }
}

EQ::~EQ(){

}

float EQ::process(float samp){

  if (m_isOn){

    // std::cout << "samp: " << samp << std::endl;

    float out = (shelfArr[0].process(samp) + notchArr[0].process(samp) + notchArr[1].process(samp) + shelfArr[1].process(samp)) / 4;
    
    // std::cout << "out: " << out << std::endl;

    return out;
  }

 return samp; 
}

void EQ::toggleOnOff(){
  m_isOn = !m_isOn;
}