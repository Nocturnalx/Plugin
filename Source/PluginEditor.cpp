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

    m_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (m_depthSlider.get());
    m_depthSlider->setRange (-1, 1, 0);
    m_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_depthSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_depthSlider->addListener (this);

    m_depthSlider->setBounds (24, 96, 128, 48);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Output Gain")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (160, 160, 88, 24);

    m_gainSlider.reset (new juce::Slider ("gain"));
    addAndMakeVisible (m_gainSlider.get());
    m_gainSlider->setRange (0, 1, 0);
    m_gainSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_gainSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_gainSlider->addListener (this);

    m_gainSlider->setBounds (160, 168, 128, 48);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("Depth")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (24, 88, 51, 15);

    m_sineButton.reset (new juce::TextButton ("sine"));
    addAndMakeVisible (m_sineButton.get());
    m_sineButton->setButtonText (TRANS("Sine"));
    m_sineButton->addListener (this);

    m_sineButton->setBounds (168, 88, 40, 24);

    m_triangleButton.reset (new juce::TextButton ("triangle"));
    addAndMakeVisible (m_triangleButton.get());
    m_triangleButton->setButtonText (TRANS("Tri"));
    m_triangleButton->addListener (this);

    m_triangleButton->setBounds (216, 88, 40, 24);

    m_sawButton.reset (new juce::TextButton ("saw"));
    addAndMakeVisible (m_sawButton.get());
    m_sawButton->setButtonText (TRANS("Saw"));
    m_sawButton->addListener (this);

    m_sawButton->setBounds (168, 120, 40, 24);

    m_squareButton.reset (new juce::TextButton ("square"));
    addAndMakeVisible (m_squareButton.get());
    m_squareButton->setButtonText (TRANS("squ"));
    m_squareButton->addListener (this);

    m_squareButton->setBounds (216, 120, 40, 24);

    m_panSlider.reset (new juce::Slider ("pan"));
    addAndMakeVisible (m_panSlider.get());
    m_panSlider->setRange (-1, 1, 0);
    m_panSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_panSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_panSlider->addListener (this);

    m_panSlider->setBounds (24, 168, 128, 48);

    Pan_label.reset (new juce::Label ("pan",
                                      TRANS("Pan")));
    addAndMakeVisible (Pan_label.get());
    Pan_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    Pan_label->setJustificationType (juce::Justification::centredLeft);
    Pan_label->setEditable (false, false, false);
    Pan_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    Pan_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    Pan_label->setBounds (24, 160, 40, 24);

    harm1_sineButton.reset (new juce::TextButton ("sine"));
    addAndMakeVisible (harm1_sineButton.get());
    harm1_sineButton->setButtonText (TRANS("Sine"));
    harm1_sineButton->addListener (this);

    harm1_sineButton->setBounds (440, 22, 40, 24);

    harm1_triangleButton.reset (new juce::TextButton ("triangle"));
    addAndMakeVisible (harm1_triangleButton.get());
    harm1_triangleButton->setButtonText (TRANS("Tri"));
    harm1_triangleButton->addListener (this);

    harm1_triangleButton->setBounds (488, 22, 40, 24);

    harm1_sawButton.reset (new juce::TextButton ("saw"));
    addAndMakeVisible (harm1_sawButton.get());
    harm1_sawButton->setButtonText (TRANS("Saw"));
    harm1_sawButton->addListener (this);

    harm1_sawButton->setBounds (440, 54, 40, 24);

    harm1_squareButton.reset (new juce::TextButton ("square"));
    addAndMakeVisible (harm1_squareButton.get());
    harm1_squareButton->setButtonText (TRANS("squ"));
    harm1_squareButton->addListener (this);

    harm1_squareButton->setBounds (488, 54, 40, 24);

    harm1_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm1_depthSlider.get());
    harm1_depthSlider->setRange (-1, 1, 0);
    harm1_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm1_depthSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    harm1_depthSlider->addListener (this);

    harm1_depthSlider->setBounds (304, 24, 136, 48);

    harm1_offsetSlider.reset (new juce::Slider ("offset"));
    addAndMakeVisible (harm1_offsetSlider.get());
    harm1_offsetSlider->setRange (0, 12, 1);
    harm1_offsetSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    harm1_offsetSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    harm1_offsetSlider->addListener (this);

    harm1_offsetSlider->setBounds (544, 32, 150, 40);

    harm2_sineButton.reset (new juce::TextButton ("sine"));
    addAndMakeVisible (harm2_sineButton.get());
    harm2_sineButton->setButtonText (TRANS("Sine"));
    harm2_sineButton->addListener (this);

    harm2_sineButton->setBounds (442, 91, 40, 24);

    harm2_triangleButton.reset (new juce::TextButton ("triangle"));
    addAndMakeVisible (harm2_triangleButton.get());
    harm2_triangleButton->setButtonText (TRANS("Tri"));
    harm2_triangleButton->addListener (this);

    harm2_triangleButton->setBounds (490, 91, 40, 24);

    harm2_sawButton.reset (new juce::TextButton ("saw"));
    addAndMakeVisible (harm2_sawButton.get());
    harm2_sawButton->setButtonText (TRANS("Saw"));
    harm2_sawButton->addListener (this);

    harm2_sawButton->setBounds (442, 123, 40, 24);

    harm2_squareButton.reset (new juce::TextButton ("square"));
    addAndMakeVisible (harm2_squareButton.get());
    harm2_squareButton->setButtonText (TRANS("squ"));
    harm2_squareButton->addListener (this);

    harm2_squareButton->setBounds (490, 123, 40, 24);

    harm2_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm2_depthSlider.get());
    harm2_depthSlider->setRange (-1, 1, 0);
    harm2_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm2_depthSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    harm2_depthSlider->addListener (this);

    harm2_depthSlider->setBounds (306, 93, 136, 48);

    harm2_offsetSlider.reset (new juce::Slider ("offset"));
    addAndMakeVisible (harm2_offsetSlider.get());
    harm2_offsetSlider->setRange (0, 12, 1);
    harm2_offsetSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    harm2_offsetSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    harm2_offsetSlider->addListener (this);

    harm2_offsetSlider->setBounds (544, 104, 150, 40);

    harm3_sineButton.reset (new juce::TextButton ("sine"));
    addAndMakeVisible (harm3_sineButton.get());
    harm3_sineButton->setButtonText (TRANS("Sine"));
    harm3_sineButton->addListener (this);

    harm3_sineButton->setBounds (443, 159, 40, 24);

    harm3_triangleButton.reset (new juce::TextButton ("triangle"));
    addAndMakeVisible (harm3_triangleButton.get());
    harm3_triangleButton->setButtonText (TRANS("Tri"));
    harm3_triangleButton->addListener (this);

    harm3_triangleButton->setBounds (491, 159, 40, 24);

    harm3_sawButton.reset (new juce::TextButton ("saw"));
    addAndMakeVisible (harm3_sawButton.get());
    harm3_sawButton->setButtonText (TRANS("Saw"));
    harm3_sawButton->addListener (this);

    harm3_sawButton->setBounds (443, 191, 40, 24);

    harm3_squareButton.reset (new juce::TextButton ("square"));
    addAndMakeVisible (harm3_squareButton.get());
    harm3_squareButton->setButtonText (TRANS("squ"));
    harm3_squareButton->addListener (this);

    harm3_squareButton->setBounds (491, 191, 40, 24);

    harm3_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm3_depthSlider.get());
    harm3_depthSlider->setRange (-1, 1, 0);
    harm3_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm3_depthSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    harm3_depthSlider->addListener (this);

    harm3_depthSlider->setBounds (307, 161, 136, 48);

    harm3_offsetSlider.reset (new juce::Slider ("offset"));
    addAndMakeVisible (harm3_offsetSlider.get());
    harm3_offsetSlider->setRange (0, 12, 1);
    harm3_offsetSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    harm3_offsetSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    harm3_offsetSlider->addListener (this);

    harm3_offsetSlider->setBounds (544, 168, 150, 39);

    harm4_sineButton.reset (new juce::TextButton ("sine"));
    addAndMakeVisible (harm4_sineButton.get());
    harm4_sineButton->setButtonText (TRANS("Sine"));
    harm4_sineButton->addListener (this);

    harm4_sineButton->setBounds (446, 230, 40, 24);

    harm4_triangleButton.reset (new juce::TextButton ("triangle"));
    addAndMakeVisible (harm4_triangleButton.get());
    harm4_triangleButton->setButtonText (TRANS("Tri"));
    harm4_triangleButton->addListener (this);

    harm4_triangleButton->setBounds (494, 230, 40, 24);

    harm4_sawButton.reset (new juce::TextButton ("saw"));
    addAndMakeVisible (harm4_sawButton.get());
    harm4_sawButton->setButtonText (TRANS("Saw"));
    harm4_sawButton->addListener (this);

    harm4_sawButton->setBounds (446, 262, 40, 24);

    harm4_squareButton.reset (new juce::TextButton ("square"));
    addAndMakeVisible (harm4_squareButton.get());
    harm4_squareButton->setButtonText (TRANS("squ"));
    harm4_squareButton->addListener (this);

    harm4_squareButton->setBounds (494, 262, 40, 24);

    harm4_offsetSlider.reset (new juce::Slider ("offset"));
    addAndMakeVisible (harm4_offsetSlider.get());
    harm4_offsetSlider->setRange (0, 12, 1);
    harm4_offsetSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    harm4_offsetSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    harm4_offsetSlider->addListener (this);

    harm4_offsetSlider->setBounds (544, 240, 150, 40);

    harm4_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm4_depthSlider.get());
    harm4_depthSlider->setRange (-1, 1, 0);
    harm4_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm4_depthSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    harm4_depthSlider->addListener (this);

    harm4_depthSlider->setBounds (304, 232, 144, 48);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

