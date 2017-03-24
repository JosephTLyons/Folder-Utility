//
//  AnalyzeFiles.hpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/24/17.
//
//

#ifndef AnalyzeFiles_hpp
#define AnalyzeFiles_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class AnalyzeFiles
{
private:
    File fileHolder;
    File mainPathway;
    
public:
    
    void setMainPathway(File holdsFirstPathSelected);
};

#endif /* AnalyzeFiles_hpp */
