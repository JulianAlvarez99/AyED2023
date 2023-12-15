#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TDAMatrix.h"
#include "TDAVector.h"


int replace_row(matrix* m, int row, vector_t* v)
{
    int result = -1;

    if(vector_size(v) == matrix_columns(m))
    {
        for (int i = 0; i < matrix_columns(m); i++)
        {
            matrix_set(m, row, i, vector_get(v, i));
        }
        result = 0;
    }
    return result;
}

//Punto 4
int replace_column(matrix*m, int column, vector_t* v)
{
    int result = -1;

    if(vector_size(v) == matrix_rows(m))
    {
        for (int i = 0; i < matrix_rows(m); i++)
        {
            matrix_set(m, i, column, vector_get(v, i));
        }
        result = 0;
    }
    return result;
}


int main()
{
    int* aux;
    matrix* m = matrix_new(10, 10);

    printf("\n\nInicio pruebas de matriz de enteros\n");

    srand(time(NULL));
    for (int i = 0; i < matrix_rows(m); i++)
    {
        for (int j = 0; j < matrix_columns(m); j++)
        {
            aux = malloc(sizeof(int));
            *aux = rand() % 1000;
            matrix_set(m, i, j, aux);
        }
    }

    int* aux_2;
    vector_t* v = vector_new(10);

    srand(time(NULL));
    while (!vector_isfull(v))
    {
        aux_2 = malloc(sizeof(int));
        *aux_2 = rand() % 1000;
        vector_add(v, aux_2);
    }

    printf("\nMatriz original\n");
    matrix_print(m,print_int);


    vector_print(v,vprint_int);
    printf("\n");
    printf("\nMatriz con fila intercambiada\n");
    replace_row(m,5,v);
    replace_column(m,3,v);
    matrix_print(m,print_int);


    matrix_free(m);

    return 0;
}
