//
//  CapitalizeItems.hpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/23/17.
//
//

#ifndef CapitalizeItems_hpp
#define CapitalizeItems_hpp

#include "FunctionBase.hpp"

class CapitalizeItems : public FunctionBase
{
private:
    
    // Private function members
    void capitalizeItems(Array<File> &items);
    void makeUpperCase();
    
public:
    
    void capitalizeItemsDriver(const bool &files, const bool &folders);
    
};

#endif /* CapitalizeItems_hpp */
