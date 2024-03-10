#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void listFilesRecursively(const char *basePath) {
    DIR *dir;
    struct dirent *entry;
 
    if ((dir = opendir(basePath)) == NULL) {
        perror("Error opening directory");
        return;
    }
 
    while ((entry = readdir(dir)) != NULL) {
 
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
 
            printf("%s/%s\n", basePath, entry->d_name);
 
            if (entry->d_type == DT_DIR) {
                char path[1000];
                snprintf(path, sizeof(path), "%s/%s", basePath, entry->d_name);
                listFilesRecursively(path);
            }
        }
    }
 
    closedir(dir);
}

int main() {
    char basePath[1000];
 
    printf("Enter the base directory path: ");
    if (scanf("%s", basePath) != 1) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }
 
    listFilesRecursively(basePath);

    return 0;
}
