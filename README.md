# Empty-Folder-Remover
A simple application that removes all empty files, recursively, in a specified directory.

![alt tag](https://github.com/JosephTLyons/Empty-Folder-Remover/blob/master/Images/Empty%20Folder%20Remover.png)

WARNING: Empty Folder Remover hasn't been tested in every case.  I've only tested it in small, controlled
directories.  However, for the removal of the folders detected as being empty, I'm using JUCE code
that just moves the files to the trashcan, so worst case is a file or folder gets moved to the trash,
but isn't deleted, if this even happens at all.
