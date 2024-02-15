#include <stdio.h>
#include <stdlib.h>

/**(Sin utilizar TDA) Eliminar, de una lista dinamica doblemente enlazada donde cada nodo apunta a la raiz de un arbol, todos los nodos con arboles repetidos.
Ademas debe devolver la cantidad de nodos eliminados**/

#define t_elem_list btn*
#define t_elem_tree int

typedef struct _btn    //Implemento arboles n-arios como arboles binarios
{
    t_elem_tree value;
    struct _btn *left;
    struct _btn *right;
} btn;

typedef struct _node
{
    t_elem_list value;
    struct _node *next;
    struct _node *prev;
} list_node;


int cmp_trees(btn* t1, btn* t2)
{
    if (!t1 && !t2) return 1; // Ambos son nulos, consideramos que son iguales
    if (!t1 || !t2) return 0; // Uno de los dos es nulo, no son iguales

    int result = 0;

    if(t1->value == t2->value)
    {
        result = cmp_trees(t1->left,t2->left) && cmp_trees(t1->right, t2->right);
    }
    return result;
}

void btn_free(btn** node)
{
    if(!*node) return;

    //recorro los hijos del arbol
    btn_free(&(*node)->left);
    btn_free(&(*node)->right);

    //Elimino el nodo
    free(*node);
}

/*int list_delete_node(list_node** node, int deleted) // TAIL RECURSIVE METHOD
{
    if(!node) return -1;

    list_node *aux = (*node)->next; //ASIGNO EL SIGUIENTE NODO PARA COMPARAR
    list_node *aux2 = NULL;
    while(aux != NULL && cmp_trees((*node)->value, aux->value) == 0) // ITERO PARA ENCONTRAR UNA COINCIDENCIA O FIN DE LISTA
    {
        aux = aux->next;
    }
    if(aux != NULL) //SI TODAVIA NO ES FIN DE LISTA, QUIERE DECIR QUE ENCONTRO COINCIDENCIA, ENTONCES REMUEVE
    {
        aux2 = aux->prev;
        if(aux->next == NULL) //CASO EN EL QUE SE QUIERA BORRAR EL ULTIMO NODO
        {
            aux2->next = NULL;
        }
        else
        {
            aux2->next = aux->next;
            aux->next->prev = aux2;
        }
        btn_free(&(aux->value));
        free(aux);
        aux = NULL;
        deleted = list_delete_node(&(*node),deleted + 1); // SE INCREMENTA EL CONTADOR Y SE VUELVE A REPASAR LA LISTA

    }
    return deleted;
}


int drop_same_tree(list_node** l)
{
    if(!l) return -1;

    int result = 0;

    while(*l != NULL)
    {
        result += list_delete_node(l,0);
        *l = (*l)->next;
    }

    return result;
}*/

//NEW VERSION!!!!!
int list_deleted_repeated(list_node** head, t_elem_list element)
{
    int result = 0;
    if (*head != NULL)
    {
        result += list_deleted_repeated(&(*head)->next, element);
        if (cmp_trees((*head)->value, element->value)!=0)
        {
            list_node* aux = *head;
            list_node* aux2 = (*head)->prev;
            if(aux->next == NULL) //CASO EN EL QUE SE QUIERA BORRAR EL ULTIMO NODO
            {
                aux2->next = NULL;
            }
            else
            {
                aux2->next = aux->next;
                aux->next->prev = aux2;
            }
            btn_free(&(aux->value));
            free(aux);
            aux = NULL;
            result++;
        }
    }
    return result;
}

int drop_same_tree(list_node ** head)
{
    int result = 0;
    if(*head != NULL)
    {
        result = list_deleted_repeated(&(*head)->next, (*head)->value) + drop_same_tree(&(*head)->next);
    }
  return result;
}

/***************************************************************************************/
//********FUNCIONES AUXILIARES PARA TESTEAR**********//
// Crear un árbol
btn* create_tree(int value)
{
    btn* node = (btn*)malloc(sizeof(btn));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int btn_count(btn *node)
{
    int result = 0;
    if (node != NULL)
    {
        result = 1 + btn_count(node->left) + btn_count(node->right);
    }
    return result;
}

int btn_insert_value(btn **node, int value)
{
    int result = 0;

    if(node == NULL)return 0;

    if((*node)==NULL) // Si el subárbol es nulo, se agrega el nodo ahí
    {
        (*node) = create_tree(value);
        result = 1;
    }
    else    //Si no es NULL lo agrega en el hijo con menor cantidad de nodos
    {
        int L_nodes = btn_count((*node)->left);
        int R_nodes = btn_count((*node)->right);

        if(L_nodes > R_nodes)
        {
            btn_insert_value(&(*node)->right, value);
        }
        else    //Si a la izquierda hay menos hijos o hay la misma cantidad de hijos en ambos ramas lo agrega a la izquierda.
        {
            btn_insert_value(&(*node)->left, value);
        }
        result = 1;
    }

    return(result);
}

// Crear un nodo de lista
list_node* create_list_node(btn* tree)
{
    list_node* node = (list_node*)malloc(sizeof(list_node));
    node->value = tree;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int main()
{
    // Crear algunos árboles y nodos de lista
    btn* tree1 = create_tree(1);
    btn* tree2 = create_tree(1);
    btn* tree3 = create_tree(2);
    btn* tree4 = create_tree(3);
    btn* tree5 = create_tree(2);
    int result = 0;

    btn_insert_value(&tree1,2);
    btn_insert_value(&tree1,3);
    btn_insert_value(&tree1,4);
    btn_insert_value(&tree1,5);
    btn_insert_value(&tree2,2);
    btn_insert_value(&tree2,3);
    btn_insert_value(&tree2,4);
    btn_insert_value(&tree2,5);
    btn_insert_value(&tree3,5);
    btn_insert_value(&tree3,6);
    btn_insert_value(&tree5,5);
    btn_insert_value(&tree5,6);


    list_node* node1 = create_list_node(tree1);
    list_node* node2 = create_list_node(tree2);
    list_node* node3 = create_list_node(tree3);
    list_node* node4 = create_list_node(tree4);
    list_node* node5 = create_list_node(tree5);

    // Crear una lista enlazada
    node1->prev = NULL;
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = NULL;

    // Llamar a la función drop_same_tree
    result = drop_same_tree(&node1);

    // Después de la eliminación, la lista debería contener solo el nodo con el árbol 1
    // y los demás nodos y árboles deberían haber sido liberados
    // y el resultado debería ser 2 (dos nodos eliminados)

    // Comprobemos el resultado
    printf("Result: %d\n", result);

    // Liberar la memoria restante (limpiar el árbol que queda)
    free(node1);

    return 0;
}
