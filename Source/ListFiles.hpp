//
//  ListFiles.hpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/24/17.
//
//

#ifndef ListFiles_hpp
#define ListFiles_hpp

#include "FunctionBase.hpp"

class ListFiles : public FunctionBase
{
private:
    
    Array<File> temporaryFileHolderArray;
    Array<String> filenameArray;
    
    void collectFileNamesInStrinArray();
    void addEachItemToOutputString();
    void addCompletionInfoToOutputString();
    
public:
    void collectFilenames();
};

#endif /* ListFiles_hpp */
