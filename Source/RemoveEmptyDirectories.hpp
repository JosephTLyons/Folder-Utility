//
//  RemoveEmptyDirectories.hpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/20/17.
//
//

#ifndef RemoveEmptyDirectories_hpp
#define RemoveEmptyDirectories_hpp

#include "Base.hpp"

class RemoveEmptyDirectories : public Base
{
private:
    
    int numberOfFilesRemoved;
    bool iterateAgain;
    
    bool folderIsEmpty();
    void removeSingleEmptyFolder();
    
public:
    
    RemoveEmptyDirectories();
    void removeAllEmptyFolders();
    int getNumberOfFilesRemoved();
    void clearNumberOfFilesRemoved();
};

#endif /* RemoveEmptyDirectories_hpp */
