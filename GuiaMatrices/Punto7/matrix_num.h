#ifndef MATRIX_NUM_H_INCLUDED
#define MATRIX_NUM_H_INCLUDED
#include "TDAMatrix.h"

typedef struct {
    matrix* mat;
} num_matrix; //num_matrix is a struct that contains a matrix


num_matrix* num_matrix_new(int rows, int columns);
//Crea la matriz con el tamaño apropiado según las dimensiones establecidas.

void num_matrix_free(num_matrix* m);
//Elimina la matriz

int num_matrix_rows(num_matrix* m);
//Permite obtener la cantidad de filas

int num_matrix_columns(num_matrix* m);
//Permite obtener la cantidad de columnas

float num_matrix_get(num_matrix* m, int row, int col);
//Permite obtener el valor de una posición de la matriz

void num_matrix_set(num_matrix* m, int row, int col, float value);
//Permite reemplazar o asignar un elemento a la matriz

void num_matrix_print(num_matrix* m);
//Permite imprimir una matriz por consola

#endif // MATRIX_NUM_H_INCLUDED
