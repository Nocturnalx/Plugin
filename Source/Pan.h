/*
  ==============================================================================

    Gain.h
    Created: 26 Jan 2021 6:41:09pm
    Author:  drian

  ==============================================================================
*/

#include <JuceHeader.h>

#pragma once
class Pan
{
public:
	Pan(juce::AudioProcessorValueTreeState * treeState);
	~Pan();

	void setPan(float gain);
	float getPan();
	void initialise(float gain);
	void process(float& lefsample, float& rightsample);

private:
	float m_pan;
};
