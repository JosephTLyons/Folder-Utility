//
//  Directory.cpp
//  Empty Folder Remover
//
//  Created by Joseph Lyons on 3/20/17.
//
//

#include "Directory.hpp"
#include "../JuceLibraryCode/JuceHeader.h"

void removeEmptyFolders(const char *directoryPath)
{
    DirectoryIterator dirIter (File (directoryPath), true, "*",
                               File::findFilesAndDirectories + File::ignoreHiddenFiles);
    
    File fileHolder;
    
    while (dirIter.next())
    {
        fileHolder = dirIter.getFile();
    }
}
