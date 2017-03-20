//
//  Directory.cpp
//  Empty Folder Remover
//
//  Created by Joseph Lyons on 3/20/17.
//
//

#include "Directory.hpp"

void removeEmptyFolders(const char *directoryPath)
{
    // Scans files and directories recursively, but skips hidden files
    DirectoryIterator dirIter (File (directoryPath), true, "*",
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
    // MAKE AN OPTION TO NOT DELETE FOLDERS WITH HIDDEN ITEMS?
    DirectoryIterator dirIter (File (fileHolder.getFullPathName()), false, "*",
                               File::findFilesAndDirectories + File::ignoreHiddenFiles);
    
    int fileCount = 0;
    
    while (dirIter.next())
    {
        fileHolder = dirIter.getFile();
        
        return false;
    }
    
    if(fileCount != 0)
    {
        return false;
    }
    
    else
        return true;
}
