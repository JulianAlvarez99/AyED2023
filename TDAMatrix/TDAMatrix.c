#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TDAMatrix.h"

//Crea la matriz
matrix* matrix_new(int rows, int columns)
{
    matrix* result = (matrix*)malloc(sizeof(matrix));
    result->a = (void**)malloc(sizeof(void*) * rows * columns);
    result->rows = rows;
    result->columns = columns;
    return result;
}

//Elimina la matriz
void matrix_free(matrix* m){
    free(m->a);
    free(m);
}

//Obtener la cantidad de filas
int matrix_rows(matrix* m){
    return m->rows;
}

//Obtener la cantidad de columnas
int matrix_columns(matrix* m)
{
    return m->columns;
}

//Obtener un elemento en una posición
void* matrix_get(matrix* m, int row, int col)
{
    return m->a[row * m->columns + col];
}

//Setea un valor de tipo void*
void matrix_set(matrix* m, int row, int col, void* value)
{
    m->a[row * m->columns + col] = value;
}

void print_int(void* value) {
    printf("%5d ", *(int*)value);
}

void matrix_print(matrix* m, void prt(void*))
{
    for(int i = 0; i < m->rows; i++)
    {
        for(int j = 0; j < m->columns; j++)
        {
            prt(matrix_get(m, i, j));
        }
        printf("\n");
    }
}
