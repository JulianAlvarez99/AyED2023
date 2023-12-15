#include "num_vector.h"

num_vector* num_vector_new(int ini_size)
{
    num_vector* result = (num_vector*)malloc(sizeof(num_vector));

    result->vec = vector_new(ini_size);

    return result;
}

void num_vector_free(num_vector* v)
{
        vector_free(v->vec);
        free(v);
}

int num_vector_size(num_vector* v)
{
    return vector_size(v->vec);
}

int num_vector_isfull(num_vector* v)
{
    return vector_isfull(v->vec);
}

int num_vector_isempty(num_vector* v)
{
    return vector_isempty(v->vec);
}

float num_vector_get(num_vector* v, int index)
{
    return *(float*)vector_get(v->vec,index);
}

int num_vector_set(num_vector* v, int index, float value)
{
    int result = 0;
    float* aux = (float*)malloc(sizeof(float));
    *aux = value;

    result = vector_set(v->vec,index,aux);
    return result;
}

int num_vector_add(num_vector* v, float value)
{
    int result = 0;
    float* aux = (float*)malloc(sizeof(float));
    *aux = value;

    result = vector_add(v->vec,aux);
    return result;
}

int num_vector_insert(num_vector* v, int index, float value)
{
    int result = 0;
    float* aux = (float*)malloc(sizeof(float));
    *aux = value;

    result = vector_insert(v->vec,index,aux);
    return result;
}

float num_vector_remove(num_vector* v, int index)
{
    return *(float*)vector_remove(v->vec,index);
}

void print_float(void* value)
{
    printf("%05.2f ",*(float*)value);
}

//Imprime el vector
void num_vector_print(num_vector* v)
{
    vector_print(v->vec,print_float);
}
