#include <stdio.h>
#include <stdlib.h>
#include "matrix_num.h"

/**
 * @brief Crea la matriz con el tamaño apropiado según las dimensiones establecidas.
 *
 * @param row filas
 * @param col columnaumns
 * @return num_matrix*
 */
num_matrix* num_matrix_new(int rows, int columns)
{

    num_matrix* result = (num_matrix*)malloc(sizeof(num_matrix));

    result->mat = matrix_new(rows,columns);

    return result;
}

/**
 * @brief Elimina la matriz
 *
 * @param m puntero a la matriz
 */
void num_matrix_free(num_matrix* m)
{

    matrix_free(m->mat);
    free(m);
}

/**
 * @brief Permite obtener la cantidad de filas
 *
 * @param m puntero a la matriz
 * @return int la cantidad de filas
 */
int num_matrix_rows(num_matrix* m)
{
    return matrix_rows(m->mat);
}

/**
 * @brief Permite obtener la cantidad de columnas
 *
 * @param m puntero a la matriz
 * @return int la cantidad de columnas
 */
int num_matrix_columns(num_matrix* m)
{
    return matrix_columns(m->mat);
}

/**
 * @brief Permite obtener el valor de una posición de la matriz
 *
 * @param m puntero a la matriz
 * @param row fila
 * @param col columna
 * @return float
 */
float num_matrix_get(num_matrix* m, int row, int col)
{
    return *(float*)matrix_get(m->mat,row,col);
}

/**
 * @brief Permite reemplazar o asignar un elemento a la matriz
 *
 * @param m puntero a la matriz
 * @param row fila
 * @param col columna
 * @param value valor a asignar
 */
void num_matrix_set(num_matrix* m, int row, int col, float value)
{
    float* aux = (float*)malloc(sizeof(float));
    *aux = value;

    matrix_set(m->mat,row,col,aux);
}


void _print_float (void* value)
{

    printf("%05.2f ", *(float*)value);
}

/**
 * @brief Permite imprimir una matriz por consola
 *
 * @param m puntero a la matriz
 * @param prt función que permite imprimir un valor de la matriz
 */
void num_matrix_print(num_matrix* m)
{
    matrix_print(m->mat, _print_float);
}
