#include<stdio.h>

int main()
{
    float valor, trocados, subtracao;;
    int notaCem, notaCinquenta, notaVinte, notaDez, notaCinco, notaDois, valorInt;
    int moedaReal, moedaCinquenta, moedaVintecinco, moedaDez, moedaCinco, moedaUm;

    do
    {
        printf("\nInforme um valor com no maximo duas casas decimais:");
        scanf("%f", &valor);
    }
    while(valor < 0 || valor >= 1000);

    //calculando numero de notas
    notaCem = valor/100;
    notaCinquenta = (valor - (notaCem*100))/50;
    notaVinte = (valor - ((notaCem*100) + (notaCinquenta*50)))/20;
    notaDez = (valor - ((notaCem*100) + (notaCinquenta*50) + (notaVinte*20)))/10;
    notaCinco = (valor - ((notaCem*100) + (notaCinquenta*50) + (notaVinte*20) + (notaDez*10)))/5;
    notaDois = (valor - ((notaCem*100) + (notaCinquenta*50) + (notaVinte*20) + (notaDez*10) + (notaCinco*5)))/2;

    //calculando numero de moedas

    moedaReal = (valor - ((notaCem*100) + (notaCinquenta*50) + (notaVinte*20) + (notaDez*10) + (notaCinco*5) + (notaDois*2)));

    valorInt = valor;
    trocados = valor - valorInt;    //separando a parte decimal do valor inserido

    moedaCinquenta = trocados/0.50;
    moedaVintecinco = (trocados - (moedaCinquenta*0.50))/0.25;
    moedaDez = (trocados - ((moedaCinquenta*0.50) + (moedaVintecinco*0.25)))/0.10;
    moedaCinco = (trocados - ((moedaCinquenta*0.50) + (moedaVintecinco*0.25) + (moedaDez*0.10)))/0.05;
    subtracao = (trocados - ((moedaCinquenta*0.50) + (moedaVintecinco*0.25) + (moedaDez*0.10) + (moedaCinco*0.05)))/0.01;
    moedaUm = round(subtracao); //foi preciso utilizar essa função para arredondar a subtração, a divisão acima não estava saindo exata

    printf("\nNOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", notaCem);
    printf("%d nota(s) de R$ 50.00\n", notaCinquenta);
    printf("%d nota(s) de R$ 20.00\n", notaVinte);
    printf("%d nota(s) de R$ 10.00\n", notaDez);
    printf("%d nota(s) de R$ 5.00\n", notaCinco);
    printf("%d nota(s) de R$ 2.00\n", notaDois);

    printf("\nMOEDAS:\n");
    printf("%d moedas(s) de R$ 1.00\n", moedaReal);
    printf("%d moedas(s) de R$ 0.50\n", moedaCinquenta);
    printf("%d moedas(s) de R$ 0.25\n", moedaVintecinco);
    printf("%d moedas(s) de R$ 0.10\n", moedaDez);
    printf("%d moedas(s) de R$ 0.05\n", moedaCinco);
    printf("%d moedas(s) de R$ 0.01\n", moedaUm);

    return 0;
}
