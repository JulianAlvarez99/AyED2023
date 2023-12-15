#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "matrix_num.h"

void test_matrix_int()
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

    printf("\nMatriz original\n");
    matrix_print(m,print_int);

}

void multiply_matrix(num_matrix* m1, num_matrix* m2, num_matrix* m3)
{
    for (int i = 0; i < num_matrix_rows(m3); i++)
    {
        for (int j = 0; j < num_matrix_columns(m3); j++)
        {
            float aux = 0;
            for (int k = 0; k < num_matrix_columns(m1); k++)
            {
                aux += num_matrix_get(m1, i, k) * num_matrix_get(m2, k, j);
            }
            num_matrix_set(m3, i, j, aux);
        }
    }
}



// rellenar la matriz con numeros aleatorios
void fill_matrix(num_matrix* m, int max)
{
    static int i = 0;
    float aux;
    i++;
    srand(time(NULL)+i);
    for (int i = 0; i < num_matrix_rows(m); i++)
    {
        for (int j = 0; j < num_matrix_columns(m); j++)
        {
            int auxi = rand() % max;
            //aux = (float)rand()/(float)(RAND_MAX/100);
            aux = auxi;
            num_matrix_set(m, i, j, aux);
        }
    }
}

void test_matrix_float()
{

    num_matrix* a = num_matrix_new(3, 2);
    num_matrix* b = num_matrix_new(2, 4);
    num_matrix* c = num_matrix_new(3, 4);

    printf("\n\nInicio pruebas de matriz de flotantes\n");
    fill_matrix (a, 10);
    fill_matrix (b, 10);

    printf("\nMatriz A\n");
    num_matrix_print(a);
    printf("\nMatriz B\n");
    num_matrix_print(b);

    multiply_matrix(a, b, c);
    printf("\nMatriz C\n");
    num_matrix_print(c);

}


int main()
{
    test_matrix_float();
    return 0;
}
