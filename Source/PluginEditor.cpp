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
void JoeProjectAudioProcessorEditor::repaintWaveformButtons(int selectedWaveform){
    harm_sawButton->setColour(0x1000100, juce::Colour());
    harm_squareButton->setColour(0x1000100, juce::Colour());
    harm_sineButton->setColour(0x1000100, juce::Colour());
    harm_triangleButton->setColour(0x1000100, juce::Colour());

    if (selectedWaveform == kSine){harm_sineButton->setColour(0x1000100, juce::Colours::red);}
    if (selectedWaveform == kTriangle){harm_triangleButton->setColour(0x1000100, juce::Colours::red);}
    if (selectedWaveform == kSaw){harm_sawButton->setColour(0x1000100, juce::Colours::red);}
    if (selectedWaveform == kSquare){harm_squareButton->setColour(0x1000100, juce::Colours::red);}

}

void JoeProjectAudioProcessorEditor::repaintSelectButtons(std::unique_ptr<juce::TextButton> & newButton){
    
    harm1_selectButton->setColour(0x1000100, juce::Colour());
    harm2_selectButton->setColour(0x1000100, juce::Colour());
    harm3_selectButton->setColour(0x1000100, juce::Colour());
    harm4_selectButton->setColour(0x1000100, juce::Colour());

    newButton->setColour(0x1000100, juce::Colours::red);
}
//[/MiscUserDefs]

