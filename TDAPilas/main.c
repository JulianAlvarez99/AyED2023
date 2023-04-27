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
}stack_t;

stack_t* stack_new()    /**INICIALIZA LA PILA**/
{
    stack_t* s = (stack_t*)malloc(sizeof(stack_t));
    if(s!=NULL)
    {
        s->count = 0;
    }
    return s;
}


void _node_free(node_t** h)     /**LIBERA UN NODO Y SE REAPUNTA AL SIGUIENTE NODO**/
{
    if(*h != NULL)
    {
    node_t* aux = *h;
    aux = (*h)->next;
    free(*h);
    *h = aux;
    }
}


void stack_free(stack_t* s)     /**LIBERA UN ESPACIO DE LA PILA**/
{
    _node_free(&s->h);
}


node_t* _node_new(t_elem element)   /**AGREGA UN NUEVO NODO A LA LISTA DINAMICA ENLAZADA CON LA PILA**/
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));

    if (new_node != NULL)
    {
        new_node->value = element;
        new_node->next = NULL;
    }
    return new_node;
}

int stack_push(stack_t* s, t_elem value)    /**DEVUELVE 1 SI SE AGREGA EL VALOR O 0 SI NO SE PUDO AGREGAR**/
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

t_elem stack_pop(stack_t* s)    /**QUITA DE LA LISTA EL VALOR TOPE Y LO MUESTRA**/
{
    t_elem result = 0;

    if (s != NULL)
    {
        result = s->h->value;
        stack_free(s);
        s->count--;
    }
    return result;
}


t_elem stack_top(stack_t* s)    /**MUESTRA EL VALOR TOPE DE LA LISTA**/
{
    return s->h->value;
}

t_elem stack_get_size (stack_t* s)      /**DEVUELVE EL SIZE DE LA PILA**/
{
    return s->count;
}



int main()
{
    t_elem values[]={1,2,3,4,5,6,7,8,9,10};
    stack_t *stack = NULL;

    stack = stack_new();

    for(int i = 0; i<10; i++)
    {
        stack_push(stack,values[i]);
    }

    printf("RECIBO EL SIZE DE LA PILA: %d\n", stack_get_size(stack));

    printf("ESTA ES UNA PRUEBA DE TOP %d\n",stack_top(stack));

    printf("ESTA ES UNA PRUEBA DE POP %d\n",stack_pop(stack));

    printf("INGRESO NUEVAMENTE EL 10 A LA PILA %d\n", stack_push(stack,10));

    printf("NUEVAMENTE PRUEBO TOP %d\n", stack_top(stack));

    for(int i = 0; i<9; i++)
    {
        printf("ACA VOY A ELIMINAR TODOS LOS VALORES MENOS EL PRIMERO DE LA PILA %d\n",stack_pop(stack));
    }

    stack_free(stack);
    free(stack);

    return 0;
}
