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

    addAndMakeVisible (summaryLabel = new Label ("summaryLabel",
                                                 TRANS("Summary:")));
    summaryLabel->setFont (Font ("American Typewriter", 15.00f, Font::plain));
    summaryLabel->setJustificationType (Justification::centred);
    summaryLabel->setEditable (false, false, false);
    summaryLabel->setColour (Label::textColourId, Colour (0xffc6c6c6));
    summaryLabel->setColour (TextEditor::textColourId, Colours::black);
    summaryLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (folderUtilityLabel = new Label ("folderUtilityLabel",
                                                       TRANS("Folder Utility")));
    folderUtilityLabel->setFont (Font ("American Typewriter", 45.60f, Font::plain));
    folderUtilityLabel->setJustificationType (Justification::centred);
    folderUtilityLabel->setEditable (false, false, false);
    folderUtilityLabel->setColour (Label::textColourId, Colours::white);
    folderUtilityLabel->setColour (TextEditor::textColourId, Colours::black);
    folderUtilityLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (selectDirectoryButton = new TextButton ("selectDirectoryselectDirectoryButton"));
    selectDirectoryButton->setButtonText (TRANS("Select Directory"));
    selectDirectoryButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    selectDirectoryButton->addListener (this);
    selectDirectoryButton->setColour (TextButton::buttonColourId, Colour (0xff48b988));
    selectDirectoryButton->setColour (TextButton::textColourOffId, Colours::white);

    addAndMakeVisible (removeEmptyFolders = new TextButton ("removeEmptyFolders"));
    removeEmptyFolders->setButtonText (TRANS("Remove Empty Folders"));
    removeEmptyFolders->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    removeEmptyFolders->addListener (this);
    removeEmptyFolders->setColour (TextButton::buttonColourId, Colours::cornflowerblue);
    removeEmptyFolders->setColour (TextButton::textColourOffId, Colours::white);

    addAndMakeVisible (directoryPathDisplay = new TextEditor ("directoryPathDisplay"));
    directoryPathDisplay->setMultiLine (true);
    directoryPathDisplay->setReturnKeyStartsNewLine (false);
    directoryPathDisplay->setReadOnly (true);
    directoryPathDisplay->setScrollbarsShown (true);
    directoryPathDisplay->setCaretVisible (false);
    directoryPathDisplay->setPopupMenuEnabled (true);
    directoryPathDisplay->setColour (TextEditor::textColourId, Colours::white);
    directoryPathDisplay->setColour (TextEditor::backgroundColourId, Colour (0xff3e3e3e));
    directoryPathDisplay->setText (String());

    addAndMakeVisible (summaryTextEditor = new TextEditor ("summaryTextEditor"));
    summaryTextEditor->setMultiLine (true);
    summaryTextEditor->setReturnKeyStartsNewLine (false);
    summaryTextEditor->setReadOnly (true);
    summaryTextEditor->setScrollbarsShown (true);
    summaryTextEditor->setCaretVisible (false);
    summaryTextEditor->setPopupMenuEnabled (true);
    summaryTextEditor->setColour (TextEditor::textColourId, Colours::white);
    summaryTextEditor->setColour (TextEditor::backgroundColourId, Colour (0xff3e3e3e));
    summaryTextEditor->setText (String());

    addAndMakeVisible (directoryPathwayLabel = new Label ("directoryPathwayLabel",
                                                          TRANS("Directory Pathway:")));
    directoryPathwayLabel->setFont (Font ("American Typewriter", 15.00f, Font::plain));
    directoryPathwayLabel->setJustificationType (Justification::centred);
    directoryPathwayLabel->setEditable (false, false, false);
    directoryPathwayLabel->setColour (Label::textColourId, Colour (0xffc6c6c6));
    directoryPathwayLabel->setColour (TextEditor::textColourId, Colours::black);
    directoryPathwayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (capitalizeItemsButton = new TextButton ("capitalizeItemsButton"));
    capitalizeItemsButton->setButtonText (TRANS("Capitilize Items"));
    capitalizeItemsButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    capitalizeItemsButton->addListener (this);
    capitalizeItemsButton->setColour (TextButton::buttonColourId, Colours::cornflowerblue);
    capitalizeItemsButton->setColour (TextButton::textColourOffId, Colours::white);

    addAndMakeVisible (filesOptionToggle = new TextButton ("filesOptionToggle"));
    filesOptionToggle->setButtonText (TRANS("Files"));
    filesOptionToggle->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    filesOptionToggle->addListener (this);
    filesOptionToggle->setColour (TextButton::textColourOnId, Colours::grey);

    addAndMakeVisible (foldersOptionToggle2 = new TextButton ("foldersOptionToggle2"));
    foldersOptionToggle2->setButtonText (TRANS("Folders"));
    foldersOptionToggle2->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    foldersOptionToggle2->addListener (this);
    foldersOptionToggle2->setColour (TextButton::textColourOnId, Colours::grey);

    addAndMakeVisible (listAllFiles = new TextButton ("listAllFiles"));
    listAllFiles->setButtonText (TRANS("List All Files"));
    listAllFiles->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    listAllFiles->addListener (this);
    listAllFiles->setColour (TextButton::buttonColourId, Colours::cornflowerblue);
    listAllFiles->setColour (TextButton::textColourOffId, Colours::white);

    addAndMakeVisible (unlockButton = new TextButton ("unlockButton"));
    unlockButton->setButtonText (TRANS("Unlock"));
    unlockButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    unlockButton->addListener (this);
    unlockButton->setColour (TextButton::buttonColourId, Colour (0xffe86565));

    addAndMakeVisible (stripCharactersButton = new TextButton ("stripCharactersButton"));
    stripCharactersButton->setButtonText (TRANS("Strip Characters"));
    stripCharactersButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    stripCharactersButton->addListener (this);
    stripCharactersButton->setColour (TextButton::buttonColourId, Colours::cornflowerblue);
    stripCharactersButton->setColour (TextButton::textColourOffId, Colours::white);

    addAndMakeVisible (stripUnderscoreToggle = new TextButton ("stripUnderscoreToggle"));
    stripUnderscoreToggle->setButtonText (TRANS("\"_\""));
    stripUnderscoreToggle->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    stripUnderscoreToggle->addListener (this);
    stripUnderscoreToggle->setColour (TextButton::textColourOnId, Colours::grey);

    addAndMakeVisible (stripHyphenToggle = new TextButton ("stripHyphenToggle"));
    stripHyphenToggle->setButtonText (TRANS("\"-\""));
    stripHyphenToggle->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    stripHyphenToggle->addListener (this);
    stripHyphenToggle->setColour (TextButton::textColourOnId, Colours::grey);

    addAndMakeVisible (fontSizeSlider = new Slider ("fontSizeSlider"));
    fontSizeSlider->setRange (10, 50, 1);
    fontSizeSlider->setSliderStyle (Slider::LinearHorizontal);
    fontSizeSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 25, 20);
    fontSizeSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff3e3e3e));
    fontSizeSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    fontSizeSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xff3e3e3e));
    fontSizeSlider->setColour (Slider::textBoxOutlineColourId, Colour (0xff3e3e3e));
    fontSizeSlider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 550);


    //[Constructor] You can add your own custom stuff here..

    // These buttons are off until path is set
    enableAllButtons(false, false);

    // Set these buttons to be toggle switches
    filesOptionToggle->setClickingTogglesState(true);
    foldersOptionToggle2->setClickingTogglesState(true);
    stripUnderscoreToggle->setClickingTogglesState(true);
    stripHyphenToggle->setClickingTogglesState(true);

    //[/Constructor]
}

