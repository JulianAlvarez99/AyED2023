#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "charset.h"

int main()
{
    charset_t* cs = NULL;
    int sets = 0;
    int check = 0;

    printf("Cantidad de sets a ingresar: ");
    scanf("%d",&sets);

    cs = charset_init(cs,sets);
    printf("\n");

    for(int i = 0; i<sets; i++)
    {
        printf("Ingrese el conjunto [%d]: ",i);
        scanf("%s", cs[i].str);
        cs[i].lenght = strlen(cs[i].str);
    }


    check = charset_check(cs,0,'a');

    printf("\nLa posicion del caracter comparado es: %d", check);

    printf("\nSize del primer conjunto %d",cs[0].lenght);

    charset_add(cs,'j',0);

    printf("\nSize del primer conjunto %d",cs[0].lenght);

    printf("\n");

    for (int i = 0; i< cs[0].lenght; i++)
    {
       printf("%c",cs[0].str[i]);
    }


    return 0;
}
