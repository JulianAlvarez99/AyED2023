#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "TDAVector.h"

/**
 * @brief Crea el vector vac�o reservando el espacio en memoria. Tama�o = 0, Tama�o M�ximo = ini_size.
 *
 * @param ini_size
 * @return vector*
 */
vector_t* vector_new(int ini_size)
{
    vector_t *vector = NULL;

    vector = (vector_t*)malloc(sizeof(vector_t));               // reservar espacio en memoria para el vector
    if(vector==NULL)
    {
        printf("ERROR EN LA RESERVA DE MEMORIA");
        exit(-12);
    }
    vector->Str = (void*)malloc(ini_size*sizeof(void*));        // reservar espacio en memoria para el arreglo de punteros
    vector ->Size = 0;                                          // el tama�o actual del vector es cero
    vector->MAX_size = ini_size;                                // el tama�o m�ximo del vector es el valor recibido como par�metro

    return (vector);
}

/**
 * @brief Eliminar el vector
 *
 * @param v
 */
void vector_free(vector_t* v)
{
    free(v->Str);
    free(v);
}

/**
 * @brief Permite obtener el tamanio actual del vector
 *
 * @param v
 * @return int
 */
int vector_size(vector_t* v)
{
    return v->Size;
}

/**
 * @brief Devuelve 0 si no est� lleno y 1 si est� lleno.
 *
 * @param v
 * @return int
 */
int vector_isfull(vector_t* v)
{
    return(v->Size == v->MAX_size);
}

/**
 * @brief Devuelve 0 si no est� vac�o y 1 si est� vac�o.
 *
 * @param v
 * @return int
 */
int vector_isempty(vector_t* v)
{
    return(v->Size == 0);
}


/**
 * @brief Permite obtener el valor de una posici�n del vector
 *
 * @param v
 * @param index
 * @return void*
 */
void* vector_get(vector_t* v, int index)
{

    if(index<0 || index >= v->Size)
    {
        puts("Este indice no pertenece al arreglo\n");
        return NULL;
    }
    return(v->Str[index]);
}


/**
 * @brief Permite reemplazar el valor de una posici�n del vector
 *
 * @param v
 * @param index
 * @return void*
 */
int vector_set(vector_t* v, int index, void* value)
{
    if(index<0 || index >= v->Size)
    {
        puts("Este indice no pertenece al arreglo\n");
        return 0;
    }
    v->Str[index] = value;
    return 1;
}

/**
 * @brief Permite agregar un elemento al final. Devuelve 0 si pudo agregarlo y 1 si no pudo.
 *
 * @param v
 * @param value
 */
int vector_add(vector_t* v, void* value)
{
    if(vector_isfull(v)==1)
    {
        return 1;
    }
    v->Str[v->Size]=value;
    v->Size++;

    return 0;
}

/**
 * @brief Permite agregar un elemento en una posici�n determinada.Devuelve 0 si pudo agregarlo y 1 si no pudo.
 *
 * @param v
 * @param index
 * @param value
 */
int vector_insert(vector_t* v, int index, void* value)
{
    /**CORREGIR, TIENE QUE HACER UN ESPACIO EN EL ARREGLO DEPENDIENDO DEL INDICE E INSERTAR EL VALOR**/
    if(vector_isfull(v)==1)
    {
        return 1;
    }

    for(int i = v->Size; i > index; i--)
    {
        v->Str[i] = v->Str[i-1];
    }

    vector_set(v,index,value);

    v->Size++;

    return 0;
}


/**
 * @brief Permite eliminar un elemento del vector y lo devuelve, si no puede remover devuelve 1
 *
 * @param v
 * @param index
 */
void* vector_remove(vector_t* v, int index)
{
    void* aux;

    if(vector_isempty(v)==1)
    {
        puts("El arreglo esta vacio\n");
        return NULL;
    }
    if(index<0 || index >= v->Size)
    {
        puts("Este indice no pertenece al arreglo\n");
        return NULL;
    }
    aux = v->Str[index];

    for(int i = index; i < v->Size-1; i++)
    {
        v->Str[i] = v->Str[i+1];
    }
    v->Size--;

    return aux;
}

/**
 * @brief print the vector
 *
 */
void vector_print(vector_t* v, void print(void*))
{
    printf("\n");
    for (int i = 0; i < vector_size(v); i++)
    {
       print(vector_get(v,i));
    }
    printf("\n");
}

/**
 * @brief print a vector of int*
 *
 */
 void vprint_int(void* value)
 {
    printf("%d ", *(int*)value);
    //printf("\n");
 }
