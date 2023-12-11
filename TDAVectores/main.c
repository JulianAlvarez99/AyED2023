#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Vector_func.h"

void print_vector_int(vector_t* v)
{
    int i = 0;
    for (i = 0; i < vector_size(v); i++)
    {
        printf("%d ", *(int*)vector_get(v, i));
    }
    printf("\n");
}

/**
 * @brief print a vector of str
 *
 */
void print_vector_str(vector_t* v)
{
    int i = 0;
    for (i = 0; i < vector_size(v); i++)
    {
        printf("%s ", (char*)vector_get(v, i));
    }
    printf("\n");
}

/**
 * @brief test vector ATD
 *
 */
void test_vector_int()
{
    int* aux;
    vector_t* v = vector_new(10);

    printf("\n\nInicio pruebas de vector de enteros\n");

    // complete vector with random values
    srand(time(NULL));
    while (!vector_isfull(v))
    {
        aux = malloc(sizeof(int));
        *aux = rand() % 1000;
        vector_add(v, aux);
    }
    getc(stdin);
    // print vector
    print_vector_int(v);

    // remove an element
    aux = vector_remove(v, 2);
    printf("Eliminado: %d\n", *aux);
    free(aux);
    print_vector_int(v);

    // insert a value in the misddle of the vector
    aux = malloc(sizeof(int));
    *aux = rand() % 1000;
    vector_insert(v, 2, aux);

    printf("Valor insertado %d \n", *aux);
    print_vector_int(v);

    // remove a value in the middle of the vector
    aux = vector_remove(v, 5);
    printf("Valor eliminado %d \n", *aux);
    print_vector_int(v);

    // remove all values
    while (!vector_isempty(v))
    {
        aux = vector_remove(v, 0);
        printf("Valor eliminado %d \n", *aux);
        print_vector_int(v);
        free(aux);
    }

    // free the vector
    if (vector_isempty(v))
    {
        printf("\n vector vacio \n");
        vector_free(v);
    }

    printf("\n fin \n");
}

void test_vector_str()
{
    char* frutas[] = {"manzana", "pera",   "uva",       "fresa", "naranja",
                      "guanabana",   "banana", "limon", "mango", "coco"
                     };
    int n = sizeof(frutas) / sizeof(char*);


    printf("\n\nInicio pruebas de vector de strings\n");
    vector_t* v = vector_new(20);
    for (int i = 0; i < n; i++)
    {
        vector_add(v, frutas[i]);
    }

    print_vector_str(v);

    // find position of "limon"
    int pos = 0;
    while (!vector_isempty(v) && strcmp((char*)vector_get(v, pos), "limon"))
    {
        pos++;
    }
    printf("posicion de limon: %d\n", pos);

    // remove "limon"
    char* aux = vector_remove(v, pos);
    printf("eliminado: %s\n", aux);
    print_vector_str(v);

    // remove all elements and free the vector
    while (vector_remove(v, vector_size(v)-1))
        printf(".");

    if (vector_isempty(v))
    {
        printf("\n vector vacio \n");
        vector_free(v);
    }

}

int cmp_int (const void* a, const void* b)
{
    int* x = (int*)a;
    int* y = (int*)b;
    return *x - *y;
}

int vector_binary_search(vector_t* v, void* value, int (*cmp)(const void*, const void*))
{
    int low = 0;
    int high = vector_size(v) - 1;
    int mid = (low + high) / 2;    // midpoint of search
    while ((low < high) && (cmp(value, vector_get(v, mid)) != 0))
    {
        if (cmp(value, vector_get(v, mid)) < 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return (cmp(value, vector_get(v, mid)) == 0)? mid : -1;
}


void test_vector_search()
{
    srand(time(NULL));
    int* aux = malloc(sizeof(int));
    *aux = rand() % 5;
    vector_t* v = vector_new(100);
    while (!vector_isfull(v))
    {
        vector_add(v, aux);
        aux = malloc(sizeof(int));
        *aux = rand() % 4 + 1 + *(int*)vector_get(v, vector_size(v)-1);
    }

    print_vector_int(v);
    int valor =  rand() % 100;
    printf("buscando %d\n", valor);
    int pos = vector_binary_search(v, &valor, cmp_int);
    if (pos == -1)
    {
        printf("no encontrado\n");
    }
    else
    {
        printf("encontrado en posicion %d\n", pos);
    }

}

int main()
{
    test_vector_int();
    getc(stdin);
    //test_vector_str();
    //getc(stdin);
    //test_vector_search();
    //getc(stdin);
    return EXIT_SUCCESS;
}
