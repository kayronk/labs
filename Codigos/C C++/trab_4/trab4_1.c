#include <stdio.h>               //windows
#include <stdlib.h>             //As funcoes comentadas foram utilizadas no linux
#include <string.h>
#define MAX_STRING 50
#define MAX_TITULO 50
#define MAX_PARTIDOS 10
#define MAX_DEPUTADOS 513

typedef struct TEstado
{
    char nome[MAX_STRING];
    char sigla[MAX_STRING];
}TEstado;

typedef struct TPartido
{
    char nome[MAX_STRING];
    char sigla[MAX_STRING];
}TPartido;

typedef struct TEstadoDeputado
{
    char nome[MAX_STRING];
    char sigla[MAX_STRING];
}TEstadoDeputado;

typedef struct TPartidoDeputado
{
    char nome[MAX_STRING];
    char sigla[MAX_STRING];
}TPartidoDeputado;

typedef struct TCongressista
{
    char nome[MAX_STRING];
    int matricula;
    int voto;
    int bancada;
    TPartidoDeputado partido;
    TEstadoDeputado estado;
}TCongressista;

void converteString(TCongressista deputado[MAX_DEPUTADOS], int z)
{
    int k, j, count = 0;
    char auxiliar[2];

    strlwr(deputado[z].nome);

    auxiliar[0] = deputado[z].nome[0];
    auxiliar[1] = '\0';

    strupr(auxiliar);

    deputado[z].nome[0] = auxiliar[0];

    for(k = 2; k < MAX_STRING; k++)
    {
        if(deputado[z].nome[k-1] == ' ')
        {
            count = 0;

            for(j = k; j < MAX_STRING; j++)
            {
                if(deputado[z].nome[j] == ' ' || deputado[z].nome[j] == '\0')
                {
                    break;
                }
                count = count + 1;
            }

            if(count > 2)
            {
                auxiliar[0] = deputado[z].nome[k];
                auxiliar[1] = '\0';
                strupr(auxiliar);
                deputado[z].nome[k] = auxiliar[0];
            }
        }
    }

    printf("%s\n", deputado[z].nome);
}

