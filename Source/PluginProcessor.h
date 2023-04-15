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
#include "Delay.h"
#include <math.h>

enum parameters{
  //global
  kGain,
  kPan,

  //osc params
  kDepthCoef,
  kWaveform,
  kOffset,

  //ADSR params
  kAttack,
  kDecay,
  kSustain,
  kSustainHeight,
  kRelease,
  
  //delay params
  kFeedback,
  kFeedforward,
  kDelayTime,
  kDelayOnOff,
  kWetness
};

enum waveshapes {
  kSine,
  kTriangle,
  kSaw,
  kSquare
};

enum harmonics{
  harm1,
  harm2,
  harm3,
  harm4
};

enum taps{
  tap1,
  tap2,
  tap3
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

    // void updateGlobalParameters(parameters param, waveshapes value);
    void updateGlobalParameters(int param, float value);
    // void updateGlobalParameters(parameters param, parameters param2, float value);

    void updateHarmParameters(int param, float value);
    // void updateHarmParameters(parameters param, waveshapes value);
    // void updateHarmParameters(parameters param, parameters param2, float value);
    void updateHarmParameters(int harm, int param, float value);

    void updateDelayParameters(int tap, int delayParam, float value);

    float getOscADSR(parameters param);
    float getOscADSR(parameters param, harmonics harm);

    int getSelectedHarm();
    void setHarm(harmonics harm);
    int getHarmOffset();

    void setTap(taps tap);
    int getSelectedTap();

    float getDelay();
    float getFeedback();
    float getFeedforward();
    void toggleOnOff(parameters param);

    juce::AudioProcessorValueTreeState treeState;
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    

private:
    std::unique_ptr<Gain> m_GainInstance;
    std::unique_ptr<Pan> m_PanInstance;
    std::unique_ptr<Delay> m_DelayInstance;

    std::unique_ptr<Master> m_OSCMaster;
    std::unique_ptr<Harmonic []> harmArr;

    int harmCnt;
    int selectedHarm;

    int selectedTap;

    float midiPitchBend;
    int midiNotenumber;
    int midiVelocity;

    int notesPressed;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JoeProjectAudioProcessor)
};