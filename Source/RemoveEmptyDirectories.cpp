//
//  RemoveEmptyDirectories.cpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/20/17.
//
//

#include "RemoveEmptyDirectories.hpp"

RemoveEmptyDirectories::RemoveEmptyDirectories()
{
    clearNumberOfFilesRemoved();
    iterateAgain = false;
}

void RemoveEmptyDirectories::removeAllEmptyFolders()
{
    // Scans files and directories recursively, but skips hidden files
    DirectoryIterator dirIter (File (mainPathway.getFullPathName()), true, "*",
                               File::findFilesAndDirectories + File::ignoreHiddenFiles);
    
    // Iterate and collect all files and store in filesArray
    while(dirIter.next())
    {
        filesArray.add(dirIter.getFile());
    }
    
    do
    {
        iterateAgain = false;
        
        for(int i = 0; (i < filesArray.size()) && (iterateAgain == false); i++)
        {
            fileHolder = filesArray[i];
            
            if(fileHolder.isDirectory())
            {
                if(folderIsEmpty())
                {
                    iterateAgain = true;
                    filesArray.remove(i);
                    removeSingleEmptyFolder();
                }
            }
        }
    }
    while(iterateAgain);
    
    // Add remaining infomrmation to text string for textEditor
    listOfFoldersRemoved += "Completed: ";
    listOfFoldersRemoved += (String) numberOfFilesRemoved;
    listOfFoldersRemoved += " empty folder(s) moved to trash.\n\n";
}

bool RemoveEmptyDirectories::folderIsEmpty()
{
    // Scans files and directories non-recursively, but skips hidden files
    DirectoryIterator dirIter (File (fileHolder.getFullPathName()), false, "*",
                               File::findFilesAndDirectories + File::ignoreHiddenFiles);
    
    // This will return true if the directory iterator can advance to a file or folder
    // If it cannot, there is no file or folder in this pathway
    if(dirIter.next())
    {
        return false;
    }
    
    return true;
}

void RemoveEmptyDirectories::removeSingleEmptyFolder()
{
    // Move file
    //while(! fileHolder.moveToTrash());
    
    fileHolder.deleteRecursively();

    // Add filename to list of removed files
    listOfFoldersRemoved += (numberOfFilesRemoved + 1);
    listOfFoldersRemoved += ": /";
    listOfFoldersRemoved += fileHolder.getRelativePathFrom(mainPathway.getFullPathName());
    listOfFoldersRemoved += "\n\n";

    // Increment number of files removed
    numberOfFilesRemoved++;
}

void RemoveEmptyDirectories::setMainPathway(File holdsFirstPathSelected)
{
    mainPathway = holdsFirstPathSelected;
}

File RemoveEmptyDirectories::getMainPathway()
{
    return mainPathway;
}

String RemoveEmptyDirectories::getListOfFoldersRemoved()
{
    return listOfFoldersRemoved;
}

int RemoveEmptyDirectories::getNumberOfFilesRemoved()
{
    return numberOfFilesRemoved;
}

void RemoveEmptyDirectories::clearListOfFoldersRemoved()
{
    listOfFoldersRemoved.clear();
}

void RemoveEmptyDirectories::clearNumberOfFilesRemoved()
{
    numberOfFilesRemoved = 0;
}
