//
//  Base.cpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/24/17.
//
//

#include "Base.hpp"

File Base::getMainPathway()
{
    return mainPathway;
}

File Base::getFileHolder()
{
    return fileHolder;
}

void Base::setMainPathway(File holdsFirstPathSelected)
{
    mainPathway = holdsFirstPathSelected;
}

void Base::setFileHolder(const File &inputFileHolder)
{
    fileHolder = inputFileHolder;
}

Array<File> Base::returnDirIterItemsArray(DirectoryIterator &dirIter)
{
    // Iterate and collect all files and store in filesArray
    while(dirIter.next())
    {
        allItemsArray.add(dirIter.getFile());
    }
    
    return allItemsArray;
}

String& Base::getOutputString()
{
    return outputString;
}
