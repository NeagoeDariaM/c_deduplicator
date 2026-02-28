#include "openfolder.h"
#include "hash.h"
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int open_dir(char *directory, file *list, int *count) {
    struct dirent *new;
    struct stat st;
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        return -1;
    }
    while ((new = readdir(dir)) != NULL) {
        if (strcmp(new->d_name, ".") == 0 || strcmp(new->d_name, "..") == 0) {
            continue;
        }
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", directory, new->d_name);
        if (stat(path, &st) == 0) {
            if (S_ISREG(st.st_mode)) {
                strcpy(list[*count].path, path);
                strcpy(list[*count].name, new->d_name);
                list[*count].size = st.st_size;
                list[*count].hash = dohash(path);
                list[*count].del = 0;
                (*count)++;
            }
        }
    }
    closedir(dir);
    return 0;
}
