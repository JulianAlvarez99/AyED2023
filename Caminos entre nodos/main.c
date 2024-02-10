#include <stdio.h>
#include <stdlib.h>
#define t_list_elem int
#define t_graph_elem int
#define t_stack_elem int



/***(Sin utilizar TDAs) Dado un digrafo acíclico, implementado con listas de adyacencias, crear una función
para devolver la cantidad de caminos entre 2 nodos.***/



// Definición de la estructura de un nodo de la lista enlazada para representar las aristas
typedef struct _list
{
    t_list_elem value;
    struct _list *next;
} list;

// Definicion de una Pila
typedef struct _stack
{
    list *head;
    int count;
} stack;

// Definición de la estructura del grafo
typedef struct _graph
{
    t_graph_elem vertex_number;
    list** ady_list; // Lista de adyacencia, un array de punteros a nodos
} graph;


list* graph_vertex_adjacent_list(graph* g, int vertex)
{
    if(!g)return NULL;

    return g->ady_list[vertex];
}

t_list_elem list_remove(list** l, int index)
{
    if(!*l)return -1;

    int removed = 0;
    int iteration = 0;

    while(*l != NULL && iteration != index)
    {
        *l = (*l)->next;
        iteration++;
    }
    if(*l != NULL)
    {
        list* aux_list = *l;
        *l = (*l)->next;
        removed = aux_list->value;
        aux_list->next = NULL;
        free(aux_list);
    }
    return removed;
}

list* stack_new_node(t_stack_elem value)
{
    list* node = (list*)malloc(sizeof(list));

    if(node != NULL)
    {
        node->value = value;
        node->next = NULL;
    }
    return node;
}

stack* stack_new()
{
    stack* new_stack = (stack*)malloc(sizeof(stack));

    if(new_stack != NULL)
    {
        new_stack->head = NULL;
        new_stack->count = 0;
    }
    return new_stack;
}

void push(stack* s, t_stack_elem value)
{
    if(!s) return;

    list* n = NULL;
    n = stack_new_node(value);

    if(n != NULL)
    {
        n->next = s->head;
        s->head = n;
        s->count++;
    }
}

void pop(stack** s)
{
    if(*s != NULL)
    {
        list* aux_node = (*s)->head->next;
        free((*s)->head);
        (*s)->head = aux_node;
        (*s)->count--;
    }
}

int stack_isempty(stack* s)
{
    if(!s)return 0;

    return s->count;
}

void stack_destroy(stack* s)
{
    if(s!=NULL)
    {
        while(!stack_isempty(s))
        {
            pop(&s);
        }
    }
}

int _graph_count_paths (graph* g, int source, int target, stack* path_stack)
{
    if(!g) return 0;
    int paths = 0;

    if(source != target)
    {
        list* aux_list = graph_vertex_adjacent_list(g,source);

        while(aux_list != NULL)
        {
            int checkpoint = list_remove(&aux_list,0);
            push(path_stack,checkpoint);
            paths += _graph_count_paths(g,checkpoint,target,path_stack);
            pop(&path_stack);
        }
    }
    else
    {
        paths = 1;
    }

    return paths;
}


int graph_count_paths (graph* g, int source, int target)
{
    stack* path_stack = stack_new();
    int paths = 0;

    push(path_stack,source);

    paths = _graph_count_paths(g,source,target,path_stack);

    stack_destroy(path_stack);

    return paths;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
