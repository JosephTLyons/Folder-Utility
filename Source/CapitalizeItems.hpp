//
//  CapitalizeItems.hpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/23/17.
//
//

#ifndef CapitalizeItems_hpp
#define CapitalizeItems_hpp

#include "../JuceLibraryCode/JuceHeader.h"

class CapitalizeItems
{
private:
    File fileHolder;
    File mainPathway;
    
public:
    void capitalizeItems(const bool &files, const bool &folders);
    void setMainPathway(File holdsFirstPathSelected);
    
};

#endif /* CapitalizeItems_hpp */
