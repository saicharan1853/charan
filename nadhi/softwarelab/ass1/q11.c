#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char ch;
 
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);
 
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Unable to open the input file. Make sure the file exists.\n");
        return 1;
    }
 
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);
 
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Unable to open the output file. Make sure you have write permissions.\n");
        return 1;
    }
 
    while ((ch = fgetc(inputFile)) != EOF) {
        
        if (ch == '\n'||ch == ' '||ch == '\t')  {
         
            while ((ch = fgetc(inputFile)) == '\n') {
            
            }
 
            if (ch != EOF) {
                fputc(ch, outputFile);
            }
        } else {
         
            fputc(ch, outputFile);
        }
    }

   
    fclose(inputFile);
    fclose(outputFile);
    remove(inputFileName);
    rename(outputFileName,inputFileName);
  
    printf("Empty lines removed successfully!\n");

    return 0;
}
