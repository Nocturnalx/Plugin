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
void JoeProjectAudioProcessorEditor::repaintWfButtons(std::unique_ptr<juce::TextButton> & newButton){

    m_sineButton->setColour(0x1000100, juce::Colour());
    m_triangleButton->setColour(0x1000100, juce::Colour());
    m_sawButton->setColour(0x1000100, juce::Colour());
    m_squareButton->setColour(0x1000100, juce::Colour());

    newButton->setColour(0x1000100, juce::Colours::red);
}

void JoeProjectAudioProcessorEditor::repaintHarmWfButtons(int harmWaveform){
    harm_sawButton->setColour(0x1000100, juce::Colour());
    harm_squareButton->setColour(0x1000100, juce::Colour());
    harm_sineButton->setColour(0x1000100, juce::Colour());
    harm_triangleButton->setColour(0x1000100, juce::Colour());

    if (harmWaveform == kSine){harm_sineButton->setColour(0x1000100, juce::Colours::red);}
    if (harmWaveform == kTriangle){harm_triangleButton->setColour(0x1000100, juce::Colours::red);}
    if (harmWaveform == kSaw){harm_sawButton->setColour(0x1000100, juce::Colours::red);}
    if (harmWaveform == kSquare){harm_squareButton->setColour(0x1000100, juce::Colours::red);}

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

    effects_group.reset (new juce::GroupComponent ("effects group",
                                                   TRANS("Effects")));
    addAndMakeVisible (effects_group.get());

    effects_group->setBounds (552, 0, 298, 192);

    effects_group2.reset (new juce::GroupComponent ("effects group",
                                                    TRANS("Mix")));
    addAndMakeVisible (effects_group2.get());

    effects_group2->setBounds (850, 0, 150, 192);

    master_group.reset (new juce::GroupComponent ("master group",
                                                  TRANS("Master Oscillator")));
    addAndMakeVisible (master_group.get());

    master_group->setBounds (0, 0, 200, 192);

    harmonics_group.reset (new juce::GroupComponent ("harmonics group",
                                                     TRANS("Harmonic Oscillators")));
    addAndMakeVisible (harmonics_group.get());

    harmonics_group->setBounds (200, 0, 352, 192);

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

    juce__label->setBounds (864, 136, 88, 24);

    m_gainSlider.reset (new juce::Slider ("gain"));
    addAndMakeVisible (m_gainSlider.get());
    m_gainSlider->setRange (0, 1, 0);
    m_gainSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_gainSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_gainSlider->addListener (this);

    m_gainSlider->setBounds (864, 144, 128, 48);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("Depth")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (24, 24, 51, 15);

    m_sineButton.reset (new juce::TextButton ("sine"));
    addAndMakeVisible (m_sineButton.get());
    m_sineButton->setButtonText (TRANS("Sine"));
    m_sineButton->addListener (this);

    m_sineButton->setBounds (80, 32, 40, 24);

    m_triangleButton.reset (new juce::TextButton ("triangle"));
    addAndMakeVisible (m_triangleButton.get());
    m_triangleButton->setButtonText (TRANS("Tri"));
    m_triangleButton->addListener (this);

    m_triangleButton->setBounds (128, 32, 40, 24);

    m_sawButton.reset (new juce::TextButton ("saw"));
    addAndMakeVisible (m_sawButton.get());
    m_sawButton->setButtonText (TRANS("Saw"));
    m_sawButton->addListener (this);

    m_sawButton->setBounds (80, 64, 40, 24);

    m_squareButton.reset (new juce::TextButton ("square"));
    addAndMakeVisible (m_squareButton.get());
    m_squareButton->setButtonText (TRANS("squ"));
    m_squareButton->addListener (this);

    m_squareButton->setBounds (128, 64, 40, 24);

    m_panSlider.reset (new juce::Slider ("pan"));
    addAndMakeVisible (m_panSlider.get());
    m_panSlider->setRange (-1, 1, 0);
    m_panSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_panSlider->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    m_panSlider->addListener (this);

    m_panSlider->setBounds (864, 96, 128, 48);

    Pan_label.reset (new juce::Label ("pan",
                                      TRANS("Pan")));
    addAndMakeVisible (Pan_label.get());
    Pan_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    Pan_label->setJustificationType (juce::Justification::centredLeft);
    Pan_label->setEditable (false, false, false);
    Pan_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    Pan_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    Pan_label->setBounds (864, 88, 80, 24);

    harm_sineButton.reset (new juce::TextButton ("sine"));
    addAndMakeVisible (harm_sineButton.get());
    harm_sineButton->setButtonText (TRANS("Sine"));
    harm_sineButton->addListener (this);

    harm_sineButton->setBounds (240, 104, 40, 24);

    harm_triangleButton.reset (new juce::TextButton ("triangle"));
    addAndMakeVisible (harm_triangleButton.get());
    harm_triangleButton->setButtonText (TRANS("Tri"));
    harm_triangleButton->addListener (this);

    harm_triangleButton->setBounds (288, 104, 40, 24);

    harm_sawButton.reset (new juce::TextButton ("saw"));
    addAndMakeVisible (harm_sawButton.get());
    harm_sawButton->setButtonText (TRANS("Saw"));
    harm_sawButton->addListener (this);

    harm_sawButton->setBounds (240, 136, 40, 24);

    harm_squareButton.reset (new juce::TextButton ("square"));
    addAndMakeVisible (harm_squareButton.get());
    harm_squareButton->setButtonText (TRANS("squ"));
    harm_squareButton->addListener (this);

    harm_squareButton->setBounds (288, 136, 40, 24);

    harm1_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm1_depthSlider.get());
    harm1_depthSlider->setRange (0, 1, 0);
    harm1_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm1_depthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm1_depthSlider->addListener (this);

    harm1_depthSlider->setBounds (352, 104, 56, 48);

    harm_offsetSlider.reset (new juce::Slider ("offset"));
    addAndMakeVisible (harm_offsetSlider.get());
    harm_offsetSlider->setRange (0, 12, 1);
    harm_offsetSlider->setSliderStyle (juce::Slider::LinearHorizontal);
    harm_offsetSlider->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    harm_offsetSlider->addListener (this);

    harm_offsetSlider->setBounds (208, 32, 150, 40);

    harm2_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm2_depthSlider.get());
    harm2_depthSlider->setRange (0, 1, 0);
    harm2_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm2_depthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm2_depthSlider->addListener (this);

    harm2_depthSlider->setBounds (400, 104, 48, 48);

    harm3_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm3_depthSlider.get());
    harm3_depthSlider->setRange (0, 1, 0);
    harm3_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm3_depthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm3_depthSlider->addListener (this);

    harm3_depthSlider->setBounds (448, 104, 48, 48);

    harm4_depthSlider.reset (new juce::Slider ("Gain"));
    addAndMakeVisible (harm4_depthSlider.get());
    harm4_depthSlider->setRange (0, 1, 0);
    harm4_depthSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm4_depthSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm4_depthSlider->addListener (this);

    harm4_depthSlider->setBounds (496, 104, 48, 48);

    harm1_selectButton.reset (new juce::TextButton ("select"));
    addAndMakeVisible (harm1_selectButton.get());
    harm1_selectButton->setButtonText (TRANS("1"));
    harm1_selectButton->addListener (this);

    harm1_selectButton->setBounds (368, 152, 23, 24);

    harm2_selectButton.reset (new juce::TextButton ("select"));
    addAndMakeVisible (harm2_selectButton.get());
    harm2_selectButton->setButtonText (TRANS("2"));
    harm2_selectButton->addListener (this);

    harm2_selectButton->setBounds (408, 152, 23, 24);

    harm3_selectButton.reset (new juce::TextButton ("select"));
    addAndMakeVisible (harm3_selectButton.get());
    harm3_selectButton->setButtonText (TRANS("3"));
    harm3_selectButton->addListener (this);

    harm3_selectButton->setBounds (456, 152, 23, 24);

    harm4_selectButton.reset (new juce::TextButton ("select"));
    addAndMakeVisible (harm4_selectButton.get());
    harm4_selectButton->setButtonText (TRANS("4"));
    harm4_selectButton->addListener (this);

    harm4_selectButton->setBounds (504, 152, 23, 24);

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

    harm_attackSlider.reset (new juce::Slider ("attack"));
    addAndMakeVisible (harm_attackSlider.get());
    harm_attackSlider->setRange (0, 0.5, 0);
    harm_attackSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_attackSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_attackSlider->addListener (this);

    harm_attackSlider->setBounds (408, 31, 47, 48);

    harm_decaySlider.reset (new juce::Slider ("delay"));
    addAndMakeVisible (harm_decaySlider.get());
    harm_decaySlider->setRange (0, 0.5, 0);
    harm_decaySlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_decaySlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_decaySlider->addListener (this);

    harm_decaySlider->setBounds (440, 31, 47, 48);

    harm_sustainSlider.reset (new juce::Slider ("sustain"));
    addAndMakeVisible (harm_sustainSlider.get());
    harm_sustainSlider->setRange (0, 2, 0.01);
    harm_sustainSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_sustainSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_sustainSlider->addListener (this);

    harm_sustainSlider->setBounds (472, 31, 47, 48);

    harm_releaseSlider.reset (new juce::Slider ("release"));
    addAndMakeVisible (harm_releaseSlider.get());
    harm_releaseSlider->setRange (0, 2, 0);
    harm_releaseSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_releaseSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_releaseSlider->addListener (this);

    harm_releaseSlider->setBounds (504, 31, 47, 48);

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

    attack_label2.reset (new juce::Label ("attack_label",
                                          TRANS("A")));
    addAndMakeVisible (attack_label2.get());
    attack_label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    attack_label2->setJustificationType (juce::Justification::centredLeft);
    attack_label2->setEditable (false, false, false);
    attack_label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    attack_label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    attack_label2->setBounds (416, 17, 23, 24);

    decay_label2.reset (new juce::Label ("deay_label",
                                         TRANS("D")));
    addAndMakeVisible (decay_label2.get());
    decay_label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    decay_label2->setJustificationType (juce::Justification::centredLeft);
    decay_label2->setEditable (false, false, false);
    decay_label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    decay_label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    decay_label2->setBounds (447, 17, 23, 24);

    sustain_label2.reset (new juce::Label ("sustain_label",
                                           TRANS("S")));
    addAndMakeVisible (sustain_label2.get());
    sustain_label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sustain_label2->setJustificationType (juce::Justification::centredLeft);
    sustain_label2->setEditable (false, false, false);
    sustain_label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sustain_label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    sustain_label2->setBounds (479, 17, 23, 24);

    release_label2.reset (new juce::Label ("release_label",
                                           TRANS("R")));
    addAndMakeVisible (release_label2.get());
    release_label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    release_label2->setJustificationType (juce::Justification::centredLeft);
    release_label2->setEditable (false, false, false);
    release_label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    release_label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    release_label2->setBounds (511, 17, 23, 24);

    m_sustainHeightSlider.reset (new juce::Slider ("sustain height"));
    addAndMakeVisible (m_sustainHeightSlider.get());
    m_sustainHeightSlider->setRange (0, 1, 0);
    m_sustainHeightSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_sustainHeightSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    m_sustainHeightSlider->addListener (this);

    m_sustainHeightSlider->setBounds (120, 144, 47, 48);

    harm_sustainHeightSlider.reset (new juce::Slider ("sustain height"));
    addAndMakeVisible (harm_sustainHeightSlider.get());
    harm_sustainHeightSlider->setRange (0, 1, 0);
    harm_sustainHeightSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    harm_sustainHeightSlider->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    harm_sustainHeightSlider->addListener (this);

    harm_sustainHeightSlider->setBounds (472, 64, 47, 48);

    sustainHeight_label.reset (new juce::Label ("sustainHeight_label",
                                                TRANS("Sus level:")));
    addAndMakeVisible (sustainHeight_label.get());
    sustainHeight_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sustainHeight_label->setJustificationType (juce::Justification::centredLeft);
    sustainHeight_label->setEditable (false, false, false);
    sustainHeight_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sustainHeight_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    sustainHeight_label->setBounds (8, 160, 71, 24);

    sustainHeight_label2.reset (new juce::Label ("sustainHeight_label",
                                                 TRANS("Sus level:")));
    addAndMakeVisible (sustainHeight_label2.get());
    sustainHeight_label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    sustainHeight_label2->setJustificationType (juce::Justification::centredLeft);
    sustainHeight_label2->setEditable (false, false, false);
    sustainHeight_label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    sustainHeight_label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    sustainHeight_label2->setBounds (352, 80, 71, 24);

    time_label.reset (new juce::Label ("time",
                                       TRANS("Time S:")));
    addAndMakeVisible (time_label.get());
    time_label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    time_label->setJustificationType (juce::Justification::centredLeft);
    time_label->setEditable (false, false, false);
    time_label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    time_label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    time_label->setBounds (8, 128, 55, 24);

    time_label2.reset (new juce::Label ("time",
                                        TRANS("Time S:")));
    addAndMakeVisible (time_label2.get());
    time_label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    time_label2->setJustificationType (juce::Justification::centredLeft);
    time_label2->setEditable (false, false, false);
    time_label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    time_label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    time_label2->setBounds (360, 48, 55, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 200);


    //[Constructor] You can add your own custom stuff here..

    //these all just set GUI values to their defaults on launch
    m_depthSlider->setValue(1);
    m_gainSlider->setValue(1);

    m_attackSlider->setValue(audioProcessor.getOscADSR(kAttack));
    m_decaySlider->setValue(audioProcessor.getOscADSR(kDecay));
    m_sustainSlider->setValue(audioProcessor.getOscADSR(kSustain));
    m_sustainHeightSlider->setValue(audioProcessor.getOscADSR(kSustainHeight));
    m_releaseSlider->setValue(audioProcessor.getOscADSR(kRelease));

    m_sineButton->triggerClick();
    harm1_selectButton->triggerClick();
    //[/Constructor]
}

