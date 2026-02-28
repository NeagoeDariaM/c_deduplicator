#include <stdio.h>
#include <stdlib.h>
#include<dirent.h>

typedef struct {
    char path[1024];
    char name[256];
    long size;
    unsigned int hash;
} file;

int main (void) {
    file list[1024];
    char directory[256];
	int ct = 0;
    scanf("%s", directory);
	
	return 0;
}
