#include <stdio.h>       //windows
#include <string.h>
#define MAX_STRING 50

void converteString(char string[MAX_STRING])
{
    int k, j, count = 0;
    char auxiliar[2];

    strlwr(string);

    auxiliar[0] = string[0];
    auxiliar[1] = '\0';

    strupr(auxiliar);

    string[0] = auxiliar[0];

    for(k = 2; k < MAX_STRING; k++)
    {
        if(string[k-1] == ' ')
        {
            count = 0;

            for(j = k; j < MAX_STRING; j++)
            {
                if(string[j] == ' ' || string[j] == '\0')
                {
                    break;
                }
                count = count + 1;
            }

            if(count > 2)
            {
                auxiliar[0] = string[k];
                auxiliar[1] = '\0';
                strupr(auxiliar);
                string[k] = auxiliar[0];
            }
        }
    }

    printf("String: %s\n", string);
}

int main()
{
    char string[MAX_STRING];

    printf("Informe uma string: ");
    gets(string);

    converteString(string);

    return 0;
}
