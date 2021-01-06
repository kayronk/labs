#include <stdio.h>     //windows

void formato_24(int horas, int minutos)
{
    int dezena;
    int unidade;

    dezena  = minutos/10;
    unidade = minutos%10;

    switch(horas)
    {
        case 0:
            printf("Zero horas");
            break;
        case 1:
            printf("Uma hora");
            break;
        case 2:
            printf("Duas horas");
            break;
        case 3:
            printf("Tres horas");
            break;
        case 4:
            printf("Quatro horas");
            break;
        case 5:
            printf("Cinco horas");
            break;
        case 6:
            printf("Seis horas");
            break;
        case 7:
            printf("Sete horas");
            break;
        case 8:
            printf("Oito horas");
            break;
        case 9:
            printf("Nove horas");
            break;
        case 10:
            printf("Dez horas");
            break;
        case 11:
            printf("Onze horas");
            break;
        case 12:
            printf("Doze horas");
            break;
        case 13:
            printf("Treze horas");
            break;
        case 14:
            printf("Quatorze horas");
            break;
        case 15:
            printf("Quinze horas");
            break;
        case 16:
            printf("Dezesseis horas");
            break;
        case 17:
            printf("Dezessete horas");
            break;
        case 18:
            printf("Dezoito horas");
            break;
        case 19:
            printf("Dezenove horas");
            break;
        case 20:
            printf("Vinte horas");
            break;
        case 21:
            printf("Vinte e uma horas");
            break;
        case 22:
            printf("Vinte e duas horas");
            break;
        case 23:
            printf("Vinte e tres horas");
            break;
    }

    if(minutos > 0 && minutos < 20)
    {
        printf(" e ");

        switch(minutos)
        {
            case 1:
                printf("um minuto");
            case 2:
                printf("dois minutos");
                break;
            case 3:
                printf("tres minutos");
                break;
            case 4:
                printf("quatro minutos");
                break;
            case 5:
                printf("cinco minutos");
                break;
            case 6:
                printf("seis minutos");
                break;
            case 7:
                printf("sete minutos");
                break;
            case 8:
                printf("oito minutos");
                break;
            case 9:
                printf("nove minutos");
                break;
            case 10:
                printf("dez minutos");
                break;
            case 11:
                printf("onze minutos");
                break;
            case 12:
                printf("doze minutos");
                break;
            case 13:
                printf("treze minutos");
                break;
            case 14:
                printf("quatorze minutos");
                break;
            case 15:
                printf("quinze minutos");
                break;
            case 16:
                printf("dezesseis minutos");
                break;
            case 17:
                printf("dezessete minutos");
                break;
            case 18:
                printf("dezoito minutos");
                break;
            case 19:
                printf("dezenove minutos");
                break;

        }
    }

    else if(minutos > 19 && unidade == 0)
    {
        printf(" e ");

        switch(dezena)
        {
            case 2:
                printf("vinte minutos");
                break;
            case 3:
                printf("trinta minutos");
                break;
            case 4:
                printf("quarenta minutos");
                break;
            case 5:
                printf("cinquenta minutos");
                break;
        }
    }

    else if(minutos > 19 && unidade > 0)
    {
        printf(" e ");

        switch(dezena)
        {
            case 2:
                printf("vinte e ");
                break;
            case 3:
                printf("trinta e ");
                break;
            case 4:
                printf("quarenta e ");
                break;
            case 5:
                printf("cinquenta e ");
                break;
        }

        switch(unidade)
        {
            case 1:
                printf("um minuto");
                break;
            case 2:
                printf("dois minutos");
                break;
            case 3:
                printf("tres minutos");
                break;
            case 4:
                printf("quatro minutos");
                break;
            case 5:
                printf("cinco minutos");
                break;
            case 6:
                printf("seis minutos");
                break;
            case 7:
                printf("sete minutos");
                break;
            case 8:
                printf("oito minutos");
                break;
            case 9:
                printf("nove minutos");
                break;
        }
    }
}

