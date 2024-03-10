#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1, *file2, *mergedFile;
    char file1Name[100], file2Name[100], mergedFileName[100];
    char ch;
 
    printf("Enter the name of the first file: ");
    scanf("%s", file1Name);
 
    file1 = fopen(file1Name, "r");
    if (file1 == NULL) {
        printf("Unable to open the first file. Make sure the file exists.\n");
        return 1;
    }
 
    printf("Enter the name of the second file: ");
    scanf("%s", file2Name);
 
    file2 = fopen(file2Name, "r");
    if (file2 == NULL) {
        printf("Unable to open the second file. Make sure the file exists.\n");
        return 1;
    }
 
    printf("Enter the name of the merged file: ");
    scanf("%s", mergedFileName);
 
    mergedFile = fopen(mergedFileName, "w");
    if (mergedFile == NULL) {
        printf("Unable to open the merged file. Make sure you have write permissions.\n");
        return 1;
    }
 
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, mergedFile);
    }
 
    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, mergedFile);
    }
 
    fclose(file1);
    fclose(file2);
    fclose(mergedFile);

    printf("Files merged successfully!\n");

    return 0;
}
