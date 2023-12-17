#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree_base.h"

/**************************************************************/
/*                       NOMENCLATURAS                        */
/**************************************************************/
/**
 * BT - Binary Tree: Árbol binario.
 * BTN - binary tree node: nodo de árbol binario.
 * SBT - Search Binary Tree: ABB - Árbol binario de búsqueda.
 * AVL - AVL Tree: Árbol AVL.
 * root: nodo raíz del árbol.
 * parent node: nodo padre.
 * child node: nodo hijo.
 * internal node,
 * inner node,
 * inode,
 * branch node: nodo interno, que tiene hijos.
 * external node,
 * leaf node,
 * outer node,
 * terminal node: nodo hoja de un árbol.
 */
/**************************************************************/

/**
 *  Binary Tree Node Struct
 */



/*typedef struct _btn {
    t_elem_btree value;
    struct _btn *left;
    struct _btn *right;
} btn;*/

/**************************************************************/
/*                     ÁRBOLES BINARIOS                       */
/**************************************************************/

/**
 * Crea un nodo de un BTN en base a un valor t_elem_btree
 */
btn* btn_new(t_elem_btree value)
{
    btn* node = (btn*)malloc(sizeof(btn));

    if(node != NULL)
    {
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    }
    return node;
}

/**
 * Elimina un nodo, si tiene hijos elimina sus hijos también.
 */
void btn_free(btn** node)
{
    if(!*node)return;

    //Elimino los hijos primero
    btn_free(&(*node)->left);
    btn_free(&(*node)->right);

    //Despues elimino el nodo
    free(*node);
}

/**
 * Busca un nodo con un determinado elemento y devuelve su referencia
 * Se busca el nodo en pre-order (debe recorrer todo el árbol no hay un criterio de ordenamiento)
 * Debe devolver la referencia a la ubicación del puntero al nodo. Si no existe, devuelve NULL
 */
btn** btn_find(btn** node, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree))
{
    if(!*node) return NULL;

    if(!cmp((*node)->value,value))
    {
        btn_find(&(*node)->left,value,cmp);
        btn_find(&(*node)->right,value,cmp);
    }
    return(node);
}

/**
 * Devuelve 1 si el nodo es una hoja.
 * Devuelve 0 si no es una hoja.
 */
int btn_isLeaf(btn *node)
{
    int result = 0;

    if(!node)
    {
        result = -1;
        return result;
    }

    if((node->left == NULL) && (node->right == NULL))
    {
        result = 1;
    }

    return (result);
}

/**
 * Cuenta la cantidad de nodos de un árbol binario.
 */
int btn_count(btn *node)
{
    int result = 0;
    if (node != NULL)
    {
        result = 1 + btn_count(node->left) + btn_count(node->right);
    }
    return result;
}

/**
 * Agrega un nodo en un árbol binario con el siguiente criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */
int btn_insert(btn **node, btn *newNode)
{
    int result = 0;

    if(node == NULL)return 0;
    if(newNode == NULL)return 0;
    if((*node)==NULL) // Si el subárbol es nulo, se agrega el nodo ahí
    {
        (*node) = newNode;
        result = 1;
    }
    else    //Si no es NULL lo agrega en el hijo con menor cantidad de nodos
    {
        int L_nodes = btn_count((*node)->left);
        int R_nodes = btn_count((*node)->right);

        if(L_nodes > R_nodes)
        {
            btn_insert(&(*node)->right, newNode);
        }
        else    //Si a la izquierda hay menos hijos o hay la misma cantidad de hijos en ambos ramas lo agrega a la izquierda.
        {
            btn_insert(&(*node)->left, newNode);
        }
      result = 1;
    }

    return(result);
}

/**
 * Agrega un valor a un BT con el criterio:
 * - Si el subárbol es nulo se agrega ahí,
 * - Si no es NULL lo agrega en el hijo con menor cantidad de nodos,
 * - Si sus hijos tienen la misma cantidad de nodos lo agrega a la izquierda.
 */
