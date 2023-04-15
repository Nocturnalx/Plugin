/*
  ==============================================================================

    Gain.cpp
    Created: 26 Jan 2021 6:41:09pm
    Author:  drian

  ==============================================================================
*/

#include "Pan.h"
#include <math.h>
#define PI 3.141592654

Pan::Pan(juce::AudioProcessorValueTreeState * treeState)
{
  m_pan = *treeState->getRawParameterValue("pan");
}

Pan::~Pan()
{
}


void Pan::setPan(float pan)
{
	m_pan = pan;
}

float Pan::getPan()
{
	return m_pan;
}

void Pan::initialise(float pan)
{
	setPan(pan);
}

void Pan::process(float &leftSample, float &rightSample)
{
  float pCoeff;
  float leftGain;
  float rightGain;
  
  pCoeff = (PI * (m_pan + 1))/4;
  leftGain = cos(pCoeff);
  rightGain = sin(pCoeff);
  leftSample = leftSample * leftGain;
  rightSample = rightSample * rightGain;
}