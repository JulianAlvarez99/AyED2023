#include "TDASingleList.h"


//Create a new node for single linked list.
sll_node* sll_new_node(t_elem element)
{
    sll_node* new_node = (sll_node*)malloc(sizeof(sll_node));
    if (new_node != NULL)
    {
        new_node->value = element;
        new_node->next = NULL;
    }
    return new_node;
}

//Add a new node to the beginning of the list. (version 2)
//This version does not differentiate the first case from the others.
//warning: head is a poniter of a poniter of a node.
//         head must be a "meta_head" at the beginning of the function.
int sll_add_nodeFirst(sll_node** head, sll_node* new_node)
{
    if (new_node == NULL) return 0;

    sll_node** aux = head;
    while (*aux != NULL)
    {
        aux = &(*aux)->next;
    }
    *aux = new_node;

    return 1;
}

//Add a new node to the beginning of the list. (version 3)
//This is a recursive version, note that it does not differentiate special cases except the base case.
//warning: head is a poniter of a poniter of a node.
//         head must be a meta_head at the beginning of the function.
int sll_add_nodeLast(sll_node** head, sll_node* new_node)
{
    if (new_node == NULL) return 0;

    if (*head == NULL)
    {
        *head = new_node;
        return 1;
    }
    else
    {
        return sll_add_nodeLast(&(*head)->next, new_node);
    }

}

//Add a element to the end of de list (recursive version).
void sll_add_last(sll_node** head, t_elem element)
{
    sll_node* new_node = sll_new_node(element);
    sll_add_nodeLast(head, new_node);
}

//Add an element as head of list.
void sll_add_first(sll_node** head, t_elem element)
{
    sll_node* aux = sll_new_node(element);
    aux->next = *head;
    *head = aux;
}


//Remove all nodes with the given value.
//returns the number of nodes removed.
//(ineficient version)
int sll_remove_all(sll_node** head, t_elem element)
{
    int result = 0;
    while (sll_remove(head, element) == 1)
    {
        result += 1;
    }
    return result;
}

//Remove a node with the given value. (version 2)
//this version use a doble pointer to keep track of the previous node.
sll_node* sll_remove_element2(sll_node** head, t_elem element)
{
    sll_node* node_to_remove = NULL;
    sll_node** aux = head;

    while (*aux != NULL && (*aux)->value != element)
    {
        aux = &(*aux)->next;
    }

    if (*aux != NULL)
    {
        node_to_remove = *aux;
        *aux = (*aux)->next;
        node_to_remove->next = NULL;
    }

    return node_to_remove;
}


//Remove and free a node with the given value.
//returns 1 if could remove, 0 otherwise.
int sll_remove_element4(sll_node** head, t_elem element)
{
    int result = 0;
    if (*head != NULL)
    {
        if ((*head)->value == element)
        {
            sll_node* aux = *head;
            *head = (*head)->next;
            aux->next = NULL;
            free(aux);
            result = 1;
        }
        else
        {
            result = sll_remove_element4(&(*head)->next, element);
        }
    }
    return result;
}

//Remove and free all nodes with the given value.
//Returns the number of nodes removed.
//note: this version goes to the end of the list and removes the nodes when it returns to the head.
int sll_remove_element5(sll_node** head, t_elem element) {
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

//Print all elements of the list. (Recursive version)
void sll_print2(sll_node* head)
{
    if (head == NULL)
    {
        printf("\n");
    }
    else
    {
        printf("%d ", head->value);
        sll_print2(head->next);
    }
}

//remove all nodes with duplicate values ​​from the list
void sll_remove_duplicates(sll_node** head)
{
    if (*head != NULL)
    {
        sll_remove_element5(&(*head)->next, (*head)->value);
        sll_remove_duplicates(&(*head)->next);
    }
}

//Merge 2 sorted lists.
//returns a pointer to the new list.
sll_node* sll_merge_sorted(sll_node* head1, sll_node* head2)
{
    sll_node* result = NULL;

    if (head2 == NULL)
    {
        result = head1;
    }
    else if (head1 == NULL)
    {
        result = head2;
    }
    else     //(head1 != NULL && head2 != NULL)
    {
        if (head1->value < head2->value)
        {
            result = head1;
            result->next = sll_merge_sorted(head1->next, head2);
        }
        else
        {
            result = head2;
            result->next = sll_merge_sorted(head1, head2->next);
        }
    }
    return result;
}


void sll_swap(sll_node** head, sll_node** head2)
{
    sll_node* aux = *head;
    *head = *head2;
    *head2 = aux;
}

//Merge 2 sorted lists.
//returns a pointer to the new list.
//iterative version.
sll_node* sll_merge_sorted2(sll_node* head1, sll_node* head2)
{
    sll_node* result = NULL;

    if (head2 == NULL || (head1 != NULL && head1->value > head2->value))
    {
        sll_swap(&head1, &head2); //head1 must have the smallest value.
    }
    result = head1;     //result is the head of the new list.
    while (head1 != NULL)
    {
        if (head2 != NULL && ((head1->next) == NULL || (head1->next)->value > head2->value))
        {
            sll_swap (&(head1->next), &head2);
        }
        head1 = head1->next;
    }
    return result;
}
