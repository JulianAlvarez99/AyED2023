#ifndef SBT_H_INCLUDED
#define SBT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define t_elem_btree int

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

typedef struct _btn
{
    t_elem_btree value;
    struct _btn *left;
    struct _btn *right;

}btn;


t_elem_btree _max_elem (t_elem_btree a, t_elem_btree b, int cmp (t_elem_btree, t_elem_btree) );
btn* btn_new(t_elem_btree value);
int sbt_insert_node(btn **node, btn *newNode, int cmp (t_elem_btree, t_elem_btree));
int sbt_insert_value(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));
btn** sbt_get_min_node(btn **node);
t_elem_btree sbt_min(btn *node);
btn** sbt_get_max_node(btn **node);
t_elem_btree sbt_get_max_value(btn *node);
btn* sbt_findr(btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));
btn *sbt_findi(btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));
btn** sbt_find_node(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));
btn** sbt_findii(btn** node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));
int sbt_in(btn* node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));
btn* sbt_remove_node(btn **node,  int cmp (t_elem_btree, t_elem_btree));
btn* sbt_remove_node2(btn **node);
btn *sbt_remove_node_smart(btn **node);
int sbt_remove_value(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));
int sbt_remove_value2(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));
int sbt_remove_value_smart(btn **node, int value, int cmp (t_elem_btree, t_elem_btree));
int _btn_print(btn *tree, int is_left, int offset, int depth, char s[20][255], void toStr (btn*, char*));
void btn_print(btn *tree, void toStr (btn*, char*));

#endif // SBT_H_INCLUDED
