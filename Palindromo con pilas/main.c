#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDAStack.h"

/**Crear una función que recibe un string como parámetro y devuelve si el contenido es una frase palíndroma
(por ejemplo: “la ruta nos aportó otro paso natural” o “Anita lava la tina”).
Debe seleccionar y utilizar las estructuras adecuadas.
**/

char* removeSpacesFromStr(char *string)
{
    // Calculamos la longitud de la cadena sin espacios para determinar el tamaño necesario para la cadena resultante
    int length = strlen(string);
    int non_space_count = 0; // Contador para los caracteres que no son espacios

    // Contamos los caracteres que no son espacios
    for (int i = 0; i < length; i++)
    {
        if (string[i] != ' ')
        {
            non_space_count++;
        }
    }

    // Alocamos memoria para la cadena resultante
    char* aux = (char*)malloc((non_space_count + 1) * sizeof(char)); // Aseguramos espacio para el carácter nulo

    int j = 0; // Índice para la cadena resultante

    // Copiamos los caracteres que no son espacios a la cadena resultante
    for (int i = 0; i < length; i++)
    {
        if (string[i] != ' ')
        {
            aux[j++] = string[i];
        }
    }

    aux[j] = '\0'; // Agregamos el carácter nulo al final de la cadena resultante

    return aux;
}


int isPalidrome(char* phrase)
{
    phrase = removeSpacesFromStr(phrase);
    int length = strlen(phrase);
    stack* s = stack_new(length);
    char* phrase_inverted = (char*)malloc((length)*sizeof(char));


    for(int i = 0; i<length; i++)
    {
        push(s,&phrase[i]);
    }
    int index = 0;

    while(!stack_isempty(s))
    {
        phrase_inverted[index++] = *(char*)pop(s);
    }

    stack_destroy(s); // Liberamos la memoria de la pila
    return strcmp(phrase,phrase_inverted);
}


int main()
{
    int exit = 1;

    while( exit != 0)
    {
        char* word = (char*)malloc(sizeof(char)*100);
        fgets(word,100,stdin);
        if (word[strlen(word) - 1] == '\n')
        {
        word[strlen(word) - 1] = '\0';
        }
        printf("%d\n", isPalidrome(word));
        system("PAUSE");
        scanf("%d",&exit);
        system("CLS");
    }

    return 0;
}
