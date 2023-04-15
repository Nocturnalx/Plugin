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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

//[/MiscUserDefs]

//==============================================================================
JoeProjectAudioProcessorEditor::JoeProjectAudioProcessorEditor (JoeProjectAudioProcessor& owner)
    : AudioProcessorEditor(owner), audioProcessor(owner)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    effects_group.reset (new juce::GroupComponent ("effects group",
                                                   TRANS("Delay")));
    addAndMakeVisible (effects_group.get());

    effects_group->setBounds (0, 192, 304, 192);

    effects_group2.reset (new juce::GroupComponent ("effects group",
                                                    TRANS("Mix")));
    addAndMakeVisible (effects_group2.get());

    effects_group2->setBounds (544, 72, 144, 120);

    master_group.reset (new juce::GroupComponent ("master group",
                                                  TRANS("Master Oscillator")));
    addAndMakeVisible (master_group.get());

    master_group->setBounds (0, 0, 200, 192);

    m_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (m_depthSlider.get());
    m_depthSlider->setRange (0, 1, 0);
    m_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_depthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    m_depthSlider->addListener (this);

    m_depthSlider->setBounds (24, 32, 48, 48);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Output Gain")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (552, 136, 88, 24);

    m_gainSlider.reset (new juce::Slider ("gain"));
    addAndMakeVisible (m_gainSlider.get());
    m_gainSlider->setRange (0, 1, 0);
    m_gainSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_gainSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_gainSlider->addListener (this);

    m_gainSlider->setBounds (552, 144, 128, 48);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("Depth")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (24, 24, 51, 15);

    m_panSlider.reset (new juce::Slider ("pan"));
    addAndMakeVisible (m_panSlider.get());
    m_panSlider->setRange (-1, 1, 0);
    m_panSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_panSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_panSlider->addListener (this);

    m_panSlider->setBounds (552, 96, 128, 48);

    Pan_label.reset (new juce::Label ("pan",
                                      TRANS("Pan")));
    addAndMakeVisible (Pan_label.get());
    Pan_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    Pan_label->setJustificationType (juce::Justification::centredLeft);
    Pan_label->setEditable (false, false, false);
    Pan_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    Pan_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    Pan_label->setBounds (552, 88, 80, 24);

    m_attackSlider.reset (new juce::Slider ("attack"));
    addAndMakeVisible (m_attackSlider.get());
    m_attackSlider->setRange (0, 0.5, 0);
    m_attackSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_attackSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    m_attackSlider->addListener (this);

    m_attackSlider->setBounds (56, 112, 47, 48);

    m_decaySlider.reset (new juce::Slider ("delay"));
    addAndMakeVisible (m_decaySlider.get());
    m_decaySlider->setRange (0, 0.5, 0);
    m_decaySlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_decaySlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    m_decaySlider->addListener (this);

    m_decaySlider->setBounds (88, 112, 47, 48);

    m_sustainSlider.reset (new juce::Slider ("sustain"));
    addAndMakeVisible (m_sustainSlider.get());
    m_sustainSlider->setRange (0, 2, 0.01);
    m_sustainSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_sustainSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    m_sustainSlider->addListener (this);

    m_sustainSlider->setBounds (120, 112, 47, 48);

    m_releaseSlider.reset (new juce::Slider ("release"));
    addAndMakeVisible (m_releaseSlider.get());
    m_releaseSlider->setRange (0, 0.5, 0);
    m_releaseSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_releaseSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    m_releaseSlider->addListener (this);

    m_releaseSlider->setBounds (152, 112, 47, 48);

    attack_label.reset (new juce::Label ("attack_label",
                                         TRANS("A")));
    addAndMakeVisible (attack_label.get());
    attack_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    attack_label->setJustificationType (juce::Justification::centredLeft);
    attack_label->setEditable (false, false, false);
    attack_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    attack_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    attack_label->setBounds (65, 96, 23, 24);

    decay_label.reset (new juce::Label ("deay_label",
                                        TRANS("D")));
    addAndMakeVisible (decay_label.get());
    decay_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    decay_label->setJustificationType (juce::Justification::centredLeft);
    decay_label->setEditable (false, false, false);
    decay_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    decay_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    decay_label->setBounds (96, 96, 23, 24);

    sustain_label.reset (new juce::Label ("sustain_label",
                                          TRANS("S")));
    addAndMakeVisible (sustain_label.get());
    sustain_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sustain_label->setJustificationType (juce::Justification::centredLeft);
    sustain_label->setEditable (false, false, false);
    sustain_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sustain_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    sustain_label->setBounds (128, 96, 23, 24);

    release_label.reset (new juce::Label ("release_label",
                                          TRANS("R")));
    addAndMakeVisible (release_label.get());
    release_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    release_label->setJustificationType (juce::Justification::centredLeft);
    release_label->setEditable (false, false, false);
    release_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    release_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    release_label->setBounds (160, 96, 23, 24);

    m_sustainHeightSlider.reset (new juce::Slider ("sustain height"));
    addAndMakeVisible (m_sustainHeightSlider.get());
    m_sustainHeightSlider->setRange (0, 1, 0);
    m_sustainHeightSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_sustainHeightSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    m_sustainHeightSlider->addListener (this);

    m_sustainHeightSlider->setBounds (120, 144, 47, 48);

    sustainHeight_label.reset (new juce::Label ("sustainHeight_label",
                                                TRANS("Sus level:")));
    addAndMakeVisible (sustainHeight_label.get());
    sustainHeight_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sustainHeight_label->setJustificationType (juce::Justification::centredLeft);
    sustainHeight_label->setEditable (false, false, false);
    sustainHeight_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sustainHeight_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    sustainHeight_label->setBounds (8, 160, 71, 24);

    time_label.reset (new juce::Label ("time",
                                       TRANS("Time S:")));
    addAndMakeVisible (time_label.get());
    time_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    time_label->setJustificationType (juce::Justification::centredLeft);
    time_label->setEditable (false, false, false);
    time_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    time_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    time_label->setBounds (8, 128, 55, 24);

    delay_wetSlider.reset (new juce::Slider ("wet slider"));
    addAndMakeVisible (delay_wetSlider.get());
    delay_wetSlider->setRange (0, 1, 0);
    delay_wetSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    delay_wetSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    delay_wetSlider->addListener (this);

    delay_wetSlider->setBounds (256, 320, 48, 48);

    wetslider_label.reset (new juce::Label ("label",
                                            TRANS("Wet")));
    addAndMakeVisible (wetslider_label.get());
    wetslider_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    wetslider_label->setJustificationType (juce::Justification::centredLeft);
    wetslider_label->setEditable (false, false, false);
    wetslider_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    wetslider_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    wetslider_label->setBounds (232, 336, 32, 24);

    delay_onOffButton.reset (new juce::ToggleButton ("on off button"));
    addAndMakeVisible (delay_onOffButton.get());
    delay_onOffButton->setButtonText (TRANS("On/Off"));
    delay_onOffButton->addListener (this);
    delay_onOffButton->setToggleState (true, juce::dontSendNotification);

    delay_onOffButton->setBounds (224, 208, 72, 24);

    m_presetBox.reset (new juce::ComboBox ("presets"));
    addAndMakeVisible (m_presetBox.get());
    m_presetBox->setEditableText (false);
    m_presetBox->setJustificationType (juce::Justification::centredLeft);
    m_presetBox->setTextWhenNothingSelected (juce::String());
    m_presetBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    m_presetBox->addItem (TRANS("preset 1"), 1);
    m_presetBox->addItem (TRANS("preset 2"), 2);
    m_presetBox->addListener (this);

    m_presetBox->setBounds (544, 8, 128, 24);

    harm_tabbedComponent.reset (new juce::TabbedComponent (juce::TabbedButtonBar::TabsAtTop));
    addAndMakeVisible (harm_tabbedComponent.get());
    harm_tabbedComponent->setTabBarDepth (30);
    harm_tabbedComponent->addTab (TRANS("harm 1"), juce::Colours::lightgrey, new HarmComponent (audioProcessor, harm1), true);
    harm_tabbedComponent->addTab (TRANS("harm 2"), juce::Colours::lightgrey, new HarmComponent (audioProcessor, harm2), true);
    harm_tabbedComponent->addTab (TRANS("harm 3"), juce::Colours::lightgrey, new HarmComponent (audioProcessor, harm3), true);
    harm_tabbedComponent->addTab (TRANS("harm 4"), juce::Colours::lightgrey, new HarmComponent (audioProcessor, harm4), true);
    harm_tabbedComponent->setCurrentTabIndex (0);

    harm_tabbedComponent->setBounds (200, 8, 336, 176);

    tap_tabbedComponent.reset (new juce::TabbedComponent (juce::TabbedButtonBar::TabsAtTop));
    addAndMakeVisible (tap_tabbedComponent.get());
    tap_tabbedComponent->setTabBarDepth (30);
    tap_tabbedComponent->addTab (TRANS("Tap 1"), juce::Colours::lightgrey, new TapComponent (audioProcessor, tap1), true);
    tap_tabbedComponent->addTab (TRANS("Tap 2"), juce::Colours::lightgrey, new TapComponent (audioProcessor, tap2), true);
    tap_tabbedComponent->addTab (TRANS("Tap 3"), juce::Colours::lightgrey, new TapComponent (audioProcessor, tap3), true);
    tap_tabbedComponent->setCurrentTabIndex (0);

    tap_tabbedComponent->setBounds (16, 216, 200, 150);

    m_waveformSlider.reset (new juce::Slider ("waveform slider"));
    addAndMakeVisible (m_waveformSlider.get());
    m_waveformSlider->setRange (0, 3, 1);
    m_waveformSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_waveformSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    m_waveformSlider->addListener (this);

    m_waveformSlider->setBounds (112, 32, 55, 48);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (700, 385);


    //[Constructor] You can add your own custom stuff here..
    gainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, "gain", *m_gainSlider);
    panSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, "pan", *m_panSlider);

    depthSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, "master_depth_coef", *m_depthSlider);
    attackSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, "master_attack", *m_attackSlider);
    decaySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, "master_decay", *m_decaySlider);
    sustainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, "master_sustain", *m_sustainSlider);
    sustainHeightSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, "master_sus_height", *m_sustainHeightSlider);
    releaseSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, "master_release", *m_releaseSlider);
    waveformSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, "master_waveform", *m_waveformSlider);

    delayWetnessSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, "delay_wetness", *delay_wetSlider);
    delayOnOffButtonAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, "delay_toggle", *delay_onOffButton);

    //[/Constructor]
}

