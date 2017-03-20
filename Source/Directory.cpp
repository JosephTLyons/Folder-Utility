//
//  Directory.cpp
//  Empty Folder Remover
//
//  Created by Joseph Lyons on 3/20/17.
//
//

#include "Directory.hpp"

void removeEmptyFolders(File holdsFirstPathPicked)
{
    // Scans files and directories recursively, but skips hidden files
    DirectoryIterator dirIter (File (holdsFirstPathPicked.getFullPathName()), true, "*",
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
                fileHolder.moveToTrash();
            }
        }
    }
}

bool folderIsEmpty(File fileHolder)
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
