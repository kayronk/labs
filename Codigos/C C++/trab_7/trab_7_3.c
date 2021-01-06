#include<stdio.h>

int MDC(int m, int n)
{
    if (n == 0)
    {
        return m;
    }

    return MDC(n, m % n);
}

int main()
{
    int x, primNumero, segNumero;

    printf("-----MAXIMO DIVISOR COMUM-----\n");
    do
    {
        printf("Primeiro numero: ");
        scanf("%d", &primNumero);
        fflush(stdin);
    }while(primNumero < 0);

    do
    {
        printf("Segundo numero: ");
        scanf("%d", &segNumero);
        fflush(stdin);
    }while(segNumero < 0);

    if(primNumero >= segNumero)
    {
        x = MDC(primNumero, segNumero);
    }
    else
    {
        x = MDC(segNumero, primNumero);
    }
    printf("MDC(%d, %d) = %d\n", primNumero, segNumero, x);
    printf("------------------------------\n");

    return 0;
}
