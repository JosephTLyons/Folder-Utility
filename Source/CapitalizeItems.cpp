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
    fullPathString  = getFileHolder().getFullPathName();
    changeOccured = false;
    
    copyStringToArray();
    findLastBackslashInPath();
    capitalizeFirstLetterInPath();
    capitalizeOtherOccurances();
    fullPathString.clear();
    copyArrayBackToString();
    outputChangesToSummary();
    
    // move will actually rename the file if its in the same location
    getFileHolder().moveFileTo(fullPathString);
}

void CapitalizeItems::copyStringToArray()
{
    for(int i = 0; i < fullPathString.length(); i++)
    {
        fullPathArray.add(fullPathString[i]);
    }
}

void CapitalizeItems::findLastBackslashInPath()
{
    // Find last part of directory
    for(int i = 0; i < fullPathArray.size(); i++)
    {
        // Capitalize first letter of item
        if(fullPathArray[i] == '/')
        {
            positionOfFirstCharacter = (i);
        }
    }
}

void CapitalizeItems::capitalizeFirstLetterInPath()
{
    // Capitalize first letter after last '/'
    if(CharacterFunctions::isLowerCase(fullPathArray[positionOfFirstCharacter + 1]))
    {
        fullPathArray.set(positionOfFirstCharacter + 1,
                          CharacterFunctions::toUpperCase(fullPathArray[positionOfFirstCharacter + 1]));
        
        changeOccured = true;
    }
}

void CapitalizeItems::capitalizeOtherOccurances()
{
    for(int i = positionOfFirstCharacter; i < fullPathArray.size(); i++)
    {
        // Capitalize after spaces
        if(CharacterFunctions::isWhitespace(fullPathArray[i]))
        {
            capitalizeLetter(i);
        }
        
        // Capitalize after underscores
        if((fullPathString[i]) == '_')
        {
            capitalizeLetter(i);
        }
        
        // Capitalize after dashes
        if((fullPathString[i]) == '-')
        {
            capitalizeLetter(i);
        }
    }
}

void CapitalizeItems::capitalizeLetter(const int &position)
{
    fullPathArray.set(position + 1, CharacterFunctions::toUpperCase(fullPathArray[position + 1]));
    changeOccured = true;
}

void CapitalizeItems::copyArrayBackToString()
{
    // Copy from array over to string
    for(int i = 0; i < fullPathArray.size(); i++)
    {
        fullPathString += fullPathArray[i];
    }
}

void CapitalizeItems::outputChangesToSummary()
{
    if(changeOccured)
    {
        addToOutputString(getFileHolder().getFileName());
        addToOutputString(" -> ");
        addToOutputString(fullPathString);
        addToOutputString("\n\n");
    }
}
