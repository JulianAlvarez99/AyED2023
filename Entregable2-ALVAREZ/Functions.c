#include <stdio.h>
#include <stdlib.h>
#define t_elem char*
#include "Functions.h"
#include "FilesFunctions.h"

sll_node_t* sll_new_node(t_elem element)
{
    sll_node_t* new_node = (sll_node_t*)malloc(sizeof(sll_node_t));

    if (new_node != NULL)
    {
        new_node->value = element;
        new_node->next = NULL;
    }

    return new_node;
}

void sll_add_first(sll_node_t** head, t_elem element)
{
    sll_node_t* aux = sll_new_node(element);
    aux->next = *head;
    *head = aux;
}

int _sll_search_repeated(sll_node_t** head, t_elem element)
{
    int result = 0;
    if (*head != NULL)
    {
        result += _sll_search_repeated(&(*head)->next, element);
        if ((*head)->value == element)
        {
            result++;
        }
    }
    return result;
}

int sll_search_repeated(sll_node_t ** head)
{
    int result = 0;

    if(*head != NULL)
    {
       result += _sll_search_repeated(&(*head)->next, (*head)->value);
       sll_search_repeated(&(*head)->next);
    }

  return result;
}

void sll_print(sll_node_t *head)
{
    if(head==NULL)
    {
        printf("\n");
    }
    else{
        printf("%s ",head->value);
        sll_print(head->next);
    }
}

void sll_print2(sll_node_t *head)
{
    if(head==NULL)
    {
        printf("\n");
    }
    else{
        printf("%s ==> %d repeticiones\n",head->value, sll_search_repeated(&head));
        sll_print2(head->next);
    }
}
