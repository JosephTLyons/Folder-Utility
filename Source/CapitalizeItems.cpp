//
//  CapitalizeItems.cpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/23/17.
//
//

#include "CapitalizeItems.hpp"

void CapitalizeItems::capitalizeItems(const bool &files, const bool &folders)
{
    // Only execute function if either or is selected
    if (files || folders)
    {
        DirectoryIterator dirIterFiles (File (mainPathway.getFullPathName()), true, "*",
                                        File::findFiles + File::ignoreHiddenFiles);
        
        DirectoryIterator dirIterFolders (File (mainPathway.getFullPathName()), true, "*",
                                          File::findDirectories + File::ignoreHiddenFiles);
        
        DirectoryIterator dirIterFilesAndFolders (File (mainPathway.getFullPathName()), true, "*",
                                                  File::findFilesAndDirectories +
                                                  File::ignoreHiddenFiles);
        
        // Call function here and pass correct iter into it
    }
}

void CapitalizeItems::setMainPathway(File holdsFirstPathSelected)
{
    mainPathway = holdsFirstPathSelected;
}