Interface::~Interface()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    summaryLabel = nullptr;
    folderUtilityLabel = nullptr;
    selectDirectoryButton = nullptr;
    removeEmptyFolders = nullptr;
    directoryPathDisplay = nullptr;
    summaryTextEditor = nullptr;
    directoryPathwayLabel = nullptr;
    capitalizeItemsButton = nullptr;
    filesOptionToggle = nullptr;
    foldersOptionToggle2 = nullptr;
    listAllFiles = nullptr;
    unlockButton = nullptr;
    stripCharactersButton = nullptr;
    stripUnderscoreToggle = nullptr;
    stripHyphenToggle = nullptr;
    fontSizeSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Interface::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff3e3e3e));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Interface::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    summaryLabel->setBounds (0, 275, 400, 25);
    folderUtilityLabel->setBounds (0, 0, 400, 50);
    selectDirectoryButton->setBounds (0, 125, 400, 25);
    removeEmptyFolders->setBounds (0, 200, 400, 25);
    directoryPathDisplay->setBounds (0, 75, 400, 50);
    summaryTextEditor->setBounds (0, 300, 400, 250);
    directoryPathwayLabel->setBounds (0, 50, 400, 25);
    capitalizeItemsButton->setBounds (200, 225, 200, 25);
    filesOptionToggle->setBounds (0, 225, 100, 25);
    foldersOptionToggle2->setBounds (100, 225, 100, 25);
    listAllFiles->setBounds (0, 150, 400, 25);
    unlockButton->setBounds (0, 175, 400, 25);
    stripCharactersButton->setBounds (200, 250, 200, 25);
    stripUnderscoreToggle->setBounds (0, 250, 100, 25);
    stripHyphenToggle->setBounds (100, 250, 100, 25);
    fontSizeSlider->setBounds (0, 275, 150, 25);
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

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == selectDirectoryButton)
    {
        //[UserButtonCode_selectDirectoryButton] -- add your button handler code here..

        // Launch browser window and only if they pick a directory, do we enable other buttons
        if(fileChooser.browseForDirectory())
        {
            // Enable buttons (are off until a path is set to keep from bad things from happening
            // IE Directory Iterator trying to iterate when no path has been set
            enableAllButtons(true, false);
        }

        // set directoryPath
        directoryPath = fileChooser.getResult();

        // Display path in text editor (Consider refactoring names in this code)
        directoryPathDisplay->setText(directoryPath.getFullPathName());

        // Assign path chosen to my class' path holders
        removeEmptyDirectoriesObject.setMainPathway(directoryPath);
        capitalizeItemsObject.setMainPathway(directoryPath);
        analyzeFilesObject.setMainPathway(directoryPath);
        // set path to all other function classes as well

        //[/UserButtonCode_selectDirectoryButton]
    }
    else if (buttonThatWasClicked == removeEmptyFolders)
    {
        //[UserButtonCode_removeEmptyFolders] -- add your button handler code here..

        // Commence Action
        removeEmptyDirectoriesObject.removeAllEmptyFolders();

        // Set summary string to text editor
        outputSummaryString = removeEmptyDirectoriesObject.getOutputString();
        summaryTextEditor->setText(outputSummaryString);

        // Reset summary fields
        clearSummaryItems();

        // Disengage buttons again
        enableAllButtons(true, false);

        //[/UserButtonCode_removeEmptyFolders]
    }
    else if (buttonThatWasClicked == capitalizeItemsButton)
    {
        //[UserButtonCode_capitalizeItemsButton] -- add your button handler code here..

        // Commence Action
        capitalizeItemsObject.capitalizeItemsDriver(filesOptionToggle->getToggleState() ,
                                                    foldersOptionToggle2->getToggleState());

        // Set summary string to text editor
        outputSummaryString = capitalizeItemsObject.getOutputString();
        summaryTextEditor->setText(outputSummaryString);

        // Reset summary fields
        clearSummaryItems();

        // Disengage buttons again
        enableAllButtons(true, false);

        //[/UserButtonCode_capitalizeItemsButton]
    }
    else if (buttonThatWasClicked == filesOptionToggle)
    {
        //[UserButtonCode_filesOptionToggle] -- add your button handler code here..
        //[/UserButtonCode_filesOptionToggle]
    }
    else if (buttonThatWasClicked == foldersOptionToggle2)
    {
        //[UserButtonCode_foldersOptionToggle2] -- add your button handler code here..
        //[/UserButtonCode_foldersOptionToggle2]
    }
    else if (buttonThatWasClicked == listAllFiles)
    {
        //[UserButtonCode_listAllFiles] -- add your button handler code here..

        // Commence Action
        analyzeFilesObject.collectFilenames();

        // Set summary string to text editor
        outputSummaryString = analyzeFilesObject.getOutputString();
        summaryTextEditor->setText(outputSummaryString);

        // Reset summary fields
        clearSummaryItems();

        // Disengage buttons again
        enableAllButtons(true, false);

        //[/UserButtonCode_listAllFiles]
    }
    else if (buttonThatWasClicked == unlockButton)
    {
        //[UserButtonCode_unlockButton] -- add your button handler code here..

        enableAllButtons(true, true);

        //[/UserButtonCode_unlockButton]
    }
    else if (buttonThatWasClicked == stripCharactersButton)
    {
        //[UserButtonCode_stripCharactersButton] -- add your button handler code here..
        //[/UserButtonCode_stripCharactersButton]
    }
    else if (buttonThatWasClicked == stripUnderscoreToggle)
    {
        //[UserButtonCode_stripUnderscoreToggle] -- add your button handler code here..
        //[/UserButtonCode_stripUnderscoreToggle]
    }
    else if (buttonThatWasClicked == stripHyphenToggle)
    {
        //[UserButtonCode_stripHyphenToggle] -- add your button handler code here..
        //[/UserButtonCode_stripHyphenToggle]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void Interface::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == fontSizeSlider)
    {
        //[UserSliderCode_fontSizeSlider] -- add your slider handling code here..
        
        int fontHeight;
        
        Font summaryOutputFont;
        
        fontHeight = fontSizeSlider->getValue();
        
        summaryTextEditor->clear();
        
        summaryOutputFont.setHeight(fontHeight);
        
        summaryTextEditor->setFont(summaryOutputFont);
        
        summaryTextEditor->setText(outputSummaryString);
        
        //[/UserSliderCode_fontSizeSlider]
    }

    //[UsersliderValueChanged_Post]

    
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void Interface::enableAllButtons(const bool &enableSafeItems, const bool&enableDangerousItems)
{
    //Safe items
    listAllFiles->setEnabled(enableSafeItems);
    unlockButton->setEnabled(enableSafeItems);

    // Dangerous items
    removeEmptyFolders->setEnabled(enableDangerousItems);

    filesOptionToggle->setEnabled(enableDangerousItems);
    foldersOptionToggle2->setEnabled(enableDangerousItems);
    capitalizeItemsButton->setEnabled(enableDangerousItems);

    stripUnderscoreToggle->setEnabled(enableDangerousItems);
    stripHyphenToggle->setEnabled(enableDangerousItems);
    stripCharactersButton->setEnabled(enableDangerousItems);

}

void Interface::clearSummaryItems()
{
    // Items for removing empty directories
    removeEmptyDirectoriesObject.clearOutputString();
    removeEmptyDirectoriesObject.clearNumberOfFilesRemoved();

    // Items for capitalization
    capitalizeItemsObject.clearOutputString();

    // Items for analyze files
    analyzeFilesObject.clearOutputString();
}

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
                 fixedSize="1" initialWidth="400" initialHeight="550">
  <BACKGROUND backgroundColour="ff3e3e3e"/>
  <LABEL name="summaryLabel" id="66a66b2dca7d8008" memberName="summaryLabel"
         virtualName="" explicitFocusOrder="0" pos="0 275 400 25" textCol="ffc6c6c6"
         edTextCol="ff000000" edBkgCol="0" labelText="Summary:" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="American Typewriter"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="folderUtilityLabel" id="b7a12fdcde89fe51" memberName="folderUtilityLabel"
         virtualName="" explicitFocusOrder="0" pos="0 0 400 50" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Folder Utility"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="American Typewriter" fontsize="45.600000000000001421"
         bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="selectDirectoryselectDirectoryButton" id="48724a493ca7e66e"
              memberName="selectDirectoryButton" virtualName="" explicitFocusOrder="0"
              pos="0 125 400 25" bgColOff="ff48b988" textCol="ffffffff" buttonText="Select Directory"
              connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="removeEmptyFolders" id="4ad96e211ef69bb7" memberName="removeEmptyFolders"
              virtualName="" explicitFocusOrder="0" pos="0 200 400 25" bgColOff="ff6495ed"
              textCol="ffffffff" buttonText="Remove Empty Folders" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="directoryPathDisplay" id="1fdfeaa5b403b983" memberName="directoryPathDisplay"
              virtualName="" explicitFocusOrder="0" pos="0 75 400 50" textcol="ffffffff"
              bkgcol="ff3e3e3e" initialText="" multiline="1" retKeyStartsLine="0"
              readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <TEXTEDITOR name="summaryTextEditor" id="e96280133f57cb22" memberName="summaryTextEditor"
              virtualName="" explicitFocusOrder="0" pos="0 300 400 250" textcol="ffffffff"
              bkgcol="ff3e3e3e" initialText="" multiline="1" retKeyStartsLine="0"
              readonly="1" scrollbars="1" caret="0" popupmenu="1"/>
  <LABEL name="directoryPathwayLabel" id="1b6b6d72a7200e14" memberName="directoryPathwayLabel"
         virtualName="" explicitFocusOrder="0" pos="0 50 400 25" textCol="ffc6c6c6"
         edTextCol="ff000000" edBkgCol="0" labelText="Directory Pathway:"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="American Typewriter" fontsize="15" bold="0" italic="0"
         justification="36"/>
  <TEXTBUTTON name="capitalizeItemsButton" id="bd92522c60a73c65" memberName="capitalizeItemsButton"
              virtualName="" explicitFocusOrder="0" pos="200 225 200 25" bgColOff="ff6495ed"
              textCol="ffffffff" buttonText="Capitilize Items" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="filesOptionToggle" id="631d75a04a9c0263" memberName="filesOptionToggle"
              virtualName="" explicitFocusOrder="0" pos="0 225 100 25" textColOn="ff808080"
              buttonText="Files" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="foldersOptionToggle2" id="812321b70b3732b6" memberName="foldersOptionToggle2"
              virtualName="" explicitFocusOrder="0" pos="100 225 100 25" textColOn="ff808080"
              buttonText="Folders" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="listAllFiles" id="97829cf1ebb3f6d2" memberName="listAllFiles"
              virtualName="" explicitFocusOrder="0" pos="0 150 400 25" bgColOff="ff6495ed"
              textCol="ffffffff" buttonText="List All Files" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="unlockButton" id="915f32148b22746d" memberName="unlockButton"
              virtualName="" explicitFocusOrder="0" pos="0 175 400 25" bgColOff="ffe86565"
              buttonText="Unlock" connectedEdges="3" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="stripCharactersButton" id="783c96e8cb55d851" memberName="stripCharactersButton"
              virtualName="" explicitFocusOrder="0" pos="200 250 200 25" bgColOff="ff6495ed"
              textCol="ffffffff" buttonText="Strip Characters" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="stripUnderscoreToggle" id="2010abe8c28768f6" memberName="stripUnderscoreToggle"
              virtualName="" explicitFocusOrder="0" pos="0 250 100 25" textColOn="ff808080"
              buttonText="&quot;_&quot;" connectedEdges="3" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="stripHyphenToggle" id="3363f687a46e387d" memberName="stripHyphenToggle"
              virtualName="" explicitFocusOrder="0" pos="100 250 100 25" textColOn="ff808080"
              buttonText="&quot;-&quot;" connectedEdges="3" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="fontSizeSlider" id="1f64f0f2eb3a57f3" memberName="fontSizeSlider"
          virtualName="" explicitFocusOrder="0" pos="0 275 150 25" rotaryslideroutline="ff3e3e3e"
          textboxtext="ffffffff" textboxbkgd="ff3e3e3e" textboxoutline="ff3e3e3e"
          min="10" max="50" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="25" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
