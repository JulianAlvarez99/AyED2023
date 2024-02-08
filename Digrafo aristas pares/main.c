#include <stdio.h>
#include <stdlib.h>

//***(CON IMPLEMENTACION A ELECCION) DADO UN DIGRAFO ACICLICO, CREA UNA FUNCION PARA DEVOLVER LA CANTIDAD DE CAMINOS ENTRE 2 NODOS, CON CANTIDAD DE SALTOS "PAR"**/

#define t_graph_elem int
#define t_list_elem int
#define t_stack_elem int

int _graph_count_pair_paths(graph* g, int source, int target, stack* path_stack)    //FUNCION AUXILIAR CON PARAMETRO ADICIONAL
{
    if(!g) return 0;
    int paths = 0;
    if(source != target)        //VERIFICO SI ORIGEN ES IGUAL A DESTINO
    {
        int checkpoint = 0;
        list* vertex_list = graph_vertex_adjacent_list(g,source);   //OBTENGO LISTA DE ADYACIENCIA DEL NODO ORIGEN

        while(!list_isempty(vertex_list))   //MIENTRAS QUE LA LISTA NO ESTE VACIA
        {
            checkpoint = list_remove(vertex_list,0);    //REMUEVO EL PRIMER NODO DE LA LISTA, O EL PRIMER NODO QUE COMPARTE ARISTA CON EL ORIGEN
            push(path_stack, checkpoint);               //LO INSERTO EN UNA PILA PARA ALMACENAR EL CAMINO
            paths += _graph_count_pair_paths(g, checkpoint, target, path_stack);    //LLAMO RECURSIVAMENTE A LA FUNCION PARA ARMAR EL CAMINO E INCREMENTO LA VARIABLE SI LOS SALTOS SON PARES
            pop(path_stack);    //ELIMINO EL ULTIMO NODO AGREGADO A LA LISTA PARA SEGUIR BUSCANDO POSIBLES CAMINOS ALTERNATIVOS
        }
    }
    else
    {
        if(stack_getsize(path_stack)%2 > 0)     //SI EL TAMAÑO DE LA PILA ES IMPAR QUIERE DECIR QUE LA CANTIDAD DE SALTOS O ARISTAS ENTRE EL ORIGEN Y DESTINO ES PAR
        {
            paths = 1;      //UTILIZO COMO BOOLEANO VERDADERO
        }
    }
    return paths;
}

int graph_count_pair_paths(graph* g, int source, int target)
{
    int even_paths = 0;
    stack* path_stack = stack_new();
    push(path_stack,source);
    even_paths = _graph_count_pair_paths(g,source,target,path_stack);

    return even_paths;
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
