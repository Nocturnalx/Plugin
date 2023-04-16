/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class HarmComponent  : public juce::Component,
                       public juce::Slider::Listener
{
public:
    //==============================================================================
    HarmComponent (JoeProjectAudioProcessor &owner, int harm);
    ~HarmComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    JoeProjectAudioProcessor &audioProcessor;

    int m_harmEnum;

    juce::String harmParamIDs[4][8] = {{"harm1_depth_coef", "harm1_waveform", "harm1_offset",
                                "harm1_attack", "harm1_decay", "harm1_sustain", "harm1_sus_height", "harm1_release"},
                                {"harm2_depth_coef", "harm2_waveform", "harm2_offset",
                                "harm2_attack", "harm2_decay", "harm2_sustain", "harm2_sus_height", "harm2_release"},
                                {"harm3_depth_coef", "harm3_waveform", "harm3_offset",
                                "harm3_attack", "harm3_decay", "harm3_sustain", "harm3_sus_height", "harm3_release"},
                                {"harm4_depth_coef", "harm4_waveform", "harm4_offset",
                                "harm4_attack", "harm4_decay", "harm4_sustain", "harm4_sus_height", "harm4_release"}};

    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> depthSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> waveformSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> offsetSliderAttachment;

    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> attackSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> decaySliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> sustainSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> sustainHeightSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> releaseSliderAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> harm_depthSlider;
    std::unique_ptr<juce::Slider> harm_waveformSlider;
    std::unique_ptr<juce::Slider> harm_attackSlider;
    std::unique_ptr<juce::Slider> harm_decaySlider;
    std::unique_ptr<juce::Slider> harm_sustainSlider;
    std::unique_ptr<juce::Slider> harm_releaseSlider;
    std::unique_ptr<juce::Slider> harm_susHeightSlider;
    std::unique_ptr<juce::Slider> harm_offsetSlider;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HarmComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

