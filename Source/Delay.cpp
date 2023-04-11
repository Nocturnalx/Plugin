/*
  ==============================================================================

    Delay.cpp
    Created: 11 Apr 2023 1:51:37pm
    Author:  nocturnal

  ==============================================================================
*/

#include "Delay.h"
Delay::Delay(double fs){
  m_sampleRate = fs;

  tapCnt = 3;
  tapArr = std::unique_ptr <DelayLine []>(new DelayLine[tapCnt]);

  for (int i = 0; i < tapCnt; i++){
    tapArr[i].init(fs, 2);
  }

  tapArr[0].setFeedback(0.5);
  tapArr[0].setFeedforward(0.5);
  tapArr[0].setDelay(0.1);
  
  tapArr[1].setFeedback(0.4);
  tapArr[1].setFeedforward(0.4);
  tapArr[1].setDelay(0.2);
  
  tapArr[2].setFeedback(0.3);
  tapArr[2].setFeedforward(0.3);
  tapArr[2].setDelay(0.5);

}

Delay::~Delay(){

}


float Delay::process(float samp){
  float out = tapArr[0].process(samp) + tapArr[1].process(samp) + tapArr[2].process(samp);

  return out;
}

