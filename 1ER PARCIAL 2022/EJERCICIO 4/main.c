#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define t_elem int

/* @brief Crear una función recursiva para obtener el puntero del nodo
 * con mínimo valor de una lista dinámica  simplemente enlazada de
 * valores enteros (sin usar TDA).
 *
 * Utilizar la siguiente definición:
 *
 */

typedef struct _nodo {
	int value;
	struct _nodo* next;
} nodo;


nodo* nodo_new(t_elem value)
{
    nodo* n = (nodo*)malloc(sizeof(nodo*));
    if(n!=NULL)
    {
        n->value = value;
        n->next = NULL;
    }
    return n;
}


void sll_add_first(nodo** head, t_elem element)
{
    nodo* aux = nodo_new(element);
    aux->next = *head;
    *head = aux;
}

void sll_print(nodo *head)
{
    if(head==NULL)
    {
        printf("\n");
    }
    else{
        printf("%d ",head->value);
        sll_print(head->next);
    }
}

nodo* min_nodo_lista (nodo* head)
{
    nodo* aux = head;
    if(head!=NULL)
    {
        nodo* min = min_nodo_lista(head->next);

        if((min!=NULL) && (min->value < aux->value))
        {
            aux = min;
        }
    }
    return aux;
}


int main()
{
    nodo* head = NULL;
    srand(time(NULL));
    for(int i = 0; i< 10; i++)
    {
    sll_add_first(&head,rand()%100);
    }

    sll_print(head);
    printf("\n\n");

    nodo* min = min_nodo_lista(head);
    printf("%d\n", min->value);

    free(head);

    return 0;
}
