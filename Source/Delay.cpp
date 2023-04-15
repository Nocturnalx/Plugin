/*
  ==============================================================================

    Delay.cpp
    Created: 11 Apr 2023 1:51:37pm
    Author:  nocturnal

  ==============================================================================
*/

#include "Delay.h"
Delay::Delay(double fs, juce::AudioProcessorValueTreeState * treeState){
  m_sampleRate = fs;

  m_wetness = *treeState->getRawParameterValue("delay_wetness");
  m_isOn = *treeState->getRawParameterValue("delay_toggle");

  tapCnt = 3;
  tapArr = std::unique_ptr <DelayLine []>(new DelayLine[tapCnt]);

  for (int i = 0; i < tapCnt; i++){
    tapArr[i].init(fs, 2);
  }

  tapArr[0].setFeedback(*treeState->getRawParameterValue("tap1_feedback"));
  tapArr[0].setFeedforward(*treeState->getRawParameterValue("tap1_feedforward"));
  tapArr[0].setDelay(*treeState->getRawParameterValue("tap1_delay_time"));

  tapArr[1].setFeedback(*treeState->getRawParameterValue("tap2_feedback"));
  tapArr[1].setFeedforward(*treeState->getRawParameterValue("tap2_feedforward"));
  tapArr[1].setDelay(*treeState->getRawParameterValue("tap2_delay_time"));

  tapArr[2].setFeedback(*treeState->getRawParameterValue("tap3_feedback"));
  tapArr[2].setFeedforward(*treeState->getRawParameterValue("tap3_feedforward"));
  tapArr[2].setDelay(*treeState->getRawParameterValue("tap3_delay_time"));

}

Delay::~Delay(){

}


float Delay::process(float samp){
  if (m_isOn){
    float wetSamp = ((tapArr[0].process(samp) + tapArr[1].process(samp) + tapArr[2].process(samp))/3);
    
    float out = ((1-m_wetness) * samp) + (m_wetness * wetSamp);
    return out;
  }

  return samp;
}


void Delay::setFeedforward(int tap, float feedforward){
  tapArr[tap].setFeedforward(feedforward);
}
void Delay::setFeedback(int tap, float feedback){
  tapArr[tap].setFeedback(feedback);
}
void Delay::setDelay(int tap, float delay){
  tapArr[tap].setDelay(delay);
}

void Delay::setWetness(float wetness){
  m_wetness = wetness;
}


float Delay::getFeedforward(int tap){
  return tapArr[tap].getFeedforward();
}

float Delay::getFeedback(int tap){
  return tapArr[tap].getFeedback();
}

float Delay::getDelay(int tap){
  return tapArr[tap].getDelay();
}

float Delay::getWetness(){
  return m_wetness;
}

void Delay::toggleOnOff(){
  m_isOn = !m_isOn;
}