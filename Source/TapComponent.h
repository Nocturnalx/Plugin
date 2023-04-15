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
#include "PluginEditor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TapComponent  : public juce::Component,
                      public juce::Slider::Listener
{
public:
    //==============================================================================
    TapComponent (JoeProjectAudioProcessor &owner, int tap);
    ~TapComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    JoeProjectAudioProcessor &audioProcessor;

    int m_tapEnum;

    juce::String paramIDs[4][8] = {{"tap1_feedback", "tap1_feedforward", "tap1_delay_time"},
                                  {"tap2_feedback", "tap2_feedforward", "tap2_delay_time"},
                                  {"tap3_feedback", "tap3_feedforward", "tap3_delay_time"}};

    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> feedbackSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> feedforwardSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> delayTimeSliderAttachment;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> tap_feedbackSlider;
    std::unique_ptr<juce::Slider> tap_feedforwardSlider;
    std::unique_ptr<juce::Slider> tap_delaySlider;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TapComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

