/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Gain.h"
#include "OSC.h"
#include "Pan.h"
#include <math.h>

enum parameters{
  kGain,
  kDepth,
  kWaveform,
  kPan,
  kOffset,
  kADSR
};

enum ADSRParams{
  kAttack,
  kDecay,
  kSustain,
  kSustainHeight,
  kRelease
};

enum harmonics{
  harm1,
  harm2,
  harm3,
  harm4
};

//==============================================================================
/**
*/
class JoeProjectAudioProcessor  : public juce::AudioProcessor
                            #if JucePlugin_Enable_ARA
                             , public juce::AudioProcessorARAExtension
                            #endif
{
public:
    //==============================================================================
    JoeProjectAudioProcessor();
    ~JoeProjectAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    void updateGlobalParameters(parameters param, waveshapes value);
    void updateGlobalParameters(parameters param, float value);
    void updateGlobalParameters(parameters param, ADSRParams param2, float value);

    void updateHarmParameters(parameters param, float value);
    void updateHarmParameters(parameters param, waveshapes value);
    void updateHarmParameters(parameters param, ADSRParams param2, float value);
    void updateHarmParameters(harmonics harm, parameters param, float value);

    float getOscADSR(ADSRParams param);
    float getOscADSR(ADSRParams param, harmonics harm);

    int getSelectedHarm();
    void setHarm(harmonics harm);
    int getHarmOffset(harmonics harm);

private:
    Gain * m_GainInstance;
    Pan * m_PanInstance;
    Master * m_OSCMaster;
    Harmonic * harmArr[4];

    int harmCnt;
    int selectedHarm;

    float midiPitchBend;
    int midiNotenumber;
    int midiVelocity;

    int notesPressed;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JoeProjectAudioProcessor)
};
