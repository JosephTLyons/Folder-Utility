//
//  AnalyzeFiles.cpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/24/17.
//
//

#include "AnalyzeFiles.hpp"

void AnalyzeFiles::collectFilenames()
{
    DirectoryIterator dirIter (File (getMainPathway().getFullPathName()), true, "*",
                                     File::findFiles + File::ignoreHiddenFiles);
    
    temporaryFileHolderArray = returnDirIterItemsArray(dirIter);
    Array<int> countOfFiles;
    
    // Start off with clean array, in case we run it multiple times
    filenameArray.clear();
    collectFileNamesInStrinArray();
    filenameArray.sort();
    addEachItemToOutputString();
    addCompletionInfoToOutputString();
}

void AnalyzeFiles::collectFileNamesInStrinArray()
{
    for(int i = 0; i < temporaryFileHolderArray.size(); i++)
    {
        filenameArray.add(temporaryFileHolderArray[i].getFileName());
    }
}

void AnalyzeFiles::addEachItemToOutputString()
{
    for(int i = 0; i < filenameArray.size(); i++)
    {
        addToOutputString((String) (i + 1));
        addToOutputString(") ");
        addToOutputString(filenameArray[i]);
        addToOutputString("\n");
    }
}

void AnalyzeFiles::addCompletionInfoToOutputString()
{
    addToOutputString("\nCompleted: ");
    addToOutputString((String) filenameArray.size());
    addToOutputString(" files found.");
}