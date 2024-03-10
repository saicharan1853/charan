#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    FILE* fptr;
    char data[50];
   fptr = fopen("fileq1.txt", "r");

    if (fptr == NULL) {
        printf("The file is not opened. The program will "
               "now exit.");
    }else{

        printf("the file is opened.\n");
        while (fgets(data,50,fptr)!=NULL)
        { printf("%s", data);}
    
        fclose(fptr);
 
        printf(
            "Data successfully read from file GfgTest.c\n");
        printf("The file is now closed.");
    }
    return 0;
}