void funcaoOrganiza(int numero, char caractere)
{
    int k;

    for(k = 0; k < numero; k++)
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

void preencherEstados(TEstado estado[27])
{
    strcat(estado[0].nome, "Ceara");
    strcat(estado[1].nome, "Acre");
    strcat(estado[2].nome, "Alagoas");
    strcat(estado[3].nome, "Amapa");
    strcat(estado[4].nome, "Amazonas");
    strcat(estado[5].nome, "Bahia");
    strcat(estado[6].nome, "Distrito Federal");
    strcat(estado[7].nome, "Espirito Santo");
    strcat(estado[8].nome, "Goias");
    strcat(estado[9].nome, "Maranhao");
    strcat(estado[10].nome, "Mato-Grosso");
    strcat(estado[11].nome, "Mato Grosso do Sul");
    strcat(estado[12].nome, "Minas Gerais");
    strcat(estado[13].nome, "Para");
    strcat(estado[14].nome, "Paraiba");
    strcat(estado[15].nome, "Parana");
    strcat(estado[16].nome, "Pernambuco");
    strcat(estado[17].nome, "Piaui");
    strcat(estado[18].nome, "Rio de Janeiro");
    strcat(estado[19].nome, "Rio Grande do Norte");
    strcat(estado[20].nome, "Rio Grande do Sul");
    strcat(estado[21].nome, "Rondonia");
    strcat(estado[22].nome, "Roraima");
    strcat(estado[23].nome, "Santa Catarina");
    strcat(estado[24].nome, "Sao Paulo");
    strcat(estado[25].nome, "Sergipe");
    strcat(estado[26].nome, "Tocantins");

    strcat(estado[0].sigla, "CE");
    strcat(estado[1].sigla, "AC");
    strcat(estado[2].sigla, "AL");
    strcat(estado[3].sigla, "AP");
    strcat(estado[4].sigla, "AM");
    strcat(estado[5].sigla, "BA");
    strcat(estado[6].sigla, "DF");
    strcat(estado[7].sigla, "ES");
    strcat(estado[8].sigla, "GO");
    strcat(estado[9].sigla, "MA");
    strcat(estado[10].sigla, "MT");
    strcat(estado[11].sigla, "MS");
    strcat(estado[12].sigla, "MG");
    strcat(estado[13].sigla, "PA");
    strcat(estado[14].sigla, "PB");
    strcat(estado[15].sigla, "PR");
    strcat(estado[16].sigla, "PE");
    strcat(estado[17].sigla, "PI");
    strcat(estado[18].sigla, "RJ");
    strcat(estado[19].sigla, "RN");
    strcat(estado[20].sigla, "RS");
    strcat(estado[21].sigla, "RO");
    strcat(estado[22].sigla, "RR");
    strcat(estado[23].sigla, "SC");
    strcat(estado[24].sigla, "SP");
    strcat(estado[25].sigla, "SE");
    strcat(estado[26].sigla, "TO");

}

void incluirPartido(TPartido partido[MAX_PARTIDOS], int k)
{
    funcaoTitulo("CADASTRAR PARTIDO");
    printf("Nome do partido: ");
    //fgets(partido[k].nome, MAX_STRING, stdin);
    //__fpurge(stdin);
    gets(partido[k].nome);
    fflush(stdin);

    printf("Sigla do partido: ");
    //fgets(partido[k].sigla, MAX_STRING, stdin);
    //__fpurge(stdin);
    gets(partido[k].sigla);
    fflush(stdin);
    strupr(partido[k].sigla);
    funcaoOrganiza(MAX_TITULO-1, '-');
}

void matriculaVazia(TCongressista deputado[MAX_DEPUTADOS])
{
    int k;

    for(k = 0; k < MAX_DEPUTADOS; k++)
    {
        deputado[k].matricula = -1;
    }
}

void votoVazio(TCongressista deputado[MAX_DEPUTADOS])
{
    int k;

    for(k = 0; k < MAX_DEPUTADOS; k++)
    {
        deputado[k].voto = -1;
    }
}

void incluirCongressista(TCongressista deputado[MAX_DEPUTADOS], TPartido partido[MAX_PARTIDOS], int y, TEstado estado[27])
{
    char siglaPartido[10], siglaEstado[10];
    int comparacaoPartido, comparacaoEstado, p, e, matricula, k, existe;

    funcaoTitulo("CADASTRAR CONGRESSISTA");
    printf("Nome: ");
    //fgets(deputado[y].nome, MAX_STRING, stdin);
    //__fpurge(stdin);
    gets(deputado[y].nome);
    fflush(stdin);

    do
    {
        existe = 0;
        do
        {
            printf("Matricula: ");
            scanf("%d", &matricula);
            //__fpurge(stdin);
            fflush(stdin);
        }while(matricula <= 0);

        for(k = 0; k <= y; k++)
        {
            if(deputado[k].matricula == matricula)
            {
                existe = existe + 1;
            }
        }
    }while(existe > 0);

    deputado[y].matricula = matricula;

    printf("Estado: ");
    //fgets(siglaEstado, 10, stdin);
    //__fpurge(stdin);
    gets(siglaEstado);
    strupr(siglaEstado);
    fflush(stdin);

    for(e = 0; e < 27; e++)
    {
        comparacaoEstado = strcmp(estado[e].sigla, siglaEstado);
        if(comparacaoEstado == 0)
        {
            strcat(deputado[y].estado.sigla, siglaEstado);
            strcat(deputado[y].estado.nome, estado[e].nome);
            break;
        }
    }

    do
    {
        printf("Bancada:\n");
        printf("1 - Ruralistas\n");
        printf("2 - Religiosos\n");
        printf("3 - Armamentistas\n");
        printf("4 - Sindicalistas\n");
        printf("5 - Maria vai com as outras\n");
        scanf("%d", &deputado[y].bancada);
        //__fpurge(stdin);
        fflush(stdin);
    }while(deputado[y].bancada < 1 || deputado[y].bancada > 5);


    printf("Partido: ");
    //fgets(siglaPartido, 10, stdin);
    //__fpurge(stdin);
    gets(siglaPartido);
    strupr(siglaPartido);
    fflush(stdin);

    for(p = 0; p < 10; p++)
    {
        comparacaoPartido = strcmp(siglaPartido, partido[p].sigla);
        if(comparacaoPartido == 0)
        {
            strcat(deputado[y].partido.sigla, siglaPartido);
            strcat(deputado[y].partido.nome, partido[p].nome);
            break;
        }
    }

    printf("Voto: Nao votou ainda.\n");
    funcaoOrganiza(MAX_TITULO-1, '-');
}

void exibirDeputado(TCongressista deputado[MAX_DEPUTADOS], int k)
{
    printf("Nome: ");
    converteString(deputado, k);
    printf("Matricula: %d\n", deputado[k].matricula);
    printf("Estado: %s\n", deputado[k].estado.nome);
    printf("Sigla do estado: %s\n", deputado[k].estado.sigla);
    switch(deputado[k].bancada)
    {
        case 1:
            printf("Bancada: Ruralista\n");
            break;
        case 2:
            printf("Bancada: Religiosa\n");
            break;
        case 3:
            printf("Bancada: Armamentista\n");
            break;
        case 4:
            printf("Bancada: Sindicalista\n");
            break;
        case 5:
            printf("Bancada: Maria vai com as outras\n");
            break;
    }
    printf("Partido: %s\n", deputado[k].partido.nome);
    printf("Sigla do partido: %s\n", deputado[k].partido.sigla);
}

void realizarVoto(TCongressista deputado[MAX_DEPUTADOS])
{
    int numMatricula, voto, k;

    funcaoTitulo("REALIZAR VOTO");
    do
    {
        printf("Numero de matricula: ");
        scanf("%d", &numMatricula);
        fflush(stdin);
    }while(numMatricula < 0);
    funcaoOrganiza(MAX_TITULO-1, '-');

    for(k = 0; k < MAX_DEPUTADOS; k++)
    {
        if(numMatricula == deputado[k].matricula)
        {
            if(deputado[k].voto == -1)
            {
                funcaoTitulo("PERFIL");
                printf("Nome: ");
                converteString(deputado, k);
                printf(" - %s\n", deputado[k].estado.sigla);

                funcaoTitulo("VOTO");

                printf("0 - A favor\n");
                printf("1 - contra\n");
                printf("2 - Abstencao\n");
                funcaoOrganiza(MAX_TITULO-1, '-');
                scanf("%d", &voto);
                deputado[k].voto = voto;
                printf("Voto computado com sucesso!!\n");

                break;
            }
            else
            {
                printf("Sem maracutaia... este voto ja foi computado!!\n");
                funcaoOrganiza(MAX_TITULO-1, '-');
                break;
            }
        }
    }
    k = k + 1;
    if(k > MAX_DEPUTADOS)
    {
        printf("Voce digitou uma matricula que nao existe!!\n");
        funcaoOrganiza(MAX_TITULO-1, '-');
    }
}

void contabilizarVotacao(TCongressista deputado[MAX_DEPUTADOS], int modo)
{
    int k, umTerco;
    int contra = 0, aFavor = 0, abstencoes = 0, ausencias = 0;

    for(k = 0; k < MAX_DEPUTADOS; k++)
    {
        if(deputado[k].voto == -1)
        {
            ausencias = ausencias + 1;
        }
        else if(deputado[k].voto == 0)
        {
            aFavor = aFavor + 1;
        }
        else if(deputado[k].voto == 1)
        {
            contra = contra + 1;
        }
        else if(deputado[k].voto == 2)
        {
            abstencoes = abstencoes + 1;
        }
    }

    funcaoTitulo("CONTABILIZACAO DOS VOTOS");

    printf("A favor: %d\n", aFavor);
    printf("Contra: %d\n", contra);
    printf("Abstencoes: %d\n", abstencoes);
    printf("Ausencias: %d\n", ausencias);

    if(modo == 0)
    {
        printf("Indefinido modo de apuracao!\n");
    }
    else if(modo == 1)
    {
        if(aFavor > contra)
        {
            printf("Resultado: Aprovado\n");
        }
        else
        {
            printf("Resultado: Recusado\n");
        }
    }
    else if(modo == 2)
    {
        umTerco = (aFavor + contra)/3;
        if(contra <= umTerco)
        {
            printf("Resultado: Aprovado\n");
        }
        else
        {
            printf("Resultado: Recusado\n");
        }
    }

    funcaoOrganiza(MAX_TITULO-1, '-');
}

void contabilizarPartido(TCongressista deputado[MAX_DEPUTADOS])
{
    char siglaPartido[MAX_STRING];
    int k, comp;
    int contra = 0, aFavor = 0, abstencoes = 0, ausentes = 0;

    funcaoTitulo("CONTABILIZACAO POR PARTIDO");
    printf("Informe a sigla do partido: ");
    gets(siglaPartido);
    fflush(stdin);
    strupr(siglaPartido);
    funcaoOrganiza(MAX_TITULO, '-');

    for(k = 0; k < MAX_DEPUTADOS; k++)
    {
        comp = strcmp(siglaPartido, deputado[k].partido.sigla);
        if(comp == 0)
        {
            if(deputado[k].voto == -1)
            {
                ausentes = ausentes + 1;
            }
            else if(deputado[k].voto == 0)
            {
                aFavor = aFavor + 1;
            }
            else if(deputado[k].voto == 1)
            {
                contra = contra + 1;
            }
            else if(deputado[k].voto == 2)
            {
                abstencoes = abstencoes + 1;
            }

            exibirDeputado(deputado, k);
            if(deputado[k].voto == -1)
            {
                printf("voto: Ainda nao votou\n");
            }
            else if(deputado[k].voto == 0)
            {
                printf("voto: A favor\n");
            }
            else if(deputado[k].voto == 1)
            {
                printf("voto: Contra\n");
            }
            else if(deputado[k].voto == 2)
            {
                printf("voto: Abstencao\n");
            }

            funcaoOrganiza(MAX_TITULO-1, '-');
        }
    }
    printf("\n");
    funcaoTitulo("CONTABILIZACAO DOS VOTOS POR PARTIDO");

    printf("A favor: %d\n", aFavor);
    printf("Contra: %d\n", contra);
    printf("Abstencoes: %d\n", abstencoes);
    printf("Ausentes: %d\n", ausentes);
    funcaoOrganiza(MAX_TITULO, '-');
}

void contabilizarEstado(TCongressista deputado[MAX_DEPUTADOS])
{
    char siglaEstado[MAX_STRING];
    int k, comp;
    int contra = 0, aFavor = 0, abstencoes = 0, ausentes = 0;

    funcaoTitulo("CONTABILIZACAO POR ESTADO");
    printf("Informe a sigla do estado: ");
    gets(siglaEstado);
    fflush(stdin);
    strupr(siglaEstado);
    funcaoOrganiza(MAX_TITULO, '-');

    for(k = 0; k < MAX_DEPUTADOS; k++)
    {
        comp = strcmp(siglaEstado, deputado[k].estado.sigla);
        if(comp == 0)
        {
            if(deputado[k].voto == -1)
            {
                ausentes = ausentes + 1;
            }
            else if(deputado[k].voto == 0)
            {
                aFavor = aFavor + 1;
            }
            else if(deputado[k].voto == 1)
            {
                contra = contra + 1;
            }
            else if(deputado[k].voto == 2)
            {
                abstencoes = abstencoes + 1;
            }

            exibirDeputado(deputado, k);
            if(deputado[k].voto == -1)
            {
                printf("voto: Ainda nao votou\n");
            }
            else if(deputado[k].voto == 0)
            {
                printf("voto: A favor\n");
            }
            else if(deputado[k].voto == 1)
            {
                printf("voto: Contra\n");
            }
            else if(deputado[k].voto == 2)
            {
                printf("voto: Abstencao\n");
            }

            funcaoOrganiza(MAX_TITULO-1, '-');
        }
    }
    printf("\n");
    funcaoTitulo("CONTABILIZACAO DOS VOTOS POR ESTADO");

    printf("A favor: %d\n", aFavor);
    printf("Contra: %d\n", contra);
    printf("Abstencoes: %d\n", abstencoes);
    printf("Ausentes: %d\n", ausentes);
    funcaoOrganiza(MAX_TITULO-1, '-');
}

void contabilizarBancada(TCongressista deputado[MAX_DEPUTADOS])
{
    int k, comp, bancada;
    int contra = 0, aFavor = 0, abstencoes = 0, ausentes = 0;

    funcaoTitulo("CONTABILIZACAO POR BANCADA");
    printf("Bancada:\n");
    printf("1 - Ruralistas\n");
    printf("2 - Religiosos\n");
    printf("3 - Armamentistas\n");
    printf("4 - Sindicalistas\n");
    printf("5 - Maria vai com as outras\n");
    scanf("%d", &bancada);
    fflush(stdin);
    funcaoOrganiza(MAX_TITULO-1, '-');

    for(k = 0; k < MAX_DEPUTADOS; k++)
    {
        if(bancada == deputado[k].bancada)
        {
            if(deputado[k].voto == -1)
            {
                ausentes = ausentes + 1;
            }
            else if(deputado[k].voto == 0)
            {
                aFavor = aFavor + 1;
            }
            else if(deputado[k].voto == 1)
            {
                contra = contra + 1;
            }
            else if(deputado[k].voto == 2)
            {
                abstencoes = abstencoes + 1;
            }

            exibirDeputado(deputado, k);
            if(deputado[k].voto == -1)
            {
                printf("voto: Ainda nao votou\n");
            }
            else if(deputado[k].voto == 0)
            {
                printf("voto: A favor\n");
            }
            else if(deputado[k].voto == 1)
            {
                printf("voto: Contra\n");
            }
            else if(deputado[k].voto == 2)
            {
                printf("voto: Abstencao\n");
            }

            funcaoOrganiza(MAX_TITULO-1, '-');
        }
    }
    printf("\n");
    funcaoTitulo("CONTABILIZACAO DOS VOTOS POR BANCADA");

    printf("A favor: %d\n", aFavor);
    printf("Contra: %d\n", contra);
    printf("Abstencoes: %d\n", abstencoes);
    printf("Ausentes: %d\n", ausentes);
    funcaoOrganiza(MAX_TITULO-1, '-');
}

void menu(TCongressista deputado[MAX_DEPUTADOS], TPartido partido[MAX_PARTIDOS], TEstado estado[27])
{
    char o;
    int k = 0, y = 0, m = 0;
    int modo = 0;

    while (o != '9')
    {
        funcaoTitulo("MENU");
        printf("1 - Incluir partido\n");
        printf("2 - Incluir congressista\n");
        printf("3 - Realizar voto\n");
        printf("4 - Modo de contabilizacao dos votos\n");
        printf("5 - Contabiliziar votacao\n");
        printf("6 - Contabilizar votacao por partido\n");
        printf("7 - Contabilizar votacao por estado\n");
        printf("8 - Contabilizar votacao por bancada\n");
        printf("9 - Sair\n");
        funcaoOrganiza(MAX_TITULO-1, '-');
        scanf("%c", &o);
        //__fpurge(stdin);
        fflush(stdin);
        switch(o)
        {
            case '1':
                if(k < MAX_PARTIDOS)
                {
                    incluirPartido(partido, k);
                    k = k + 1;
                }
                else
                {
                    printf("Voce ja cadastrou o maximo de partidos possiveis!!");
                }
                getch();
                break;
            case '2':
                if(y < MAX_DEPUTADOS)
                {
                    incluirCongressista(deputado, partido, y, estado);
                    y = y + 1;
                }
                else
                {
                    printf("Voce ja cadastrou os 513 deputados!!");
                }
                getch();
                break;
            case '3':
                realizarVoto(deputado);
                getch();
                break;
            case '4':
                do
                {
                    funcaoTitulo("MODO DE CONTABILIZACAO");
                    printf("\n1 - Maioria Simples(Metade dos votos dos presentes +1)\n");
                    printf("2 - 2/3 dos votos validos\n");
                    scanf("%d", &modo);
                    fflush(stdin);
                    funcaoOrganiza(MAX_TITULO-1, '-');
                }while(modo < 1 || modo > 2);
                getch();
                break;
            case '5':
                contabilizarVotacao(deputado, modo);
                getch();
                break;
            case '6':
                contabilizarPartido(deputado);
                getch();
                break;
            case '7':
                contabilizarEstado(deputado);
                getch();
                break;
            case '8':
                contabilizarBancada(deputado);
                getch();
                break;
            case '9':
                printf("Voce digitou a opcao que finaliza o programa.");
                getch();
                break;
            default:
                printf("Opcao invalida!\n");
                getch();
        }
        //system("clear");
        //__fpurge(stdin);
        system("CLS");
        fflush(stdin);
    }
}

int main()
{
    TCongressista deputado[MAX_DEPUTADOS];
    TPartido partido[MAX_PARTIDOS];
    TEstado estado[27];

    matriculaVazia(deputado);
    votoVazio(deputado);
    preencherEstados(estado);
    menu(deputado, partido, estado);

    return 0;
}