//==============================================================================
JoeProjectAudioProcessorEditor::JoeProjectAudioProcessorEditor (JoeProjectAudioProcessor& owner)
    : AudioProcessorEditor(owner), audioProcessor(owner)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    m_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (m_depthSlider.get());
    m_depthSlider->setRange (0, 1, 0);
    m_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_depthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    m_depthSlider->addListener (this);

    m_depthSlider->setBounds (8, 16, 48, 48);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("Output Gain")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (312, 168, 88, 24);

    m_gainSlider.reset (new juce::Slider ("gain"));
    addAndMakeVisible (m_gainSlider.get());
    m_gainSlider->setRange (0, 1, 0);
    m_gainSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_gainSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_gainSlider->addListener (this);

    m_gainSlider->setBounds (312, 176, 128, 48);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("Depth")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (8, 8, 51, 15);

    m_sineButton.reset (new juce::TextButton ("sine"));
    addAndMakeVisible (m_sineButton.get());
    m_sineButton->setButtonText (TRANS("Sine"));
    m_sineButton->addListener (this);

    m_sineButton->setBounds (64, 16, 40, 24);

    m_triangleButton.reset (new juce::TextButton ("triangle"));
    addAndMakeVisible (m_triangleButton.get());
    m_triangleButton->setButtonText (TRANS("Tri"));
    m_triangleButton->addListener (this);

    m_triangleButton->setBounds (112, 16, 40, 24);

    m_sawButton.reset (new juce::TextButton ("saw"));
    addAndMakeVisible (m_sawButton.get());
    m_sawButton->setButtonText (TRANS("Saw"));
    m_sawButton->addListener (this);

    m_sawButton->setBounds (64, 48, 40, 24);

    m_squareButton.reset (new juce::TextButton ("square"));
    addAndMakeVisible (m_squareButton.get());
    m_squareButton->setButtonText (TRANS("squ"));
    m_squareButton->addListener (this);

    m_squareButton->setBounds (112, 48, 40, 24);

    m_panSlider.reset (new juce::Slider ("pan"));
    addAndMakeVisible (m_panSlider.get());
    m_panSlider->setRange (-1, 1, 0);
    m_panSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_panSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_panSlider->addListener (this);

    m_panSlider->setBounds (176, 176, 128, 48);

    Pan_label.reset (new juce::Label ("pan",
                                      TRANS("Pan")));
    addAndMakeVisible (Pan_label.get());
    Pan_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    Pan_label->setJustificationType (juce::Justification::centredLeft);
    Pan_label->setEditable (false, false, false);
    Pan_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    Pan_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    Pan_label->setBounds (176, 168, 40, 24);

    harm_sineButton.reset (new juce::TextButton ("sine"));
    addAndMakeVisible (harm_sineButton.get());
    harm_sineButton->setButtonText (TRANS("Sine"));
    harm_sineButton->addListener (this);

    harm_sineButton->setBounds (176, 16, 40, 24);

    harm_triangleButton.reset (new juce::TextButton ("triangle"));
    addAndMakeVisible (harm_triangleButton.get());
    harm_triangleButton->setButtonText (TRANS("Tri"));
    harm_triangleButton->addListener (this);

    harm_triangleButton->setBounds (224, 16, 40, 24);

    harm_sawButton.reset (new juce::TextButton ("saw"));
    addAndMakeVisible (harm_sawButton.get());
    harm_sawButton->setButtonText (TRANS("Saw"));
    harm_sawButton->addListener (this);

    harm_sawButton->setBounds (176, 48, 40, 24);

    harm_squareButton.reset (new juce::TextButton ("square"));
    addAndMakeVisible (harm_squareButton.get());
    harm_squareButton->setButtonText (TRANS("squ"));
    harm_squareButton->addListener (this);

    harm_squareButton->setBounds (224, 48, 40, 24);

    harm1_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm1_depthSlider.get());
    harm1_depthSlider->setRange (0, 1, 0);
    harm1_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm1_depthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm1_depthSlider->addListener (this);

    harm1_depthSlider->setBounds (184, 80, 56, 48);

    harm_offsetSlider.reset (new juce::Slider ("offset"));
    addAndMakeVisible (harm_offsetSlider.get());
    harm_offsetSlider->setRange (0, 12, 1);
    harm_offsetSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    harm_offsetSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    harm_offsetSlider->addListener (this);

    harm_offsetSlider->setBounds (296, 24, 150, 40);

    harm2_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm2_depthSlider.get());
    harm2_depthSlider->setRange (0, 1, 0);
    harm2_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm2_depthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm2_depthSlider->addListener (this);

    harm2_depthSlider->setBounds (232, 80, 48, 48);

    harm3_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm3_depthSlider.get());
    harm3_depthSlider->setRange (0, 1, 0);
    harm3_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm3_depthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm3_depthSlider->addListener (this);

    harm3_depthSlider->setBounds (280, 80, 48, 48);

    harm4_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm4_depthSlider.get());
    harm4_depthSlider->setRange (0, 1, 0);
    harm4_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm4_depthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm4_depthSlider->addListener (this);

    harm4_depthSlider->setBounds (328, 80, 48, 48);

    harm1_selectButton.reset (new juce::TextButton ("select"));
    addAndMakeVisible (harm1_selectButton.get());
    harm1_selectButton->setButtonText (TRANS("1"));
    harm1_selectButton->addListener (this);

    harm1_selectButton->setBounds (200, 128, 23, 24);

    harm2_selectButton.reset (new juce::TextButton ("select"));
    addAndMakeVisible (harm2_selectButton.get());
    harm2_selectButton->setButtonText (TRANS("2"));
    harm2_selectButton->addListener (this);

    harm2_selectButton->setBounds (240, 128, 23, 24);

    harm3_selectButton.reset (new juce::TextButton ("select"));
    addAndMakeVisible (harm3_selectButton.get());
    harm3_selectButton->setButtonText (TRANS("3"));
    harm3_selectButton->addListener (this);

    harm3_selectButton->setBounds (288, 128, 23, 24);

    harm4_selectButton.reset (new juce::TextButton ("select"));
    addAndMakeVisible (harm4_selectButton.get());
    harm4_selectButton->setButtonText (TRANS("4"));
    harm4_selectButton->addListener (this);

    harm4_selectButton->setBounds (336, 128, 23, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    repaintSelectButtons(harm1_selectButton);
    repaintWaveformButtons(selectedWaveformArr[harm1]);
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
    harm_sineButton = nullptr;
    harm_triangleButton = nullptr;
    harm_sawButton = nullptr;
    harm_squareButton = nullptr;
    harm1_depthSlider = nullptr;
    harm_offsetSlider = nullptr;
    harm2_depthSlider = nullptr;
    harm3_depthSlider = nullptr;
    harm4_depthSlider = nullptr;
    harm1_selectButton = nullptr;
    harm2_selectButton = nullptr;
    harm3_selectButton = nullptr;
    harm4_selectButton = nullptr;


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
        audioProcessor.updateGlobalParameters(kDepth, m_depthSlider->getValue());
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
    else if (sliderThatWasMoved == harm1_depthSlider.get())
    {
        //[UserSliderCode_harm1_depthSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(0, kDepth, harm1_depthSlider->getValue());
        //[/UserSliderCode_harm1_depthSlider]
    }
    else if (sliderThatWasMoved == harm_offsetSlider.get())
    {
        //[UserSliderCode_harm_offsetSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(kOffset, harm_offsetSlider->getValue());
        //[/UserSliderCode_harm_offsetSlider]
    }
    else if (sliderThatWasMoved == harm2_depthSlider.get())
    {
        //[UserSliderCode_harm2_depthSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(1, kDepth, harm2_depthSlider->getValue());
        //[/UserSliderCode_harm2_depthSlider]
    }
    else if (sliderThatWasMoved == harm3_depthSlider.get())
    {
        //[UserSliderCode_harm3_depthSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(2, kDepth, harm3_depthSlider->getValue());
        //[/UserSliderCode_harm3_depthSlider]
    }
    else if (sliderThatWasMoved == harm4_depthSlider.get())
    {
        //[UserSliderCode_harm4_depthSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(3, kDepth, harm4_depthSlider->getValue());
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
        audioProcessor.updateGlobalParameters(kWaveform, kSine);
        //[/UserButtonCode_m_sineButton]
    }
    else if (buttonThatWasClicked == m_triangleButton.get())
    {
        //[UserButtonCode_m_triangleButton] -- add your button handler code here..
        audioProcessor.updateGlobalParameters(kWaveform, kTriangle);
        //[/UserButtonCode_m_triangleButton]
    }
    else if (buttonThatWasClicked == m_sawButton.get())
    {
        //[UserButtonCode_m_sawButton] -- add your button handler code here..
        audioProcessor.updateGlobalParameters(kWaveform, kSaw);
        //[/UserButtonCode_m_sawButton]
    }
    else if (buttonThatWasClicked == m_squareButton.get())
    {
        //[UserButtonCode_m_squareButton] -- add your button handler code here..
        audioProcessor.updateGlobalParameters(kWaveform, kSquare);
        //[/UserButtonCode_m_squareButton]
    }
    else if (buttonThatWasClicked == harm_sineButton.get())
    {
        //[UserButtonCode_harm_sineButton] -- add your button handler code here..
        audioProcessor.updateHarmParameters(kWaveform, kSine);
        selectedWaveformArr[audioProcessor.getSelectedHarm()] = kSine;
        repaintWaveformButtons(selectedWaveformArr[audioProcessor.getSelectedHarm()]);
        //[/UserButtonCode_harm_sineButton]
    }
    else if (buttonThatWasClicked == harm_triangleButton.get())
    {
        //[UserButtonCode_harm_triangleButton] -- add your button handler code here..
        audioProcessor.updateHarmParameters(kWaveform, kTriangle);
        selectedWaveformArr[audioProcessor.getSelectedHarm()] = kTriangle;
        repaintWaveformButtons(selectedWaveformArr[audioProcessor.getSelectedHarm()]);
        //[/UserButtonCode_harm_triangleButton]
    }
    else if (buttonThatWasClicked == harm_sawButton.get())
    {
        //[UserButtonCode_harm_sawButton] -- add your button handler code here..
        audioProcessor.updateHarmParameters(kWaveform, kSaw);
        selectedWaveformArr[audioProcessor.getSelectedHarm()] = kSaw;
        repaintWaveformButtons(selectedWaveformArr[audioProcessor.getSelectedHarm()]);
        //[/UserButtonCode_harm_sawButton]
    }
    else if (buttonThatWasClicked == harm_squareButton.get())
    {
        //[UserButtonCode_harm_squareButton] -- add your button handler code here..
        audioProcessor.updateHarmParameters(kWaveform, kSquare);
        selectedWaveformArr[audioProcessor.getSelectedHarm()] = kSquare;
        repaintWaveformButtons(selectedWaveformArr[audioProcessor.getSelectedHarm()]);
        //[/UserButtonCode_harm_squareButton]
    }
    else if (buttonThatWasClicked == harm1_selectButton.get())
    {
        //[UserButtonCode_harm1_selectButton] -- add your button handler code here..
        audioProcessor.setHarm(harm1);

        repaintSelectButtons(harm1_selectButton);
        repaintWaveformButtons(selectedWaveformArr[audioProcessor.getSelectedHarm()]);

        harm_offsetSlider->setValue(audioProcessor.getHarm(harm1).getOffset());
        //[/UserButtonCode_harm1_selectButton]
    }
    else if (buttonThatWasClicked == harm2_selectButton.get())
    {
        //[UserButtonCode_harm2_selectButton] -- add your button handler code here..
        audioProcessor.setHarm(harm2);

        repaintSelectButtons(harm2_selectButton);
        repaintWaveformButtons(selectedWaveformArr[audioProcessor.getSelectedHarm()]);

        harm_offsetSlider->setValue(audioProcessor.getHarm(harm2).getOffset());
        //[/UserButtonCode_harm2_selectButton]
    }
    else if (buttonThatWasClicked == harm3_selectButton.get())
    {
        //[UserButtonCode_harm3_selectButton] -- add your button handler code here..
        audioProcessor.setHarm(harm3);

        repaintSelectButtons(harm3_selectButton);
        repaintWaveformButtons(selectedWaveformArr[audioProcessor.getSelectedHarm()]);

        harm_offsetSlider->setValue(audioProcessor.getHarm(harm3).getOffset());
        //[/UserButtonCode_harm3_selectButton]
    }
    else if (buttonThatWasClicked == harm4_selectButton.get())
    {
        //[UserButtonCode_harm4_selectButton] -- add your button handler code here..
        audioProcessor.setHarm(harm4);

        repaintSelectButtons(harm4_selectButton);
        repaintWaveformButtons(selectedWaveformArr[audioProcessor.getSelectedHarm()]);

        harm_offsetSlider->setValue(audioProcessor.getHarm(harm4).getOffset());
        //[/UserButtonCode_harm4_selectButton]
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
          virtualName="" explicitFocusOrder="0" pos="8 16 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="a07cd26b6f2d246c" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="312 168 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="gain" id="ef8ea6ef3e44ff24" memberName="m_gainSlider" virtualName=""
          explicitFocusOrder="0" pos="312 176 128 48" min="0.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="264bb30d81321ded" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="8 8 51 15" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="sine" id="514c258c4c150462" memberName="m_sineButton" virtualName=""
              explicitFocusOrder="0" pos="64 16 40 24" buttonText="Sine" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="triangle" id="c1a31b02f843b4ae" memberName="m_triangleButton"
              virtualName="" explicitFocusOrder="0" pos="112 16 40 24" buttonText="Tri"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="saw" id="288c261eeaf4e330" memberName="m_sawButton" virtualName=""
              explicitFocusOrder="0" pos="64 48 40 24" buttonText="Saw" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="square" id="3013584e22ea8e55" memberName="m_squareButton"
              virtualName="" explicitFocusOrder="0" pos="112 48 40 24" buttonText="squ"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="pan" id="a46ddc996119acdc" memberName="m_panSlider" virtualName=""
          explicitFocusOrder="0" pos="176 176 128 48" min="-1.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="pan" id="786869f480bd2bcf" memberName="Pan_label" virtualName=""
         explicitFocusOrder="0" pos="176 168 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="sine" id="8ebd04298c88ef8d" memberName="harm_sineButton"
              virtualName="" explicitFocusOrder="0" pos="176 16 40 24" buttonText="Sine"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="triangle" id="769be70b6489e180" memberName="harm_triangleButton"
              virtualName="" explicitFocusOrder="0" pos="224 16 40 24" buttonText="Tri"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="saw" id="d607df7411e2199f" memberName="harm_sawButton"
              virtualName="" explicitFocusOrder="0" pos="176 48 40 24" buttonText="Saw"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="square" id="60d4f51debff870f" memberName="harm_squareButton"
              virtualName="" explicitFocusOrder="0" pos="224 48 40 24" buttonText="squ"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="Gain" id="f3bbd10d0f0caf92" memberName="harm1_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="184 80 56 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="offset" id="3467df760a7086ca" memberName="harm_offsetSlider"
          virtualName="" explicitFocusOrder="0" pos="296 24 150 40" min="0.0"
          max="12.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Gain" id="f76fdc232f158507" memberName="harm2_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="232 80 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Gain" id="b66381e24df2a4ea" memberName="harm3_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="280 80 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Gain" id="752a662d53726ffc" memberName="harm4_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="328 80 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="select" id="662d6df114ed90ae" memberName="harm1_selectButton"
              virtualName="" explicitFocusOrder="0" pos="200 128 23 24" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="select" id="5d9a6e83e7b7594c" memberName="harm2_selectButton"
              virtualName="" explicitFocusOrder="0" pos="240 128 23 24" buttonText="2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="select" id="d434d7b6c26418eb" memberName="harm3_selectButton"
              virtualName="" explicitFocusOrder="0" pos="288 128 23 24" buttonText="3"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="select" id="da46dcdcec41660a" memberName="harm4_selectButton"
              virtualName="" explicitFocusOrder="0" pos="336 128 23 24" buttonText="4"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

