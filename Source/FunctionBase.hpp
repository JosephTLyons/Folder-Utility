//
//  FunctionBase.hpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/24/17.
//
//

#ifndef FunctionBase_hpp
#define FunctionBase_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class FunctionBase
{
private:
    File mainPathway;
    File fileHolder;
    String outputString;
    
public:
    File getMainPathway();
    File getFileHolder();
    String getOutputString();
    
    void setMainPathway(File holdsFirstPathSelected);
    void setFileHolder(const File &inputFileHolder);
    
    void addToOutputString(const char *inputText);
    void addToOutputString(const String &inputString);
    
    void clearOutputString();
    Array<File> returnDirIterItemsArray(DirectoryIterator &dirIter);
};

#endif /* FunctionBase_hpp */
