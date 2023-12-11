#include <stdio.h>
#include <stdlib.h>
#define t_elem int
typedef struct _node
{
    t_elem value;
    struct _node* next;

} node_t;

typedef struct pila
{
    node_t* h;
    int count;
}stack;

stack* stack_new()
{
    stack* s = (stack*)malloc(sizeof(stack));
    if(s!=NULL)
    {
        s->count = 0;
    }
    return s;
}


void _node_free(node_t* h)  /** REVISAR**/
{
    if(h != NULL)
    {
    node_t* aux = h;
    h = h->next;
    aux->next = NULL;
    free(aux);
    }
}

void stack_free(stack* s)
{
    _node_free(s->h);
}


node_t* _node_new(t_elem element)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    if (new_node != NULL)
    {
        new_node->value = element;
        new_node->next = NULL;
    }
    return new_node;
}

int stack_push(stack* s, t_elem value)
{
    node_t* n = NULL;
    int result = 0;

    n = _node_new(value);
    if(n!=NULL)
    {
        n->next = s->h;
        s->h = n;
        s->count++;
        result = 1;
    }
    return result;
}

t_elem stack_pop(stack* s)
{
    t_elem result = 0;

    if (s != NULL)
    {
        node_t* aux_eliminado = s->h;
        result = s->h->value;
        s->h = s->h->next;
        _node_free(aux_eliminado);

        s->count--;
    }
    return result;
}


/*t_elem stack_pop(node_t ** head)
{
    t_elem result = 0;

    node_t* next_node = NULL;

    if (*head == NULL) {
        printf("La pila está vacía\n");
    }

    next_node = (*head)->next;
    result = (*head)->value;
    free(*head);
    *head = next_node;
    return result;
}*/

t_elem stack_top(stack* s)
{
    return s->h->value;
}

t_elem stack_get_size (stack* s)
{
    return s->count;
}

int main()
{
    stack* pila = stack_new();

    stack_push(pila,1);
    stack_push(pila,2);
    stack_push(pila,3);
    stack_push(pila,4);
    stack_push(pila,5);

    printf("%d", stack_pop(pila));
    printf("%d", stack_pop(pila));
    printf("%d", stack_pop(pila));
    printf("%d", stack_pop(pila));
    printf("%d", stack_pop(pila));

    stack_free(pila);

    return 0;
}
