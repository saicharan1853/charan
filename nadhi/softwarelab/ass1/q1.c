
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
 FILE *fptr;
 char data[50]="Am the one \n" "your the next";
 
  fptr= fopen("fileq1.txt","w");
   
  if(fptr == NULL)
  {
  printf("the file is not opened");   
   }
   else{
    printf(" the file is  now opened \n");
     if (strlen(data)>0) 
      {
       fputs(data,fptr);
       fputs("\n",fptr);
      }
      fclose(fptr);
      printf("data written successfully and file is closed");
      }
      return 0;
      }