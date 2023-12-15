#ifndef NUM_VECTOR_H_INCLUDED
#define NUM_VECTOR_H_INCLUDED
#include "TDAVector.h"
typedef struct
{
    vector_t* vec;

}num_vector;


num_vector* num_vector_new(int ini_size);
// Crea el vector vacío reservando el espacio en memoria. Tamanio = 0, Tamanio
// Máximo = ini_size.

void num_vector_free(num_vector* v);
// Eliminar el vector

int num_vector_size(num_vector* v);
// Permite obtener el tamaño actual del vector

int num_vector_isfull(num_vector* v);
// Devuelve 0 si no esta lleno y 1 si esta lleno.

int num_vector_isempty(num_vector* v);
// Devuelve 0 si no esta vacío y 1 si esta vacío.

float num_vector_get(num_vector* v, int index);
// Permite obtener el valor de una posicion del vector

int num_vector_set(num_vector* v, int index, float value);
// Permite reemplazar el valor de una posición del vector

int num_vector_add(num_vector* v, float value);
// Permite agregar un elemento al final

int num_vector_insert(num_vector* v, int index, float value);
// Permite agregar un elemento en una posicion determinada.

float num_vector_remove(num_vector* v, int index);
// Permite eliminar un elemento del vector

//Imprime el vector
void num_vector_print(num_vector* v);

#endif // NUM_VECTOR_H_INCLUDED
