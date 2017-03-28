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
    String fullPath = getFileHolder().getFullPathName();
    int positionOfFirstCharacter;
    
    // Find last part of directory
    for(int i = 0; i < fullPath.length(); i++)
    {
        // Capitalize first letter of item
        if(fullPath[i] == '/')
        {
            positionOfFirstCharacter = (++i);
            // Capitalize i + 1 here
        }
    }
    
    for(int i = positionOfFirstCharacter; i < fullPath.length(); i++)
    {
        // Capitalize spaces
        if(CharacterFunctions::isWhitespace(fullPath[i]))
        {
            fullPath[i + 1] = CharacterFunctions::toUpperCase(fullPath[i + 1]);
        }
        
        // Capitalize underscores
        if((fullPath[i]) == '_')
        {
            fullPath[i + 1] = CharacterFunctions::toUpperCase(fullPath[i + 1]);
        }
        
        // Capitalize dashes
        if((fullPath[i]) == '-')
        {
            fullPath[i + 1] = CharacterFunctions::toUpperCase(fullPath[i + 1]);
        }
    }
    
    getFileHolder().moveFileTo(fullPath);
}
