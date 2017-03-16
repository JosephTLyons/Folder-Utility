/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "Interface.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Interface::Interface ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (titleText = new Label ("titleText",
                                              TRANS("Eradicate Empty Folders")));
    titleText->setFont (Font (27.40f, Font::plain));
    titleText->setJustificationType (Justification::centred);
    titleText->setEditable (false, false, false);
    titleText->setColour (Label::textColourId, Colours::white);
    titleText->setColour (TextEditor::textColourId, Colours::black);
    titleText->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (selectDirectoryButton = new TextButton ("selectDirectoryselectDirectoryButton"));
    selectDirectoryButton->setButtonText (TRANS("Select Directory"));
    selectDirectoryButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    selectDirectoryButton->addListener (this);

    addAndMakeVisible (eradicateEmptyFoldersButton = new TextButton ("eradicateEmptyFoldersButton"));
    eradicateEmptyFoldersButton->setButtonText (TRANS("Eradicate Empty Folders"));
    eradicateEmptyFoldersButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    eradicateEmptyFoldersButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 150);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Interface::~Interface()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    titleText = nullptr;
    selectDirectoryButton = nullptr;
    eradicateEmptyFoldersButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Interface::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff393939));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Interface::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    titleText->setBounds (0, 0, 300, 50);
    selectDirectoryButton->setBounds (0, 50, 300, 50);
    eradicateEmptyFoldersButton->setBounds (0, 100, 300, 50);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Interface::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == selectDirectoryButton)
    {
        //[UserButtonCode_selectDirectoryButton] -- add your button handler code here..
        
        FileChooser fc ("Choose a directory...",
                        File::getCurrentWorkingDirectory(),
                        "*",
                        true);
        
        
        FileChooser fs ("stuff",
                        File::getCurrentWorkingDirectory(),
                        "dude",
                        true,
                        true
                        );
        
        fs.showDialog(1, <#juce::FilePreviewComponent *previewComponent#>)
        
        
        //[/UserButtonCode_selectDirectoryButton]
    }
    else if (buttonThatWasClicked == eradicateEmptyFoldersButton)
    {
        //[UserButtonCode_eradicateEmptyFoldersButton] -- add your button handler code here..
        //[/UserButtonCode_eradicateEmptyFoldersButton]
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

<JUCER_COMPONENT documentType="Component" className="Interface" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="4" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="300" initialHeight="150">
  <BACKGROUND backgroundColour="ff393939"/>
  <LABEL name="titleText" id="b7a12fdcde89fe51" memberName="titleText"
         virtualName="" explicitFocusOrder="0" pos="0 0 300 50" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Eradicate Empty Folders"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="27.399999999999998579" bold="0"
         italic="0" justification="36"/>
  <TEXTBUTTON name="selectDirectoryselectDirectoryButton" id="48724a493ca7e66e"
              memberName="selectDirectoryButton" virtualName="" explicitFocusOrder="0"
              pos="0 50 300 50" buttonText="Select Directory" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="eradicateEmptyFoldersButton" id="4ad96e211ef69bb7" memberName="eradicateEmptyFoldersButton"
              virtualName="" explicitFocusOrder="0" pos="0 100 300 50" buttonText="Eradicate Empty Folders"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
