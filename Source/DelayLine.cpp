/*
  ==============================================================================

    Delay.cpp
    Created: 10 Apr 2023 11:40:17pm
    Author:  nocturnal

  ==============================================================================
*/

#include "DelayLine.h"

DelayLine::DelayLine()
{
	m_delayInSamples = 0;
	m_bufferSize = 0;
	m_indexRead = 0; // Read head position for circular buffer
	m_indexWrite = 0; // Write head position for circular buffer
	m_sampleRate = 0;
	m_feedForward = 0;
	m_feedBack = 0;
}

DelayLine::~DelayLine(){

}

void DelayLine::init(float sampleRate, float maxDelay)
{
	m_bufferSize = (maxDelay*sampleRate); // Calculate buffer size in samples
	m_buffer.setSize(1,m_bufferSize,false); // Set up the circular buffer as an audio buffer
	reset();

	//we need to store the sample rate in our class so we can convert
	//incoming delay times in MS into samples
  	m_sampleRate = sampleRate;
}

void DelayLine::reset()
{
	//flush the buffer - fill it with zeroes
	m_buffer.clear(0,0,m_bufferSize);

    //reset indexes
    m_indexRead = 0; // Read head is position 0
    m_indexWrite = 0; // Write head is position 0
}

float DelayLine::process(float samp)
{
	//get a pointer to the circular buffer
	float* buff = m_buffer.getWritePointer(0); // Get a pointer to the audio buffer

    
	float yn = buff[m_indexRead]; // The delayed sample
	float xn = (samp+(m_feedBack*yn)); // The undelayed (current) sample plus feedback

    if(m_delayInSamples == 0) // Check for a special case of no delay
        yn = xn;

	buff[m_indexWrite] = xn; // Write the current sample to the write position

	
    // Increase the read head position. Check to see if it has gone off the edge of the buffer
	m_indexRead++;
    if(m_indexRead >= m_bufferSize)
        m_indexRead = 0;
        
    // Increase the write head position. Check to see if it has gone off the edge of the buffer    
    m_indexWrite++;
    if(m_indexWrite >= m_bufferSize)
        m_indexWrite = 0;
    
	samp = (yn+(m_feedForward*samp)); // Return the delayed sample back to the line which called this method
	return (samp);
}

void DelayLine::setFeedforward(float gain)
{
    m_feedForward = gain;
}

void DelayLine::setFeedback(float gain)
{
    m_feedBack = gain;
}

void DelayLine::setDelay(float delay)
{
	m_delayInSamples = delay * m_sampleRate; // Calculate delay in samples

	
	// Set the read head to enable the delay
	m_indexRead = m_indexWrite - m_delayInSamples;
	if (m_indexRead < 0)
		m_indexRead += m_bufferSize;
}

float DelayLine::getFeedforward()
{
    return m_feedForward;
}

float DelayLine::getFeedback()
{
    return m_feedBack;
}

float DelayLine::getDelay()
{
	return m_delayInSamples/m_sampleRate; // Return the delay in samples
}