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

#include "HarmComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
HarmComponent::HarmComponent (JoeProjectAudioProcessor &owner, int harm)
    : audioProcessor(owner)
{
    //[Constructor_pre] You can add your own custom stuff here..
    m_harmEnum = harm;
    //[/Constructor_pre]

    harm_depthSlider.reset (new juce::Slider ("depth"));
    addAndMakeVisible (harm_depthSlider.get());
    harm_depthSlider->setRange (0, 1, 0);
    harm_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_depthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_depthSlider->addListener (this);

    harm_depthSlider->setBounds (280, 96, 48, 48);

    harm_waveformSlider.reset (new juce::Slider ("waveform"));
    addAndMakeVisible (harm_waveformSlider.get());
    harm_waveformSlider->setRange (0, 3, 1);
    harm_waveformSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_waveformSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_waveformSlider->addListener (this);

    harm_waveformSlider->setBounds (8, 16, 48, 48);

    harm_attackSlider.reset (new juce::Slider ("attack"));
    addAndMakeVisible (harm_attackSlider.get());
    harm_attackSlider->setRange (0, 0.5, 0);
    harm_attackSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_attackSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_attackSlider->addListener (this);

    harm_attackSlider->setBounds (160, 16, 48, 48);

    harm_decaySlider.reset (new juce::Slider ("decay"));
    addAndMakeVisible (harm_decaySlider.get());
    harm_decaySlider->setRange (0, 0.5, 0);
    harm_decaySlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_decaySlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_decaySlider->addListener (this);

    harm_decaySlider->setBounds (192, 16, 48, 48);

    harm_sustainSlider.reset (new juce::Slider ("sustain"));
    addAndMakeVisible (harm_sustainSlider.get());
    harm_sustainSlider->setRange (0, 2, 0);
    harm_sustainSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_sustainSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_sustainSlider->addListener (this);

    harm_sustainSlider->setBounds (224, 16, 48, 48);

    harm_releaseSlider.reset (new juce::Slider ("release"));
    addAndMakeVisible (harm_releaseSlider.get());
    harm_releaseSlider->setRange (0, 0.5, 0);
    harm_releaseSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_releaseSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_releaseSlider->addListener (this);

    harm_releaseSlider->setBounds (256, 16, 48, 48);

    harm_susHeightSlider.reset (new juce::Slider ("sus height"));
    addAndMakeVisible (harm_susHeightSlider.get());
    harm_susHeightSlider->setRange (0, 1, 0);
    harm_susHeightSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_susHeightSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_susHeightSlider->addListener (this);

    harm_susHeightSlider->setBounds (224, 56, 48, 48);

    harm_offsetSlider.reset (new juce::Slider ("offset"));
    addAndMakeVisible (harm_offsetSlider.get());
    harm_offsetSlider->setRange (0, 12, 1);
    harm_offsetSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    harm_offsetSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    harm_offsetSlider->addListener (this);

    harm_offsetSlider->setBounds (8, 80, 152, 48);

    attack_label.reset (new juce::Label ("attack_label",
                                         TRANS("A")));
    addAndMakeVisible (attack_label.get());
    attack_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    attack_label->setJustificationType (juce::Justification::centredLeft);
    attack_label->setEditable (false, false, false);
    attack_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    attack_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    attack_label->setBounds (169, 3, 23, 24);

    decay_label.reset (new juce::Label ("deay_label",
                                        TRANS("D")));
    addAndMakeVisible (decay_label.get());
    decay_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    decay_label->setJustificationType (juce::Justification::centredLeft);
    decay_label->setEditable (false, false, false);
    decay_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    decay_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    decay_label->setBounds (200, 0, 23, 24);

    sustain_label.reset (new juce::Label ("sustain_label",
                                          TRANS("S")));
    addAndMakeVisible (sustain_label.get());
    sustain_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sustain_label->setJustificationType (juce::Justification::centredLeft);
    sustain_label->setEditable (false, false, false);
    sustain_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sustain_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    sustain_label->setBounds (232, 0, 23, 24);

    release_label.reset (new juce::Label ("release_label",
                                          TRANS("R")));
    addAndMakeVisible (release_label.get());
    release_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    release_label->setJustificationType (juce::Justification::centredLeft);
    release_label->setEditable (false, false, false);
    release_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    release_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    release_label->setBounds (264, 0, 23, 24);

    sustainHeight_label.reset (new juce::Label ("sustainHeight_label",
                                                TRANS("Sus level:")));
    addAndMakeVisible (sustainHeight_label.get());
    sustainHeight_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sustainHeight_label->setJustificationType (juce::Justification::centredLeft);
    sustainHeight_label->setEditable (false, false, false);
    sustainHeight_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sustainHeight_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    sustainHeight_label->setBounds (160, 72, 71, 24);

    time_label.reset (new juce::Label ("time",
                                       TRANS("Time S:")));
    addAndMakeVisible (time_label.get());
    time_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    time_label->setJustificationType (juce::Justification::centredLeft);
    time_label->setEditable (false, false, false);
    time_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    time_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    time_label->setBounds (112, 32, 55, 24);

    label.reset (new juce::Label ("label",
                                  TRANS("Waveshape")));
    addAndMakeVisible (label.get());
    label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (juce::Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label->setBounds (0, 8, 87, 16);

    harm_waveshapeLabel.reset (new juce::Label ("waveshape slider",
                                                TRANS("Sine")));
    addAndMakeVisible (harm_waveshapeLabel.get());
    harm_waveshapeLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    harm_waveshapeLabel->setJustificationType (juce::Justification::centredLeft);
    harm_waveshapeLabel->setEditable (false, false, false);
    harm_waveshapeLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    harm_waveshapeLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    harm_waveshapeLabel->setBounds (48, 40, 39, 16);

    offsetlabel.reset (new juce::Label ("offsetlabel",
                                        TRANS("Offset")));
    addAndMakeVisible (offsetlabel.get());
    offsetlabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    offsetlabel->setJustificationType (juce::Justification::centredLeft);
    offsetlabel->setEditable (false, false, false);
    offsetlabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    offsetlabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    offsetlabel->setBounds (0, 64, 47, 16);

    depth_slider.reset (new juce::Label ("depth sliider",
                                         TRANS("Depth")));
    addAndMakeVisible (depth_slider.get());
    depth_slider->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    depth_slider->setJustificationType (juce::Justification::centredLeft);
    depth_slider->setEditable (false, false, false);
    depth_slider->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    depth_slider->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    depth_slider->setBounds (240, 112, 47, 16);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    //slider attachments
    depthSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, harmParamIDs[m_harmEnum][kDepthID], *harm_depthSlider);
    waveformSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, harmParamIDs[m_harmEnum][kWaveformID], *harm_waveformSlider);
    offsetSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, harmParamIDs[m_harmEnum][kOffsetID], *harm_offsetSlider);
    attackSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, harmParamIDs[m_harmEnum][kAttackID], *harm_attackSlider);
    decaySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, harmParamIDs[m_harmEnum][kDecayID], *harm_decaySlider);
    sustainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, harmParamIDs[m_harmEnum][kSustainID], *harm_sustainSlider);
    sustainHeightSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, harmParamIDs[m_harmEnum][kSusHeightID], *harm_susHeightSlider);
    releaseSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, harmParamIDs[m_harmEnum][kReleaseID], *harm_releaseSlider);

    //[/Constructor]
}

