#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SBT.h"

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

/**************************************************************/
/*             ÁRBOLES BINARIOS DE BÚSQUEDA                   */
/**************************************************************/

/**
 * Devuelve el valor máximo entre 2 enteros.
 * Función auxiliar utilizada en height.
 */
t_elem_btree _max_elem (t_elem_btree a, t_elem_btree b, int cmp (t_elem_btree, t_elem_btree) )
{
    return (cmp(a, b) > 0) ? a : b;
}


/**
 * Crea un nodo de un BTN en base a un valor t_elem_btree
 */
btn* btn_new(t_elem_btree value)
{
    btn* node = (btn*)malloc(sizeof(btn));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/**
 * Agrega un nodo a un árbol binario de búsqueda (SBT)
 * (no agrega valores repetidos)
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a insertar
 *          *newNode: puntero al nodo que se va a insertar en el SBT
 * Devuelve:
 *  1 si pudo insertar
 *  0 si no pudo insertar
 */
int sbt_insert_node(btn **node, btn *newNode, int cmp (t_elem_btree, t_elem_btree))
{

    if (node == NULL) return 0;
    if (newNode == NULL) return 1;

    int result;

    if((*node)==NULL)
    {
        *node = newNode;
        result = 1;
    }
    else
    {
        if(cmp((*node)->value, newNode->value)<0)
        {
            result = sbt_insert_node(&(*node)->left,newNode,cmp);
        }
        else if (cmp((*node)->value,newNode->value)>0)
        {
            result = sbt_insert_node(&(*node)->right,newNode,cmp);
        }
        else
            result = 0;
        }
    return result;
}

/**
 * Agrega un valor a un árbol binario de búsqueda (SBT)
 * (no agrega valores repetidos)
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a insertar
 *          value: el valor a agregar.
 * Devuelve:
 *  1 si pudo insertar
 *  0 si no pudo insertar
 */

int sbt_insert_value(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree))
{
    if (node == NULL) return 0;
    int result;

    if((*node)==NULL)
    {
        *node = btn_new(value);
        result = 1;
    }
    else
    {
        if(cmp((*node)->value, value)>0)
        {
            result = sbt_insert_value(&(*node)->left,value,cmp);
        }
        else if (cmp((*node)->value,value)<0)
        {
        result = sbt_insert_value(&(*node)->right,value,cmp);
        }
        else
            result = 0;
        }
    return result;
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor mínimo de un
 * SBT.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar
 */
btn** sbt_get_min_node(btn **node)
{
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return node;  // []->nodo

    /**** COMPLETAR ****/
}

/**
 * Devuelve el valor mínimo de un SBT
 */
t_elem_btree sbt_min(btn *node)
{
    /**** COMPLETAR ****/
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor máximo de un
 * SBT.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar
 */
btn** sbt_get_max_node(btn **node)
{
    /**** COMPLETAR ****/
}

/**
 * Devuelve el valor máximo de un SBT
 */
t_elem_btree sbt_get_max_value(btn *node)
{
    if (node == NULL) return -1;
    btn **r = sbt_get_max_node(&node);
    return (*r)->value;
}


/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versión recursiva)
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          *node: el puntero al nodo del sub-árbol donde se
 * va a buscar.
 */
btn* sbt_findr(btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree))
{
    if(node == NULL || cmp(node->value,value)== 0)
    {
        return node;
    }
    else if(cmp(node->value,value)<0)
    {
        return (sbt_findr(node->left,value,cmp));
    }
    else
    {
        return (sbt_findr(node->right,value,cmp));
    }
}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versión iterativa)
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          *node: el puntero al nodo del sub-árbol donde se
 * va a buscar.
 */
btn *sbt_findi(btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree))
{
    /**** COMPLETAR ****/
}


/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor solicitado de
 * un SBT.
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar.
 */
btn** sbt_find_node(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree))
{
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return NULL;  // []->nodo

    /**** COMPLETAR ****/
}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versión iterativa en reducida) *
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          **node: referencia al puntero al nodo del sub-árbol donde se
 * va a buscar.
 * Devuelve una doble puntero para permitir la modificación.
 */
btn** sbt_findii(btn** node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree))
{
    /**** COMPLETAR ****/
}

/**
 * Devuelve 1 si un valor se encuentra en el árbol, o 0 si no se encuentra
 */
int sbt_in(btn* node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree))
{
    /**** COMPLETAR ****/
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por su rama Derecha y agregando
 * la rama Izquierda a la rama derecha.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */
btn* sbt_remove_node(btn **node,  int cmp (t_elem_btree, t_elem_btree))
{
    /**** COMPLETAR ****/
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por el máximo de su rama
 * izquierda, o en su defecto por el mínimo de su rama derecha.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */
btn* sbt_remove_node2(btn **node)
{
    /**** COMPLETAR ****/
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por
 * 1) el máximo de su rama izquierda, si la rama izquierda es igual o más alta
 * que la derecha.
 * 2) el mínimo de su rama derecha, si la rama derecha es más
 * alta que la izquierda.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */
btn *sbt_remove_node_smart(btn **node)
{
    if (!node) return NULL;
    if (!(*node)) return NULL;

    /**** COMPLETAR ****/
}

/**
 * Elimina un valor de un SBT.
 * Usa método de reemplazo por el hijo derecho.
 * Devuelve 1 si pudo eliminarlo,
 * Devuelve 0 si no pudo
 */
int sbt_remove_value(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree))
{
    /**** COMPLETAR ****/
}

/**
 * Elimina un valor de un SBT.
 * Usa método de reemplazo del máximo de la rama izquierda o mínimo de la rama
 * derecha. Devuelve 1 si pudo eliminarlo, o 0 si no pudo.
 */
int sbt_remove_value2(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree))
{
    /**** COMPLETAR ****/
}

/**
 * Elimina un valor de un SBT.
 * Usa método de reemplazo del máximo de la rama izquierda o mínimo de la rama
 * según cual sea más alto.
 * Devuelve 1 si pudo eliminarlo, o 0 si no pudo.
 */
int sbt_remove_value_smart(btn **node, int value, int cmp (t_elem_btree, t_elem_btree))
{
    /**** COMPLETAR ****/
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
