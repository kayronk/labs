#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MATRIZ 10

void preecherMatriz(int sala[MAX_MATRIZ][MAX_MATRIZ])
{
    int i, j;

    for(i = 0; i < MAX_MATRIZ; i++)
    {
        for(j = 0; j < MAX_MATRIZ; j++)
        {
            sala[i][j] = 0;
        }
    }
}

void venderIngresso(int sala[MAX_MATRIZ][MAX_MATRIZ])
{
    int linhaAssento, colunaAssento, formaPagamento;

    do
    {
        printf("Informe a linha do assento desejado:");
        scanf("%d", &linhaAssento);
        __fpurge(stdin);
    }while(linhaAssento < 1 || linhaAssento > MAX_MATRIZ);

    do
    {
        printf("Informe a coluna do assento desejado:");
        scanf("%d", &colunaAssento);
        __fpurge(stdin);
    }while(colunaAssento < 1 || colunaAssento > MAX_MATRIZ);

    linhaAssento = linhaAssento - 1;
    colunaAssento = colunaAssento - 1;

    do
    {
        printf("-----------------------------\n");
        printf("Informe a forma de pagamento:\n");
        printf("1 - Meia-entrada\n");
        printf("2 - Inteira\n");
        printf("-----------------------------\n");
        scanf("%d", &formaPagamento);
        fflush(stdin);
    }while(formaPagamento < 1 || formaPagamento > 2);

    if(sala[linhaAssento][colunaAssento] == 0)
    {
        sala[linhaAssento][colunaAssento] = formaPagamento;
    }

    else
    {
        sala[linhaAssento][colunaAssento] = 0;
        printf("\nO assento foi liberado!");
    }
}

