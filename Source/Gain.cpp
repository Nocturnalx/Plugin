/*
  ==============================================================================

    Gain.cpp
    Created: 26 Jan 2021 6:41:09pm
    Author:  drian

  ==============================================================================
*/

#include "Gain.h"

Gain::Gain()
{
  m_gain = 1;
}

Gain::~Gain()
{
}

void Gain::setGain(float gain)
{
	m_gain = gain;
}

float Gain::getGain()
{
	return m_gain;
}

void Gain::initialise(float gain)
{
	setGain(gain);
}

void Gain::process(float &leftSample, float &rightSample)
{
	leftSample *= m_gain;
	rightSample *= m_gain;
}