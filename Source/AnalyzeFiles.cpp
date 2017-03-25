//
//  AnalyzeFiles.cpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/24/17.
//
//

#include "AnalyzeFiles.hpp"

void AnalyzeFiles::setMainPathway(File holdsFirstPathSelected)
{
    Base::setMainPathway(holdsFirstPathSelected);
}

void AnalyzeFiles::collectFilenames()
{
    DirectoryIterator dirIter (File (getMainPathway().getFullPathName()), true, "*",
                                     File::findFiles + File::ignoreHiddenFiles);
    
    Array<File> temporaryFileHolderArray = Base::returnDirIterItemsArray(dirIter);
    Array<String> extensionArray;
    Array<int> countOfFiles;
    
    // Get all extensions from the file array into the string array
    for(int i = 0; i < temporaryFileHolderArray.size(); i++)
    {
        extensionArray.add(temporaryFileHolderArray[i].getFileName());
    }
    
    extensionArray.sort();
    
    for(int i = 0; i < extensionArray.size(); i++)
    {
        Base::addToOutputString(extensionArray[i]);
        Base::addToOutputString("\n");
    }
    
    #include <iostream>
    using namespace std;
    cout << Base::getOutputString();
}

String AnalyzeFiles::getListOfItems()
{
    return Base::getOutputString();
}

void AnalyzeFiles::clearListOfFiles()
{
    Base::clearOutputString();
}