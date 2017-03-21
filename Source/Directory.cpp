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
}

void Directory::removeEmptyFolders()
{
    // Scans files and directories recursively, but skips hidden files
    DirectoryIterator dirIter (File (originalPathwaySelected.getFullPathName()), true, "*",
                               File::findFilesAndDirectories + File::ignoreHiddenFiles);
    
    File fileHolder;
    
    // Iterate through all files and directories
    while (dirIter.next())
    {
        fileHolder = dirIter.getFile();
        
        if(fileHolder.isDirectory())
        {
            if(folderIsEmpty(fileHolder))
            {
                // Move file
                fileHolder.moveToTrash();
                
                // Add filename to list of removed files
                listOfFoldersRemoved += fileHolder.getFileName();
                listOfFoldersRemoved += '\n';
                
                // Increment number of files removed
                numberOfFilesRemoved++;
            }
        }
    }
    
    // Add remaining infomrmation to text string for textEditor
    listOfFoldersRemoved += "\nCompleted: ";
    listOfFoldersRemoved += (String) numberOfFilesRemoved;
    listOfFoldersRemoved += " empty folder(s) moved to trash.";
}

bool Directory::folderIsEmpty(File fileHolder)
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

void Directory::setOriginalPathWay(File holdsFirstPathPicked)
{
    originalPathwaySelected = holdsFirstPathPicked;
}

File Directory::getOriginalPathway()
{
    return originalPathwaySelected;
}

String Directory::getListOfFoldersRemoved()
{
    return listOfFoldersRemoved;
}

void Directory::clearListOfFoldersRemoved()
{
    listOfFoldersRemoved.clear();
}

void Directory::clearNumberOfFilesRemoved()
{
    numberOfFilesRemoved = 0;
}
