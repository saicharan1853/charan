#include <stdio.h>
#include <stdlib.h>
    

int main() {
    FILE *file1, *file2;
    char ch1,ch2;
    char filename1[100], filename2[100];

    printf("Enter the name of the first file: ");
    scanf("%s", filename1);

    printf("Enter the name of the second file: ");
    scanf("%s", filename2);

  file1 = fopen(filename1, "r");
    file2 = fopen(filename2, "r");

  if (file1 == NULL || file2 == NULL) {
        printf("Unable to open one or both files. Make sure the files exist.\n");
        return 1;
    }
    else {
        ch1=fgetc(file1);
        ch2=fgetc(file2);

      while (ch1 != EOF && ch2 != EOF) {
        ch1=fgetc(file1);
        ch2=fgetc(file2);
      }
        if (ch1 == ch2) {
        printf("Files are identical.\n");
        }
     else if (ch1!=ch2){
        printf("Files are not identical.\n");
    } else {
        printf("some crap occured\n");
        
    }

    fclose(file1);
    fclose(file2);
      }
    return 0;
}
