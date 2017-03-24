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
    DirectoryIterator dirIter (File (Base::getMainPathway().getFullPathName()), true, "*",
                               File::findFilesAndDirectories + File::ignoreHiddenFiles);
    
    Array<File> allFilesAndFoldersArray = Base::returnDirIterItemsArray(dirIter);
    
    do
    {
        iterateAgain = false;
        
        for(int i = 0; (i < allFilesAndFoldersArray.size()) && (iterateAgain == false); i++)
        {
            Base::setFileHolder(allFilesAndFoldersArray[i]);
            
            if(Base::getFileHolder().isDirectory())
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
    Base::addToOutputString("Completed: ");
    Base::addToOutputString((String) numberOfFilesRemoved);
    Base::addToOutputString(" empty folder(s) moved to trash.\n\n");
}

bool RemoveEmptyDirectories::folderIsEmpty()
{
    // Scans files and directories non-recursively, but skips hidden files
    DirectoryIterator dirIter (File (Base::getFileHolder().getFullPathName()), false, "*",
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
    // If the folder is a read-only folder, it will never get moved and this
    // loop will infinitely loop, so this forces a breakout in that situation
    int loopCounter = 0;
    const int endLoopAfterXTries = 100;
    
    // This code is to fix the broken Apple code that doesn't always move items to trash
    // Continually try until the file doesn't exist
    for(; (loopCounter < endLoopAfterXTries) && (Base::getFileHolder().exists()); loopCounter++)
    {
        Base::getFileHolder().moveToTrash();
        Thread::sleep(15);
    }
    
    // Remove when done testing
    #include <iostream>
    using namespace std;
    cout << endl << loopCounter;

    // Add filename to list of removed files
    Base::addToOutputString((String) (numberOfFilesRemoved + 1));
    Base::addToOutputString(": /");
    Base::addToOutputString(Base::getFileHolder().getRelativePathFrom(Base::getMainPathway().getFullPathName()));
    Base::addToOutputString("\n\n");

    // Increment number of files removed
    numberOfFilesRemoved++;
}

void RemoveEmptyDirectories::setMainPathway(File holdsFirstPathSelected)
{
    Base::setMainPathway(holdsFirstPathSelected);
}

File RemoveEmptyDirectories::getMainPathway()
{
    return Base::getMainPathway();
}

String RemoveEmptyDirectories::getListOfFoldersRemoved()
{
    return Base::getOutputString();
}

int RemoveEmptyDirectories::getNumberOfFilesRemoved()
{
    return numberOfFilesRemoved;
}

void RemoveEmptyDirectories::clearListOfFoldersRemoved()
{
    Base::clearOutputString();
}

void RemoveEmptyDirectories::clearNumberOfFilesRemoved()
{
    numberOfFilesRemoved = 0;
}
