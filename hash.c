#include "hash.h"
#include <stdio.h>

unsigned int dohash(char *file) {
    FILE *f = fopen(file, "rb");
    if (!f) {
        return 0;
    }
    unsigned int hash = 5381;
    unsigned char buff[4096];
    int bytes;
    while ((bytes = fread(buff, 1, sizeof(buff), f)) > 0) {
        for (int i = 0; i < bytes; i++) {
            hash = ((hash << 5) + hash) + buff[i];
        }
    }
    fclose(f);
    return hash;
}
