#include <stdio.h>

void retangulo()
{
    int altura, base, k, i;

    do
    {
        printf("Informe a altura:");
        scanf("%d", &altura);
    }
    while(altura <= 0 || altura >= 50);

    do
    {
        printf("\nInforme o tamanho da base:");
        scanf("%d", &base);
    }
    while(base <= 0 || base >= 50);


    for(k = 1; k <= altura; k++)
    {
        for(i = 1; i <= base; i++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void trianguloRetangulo()
{
    int base, i, j;

    do
    {
        printf("Informe a base:");
        scanf("%d", &base);
    }
    while(base <= 0 || base >= 50);

    for(j = 1; j <= base; j++)
    {
        for(i = 1; i <= j; i++)
        {
           printf("*");
        }
        printf("\n");
    }
}

void retanguloVazio()
{
    int altura, base, k, i;

    do
    {
        printf("Informe a altura:");
        scanf("%d", &altura);
    }
    while(altura <= 0 || altura >= 50);

    do
    {
        printf("Informe a base:");
        scanf("%d", &base);
    }
    while(base <= 0 || base >= 50);

    printf("\n");

    for(k = 1; k <= altura; k++)
    {
        for(i = 1; i <= base; i++)
        {
            if((k == 1 || k == altura)||(i == 1 || i == base))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void triangulo()
{
    int base, i, j, k, cont;

    do
    {
        printf("Informe uma base impar:");
        scanf("%d", &base);
    }
    while(base <= 0 || base >= 50 || base%2 == 0);

    cont = base;

    for(j = 1; j <= base; j++)
    {
        cont = cont - 1;
        for(k = cont/2 ; k >= 1 ; k--)
        {
            if(j%2 != 0)
            {
                printf(" ");
            }
        }

        for(i = 1; i <= j; i++)
        {
            if(j%2 != 0)
            {
                printf("*");
            }
        }

        if(j%2 != 0)
        {
            printf("\n");
        }

    }
}

void paralelogramo()
{
    int base, i, j, cont = 0, k;

    do
    {
        printf("Informe a base:");
        scanf("%d", &base);
    }
    while(base <= 0 || base >= 50);

    for(j = 1; j <= base; j++)
    {
        for(i = 1; i <= j; i++)
        {
           printf("*");
        }
        printf("\n");
    }

    printf(" ");

    for(j = base-1; j >= 1; j--)
    {
        for(i = j; i >= 1; i--)
        {
           printf("*");
        }
        printf("\n");

        cont = cont + 1;

        for(k = 0 ; k <= cont ; k++)
        {
            printf(" ");
        }
    }
}

void menu()
{
    int opcao;

    printf("Escolha uma opcao:\n");

    while (opcao != 0)
    {
        printf("------------Menu------------- \n");
        printf("0 - Sair\n");
        printf("1 - Retangulo\n");
        printf("2 - Triangulo retangulo\n");
        printf("3 - Retangulo com interior vazio\n");
        printf("4 - Triangulo\n");
        printf("5 - Paralelogramo\n");
        printf("-----------------------------\n");

        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                retangulo();
                break;
            case 2:
                trianguloRetangulo();
                break;
            case 3:
                retanguloVazio();
                break;
            case 4:
                triangulo();
                break;
            case 5:
                paralelogramo();
                break;
            case 0:
                printf("Voce digitou a opcao que finaliza o programa.");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }
}

int main()
{
    menu();

    return 0;
}
