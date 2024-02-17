#include "TDAStack.h"

stack* stack_new(int maxsize)    /**INICIALIZA LA PILA**/
{
    stack* s = (stack*)malloc(sizeof(stack));
    if(s!=NULL)
    {
        s->head = NULL;
        s->count = 0;
        s->maxsize = maxsize;
    }
    return s;
}

void _node_free(stack_node** h)     /**LIBERA UN NODO Y SE REAPUNTA AL SIGUIENTE NODO**/
{
    if(*h != NULL)
    {
        stack_node* aux = *h;
        aux = (*h)->next;
        free(*h);
        *h = aux;
    }
}

void stack_free(stack* s)     /**LIBERA UN ESPACIO DE LA PILA**/
{
    _node_free(&s->head);
    s->count--;
}


int stack_getmaxsize(stack* s)
{
    return s->maxsize;
}

stack_node* _node_new(t_elem element)   /**AGREGA UN NUEVO NODO A LA LISTA DINAMICA ENLAZADA CON LA PILA**/
{
    stack_node* new_node = (stack_node*)malloc(sizeof(stack_node));

    if (new_node != NULL)
    {
        new_node->value = element;
        new_node->next = NULL;
    }
    return new_node;
}

void push(stack* s, t_elem value)    /**DEVUELVE 1 SI SE AGREGA EL VALOR O 0 SI NO SE PUDO AGREGAR**/
{
    stack_node* n = NULL;

    n = _node_new(value);
    if(n!=NULL)
    {
        n->next = s->head;
        s->head = n;
        s->count++;
    }
}

t_elem pop(stack* s)    /**QUITA DE LA LISTA EL VALOR TOPE Y LO MUESTRA**/
{
    t_elem result = 0;

    if (s != NULL)
    {
        result = s->head->value;
        stack_free(s);
    }
    return result;
}

t_elem top(stack* s)    /**MUESTRA EL VALOR TOPE DE LA LISTA**/
{
    return s->head->value;
}

int stack_getsize(stack* s)      /**DEVUELVE EL SIZE DE LA PILA**/
{
    return s->count;
}

int stack_isempty(stack* s)
{
    return(s->count == 0);
}

int stack_isfull(stack* s)
{
    return(s->count == s->maxsize);
}

void stack_destroy(stack* s)
{
    if(s != NULL)
    {
        while(!stack_isempty(s))
        {
            stack_free(s);
        }
    }

}

void stack_print(stack* s, void prt (t_elem))
{
    if (!stack_isempty(s))
    {
        t_elem e = pop(s);
        prt(e);
        stack_print(s, prt);
        push(s, e);
    }
}

int stack_sum(stack* s)
{
    int result = 0;
    if (!stack_isempty(s))
    {
        t_elem e = pop(s);

        result += *(int*)e + stack_sum(s);
        push(s, e);
    }
    return result;
}

void print_elem (t_elem e)
{
    printf("%c\n", *(char*)e);
}

stack* stack_copy(stack* s)
{
  if(!s) return NULL;

  stack* aux = stack_new(stack_getmaxsize(s));
  stack* copy = stack_new(stack_getmaxsize(s));

  t_elem value;

  while(!stack_isempty(s))
  {
   value = pop(s);
   push(aux, value);
  }

   while(!stack_isempty(aux))
  {
   value = pop(aux);
   push(s, value);
   push(copy, value);
  }

 stack_destroy(aux);

return copy;
}
