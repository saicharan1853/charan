#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    FILE *fp1,*fp2;
    char line[100];
    char line_to_remove[100];
    char actual_line[100];
    char new_line[50];
    printf("Enter the line to be removed:\n");
    fgets(line_to_remove,100,stdin);
    printf("Enter the line to replace the line removed:\n");
    fgets(new_line,100,stdin);
    fp1=fopen("fileq1.txt","r");
    fp2=fopen("fileq2.txt","w");
    if(fp1==NULL || fp2==NULL)
    {
        printf("Cannot open the files");
        return 1;
    }
    else 
    {
        while(fgets(line,100,fp1)!=NULL)
        {
            strcpy(actual_line,line);
            for(int i=0;i<50;i++)
            {
                line[i]=tolower(line[i]);
            }
            if(strcmp(line,line_to_remove)!=0)
            {
                fputs(actual_line,fp2);
            }
            else
            {
                fputs(new_line,fp2);
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("fileq1.txt");
    rename("fileq2.txt","fileq1.txt");
    printf("line is replaced successfully");
}