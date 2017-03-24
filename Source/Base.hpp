//
//  Base.hpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/24/17.
//
//

#ifndef Base_hpp
#define Base_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class Base
{
private:
    File fileHolder;
    File mainPathway;
    Array<File> allFilesAndFoldersArray;
    
public:
    File getFileHolder();
    File getMainPathway();
    
    void setFileHolder(const File &inputFileHolder);
    void setMainPathway(File holdsFirstPathSelected);
    Array<File> returnDirIterItemsArray(DirectoryIterator &dirIter);
};

#endif /* Base_hpp */
