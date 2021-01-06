#include <stdio.h>               //windows
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 50
#define MAX_TITULO 70

struct aluno
{
    int matricula;
    char nome[MAX_STRING];
    float nota[3];
    float media;
    int faltas;
};

typedef struct aluno TAluno;

typedef struct lista Lista;

struct lista
{
    TAluno info;
    Lista* prox;
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

void free_lista(Lista* lst)
{
    if(lst != NULL)
    {
        free(lst);
        free_lista(lst->prox);
    }
}

int validar_matricula(int x, Lista* lst)
{
	Lista* ret;

	for(ret = lst; ret != NULL; ret = ret->prox)
	{
        if(ret->info.matricula == x)
        {
            return 1;
        }
	}
	return;
}

TAluno criaNovo(Lista* lst)
{
    TAluno novo;
    int existe;

    printf("Nome: ");
    gets(novo.nome);
    fflush(stdin);

    do
    {
        printf("Matricula: ");
        scanf("%d", &novo.matricula);
        fflush(stdin);
        existe = validar_matricula(novo.matricula, lst);
    }while(existe == 1);

    do
    {
        printf("Faltas: ");
        scanf("%d", &novo.faltas);
        fflush(stdin);
    }while(novo.faltas < 0);

    do
    {
        printf("Primeira nota: ");
        scanf("%f", &novo.nota[0]);
        fflush(stdin);
    }while(novo.nota[0] < 0 || novo.nota[0] > 10);

    do
    {
        printf("Segunda nota: ");
        scanf("%f", &novo.nota[1]);
        fflush(stdin);
    }while(novo.nota[1] < 0 || novo.nota[1] > 10);

    do
    {
        printf("Terceira nota: ");
        scanf("%f", &novo.nota[2]);
        fflush(stdin);
    }while(novo.nota[2] < 0 || novo.nota[2] > 10);

    novo.media = (novo.nota[0] + novo.nota[1] + novo.nota[2])/3;
    printf("Media: %.1f\n", novo.media);
    funcaoOrganiza(MAX_TITULO, '-');

    return novo;
}

Lista* cria_lista(void)
{
    return NULL;
}

int lista_vazia(Lista* lst)
{
    return (lst == NULL);
}

Lista* remover_lista(Lista* lst, int k)
{
    if (!lista_vazia(lst))
    {
        if (lst->info.matricula == k)
        {
            Lista* temporaria = lst;
            lst = lst->prox;
            free(temporaria);
        }
        else
        {
            lst->prox = remover_lista(lst->prox, k);
        }
    }
    return lst;
}

Lista* insere_inicio(Lista* lst, TAluno aluno)
{
	Lista* novo;

	novo = (Lista*) malloc(sizeof(Lista));

	if(novo == NULL)
	{
        printf("ERRO!!\n");
        return lst;
	}
	else
	{
        novo->info = aluno;
        novo->prox = lst;
	}

	return novo;
}

Lista* insere_fim(Lista* lst, TAluno aluno)
{
	Lista* novo;

	novo = (Lista*) malloc(sizeof(Lista));

	if(novo == NULL)
	{
        printf("ERRO!!");
        return lst;
	}

    novo->info = aluno;

    Lista* cauda = lst;
    Lista* cabeca = cauda;
    Lista* anterior = NULL;

    while(cauda != NULL)
    {
        anterior = cauda;
        cauda = cauda->prox;
    }
    if(anterior != NULL)
    {
        anterior->prox = novo;
        novo->prox = NULL;
    }
    else
    {
        return insere_inicio(lst, aluno);
    }

    return cabeca;
}

Lista* insere_ordenado(Lista* lst, TAluno aluno)
{
    Lista* novo;
    Lista* ant = NULL;
    Lista* p = lst;

    while(p != NULL && p->info.matricula < aluno.matricula)
    {
        ant = p ;
        p = p->prox;
    }

    novo = (Lista*)malloc(sizeof(Lista));

    if(novo == NULL)
	{
        printf("ERRO!!");
        return lst;
	}

    novo->info = aluno;
    if (ant == NULL)
    {
        novo->prox = lst;
        lst = novo;
    }
    else
    {
        novo->prox = ant->prox ;
        ant->prox = novo ;
    }
    return lst;
}

Lista* insere_indice(Lista* lst, Lista *p , TAluno aluno, int indice, int cont)
{
    Lista* novo;

    novo = (Lista*) malloc(sizeof(Lista));

    if(novo == NULL)
	{
        printf("ERRO!!");
        return lst;
	}
    if (indice == 1)
    {
        return insere_inicio(lst, aluno);
    }

    if (cont != (indice - 1))
    {
        cont++;
        p = p->prox;
        insere_indice(lst, p ,aluno , indice, cont);
    }
    else
    {
        Lista* ant = p;
        Lista* pos = p->prox;

        ant->prox = novo;

        novo->info = aluno;
        novo->prox = pos;
    }
    return lst;
}

int tamanho_lista(Lista* lst)
{
    if(lst == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + tamanho_lista(lst->prox);
    }
}

int indice_aluno(Lista* lst, int k)
{
    if(lst == NULL)
    {
        return 0;
    }
    else if(lst->info.matricula == k)
    {
        return 1;
    }

    else
    {
        return 1 + indice_aluno(lst->prox, k);
    }
}

void imprime(TAluno a)
{
    printf("Nome: %s\n", a.nome);
    printf("Matricula: %d\n", a.matricula);
    printf("Faltas: %d\n", a.matricula);
    printf("Primeira nota: %.1f\n", a.nota[0]);
    printf("Segunda nota: %.1f\n", a.nota[1]);
    printf("Terceira nota: %.1f\n", a.nota[2]);
    printf("Media: %.1f\n", a.media);
    funcaoOrganiza(MAX_TITULO, '-');
}

void imprime_lista(Lista* lst)
{
    if (lst == NULL)
    {
        return;
    }
        imprime(lst->info);
        imprime_lista (lst->prox);
}

Lista* buscar_dados(int x, Lista* lst)
{
    Lista* a;

    a = lst;
    if (a == NULL)
    {
        return NULL;
    }
    if (a->info.matricula == x)
    {
        imprime(a->info);
    }
    return buscar_dados(x, a->prox);
}

void bubbleSort(Lista* vetor, int tamanho)
{
    int k, y;
    Lista aux;
    Lista* p;

    for(y = tamanho-1; y >= 1; y--)
    {
        for(k = 0; k < y; k++)
        {
            if(vetor[k].info.matricula > vetor[k+1].info.matricula)
            {
                aux = vetor[k];
                vetor[k] = vetor[k+1];
                vetor[k+1] = aux;
            }
        }
    }
}

Lista* ordenar_lista(Lista* vetor, Lista* lst, Lista* p, int tamanho, int i)
{
    bubbleSort(vetor, tamanho);

    for(p = lst; p != NULL; p = p->prox)
    {
        p->info = vetor[i].info;
        i++;
    }
    if( p != NULL )
    {
        p->info = vetor[i].info;
        ordenar_lista(vetor, lst, p->prox, tamanho, i+1);
    }
    else
    {
        return lst;
    }
}

void criar_arquivo(Lista* lst, Lista* p)
{
    FILE* aptr;
    TAluno aluno;

    if( p != NULL)
    {
        aluno = p->info;
        fopen("arquivo.txt","a+b");
        fwrite(&aluno, sizeof(TAluno), 1, aptr);
        fclose(aptr);
        criar_arquivo(lst, p->prox);
    }
}

/*void ler_arquivo()
{

  Lista *primeiro, *ultimo, *p;
  TAluno aluno;


  primeiro = (Lista *)malloc(sizeof(Lista));
  primeiro->prox = NULL;
  ultimo = primeiro;


  FILE *fp;
  fp = fopen("arquivo.txt", "rb");
  if (fp != NULL)
    {
     fread(&item, sizeof(item), 1, fp);
     while (!feof(fp))
    {

       ultimo->prox = (Lista *)malloc(sizeof(Lista));
       ultimo = ultimo->prox;
       ultimo->item = item;
       ultimo->prox = NULL;

       fread(&aluno, sizeof(aluno), 1, fp);
     }
     fclose(fp);
  }*/

void menu()
{
    int tamanho, indice;
    int o;
    int op;
    int mat;
    TAluno aluno;
    Lista* minha_lista = cria_lista();

    while (o != 14)
    {
        funcaoTitulo("MENU");
        printf("1 - Inserir aluno no inicio da lista\n");
        printf("2 - Inserir aluno no final da lista\n");
        printf("3 - Inserir aluno em uma posicao especifica da lista\n");
        printf("4 - Inserir aluno de forma ordenada\n");
        printf("5 - Remover dados de um aluno de acordo com sua matricula\n");
        printf("6 - Consultar dados de um aluno de acordo com a matricula\n");
        printf("7 - Listar todos os alunos\n");
        printf("8 - Apresentar o numero de alunos cadastrados\n");
        printf("9 - Indicar o indice de acordo com seu numero de matricula\n");
        printf("10 - Re-inicializar a lista\n");
        printf("11 - Ordenar a lista de acordo com a ordem de matricula dos alunos cadastrados\n");
        printf("12 - Gerar um arquivo com os dados dos alunos\n");
        printf("13 - Carregar a lista a partir de um arquivo existente\n");
        printf("14 - Encerrar programa\n");
        funcaoOrganiza(MAX_TITULO, '-');
        scanf("%d", &o);
        fflush(stdin);
        system("CLS");
        switch(o)
        {
            case 1:
                funcaoTitulo("INSERIR ALUNO NO INICIO DA LISTA");
                aluno = criaNovo(minha_lista);
                minha_lista = insere_inicio(minha_lista, aluno);
                funcaoOrganiza(MAX_TITULO, '-');
                getch();
                break;
            case 2:
                funcaoTitulo("INSERIR ALUNO NO FIM DA LISTA");
                aluno = criaNovo(minha_lista);
                minha_lista = insere_fim(minha_lista, aluno);
                funcaoOrganiza(MAX_TITULO, '-');
                getch();
                break;
            case 3:
                funcaoTitulo("INSERIR ALUNO EM UM POSICAO ESPECIFICA");
                tamanho = tamanho_lista(minha_lista);
                printf("Total de alunos: %d\n", tamanho);
                do
                {
                    printf("Indice: ");
                    scanf("%d", &indice);
                    fflush(stdin);
                    funcaoOrganiza(MAX_TITULO, '-');
                }while(indice < 1 || indice > tamanho+1);
                aluno = criaNovo(minha_lista);
                Lista *p = minha_lista;
                minha_lista = insere_indice(minha_lista, p, aluno, indice, 1);
                funcaoOrganiza(MAX_TITULO, '-');
                getch();
                break;
            case 4:
                funcaoTitulo("INSERIR ALUNO DE FORMA ORDENADA");
                aluno = criaNovo(minha_lista);
                minha_lista = insere_ordenado(minha_lista, aluno);
                funcaoOrganiza(MAX_TITULO, '-');
                getch();
                break;
            case 5:
                funcaoTitulo("REMOVER ALUNO");
                if(!lista_vazia(minha_lista))
                {
                    printf("Matricula: ");
                    scanf("%d", &mat);
                    fflush(stdin);
                    minha_lista = remover_lista(minha_lista, mat);
                    funcaoOrganiza(MAX_TITULO, '-');
                }
                else
                {
                    printf("A lista esta vazia!!\n");
                    funcaoOrganiza(MAX_TITULO, '-');
                }
                getch();
                break;

            case 6:
                funcaoTitulo("BUSCA POR MATRICULA");
                printf("Matricula: ");
                scanf("%d", &mat);
                fflush(stdin);
                funcaoOrganiza(MAX_TITULO, '-');
                buscar_dados(mat, minha_lista);
                funcaoOrganiza(MAX_TITULO, '-');
                getch();
                break;

            case 7:
                funcaoTitulo("LISTA DE ALUNOS");
                imprime_lista(minha_lista);
                funcaoOrganiza(MAX_TITULO, '-');
                getch();
                break;

            case 8:
                funcaoTitulo("ALUNOS CADASTRADOS");
                printf("Total: %d\n", tamanho_lista(minha_lista));
                funcaoOrganiza(MAX_TITULO, '-');
                getch();
                break;

            case 9:
                funcaoTitulo("INDICE DO ALUNO");
                printf("Matricula: ");
                scanf("%d", &mat);
                fflush(stdin);
                funcaoOrganiza(MAX_TITULO, '-');
                printf("Indice do aluno: %d\n", indice_aluno(minha_lista, mat));
                funcaoOrganiza(MAX_TITULO, '-');
                getch();
                break;

            case 10:
                if(!lista_vazia(minha_lista))
                {
                    free_lista(minha_lista);
                    minha_lista = cria_lista();
                }
                printf("Lista de alunos re-inicializada!!\n");
                getch();
                break;

            case 11:
                funcaoTitulo("ORDENAR LISTA POR MATRICULA");
                tamanho = tamanho_lista(minha_lista);
                Lista *u = (Lista*) malloc(tamanho*sizeof(Lista));
                Lista *v = minha_lista;
                Lista *x = minha_lista;
                int i;
                for(i = 0; i < tamanho; i++)
                {
                    u[i] = *v;
                    v = v->prox;
                }
                minha_lista = ordenar_lista(u, minha_lista, x, tamanho, 0);
                free(u);
                printf("Lista ordenada!!\n");
                funcaoOrganiza(MAX_TITULO, '-');
                getch();
                break;

            case 12:
                funcaoTitulo("GERAR ARQUIVO");
                Lista *k = minha_lista;
                //criar_arquivo(minha_lista, k);
                funcaoOrganiza(MAX_TITULO, '-');
                getch();
                break;

            case 13:
                funcaoTitulo("CARREGAR ARQUIVO");
                //ler_arquivo(minha_lista);
                funcaoOrganiza(MAX_TITULO, '-');
                getch();
                break;

            case 14:
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
    menu();

    return 0;
}
