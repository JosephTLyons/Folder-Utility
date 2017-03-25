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
    Array<String> filenameArray;
    Array<int> countOfFiles;
    
    // Get all extensions from the file array into the string array
    for(int i = 0; i < temporaryFileHolderArray.size(); i++)
    {
        filenameArray.add(temporaryFileHolderArray[i].getFileName());
    }
    
    filenameArray.sort();
    
    for(int i = 0; i < filenameArray.size(); i++)
    {
        Base::addToOutputString((String) (i + 1));
        Base::addToOutputString(") ");
        Base::addToOutputString(filenameArray[i]);
        Base::addToOutputString("\n");
    }
    
    Base::addToOutputString("\nCompleted: ");
    Base::addToOutputString((String) filenameArray.size());
    Base::addToOutputString(" files found.");
}

String AnalyzeFiles::getListOfItems()
{
    return Base::getOutputString();
}

void AnalyzeFiles::clearListOfFiles()
{
    Base::clearOutputString();
}
