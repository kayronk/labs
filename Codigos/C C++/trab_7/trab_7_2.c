#include<stdio.h>
#include<stdlib.h>     //windows

void Dec2Bin(int decimal)
{
    if(decimal / 2 != 0)
    {
        Dec2Bin(decimal / 2);
    }
    printf("%d", decimal % 2);
}

int main()
{
    int decimal;

    printf("Numero decimal: ");
    scanf("%d", &decimal);
    fflush(stdin);
    Dec2Bin(decimal);

    return 0;
}
