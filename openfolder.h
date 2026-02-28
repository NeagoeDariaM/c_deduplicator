#ifndef OPEN_H
#define OPEN_H

typedef struct {
    char path[1024];
    char name[256];
    long size;
    unsigned int hash;
} file;

int open_dir(char *directory, file *list, int *count);

#endif