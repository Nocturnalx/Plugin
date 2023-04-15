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

    harm_depthSlider->setBounds (248, 88, 48, 48);

    harm_waveformSlider.reset (new juce::Slider ("waveform"));
    addAndMakeVisible (harm_waveformSlider.get());
    harm_waveformSlider->setRange (0, 3, 1);
    harm_waveformSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_waveformSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    harm_waveformSlider->addListener (this);

    harm_waveformSlider->setBounds (24, 16, 56, 72);

    harm_attackSlider.reset (new juce::Slider ("attack"));
    addAndMakeVisible (harm_attackSlider.get());
    harm_attackSlider->setRange (0, 0.5, 0);
    harm_attackSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_attackSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_attackSlider->addListener (this);

    harm_attackSlider->setBounds (112, 16, 48, 48);

    harm_decaySlider.reset (new juce::Slider ("decay"));
    addAndMakeVisible (harm_decaySlider.get());
    harm_decaySlider->setRange (0, 0.5, 0);
    harm_decaySlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_decaySlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_decaySlider->addListener (this);

    harm_decaySlider->setBounds (152, 16, 48, 48);

    harm_sustainSlider.reset (new juce::Slider ("sustain"));
    addAndMakeVisible (harm_sustainSlider.get());
    harm_sustainSlider->setRange (0, 2, 0);
    harm_sustainSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_sustainSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_sustainSlider->addListener (this);

    harm_sustainSlider->setBounds (192, 16, 48, 48);

    harm_releaseSlider.reset (new juce::Slider ("release"));
    addAndMakeVisible (harm_releaseSlider.get());
    harm_releaseSlider->setRange (0, 0.5, 0);
    harm_releaseSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_releaseSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_releaseSlider->addListener (this);

    harm_releaseSlider->setBounds (232, 16, 48, 48);

    harm_susHeightSlider.reset (new juce::Slider ("sus height"));
    addAndMakeVisible (harm_susHeightSlider.get());
    harm_susHeightSlider->setRange (0, 1, 0);
    harm_susHeightSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_susHeightSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_susHeightSlider->addListener (this);

    harm_susHeightSlider->setBounds (192, 56, 48, 48);

    harm_offsetSlider.reset (new juce::Slider ("offset"));
    addAndMakeVisible (harm_offsetSlider.get());
    harm_offsetSlider->setRange (0, 12, 1);
    harm_offsetSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    harm_offsetSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    harm_offsetSlider->addListener (this);

    harm_offsetSlider->setBounds (16, 88, 150, 56);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    //slider attachments
    depthSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, paramIDs[m_harmEnum][0], *harm_depthSlider);
    waveformSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, paramIDs[m_harmEnum][1], *harm_waveformSlider);
    offsetSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, paramIDs[m_harmEnum][2], *harm_offsetSlider);
    attackSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, paramIDs[m_harmEnum][3], *harm_attackSlider);
    decaySliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, paramIDs[m_harmEnum][4], *harm_decaySlider);
    sustainSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, paramIDs[m_harmEnum][5], *harm_sustainSlider);
    sustainHeightSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, paramIDs[m_harmEnum][6], *harm_susHeightSlider);
    releaseSliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, paramIDs[m_harmEnum][7], *harm_releaseSlider);

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
        audioProcessor.updateHarmParameters(m_harmEnum, kWaveform, harm_waveformSlider->getValue());
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
          virtualName="" explicitFocusOrder="0" pos="248 88 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="waveform" id="773fad68130a2211" memberName="harm_waveformSlider"
          virtualName="" explicitFocusOrder="0" pos="24 16 56 72" min="0.0"
          max="3.0" int="1.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="attack" id="ae0af547dee372fd" memberName="harm_attackSlider"
          virtualName="" explicitFocusOrder="0" pos="112 16 48 48" min="0.0"
          max="0.5" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="decay" id="a40f7cb0e450634f" memberName="harm_decaySlider"
          virtualName="" explicitFocusOrder="0" pos="152 16 48 48" min="0.0"
          max="0.5" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="sustain" id="6f5acfdc15e6e413" memberName="harm_sustainSlider"
          virtualName="" explicitFocusOrder="0" pos="192 16 48 48" min="0.0"
          max="2.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="release" id="3b23cfc4a3b5b5b1" memberName="harm_releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="232 16 48 48" min="0.0"
          max="0.5" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="sus height" id="9f9e55e476333a62" memberName="harm_susHeightSlider"
          virtualName="" explicitFocusOrder="0" pos="192 56 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="offset" id="161f7d9ee7c2499f" memberName="harm_offsetSlider"
          virtualName="" explicitFocusOrder="0" pos="16 88 150 56" min="0.0"
          max="12.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

