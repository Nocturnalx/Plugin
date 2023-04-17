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
#include "EQ.h"
#include <math.h>

enum parameters{
  //global
  kGain,
  kPan,

  //osc
  kDepthCoef,
  kWaveform,
  kOffset,
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
  kWetness,

  //EQ 
  kEQGain,
  kEQFreq,
  kEQControl,
  kEQOnOff,
  kFilterOnOff
};

enum waveshapes {
  kSine,
  kTriangle,
  kSaw,
  kSquare
};

enum harmonics{
  kHarm1,
  kHarm2,
  kHarm3,
  kHarm4
};

//for use in arrays to fetch string ids
enum harmIDIndex{
  kDepthID,
  kWaveformID,
  kOffsetID,
  kAttackID,
  kDecayID,
  kSustainID,
  kSusHeightID,
  kReleaseID
};

enum taps{
  kTap1,
  kTap2,
  kTap3
};

//for use in arrays to fetch string ids
enum tapIDIndex{
  kFeedbackID,
  kFeedforwardID,
  kDelayTimeID
};

enum notches{
  kNotch1,
  kNotch2
};

enum shelfs{
  kShelf1,
  kShelf2
};

//for use in arrays to fetch string ids
enum filterIDIndex{
  kControllID, //this is Q or S just first in array
  kFilterFreqID,
  kFilterGainID,
  kFilterOnOffID
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

    void updateGlobalParameters(int param, float value);
    void updateHarmParameters(int harm, int param, float value);
    void updateDelayParameters(int tap, int param, float value);
    void updateNotchParameters(notches notch, int param, float value);
    void updateShelfParameters(shelfs shelf, int param, float value);

    void toggleOnOff(parameters param);

    juce::AudioProcessorValueTreeState treeState;
    juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

private:
    std::unique_ptr<Gain> m_GainInstance;
    std::unique_ptr<Pan> m_PanInstance;
    std::unique_ptr<Delay> m_DelayInstance;

    std::unique_ptr<Master> m_OSCMaster;
    std::unique_ptr<Harmonic []> harmArr;
    std::unique_ptr<EQ> m_EQInstance;

    int harmCnt;

    float midiPitchBend;
    int midiNotenumber;
    int midiVelocity;

    int notesPressed;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JoeProjectAudioProcessor)
};