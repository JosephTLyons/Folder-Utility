# Folder Utility
A simple application for cleaning up folders / directories.

* Remove all empty folders within a chosen directory.
* Capitalize folders names, file names, or both.

![alt tag](https://github.com/JosephTLyons/Folder-Utility/blob/master/Images/Folder%20Utility%20GUI.png)

WARNING: Folder Utility hasn't been tested in every case.  I've only tested it in small, controlled
directories.  However, for the removal of the folders detected as being empty, I'm using JUCE code
that just moves the files to the trashcan, so the worst case is a file or folder gets moved to the trash,
but isn't deleted, if this even happens at all.