void resumoFinanceiro(int sala[MAX_MATRIZ][MAX_MATRIZ], float precoIngresso)
{
    int i, j, meiaPop = 0, inteiraPop = 0, meiaVip = 0, inteiraVip = 0, meiaComum = 0, inteiraComum = 0;
    int k, l, a, b, assentosVagos = 0, totalInteiras = 0, totalMeias = 0;
    float precoVip, precoPop, meiaIngresso;
    float meiaPreco_pop, meiaPreco_vip, totalComum, totalVip, totalPop, totalGeral;

    for(i = 0; i <= 1; i++)
    {
        for(j = 0; j < MAX_MATRIZ; j++)
        {
            if(sala[i][j] == 1)
            {
                meiaPop = meiaPop + 1;
            }
            else if(sala[i][j] == 2)
            {
               inteiraPop = inteiraPop + 1;
            }
        }
    }

    for(k = 4; k <= 7; k++)
    {
        for(l = 2; l <= 7; l++)
        {
            if(sala[k][l] == 1)
            {
                meiaVip = meiaVip + 1;
            }
            else if(sala[k][l] == 2)
            {
               inteiraVip = inteiraVip + 1;
            }
        }
    }

    for(a = 0; a < MAX_MATRIZ; a++)
    {
        for(b = 0; b < MAX_MATRIZ; b++)
        {
            if(sala[a][b] == 0)
            {
                assentosVagos = assentosVagos + 1;
            }
            else if(sala[a][b] == 1)
            {
                totalMeias = totalMeias + 1;
            }
            else if(sala[a][b] == 2)
            {
                totalInteiras = totalInteiras + 1;
            }
        }
    }

    meiaComum = totalMeias - (meiaVip + meiaPop);
    inteiraComum = totalInteiras - (inteiraVip + inteiraPop);

    precoPop = precoIngresso*0.75;
    meiaPreco_pop = precoPop/2;
    precoVip = precoIngresso*1.3;
    meiaPreco_vip = precoVip/2;
    meiaIngresso = precoIngresso/2;

    totalComum = (precoIngresso*inteiraComum) + (meiaIngresso*meiaComum);
    totalVip = (inteiraVip*precoVip) + (meiaVip*meiaPreco_vip);
    totalPop = (inteiraPop*precoPop) + (meiaPop*meiaPreco_pop);

    totalGeral = totalComum + totalVip + totalPop;

    printf("---------------------RESUMO FINANCEIRO------------------------------\n");
    printf("Preco do Ingresso: %.2f reais (comum), %.2f (popular), %.2f (VIP)\n", precoIngresso, precoPop, precoVip);
    printf("Ingresssos populares:\n");
    printf("%d inteiras, %d meia. Total: %.2f reais\n", inteiraPop, meiaPop, totalPop);
    printf("Ingressos comum:\n");
    printf("%d inteiras, %d meia. Total: %.2f reais\n", inteiraComum, meiaComum, totalComum);
    printf("Ingressos VIP:\n");
    printf("%d inteiras, %d meia. Total: %.2f reais\n", inteiraVip, meiaVip, totalVip);
    printf("TOTAL GERAL:%.2f\n", totalGeral);
    printf("--------------------------------------------------------------------\n");
    printf("Numero de assentos vagos:%d\n", assentosVagos);
    printf("Numero de meias:%d\n", totalMeias);
    printf("Numero de inteiras:%d\n", totalInteiras);
    printf("--------------------------------------------------------------------\n");
}
void exibirSala(int sala[MAX_MATRIZ][MAX_MATRIZ], float precoIngresso)
{
    int k, i, j;

    printf("-------MAPA DO CINEMA--------");
    printf("\n  ");

    for(k = 1; k <= MAX_MATRIZ; k++)
    {
        printf("%d ", k);
    }
    printf("\nA ");

    for(i = 0; i < MAX_MATRIZ; i++)
    {
        for(j = 0; j < MAX_MATRIZ; j++)
        {
            printf("%d ", sala[i][j]);

            if(i == 0 && j == 9)
            {
                printf("\nB ");
            }
            else if(i == 1 && j == 9)
            {
                printf("\nC ");
            }
            else if(i == 2 && j == 9)
            {
                printf("\nD ");
            }
            else if(i == 3 && j == 9)
            {
                printf("\nE ");
            }
            else if(i == 4 && j == 9)
            {
                printf("\nF ");
            }
            else if(i == 5 && j == 9)
            {
                printf("\nG ");
            }
            else if(i == 6 && j == 9)
            {
                printf("\nH ");
            }
            else if(i == 7 && j == 9)
            {
                printf("\nI ");
            }
            else if(i == 8 && j == 9)
            {
                printf("\nJ ");
            }
        }
    }
    printf("\n\n");

    resumoFinanceiro(sala, precoIngresso);
}

void menu(int sala[MAX_MATRIZ][MAX_MATRIZ], float precoIngresso)
{
    char o;

    printf("Escolha uma opcao:\n");

    while (o != '3')
    {
        printf("------------Menu------------- \n");
        printf("1 - Vender ou liberar assento\n");
        printf("2 - Resumo da ocupacao\n");
        printf("3 - Sair\n");
        printf("-----------------------------\n");
        scanf("%c", &o);
        __fpurge(stdin);
        switch(o)
        {
            case '1':
                venderIngresso(sala);
               getchar();
                break;
            case '2':
                exibirSala(sala, precoIngresso);
                getchar();
                break;
            case '3':
                printf("Voce digitou a opcao que finaliza o programa.\n\n");
                getchar();
                break;
            default:
                printf("Opcao invalida!\n");
                getchar();
        }
        system("clear");
        __fpurge(stdin);
    }
}

int main()
{
    int sala[MAX_MATRIZ][MAX_MATRIZ];
    float precoIngresso;

    do
    {
        printf("Informe o preco do ingresso:");
        scanf("%f", &precoIngresso);
        __fpurge(stdin);
    }while(precoIngresso < 0);

    preecherMatriz(sala);
    menu(sala, precoIngresso);

    return 0;
}
