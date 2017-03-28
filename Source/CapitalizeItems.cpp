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
    Array<juce_wchar> stringOfCharToCapitalize;
    Array<juce_wchar> fileNameArray;
    String fullPath = getFileHolder().getFullPathName();
    int positionOfFirstCharacter;
    
    for(int i = 0; i < fullPath.length(); i++)
    {
        fileNameArray.add(fullPath[i]);
    }
    
    // Find last part of directory
    for(int i = 0; i < fileNameArray.size(); i++)
    {
        // Capitalize first letter of item
        if(fileNameArray[i] == '/')
        {
            positionOfFirstCharacter = (i);
        }
    }
    
    // Capitalize i + 1 here
    fileNameArray.set(positionOfFirstCharacter + 1,
                     CharacterFunctions::toUpperCase(fileNameArray[positionOfFirstCharacter + 1]));
    
    for(int i = positionOfFirstCharacter; i < fileNameArray.size(); i++)
    {
        // Capitalize after spaces
        if(CharacterFunctions::isWhitespace(fileNameArray[i]))
        {
            fileNameArray.set(i + 1, CharacterFunctions::toUpperCase(fileNameArray[i + 1]));
        }
        
        // Capitalize after underscores
        if((fullPath[i]) == '_')
        {
            fileNameArray.set(i + 1, CharacterFunctions::toUpperCase(fileNameArray[i + 1]));
        }
        
        // Capitalize after dashes
        if((fullPath[i]) == '-')
        {
            fileNameArray.set(i + 1, CharacterFunctions::toUpperCase(fileNameArray[i + 1]));
        }
    }
    
    fullPath.clear();
    
    for(int i = 0; i < fileNameArray.size(); i++)
    {
        fullPath += fileNameArray[i];
    }
    
    getFileHolder().moveFileTo(fullPath);
}
