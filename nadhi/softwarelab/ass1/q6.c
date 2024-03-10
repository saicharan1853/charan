#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFileName[100], destinationFileName[100];
    char ch;

        printf("Enter the name of the source file: ");
    scanf("%s", sourceFileName);

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file. Make sure the file exists.\n");
    
    }

    printf("Enter the name of the destination file: ");
    scanf("%s", destinationFileName);

    destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Unable to open the destination file. Make sure you have write permissions.\n");

    }
    while (fscanf(sourceFile,"%c",&ch) != EOF) {
        fprintf(destinationFile,"%c",ch);
        
    
    }
    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copy successful!\n");

    return 0;
}
