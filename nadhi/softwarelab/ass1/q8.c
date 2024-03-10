#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int charCount = 0, wordCount = 0, lineCount = 0, inWord = 0;
 
    printf("Enter the name of the text file: ");
    scanf("%s", filename);
 
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file. Make sure the file exists.\n");
        return 1;
    }
 
    while ((ch = fgetc(file)) != EOF) {
   
        charCount++;
 
         if (ch == ' ' || ch == '\t' || ch == '\n') {
            if (inWord) {
                inWord = 0;
                wordCount++;
            }
        } else {
            inWord = 1;
        }
 
        if (ch == '\n') {
            lineCount++;
        }
    }
 
    if (inWord) {
        wordCount++;
    }
 
    fclose(file);
 
    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);

    return 0;
}
