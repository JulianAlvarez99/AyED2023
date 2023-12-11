#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TDAMatrix.h"

int main()
{
    int* aux;
    matrix* m = matrix_new(10, 10);

    printf("\n\nInicio pruebas de matriz de enteros\n");

    srand(time(NULL));
    for (int i = 0; i < matrix_rows(m); i++) {
        for (int j = 0; j < matrix_columns(m); j++) {
            aux = malloc(sizeof(int));
            *aux = rand() % 1000;
            matrix_set(m, i, j, aux);
        }
    }

    printf("\nMatriz original\n");
    matrix_print(m,print_int);
    matrix_free(m);

    return 0;
}
