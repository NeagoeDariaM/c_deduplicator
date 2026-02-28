#include <stdio.h>
#include "openfolder.h"

int main (void) {
    file list[1024];
    char directory[256];
	int ct = 0;
	printf("Enter the folder to scan: ");
    scanf("%s", directory);
	if (open_dir(directory, list, &ct) != 0)  {
		printf("Folder error.\n");
		return -1;
	}
	for (int i = 0; i < ct; i++) {
		if (list[i].del) {
			continue;
		}
		for (int j = i + 1; j < ct; j++) {
			if (list[j].del) {
			continue;
		}
			if (list[i].size == list[j].size) {
				if (list[i].hash == list[j].hash) {
					printf("The file: %s is the same with: %s\n", list[i].name, list[j].name);
					printf("\nDelete the copy? (y/n): ");
					char ch;
					scanf(" %c", &ch);
					if (ch == 'y' || ch == 'Y') {
						if (remove(list[j].path) == 0) {
							printf("Deleted!\n");
							list[j].del = 1;
						} else {
							printf("Error\n");
						}
					}
				}
			}
		}
	}
	printf("Scan complete.\n");
	return 0;
}
