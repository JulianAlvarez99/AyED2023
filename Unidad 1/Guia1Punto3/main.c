#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 50

//ESPRMOCINA

int existe(char str[], int i)
{
    for (int j = i-1; j >= 0; j--)
    {
        if (str[i] == str[j])
        {
            return 1;
        }
    }
    return 0;

}

void contar_letras(char str[])
{
    for (int i = 0; str[i] != '\n'; i++)
    {
        if (!existe(str, i))
        {
            printf("%c ", str[i]);
        }
    }

}

int main()

{
    char str[MAX_SIZE];

    printf("Ingrese una cadena: ");

    fgets(str, MAX_SIZE, stdin);

    int lenght=sizeof(str)/sizeof(str[0]);

    for(int i = 0; i<lenght; i++)
    {
        str[i]=toupper(str[i]);
    }

    contar_letras(str);

    return 0;

}
