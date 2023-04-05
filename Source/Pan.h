/*
  ==============================================================================

    Gain.h
    Created: 26 Jan 2021 6:41:09pm
    Author:  drian

  ==============================================================================
*/

#pragma once
class Pan
{
public:
	Pan();
	~Pan();

	void setPan(float gain);
	float getPan();
	void initialise(float gain);
	void process(float& lefsample, float& rightsample);

private:
	float m_pan;
};
