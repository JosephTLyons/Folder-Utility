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

String Base::getOutputString()
{
    return outputString;
}

void Base::setMainPathway(File holdsFirstPathSelected)
{
    mainPathway = holdsFirstPathSelected;
}

void Base::setFileHolder(const File &inputFileHolder)
{
    fileHolder = inputFileHolder;
}

void Base::addToOutputString(const char *inputText)
{
    outputString += inputText;
}

void Base::addToOutputString(const String &inputString)
{
    outputString += inputString;
}

void Base::clearOutputString()
{
    outputString.clear();
}

Array<File> Base::returnDirIterItemsArray(DirectoryIterator &dirIter)
{
    Array<File> allItemsArray;
    
    // Iterate and collect all files and store in filesArray
    while(dirIter.next())
    {
        allItemsArray.add(dirIter.getFile());
    }
    
    return allItemsArray;
}
