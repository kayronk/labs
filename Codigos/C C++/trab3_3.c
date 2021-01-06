#include <stdio.h>        //windows
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 20

void listaVazia(float vetNotas[MAX_ALUNOS][3], char vetNome[MAX_ALUNOS][MAX_ALUNOS], int vetMatricula[MAX_ALUNOS][3], int vetFaltas[MAX_ALUNOS])
{
    int i, j, k, l, z, a, b;

    for(z = 0; z < MAX_ALUNOS; z++)
    {
        vetFaltas[z] = -1;
    }

    for(i = 0; i < MAX_ALUNOS; i++)
    {
        for(j = 0; j < 3; j++)
        {
            vetNotas[i][j] = -1;
        }
    }

    for(k = 0; k < MAX_ALUNOS; k++)
    {
        for(l = 0; l < 3; l++)
        {
            vetMatricula[k][l] = -1;
        }
    }

    for(a = 0; a < MAX_ALUNOS; a++)
    {
        for(b = 0; b < MAX_ALUNOS; b++)
        {
            vetNome[a][b] = '9';
        }
    }
}

float mediaMaiores(float vetNotas[MAX_ALUNOS][3], int k)
{
    float maior1, maior2, menor, media;

    if(vetNotas[k][0] > vetNotas[k][1])
    {
        maior1 = vetNotas[k][0];
        menor = vetNotas[k][1];
    }
    else
    {
        maior1 = vetNotas[k][1];
        menor = vetNotas[k][0];
    }
    if(vetNotas[k][2] > menor)
    {
        maior2 = vetNotas[k][2];
    }
    else
    {
        maior2 = menor;
    }

    media = (maior1 + maior2)/2;

    return media;
}
void inserirDados(float vetNotas[MAX_ALUNOS][3], char vetNome[MAX_ALUNOS][MAX_ALUNOS], int vetMatricula[MAX_ALUNOS][3], int vetFaltas[MAX_ALUNOS])
{
    int k, z, matricula, quantFaltas, vagas = 0;
    float priNota, segNota, terNota;
    char nomeAluno[20];

    printf("------------INSERIR DADOS-------------\n");
    printf("Informe o nome do aluno:");
    gets(nomeAluno);
    fflush(stdin);

    printf("Informe  a matricula do aluno:");
    scanf("%d", &matricula);
    fflush(stdin);

    printf("Informe  a quantidade de faltas aluno:");
    scanf("%d", &quantFaltas);
    fflush(stdin);

    printf("Informe  a primeira nota do aluno:");
    scanf("%f", &priNota);
    fflush(stdin);

    printf("Informe  a segunda nota do aluno:");
    scanf("%f", &segNota);
    fflush(stdin);

    printf("Informe  a terceira nota do aluno:");
    scanf("%f", &terNota);
    fflush(stdin);
    printf("-------------------------------------\n");

    for(k = 0; k < MAX_ALUNOS; k++)
    {
        if(vetMatricula[k][0] == -1)
        {
            vagas = vagas + 1;
            for(z = 0; z < 20; z++)
            {
                vetNome[k][z] = nomeAluno[z];
                if(nomeAluno == '\0')
                {
                    break;
                }
            }

            vetMatricula[k][0] = matricula;
            vetNotas[k][0] = priNota;
            vetNotas[k][1] = segNota;
            vetNotas[k][2] = terNota;
            vetFaltas[k] = quantFaltas;

            break;
        }
    }

    if(vagas == 0)
    {
        printf("Desculpe professor, nao existem mais vagas na turma.\n");
    }

}

void removerAluno(float vetNotas[MAX_ALUNOS][3], char vetNome[MAX_ALUNOS][MAX_ALUNOS], int vetMatricula[MAX_ALUNOS][3], int vetFaltas[MAX_ALUNOS])
{
    int k, z, matricula, quantFaltas, cont = 0;
    float priNota, segNota, terNota;

    printf("----------REMOVER ALUNO----------\n");
    printf("Informe a matricula do aluno:\n");
    scanf("%d", &matricula);

    for(k = 0; k < MAX_ALUNOS; k++)
    {
        if(vetMatricula[k][0] == matricula)
        {
            cont = cont + 1;
            for(z = 0; z < 20; z++)
            {
                vetNome[k][z] = '9';
            }

            vetMatricula[k][0] = -1;
            vetNotas[k][0] = -1;
            vetNotas[k][1] = -1;
            vetNotas[k][2] = -1;
            vetFaltas[k] = -1;

            printf("Aluno removido com sucesso!\n");
            printf("---------------------------\n");

            break;
        }
    }

    if(cont == 0)
    {
        printf("Desculpe professor, mas essa matricula nao existe!\n");
    }

}

