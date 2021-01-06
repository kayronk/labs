#include <stdio.h>
#include <stdlib.h>      //windows
#include <string.h>

struct TAluno
{
    int matricula;
    char nome[51];
    float nota[3];
    int faltas;
};

typedef struct TAluno Aluno;

typedef struct TArvore Arvore;

struct TArvore
{
    Aluno conteudo;
    Arvore* esq;
    Arvore* dir;
};

void funcaoOrganiza(int numero, char caractere)
{
    int k;

    for(k = 0; k < numero-1; k++)
    {
        printf("%c", caractere);
    }
    printf("\n");
}

int Menu()
{
    int op;

    system("CLS");
    printf("-------------------MENU-------------------\n");
    printf(" 1 - Inserir um novo aluno\n");
    printf(" 2 - Imprimir dados de alunos - in-order\n");
    printf(" 3 - Imprimir dados de alunos - pre-order\n");
    printf(" 4 - Imprimir dados de alunos - pos-order\n");
    printf(" 5 - Altura da arvore\n");
    printf(" 6 - Profundidade do no\n");
    printf(" 7 - Numero de nos-folha\n");
    printf(" 8 - Numero de nos-pai\n");
    printf(" 9 - Maior media\n");
    printf("10 - Arvore Balanceada\n");
    printf("11 - Sair\n");
    funcaoOrganiza(43, '-');
    scanf("%d", &op);

    return op;
}

Arvore* Inicializa()
{
    return NULL;
}

Aluno Novo_Aluno()
{
    Aluno novo;
    int cont;

    funcaoOrganiza(43, '-');
    printf("Digite a matricula do aluno: ");
    scanf("%d", &novo.matricula);
    printf("Digite o nome do aluno: ");
    fflush(stdin);
    gets(novo.nome);
    for(cont = 0; cont < 3; cont++)
    {
        do
        {
            printf("Digite a %dª nota do aluno: ", cont+1);
            scanf("%f", &novo.nota[cont]);
        }while((novo.nota[cont] < 0)||(novo.nota[cont] > 10));
    }
    printf("Digite o numero de faltas do aluno: ");
    scanf("%d", &novo.faltas);
    if(novo.faltas < 0)
        novo.faltas = 0;
    funcaoOrganiza(43, '-');

    return novo;
}

Arvore* Inserir_No(Arvore* arv, Aluno alu)
{
    Arvore* novo_no = (Arvore*)malloc(sizeof(Arvore));
    novo_no->conteudo = alu;
    novo_no->esq = novo_no->dir = NULL;
    Arvore *pred, *raiz = arv;

    if(arv == NULL)
        return novo_no;
    else
    {
        while(arv != NULL)
        {
            pred = arv;
            if(novo_no->conteudo.matricula < arv->conteudo.matricula)
                arv = arv->esq;
            else
                arv = arv->dir;
        }
        if(novo_no->conteudo.matricula > pred->conteudo.matricula)
            pred->dir = novo_no;
        else
            pred->esq = novo_no;

        return raiz;
    }
}

int Verificar_Matricula(Arvore *arv, int mat)
{
    if(arv->conteudo.matricula == mat)
        return 1;
    else
        return 0;
    if(mat > arv->conteudo.matricula)
        return Verificar_Matricula(arv->dir, mat);
    else
        return Verificar_Matricula(arv->esq, mat);
}

float Calcular_Media(Arvore* arv)
{
    float soma = 0;
    int i;

    for(i = 0; i < 3; i++)
    {
        soma = soma + arv->conteudo.nota[i];
    }

    return (soma / 3);
}

void Imprimir_Arvore(Arvore* arv)
{
    printf("Nome: %s\n", arv->conteudo.nome);
    printf("Matricula: %d\n", arv->conteudo.matricula);
    printf("Nota 1: %.1f\nNota 2: %.1f\nNota 3: %.1f\n", arv->conteudo.nota[0], arv->conteudo.nota[1], arv->conteudo.nota[2]);
    printf("Media: %.1f\n", Calcular_Media(arv));
    printf("Faltas: %d\n\n", arv->conteudo.faltas);
    funcaoOrganiza(43, '-');
}

void Erd(Arvore* arv)
{
    if(arv != NULL)
    {
        Erd(arv->esq);
        Imprimir_Arvore(arv);
        Erd(arv->dir);
    }
}

void Red(Arvore* arv)
{
    if(arv != NULL)
    {
        Imprimir_Arvore(arv);
        Erd(arv->esq);
        Erd(arv->dir);
    }
}

