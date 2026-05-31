# c_deduplicator

This project identifies and deletes duplicate files in a given directory.
For this project I used two .h and three .c files.

## hash.c

I chose to use the hash algorithm, *DJB2*, to be able to easily compare the contents of the files.
In the *dohash* function, the file is opened, and while we read bytes from the file, for each byte we make a hash, shifting by 5 and adding the hash and what is in the buffer at that position. In order for the algorithm to be more efficient, the hash is not calculated for each file, but only for those whose size is the same.

## openfolder.c

For the *open_dir* function, we needed the `dirent.h` and `sys/stat.h` libraries. We opened the directory, and then while we read from the directory we want to build the entire path, to check if the stat function (get information about the file) was completed successfully. Then, if the file is not another folder or link (it is a regular file), all the necessary information about the file is placed in the structure (name, path, size, hash, whether it is deleted or not).

## main.c

In the *main* function, the folder that will be analyzed is read, then each file is taken separately and compared with the rest, only if one of them has not been deleted by then. Checking if the files are the same is done by comparing the size, and then the hash. If they are the same, the user is asked if he wants to be deleted, in the affirmative case deleting.
