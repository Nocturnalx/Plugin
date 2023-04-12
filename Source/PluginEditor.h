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
class JoeProjectAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                        public juce::Slider::Listener,
                                        public juce::Button::Listener
{
public:
    //==============================================================================
    JoeProjectAudioProcessorEditor (JoeProjectAudioProcessor& owner);
    ~JoeProjectAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void repaintWfButtons(std::unique_ptr<juce::TextButton> & newButton);
    void repaintHarmWfButtons(int harmWaveform);
    void repaintSelectButtons(std::unique_ptr<juce::TextButton> & newButton);
    void repaintDelayButtons(std::unique_ptr<juce::TextButton> & newButton);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    JoeProjectAudioProcessor& audioProcessor;

    int harmWaveformArr[4] = {0,0,0,0};
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> effects_group;
    std::unique_ptr<juce::GroupComponent> effects_group2;
    std::unique_ptr<juce::GroupComponent> master_group;
    std::unique_ptr<juce::GroupComponent> harmonics_group;
    std::unique_ptr<juce::Slider> m_depthSlider;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Slider> m_gainSlider;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::TextButton> m_sineButton;
    std::unique_ptr<juce::TextButton> m_triangleButton;
    std::unique_ptr<juce::TextButton> m_sawButton;
    std::unique_ptr<juce::TextButton> m_squareButton;
    std::unique_ptr<juce::Slider> m_panSlider;
    std::unique_ptr<juce::Label> Pan_label;
    std::unique_ptr<juce::TextButton> harm_sineButton;
    std::unique_ptr<juce::TextButton> harm_triangleButton;
    std::unique_ptr<juce::TextButton> harm_sawButton;
    std::unique_ptr<juce::TextButton> harm_squareButton;
    std::unique_ptr<juce::Slider> harm1_depthSlider;
    std::unique_ptr<juce::Slider> harm_offsetSlider;
    std::unique_ptr<juce::Slider> harm2_depthSlider;
    std::unique_ptr<juce::Slider> harm3_depthSlider;
    std::unique_ptr<juce::Slider> harm4_depthSlider;
    std::unique_ptr<juce::TextButton> harm1_selectButton;
    std::unique_ptr<juce::TextButton> harm2_selectButton;
    std::unique_ptr<juce::TextButton> harm3_selectButton;
    std::unique_ptr<juce::TextButton> harm4_selectButton;
    std::unique_ptr<juce::Slider> m_attackSlider;
    std::unique_ptr<juce::Slider> m_decaySlider;
    std::unique_ptr<juce::Slider> m_sustainSlider;
    std::unique_ptr<juce::Slider> m_releaseSlider;
    std::unique_ptr<juce::Slider> harm_attackSlider;
    std::unique_ptr<juce::Slider> harm_decaySlider;
    std::unique_ptr<juce::Slider> harm_sustainSlider;
    std::unique_ptr<juce::Slider> harm_releaseSlider;
    std::unique_ptr<juce::Label> attack_label;
    std::unique_ptr<juce::Label> decay_label;
    std::unique_ptr<juce::Label> sustain_label;
    std::unique_ptr<juce::Label> release_label;
    std::unique_ptr<juce::Label> attack_label2;
    std::unique_ptr<juce::Label> decay_label2;
    std::unique_ptr<juce::Label> sustain_label2;
    std::unique_ptr<juce::Label> release_label2;
    std::unique_ptr<juce::Slider> m_sustainHeightSlider;
    std::unique_ptr<juce::Slider> harm_sustainHeightSlider;
    std::unique_ptr<juce::Label> sustainHeight_label;
    std::unique_ptr<juce::Label> sustainHeight_label2;
    std::unique_ptr<juce::Label> time_label;
    std::unique_ptr<juce::Label> time_label2;
    std::unique_ptr<juce::TextButton> tap1_selectButton;
    std::unique_ptr<juce::TextButton> tap2_selectButton;
    std::unique_ptr<juce::TextButton> tap3_selectButton;
    std::unique_ptr<juce::Slider> tap_feedforwardSlider;
    std::unique_ptr<juce::Slider> tap_delaySlider;
    std::unique_ptr<juce::Slider> tap_feedbackSlider;
    std::unique_ptr<juce::Label> feedback_label;
    std::unique_ptr<juce::Label> feedforward_label;
    std::unique_ptr<juce::Label> delay_label;
    std::unique_ptr<juce::Slider> delay_wetSlider;
    std::unique_ptr<juce::Label> wetslider_label;
    std::unique_ptr<juce::ToggleButton> delay_onOffButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JoeProjectAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

