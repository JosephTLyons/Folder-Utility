//
//  CapitalizeItems.cpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/23/17.
//
//

#include <ctype.h> // For touppper function
#include "CapitalizeItems.hpp"

void CapitalizeItems::capitalizeItemsDriver(const bool &files, const bool &folders)
{
    // Only execute function if either or is selected
    if (files || folders)
    {
        // Call function here and pass correct iter into it
        if(files && folders)
        {
            DirectoryIterator dirIterFilesAndFolders (File (getMainPathway().getFullPathName()),
                                                      true, "*",
                                                      File::findFilesAndDirectories +
                                                      File::ignoreHiddenFiles);
            
            Array<File> allFilesAndFoldersArray = returnDirIterItemsArray(dirIterFilesAndFolders);
            
            capitalizeItems(allFilesAndFoldersArray);
        }
        
        else if(files)
        {
            DirectoryIterator dirIterFiles (File (getMainPathway().getFullPathName()), true, "*",
                                            File::findFiles + File::ignoreHiddenFiles);
            
            Array<File> allFilesArray = returnDirIterItemsArray(dirIterFiles);
            
            capitalizeItems(allFilesArray);
        }
        
        // Folders
        else
        {
            DirectoryIterator dirIterFolders (File (getMainPathway().getFullPathName()), true, "*",
                                              File::findDirectories + File::ignoreHiddenFiles);
            
            Array<File> allFoldersArray = returnDirIterItemsArray(dirIterFolders);
            
            capitalizeItems(allFoldersArray);
        }
    }
}

void CapitalizeItems::capitalizeItems(Array<File> &items)
{
    for(int i = 0; i < items.size(); i++)
    {
        setFileHolder(items[i]);
        makeUpperCase();
    }
}

void CapitalizeItems::makeUpperCase()
{
    Array<juce_wchar> fullPathArray;
    String fullPathString = getFileHolder().getFullPathName();
    int positionOfFirstCharacter;
    bool didAChangeOccur = false;
    
    for(int i = 0; i < fullPathString.length(); i++)
    {
        fullPathArray.add(fullPathString[i]);
    }
    
    // Find last part of directory
    for(int i = 0; i < fullPathArray.size(); i++)
    {
        // Capitalize first letter of item
        if(fullPathArray[i] == '/')
        {
            positionOfFirstCharacter = (i);
        }
    }
    
    // Capitalize first letter after last '/'
    if(CharacterFunctions::isLowerCase(fullPathArray[positionOfFirstCharacter + 1]))
    {
        fullPathArray.set(positionOfFirstCharacter + 1,
                          CharacterFunctions::toUpperCase(fullPathArray[positionOfFirstCharacter + 1]));
        
        didAChangeOccur = true;
    }
    
    for(int i = positionOfFirstCharacter; i < fullPathArray.size(); i++)
    {
        // Capitalize after spaces
        if(CharacterFunctions::isWhitespace(fullPathArray[i]))
        {
            fullPathArray.set(i + 1, CharacterFunctions::toUpperCase(fullPathArray[i + 1]));
            
            didAChangeOccur = true;
        }
        
        // Capitalize after underscores
        if((fullPathString[i]) == '_')
        {
            fullPathArray.set(i + 1, CharacterFunctions::toUpperCase(fullPathArray[i + 1]));
            
            didAChangeOccur = true;
        }
        
        // Capitalize after dashes
        if((fullPathString[i]) == '-')
        {
            fullPathArray.set(i + 1, CharacterFunctions::toUpperCase(fullPathArray[i + 1]));
            
            didAChangeOccur = true;
        }
    }
    
    fullPathString.clear();
    
    // Copy from array over to string
    for(int i = 0; i < fullPathArray.size(); i++)
    {
        fullPathString += fullPathArray[i];
    }
    
    addToOutputString(getFileHolder().getFileName());
    addToOutputString(" -> ");
    addToOutputString(fullPathString);
    addToOutputString("\n\n");
    
    // move will actually rename the file if its in the same location
    getFileHolder().moveFileTo(fullPathString);
}
