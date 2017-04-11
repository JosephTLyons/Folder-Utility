//
//  ListFiles.cpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/24/17.
//
//

#include "ListFiles.hpp"

void ListFiles::collectFilenames()
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

void ListFiles::collectFileNamesInStrinArray()
{
    for(int i = 0; i < temporaryFileHolderArray.size(); i++)
    {
        filenameArray.add(temporaryFileHolderArray[i].getRelativePathFrom(getMainPathway()));
    }
}

void ListFiles::addEachItemToOutputString()
{
    for(int i = 0; i < filenameArray.size(); i++)
    {
        addToOutputString((String) (i + 1));
        addToOutputString(") ");
        addToOutputString(filenameArray[i]);
        addToOutputString("\n");
    }
}

void ListFiles::addCompletionInfoToOutputString()
{
    addToOutputString("\nCompleted: ");
    addToOutputString((String) filenameArray.size());
    addToOutputString(" file(s) found.");
}
