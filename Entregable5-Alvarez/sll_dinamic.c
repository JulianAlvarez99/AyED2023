#include <stdio.h>
#include <stdlib.h>
#include "sll_dinamic.h"

/**
Crea un nuevo nodo a la lista simplemente enlazada con un t_elem_list
**/
sll_node* sll_new_node(t_elem_list element) //Create a new node for single linked list.
{
    sll_node* new_node = (sll_node*)malloc(sizeof(sll_node));

    if (new_node != NULL)
    {
        new_node->value = element;
        new_node->next = NULL;
    }

    return new_node;
}

/**
Agrega un nuevo nodo a la lista simplemente enlazada con un t_elem_list
**/

int sll_add_node(sll_node** head, sll_node* new_node) //Add a new node to the end of the list.
{
    if (new_node == NULL) return 0;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        sll_node* aux = *head;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = new_node;
    }

    return 1;
}

/**
Agrega un t_elem_list al final de la lista simplemente enlazada
**/
void sll_add_day_measures(sll_node** head, t_elem_list element) //Add a element to the end of de list (recursive).
{
    sll_node* new_node = sll_new_node(element);
    sll_add_node(head, new_node);
}

//Remove and free a node with the given value.
//returns 1 if could remove, 0 otherwise.
int sll_remove_element4(sll_node** head, t_elem_list element) {
    int result = 0;
    if (*head != NULL) {
        if ((*head)->value == element) {
            sll_node* aux = *head;
            *head = (*head)->next;
            aux->next = NULL;
            free(aux);
            result = 1;
        } else {
            result = sll_remove_element4(&(*head)->next, element);
        }
    }
    return result;
}

//Remove and free all nodes with the given value.
//Returns the number of nodes removed.
//note: this version goes to the end of the list and removes the nodes when it returns to the head.
int sll_remove_element5(sll_node** head, t_elem_list element)
{
    int result = 0;
    if (*head != NULL) {
        result += sll_remove_element5(&(*head)->next, element);
        if ((*head)->value == element) {
            sll_node* aux = *head;
            *head = (*head)->next;
            aux->next = NULL;
            free(aux);
            result++;
        }
    }
    return result;
}


