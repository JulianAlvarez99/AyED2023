#ifndef VECTOR_FUNC_H_INCLUDED
#define VECTOR_FUNC_H_INCLUDED


typedef struct
{
    void** Str;
    int Size;
    int MAX_size;

}vector_t;


vector_t* vector_new(int ini_size);
// Crea el vector vac�o reservando el espacio en memoria. Tama�o = 0, Tama�o
// M�ximo = ini_size.

void vector_free(vector_t* v);
// Eliminar el vector

int vector_size(vector_t* v);
// Permite obtener el tama�o actual del vector

int vector_isfull(vector_t* v);
// Devuelve 0 si no est� lleno y 1 si est� lleno.

int vector_isempty(vector_t* v);
// Devuelve 0 si no est� vac�o y 1 si est� vac�o.

void* vector_get(vector_t* v, int index);
// Permite obtener el valor de una posici�n del vector

int vector_set(vector_t* v, int index, void* value);
// Permite reemplazar el valor de una posici�n del vector

int vector_add(vector_t* v, void* value);
// Permite agregar un elemento al final

int vector_insert(vector_t* v, int index, void* value);
// Permite agregar un elemento en una posici�n determinada.

void* vector_remove(vector_t* v, int index);
// Permite eliminar un elemento del vector


#endif // VECTOR_FUNC_H_INCLUDED
