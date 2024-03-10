#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD 100

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[WORD], outputFileName[WORD], wordToRemove[WORD];
    char word[WORD], ch;
    int wordFound = 0, wordLength;
 
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
 
    printf("Enter the word to remove: ");
    scanf("%s", wordToRemove);
 
    wordLength = strlen(wordToRemove);
 
    while ((ch = fgetc(inputFile)) != EOF) {
   
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
  
            int i = 0;
            while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                word[i++] = ch;
                ch = fgetc(inputFile);
            }
            word[i] = '\0';
 
            if (strcmp(word, wordToRemove) == 0) {
            
                wordFound = 1;
            } else {
            
                fputs(word, outputFile);
            }
        }
 
        fputc(ch, outputFile);
    }
 
    fclose(inputFile);
    fclose(outputFile);
    remove(inputFileName);
    rename(outputFileName,inputFileName);
 
    if (wordFound) {
        printf("Word '%s' removed successfully!\n", wordToRemove);
    } else {
        printf("Word '%s' not found in the file.\n", wordToRemove);
    }

    return 0;
}