void formato_12(int horas, int minutos)
{
    int dezena;
    int unidade;

    dezena  = minutos/10;
    unidade = minutos%10;

    switch(horas)
    {
        case 0:
            printf("Doze horas");
            break;
        case 1:
            printf("Uma hora");
            break;
        case 2:
            printf("Duas horas");
            break;
        case 3:
            printf("Tres horas");
            break;
        case 4:
            printf("Quatro horas");
            break;
        case 5:
            printf("Cinco horas");
            break;
        case 6:
            printf("Seis horas");
            break;
        case 7:
            printf("Sete horas");
            break;
        case 8:
            printf("Oito horas");
            break;
        case 9:
            printf("Nove horas");
            break;
        case 10:
            printf("Dez horas");
            break;
        case 11:
            printf("Onze horas");
            break;
        case 12:
            printf("Doze horas");
            break;
        case 13:
            printf("Uma horas");
            break;
        case 14:
            printf("Duas horas");
            break;
        case 15:
            printf("Tres horas");
            break;
        case 16:
            printf("Quatro horas");
            break;
        case 17:
            printf("Cinco horas");
            break;
        case 18:
            printf("seis horas");
            break;
        case 19:
            printf("Sete horas");
            break;
        case 20:
            printf("Oito horas");
            break;
        case 21:
            printf("Nove horas");
            break;
        case 22:
            printf("Dez horas");
            break;
        case 23:
            printf("Onze horas");
            break;
    }

    if(minutos > 0 && minutos < 20)
    {
        printf(" e ");

        switch(minutos)
        {
            case 1:
                printf("um minuto");
            case 2:
                printf("dois minutos");
                break;
            case 3:
                printf("tres minutos");
                break;
            case 4:
                printf("quatro minutos");
                break;
            case 5:
                printf("cinco minutos");
                break;
            case 6:
                printf("seis minutos");
                break;
            case 7:
                printf("sete minutos");
                break;
            case 8:
                printf("oito minutos");
                break;
            case 9:
                printf("nove minutos");
                break;
            case 10:
                printf("dez minutos");
                break;
            case 11:
                printf("onze minutos");
                break;
            case 12:
                printf("doze minutos");
                break;
            case 13:
                printf("treze minutos");
                break;
            case 14:
                printf("quatorze minutos");
                break;
            case 15:
                printf("quinze minutos");
                break;
            case 16:
                printf("dezesseis minutos");
                break;
            case 17:
                printf("dezessete minutos");
                break;
            case 18:
                printf("dezoito minutos");
                break;
            case 19:
                printf("dezenove minutos");
                break;

        }
    }

    else if(minutos > 19 && unidade == 0)
    {
        printf(" e ");

        switch(dezena)
        {
            case 2:
                printf("vinte minutos");
                break;
            case 3:
                printf("trinta minutos");
                break;
            case 4:
                printf("quarenta minutos");
                break;
            case 5:
                printf("cinquenta minutos");
                break;
        }
    }

    else if(minutos > 19 && unidade > 0)
    {
        printf(" e ");

        switch(dezena)
        {
            case 2:
                printf("vinte e ");
                break;
            case 3:
                printf("trinta e ");
                break;
            case 4:
                printf("quarenta e ");
                break;
            case 5:
                printf("cinquenta e ");
                break;
        }

        switch(unidade)
        {
            case 1:
                printf("um minuto");
                break;
            case 2:
                printf("dois minutos");
                break;
            case 3:
                printf("tres minutos");
                break;
            case 4:
                printf("quatro minutos");
                break;
            case 5:
                printf("cinco minutos");
                break;
            case 6:
                printf("seis minutos");
                break;
            case 7:
                printf("sete minutos");
                break;
            case 8:
                printf("oito minutos");
                break;
            case 9:
                printf("nove minutos");
                break;
        }
    }

    if(0 <= horas && horas < 5)
    {
        printf(" da madrugada");
    }
    else if(5 <= horas && horas < 12)
    {
        printf(" da manha");
    }
    else if(12 <= horas && horas < 18)
    {
        printf(" da tarde");
    }
    else if(18 <= horas && horas < 24)
    {
        printf(" da noite");
    }
}

int main()
{
    int horas, minutos, formato;

    printf("----------------HORAS---------------\n");
    do
    {
        printf("Informe as horas:");
        scanf("%d", &horas);
    }
    while(horas < 0 || horas > 23);

    do
    {
        printf("Informe os minutos:");
        scanf("%d", &minutos);
    }
    while(minutos < 0 || minutos > 59);

    do
    {
        printf("Informe o formato das horas:\n1 - 24 horas\n2 - 12 horas\n");
        scanf("%d", &formato);
    }
    while(formato < 1 || formato > 2);

    printf("-----------------------------------\n");

    if(formato == 1)
    {
        formato_24(horas, minutos);
    }
    else
    {
        formato_12(horas, minutos);
    }

    return 0;
}
