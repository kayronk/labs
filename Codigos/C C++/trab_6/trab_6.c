#include <stdio.h>   //windows
#include <stdlib.h>
#include <string.h>
#define MAX_TITULO 60
#define MAX_STRING 50

typedef struct TAluno
{
    int matricula;
    char nome[MAX_STRING];
    float nota[3];
    float media;
    int faltas;
}TAluno;

void funcaoOrganiza(int numero, char caractere)
{
    int k;

    for(k = 0; k < numero-1; k++)
    {
        printf("%c", caractere);
    }
    printf("\n");
}

void funcaoTitulo(char string[MAX_TITULO])
{
    int numCaracteres, meio, i, j, k = 0;
    char stringAux[MAX_TITULO];

    numCaracteres = strlen(string)+1;

    for(i = 0; i < MAX_TITULO-1; i++)
    {
        stringAux[i] = '-';
    }
    stringAux[MAX_TITULO-1] = '\0';

    meio = (MAX_TITULO - numCaracteres)/2;

    for(j = meio; j < (meio + numCaracteres); j++)
    {
        if(string[k] == '\0')
        {
            break;
        }
        stringAux[j] = string[k];
        k = k + 1;
    }
    printf("%s\n", stringAux);
}

TAluno *realoca(TAluno *aluno, int *maxAlunos)
{
    aluno = (TAluno*) realloc(aluno, (*maxAlunos*sizeof(TAluno)));

    if(aluno == NULL)
    {
        printf("Erro na alocação de memoria!!");
    }
    else
    {
        return aluno;
    }
}

void inserirAluno(TAluno *aluno, FILE *arquivo, int y, int *maxAlunos)
{
    int existe;

    if(y == *maxAlunos)
    {
        *maxAlunos = *maxAlunos*2;
        aluno = realoca(aluno, maxAlunos);
    }

    //printf("maxAlunos* = %d\n", *maxAlunos);

    funcaoTitulo("CADASTRO");

    arquivo = fopen("arquivo.txt","rb");

    if(arquivo == NULL)
    {
        existe = 0;
    }
    else
    {
        existe = 1;
    }

    fclose(arquivo);

    if(existe == 1)
    {
        arquivo = fopen("arquivo.txt","ab");
        printf("Nome: ");
        gets(aluno[y].nome);
        fflush(stdin);

        printf("Matricula: ");
        scanf("%d", &aluno[y].matricula);
        fflush(stdin);

        do
        {
            printf("Faltas: ");
            scanf("%d", &aluno[y].faltas);
            fflush(stdin);
        }while(aluno[y].faltas < 0);

        do
        {
            printf("Primeira nota: ");
            scanf("%f", &aluno[y].nota[0]);
            fflush(stdin);
        }while(aluno[y].nota[0] < 0 || aluno[y].nota[0] > 10);

        do
        {
            printf("Segunda nota: ");
            scanf("%f", &aluno[y].nota[1]);
            fflush(stdin);
        }while(aluno[y].nota[1] < 0 || aluno[y].nota[1] > 10);

        do
        {
            printf("Terceira nota: ");
            scanf("%f", &aluno[y].nota[2]);
            fflush(stdin);
        }while(aluno[y].nota[2] < 0 || aluno[y].nota[2] > 10);

        aluno[y].media = (aluno[y].nota[0] + aluno[y].nota[1] + aluno[y].nota[2])/3;
        printf("Media: %.1f\n", aluno[y].media);

        fwrite(aluno, *maxAlunos*sizeof(TAluno), 1, arquivo);
        fclose(arquivo);
    }
    else
    {
        arquivo = fopen("arquivo.txt","wb");
        printf("Nome: ");
        gets(aluno[y].nome);
        fflush(stdin);

        printf("Matricula: ");
        scanf("%d", &aluno[y].matricula);
        fflush(stdin);

        do
        {
            printf("Faltas: ");
            scanf("%d", &aluno[y].faltas);
            fflush(stdin);
        }while(aluno[y].faltas < 0);

        do
        {
            printf("Primeira nota: ");
            scanf("%f", &aluno[y].nota[0]);
            fflush(stdin);
        }while(aluno[y].nota[0] < 0 || aluno[y].nota[0] > 10);

        do
        {
            printf("Segunda nota: ");
            scanf("%f", &aluno[y].nota[1]);
            fflush(stdin);
        }while(aluno[y].nota[1] < 0 || aluno[y].nota[1] > 10);

        do
        {
            printf("Terceira nota: ");
            scanf("%f", &aluno[y].nota[2]);
            fflush(stdin);
        }while(aluno[y].nota[2] < 0 || aluno[y].nota[2] > 10);

        aluno[y].media = (aluno[y].nota[0] + aluno[y].nota[1] + aluno[y].nota[2])/3;
        printf("Media: %.1f\n", aluno[y].media);

        fwrite(aluno, *maxAlunos*sizeof(TAluno), 1, arquivo);
        fclose(arquivo);
    }

    funcaoOrganiza(MAX_TITULO, '-');
}

