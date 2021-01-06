#include <stdio.h>      //windows
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define NUMEROS_SORTEIO 20

void ler_aposta(int *aposta, int n)
{
    int k, y, existe;

    for(k = 0; k < n; k++)
    {
        do
        {
            printf("Informe a aposta numero %d: ", k+1);
            scanf("%d", &aposta[k]);
            existe = 0;
            for(y = 0; y < k; y++)
            {
                if(aposta[y] == aposta[k])
                {
                    existe = existe + 1;
                }
            }
        }while(aposta[k] < 0 || aposta[k] > 100 || existe > 0);
    }
}

void sorteia_valores(int *sorteio, int n)
{
    int k,i;

    for(k = 0; k < n; k++)
    {
        srand(time(NULL));
        sorteio[k] = rand()%101;
        printf("sort %d = %d\n", k+1, sorteio[k]);
        Sleep(1000);
    }
}

int *compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns)
{
    int k, y, i, j;
    int *vetorAcertos;

    vetorAcertos = (int*) malloc(NUMEROS_SORTEIO*sizeof(int));

    if(vetorAcertos == NULL)
    {
        printf("ERRO NA ALOCACAO DE MEMORIA!!!!");
    }
    else
    {
        printf("\nOs numeros que voce acertou foram:\n");
            for(k = 0; k < na; k++)
            {
                for(y = 0; y < ns; y++)
                {
                    if(aposta[k] == sorteio[y])
                    {
                        *qtdacertos = *qtdacertos + 1;
                        vetorAcertos[k] = aposta[k];
                        printf("%d ", vetorAcertos[k]);
                    }
                }
            }
        printf("\nA quantidade de numeros acertados foi: %d", qtdacertos);

        return vetorAcertos;
    }
}

int main()
{
    int quantNumeros, i;
    int *aposta, *sorteio, *qtdacertos = 0, *vetorResultado;

    do
    {
        printf("Informe a quantidade de numeros que voce deseja apostar: ");
        scanf("%d", &quantNumeros);
    }while(quantNumeros < 1 || quantNumeros > 20);

    aposta = (int*) malloc(quantNumeros*sizeof(int));
    sorteio = (int*) malloc(NUMEROS_SORTEIO*sizeof(int));

    if(aposta == NULL || sorteio == NULL)
    {
        printf("ERRO NA ALOCACAO DE MEMORIA!!!!");
    }
    else
    {
        ler_aposta(aposta, quantNumeros);
        sorteia_valores(sorteio, NUMEROS_SORTEIO);
        vetorResultado = compara_aposta(aposta, sorteio, &qtdacertos, quantNumeros, NUMEROS_SORTEIO);
    }

    free(aposta);
    free(sorteio);
    free(vetorResultado);
    vetorResultado = NULL;
    aposta = NULL;
    sorteio = NULL;

    return 0;
}
