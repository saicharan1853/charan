#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fptr;
    fptr=fopen("fileq1.txt","a");
    if(fptr == NULL)
  {
  printf("the file is not opened");   
   }
   else{
    printf(" the file is  now opened \n");
       fputs("heeyy..!",fptr);
       fputs(" \n",fptr);
   }
    fclose(fptr);
    printf("data is appended in the file..");
    return 0;
}