void listarAlunos(TAluno *aluno, FILE *arquivo, int maxAlunos)
{
    int i;

    //printf("\nmaxAlunos = %d\n", maxAlunos);
    arquivo = fopen("arquivo.txt","rb");
    fread(aluno, maxAlunos*sizeof(TAluno), 1, arquivo);

    funcaoTitulo("LISTA DE ALUNOS");
    for(i = 0; i < maxAlunos; i++)
    {
        printf("Nome: %s\n", aluno[i].nome);
        printf("Matricula: %d\n", aluno[i].matricula);
        printf("Primeira nota: %.1f\n", aluno[i].nota[0]);
        printf("Primeira nota: %.1f\n", aluno[i].nota[1]);
        printf("Primeira nota: %.1f\n", aluno[i].nota[2]);
        printf("Media: %.1f\n", aluno[i].media);
        printf("Faltas: %d\n", aluno[i].faltas);
        funcaoOrganiza(MAX_TITULO, '-');
    }
    fclose(arquivo);
}

void menu(TAluno *aluno, FILE *arquivo, int maxAlunos)
{
    char o;
    int y = 0;

    while (o != '8')
    {
        funcaoTitulo("MENU");
        printf("1 - Inserir dados de um aluno\n");
        printf("2 - Remover dados de um aluno de acordo com sua matricula\n");
        printf("3 - Alterar dados de um aluno\n");
        printf("4 - Consultar dados de um aluno\n");
        printf("5 - Reordenar o arquivo de alunos\n");
        printf("6 - Listar alunos\n");
        printf("7 - Imprimir relatorio\n");
        printf("8 - Sair\n");
        funcaoOrganiza(MAX_TITULO, '-');
        scanf("%c", &o);
        fflush(stdin);
        system("CLS");
        switch(o)
        {
            case '1':
                inserirAluno(aluno, arquivo, y, &maxAlunos);
                y = y + 1;
                getch();
                break;
            case '2':
                //removerAluno(aluno, numeroAlunos);
                getch();
                break;
            case '3':
                //listarAprovados(aluno, numeroAlunos);
                getch();
                break;
            case '4':
                //reprovadosFalta(aluno, numeroAlunos);
                getch();
                break;
            case '5':
                //reprovadosDesempenho(aluno, numeroAlunos);
                getch();
                break;
            case '6':
                listarAlunos(aluno, arquivo, maxAlunos);
                getch();
                break;
            case '7':

                getch();
                break;
            case '8':
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
    FILE *arquivo;
    TAluno *aluno;
    int maxAlunos = 1;

    aluno = (TAluno*) malloc(sizeof(TAluno));

    if(aluno == NULL)
    {
        printf("Erro na alocacao de memoria!!!");
    }
    else
    {
        menu(aluno, arquivo, maxAlunos);
    }

    free(aluno);
    aluno = NULL;

    return 0;
}
