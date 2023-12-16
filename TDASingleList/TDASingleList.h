#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define t_elem int
#define bool int
#define true 1
#define false 0

/**
 * Singly linked list
 * A singly linked list is a type of linked list that is unidirectional, that
 * is, it can be traversed in only one direction from head to the last node
 * (tail). Each element in a linked list is called a node. A single node
 * contains data and a pointer to the next node which helps in maintaining the
 * structure of the list.
 */

typedef struct _sll_node
{
    t_elem value;
    struct _sll_node* next;
} sll_node;

sll_node* sll_new_node(t_elem element);

int sll_add_nodeFirst(sll_node** head, sll_node* new_node);

int sll_add_nodeLast(sll_node** head, sll_node* new_node);

void sll_add_last(sll_node** head, t_elem element);

void sll_add_first(sll_node** head, t_elem element);

int sll_remove_all(sll_node** head, t_elem element);

sll_node* sll_remove_element2(sll_node** head, t_elem element);

int sll_remove_element4(sll_node** head, t_elem element);

void sll_print2(sll_node* head);

void sll_remove_duplicates(sll_node** head);

sll_node* sll_merge_sorted(sll_node* head1, sll_node* head2);

void sll_swap(sll_node** head, sll_node** head2);

sll_node* sll_merge_sorted2(sll_node* head1, sll_node* head2);
/*******************************************************************************************/

typedef struct list
{
    sll_node *head;
    int maxsize;
    int count;
} list;


list *list_new(int maxsize)
{
    list* new_list = (list*)malloc(sizeof(list)*maxsize);
    if(new_list != NULL)
    {
        new_list->head = NULL;
        new_list->maxsize = maxsize;
        new_list->count = 0;
    }
    return new_list;
}

bool list_isempty(list *L)
{
    bool result = false;

    if(L->count == 0)
    {
        result = true;
    }
    return(result);
}

bool list_isfull(list *L)
{
    bool result = false;

    if(L->count == L->maxsize)
    {
        result = true;
    }
    return(result);
}

int list_length(list *L)
{
    return L->count;
}

t_elem list_get(list *L, int index)
{
    list* aux = L;
    t_elem result;
    int i = 0;

    if(index>0 || index <= L->count)
    {
        while (aux->head != NULL && i != index)
        {
            aux->head = aux->head->next;
            i++;
        }
        if (aux->head != NULL)
        {
            result = aux->head->value;
        }
    }
    return result;
}

int list_search(list *L, t_elem elem)
{
    int result_index = -1;
    int i = 0;

    if(!L)
        return -1;
    list* aux = L;
    while(aux->head != NULL && aux->head->value != elem)
    {
        aux->head = aux->head->next;
        i++;
    }
    if (aux->head != NULL)
    {
        result_index = i;
    }
    return result_index;
}

void list_insert(list *L, int index, t_elem elem)
{
    if(L->count == 0)
    {
        sll_add_first(&L->head,elem);
    }
    sll
}

void list_delete(list *L, int index);

void list_traverse(list *L, bool look(t_elem elem, int index, void *ctx), void *ctx);
