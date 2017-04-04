# Folder Utility
Folder Utility is a simple tool that can clean up the contents of any directory (folder), tidy up the names of items, and analyze the contents within any directory and return the results all in a single summary output section.

* List all files.
* Remove all empty folders within a chosen directory.
* Capitalize folders names, file names, or both (still being worked on).
* Strip characters from a file, either "_", "-", or both (not implemented yet).
* A summary output window shows the details of what Folder Utility does specifically when an action is chosen.
* The summary output window's font is variable with the associated slider.

![alt tag](https://github.com/JosephTLyons/Folder-Utility/blob/master/Images/Folder%20Utility%20GUI.png)

WARNING: Folder Utility hasn't been tested in every case.  I've only tested it in small, controlled
directories.  However, for the removal of the folders detected as being empty, I'm using JUCE code
that just moves the files to the trashcan, so the worst case is a file or folder gets moved to the trash,
but isn't deleted, if this even happens at all.
