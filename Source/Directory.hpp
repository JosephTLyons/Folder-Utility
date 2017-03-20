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
    
    File originalPathwaySelected;
    String listOfFoldersRemoved;
    
    bool folderIsEmpty(File fileHolder);
    
public:
    
    void removeEmptyFolders();
    
    void setOriginalPathWay(File holdsFirstPathPicked);
    File getOriginalPathway();
    
    String getListOfFoldersRemoved();
};

#endif /* Directory_hpp */
