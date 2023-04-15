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

#include "TapComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TapComponent::TapComponent (JoeProjectAudioProcessor &owner, int tap)
    : audioProcessor(owner)
{
    //[Constructor_pre] You can add your own custom stuff here..
    m_tapEnum = tap;
    //[/Constructor_pre]

    tap_feedbackSlider.reset (new juce::Slider ("feedback"));
    addAndMakeVisible (tap_feedbackSlider.get());
    tap_feedbackSlider->setRange (0, 1, 0);
    tap_feedbackSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    tap_feedbackSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    tap_feedbackSlider->addListener (this);

    tap_feedbackSlider->setBounds (8, 24, 56, 72);

    tap_feedforwardSlider.reset (new juce::Slider ("feedforward"));
    addAndMakeVisible (tap_feedforwardSlider.get());
    tap_feedforwardSlider->setRange (0, 1, 0);
    tap_feedforwardSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    tap_feedforwardSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    tap_feedforwardSlider->addListener (this);

    tap_feedforwardSlider->setBounds (64, 24, 56, 72);

    tap_delaySlider.reset (new juce::Slider ("delay time"));
    addAndMakeVisible (tap_delaySlider.get());
    tap_delaySlider->setRange (0, 2, 0);
    tap_delaySlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    tap_delaySlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    tap_delaySlider->addListener (this);

    tap_delaySlider->setBounds (120, 24, 56, 72);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("FB")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (16, 8, 31, 24);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("FF")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (72, 8, 31, 24);

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS("Time (S)")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (120, 8, 63, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    ///slider attachments
    feedbackSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, paramIDs[m_tapEnum][0], *tap_feedbackSlider);
    feedforwardSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, paramIDs[m_tapEnum][1], *tap_feedforwardSlider);
    delayTimeSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, paramIDs[m_tapEnum][2], *tap_delaySlider);

    //[/Constructor]
}

TapComponent::~TapComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..

    //destruct slider attachments!!!
    feedbackSliderAttachment = nullptr;
    feedforwardSliderAttachment = nullptr;
    delayTimeSliderAttachment = nullptr;

    //[/Destructor_pre]

    tap_feedbackSlider = nullptr;
    tap_feedforwardSlider = nullptr;
    tap_delaySlider = nullptr;
    juce__label = nullptr;
    juce__label2 = nullptr;
    juce__label3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TapComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff505050));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TapComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TapComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == tap_feedbackSlider.get())
    {
        //[UserSliderCode_tap_feedbackSlider] -- add your slider handling code here..
        audioProcessor.updateDelayParameters(m_tapEnum, kFeedback, tap_feedbackSlider->getValue());
        //[/UserSliderCode_tap_feedbackSlider]
    }
    else if (sliderThatWasMoved == tap_feedforwardSlider.get())
    {
        //[UserSliderCode_tap_feedforwardSlider] -- add your slider handling code here..
        audioProcessor.updateDelayParameters(m_tapEnum, kFeedforward, tap_feedforwardSlider->getValue());
        //[/UserSliderCode_tap_feedforwardSlider]
    }
    else if (sliderThatWasMoved == tap_delaySlider.get())
    {
        //[UserSliderCode_tap_delaySlider] -- add your slider handling code here..
        audioProcessor.updateDelayParameters(m_tapEnum, kDelayTime, tap_delaySlider->getValue());
        //[/UserSliderCode_tap_delaySlider]
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

<JUCER_COMPONENT documentType="Component" className="TapComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="JoeProjectAudioProcessor &amp;owner, int tap"
                 variableInitialisers="audioProcessor(owner)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ff505050"/>
  <SLIDER name="feedback" id="3ccaf222c1423a5f" memberName="tap_feedbackSlider"
          virtualName="" explicitFocusOrder="0" pos="8 24 56 72" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="feedforward" id="234c88f88b53e250" memberName="tap_feedforwardSlider"
          virtualName="" explicitFocusOrder="0" pos="64 24 56 72" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="delay time" id="bff6549dd2e3c7c2" memberName="tap_delaySlider"
          virtualName="" explicitFocusOrder="0" pos="120 24 56 72" min="0.0"
          max="2.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="a8da095189ecacad" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="16 8 31 24" edTextCol="ff000000"
         edBkgCol="0" labelText="FB" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="450858059ee30f39" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="72 8 31 24" edTextCol="ff000000"
         edBkgCol="0" labelText="FF" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="2aee48343f5b5992" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="120 8 63 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Time (S)" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