void Edr(Arvore* arv)
{
    if(arv != NULL)
    {
        Erd(arv->esq);
        Erd(arv->dir);
        Imprimir_Arvore(arv);
    }
}

int Altura(Arvore* arv)
{
    if(arv == NULL)
        return -1;
    else
    {
        int he = Altura(arv->esq);
        int hd = Altura(arv->dir);
        if(he < hd)
            return hd + 1;
        else
            return he + 1;
    }
}

int Nos_Pai(Arvore* arv)
{
    if(arv == NULL)
        return 0;
    if((arv->esq != NULL)||(arv->dir != NULL))
        return 1 + Nos_Pai(arv->esq) + Nos_Pai(arv->dir);
}

int Folhas(Arvore* arv)
{

   if(arv == NULL)
        return 0;
   if((arv->esq == NULL) && (arv->dir == NULL))
        return 1;

   return Folhas(arv->esq) + Folhas(arv->dir);
}

int Profundidade(Arvore *arv, int mat)
{
    if(arv != NULL )
    {
        if(arv->conteudo.matricula == mat)
            return 0;
        else
        {
            if(mat < arv->conteudo.matricula )
                return 1 + Profundidade(arv->esq, mat);
            if(mat > arv->conteudo.matricula)
                return 1 + Profundidade(arv->dir, mat);
        }
    }
    return -1;
}

Aluno Media(Arvore *arv)
{
    if((arv->dir)&&(Calcular_Media(arv->dir) > Calcular_Media(arv)))
        return Media(arv->dir);
    else
        return arv->conteudo;
    if((arv->esq)&&(Calcular_Media(arv->esq) > Calcular_Media(arv)))
        return Media(arv->esq);
    else
        return arv->conteudo;
}

int main()
{
    int opcao, matricula;
    Arvore* minha_arvore = Inicializa();
    Aluno alu;

    do
    {
        opcao = Menu();
        switch(opcao)
        {
            case 1:
                system("CLS");
                if(minha_arvore == NULL)
                    minha_arvore = Inserir_No(minha_arvore, Novo_Aluno());
                else
                {
                    alu = Novo_Aluno();
                    if(Verificar_Matricula(minha_arvore, alu.matricula) == 1)
                    {
                        printf("\nEssa matricula ja existe na arvore!!!!\n");
                        fflush(stdin);
                        getchar();
                    }
                    else
                        minha_arvore = Inserir_No(minha_arvore, alu);
                }
            break;

            case 2:
                system("CLS");
                if(minha_arvore != NULL)
                    Erd(minha_arvore);
                else
                    printf("\nA arvore esta vazia!!!\n");
                fflush(stdin);
                getchar();
            break;

            case 3:
                system("CLS");
                if(minha_arvore != NULL)
                    Red(minha_arvore);
                else
                    printf("\nA arvore esta vazia!!\n");
                fflush(stdin);
                getchar();
            break;

            case 4:
                system("CLS");
                if(minha_arvore != NULL)
                    Edr(minha_arvore);
                else
                    printf("\nA arvore esta vazia!!1\n");
                fflush(stdin);
                getchar();
            break;

            case 5:
                printf("\nA altura da arvore e: %d\n", Altura(minha_arvore));
                fflush(stdin);
                getchar();
            break;

            case 6:
                printf("\nMatricula do aluno: ");
                scanf("%d", &matricula);
                printf("\nA profundidade do no e: %d\n", Profundidade(minha_arvore, matricula));
                fflush(stdin);
                getchar();
            break;

            case 7:
                printf("\nO numero de nos-folha da arvore e: %d", Folhas(minha_arvore));
                fflush(stdin);
                getchar();
            break;

            case 8:
                system("CLS");
                printf("\nO numero de nos-pai da arvore e: %d", Nos_Pai(minha_arvore));
                fflush(stdin);
                getchar();
            break;

            case 9:
                alu = Media(minha_arvore);
                system("CLS");
                printf("\nAluno com maior media:\n");
                printf("Nome: %s\n", alu.nome);
                printf("Matricula: %d\n", alu.matricula);
                printf("Nota 1: %.1f\tNota 2: %.1f\tNota 3: %.1f\t", alu.nota[0], alu.nota[1], alu.nota[2]);
                printf("Media: %.1f\n", (alu.nota[0]+alu.nota[1]+alu.nota[2])/3);
                printf("Faltas: %d\n\n",  alu.faltas);
                fflush(stdin);
                getchar();
            break;

            case 11:
                free(minha_arvore);
                minha_arvore = NULL;
                printf("\nEncerrando programa!\n");
            break;
        }
    }while(opcao != 11);

    return 0;
}
