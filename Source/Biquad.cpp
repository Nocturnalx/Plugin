/*
  ==============================================================================

    Biquad.cpp
    Created: 17 Apr 2023 8:21:39am
    Author:  nocturnal

    This class uses the biquad code from https://github.com/TheWaveWarden/odin2 as a template.

  ==============================================================================
*/

#include "Biquad.h"
#include <math.h>

Biquad::Biquad(){

 
}

Biquad::~Biquad(){

}

float Biquad::process(float samp){
  if (m_isOn) {

    //this uses direct form 2 from wikipedia page
    //https://en.wikipedia.org/wiki/Digital_biquad_filter
    double left_side = samp - m_z2 * m_a2 - m_z1 * m_a1;
    double output    = m_b2 * m_z2 + m_b1 * m_z1 + m_b0 * left_side;

    //update buffers
    m_z2 = m_z1;
    m_z1 = left_side;

    return output;
  }

  return samp;
}

void Biquad::setFreq(float freq){
    m_freq = freq;
    calculateCoefs();
}

void Biquad::setGain(float gain){
    m_gain = gain;
    calculateCoefs();
}

void Biquad::toggleOnOff(){
  m_isOn = !m_isOn;
}


Notch::Notch(){
  double m_b0 = 0;
  double m_b1 = 0;
  double m_b2 = 0;
  double m_a1 = 0;
  double m_a2 = 0;

  float m_z1 = 0;
  float m_z2 = 0;
}

Notch::~Notch(){

}

void Notch::calculateCoefs() {
  //https://webaudio.github.io/Audio-EQ-Cookbook/audio-eq-cookbook.html

  //this changes depending on filter type
  float alpha = sin(2. *M_PI * m_freq * m_one_over_samplerate) / (2.f * m_Q);

  float A = pow(10, m_gain / 40);
  float a_0 = 1. + alpha / A; // we need to divide by this, since form is unnormalized

  m_b0 = (1. + alpha * A) / a_0;
  m_b1 = -2. * cos(m_freq * 2. *M_PI * m_one_over_samplerate) / a_0; 
  m_b2 = (1 - alpha * A) / a_0;
  m_a1 = m_b1;
  m_a2 = (1 - alpha / A) / a_0;
}

void Notch::init(float fs, float Q, float freq, float gain, bool isOn){

  m_isOn = isOn;

  m_sampleRate = fs;
  m_one_over_samplerate = 1/m_sampleRate;

  m_Q = Q;
  m_freq = freq;
  m_gain = gain;
  calculateCoefs();
}

void Notch::setQ(float Q){
    m_Q = Q;
    calculateCoefs();
}



Shelf::Shelf(){
  double m_b0 = 0;
  double m_b1 = 0;
  double m_b2 = 0;
  double m_a1 = 0;
  double m_a2 = 0;

  float m_z1 = 0;
  float m_z2 = 0;
}

Shelf::~Shelf(){

}

void Shelf::calculateCoefs() {
  //https://webaudio.github.io/Audio-EQ-Cookbook/audio-eq-cookbook.html

  //this changes depending on filter type
  float A = pow(10, m_gain / 40);

  float alpha = (sin(2. *M_PI * m_freq * m_one_over_samplerate) / 2.f) * sqrt(((A + (1/A)) * ((1/m_S) - 1)) + 2);

  float a_0 = 1. + alpha / A; // we need to divide by this, since form is unnormalized

  m_b0 = (1. + alpha * A) / a_0;
  m_b1 = -2. * cos(m_freq * 2. *M_PI * m_one_over_samplerate) / a_0; 
  m_b2 = (1 - alpha * A) / a_0;
  m_a1 = m_b1;
  m_a2 = (1 - alpha / A) / a_0;
  
}

void Shelf::init(float fs, float S, float freq, float gain, bool isOn){

  m_isOn = isOn;

  m_sampleRate = fs;
  m_one_over_samplerate = 1/m_sampleRate;

  m_S = S;
  m_freq = freq;
  m_gain = gain;
  calculateCoefs();
}

void Shelf::setS(float S){
    m_S = S;
    calculateCoefs();
}