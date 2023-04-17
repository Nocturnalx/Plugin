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

  double m_sampleRate;

  double m_freq;
  double m_gain;

  double m_one_over_samplerate;
  double m_b0;
  double m_b1;
  double m_b2;
  double m_a1;
  double m_a2;

  double m_z1;
  double m_z2 ;
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