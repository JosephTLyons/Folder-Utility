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

#ifndef __JUCE_HEADER_156B5A0DC5E114BE__
#define __JUCE_HEADER_156B5A0DC5E114BE__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "CapitalizeItems.hpp"
#include "RemoveEmptyDirectories.hpp"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Interface  : public Component,
                   public ButtonListener
{
public:
    //==============================================================================
    Interface ();
    ~Interface();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

    RemoveEmptyDirectories removeEmptyDirectoriesObject;
    CapitalizeItems capitalizeItemsObject;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> folderUtilityLabel;
    ScopedPointer<TextButton> selectDirectoryButton;
    ScopedPointer<TextButton> removeEmptyFolders;
    ScopedPointer<TextEditor> directoryPathDisplay;
    ScopedPointer<TextEditor> listOfFoldersRemovedEditor;
    ScopedPointer<Label> summaryLabel;
    ScopedPointer<Label> directoryPathwayLabel;
    ScopedPointer<TextButton> capitalizeItemsButton;
    ScopedPointer<TextButton> filesOptionToggle;
    ScopedPointer<TextButton> foldersOptionToggle2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Interface)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_156B5A0DC5E114BE__
