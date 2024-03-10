#include <stdio.h>

int main() {
    FILE *file;
    char ch;
 
    file = fopen("q17.c", "r");
 
    if (file == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }
 
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
 
    fclose(file);

    return 0;
}
