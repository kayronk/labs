#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void exemplo(float **matriz, float *vetor)
{
    //exemplo dos slides para testes
    matriz[0][0] = 3;
    matriz[0][1] = 2;
    matriz[0][2] = 4;
    matriz[1][0] = 1;
    matriz[1][1] = 1;
    matriz[1][2] = 2;
    matriz[2][0] = 4;
    matriz[2][1] = 3;
    matriz[2][2] = -2;

    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 3;

}

void lerInput(float **matriz, int size, float *vetor)
{

    int i, j, k;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            printf("Matriz[%d][%d] = ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }
    printf("\n");
    for (k = 0; k < size; k++)
    {
        printf("Vetor[%d] = ", k+1);
        scanf("%f", &vetor[k]);
    }
}

void mostrarMatriz(int size, float **matriz, float *vetor)
{
    int i, j, k;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {

            printf("%.1f ", matriz[i][j]);
            if(j == size-1)
            {
                printf("\n");
            }
        }
    }
    for (k = 0; k < size; k++)
    {
       printf("V[%d] = %.1f\n", k+1, vetor[k]);
    }
}

void pivot(float** a, float size)
{
    int i, j, index;
    float tmp;

    for (i = 0; i < size; i++)
    {
        tmp = a[i][i];
        index = i;
        for (j = i+1; j < size; j++)
        {
            if (a[j][i] > tmp)
            {
                index = j;
                tmp = a[j][i];
            }
        }
        for (j = 0; j < size; j++)
        {
            tmp = a[i][j];
            a[i][j] = a[index][j];
            a[index][j] = tmp;
        }
    }
}

void triangularizacao(int size, float **a, float *vetor)
{
    int i, j= 0, k = 0;
    float m;

    //pivot(a, size);
    for (k = 0; k < size-1; k++)
    {
        for (i = k + 1; i<size; i++)
        {
            m = a[i][k]/a[k][k]; //calcula o multiplicador
            a[i][k] = 0;

            for (j=k+1; j<size; j++) //comeca do elemento apos o valor a ser zerado
            {
                a[i][j] = a[i][j] - (m*a[k][j]);
            }
            vetor[i] = vetor[i] - m * vetor[k];
        }
    }
    printf("---------------Matriz aplicando Gauss---------------\n");
    mostrarMatriz(size, a, vetor);
}

void gaussJordan(int size, float **a, float *vetor, float valor_a)
{
    int i, j= 0, k = 0;
    float m;
    float piv;

    for (k = 0; k < size; k++)
    {
        piv = a[k][k];
        vetor[k] = vetor[k]/piv;
        for (i = 0; i < size; i++)
        {
            a[k][i] = a[k][i]/piv;
        }
        for (i = 0; i<size; i++)
        {
            if(i != k)
            {
                m = a[i][k];
                a[i][k] = 0;

                for (j= k+1; j<size; j++)
                {
                    a[i][j] = a[i][j] - (m*a[k][j]);
                }
                vetor[i] = vetor[i] - m * vetor[k];
            }
        }
    }
    printf("\n");
    printf("-----------Matriz aplicando Gauss-Jordan------------\n");
    mostrarMatriz(size, a, vetor);
    for(k=0; k<size; k++)
    {
        printf("\nd%d = %.2f", k+1, vetor[k]);
    }
    for(k=0; k<size; k++)
    {
        printf("\nAmplitude%d = %.2f", k+1, vetor[k]*valor_a);
    }
    printf("\n----------------------------------------------------\n");
}

void substituicaoGauss(int size, float **a, float *vetor, float valor_a)
{
    float soma;
    int i, j, k, linha, coluna;

    float *resGauss;
    resGauss = (float *) malloc(size * sizeof(float));

    if (a[size-1][size-1] != 0.0)
    {
        if(vetor[size-1] == 0)
        {
            resGauss[size-1] = 0;
        }
        else
        {
            resGauss[size-1] = vetor[size-1] / a[size-1][size-1];
        }
    }
    else
    {
        printf("Erro, divisao por zero...");
    } //erro de divis�o por zero

    for (i = size-2; i >-1; i--)
    {
        soma = 0;
        for (j = i+1; j < size; j++)
        {
            soma += a[i][j] * resGauss[j];
        }
        if (a[i][i] != 0)
        {
            resGauss[i] = (vetor[i] - soma)/ a[i][i];
        }
        else
        {
            printf("Erro, divisao por zero...");
        } //erro de divis�o por zero
    }
    for(k=0; k<size; k++)
    {
        printf("\nd%d = %.2f", k+1, resGauss[k]);
    }
    for(k=0; k<size; k++)
    {
        printf("\nAmplitude%d = %.2f", k+1, resGauss[k]*valor_a);
    }
    printf("\n----------------------------------------------------");
    free (resGauss);
}

void metodoGauss(int size, float **matriz, float *vetor, float valor_a)
{
    triangularizacao(size, matriz, vetor);
    substituicaoGauss(size, matriz, vetor, valor_a);
}

int main()
{
    int i , j;
    int size;
    float valor_a;

    printf("Informe o valor do parametro a: ");
    scanf("%f", &valor_a);

    printf("Informe a quantidade de deslocamentos (pendulos): ");
    scanf("%d", &size);
    printf("\n");

    float *vetor;
    vetor = (float *) malloc(size * sizeof(float));         //alocando vetor

    float **matriz;
    matriz = (float **) malloc (size * sizeof (float*));

    for (i = 0; i < size; ++i)
    {
        matriz[i] = (float*) malloc (size * sizeof (float));
    }

    lerInput(matriz, size, vetor);
    //exemplo(matriz, vetor);
    printf("------------------Matriz inicial--------------------\n");
    mostrarMatriz(size, matriz, vetor);
    printf("----------------------------------------------------\n");
    metodoGauss(size, matriz, vetor, valor_a);
    gaussJordan(size, matriz, vetor, valor_a);

    free (vetor);
    free (matriz);

    return 0;
}
