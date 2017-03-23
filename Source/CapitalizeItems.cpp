//
//  CapitalizeItems.cpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/23/17.
//
//

#include "CapitalizeItems.hpp"

void CapitalizeItems::capitalizeItems()
{
    DirectoryIterator dirIter (File (mainPathway.getFullPathName()), true, "*",
                               File::findFilesAndDirectories + File::ignoreHiddenFiles);
}

void CapitalizeItems::setMainPathway(File holdsFirstPathSelected)
{
    mainPathway = holdsFirstPathSelected;
}
