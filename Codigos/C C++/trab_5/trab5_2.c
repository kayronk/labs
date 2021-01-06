#include <stdio.h>   //windows
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 50
#define MAX_TITULO 60

typedef struct TAluno
{
    int matricula;
    char nome[MAX_STRING];
    float notas[3];
    int faltas;
}TAluno;

TAluno *realoca(TAluno *aluno, int *numeroAlunos)
{
    aluno = (TAluno*) realloc(aluno, (*numeroAlunos*sizeof(TAluno)));

    if(aluno == NULL)
    {
        printf("Erro na alocação de memoria!!");
    }
    else
    {
        return aluno;
    }
}

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

void listaVazia(TAluno *aluno, int numeroAlunos)
{
    int i, j, k, l, z, a, b;

    for(z = 0; z < numeroAlunos; z++)
    {
        aluno[z].faltas = -1;
        aluno[z].matricula = -1;
    }

    for(i = 0; i < numeroAlunos; i++)
    {
        for(j = 0; j < 3; j++)
        {
            aluno[i].notas[j] = -1;
        }
    }

   for(a = 0; a < numeroAlunos; a++)
    {
        for(b = 0; b < MAX_STRING; b++)
        {
            aluno[a].nome[b] = -1;
        }
    }
}

void inserirDados(TAluno *aluno, int *numeroAlunos)
{
    int k, w, y, j, vagas = 0, existe, opcao;

    funcaoTitulo("INSERIR DADOS");

    for(k = 0; k < *numeroAlunos; k++)
    {
        if(aluno[k].matricula == -1)
        {
            vagas = vagas + 1;

            printf("Informe o nome do aluno: ");
            gets(aluno[k].nome);
            fflush(stdin);

            do
            {
                printf("Informe a matricula do aluno: ");
                scanf("%d", &aluno[k].matricula);
                fflush(stdin);
                existe = 0;
                for(w = 0; w < *numeroAlunos; w++)
                {
                    if(aluno[w].matricula == aluno[k].matricula)
                    {
                        existe = existe + 1;
                    }
                }
            }while(existe > 1);

            do
            {
                printf("Informe a quantidade de faltas aluno: ");
                scanf("%d", &aluno[k].faltas);
                fflush(stdin);
            }while(aluno[k].faltas < 0);

            do
            {
                printf("Informe a primeira nota do aluno: ");
                scanf("%f", &aluno[k].notas[0]);
                fflush(stdin);
            }while(aluno[k].notas[0] < 0 || aluno[k].notas[0] > 10);

            do
            {
                printf("Informe a segunda nota do aluno: ");
                scanf("%f", &aluno[k].notas[1]);
                fflush(stdin);
            }while(aluno[k].notas[1] < 0 || aluno[k].notas[1] > 10);

            do
            {
                printf("Informe a terceira nota do aluno: ");
                scanf("%f", &aluno[k].notas[2]);
                fflush(stdin);
            }while(aluno[k].notas[2] < 0 || aluno[k].notas[2] > 10);
            break;
        }
    }
    if(vagas == 0)
    {
        printf("Desculpe professor, nao existem mais vagas na turma.\n");
        printf("Voce gostaria de dobrar a quantidade de cadastro de alunos?\n");
        printf("1 - Sim\n");
        printf("2 - Nao\n");
        scanf("%d", &opcao);
        fflush(stdin);
        if(opcao == 1)
        {
            *numeroAlunos = *numeroAlunos*2;
            aluno = realoca(aluno, numeroAlunos);

            for(y = *numeroAlunos/2; y < *numeroAlunos; y++)
            {
                aluno[y].faltas = -1;
                aluno[y].matricula = -1;
                for(j = 0; j < 3; j++)
                {
                    aluno[y].notas[j] = -1;
                    aluno[y].nome[j] = -1;
                }
            }
        }
    }
    funcaoOrganiza(MAX_TITULO, '-');
}

void removerAluno(TAluno *aluno, int numeroAlunos)
{
    int k, z, y, matricula, quantFaltas, cont = 0;
    float priNota, segNota, terNota;

    funcaoTitulo("REMOVER ALUNO");
    printf("Informe a matricula do aluno:\n");
    scanf("%d", &matricula);
    fflush(stdin);

    for(k = 0; k < numeroAlunos; k++)
    {
        if(aluno[k].matricula == matricula)
        {
            cont = cont + 1;
            for(y = 0; y < MAX_STRING; y++)
            {
                aluno[k].nome[y] = -1;
            }
            aluno[k].matricula = -1;
            aluno[k].notas[0] = -1;
            aluno[k].notas[1] = -1;
            aluno[k].notas[2] = -1;
            aluno[k].faltas = -1;

            printf("Aluno removido com sucesso!\n");
            funcaoOrganiza(MAX_TITULO, '-');
            break;
        }
    }
    if(cont == 0)
    {
        printf("Desculpe professor, mas essa matricula nao existe!\n");
    }

}

