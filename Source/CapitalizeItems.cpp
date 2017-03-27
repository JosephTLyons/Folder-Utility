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
    String fullPath = getFileHolder().getFullPathName();
    int positionOfBackSlash;
    
    for(int i = 0; i < fullPath.length(); i++)
    {
        if(fullPath[i] == '/')
        {
            positionOfBackSlash = i;
        }
    }
    
    //fullPath[positionOfBackSlash + 1] = (fullPath[positionOfBackSlash + 1]);
    
    
    // Algorithm to identify letters to make uppercase
    // -first occuring character, every chareacter after a space
    
    // rebuild the name of the item here
    
    getFileHolder().moveFileTo(fullPath);
}
