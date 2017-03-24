//
//  Base.cpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/24/17.
//
//

#include "Base.hpp"

File Base::getFileHolder()
{
    return fileHolder;
}

File Base::getMainPathway()
{
    return mainPathway;
}

void Base::setFileHolder(const File &inputFileHolder)
{
    fileHolder = inputFileHolder;
}

void Base::setMainPathway(File holdsFirstPathSelected)
{
    mainPathway = holdsFirstPathSelected;
}

Array<File> Base::returnDirIterItemsArray(DirectoryIterator &dirIter)
{
    // Iterate and collect all files and store in filesArray
    while(dirIter.next())
    {
        allFilesAndFoldersArray.add(dirIter.getFile());
    }
    
    return allFilesAndFoldersArray;
}
