#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 250

int main()
{
    FILE * fp;
    char distinct_words[SIZE][50];
    char word[SIZE];
    int count[50];
    int ind=0;
    int len,isUnique;
    for(int i=0;i<50;i++)
    {
        count[i]=0;
    }
    fp=fopen("fileq1.txt","r");
    if(fp==NULL)
    {
        printf("Cannot open the file");
        return 1;
    }
    else
    {
        while(fscanf(fp,"%s",word)!=EOF)
        {
            for(int i=0;i<50;i++)
            {
                word[i]=tolower(word[i]);
            }
            len=strlen(word);
            if(ispunct(word[len-1])) 
            {
                word[len-1]='\0';    
            }
            isUnique=1;
            for(int i=0;i<ind && isUnique;i++)
            {
                if(strcmp(distinct_words[i],word)==0) 
                {
                    isUnique=0;              
                    count[i]++;              
               }
            }
            if(isUnique)
            {
                strcpy(distinct_words[ind],word); 
                count[ind]++;
                ind++;
            }
        }
    }
    fclose(fp);
    for(int i=0;i<ind;i++)
    {
        printf("The word %s appears %d times\n",distinct_words[i],count[i]);
    }
    return 0;
}