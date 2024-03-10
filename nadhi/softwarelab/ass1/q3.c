#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isprime(int num)
{
    int flag=0;
    int retVal=1;
    if(num<=1)
    {
        retVal=0;
    }
    else if(num==2)
    {
        retVal=1;
    }
    else if(num%2==0)
    {
        retVal=0;
    }
    else
    {
        for(int i=3;i<=sqrt(num) && flag==0;i=i+2)
        {
            if(num%i==0)
            {
                retVal=0;
                flag=1;
            }
        }
    }
    return retVal;
}
int iseven(int num)
{
    int retVal=1;
    if(num%2!=0)
    {
        retVal=0;
    }
    return retVal;
}
int main()
{
    FILE *fPtrIn, *fPtrEven, *fPtrOdd, *fPtrPrime;

    int num;

    fPtrIn   = fopen("numbers.txt", "r");
    if(fPtrIn==NULL)
    {
        printf("Num file cannot be opened");
        return 1;
    }
    fPtrEven = fopen("even.txt" , "w");
    fPtrOdd  = fopen("odd.txt" , "w");
    fPtrPrime= fopen("prime.txt", "w");
    num=fgetc(fPtrIn);
if(fPtrEven==NULL||fPtrOdd==NULL||fPtrPrime==NULL)
    {
        printf("Cannot open one of the files");
        return 1;
    }
    else
    {
    while (fscanf(fPtrIn,"%d",&num)!=-1)
    {
        if (isprime(num))
           { fputc(num,fPtrPrime);
           }
        else if (iseven(num)){
            fputc(num,fPtrEven);
        }
        else{
            fputc(num,fPtrOdd);
        }

    }
    }
    fclose(fPtrIn);
    fclose(fPtrEven);
    fclose(fPtrOdd);
    fclose(fPtrPrime);

    printf("Data written to files successfully.");

    return 0;

}
