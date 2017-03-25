# Folder Utility
Folder Utility is a simple tool that can clean up the contents of any directory (folder), tidy up the names of items, and analyze the contents within any directory and return the results all in a single summary output section.

* Remove all empty folders within a chosen directory.
* Capitalize folders names, file names, or both.
* List all files and list a count of all file extensions

![alt tag](https://github.com/JosephTLyons/Folder-Utility/blob/master/Images/Folder%20Utility%20GUI.png)

WARNING: Folder Utility hasn't been tested in every case.  I've only tested it in small, controlled
directories.  However, for the removal of the folders detected as being empty, I'm using JUCE code
that just moves the files to the trashcan, so the worst case is a file or folder gets moved to the trash,
but isn't deleted, if this even happens at all.
