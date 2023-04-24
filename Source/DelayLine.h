/*
  ==============================================================================

    Delay.h
    Created: 10 Apr 2023 11:40:17pm
    Author:  nocturnal

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class DelayLine
{
public:

  DelayLine();
  ~DelayLine();
    
  //initialise function sets up the circular buffer
	//so MUST be called before using the DelayLine

  //max delay in seconds
  void init(float sampleRate, float maxDelay);
  void reset();
    
	//processes a single sample through the delay line
	//sample is passed by reference, with 'in' being 
	//overwritten with the delayed output sample
  float process(float samp);

	//delay time should be set in milliseconds
  void setDelay(float delay);
  void setFeedforward(float ff); // Set feed forward gain
  void setFeedback(float fb); // Set feedback gain

  float getDelay();
  float getFeedforward(); // Set feed forward gain
  float getFeedback(); // Set feedback gain

private:
  //buffer
	juce::AudioSampleBuffer m_buffer;
  long m_bufferSize;

	//delay parameters
	long m_delayInSamples;
	float m_feedForward;
	float m_feedBack;

	//control variables
  long m_indexRead;
  long m_indexWrite;
  double m_sampleRate;
    
};