JoeProjectAudioProcessorEditor::~JoeProjectAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    effects_group = nullptr;
    effects_group2 = nullptr;
    master_group = nullptr;
    harmonics_group = nullptr;
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
    m_attackSlider = nullptr;
    m_decaySlider = nullptr;
    m_sustainSlider = nullptr;
    m_releaseSlider = nullptr;
    harm_attackSlider = nullptr;
    harm_decaySlider = nullptr;
    harm_sustainSlider = nullptr;
    harm_releaseSlider = nullptr;
    attack_label = nullptr;
    decay_label = nullptr;
    sustain_label = nullptr;
    release_label = nullptr;
    attack_label2 = nullptr;
    decay_label2 = nullptr;
    sustain_label2 = nullptr;
    release_label2 = nullptr;
    m_sustainHeightSlider = nullptr;
    harm_sustainHeightSlider = nullptr;
    sustainHeight_label = nullptr;
    sustainHeight_label2 = nullptr;
    time_label = nullptr;
    time_label2 = nullptr;


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
        audioProcessor.updateHarmParameters(harm1, kDepth, harm1_depthSlider->getValue());
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
        audioProcessor.updateHarmParameters(harm2, kDepth, harm2_depthSlider->getValue());
        //[/UserSliderCode_harm2_depthSlider]
    }
    else if (sliderThatWasMoved == harm3_depthSlider.get())
    {
        //[UserSliderCode_harm3_depthSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(harm3, kDepth, harm3_depthSlider->getValue());
        //[/UserSliderCode_harm3_depthSlider]
    }
    else if (sliderThatWasMoved == harm4_depthSlider.get())
    {
        //[UserSliderCode_harm4_depthSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(harm4, kDepth, harm4_depthSlider->getValue());
        //[/UserSliderCode_harm4_depthSlider]
    }
    else if (sliderThatWasMoved == m_attackSlider.get())
    {
        //[UserSliderCode_m_attackSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kADSR, kAttack, m_attackSlider->getValue());
        //[/UserSliderCode_m_attackSlider]
    }
    else if (sliderThatWasMoved == m_decaySlider.get())
    {
        //[UserSliderCode_m_decaySlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kADSR, kDecay, m_decaySlider->getValue());
        //[/UserSliderCode_m_decaySlider]
    }
    else if (sliderThatWasMoved == m_sustainSlider.get())
    {
        //[UserSliderCode_m_sustainSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kADSR, kSustain, m_sustainSlider->getValue());
        //[/UserSliderCode_m_sustainSlider]
    }
    else if (sliderThatWasMoved == m_releaseSlider.get())
    {
        //[UserSliderCode_m_releaseSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kADSR, kRelease, m_releaseSlider->getValue());
        //[/UserSliderCode_m_releaseSlider]
    }
    else if (sliderThatWasMoved == harm_attackSlider.get())
    {
        //[UserSliderCode_harm_attackSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(kADSR, kAttack, harm_attackSlider->getValue());
        //[/UserSliderCode_harm_attackSlider]
    }
    else if (sliderThatWasMoved == harm_decaySlider.get())
    {
        //[UserSliderCode_harm_decaySlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(kADSR, kDecay, harm_decaySlider->getValue());
        //[/UserSliderCode_harm_decaySlider]
    }
    else if (sliderThatWasMoved == harm_sustainSlider.get())
    {
        //[UserSliderCode_harm_sustainSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(kADSR, kSustain, harm_sustainSlider->getValue());
        //[/UserSliderCode_harm_sustainSlider]
    }
    else if (sliderThatWasMoved == harm_releaseSlider.get())
    {
        //[UserSliderCode_harm_releaseSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(kADSR, kRelease, harm_releaseSlider->getValue());
        //[/UserSliderCode_harm_releaseSlider]
    }
    else if (sliderThatWasMoved == m_sustainHeightSlider.get())
    {
        //[UserSliderCode_m_sustainHeightSlider] -- add your slider handling code here..
        audioProcessor.updateGlobalParameters(kADSR, kSustainHeight, m_sustainHeightSlider->getValue());
        //[/UserSliderCode_m_sustainHeightSlider]
    }
    else if (sliderThatWasMoved == harm_sustainHeightSlider.get())
    {
        //[UserSliderCode_harm_sustainHeightSlider] -- add your slider handling code here..
        audioProcessor.updateHarmParameters(kADSR, kSustainHeight, harm_sustainHeightSlider->getValue());
        //[/UserSliderCode_harm_sustainHeightSlider]
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
        repaintWfButtons(m_sineButton);
        //[/UserButtonCode_m_sineButton]
    }
    else if (buttonThatWasClicked == m_triangleButton.get())
    {
        //[UserButtonCode_m_triangleButton] -- add your button handler code here..
        audioProcessor.updateGlobalParameters(kWaveform, kTriangle);
        repaintWfButtons(m_triangleButton);
        //[/UserButtonCode_m_triangleButton]
    }
    else if (buttonThatWasClicked == m_sawButton.get())
    {
        //[UserButtonCode_m_sawButton] -- add your button handler code here..
        audioProcessor.updateGlobalParameters(kWaveform, kSaw);
        repaintWfButtons(m_sawButton);
        //[/UserButtonCode_m_sawButton]
    }
    else if (buttonThatWasClicked == m_squareButton.get())
    {
        //[UserButtonCode_m_squareButton] -- add your button handler code here..
        audioProcessor.updateGlobalParameters(kWaveform, kSquare);
        repaintWfButtons(m_squareButton);
        //[/UserButtonCode_m_squareButton]
    }
    else if (buttonThatWasClicked == harm_sineButton.get())
    {
        //[UserButtonCode_harm_sineButton] -- add your button handler code here..
        audioProcessor.updateHarmParameters(kWaveform, kSine);
        harmWaveformArr[audioProcessor.getSelectedHarm()] = kSine;
        repaintHarmWfButtons(harmWaveformArr[audioProcessor.getSelectedHarm()]);
        //[/UserButtonCode_harm_sineButton]
    }
    else if (buttonThatWasClicked == harm_triangleButton.get())
    {
        //[UserButtonCode_harm_triangleButton] -- add your button handler code here..
        audioProcessor.updateHarmParameters(kWaveform, kTriangle);
        harmWaveformArr[audioProcessor.getSelectedHarm()] = kTriangle;
        repaintHarmWfButtons(harmWaveformArr[audioProcessor.getSelectedHarm()]);
        //[/UserButtonCode_harm_triangleButton]
    }
    else if (buttonThatWasClicked == harm_sawButton.get())
    {
        //[UserButtonCode_harm_sawButton] -- add your button handler code here..
        audioProcessor.updateHarmParameters(kWaveform, kSaw);
        harmWaveformArr[audioProcessor.getSelectedHarm()] = kSaw;
        repaintHarmWfButtons(harmWaveformArr[audioProcessor.getSelectedHarm()]);
        //[/UserButtonCode_harm_sawButton]
    }
    else if (buttonThatWasClicked == harm_squareButton.get())
    {
        //[UserButtonCode_harm_squareButton] -- add your button handler code here..
        audioProcessor.updateHarmParameters(kWaveform, kSquare);
        harmWaveformArr[audioProcessor.getSelectedHarm()] = kSquare;
        repaintHarmWfButtons(harmWaveformArr[audioProcessor.getSelectedHarm()]);
        //[/UserButtonCode_harm_squareButton]
    }
    else if (buttonThatWasClicked == harm1_selectButton.get())
    {
        //[UserButtonCode_harm1_selectButton] -- add your button handler code here..
        audioProcessor.setHarm(harm1);

        repaintSelectButtons(harm1_selectButton);
        repaintHarmWfButtons(harmWaveformArr[audioProcessor.getSelectedHarm()]);
        
        //set offset slider
        harm_offsetSlider->setValue(audioProcessor.getHarmOffset(harm1));

        //set ADSR
        harm_attackSlider->setValue(audioProcessor.getOscADSR(kAttack, harm1));
        harm_decaySlider->setValue(audioProcessor.getOscADSR(kDecay, harm1));
        harm_sustainSlider->setValue(audioProcessor.getOscADSR(kSustain, harm1));
        harm_sustainHeightSlider->setValue(audioProcessor.getOscADSR(kSustainHeight, harm1));
        harm_releaseSlider->setValue(audioProcessor.getOscADSR(kRelease, harm1));
        //[/UserButtonCode_harm1_selectButton]
    }
    else if (buttonThatWasClicked == harm2_selectButton.get())
    {
        //[UserButtonCode_harm2_selectButton] -- add your button handler code here..
        audioProcessor.setHarm(harm2);

        repaintSelectButtons(harm2_selectButton);
        repaintHarmWfButtons(harmWaveformArr[audioProcessor.getSelectedHarm()]);

        //set offset slider
        harm_offsetSlider->setValue(audioProcessor.getHarmOffset(harm2));

        //set ADSR
        harm_attackSlider->setValue(audioProcessor.getOscADSR(kAttack, harm2));
        harm_decaySlider->setValue(audioProcessor.getOscADSR(kDecay, harm2));
        harm_sustainSlider->setValue(audioProcessor.getOscADSR(kSustain, harm2));
        harm_sustainHeightSlider->setValue(audioProcessor.getOscADSR(kSustainHeight, harm2));
        harm_releaseSlider->setValue(audioProcessor.getOscADSR(kRelease, harm2));
        //[/UserButtonCode_harm2_selectButton]
    }
    else if (buttonThatWasClicked == harm3_selectButton.get())
    {
        //[UserButtonCode_harm3_selectButton] -- add your button handler code here..
        audioProcessor.setHarm(harm3);

        repaintSelectButtons(harm3_selectButton);
        repaintHarmWfButtons(harmWaveformArr[audioProcessor.getSelectedHarm()]);

        //set offset slider
        harm_offsetSlider->setValue(audioProcessor.getHarmOffset(harm3));

        //set ADSR
        harm_attackSlider->setValue(audioProcessor.getOscADSR(kAttack, harm3));
        harm_decaySlider->setValue(audioProcessor.getOscADSR(kDecay, harm3));
        harm_sustainSlider->setValue(audioProcessor.getOscADSR(kSustain, harm3));
        harm_sustainHeightSlider->setValue(audioProcessor.getOscADSR(kSustainHeight, harm3));
        harm_releaseSlider->setValue(audioProcessor.getOscADSR(kRelease, harm3));
        //[/UserButtonCode_harm3_selectButton]
    }
    else if (buttonThatWasClicked == harm4_selectButton.get())
    {
        //[UserButtonCode_harm4_selectButton] -- add your button handler code here..
        audioProcessor.setHarm(harm4);

        repaintSelectButtons(harm4_selectButton);
        repaintHarmWfButtons(harmWaveformArr[audioProcessor.getSelectedHarm()]);

        //set offset slider
        harm_offsetSlider->setValue(audioProcessor.getHarmOffset(harm4));

        //set ADSR
        harm_attackSlider->setValue(audioProcessor.getOscADSR(kAttack, harm4));
        harm_decaySlider->setValue(audioProcessor.getOscADSR(kDecay, harm4));
        harm_sustainSlider->setValue(audioProcessor.getOscADSR(kSustain, harm4));
        harm_sustainHeightSlider->setValue(audioProcessor.getOscADSR(kSustainHeight, harm4));
        harm_releaseSlider->setValue(audioProcessor.getOscADSR(kRelease, harm4));
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
                 fixedSize="0" initialWidth="1000" initialHeight="200">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GROUPCOMPONENT name="effects group" id="a1843f4e14437c21" memberName="effects_group"
                  virtualName="" explicitFocusOrder="0" pos="552 0 298 192" title="Effects"/>
  <GROUPCOMPONENT name="effects group" id="a352b916ecb48379" memberName="effects_group2"
                  virtualName="" explicitFocusOrder="0" pos="850 0 150 192" title="Mix"/>
  <GROUPCOMPONENT name="master group" id="25f270b0cd5b75bf" memberName="master_group"
                  virtualName="" explicitFocusOrder="0" pos="0 0 200 192" title="Master Oscillator"/>
  <GROUPCOMPONENT name="harmonics group" id="ab300ba060ef6c2c" memberName="harmonics_group"
                  virtualName="" explicitFocusOrder="0" pos="200 0 352 192" title="Harmonic Oscillators"/>
  <SLIDER name="Gain" id="42f75b1dba908f01" memberName="m_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="24 32 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="a07cd26b6f2d246c" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="864 136 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Output Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="gain" id="ef8ea6ef3e44ff24" memberName="m_gainSlider" virtualName=""
          explicitFocusOrder="0" pos="864 144 128 48" min="0.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="new label" id="264bb30d81321ded" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="24 24 51 15" edTextCol="ff000000"
         edBkgCol="0" labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="sine" id="514c258c4c150462" memberName="m_sineButton" virtualName=""
              explicitFocusOrder="0" pos="80 32 40 24" buttonText="Sine" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="triangle" id="c1a31b02f843b4ae" memberName="m_triangleButton"
              virtualName="" explicitFocusOrder="0" pos="128 32 40 24" buttonText="Tri"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="saw" id="288c261eeaf4e330" memberName="m_sawButton" virtualName=""
              explicitFocusOrder="0" pos="80 64 40 24" buttonText="Saw" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="square" id="3013584e22ea8e55" memberName="m_squareButton"
              virtualName="" explicitFocusOrder="0" pos="128 64 40 24" buttonText="squ"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="pan" id="a46ddc996119acdc" memberName="m_panSlider" virtualName=""
          explicitFocusOrder="0" pos="864 96 128 48" min="-1.0" max="1.0"
          int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="pan" id="786869f480bd2bcf" memberName="Pan_label" virtualName=""
         explicitFocusOrder="0" pos="864 88 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="sine" id="8ebd04298c88ef8d" memberName="harm_sineButton"
              virtualName="" explicitFocusOrder="0" pos="240 104 40 24" buttonText="Sine"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="triangle" id="769be70b6489e180" memberName="harm_triangleButton"
              virtualName="" explicitFocusOrder="0" pos="288 104 40 24" buttonText="Tri"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="saw" id="d607df7411e2199f" memberName="harm_sawButton"
              virtualName="" explicitFocusOrder="0" pos="240 136 40 24" buttonText="Saw"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="square" id="60d4f51debff870f" memberName="harm_squareButton"
              virtualName="" explicitFocusOrder="0" pos="288 136 40 24" buttonText="squ"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="Gain" id="f3bbd10d0f0caf92" memberName="harm1_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="352 104 56 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="offset" id="3467df760a7086ca" memberName="harm_offsetSlider"
          virtualName="" explicitFocusOrder="0" pos="208 32 150 40" min="0.0"
          max="12.0" int="1.0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Gain" id="f76fdc232f158507" memberName="harm2_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="400 104 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Gain" id="b66381e24df2a4ea" memberName="harm3_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="448 104 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Gain" id="752a662d53726ffc" memberName="harm4_depthSlider"
          virtualName="" explicitFocusOrder="0" pos="496 104 48 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="select" id="662d6df114ed90ae" memberName="harm1_selectButton"
              virtualName="" explicitFocusOrder="0" pos="368 152 23 24" buttonText="1"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="select" id="5d9a6e83e7b7594c" memberName="harm2_selectButton"
              virtualName="" explicitFocusOrder="0" pos="408 152 23 24" buttonText="2"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="select" id="d434d7b6c26418eb" memberName="harm3_selectButton"
              virtualName="" explicitFocusOrder="0" pos="456 152 23 24" buttonText="3"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="select" id="da46dcdcec41660a" memberName="harm4_selectButton"
              virtualName="" explicitFocusOrder="0" pos="504 152 23 24" buttonText="4"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
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
  <SLIDER name="attack" id="447495dd3cebd030" memberName="harm_attackSlider"
          virtualName="" explicitFocusOrder="0" pos="408 31 47 48" min="0.0"
          max="0.5" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="delay" id="b1986229c9464157" memberName="harm_decaySlider"
          virtualName="" explicitFocusOrder="0" pos="440 31 47 48" min="0.0"
          max="0.5" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="sustain" id="3eb6134722da797b" memberName="harm_sustainSlider"
          virtualName="" explicitFocusOrder="0" pos="472 31 47 48" min="0.0"
          max="2.0" int="0.01" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="release" id="629a7e14bc9049f9" memberName="harm_releaseSlider"
          virtualName="" explicitFocusOrder="0" pos="504 31 47 48" min="0.0"
          max="2.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
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
  <LABEL name="attack_label" id="a71749398b581e7b" memberName="attack_label2"
         virtualName="" explicitFocusOrder="0" pos="416 17 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="deay_label" id="767a2e67343fe793" memberName="decay_label2"
         virtualName="" explicitFocusOrder="0" pos="447 17 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="D" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="sustain_label" id="1bb7556606d39922" memberName="sustain_label2"
         virtualName="" explicitFocusOrder="0" pos="479 17 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="S" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="release_label" id="8ecf3186e4d5c179" memberName="release_label2"
         virtualName="" explicitFocusOrder="0" pos="511 17 23 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="sustain height" id="1692b5e13f5f0d0" memberName="m_sustainHeightSlider"
          virtualName="" explicitFocusOrder="0" pos="120 144 47 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="sustain height" id="bb18dbede604ae60" memberName="harm_sustainHeightSlider"
          virtualName="" explicitFocusOrder="0" pos="472 64 47 48" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="sustainHeight_label" id="840fedbf8a4a25c2" memberName="sustainHeight_label"
         virtualName="" explicitFocusOrder="0" pos="8 160 71 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sus level:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="sustainHeight_label" id="ceb30055fdd15eff" memberName="sustainHeight_label2"
         virtualName="" explicitFocusOrder="0" pos="352 80 71 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Sus level:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="time" id="c54a23993d1f7f34" memberName="time_label" virtualName=""
         explicitFocusOrder="0" pos="8 128 55 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Time S:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="time" id="364c9c5024d1838a" memberName="time_label2" virtualName=""
         explicitFocusOrder="0" pos="360 48 55 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Time S:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

