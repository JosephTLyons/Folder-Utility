//
//  FunctionBase.cpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/24/17.
//
//

#include "FunctionBase.hpp"

File FunctionBase::getMainPathway()
{
    return mainPathway;
}

File FunctionBase::getFileHolder()
{
    return fileHolder;
}

String FunctionBase::getOutputString()
{
    return outputString;
}

void FunctionBase::setMainPathway(File holdsFirstPathSelected)
{
    mainPathway = holdsFirstPathSelected;
}

void FunctionBase::setFileHolder(const File &inputFileHolder)
{
    fileHolder = inputFileHolder;
}

void FunctionBase::addToOutputString(const char *inputText)
{
    outputString += inputText;
}

void FunctionBase::addToOutputString(const String &inputString)
{
    outputString += inputString;
}

void FunctionBase::clearOutputString()
{
    outputString.clear();
}

Array<File> FunctionBase::returnDirIterItemsArray(DirectoryIterator &dirIter)
{
    Array<File> allItemsArray;
    
    // Iterate and collect all files and store in filesArray
    while(dirIter.next())
    {
        allItemsArray.add(dirIter.getFile());
    }
    
    return allItemsArray;
}
