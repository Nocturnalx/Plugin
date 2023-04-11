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

class Delay{
  public:
    Delay(double fs);
    ~Delay();

    float process(float samp);

    //set functions 

    //get functions

  private:
  std::unique_ptr <DelayLine []> tapArr;
  int tapCnt;

  double m_sampleRate;
};