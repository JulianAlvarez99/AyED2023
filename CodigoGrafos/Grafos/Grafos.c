#include "Grafos.h"

graph* graph_new()
{
    graph* g = (graph*)malloc(sizeof(graph));
    g->ady_matrix = matrix_new(10,10);
    g->vertex_list = vector_new(10);
    g->vertex = 0;
    return g;
}

void graph_destroy(graph* g) // Destroy a graph
{
    matrix_free(g->ady_matrix);
    vector_free(g->vertex_list);
    free(g);
}

int graph_add_vertex(graph* g, t_graph_elem vertex)// Add a vertex to the graph
{
    if(!g)return 0;

    int result = 0;
    if(g->vertex + 1 <= vector_size(g->vertex_list))
    {
        g->vertex++;
        vector_add(g->vertex_list,g->vertex);
        result = 1;
    }
    else
    {
        g->vertex_list = vector_resize(g->vertex_list,g->vertex);
        g->ady_matrix = matrix_resize(g->ady_matrix,g->vertex);
        graph_add_vertex(g,vertex);
    }
    return result;
}

t_graph_elem graph_vertex_get(graph* g, int index) // Get vertex by index
{
    if(!g)return INF;

    t_graph_elem result;

    if(index <= g->vertex)
    {
        result = vector_get(g->vertex_list,index);
    }
    else
    {
        result = INF;
    }
    return result;
}


int graph_vertex_index(graph* g, t_graph_elem vertex, int cmp (t_graph_elem, t_graph_elem)) // Get the index of a vertex
{
    if(!g)return INF;

    t_graph_elem result;
    int count = 0;

    while(!cmp(vertex,vector_get(g->vertex_list,count)) && count < g->vertex)
    {
        count++;
    }
    if(count<g->vertex)
    {
        result = count;
    }
    return result;
}

int graph_add_edge(graph* g, int v1, int v2, int weight) // Add an edge to the graph
{
    if(!g) return 0;

    int result = 0;

    if(v1 <= g->vertex && v2 <= g->vertex)
    {
        matrix_set(g->ady_matrix,v1,v1,0);
        matrix_set(g->ady_matrix,v2,v2,0);
        matrix_set(g->ady_matrix,v1,v2,weight);
        result = 1;
    }

    return result;
}

int graph_remove_edge(graph* g, int v1, int v2, int weight)// Remove an edge from the graph
{
    if(!g) return 0;

    int result = 0;

    if(v1 <= g->vertex && v2 <= g->vertex && weight == matrix_get(g->ady_matrix,v1,v2))
    {
        matrix_set(g->ady_matrix,v1,v2,INF);
        result = 1;
    }
    return result;
}
int graph_remove_vertex(graph* g, int v) // Remove a vertex from the graph
{
    if(!g) return 0;

    int result = 0;

    if(v <= g->vertex)
    {
        vector_remove(g->vertex_list,v);
        result = 1;
    }

    return result;
}

int graph_get_edge_weight(graph* g, int v1, int v2) // Get the weight of an edge
{
    if(!g) return 0;

    return matrix_get(g->ady_matrix,v1,v2);
}

int graph_get_edge_cost(graph* g, int v1, int v2)  // Get the cost of an edge
{
    if(!g)return 0;

    int result = 0;

    // devuelve 0 si es la misma arista
    // devuelve infinito si la arista no existe
    // devuelve el peso si la arista existe

    return result;
}

