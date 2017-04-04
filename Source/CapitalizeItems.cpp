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
    int itemsSize = items.size();
    
    sortItems(items);
    
    for(int i = 0; i < itemsSize; i++)
    {
        setFileHolder(items[i]);
        makeUpperCase();
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
    int directoryPathLength = directoryPath.length();
    
    for(int i = 0; i < directoryPathLength; i++)
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
    changeOccured         = false;
    fileNameString        = getFileHolder().getFileName();
    parentDirectoryFile   = getFileHolder().getParentDirectory();
    parentDirectoryString = parentDirectoryFile.getFullPathName();
    
    copyStringToArray();
    capitalizeFirstLetterInPath();
    capitalizeOtherOccurances();
    fileNameString.clear();
    copyArrayBackToString();
    fileNameArray.clear();
    
    // Rebuild full path
    parentDirectoryString += '/';
    parentDirectoryString += fileNameString;
    outputChangesToSummary();
    
    // Move will actually rename the file if its in the same location
    // Much like renaming in shell with mv
    getFileHolder().moveFileTo(parentDirectoryString);
}

void CapitalizeItems::copyStringToArray()
{
    int fileNameStringLenght = fileNameString.length();
    
    for(int i = 0; i < fileNameStringLenght; i++)
    {
        fileNameArray.add(fileNameString[i]);
    }
}

void CapitalizeItems::capitalizeFirstLetterInPath()
{
    if(CharacterFunctions::isLowerCase(fileNameArray[0]))
    {
        fileNameArray.set(0, CharacterFunctions::toUpperCase(fileNameArray[0]));
        
        changeOccured = true;
    }
}

void CapitalizeItems::capitalizeOtherOccurances()
{
    int fileNameArraySize = fileNameArray.size();
    
    for(int i = 0; i < fileNameArraySize; i++)
    {
        // Capitalize after spaces
        if(CharacterFunctions::isWhitespace(fileNameArray[i]))
        {
            capitalizeLetter(i);
        }
        
        // Capitalize after underscores
        if((fileNameArray[i]) == '_')
        {
            capitalizeLetter(i);
        }
        
        // Capitalize after dashes
        if((fileNameArray[i]) == '-')
        {
            capitalizeLetter(i);
        }
    }
}

void CapitalizeItems::capitalizeLetter(const int &position)
{
    fileNameArray.set(position + 1, CharacterFunctions::toUpperCase(fileNameArray[position + 1]));
    changeOccured = true;
}

void CapitalizeItems::copyArrayBackToString()
{
    int fileNameArraySize = fileNameArray.size();
    
    // Copy from array over to string
    for(int i = 0; i < fileNameArraySize; i++)
    {
        fileNameString += fileNameArray[i];
    }
}

void CapitalizeItems::outputChangesToSummary()
{
    if(changeOccured)
    {
        addToOutputString(getFileHolder().getFullPathName());
        addToOutputString(" -> ");
        addToOutputString(fileNameString);
        addToOutputString("\n\n");
    }
}
