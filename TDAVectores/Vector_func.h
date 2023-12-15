#ifndef VECTOR_FUNC_H_INCLUDED
#define VECTOR_FUNC_H_INCLUDED


typedef struct
{
    void** Str;
    int Size;
    int MAX_size;

}vector_t;


vector_t* vector_new(int ini_size);
// Crea el vector vacío reservando el espacio en memoria. Tamaño = 0, Tamaño
// Máximo = ini_size.

void vector_free(vector_t* v);
// Eliminar el vector

int vector_size(vector_t* v);
// Permite obtener el tamaño actual del vector

int vector_isfull(vector_t* v);
// Devuelve 0 si no está lleno y 1 si está lleno.

int vector_isempty(vector_t* v);
// Devuelve 0 si no está vacío y 1 si está vacío.

void* vector_get(vector_t* v, int index);
// Permite obtener el valor de una posición del vector

int vector_set(vector_t* v, int index, void* value);
// Permite reemplazar el valor de una posición del vector

int vector_add(vector_t* v, void* value);
// Permite agregar un elemento al final

int vector_insert(vector_t* v, int index, void* value);
// Permite agregar un elemento en una posición determinada.

void* vector_remove(vector_t* v, int index);
// Permite eliminar un elemento del vector

void vector_print(vector_t* v, void print(void*))
//Permite imprimir los elementos del vector


#endif // VECTOR_FUNC_H_INCLUDED