HarmComponent::~HarmComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..

    //destruct attachments!!!
    depthSliderAttachment = nullptr;
    waveformSliderAttachment = nullptr;
    offsetSliderAttachment = nullptr;
    attackSliderAttachment = nullptr;
    decaySliderAttachment = nullptr;
    sustainSliderAttachment = nullptr;
    sustainHeightSliderAttachment = nullptr;
    releaseSliderAttachment = nullptr;

    //[/Destructor_pre]

    harm_depthSlider = nullptr;
    harm_waveformSlider = nullptr;
    harm_attackSlider = nullptr;
    harm_decaySlider = nullptr;
    harm_sustainSlider = nullptr;
    harm_releaseSlider = nullptr;
    harm_susHeightSlider = nullptr;
    harm_offsetSlider = nullptr;
    attack_label = nullptr;
    decay_label = nullptr;
    sustain_label = nullptr;
    release_label = nullptr;
    sustainHeight_label = nullptr;
    time_label = nullptr;
    label = nullptr;
    harm_waveshapeLabel = nullptr;
    offsetlabel = nullptr;
    depth_slider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void HarmComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff505050));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void HarmComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void HarmComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == harm_depthSlider.get())
    {
        //[UserSliderCode_harm_depthSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(m_harmEnum, kDepthCoef, harm_depthSlider->getValue());
        //[/UserSliderCode_harm_depthSlider]
    }
    else if (sliderThatWasMoved == harm_waveformSlider.get())
    {
        //[UserSliderCode_harm_waveformSlider] -- add your slider handling code here..
        int val = harm_waveformSlider->getValue();

        audioProcessor.updateHarmParameters(m_harmEnum, kWaveform, val);

        if(val == kSine){
            harm_waveshapeLabel->setText("Sine", juce::dontSendNotification);
        }

        if (val == kTriangle){
            harm_waveshapeLabel->setText("Triangle", juce::dontSendNotification);
        }

        if (val == kSaw){
            harm_waveshapeLabel->setText("Saw", juce::dontSendNotification);
        }

        if (val == kSquare){
            harm_waveshapeLabel->setText("Square", juce::dontSendNotification);
        }
        //[/UserSliderCode_harm_waveformSlider]
    }
    else if (sliderThatWasMoved == harm_attackSlider.get())
    {
        //[UserSliderCode_harm_attackSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(m_harmEnum, kAttack, harm_attackSlider->getValue());
        //[/UserSliderCode_harm_attackSlider]
    }
    else if (sliderThatWasMoved == harm_decaySlider.get())
    {
        //[UserSliderCode_harm_decaySlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(m_harmEnum, kDecay, harm_decaySlider->getValue());
        //[/UserSliderCode_harm_decaySlider]
    }
    else if (sliderThatWasMoved == harm_sustainSlider.get())
    {
        //[UserSliderCode_harm_sustainSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(m_harmEnum, kSustain, harm_sustainSlider->getValue());
        //[/UserSliderCode_harm_sustainSlider]
    }
    else if (sliderThatWasMoved == harm_releaseSlider.get())
    {
        //[UserSliderCode_harm_releaseSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(m_harmEnum, kRelease, harm_releaseSlider->getValue());
        //[/UserSliderCode_harm_releaseSlider]
    }
    else if (sliderThatWasMoved == harm_susHeightSlider.get())
    {
        //[UserSliderCode_harm_susHeightSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(m_harmEnum, kSustainHeight, harm_susHeightSlider->getValue());
        //[/UserSliderCode_harm_susHeightSlider]
    }
    else if (sliderThatWasMoved == harm_offsetSlider.get())
    {
        //[UserSliderCode_harm_offsetSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(m_harmEnum, kOffset, harm_offsetSlider->getValue());
        //[/UserSliderCode_harm_offsetSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="HarmComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="JoeProjectAudioProcessor &amp;owner, int harm"
                 variableInitialisers="audioProcessor(owner)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff505050"/>
  <SLIDER name="depth" id="79a572d2b8ea4f70" memberName="harm_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="280 96 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="waveform" id="773fad68130a2211" memberName="harm_waveformSlider"
          virtualName="" explicitFocusOrder="0" pos="8 16 48 48" min="0.0"
          max="3.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="attack" id="ae0af547dee372fd" memberName="harm_attackSlider"
          virtualName="" explicitFocusOrder="0" pos="160 16 48 48" min="0.0"
          max="0.5" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="decay" id="a40f7cb0e450634f" memberName="harm_decaySlider"
          virtualName="" explicitFocusOrder="0" pos="192 16 48 48" min="0.0"
          max="0.5" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="sustain" id="6f5acfdc15e6e413" memberName="harm_sustainSlider"
          virtualName="" explicitFocusOrder="0" pos="224 16 48 48" min="0.0"
          max="2.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="release" id="3b23cfc4a3b5b5b1" memberName="harm_releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="256 16 48 48" min="0.0"
          max="0.5" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="sus height" id="9f9e55e476333a62" memberName="harm_susHeightSlider"
          virtualName="" explicitFocusOrder="0" pos="224 56 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="offset" id="161f7d9ee7c2499f" memberName="harm_offsetSlider"
          virtualName="" explicitFocusOrder="0" pos="8 80 152 48" min="0.0"
          max="12.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="attack_label" id="51e208b97073091" memberName="attack_label"
         virtualName="" explicitFocusOrder="0" pos="169 3 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="deay_label" id="a6950e3df5194f1b" memberName="decay_label"
         virtualName="" explicitFocusOrder="0" pos="200 0 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="D" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="sustain_label" id="61b814e3481fa9ac" memberName="sustain_label"
         virtualName="" explicitFocusOrder="0" pos="232 0 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="S" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="release_label" id="41d157e8c885bc0a" memberName="release_label"
         virtualName="" explicitFocusOrder="0" pos="264 0 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="sustainHeight_label" id="840fedbf8a4a25c2" memberName="sustainHeight_label"
         virtualName="" explicitFocusOrder="0" pos="160 72 71 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sus level:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="time" id="c54a23993d1f7f34" memberName="time_label" virtualName=""
         explicitFocusOrder="0" pos="112 32 55 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Time S:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="label" id="ccc5a278409ff4f3" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 8 87 16" edTextCol="ff000000" edBkgCol="0"
         labelText="Waveshape" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="waveshape slider" id="d661c911d9f53e76" memberName="harm_waveshapeLabel"
         virtualName="" explicitFocusOrder="0" pos="48 40 39 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Sine" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="offsetlabel" id="61c0c4c747c0128d" memberName="offsetlabel"
         virtualName="" explicitFocusOrder="0" pos="0 64 47 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Offset" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="depth sliider" id="799e645c3dc8b306" memberName="depth_slider"
         virtualName="" explicitFocusOrder="0" pos="240 112 47 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

