//
//  Settings.hpp
//  Folder Utility
//
//  Created by Joseph Lyons on 4/8/17.
//
//

#ifndef Settings_hpp
#define Settings_hpp

class Settings
{
private:
    
    int fontSizeForOutputSlider;
    int fontSizeForDirectoryPathSlider;
    
public:
    
    void saveSettings();
    void restoreSettings();
    
};

#endif /* Settings_hpp */
