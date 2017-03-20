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
    bool folderIsEmpty(File fileHolder);
    
public:
    
    void setOriginalPathWay(File holdsFirstPathPicked);
    File getOriginalPathway();
    void removeEmptyFolders();
};

#endif /* Directory_hpp */
