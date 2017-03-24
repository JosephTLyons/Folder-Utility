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
    Array<File> allFilesAndFoldersArray = Base::returnAllFilesAndFoldersArray();
    
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
    listOfFoldersRemoved += "Completed: ";
    listOfFoldersRemoved += (String) numberOfFilesRemoved;
    listOfFoldersRemoved += " empty folder(s) moved to trash.\n\n";
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
    // Move file
    //while(! fileHolder.moveToTrash());
    
    Base::getFileHolder().deleteRecursively();

    // Add filename to list of removed files
    listOfFoldersRemoved += (numberOfFilesRemoved + 1);
    listOfFoldersRemoved += ": /";
    listOfFoldersRemoved += Base::getFileHolder().getRelativePathFrom(Base::getMainPathway().getFullPathName());
    listOfFoldersRemoved += "\n\n";

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
