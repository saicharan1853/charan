#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];
    char wordToFind[MAX_WORD_LENGTH], replacementWord[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH], ch;
    int wordLength, inWord = 0;
 
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
 
    printf("Enter the word to find: ");
    scanf("%s", wordToFind);
 
    printf("Enter the replacement word: ");
    scanf("%s", replacementWord);
 
    wordLength = strlen(wordToFind);
 
    while ((ch = fgetc(inputFile)) != EOF) {
    
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
          
            int i = 0;
            while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
                word[i++] = ch;
                ch = fgetc(inputFile);
            }
            word[i] = '\0';
 
            if (strcmp(word, wordToFind) == 0) {
         
                fputs(replacementWord, outputFile);
                inWord = 1;
            } else {
            
                fputs(word, outputFile);
            }
        } else {
            
            if (inWord) {
                fputc(ch, outputFile);
                inWord = 0;
            } else {
                fputc(ch, outputFile);
            }
        }
    }
 
    fclose(inputFile);
    fclose(outputFile);
    remove(inputFileName);
    rename(outputFileName,inputFileName);
    printf("Word '%s' replaced with '%s' successfully!\n", wordToFind, replacementWord);

    return 0;
}
