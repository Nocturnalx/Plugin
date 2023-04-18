/*
  ==============================================================================

    Biquad.h
    Created: 17 Apr 2023 8:21:39am
    Author:  nocturnal

    This class uses the biquad code from https://github.com/TheWaveWarden/odin2 as a template.

  ==============================================================================
*/

#pragma once

class Biquad {
  public:
  
  Biquad();
  ~Biquad();

  float process(float samp);

  virtual void calculateCoefs()=0;

  void setFreq(float freq);
  void setGain(float gain);

  void toggleOnOff();

  // void setEQParams(float Q, float freq, float gain);
  // void setSampleRate(float SampleRate);

  protected:
  bool m_isOn;

  float m_sampleRate;

  float m_pi = 3.141592653589793238462643383279502;

  float m_freq;
  float m_gain;

  float m_one_over_samplerate;
  float m_b0;
  float m_b1;
  float m_b2;
  float m_a1;
  float m_a2;

  float m_z1;
  float m_z2 ;
};

class Notch : public Biquad {
  
  public:
  Notch();
  ~Notch();

  void calculateCoefs() override;

  void init(float fs, float Q, float freq, float gain, bool isOn);

  void setQ(float Q);

  private:
    float m_Q;
};

class Shelf : public Biquad {

  public:
    Shelf();
    ~Shelf();

    void calculateCoefs() override;

    void init(float fs, float S, float freq, float gain, bool isOn);

    void setS(float S);

  private:
    float m_S;

};