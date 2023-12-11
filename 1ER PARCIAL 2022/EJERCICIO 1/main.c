#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue_static.h"
#include "stack_static.h"


//EJERCICIO 1
//Crear una función para invertir el orden los primeros N elementos de una cola (queue) Q.

/****
queue* queue_new(int maxsize);

void queue_free (queue* q);

int queue_getmaxsize(queue* q);

int queue_getsize(queue* q);

int queue_isfull (queue* q);

int queue_isempty (queue* q);

void enqueue (queue* q, t_elem elem);

t_elem dequeue (queue* q);

t_elem peek (queue* q);
***/

/***
stack* stack_new(int maxsize);

void stack_free(stack* s);

int stack_getsize(stack* s);

int stack_getmaxsize(stack* s);

void push(stack* s, t_elems elem);

t_elems pop(stack* s);

t_elems top(stack* s);

int stack_isempty(stack* s);

int stack_isfull(stack* s);

void stack_destroy(stack* s, void elem_free(t_elems));

***/


void queue_invert (queue* q, int n)
{
    stack* s = NULL;

    s = stack_new(queue_getmaxsize(q));

    while ( (n > 0) && (!queue_isempty(q)))
    {
        push(s,dequeue(q));
        n--;
    }

   while((!stack_isempty (s)) )
   {
       enqueue(q,pop(s));
   }

   stack_free(s);
}

void queue_print(queue* q)
{
    int aux = 0;

    printf("[");

    int count = queue_getmaxsize(q);

    while(count > 0)
    {
        aux = dequeue(q);
        printf("%d ",aux);
        enqueue(q,aux);
        count--;
    }

    printf("]\n\n");
}


int main()
{
    queue* q = queue_new(10);

    srand(time(NULL));
    int i;
    for (i = 0; i < 10; i++)
    {
        enqueue(q, rand()%100);
    }
    printf("\n\n");

    queue_print(q);

    queue_invert(q,5); // VARIANDO EL VALOR PODEMOS INVERTIR LOS PRIMEROS N ELEMENTOS DE LA

    queue_print(q);

    queue_free(q);

    return 0;
}
