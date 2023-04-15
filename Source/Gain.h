/*
  ==============================================================================

    Gain.h
    Created: 26 Jan 2021 6:41:09pm
    Author:  drian

  ==============================================================================
*/

#include <JuceHeader.h>

#pragma once
class Gain{
	
public:
	Gain(juce::AudioProcessorValueTreeState * treeState);
	~Gain();

	void setGain(float gain);
	float getGain();
	void initialise(float gain);
	void process(float& leftsample, float& rightsample);

protected:
	float m_gain;
};