TAluno *vetor_aprovados(TAluno *aluno, int numeroAlunos, int *totalAprovados)
{
    TAluno *aprovados;
    int k, z;
    float media;

    aprovados = (TAluno*) malloc(*totalAprovados*sizeof(TAluno));

    if(aprovados == NULL)
    {
        printf("Erro na alocação de memoria!!");
    }
    else
    {
        for(k = 0; k < numeroAlunos; k++)
        {
            media = (aluno[k].notas[0] + aluno[k].notas[1] + aluno[k].notas[2])/3;
            if((media >= 7) && (aluno[k].faltas <= 10))
            {
                strcpy(aprovados[k].nome, aluno[k].nome);
                aprovados[k].matricula = aluno[k].matricula;
                aprovados[k].faltas = aluno[k].faltas;
                aprovados[k].notas[0] = aluno[k].notas[0];
                aprovados[k].notas[1] = aluno[k].notas[1];
                aprovados[k].notas[2] = aluno[k].notas[2];
            }
        }
        return aprovados;
    }
    free(aprovados);
    aprovados = NULL;
}

TAluno *vetor_reprovados(TAluno *aluno, int numeroAlunos, int *totalReprovados)
{
    TAluno *reprovados;
    int k;
    float media;

    reprovados = (TAluno*) malloc(*totalReprovados*sizeof(TAluno));

    if(reprovados == NULL)
    {
        printf("Erro na alocação de memoria!!");
    }
    else
    {
        for(k = 0; k < numeroAlunos; k++)
        {
            media = (aluno[k].notas[0] + aluno[k].notas[1] + aluno[k].notas[2])/3;
            if((media < 7) && (media >= 0) && (aluno[k].faltas <= 10))
            {
                strcpy(reprovados[k].nome, aluno[k].nome);
                reprovados[k].matricula = aluno[k].matricula;
                reprovados[k].faltas = aluno[k].faltas;
                reprovados[k].notas[0] = aluno[k].notas[0];
                reprovados[k].notas[1] = aluno[k].notas[1];
                reprovados[k].notas[2] = aluno[k].notas[2];
            }
        }
        return reprovados;
    }
    free(reprovados);
    reprovados = NULL;
}

TAluno *vetor_reprovadosFalta(TAluno *aluno, int numeroAlunos, int *totalReprovadosFalta)
{
    TAluno *reprovadosFalta ;
    int k;

    reprovadosFalta = (TAluno*) malloc(*totalReprovadosFalta*sizeof(TAluno));

    if(reprovadosFalta == NULL)
    {
        printf("Erro na alocação de memoria!!");
    }
    else
    {
        for(k = 0; k < numeroAlunos; k++)
        {
            if(aluno[k].faltas > 10)
            {
                strcpy(reprovadosFalta[k].nome, aluno[k].nome);
                reprovadosFalta[k].matricula = aluno[k].matricula;
                reprovadosFalta[k].faltas = aluno[k].faltas;
                reprovadosFalta[k].notas[0] = aluno[k].notas[0];
                reprovadosFalta[k].notas[1] = aluno[k].notas[1];
                reprovadosFalta[k].notas[2] = aluno[k].notas[2];
            }
        }
        return reprovadosFalta;
    }
    free(reprovadosFalta);
    reprovadosFalta = NULL;
}

void reprovadosDesempenho(TAluno *aluno, int numeroAlunos)
{
    int k, totalReprovados = 0;
    float media;
    TAluno *listaReprovados;

    funcaoTitulo("REPROVADOS POR DESEMPENHO");
    for(k = 0; k < numeroAlunos; k++)
    {
        media = (aluno[k].notas[0] + aluno[k].notas[1] + aluno[k].notas[2])/3;
        if((media < 7) && (media >= 0) && (aluno[k].faltas <= 10))
        {
            totalReprovados = totalReprovados + 1;
        }
    }

    listaReprovados = vetor_reprovados(aluno, numeroAlunos, &totalReprovados);
    listarAlunos(listaReprovados, numeroAlunos, totalReprovados);

    free(listaReprovados);
    listaReprovados = NULL;

    funcaoOrganiza(MAX_TITULO, '-');
}

