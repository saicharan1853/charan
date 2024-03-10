#include<stdio.h>
#include<ctype.h>
int main()
{
    FILE * fp1,*fp2;
    char ch,new_ch;
      char inputFileName[100], outputFileName[100];
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    fp1 = fopen(inputFileName, "r");
    if (fp1 == NULL) {
        printf("Unable to open the input file. Make sure the file exists.\n");
        return 1;
    }
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    fp2 = fopen(outputFileName, "w");
    if (fp2 == NULL) {
        printf("Unable to open the output file. Make sure you have write permissions.\n");
       return 1;
    }
    
    if(fp1==NULL || fp2==NULL)
    {
        printf("Cannot open the files");
        return 1;
    }
    else 
    {
        ch=fgetc(fp1);
        while(ch!=EOF)
        {
            new_ch=tolower(ch);
            if(new_ch==ch)
            {
               new_ch=toupper(ch);
            }
            fputc(new_ch,fp2);
            ch=fgetc(fp1);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove(inputFileName);
    rename(outputFileName,inputFileName);
    return 0;
}