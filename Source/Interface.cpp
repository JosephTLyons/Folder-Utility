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

#include "Directory.hpp"

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

    addAndMakeVisible (directoryPathDisplay = new TextEditor ("directoryPathDisplay"));
    directoryPathDisplay->setMultiLine (true);
    directoryPathDisplay->setReturnKeyStartsNewLine (false);
    directoryPathDisplay->setReadOnly (true);
    directoryPathDisplay->setScrollbarsShown (true);
    directoryPathDisplay->setCaretVisible (false);
    directoryPathDisplay->setPopupMenuEnabled (true);
    directoryPathDisplay->setText (String());

    addAndMakeVisible (listOfFoldersRemovedEditor = new TextEditor ("listOfFoldersRemovedEditor"));
    listOfFoldersRemovedEditor->setMultiLine (true);
    listOfFoldersRemovedEditor->setReturnKeyStartsNewLine (false);
    listOfFoldersRemovedEditor->setReadOnly (true);
    listOfFoldersRemovedEditor->setScrollbarsShown (true);
    listOfFoldersRemovedEditor->setCaretVisible (false);
    listOfFoldersRemovedEditor->setPopupMenuEnabled (true);
    listOfFoldersRemovedEditor->setText (String());

    addAndMakeVisible (foldersRemovedLabel = new Label ("foldersRemovedLabel",
                                                        TRANS("Folders Removed:")));
    foldersRemovedLabel->setFont (Font (15.00f, Font::plain));
    foldersRemovedLabel->setJustificationType (Justification::centred);
    foldersRemovedLabel->setEditable (false, false, false);
    foldersRemovedLabel->setColour (Label::textColourId, Colours::white);
    foldersRemovedLabel->setColour (TextEditor::textColourId, Colours::black);
    foldersRemovedLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (directoryPathwayLabel = new Label ("directoryPathwayLabel",
                                                          TRANS("Directory Pathway:")));
    directoryPathwayLabel->setFont (Font (15.00f, Font::plain));
    directoryPathwayLabel->setJustificationType (Justification::centred);
    directoryPathwayLabel->setEditable (false, false, false);
    directoryPathwayLabel->setColour (Label::textColourId, Colours::white);
    directoryPathwayLabel->setColour (TextEditor::textColourId, Colours::black);
    directoryPathwayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 400);


    //[Constructor] You can add your own custom stuff here..

    // Button is off until path is set
    eradicateEmptyFoldersButton->setEnabled(false);

    //[/Constructor]
}

Interface::~Interface()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    titleText = nullptr;
    selectDirectoryButton = nullptr;
    eradicateEmptyFoldersButton = nullptr;
    directoryPathDisplay = nullptr;
    listOfFoldersRemovedEditor = nullptr;
    foldersRemovedLabel = nullptr;
    directoryPathwayLabel = nullptr;


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

    titleText->setBounds (0, 0, 400, 50);
    selectDirectoryButton->setBounds (0, 125, 400, 50);
    eradicateEmptyFoldersButton->setBounds (0, 175, 400, 50);
    directoryPathDisplay->setBounds (0, 75, 400, 50);
    listOfFoldersRemovedEditor->setBounds (0, 250, 400, 150);
    foldersRemovedLabel->setBounds (0, 225, 400, 25);
    directoryPathwayLabel->setBounds (0, 50, 400, 25);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Interface::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

    FileChooser fileChooser ("Choose a directory...",
                             File::getCurrentWorkingDirectory(),
                             "*",
                             true);

    // Enable button (its off until a path is set to keep from bad things from happening
    // IE Directory Iterator trying to iterate when no path has been set
    eradicateEmptyFoldersButton->setEnabled(true);

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == selectDirectoryButton)
    {
        //[UserButtonCode_selectDirectoryButton] -- add your button handler code here..

        // Launch browser window
        fileChooser.browseForDirectory();

        // Assign path chosen to my class' path holder
        directory.setMainPathway(fileChooser.getResult());

        // Display path in text editor (Consider refactoring names in this code)
        directoryPathDisplay->setText(directory.getMainPathway().getFullPathName());

        //[/UserButtonCode_selectDirectoryButton]
    }
    else if (buttonThatWasClicked == eradicateEmptyFoldersButton)
    {
        //[UserButtonCode_eradicateEmptyFoldersButton] -- add your button handler code here..

        // Reset history fields
        listOfFoldersRemovedEditor->clear();
        directory.clearNumberOfFilesRemoved();

        directory.removeEmptyFolders();

        // Set history string to text editor
        listOfFoldersRemovedEditor->setText(directory.getListOfFoldersRemoved());

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
                 fixedSize="1" initialWidth="400" initialHeight="400">
  <BACKGROUND backgroundColour="ff393939"/>
  <LABEL name="titleText" id="b7a12fdcde89fe51" memberName="titleText"
         virtualName="" explicitFocusOrder="0" pos="0 0 400 50" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Eradicate Empty Folders"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="27.399999999999998579" bold="0"
         italic="0" justification="36"/>
  <TEXTBUTTON name="selectDirectoryselectDirectoryButton" id="48724a493ca7e66e"
              memberName="selectDirectoryButton" virtualName="" explicitFocusOrder="0"
              pos="0 125 400 50" buttonText="Select Directory" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="eradicateEmptyFoldersButton" id="4ad96e211ef69bb7" memberName="eradicateEmptyFoldersButton"
              virtualName="" explicitFocusOrder="0" pos="0 175 400 50" buttonText="Eradicate Empty Folders"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="directoryPathDisplay" id="1fdfeaa5b403b983" memberName="directoryPathDisplay"
              virtualName="" explicitFocusOrder="0" pos="0 75 400 50" initialText=""
              multiline="1" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <TEXTEDITOR name="listOfFoldersRemovedEditor" id="e96280133f57cb22" memberName="listOfFoldersRemovedEditor"
              virtualName="" explicitFocusOrder="0" pos="0 250 400 150" initialText=""
              multiline="1" retKeyStartsLine="0" readonly="1" scrollbars="1"
              caret="0" popupmenu="1"/>
  <LABEL name="foldersRemovedLabel" id="66a66b2dca7d8008" memberName="foldersRemovedLabel"
         virtualName="" explicitFocusOrder="0" pos="0 225 400 25" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Folders Removed:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="directoryPathwayLabel" id="1b6b6d72a7200e14" memberName="directoryPathwayLabel"
         virtualName="" explicitFocusOrder="0" pos="0 50 400 25" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Directory Pathway:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
