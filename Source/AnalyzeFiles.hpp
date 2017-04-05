//
//  AnalyzeFiles.hpp
//  Folder Utility
//
//  Created by Joseph Lyons on 3/24/17.
//
//

#ifndef AnalyzeFiles_hpp
#define AnalyzeFiles_hpp

#include "FunctionBase.hpp"

class AnalyzeFiles : public FunctionBase
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

#endif /* AnalyzeFiles_hpp */
