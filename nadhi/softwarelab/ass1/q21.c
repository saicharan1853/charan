#include <stdio.h>

int main() {
    char oldFileName[100], newFileName[100];


    printf("Enter the old file name: ");
    scanf("%s", oldFileName);


    printf("Enter the new file name: ");
    scanf("%s", newFileName);


    if (rename(oldFileName, newFileName) == 0) {
        printf("File renamed successfully.\n");
    } else {
        printf("Error renaming file");
    }

    return 0;
}
