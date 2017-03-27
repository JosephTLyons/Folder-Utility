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
    DirectoryIterator dirIter (File (getMainPathway().getFullPathName()), true, "*",
                               File::findFilesAndDirectories + File::ignoreHiddenFiles);
    
    Array<File> allFilesAndFoldersArray = returnDirIterItemsArray(dirIter);
    
    do
    {
        iterateAgain = false;
        
        for(int i = 0; (i < allFilesAndFoldersArray.size()) && (iterateAgain == false); i++)
        {
            setFileHolder(allFilesAndFoldersArray[i]);
            
            if(getFileHolder().isDirectory())
            {
                if(folderIsEmpty())
                {
                    iterateAgain = true;
                    allFilesAndFoldersArray.remove(i);
                    removeSingleEmptyFolder();
                }
            }
        }
    }
    while(iterateAgain);
    
    // Add remaining infomrmation to text string for textEditor
    addToOutputString("Completed: ");
    addToOutputString((String) numberOfFilesRemoved);
    addToOutputString(" empty folder(s) moved to trash.\n\n");
}

bool RemoveEmptyDirectories::folderIsEmpty()
{
    int numberOfChildrenFiles = getFileHolder().getNumberOfChildFiles(File::findFilesAndDirectories + File::ignoreHiddenFiles);
    // This will return true if the directory iterator can advance to a file or folder
    // If it cannot, there is no file or folder in this pathway
    if(numberOfChildrenFiles != 0)
    {
        return false;
    }
    
    return true;
}

void RemoveEmptyDirectories::removeSingleEmptyFolder()
{
    // If the folder is a read-only folder, it will never get moved and this
    // loop will infinitely loop, so this forces a breakout in that situation
    int loopCounter = 0;
    const int END_LOOP_AFTER_100_ATTEMPTS = 100;
    
    // This code is to fix the broken Apple code that doesn't always move items to trash
    // Continually try until the file doesn't exist
    for(; (loopCounter < END_LOOP_AFTER_100_ATTEMPTS) && (getFileHolder().exists()); loopCounter++)
    {
        getFileHolder().moveToTrash();
        Thread::sleep(15);
    }

    // Add filename to list of removed files
    addToOutputString((String) (numberOfFilesRemoved + 1));
    addToOutputString(": /");
    addToOutputString(getFileHolder().getRelativePathFrom(getMainPathway().getFullPathName()));
    addToOutputString("\n");

    // Increment number of files removed
    numberOfFilesRemoved++;
}

int RemoveEmptyDirectories::getNumberOfFilesRemoved()
{
    return numberOfFilesRemoved;
}

void RemoveEmptyDirectories::clearNumberOfFilesRemoved()
{
    numberOfFilesRemoved = 0;
}
