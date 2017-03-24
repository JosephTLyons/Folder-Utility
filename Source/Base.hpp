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
    File mainPathway;
    File fileHolder;
    Array<File> allItemsArray;
    String outputString;
    
public:
    File getMainPathway();
    File getFileHolder();
    String& getOutputString();
    
    void setMainPathway(File holdsFirstPathSelected);
    void setFileHolder(const File &inputFileHolder);
    Array<File> returnDirIterItemsArray(DirectoryIterator &dirIter);
};

#endif /* Base_hpp */
