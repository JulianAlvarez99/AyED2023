#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "charset.h"


charset_t* charset_init(charset_t* ptr, int quantity)
{
    ptr = (charset_t*)calloc(quantity,sizeof(charset_t));
    if(ptr == NULL)
    {
        perror("\n Error ");
        exit(-12);
    }
    ptr->lenght = 0;

    return ptr;
}


void charset_free(charset_t* ptr) /**LIBERA LA MEMORIA DE LOS PUNTEROS DE TIPO ESTRUCTURA UTILIZADOS EN EL PROGRAMA**/
{
    free(ptr);
}

/*SI EL CARACTER SE ENCUENTRA EN EL SET DEVUELVE LA POSICION DEL CARACTER, SI NO PERTENECE DEVUELVE 0*/
int charset_check(charset_t* ptr, int index, char c)
{
    int loop = 0;
    int check = 0;

    while((loop < ptr[index].lenght) && (ptr[index].str[loop]!= c))
    {
        loop ++;
    }
    if(loop < ptr[index].lenght)
    {
        check = 1;
    }

    return check;
}



void charset_add(charset_t* ptr, char c, int index)
{
    int check = 0;

    for(int loop = 0; loop <= index; loop++)
    {
        check = charset_check(ptr,loop,c);

        if(check!=1)
        {
            ptr[loop].str[ptr[loop].lenght] = c;
            ptr[loop].lenght++;
        }
    }
}


void charset_remove(charset_t* ptr, char c, int index)
{
    int check = 0;

    for(int loop = 0; loop < index; loop++)
    {
        check = charset_check(ptr,loop,c);

        if(!check)
        {
            ptr[loop].str[check] = '0';

            for(int i = check; i<ptr[loop].lenght-1; i++)
            {
                ptr[loop].str[check] = ptr[loop].str[check+1];
            }
            ptr[loop].lenght -= 1;

        }
    }
}


void charset_union(charset_t* ptr_1, char* ptr_2, int index)
{
    int i = 0;

    if(ptr_2 == NULL)
    {
        puts("No existe un una cadena de caracteres para unir \n");
    }

    while(ptr_2[i] != '\0')
    {
        charset_add(ptr_1,ptr_2[i], index);
        i++;
    }
}

char charset_intersection(charset_t* ptr_1, char* ptr_2, int index)
{
    int i,j = 0;
    int check = 0;
    char ptr_inter[MAX] = {0};

    if(ptr_2 == NULL)
    {
        puts("No existe un una cadena de caracteres para intersectar \n");
    }

    while(ptr_2[i] != '\0')
    {
        check = charset_check(ptr_1, index,ptr_2[i]);
        if(!check)
        {
            ptr_inter[j] = ptr_2[i];
            j++;
        }
        i++;
    }
    return *ptr_inter;
}

void charset_add_range (charset_t *ptr,unsigned char a, unsigned char b, int index) //AGREGA EN UN RANGO DE CARACATERES PERTENECIENTES AL ASCII
{
    for (unsigned char i = a; i <= b; i++)
    {
        charset_add (ptr, i, index);
    }
}
