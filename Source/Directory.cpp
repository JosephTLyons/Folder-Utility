//
//  Directory.cpp
//  Empty Folder Remover
//
//  Created by Joseph Lyons on 3/20/17.
//
//

#include "Directory.hpp"

Directory::Directory()
{
    clearNumberOfFilesRemoved();
    iterateAgain = true;
}

void Directory::removeAllEmptyFolders()
{
    // Scans files and directories recursively, but skips hidden files
    DirectoryIterator dirIter (File (mainPathway.getFullPathName()), true, "*",
                               File::findFilesAndDirectories + File::ignoreHiddenFiles);
    
    // This loop repeats until folders stop being moved to trash
    // It uses a flag similar to how the bubble sort works
    while(iterateAgain)
    {
        iterateAgain = false;
        
        // Iterate through all files and directories
        while (dirIter.next())
        {
            fileHolder = dirIter.getFile();
            
            if(fileHolder.isDirectory())
            {
                if(folderIsEmpty())
                {
                    iterateAgain = true;
                    removeSingleEmptyFolder();
                }
            }
        }
    }
    
    // Set to true so that if the user clicks the remove empty folder again, this function will work
    iterateAgain = true;
    
    // Add remaining infomrmation to text string for textEditor
    listOfFoldersRemoved += "Completed: ";
    listOfFoldersRemoved += (String) numberOfFilesRemoved;
    listOfFoldersRemoved += " empty folder(s) moved to trash.\n\n";
}

void Directory::removeSingleEmptyFolder()
{
    // Move file
    fileHolder.moveToTrash();

    // Add filename to list of removed files
    listOfFoldersRemoved += (numberOfFilesRemoved + 1);
    listOfFoldersRemoved += ": ";
    listOfFoldersRemoved += fileHolder.getRelativePathFrom(mainPathway.getFullPathName());
    listOfFoldersRemoved += "\n\n";

    // Increment number of files removed
    numberOfFilesRemoved++;
}

bool Directory::folderIsEmpty()
{
    int numberOfFiles = fileHolder.getNumberOfChildFiles(File::findFilesAndDirectories +
                                                         File::ignoreHiddenFiles);
    
    if(numberOfFiles != 0)
    {
        return false;
    }
    
    return true;
}

void Directory::setMainPathway(File holdsFirstPathSelected)
{
    mainPathway = holdsFirstPathSelected;
}

File Directory::getMainPathway()
{
    return mainPathway;
}

String Directory::getListOfFoldersRemoved()
{
    return listOfFoldersRemoved;
}

int Directory::getNumberOfFilesRemoved()
{
    return numberOfFilesRemoved;
}

void Directory::clearListOfFoldersRemoved()
{
    listOfFoldersRemoved.clear();
}

void Directory::clearNumberOfFilesRemoved()
{
    numberOfFilesRemoved = 0;
}