void reprovadosFalta(TAluno *aluno, int numeroAlunos)
{
    int k, totalReprovadosFalta = 0;
    TAluno *listaReprovadosFalta;

    funcaoTitulo("REPROVADOS POR FALTA");
    for(k = 0; k < numeroAlunos; k++)
    {
        if(aluno[k].faltas > 10)
        {
            totalReprovadosFalta = totalReprovadosFalta + 1;
        }
    }
    listaReprovadosFalta = vetor_reprovadosFalta(aluno, numeroAlunos, &totalReprovadosFalta);
    listarAlunos(listaReprovadosFalta, numeroAlunos, totalReprovadosFalta);

    free(listaReprovadosFalta);
    listaReprovadosFalta = NULL;

    funcaoOrganiza(MAX_TITULO, '-');
}

void listarAprovados(TAluno *aluno, int numeroAlunos)
{
    int k, z, totalAprovados = 0;
    float media;
    TAluno *listaAprovados;

    funcaoTitulo("APROVADOS");
    for(k = 0; k < numeroAlunos; k++)
    {
        media = (aluno[k].notas[0] + aluno[k].notas[1] + aluno[k].notas[2])/3;
        if((media >= 7) && (aluno[k].faltas <= 10))
        {
            totalAprovados = totalAprovados + 1;
        }
    }
    listaAprovados = vetor_aprovados(aluno, numeroAlunos, &totalAprovados);
    listarAlunos(listaAprovados, numeroAlunos, totalAprovados);

    free(listaAprovados);
    listaAprovados = NULL;

    funcaoOrganiza(MAX_TITULO, '-');
}

void listarAlunos(TAluno *lista, int numeroAlunos, int numeroListados)
{
    int k;

    if(numeroListados > 0)
    {
        for(k = 0; k < numeroListados; k++)
        {
            funcaoOrganiza(MAX_TITULO, '-');
            printf("Nome: %s - Matricula: %d\n", lista[k].nome, lista[k].matricula);
            printf("Notas: %.1f %.1f %.1f - Media: %.1f\n", lista[k].notas[0], lista[k].notas[1], lista[k].notas[2], (lista[k].notas[0]+lista[k].notas[1]+lista[k].notas[2])/3);
            printf("Faltas: %d\n", lista[k].faltas);
        }
    }
    funcaoOrganiza(MAX_TITULO, '-');
}

void menu(TAluno *aluno, int numeroAlunos)
{
    char o;
    int numeroListados, i, alunosMatriculados = 0;

    while (o != '7')
    {
        funcaoTitulo("MENU");
        printf("1 - Inserir dados de um aluno\n");
        printf("2 - Remover dados de um aluno de acordo com sua matricula\n");
        printf("3 - Listar alunos aprovados\n");
        printf("4 - Listar alunos reprovados por falta\n");
        printf("5 - Listar alunos reprovados por desempenho\n");
        printf("6 - Listar alunos\n");
        printf("7 - Sair\n");
        funcaoOrganiza(MAX_TITULO, '-');
        scanf("%c", &o);
        fflush(stdin);
        switch(o)
        {
            case '1':
                inserirDados(aluno, &numeroAlunos);
                getch();
                break;
            case '2':
                removerAluno(aluno, numeroAlunos);
                getch();
                break;
            case '3':
                listarAprovados(aluno, numeroAlunos);
                getch();
                break;
            case '4':
                reprovadosFalta(aluno, numeroAlunos);
                getch();
                break;
            case '5':
                reprovadosDesempenho(aluno, numeroAlunos);
                getch();
                break;
            case '6':
                for(i = 0; i < numeroAlunos; i++)
                {
                    if(aluno[i].matricula != -1)
                    {
                        alunosMatriculados = alunosMatriculados + 1;
                    }
                }
                funcaoTitulo("LISTA DE ALUNOS");
                do
                {
                    printf("Informe a quantidade que voce quer listar:");
                    scanf("%d", &numeroListados);
                    fflush(stdin);
                }while(numeroListados > numeroAlunos || numeroListados < 0 || numeroListados > alunosMatriculados);
                listarAlunos(aluno, numeroAlunos, numeroListados);
                getch();
                break;
            case '7':
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
    TAluno *aluno;
    int numeroAlunos;

    do
    {
        printf("Informe a quantidade de alunos a serem cadastrados: ");
        scanf("%d", &numeroAlunos);
        fflush(stdin);
    }while(numeroAlunos < 1);

    aluno = (TAluno*) malloc(numeroAlunos*sizeof(TAluno));

    if(aluno == NULL)
    {
        printf("Erro na alocacao de memoria!!");
    }
    else
    {
        listaVazia(aluno, numeroAlunos);
        menu(aluno, numeroAlunos);
        free(aluno);
        aluno = NULL;
    }

    return 0;
}
