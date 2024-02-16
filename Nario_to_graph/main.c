#include <stdio.h>
#include <stdlib.h>
#define t_graph_elem int
#define t_list_elem btn*
#define t_btn_elem int

/**IMPLEMENTO ARBOLES BINARIOS COMO N-ARIOS**/
/**LA RAMA IZQUIERDA REPRESENTA EL PRIMER HIJO**/
/**LA RAMA DERECHA DEL PRIMER HIJO REPRESENTA LA LISTA DE HERMANOS**/
/**LA RAMA IZQUIERDA DE CUALQUIERA DE LA LISTA DE HERMANOS REPRESENTA LOS NIETOS Y ASI..**/

/**
        2                   2
     /  |  \              /
    3   4   0    ->      3
  /                     /  \
1                     1     4
                             \
                              0
**/


typedef struct _btn
{
    t_btn_elem value;
    struct _btn *right;
    struct _btn *left;
} btn;


int cmp(t_graph_elem v1, t_graph_elem v2)
{
    int result = 0;

    if(v1 < v2)
    {
        result =  1;
    }
    else if (v1 > v2)
    {
        result = -1;
    }
    return result;
}

/*void _tree_to_graph(btn* son, graph* g, btn* father)
{
    if(!son) return;

    if(graph_vertex_index(g,father->value,cmp)<0) // SI DEVUELVE INDICE NEGATIVO, QUIERE DECIR QUE NO SE ENCUENTRA EN EL GRAFO
    {
        graph_add_vertex(g,father->value); //AGREGO VERTICE
    }

    if(graph_vertex_index(g,son->value,cmp)<0) // SI DEVUELVE INDICE NEGATIVO, QUIERE DECIR QUE NO SE ENCUENTRA EN EL GRAFO
    {
        graph_add_vertex(g,son->value); //AGREGO VERTICE
    }

    _tree_to_graph(son->left,g,son);
    _tree_to_graph(son->right,g,son);
    graph_add_edge(g, father->value, son->value, 1);
}*/

void _tree_to_graph(btn* root, graph* g, t_btn_elem father)
{
    if(!root) return;
        
    btn* son = root->left;
    
    while(son != NULL)
    {
        if(graph_vertex_index(g,son->value,cmp)<0) // SI DEVUELVE INDICE NEGATIVO, QUIERE DECIR QUE NO SE ENCUENTRA EN EL GRAFO
        {
             graph_add_vertex(g,son->value); //AGREGO VERTICE
        }
    graph_add_edge(g, father, son->value, 1);
    _tree_to_graph(son,g,son->value);
    son = son->right;
    }
}

void tree_to_graph(btn* root, graph* g)
{
    if(root != NULL)
    {
        if(graph_vertex_index(g,root->value,cmp)<0) // SI DEVUELVE INDICE NEGATIVO, QUIERE DECIR QUE NO SE ENCUENTRA EN EL GRAFO
        {
                graph_add_vertex(g,root->value); //AGREGO VERTICE
        }
        _tree_to_graph(root,g,root->value);
    }
}

graph* create_graph(list_tree* l)
{
    if(!l) return;

    graph* g = graph_new();
    list_tree* aux_list = l;

    while(!list_isempty(aux_list))
    {
        tree_to_graph(list_remove(aux_list,0),g);
    }

    return g;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
