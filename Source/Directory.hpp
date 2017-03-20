//
//  Directory.hpp
//  Empty Folder Remover
//
//  Created by Joseph Lyons on 3/20/17.
//
//

#ifndef Directory_hpp
#define Directory_hpp

#include "../JuceLibraryCode/JuceHeader.h"

void removeEmptyFolders(File holdsFirstPathPicked);
bool folderIsEmpty(File fileHolder);

#endif /* Directory_hpp */
