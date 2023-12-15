#ifndef TDAMATRIX_H_INCLUDED
#define TDAMATRIX_H_INCLUDED

typedef struct{
   void** a;
   int rows;
   int columns;
} matrix;

matrix* matrix_new(int rows, int columns); //Crea la matriz
void matrix_free(matrix* m); //Elimina la matriz
int matrix_rows(matrix* m);//Obtener la cantidad de filas
int matrix_columns(matrix* m);//Obtener la cantidad de columnas
void* matrix_get(matrix* m, int row, int col);//Obtener un elemento en una posicion
void matrix_set(matrix* m, int row, int col, void* value);//Asignar un elemento
void matrix_print(matrix* m, void prt(void*)); //Imprimir por consola
void print_int(void* value);

#endif // TDAMATRIX_H_INCLUDED
