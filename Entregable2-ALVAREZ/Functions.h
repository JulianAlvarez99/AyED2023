#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define t_elem char*

typedef struct sll_node
{
    t_elem value;
    struct sll_node* next;

} sll_node_t;

sll_node_t* sll_new_node(t_elem element);
void sll_add_first(sll_node_t** head, t_elem element);
int _sll_search_repeated(sll_node_t** head, t_elem element);
int sll_search_repeated(sll_node_t ** head);
void sll_print(sll_node_t *head);
void sll_print2(sll_node_t *head);

#endif // FUNCTIONS_H_INCLUDED
