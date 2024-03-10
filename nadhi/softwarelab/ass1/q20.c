#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main() {
    char path[100];

    printf("Enter the file or directory path: ");
    fgets(path, sizeof(path), stdin);
 
    int length = strlen(path);
    if (length > 0 && path[length - 1] == '\n') {
        path[length - 1] = '\0';
    }
 
    if (access(path, F_OK) == 0) {
        printf("The file or directory exists.\n");
    } else {
        printf("The file or directory does not exist.\n");
    }

    return 0;
}
