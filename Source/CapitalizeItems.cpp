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
        setFileHolder(items[i]);
        makeUpperCase();
    }
}

void CapitalizeItems::sortItems(Array<File> &items)
{
    bool iterateAndSortAgain = true;
    int countOfBackslashesInFilePathOne, countOfBackslashesInFilePathTwo;
    
    // make bubble sort to organize files by how deep the folder / item is
    // The deepest folders / items are sorted to the beginning of the array
    for(int i = 0; i < (items.size() - 1) && iterateAndSortAgain == true; i++)
    {
        countOfBackslashesInFilePathOne = countBackslashesInString(items[i].getFullPathName());
        countOfBackslashesInFilePathTwo = countBackslashesInString(items[i + 1].getFullPathName());
        
        if(countOfBackslashesInFilePathOne < countOfBackslashesInFilePathTwo)
        {
            items.swap(i, (i + 1));
            iterateAndSortAgain = true;
        }
        
        // Reset loop if a swap was made
        if((i + 1) == items.size())
        {
            if(iterateAndSortAgain == true)
            {
                i = 0;
                iterateAndSortAgain = false;
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
    
    // sort array based on size (descending)
    
    
    // then collect last file name
    // capitalize
    // Remove that item from array
    // This will let me rename the last items in an a path, then rename its parents
    // doing it in the other order will ruin the pathway to get to the children
    
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
        addToOutputString(getFileHolder().getFullPathName());
        addToOutputString(" -> ");
        addToOutputString(fullPathString);
        addToOutputString("\n\n");
    }
}
