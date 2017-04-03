//
//  CapitalizeItems.cpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/23/17.
//
//

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
    sortItems(items);
    
    for(int i = 0; i < items.size(); i++)
    {
        isFolder = items[i].isDirectory();
        setFileHolder(items[i]);
        makeUpperCase();
        items.remove(i);
    }
}

void CapitalizeItems::sortItems(Array<File> &items)
{
    bool sortAgain = true;  // set flag to true to start first pass
    int countOfBackslashesInFilePathOne, countOfBackslashesInFilePathTwo;
    int itemsSize = items.size();
    
    // Make bubble sort to organize files by how deep the folder / item is
    // The deepest folders / items are sorted to the beginning of the array
    while(sortAgain)
    {
        sortAgain = false;
        
        for (int i = 0; i < itemsSize - 1; i++)
        {
            countOfBackslashesInFilePathOne = countBackslashesInString(items[i].getFullPathName());
            countOfBackslashesInFilePathTwo = countBackslashesInString(items[i + 1].getFullPathName());
            
            if (countOfBackslashesInFilePathOne < countOfBackslashesInFilePathTwo)
            {
                items.swap(i, (i + 1));
                
                sortAgain = true;             // indicates that a swap occurred.
            }
        }
    }
}

int CapitalizeItems::countBackslashesInString(const String &directoryPath)
{
    int count = 0;
    
    for(int i = 0; i < directoryPath.length(); i++)
    {
        if(directoryPath[i] == '/')
        {
            count++;
        }
    }
    
    return count;
}

void CapitalizeItems::makeUpperCase()
{
    fullPathString  = getFileHolder().getFullPathName();
    changeOccured   = false;
    
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
    int i = fullPathString.length();
    
    // If this is a directory, the last character will automatically be a '/'
    // So we need to move past this one to keep it from tripping up the algorithm
    if(isFolder)
    {
        i--;
    }
    
    // Find last part of directory
    for(; i >= 0; i--)
    {
        // Capitalize first letter of item
        if(fullPathArray[i] == '/')
        {
            positionOfFirstCharacter = i;
            return;
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
        addToOutputString(getFileHolder().getFullPathName());
        addToOutputString(" -> ");
        addToOutputString(fullPathString);
        addToOutputString("\n\n");
    }
}
