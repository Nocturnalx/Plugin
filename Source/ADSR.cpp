/*
  ==============================================================================

    ADSR.cpp
    Created: 9 Apr 2023 6:45:06am
    Author:  nocturnal

  ==============================================================================
*/

#include "ADSR.h"
#include <iostream>

//ADSR defs
ADSR::ADSR(){
  //defaults
  m_attackTimeSec = 0.1;
  m_decayTimeSec = 0.3;
  m_sustainTimeSec = 0.5;
  m_releaseTimeSec = 0.3;
  m_sustainHeight = 0.4;

  setFS(44100);
}

void ADSR::process(float& sample){

  //this is only linear atm (issue #3)
  float coef = 0;

  if (currentSample < m_attackTime){
    coef = ((float)currentSample/m_attackTime);

  } else if (currentSample < m_attackTime + m_decayTime){
    //y = mx + c, this could be optimised?
    coef = (((-1 + m_sustainHeight) / m_decayTime) * ((float)currentSample-m_attackTime)) + 1;

  } else if (currentSample < m_attackTime + m_decayTime + m_sustainTime){
    coef = (float)m_sustainHeight;    

  } else if (currentSample < m_attackTime + m_decayTime + m_sustainTime + m_releaseTime){
    //y = mx + c, this could be optimised?
    coef = (-(m_sustainHeight/m_releaseTime) * ((float)currentSample - m_attackTime - m_decayTime - m_sustainTime)) + m_sustainHeight;
  }

  sample *= coef;

  currentSample++;
}

void ADSR::reset(){
  currentSample = 0;
}

void ADSR::setAttack(float attackTime){
  m_attackTimeSec = attackTime;
  m_attackTime = (int)(attackTime*m_fs);
}

void ADSR::setDecay(float decayTime){
  m_decayTimeSec = decayTime;
  m_decayTime = (int)(decayTime*m_fs);
}

void ADSR::setSustainTime(float sustainTime){
  m_sustainTimeSec = sustainTime;
  m_sustainTime = (int)(sustainTime*m_fs);
}

void ADSR::setSustainHeight(float sustainHeight){
  m_sustainHeight = sustainHeight;
}

void ADSR::setRelease(float releaseTime){
  m_releaseTimeSec = releaseTime;
  m_releaseTime = (int)(releaseTime*m_fs);
}

void ADSR::setFS(double fs){
  m_fs = fs;
  
  m_attackTime = m_attackTimeSec * m_fs;
  m_decayTime = m_decayTimeSec * m_fs;
  m_sustainTime = m_sustainTimeSec * m_fs;
  m_releaseTime = m_releaseTimeSec * m_fs;
}

//returns ADSR timings in secs (for GUI)

float ADSR::getAttack(){
  return m_attackTimeSec;
}

float ADSR::getDecay(){
  return m_decayTimeSec;
}

float ADSR::getSustain(){
  return m_sustainTimeSec;
}

float ADSR::getSustainHeight(){
  return m_sustainHeight;
}

float ADSR::getRelease(){
  return m_releaseTimeSec;
}