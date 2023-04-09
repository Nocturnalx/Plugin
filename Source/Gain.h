/*
  ==============================================================================

    Gain.h
    Created: 26 Jan 2021 6:41:09pm
    Author:  drian

  ==============================================================================
*/

#pragma once
class Gain{
	
public:
	Gain();
	~Gain();

	void setGain(float gain);
	float getGain();
	void initialise(float gain);
	void process(float& leftsample, float& rightsample);

protected:
	float m_gain;
};