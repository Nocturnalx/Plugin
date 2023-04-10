/*
  ==============================================================================

    ADSR.h
    Created: 9 Apr 2023 6:45:06am
    Author:  nocturnal

  ==============================================================================
*/

#pragma once

class ADSR{
	
public:
	ADSR();
	~ADSR();

	void process(float& sample);

	void reset();

	void setAttack(float attackTime);
	void setDecay(float decayTime);
	void setSustainTime(float sustainTime);
	void setSustainHeight(float sustainHeight);
	void setRelease(float releaseTime);
	void setFS(double fs);

	float getAttack();
	float getDecay();
	float getSustain();
	float getSustainHeight();
	float getRelease();

private:
	// attack time etc are in samples
	int m_attackTime;
	int m_decayTime;
	int m_sustainTime;
	float m_sustainHeight;
	int m_releaseTime;

	//these values are in seconds
	float m_attackTimeSec;
	float m_decayTimeSec;
	float m_sustainTimeSec;
	float m_releaseTimeSec;

	int currentSample;

	double m_fs;
};