JoeProjectAudioProcessorEditor::~JoeProjectAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_depthSlider = nullptr;
    juce__label = nullptr;
    m_gainSlider = nullptr;
    juce__label2 = nullptr;
    m_sineButton = nullptr;
    m_triangleButton = nullptr;
    m_sawButton = nullptr;
    m_squareButton = nullptr;
    m_panSlider = nullptr;
    Pan_label = nullptr;
    harm1_sineButton = nullptr;
    harm1_triangleButton = nullptr;
    harm1_sawButton = nullptr;
    harm1_squareButton = nullptr;
    harm1_depthSlider = nullptr;
    harm1_offsetSlider = nullptr;
    harm2_sineButton = nullptr;
    harm2_triangleButton = nullptr;
    harm2_sawButton = nullptr;
    harm2_squareButton = nullptr;
    harm2_depthSlider = nullptr;
    harm2_offsetSlider = nullptr;
    harm3_sineButton = nullptr;
    harm3_triangleButton = nullptr;
    harm3_sawButton = nullptr;
    harm3_squareButton = nullptr;
    harm3_depthSlider = nullptr;
    harm3_offsetSlider = nullptr;
    harm4_sineButton = nullptr;
    harm4_triangleButton = nullptr;
    harm4_sawButton = nullptr;
    harm4_squareButton = nullptr;
    harm4_offsetSlider = nullptr;
    harm4_depthSlider = nullptr;


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
        //[/UserSliderCode_m_depthSlider]
    }
    else if (sliderThatWasMoved == m_gainSlider.get())
    {
        //[UserSliderCode_m_gainSlider] -- add your slider handling code here..
        //[/UserSliderCode_m_gainSlider]
    }
    else if (sliderThatWasMoved == m_panSlider.get())
    {
        //[UserSliderCode_m_panSlider] -- add your slider handling code here..
        audioProcessor.updateParameters(kPan, m_panSlider->getValue());
        //[/UserSliderCode_m_panSlider]
    }
    else if (sliderThatWasMoved == harm1_depthSlider.get())
    {
        //[UserSliderCode_harm1_depthSlider] -- add your slider handling code here..
        //[/UserSliderCode_harm1_depthSlider]
    }
    else if (sliderThatWasMoved == harm1_offsetSlider.get())
    {
        //[UserSliderCode_harm1_offsetSlider] -- add your slider handling code here..
        //[/UserSliderCode_harm1_offsetSlider]
    }
    else if (sliderThatWasMoved == harm2_depthSlider.get())
    {
        //[UserSliderCode_harm2_depthSlider] -- add your slider handling code here..
        //[/UserSliderCode_harm2_depthSlider]
    }
    else if (sliderThatWasMoved == harm2_offsetSlider.get())
    {
        //[UserSliderCode_harm2_offsetSlider] -- add your slider handling code here..
        //[/UserSliderCode_harm2_offsetSlider]
    }
    else if (sliderThatWasMoved == harm3_depthSlider.get())
    {
        //[UserSliderCode_harm3_depthSlider] -- add your slider handling code here..
        //[/UserSliderCode_harm3_depthSlider]
    }
    else if (sliderThatWasMoved == harm3_offsetSlider.get())
    {
        //[UserSliderCode_harm3_offsetSlider] -- add your slider handling code here..
        //[/UserSliderCode_harm3_offsetSlider]
    }
    else if (sliderThatWasMoved == harm4_offsetSlider.get())
    {
        //[UserSliderCode_harm4_offsetSlider] -- add your slider handling code here..
        //[/UserSliderCode_harm4_offsetSlider]
    }
    else if (sliderThatWasMoved == harm4_depthSlider.get())
    {
        //[UserSliderCode_harm4_depthSlider] -- add your slider handling code here..
        //[/UserSliderCode_harm4_depthSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void JoeProjectAudioProcessorEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_sineButton.get())
    {
        //[UserButtonCode_m_sineButton] -- add your button handler code here..
        audioProcessor.updateParameters(kWaveform, kSine);
        //[/UserButtonCode_m_sineButton]
    }
    else if (buttonThatWasClicked == m_triangleButton.get())
    {
        //[UserButtonCode_m_triangleButton] -- add your button handler code here..
        audioProcessor.updateParameters(kWaveform, kTriangle);
        //[/UserButtonCode_m_triangleButton]
    }
    else if (buttonThatWasClicked == m_sawButton.get())
    {
        //[UserButtonCode_m_sawButton] -- add your button handler code here..
        audioProcessor.updateParameters(kWaveform, kSaw);
        //[/UserButtonCode_m_sawButton]
    }
    else if (buttonThatWasClicked == m_squareButton.get())
    {
        //[UserButtonCode_m_squareButton] -- add your button handler code here..
        audioProcessor.updateParameters(kWaveform, kSquare);
        //[/UserButtonCode_m_squareButton]
    }
    else if (buttonThatWasClicked == harm1_sineButton.get())
    {
        //[UserButtonCode_harm1_sineButton] -- add your button handler code here..
        //[/UserButtonCode_harm1_sineButton]
    }
    else if (buttonThatWasClicked == harm1_triangleButton.get())
    {
        //[UserButtonCode_harm1_triangleButton] -- add your button handler code here..
        //[/UserButtonCode_harm1_triangleButton]
    }
    else if (buttonThatWasClicked == harm1_sawButton.get())
    {
        //[UserButtonCode_harm1_sawButton] -- add your button handler code here..
        //[/UserButtonCode_harm1_sawButton]
    }
    else if (buttonThatWasClicked == harm1_squareButton.get())
    {
        //[UserButtonCode_harm1_squareButton] -- add your button handler code here..
        //[/UserButtonCode_harm1_squareButton]
    }
    else if (buttonThatWasClicked == harm2_sineButton.get())
    {
        //[UserButtonCode_harm2_sineButton] -- add your button handler code here..
        //[/UserButtonCode_harm2_sineButton]
    }
    else if (buttonThatWasClicked == harm2_triangleButton.get())
    {
        //[UserButtonCode_harm2_triangleButton] -- add your button handler code here..
        //[/UserButtonCode_harm2_triangleButton]
    }
    else if (buttonThatWasClicked == harm2_sawButton.get())
    {
        //[UserButtonCode_harm2_sawButton] -- add your button handler code here..
        //[/UserButtonCode_harm2_sawButton]
    }
    else if (buttonThatWasClicked == harm2_squareButton.get())
    {
        //[UserButtonCode_harm2_squareButton] -- add your button handler code here..
        //[/UserButtonCode_harm2_squareButton]
    }
    else if (buttonThatWasClicked == harm3_sineButton.get())
    {
        //[UserButtonCode_harm3_sineButton] -- add your button handler code here..
        //[/UserButtonCode_harm3_sineButton]
    }
    else if (buttonThatWasClicked == harm3_triangleButton.get())
    {
        //[UserButtonCode_harm3_triangleButton] -- add your button handler code here..
        //[/UserButtonCode_harm3_triangleButton]
    }
    else if (buttonThatWasClicked == harm3_sawButton.get())
    {
        //[UserButtonCode_harm3_sawButton] -- add your button handler code here..
        //[/UserButtonCode_harm3_sawButton]
    }
    else if (buttonThatWasClicked == harm3_squareButton.get())
    {
        //[UserButtonCode_harm3_squareButton] -- add your button handler code here..
        //[/UserButtonCode_harm3_squareButton]
    }
    else if (buttonThatWasClicked == harm4_sineButton.get())
    {
        //[UserButtonCode_harm4_sineButton] -- add your button handler code here..
        //[/UserButtonCode_harm4_sineButton]
    }
    else if (buttonThatWasClicked == harm4_triangleButton.get())
    {
        //[UserButtonCode_harm4_triangleButton] -- add your button handler code here..
        //[/UserButtonCode_harm4_triangleButton]
    }
    else if (buttonThatWasClicked == harm4_sawButton.get())
    {
        //[UserButtonCode_harm4_sawButton] -- add your button handler code here..
        //[/UserButtonCode_harm4_sawButton]
    }
    else if (buttonThatWasClicked == harm4_squareButton.get())
    {
        //[UserButtonCode_harm4_squareButton] -- add your button handler code here..
        //[/UserButtonCode_harm4_squareButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
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
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <SLIDER name="Gain" id="42f75b1dba908f01" memberName="m_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="24 96 128 48" min="-1.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="a07cd26b6f2d246c" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="160 160 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="gain" id="ef8ea6ef3e44ff24" memberName="m_gainSlider" virtualName=""
          explicitFocusOrder="0" pos="160 168 128 48" min="0.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="264bb30d81321ded" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="24 88 51 15" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="sine" id="514c258c4c150462" memberName="m_sineButton" virtualName=""
              explicitFocusOrder="0" pos="168 88 40 24" buttonText="Sine" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="triangle" id="c1a31b02f843b4ae" memberName="m_triangleButton"
              virtualName="" explicitFocusOrder="0" pos="216 88 40 24" buttonText="Tri"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="saw" id="288c261eeaf4e330" memberName="m_sawButton" virtualName=""
              explicitFocusOrder="0" pos="168 120 40 24" buttonText="Saw" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="square" id="3013584e22ea8e55" memberName="m_squareButton"
              virtualName="" explicitFocusOrder="0" pos="216 120 40 24" buttonText="squ"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="pan" id="a46ddc996119acdc" memberName="m_panSlider" virtualName=""
          explicitFocusOrder="0" pos="24 168 128 48" min="-1.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="pan" id="786869f480bd2bcf" memberName="Pan_label" virtualName=""
         explicitFocusOrder="0" pos="24 160 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="sine" id="8ebd04298c88ef8d" memberName="harm1_sineButton"
              virtualName="" explicitFocusOrder="0" pos="440 22 40 24" buttonText="Sine"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="triangle" id="769be70b6489e180" memberName="harm1_triangleButton"
              virtualName="" explicitFocusOrder="0" pos="488 22 40 24" buttonText="Tri"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="saw" id="d607df7411e2199f" memberName="harm1_sawButton"
              virtualName="" explicitFocusOrder="0" pos="440 54 40 24" buttonText="Saw"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="square" id="60d4f51debff870f" memberName="harm1_squareButton"
              virtualName="" explicitFocusOrder="0" pos="488 54 40 24" buttonText="squ"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="Gain" id="f3bbd10d0f0caf92" memberName="harm1_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="304 24 136 48" min="-1.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="offset" id="3467df760a7086ca" memberName="harm1_offsetSlider"
          virtualName="" explicitFocusOrder="0" pos="544 32 150 40" min="0.0"
          max="12.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="sine" id="ea0610c035eb4c18" memberName="harm2_sineButton"
              virtualName="" explicitFocusOrder="0" pos="442 91 40 24" buttonText="Sine"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="triangle" id="22333b5b94c7f0ef" memberName="harm2_triangleButton"
              virtualName="" explicitFocusOrder="0" pos="490 91 40 24" buttonText="Tri"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="saw" id="d75743017b2bd3bf" memberName="harm2_sawButton"
              virtualName="" explicitFocusOrder="0" pos="442 123 40 24" buttonText="Saw"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="square" id="b047c17456784b39" memberName="harm2_squareButton"
              virtualName="" explicitFocusOrder="0" pos="490 123 40 24" buttonText="squ"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="Gain" id="f76fdc232f158507" memberName="harm2_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="306 93 136 48" min="-1.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="offset" id="e0db1edb18870626" memberName="harm2_offsetSlider"
          virtualName="" explicitFocusOrder="0" pos="544 104 150 40" min="0.0"
          max="12.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="sine" id="e27071135b8b1816" memberName="harm3_sineButton"
              virtualName="" explicitFocusOrder="0" pos="443 159 40 24" buttonText="Sine"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="triangle" id="68b89ed613f55726" memberName="harm3_triangleButton"
              virtualName="" explicitFocusOrder="0" pos="491 159 40 24" buttonText="Tri"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="saw" id="1910fc4a3743b041" memberName="harm3_sawButton"
              virtualName="" explicitFocusOrder="0" pos="443 191 40 24" buttonText="Saw"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="square" id="4ec8d1578d17da29" memberName="harm3_squareButton"
              virtualName="" explicitFocusOrder="0" pos="491 191 40 24" buttonText="squ"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="Gain" id="b66381e24df2a4ea" memberName="harm3_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="307 161 136 48" min="-1.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="offset" id="46b58aa0846e7490" memberName="harm3_offsetSlider"
          virtualName="" explicitFocusOrder="0" pos="544 168 150 39" min="0.0"
          max="12.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="sine" id="e96ed3b5f41e38a5" memberName="harm4_sineButton"
              virtualName="" explicitFocusOrder="0" pos="446 230 40 24" buttonText="Sine"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="triangle" id="7955bc785497d3f5" memberName="harm4_triangleButton"
              virtualName="" explicitFocusOrder="0" pos="494 230 40 24" buttonText="Tri"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="saw" id="5e4eb7eb6ed81b36" memberName="harm4_sawButton"
              virtualName="" explicitFocusOrder="0" pos="446 262 40 24" buttonText="Saw"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="square" id="9d26444a36e4eb69" memberName="harm4_squareButton"
              virtualName="" explicitFocusOrder="0" pos="494 262 40 24" buttonText="squ"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="offset" id="84173aedb071d4a9" memberName="harm4_offsetSlider"
          virtualName="" explicitFocusOrder="0" pos="544 240 150 40" min="0.0"
          max="12.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Gain" id="752a662d53726ffc" memberName="harm4_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="304 232 144 48" min="-1.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

