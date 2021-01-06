#include<stdio.h>

int main()
{
    int numero, i, multiplicacao, j;

    printf("Informe um numero:");
    scanf("%d", &numero);

    for(j = 1; j <= numero; j++)
    {
        for(i = 1; i <= j; i++)
        {
            multiplicacao = j*i;
            printf("%d ", multiplicacao);
        }
        printf("\n");
    }

    return 0;
}
