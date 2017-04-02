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
    
    Array<juce_wchar> fullPathArray;
    String fullPathString;
    int positionOfFirstCharacter;
    bool changeOccured;

    // Private function members
    void capitalizeItems(Array<File> &items);
    void sortItems(Array<File> &items);
    int  countBackslashesInString(const String &directoryPath);
    void makeUpperCase();
    void copyStringToArray();
    void findLastBackslashInPath();
    void capitalizeFirstLetterInPath();
    void capitalizeOtherOccurances();
    void capitalizeLetter(const int &position);
    void copyArrayBackToString();
    void outputChangesToSummary();
    
public:
    
    void capitalizeItemsDriver(const bool &files, const bool &folders);
    
};

#endif /* CapitalizeItems_hpp */