void reprovadosDesempenho(int vetFaltas[MAX_ALUNOS], char vetNome[MAX_ALUNOS][MAX_ALUNOS], float vetNotas[MAX_ALUNOS][3])
{
    int k, z;
    float media;

    printf("-------------REPROVADOS POR DESEMPENHO------------\n");

    for(k = 0; k < MAX_ALUNOS; k++)
    {
        //media = (vetNotas[k][0] + vetNotas[k][1] + vetNotas[k][2])/3;
        media = mediaMaiores(vetNotas, k);

        if((media < 7) && (media > 0) && (vetFaltas[k] <= 10))
        {
            for(z = 0; z < 20; z++)
            {
                printf("%c", vetNome[k][z]);
                if(vetNome[k][z] == '\0')
                {
                    break;
                }
            }
            printf("\n");
        }
    }
    printf("---------------------------------------------\n");
}

void reprovadosFalta(int vetFaltas[MAX_ALUNOS], char vetNome[MAX_ALUNOS][MAX_ALUNOS])
{
    int k, z;

    printf("----------------REPROVADOS POR FALTA----------------\n");

    for(k = 0; k < MAX_ALUNOS; k++)
    {
        if(vetFaltas[k] > 10)
        {
            for(z = 0; z < 20; z++)
            {
                printf("%c", vetNome[k][z]);
                if(vetNome[k][z] == '\0')
                {
                    break;
                }
            }
            printf("\n");
        }
    }
    printf("---------------------------------------------\n");
}

void listarAprovados(int vetFaltas[MAX_ALUNOS], char vetNome[MAX_ALUNOS][MAX_ALUNOS], float vetNotas[MAX_ALUNOS][3])
{
    int k, z;
    float media;

    printf("------------------APROVADOS---------------\n");

    for(k = 0; k < MAX_ALUNOS; k++)
    {
        //media = (vetNotas[k][0] + vetNotas[k][1] + vetNotas[k][2])/3;
        media = mediaMaiores(vetNotas, k);

        if((media >= 7) && (vetFaltas[k] <= 10))
        {
            for(z = 0; z < 20; z++)
            {
                printf("%c", vetNome[k][z]);
                if(vetNome[k][z] == '\0')
                {
                    break;
                }
            }
            printf("\n");
        }
    }
    printf("---------------------------------------------\n");
}

void menu(float vetNotas[MAX_ALUNOS][3], char vetNome[MAX_ALUNOS][MAX_ALUNOS], int vetMatricula[MAX_ALUNOS][3], int vetFaltas[MAX_ALUNOS])
{
    char o;

    printf("Escolha uma opcao:\n");

    while (o != '6')
    {
        printf("---------------------MENU------------------ \n");
        printf("1 - Inserir dados de um aluno\n");
        printf("2 - Remover dados de um aluno de acordo com sua matricula\n");
        printf("3 - Listar alunos aprovados\n");
        printf("4 - Listar alunos reprovados por falta\n");
        printf("5 - Listar alunos reprovados por desempenho\n");
        printf("6 - Sair\n");
        printf("-------------------------------------------\n");
        scanf("%c", &o);
        fflush(stdin);
        switch(o)
        {
            case '1':
                inserirDados(vetNotas, vetNome, vetMatricula, vetFaltas);
                getch();
                break;
            case '2':
                removerAluno(vetNotas, vetNome, vetMatricula, vetFaltas);
                getch();
                break;
            case '3':
                listarAprovados(vetFaltas, vetNome, vetNotas);
                getch();
                break;
            case '4':
                reprovadosFalta(vetFaltas, vetNome);
                getch();
                break;
            case '5':
                reprovadosDesempenho(vetFaltas, vetNome, vetNotas);
                getch();
                break;
            case '6':
                printf("Voce digitou a opcao que finaliza o programa.");
                getch();
                break;
            default:
                printf("Opcao invalida!\n");
                getch();
        }
        system("CLS");
        fflush(stdin);
    }
}

int main()
{
    float vetNotas[MAX_ALUNOS][3];
    char vetNome[MAX_ALUNOS][MAX_ALUNOS];
    int vetMatricula[MAX_ALUNOS][3], vetFaltas[MAX_ALUNOS];

    listaVazia(vetNotas, vetNome, vetMatricula, vetFaltas);
    menu(vetNotas, vetNome, vetMatricula, vetFaltas);


    return 0;
}
