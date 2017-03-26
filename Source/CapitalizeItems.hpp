//
//  CapitalizeItems.hpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/23/17.
//
//

#ifndef CapitalizeItems_hpp
#define CapitalizeItems_hpp

#include "Base.hpp"

class CapitalizeItems : public Base
{
private:
    
    void capitalizeItems(Array<File> &items);
    void makeUpperCase();
    
public:
    void capitalizeItemsDriver(const bool &files, const bool &folders);
    
};

#endif /* CapitalizeItems_hpp */
