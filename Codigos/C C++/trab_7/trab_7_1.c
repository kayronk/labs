#include <stdio.h>    //windows
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 50

int verificaPalindromo(char string[MAX_STRING])
{
    int tamanhoString, k;
    char stringAux[MAX_STRING];

    tamanhoString = strlen(string);
    if(tamanhoString == 0 || tamanhoString == 1)
    {
        return 1;
    }

    if(string[0] != string[tamanhoString - 1])
    {
        return 0;
    }
    else
    {
        strcpy(stringAux, string);
        for(k = 0; k < tamanhoString-1; k++)
        {
            if(k+2 == tamanhoString)
            {
                string[k] = '\0';
                break;
            }
            string[k] = stringAux[k+1];
        }
        verificaPalindromo(string);
    }

    return 1;
}

int palindromo(char string[MAX_STRING])
{
    int tamanhoString, existe = 0, k,i = 0,z;
    int resultado;
    char stringAux[MAX_STRING];

    tamanhoString = strlen(string);

    for(k = 0; k < tamanhoString; k++)
    {
        if(string[k] != 'A' && string[k] != 'B' && string[k] != 'C' && string[k] != 'D' && string[k] != 'E' && string[k] != 'F' && string[k] != 'G' && string[k] != 'H' && string[k] != 'I' && string[k] != 'J' && string[k] != 'L' && string[k] != 'M' && string[k] != 'N' && string[k] != 'O' && string[k] != 'P' && string[k] != 'Q' && string[k] != 'L' && string[k] != 'S' && string[k] != 'T' && string[k] != 'U' && string[k] != 'V' && string[k] != 'X' && string[k] != 'Z' && string[k] != 'K' && string[k] != 'Y' && string[k] != 'W' && string[k] != 'R' && string[k] != 'a' && string[k] != 'b' && string[k] != 'c' && string[k] != 'd' && string[k] != 'e' && string[k] != 'f' && string[k] != 'g' && string[k] != 'h' && string[k] != 'i' && string[k] != 'j' && string[k] != 'l' && string[k] != 'm' && string[k] != 'n' && string[k] != 'o' && string[k] != 'p' && string[k] != 'q' && string[k] != 'l' && string[k] != 's' && string[k] != 't' && string[k] != 'u' && string[k] != 'v' && string[k] != 'x' && string[k] != 'z' && string[k] != 'k' && string[k] != 'y' && string[k] != 'w' && string[k] != 'r')
        {
            existe = existe + 1;
            if(existe > 0)
            {
                break;
            }
        }
    }

    if(existe == 0)  //nao existe caractere especial
    {
        resultado = verificaPalindromo(string);

    }
    else   //existe caractere especial
    {
        strcpy(stringAux, string);
        for(z = 0; z < tamanhoString; z++)
        {
           if(stringAux[z] == 'A' || stringAux[z] == 'B' ||  stringAux[z] == 'C' || stringAux[z] == 'D' || stringAux[z] == 'E' || stringAux[z] == 'F' || stringAux[z] == 'G' || stringAux[z] == 'H' || stringAux[z] == 'I' || stringAux[z] == 'J' || stringAux[z] == 'L' || stringAux[z] == 'M' || stringAux[z] == 'N' || stringAux[z] == 'O' || stringAux[z] == 'P' || stringAux[z] == 'Q' || stringAux[z] == 'R' || stringAux[z] == 'S' || stringAux[z] == 'T' || stringAux[z] == 'U' || stringAux[z] == 'V' || stringAux[z] == 'X' || stringAux[z] == 'Z' || stringAux[z] == 'K' || stringAux[z] == 'Y' || stringAux[z] == 'W' || stringAux[z] == 'a' || stringAux[z] == 'b' || stringAux[z] == 'c' || stringAux[z] == 'd' || stringAux[z] == 'e' || stringAux[z] == 'f' || stringAux[z] == 'g' || stringAux[z] == 'h' || stringAux[z] == 'i' || stringAux[z] == 'j' || stringAux[z] == 'l' || stringAux[z] == 'm' || stringAux[z] == 'n' || stringAux[z] == 'o' || stringAux[z] == 'p' || stringAux[z] == 'q' || stringAux[z] == 'r' || stringAux[z] == 's' || stringAux[z] == 't' || stringAux[z] == 'u' || stringAux[z] == 'v' || stringAux[z] == 'x' || stringAux[z] == 'z' || stringAux[z] == 'k' || stringAux[z] == 'y' || stringAux[z] == 'w')
           {
               string[i] = stringAux[z];
               i++;
           }
        }
        string[i] = '\0';
        resultado = verificaPalindromo(string);
    }

    return resultado;
}

int main()
{
    char string[MAX_STRING];
    int resultado;

    printf("String: ");
    gets(string);
    fflush(stdin);

    resultado = palindromo(string);

    if(resultado == 1)
    {
        printf("A string e um palindromo!!");
    }
    else
    {
        printf("A string nao e um palindromo!!");
    }

    return 0;
}
