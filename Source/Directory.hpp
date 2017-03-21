//
//  Directory.hpp
//  Empty Folder Remover
//
//  Created by Joseph Lyons on 3/20/17.
//
//

#ifndef Directory_hpp
#define Directory_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class Directory
{
private:
    
    File mainPathway;
    String listOfFoldersRemoved;
    int numberOfFilesRemoved;
    bool iterateAgain;
    
    bool folderIsEmpty(File fileHolder);
    
public:
    
    Directory();
    void removeEmptyFolders();
    void setMainPathway(File holdsFirstPathSelected);
    File getMainPathway();
    String getListOfFoldersRemoved();
    int getNumberOfFilesRemoved();
    void clearListOfFoldersRemoved();
    void clearNumberOfFilesRemoved();
};

#endif /* Directory_hpp */
