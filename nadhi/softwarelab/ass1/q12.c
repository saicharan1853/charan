#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD 100

int main() {
    FILE *file;
    char filename[100], wordToFind[WORD];
    char word[WORD];
    int wordCount = 0;
 
    printf("Enter the name of the text file: ");
    scanf("%s", filename);
 
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file. Make sure the file exists.\n");
        return 1;
    }
   
    printf("Enter the word to count: ");
    scanf("%s", wordToFind);
 
    while (fscanf(file, "%s", word) == 1) {
 
        if (strcmp(word, wordToFind) == 0) {
    
            wordCount++;
        }
    }

  
    fclose(file);
 
    printf("The word '%s' occurs in the file.\n", wordToFind, wordCount);

    return 0;
}