int btn_insert_value(btn **node, int value)
{
    int result = 0;

    if(node == NULL)return 0;

    if((*node)==NULL) // Si el subárbol es nulo, se agrega el nodo ahí
    {
        (*node) = btn_new(value);
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

/**
 * Determinar el nivel de un nodo.
 * - Recibe como entrada la raíz, un valor y una función de comparación de valores.
 */
int _btn_level(btn *node, t_elem_btree value, int level, int cmp(t_elem_btree, t_elem_btree))
{
    if (node == NULL)
        return -1; // Valor no encontrado en el árbol

    if (cmp(value, node->value) == 0)
        return level; // Nivel del nodo encontrado

    int left_level = _btn_level(node->left, value, level + 1, cmp);
    int right_level = _btn_level(node->right, value, level + 1, cmp);

    // Si el nodo no se encuentra en ninguno de los subárboles, retorna -1
    if (left_level == -1 && right_level == -1)
        return -1;

    // Retorna el nivel máximo entre los subárboles izquierdo y derecho
    return (left_level != -1) ? left_level : right_level;
}


int btn_level(btn* root, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree))
{
     if(root == NULL)return 0;

     return _btn_level(root,value,0,cmp);

}


/**
 * Devuelve el valor máximo entre 2 enteros.
 * Función auxiliar utilizada en height.
 */
int _max(int a, int b)
{
    return (a > b) ? a : b;
}

/**
 * Devuelve la altura de un BTN
 */
t_elem_btree btn_height(btn *node)
{
    int result = -1;
    if (node != NULL)
    {
        result = _max(btn_height(node->left), btn_height(node->right)) +1;
    }

    return result;
}

/**
 * Recorrido de un BT en inorden
 * Recibe como parámetros el nodo actual, un puntero a una función que procesa cada nodo y un puntero a un contexto.
 */
/*int btn_inorder(btn *node, int btn_do(t_elem_btree, void*), void* ctx)
{
    if (node == NULL) return 1;

    int r = 1;

    if(r) r = btn_inorder(node->left,btn_do,ctx);
    if(r) r = btn_do(node->value,ctx);
    if(r) r = btn_inorder(node->right,btn_do,ctx);

    return r;
}*/

void btn_inorder(btn *node, void btn_do(btn*, void*), void* ctx)
{
    if (!node) return;

    btn_inorder(node->left,btn_do,ctx);
    btn_do(node,ctx);
    btn_inorder(node->right,btn_do,ctx);
}

/**
 * Recorrido de un BT en postorder
 * Recibe como parámetros el nodo actual, un puntero a una función que procesa cada nodo y un puntero a un contexto.
 */
void btn_postorder(btn *node, void btn_do(btn*, void*), void* ctx)
{
    if (!node) return;

    btn_postorder(node->left,btn_do,ctx);
    btn_postorder(node->right,btn_do,ctx);
    btn_do(node,ctx);
}

/**
 * Recorrido de un BT en preorder
 * Recibe como parámetros el nodo actual, un puntero a una función que procesa cada nodo y un puntero a un contexto.
 */
void btn_preorder(btn *node, void btn_do(btn*, void*), void* ctx)
{
    if (!node) return;

    btn_do(node,ctx);
    btn_preorder(node->left,btn_do,ctx);
    btn_preorder(node->right,btn_do,ctx);

}

btn *removeNode(btn **node)
{
    if (!node) return NULL;
    if (!(*node)) return NULL;

    btn *aux = *node;

    btn_insert(&(aux->right), (aux->left));
    *node = aux->right;
    aux->left = NULL;
    aux->right = NULL;

    return aux;
}

/**************************************************************/
/*                         ADICIONALES                        */
/**************************************************************/

/**
 * DE USO INTERNO para dibujar un árbol.
 */
int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*))
{
    char b[200];
    int width = 5;

    if (!tree) return 0;
    toStr(tree, b);
    //sprintf(b, "%s", str);


    int left = _btn_print(tree->left, 1, offset, depth + 1, s, toStr);
    int right = _btn_print(tree->right, 0, offset + left + width, depth + 1, s, toStr);

    // for (int i = 0; i < width; i++) s[2 * depth][offset + left + i] = b[i];
    for (int i = 0; i < strlen(b); i++) s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left)
    {
        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset + left + width + right + width / 2] = '+';

    }
    else if (depth && !is_left)
    {
        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width / 2 + i] = '-';

        s[2 * depth - 1][offset + left + width / 2] = '+';
        s[2 * depth - 1][offset - width / 2 - 1] = '+';
    }

    return left + width + right;
}

/**
 * Dibuja un árbol binario con caracteres
 * (Los valores de los nodos deben estar entre 0 y 999).
 */
void btn_print(btn *tree, void toStr (btn*, char*))
{
    char s[20][255];
    for (int i = 0; i < 20; i++) sprintf(s[i], "%80s", " ");

    _btn_print(tree, 0, 0, 0, s, toStr);

    for (int i = 0; i < 20; i++)
    {
        int j = 0;
        while (s[i][j] != '\0' && s[i][j] == ' ')
        {
            j++;
        }
        if (s[i][j] != '\0')
        {
            printf("%s\n", s[i]);
        }
    }
}


/** CREA Y ESPEJA EL ARBOL ORIGINAL**/
void mirror(btn** copycat, btn* node)
{
    if (!node) return;

    *copycat = btn_new(node->value);
    mirror(&(*copycat)->right,node->left);
    mirror(&(*copycat)->left,node->right);
}

/** ESPEJA EL MISMO ARBOL  **/
void mirror_2(btn*n)
{
    if(!n) return;

    btn* aux = n->right;
    n->right = n->left;
    n->left = aux;
    mirror_2(n->left);
    mirror_2(n->right);
}