JoeProjectAudioProcessorEditor::~JoeProjectAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //delete attachments before to prevent free on empty component pointers
    gainSliderAttachment = nullptr;
    panSliderAttachment = nullptr;

    depthSliderAttachment = nullptr;
    attackSliderAttachment = nullptr;
    decaySliderAttachment = nullptr;
    sustainSliderAttachment = nullptr;
    sustainHeightSliderAttachment = nullptr;
    releaseSliderAttachment = nullptr;
    waveformSliderAttachment = nullptr;

    delayWetnessSliderAttachment = nullptr;
    delayOnOffButtonAttachment = nullptr;

    //[/Destructor_pre]

    effects_group = nullptr;
    effects_group2 = nullptr;
    master_group = nullptr;
    m_depthSlider = nullptr;
    juce__label = nullptr;
    m_gainSlider = nullptr;
    juce__label2 = nullptr;
    m_panSlider = nullptr;
    Pan_label = nullptr;
    m_attackSlider = nullptr;
    m_decaySlider = nullptr;
    m_sustainSlider = nullptr;
    m_releaseSlider = nullptr;
    attack_label = nullptr;
    decay_label = nullptr;
    sustain_label = nullptr;
    release_label = nullptr;
    m_sustainHeightSlider = nullptr;
    sustainHeight_label = nullptr;
    time_label = nullptr;
    delay_wetSlider = nullptr;
    wetslider_label = nullptr;
    delay_onOffButton = nullptr;
    m_presetBox = nullptr;
    harm_tabbedComponent = nullptr;
    tap_tabbedComponent = nullptr;
    m_waveformSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void JoeProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void JoeProjectAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void JoeProjectAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_depthSlider.get())
    {
        //[UserSliderCode_m_depthSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kDepthCoef, m_depthSlider->getValue());
        //[/UserSliderCode_m_depthSlider]
    }
    else if (sliderThatWasMoved == m_gainSlider.get())
    {
        //[UserSliderCode_m_gainSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kGain, m_gainSlider->getValue());
        //[/UserSliderCode_m_gainSlider]
    }
    else if (sliderThatWasMoved == m_panSlider.get())
    {
        //[UserSliderCode_m_panSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kPan, m_panSlider->getValue());
        //[/UserSliderCode_m_panSlider]
    }
    else if (sliderThatWasMoved == m_attackSlider.get())
    {
        //[UserSliderCode_m_attackSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kAttack, m_attackSlider->getValue());

        //[/UserSliderCode_m_attackSlider]
    }
    else if (sliderThatWasMoved == m_decaySlider.get())
    {
        //[UserSliderCode_m_decaySlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kDecay, m_decaySlider->getValue());
        //[/UserSliderCode_m_decaySlider]
    }
    else if (sliderThatWasMoved == m_sustainSlider.get())
    {
        //[UserSliderCode_m_sustainSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kSustain, m_sustainSlider->getValue());
        //[/UserSliderCode_m_sustainSlider]
    }
    else if (sliderThatWasMoved == m_releaseSlider.get())
    {
        //[UserSliderCode_m_releaseSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kRelease, m_releaseSlider->getValue());
        //[/UserSliderCode_m_releaseSlider]
    }
    else if (sliderThatWasMoved == m_sustainHeightSlider.get())
    {
        //[UserSliderCode_m_sustainHeightSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kSustainHeight, m_sustainHeightSlider->getValue());
        //[/UserSliderCode_m_sustainHeightSlider]
    }
    else if (sliderThatWasMoved == delay_wetSlider.get())
    {
        //[UserSliderCode_delay_wetSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kWetness, delay_wetSlider->getValue());
        //[/UserSliderCode_delay_wetSlider]
    }
    else if (sliderThatWasMoved == m_waveformSlider.get())
    {
        //[UserSliderCode_m_waveformSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kWaveform, m_waveformSlider->getValue());
        //[/UserSliderCode_m_waveformSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void JoeProjectAudioProcessorEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == delay_onOffButton.get())
    {
        //[UserButtonCode_delay_onOffButton] -- add your button handler code here..
        audioProcessor.toggleOnOff(kDelayOnOff);
        //[/UserButtonCode_delay_onOffButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void JoeProjectAudioProcessorEditor::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == m_presetBox.get())
    {
        //[UserComboBoxCode_m_presetBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_m_presetBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="JoeProjectAudioProcessorEditor"
                 componentName="" parentClasses="public juce::AudioProcessorEditor"
                 constructorParams="JoeProjectAudioProcessor&amp; owner" variableInitialisers="AudioProcessorEditor(owner), audioProcessor(owner)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="700" initialHeight="385">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GROUPCOMPONENT name="effects group" id="a1843f4e14437c21" memberName="effects_group"
                  virtualName="" explicitFocusOrder="0" pos="0 192 304 192" title="Delay"/>
  <GROUPCOMPONENT name="effects group" id="a352b916ecb48379" memberName="effects_group2"
                  virtualName="" explicitFocusOrder="0" pos="544 72 144 120" title="Mix"/>
  <GROUPCOMPONENT name="master group" id="25f270b0cd5b75bf" memberName="master_group"
                  virtualName="" explicitFocusOrder="0" pos="0 0 200 192" title="Master Oscillator"/>
  <SLIDER name="Gain" id="42f75b1dba908f01" memberName="m_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="24 32 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="a07cd26b6f2d246c" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="552 136 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="gain" id="ef8ea6ef3e44ff24" memberName="m_gainSlider" virtualName=""
          explicitFocusOrder="0" pos="552 144 128 48" min="0.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="264bb30d81321ded" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="24 24 51 15" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="pan" id="a46ddc996119acdc" memberName="m_panSlider" virtualName=""
          explicitFocusOrder="0" pos="552 96 128 48" min="-1.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="pan" id="786869f480bd2bcf" memberName="Pan_label" virtualName=""
         explicitFocusOrder="0" pos="552 88 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="attack" id="c2cdc4abc5fd9865" memberName="m_attackSlider"
          virtualName="" explicitFocusOrder="0" pos="56 112 47 48" min="0.0"
          max="0.5" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="delay" id="cbc3d26f721ebcf4" memberName="m_decaySlider"
          virtualName="" explicitFocusOrder="0" pos="88 112 47 48" min="0.0"
          max="0.5" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="sustain" id="2d9c5ae950931483" memberName="m_sustainSlider"
          virtualName="" explicitFocusOrder="0" pos="120 112 47 48" min="0.0"
          max="2.0" int="0.01" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="release" id="5bdd2a75e2658f7b" memberName="m_releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="152 112 47 48" min="0.0"
          max="0.5" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="attack_label" id="51e208b97073091" memberName="attack_label"
         virtualName="" explicitFocusOrder="0" pos="65 96 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="deay_label" id="a6950e3df5194f1b" memberName="decay_label"
         virtualName="" explicitFocusOrder="0" pos="96 96 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="D" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="sustain_label" id="61b814e3481fa9ac" memberName="sustain_label"
         virtualName="" explicitFocusOrder="0" pos="128 96 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="S" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="release_label" id="41d157e8c885bc0a" memberName="release_label"
         virtualName="" explicitFocusOrder="0" pos="160 96 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="sustain height" id="1692b5e13f5f0d0" memberName="m_sustainHeightSlider"
          virtualName="" explicitFocusOrder="0" pos="120 144 47 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="sustainHeight_label" id="840fedbf8a4a25c2" memberName="sustainHeight_label"
         virtualName="" explicitFocusOrder="0" pos="8 160 71 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sus level:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="time" id="c54a23993d1f7f34" memberName="time_label" virtualName=""
         explicitFocusOrder="0" pos="8 128 55 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Time S:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="wet slider" id="b349d9cbd1e8ca97" memberName="delay_wetSlider"
          virtualName="" explicitFocusOrder="0" pos="256 320 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="label" id="d0e04177f0d6ec03" memberName="wetslider_label"
         virtualName="" explicitFocusOrder="0" pos="232 336 32 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Wet" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="on off button" id="4969d8c8f9de487d" memberName="delay_onOffButton"
                virtualName="" explicitFocusOrder="0" pos="224 208 72 24" buttonText="On/Off"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="1"/>
  <COMBOBOX name="presets" id="fd0a8d20684eac8b" memberName="m_presetBox"
            virtualName="" explicitFocusOrder="0" pos="544 8 128 24" editable="0"
            layout="33" items="preset 1&#10;preset 2" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <TABBEDCOMPONENT name="harm tabs" id="b904e83a971cf3dd" memberName="harm_tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="200 8 336 176" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="harm 1" colour="ffd3d3d3" useJucerComp="0" contentClassName="HarmComponent"
         constructorParams="audioProcessor, harm1" jucerComponentFile=""/>
    <TAB name="harm 2" colour="ffd3d3d3" useJucerComp="0" contentClassName="HarmComponent"
         constructorParams="audioProcessor, harm2" jucerComponentFile=""/>
    <TAB name="harm 3" colour="ffd3d3d3" useJucerComp="0" contentClassName="HarmComponent"
         constructorParams="audioProcessor, harm3" jucerComponentFile=""/>
    <TAB name="harm 4" colour="ffd3d3d3" useJucerComp="0" contentClassName="HarmComponent"
         constructorParams="audioProcessor, harm4" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <TABBEDCOMPONENT name="tap tabs" id="9f1b906844882e15" memberName="tap_tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="16 216 200 150" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="Tap 1" colour="ffd3d3d3" useJucerComp="0" contentClassName="TapComponent"
         constructorParams="audioProcessor, tap1" jucerComponentFile=""/>
    <TAB name="Tap 2" colour="ffd3d3d3" useJucerComp="0" contentClassName="TapComponent"
         constructorParams="audioProcessor, tap2" jucerComponentFile=""/>
    <TAB name="Tap 3" colour="ffd3d3d3" useJucerComp="0" contentClassName="TapComponent"
         constructorParams="audioProcessor, tap3" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <SLIDER name="waveform slider" id="cbd7d154315fd17f" memberName="m_waveformSlider"
          virtualName="" explicitFocusOrder="0" pos="112 32 55 48" min="0.0"
          max="3.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

