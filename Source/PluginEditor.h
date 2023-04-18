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
#include "HarmComponent.h"
#include "TapComponent.h"
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

    //mix controlls
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> gainSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> panSliderAttachment;

    //OSCs
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> depthSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> attackSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> decaySliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> sustainSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> sustainHeightSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> releaseSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> waveformSliderAttachment;

    //delay
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> delayWetnessSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::ButtonAttachment> delayOnOffButtonAttachment;

    //EQ
    std::unique_ptr <juce::AudioProcessorValueTreeState::ButtonAttachment> EQOnOffButtonAttachment;

    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> shelf1FreqSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> shelf1SSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> shelf1GainSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::ButtonAttachment> shelf1OnOffButtonAttachment;

    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> notch1FreqSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> notch1SSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> notch1GainSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::ButtonAttachment> notch1OnOffButtonAttachment;

    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> notch2FreqSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> notch2SSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> notch2GainSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::ButtonAttachment> notch2OnOffButtonAttachment;

    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> shelf2FreqSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> shelf2SSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::SliderAttachment> shelf2GainSliderAttachment;
    std::unique_ptr <juce::AudioProcessorValueTreeState::ButtonAttachment> shelf2OnOffButtonAttachment;

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
    std::unique_ptr<juce::GroupComponent> juce__groupComponent;
    std::unique_ptr<juce::GroupComponent> effects_group;
    std::unique_ptr<juce::GroupComponent> effects_group2;
    std::unique_ptr<juce::GroupComponent> master_group;
    std::unique_ptr<juce::Slider> m_depthSlider;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::Slider> m_gainSlider;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::Slider> m_panSlider;
    std::unique_ptr<juce::Label> Pan_label;
    std::unique_ptr<juce::Slider> m_attackSlider;
    std::unique_ptr<juce::Slider> m_decaySlider;
    std::unique_ptr<juce::Slider> m_sustainSlider;
    std::unique_ptr<juce::Slider> m_releaseSlider;
    std::unique_ptr<juce::Label> attack_label;
    std::unique_ptr<juce::Label> decay_label;
    std::unique_ptr<juce::Label> sustain_label;
    std::unique_ptr<juce::Label> release_label;
    std::unique_ptr<juce::Slider> m_sustainHeightSlider;
    std::unique_ptr<juce::Label> sustainHeight_label;
    std::unique_ptr<juce::Label> time_label;
    std::unique_ptr<juce::Slider> delay_wetSlider;
    std::unique_ptr<juce::Label> wetslider_label;
    std::unique_ptr<juce::ToggleButton> delay_onOffButton;
    std::unique_ptr<juce::TabbedComponent> harm_tabbedComponent;
    std::unique_ptr<juce::TabbedComponent> tap_tabbedComponent;
    std::unique_ptr<juce::Slider> m_waveformSlider;
    std::unique_ptr<juce::Slider> m_shelf1FreqSlider;
    std::unique_ptr<juce::Slider> m_shelf1SSlider;
    std::unique_ptr<juce::Slider> m_shelf1GainSlider;
    std::unique_ptr<juce::Slider> m_notch1FreqSlider;
    std::unique_ptr<juce::Slider> m_notch1QSlider;
    std::unique_ptr<juce::Slider> m_notch1GainSlider;
    std::unique_ptr<juce::Slider> m_notch2FreqSlider;
    std::unique_ptr<juce::Slider> m_notch2QSlider;
    std::unique_ptr<juce::Slider> m_notch2GainSlider;
    std::unique_ptr<juce::Slider> m_shelf2FreqSlider;
    std::unique_ptr<juce::Slider> m_shelf2SSlider;
    std::unique_ptr<juce::Slider> m_shelf2GainSlider;
    std::unique_ptr<juce::ToggleButton> m_shelf1OnOffButton;
    std::unique_ptr<juce::ToggleButton> m_notch1OnOffButton;
    std::unique_ptr<juce::ToggleButton> m_notch2OnOffButton;
    std::unique_ptr<juce::ToggleButton> m_shelf2OnOffButton;
    std::unique_ptr<juce::ToggleButton> m_EQOnOffButton;
    std::unique_ptr<juce::Label> label;
    std::unique_ptr<juce::Label> m_waveshapeLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JoeProjectAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

