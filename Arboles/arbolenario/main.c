#include <stdio.h>
#include <stdlib.h>

#define t_elem_ntree int

typedef struct _ntn ntn;

typedef struct _ntlist {
    ntn *node;
    struct _ntlist* next;
} ntlist;

typedef struct _ntn {
    t_elem_ntree value;
    ntlist *sons;
} ntn;

typedef struct _listint
{
    int e;
    struct _listint *next;

}listint;

void printProfundidad (ntn *node){
    if (node == NULL) return;

    printf(" %d ", node->value);

    ntlist *l = node->sons;
    while (l != NULL){
        printProfundidad(l->node);
        l = l->next;
    }

}

ntn* ntn_new(t_elem_ntree value){
    ntn* n = (ntn*)malloc(sizeof(ntn));
    n->value = value;
    n->sons = NULL;
    return n;
}

ntlist* ntl_new(ntn* node){
    ntlist* n = (ntlist*)malloc(sizeof(ntlist));
    n->node = node;
    n->next = NULL;
    return n;
}

int ntl_insert (ntlist** nodoList, ntlist* newNodoList){
    if (nodoList == NULL) return 0; //error
    if (*nodoList == NULL){
        *nodoList = newNodoList;
    } else {
        ntl_insert (&((*nodoList)->next), newNodoList);
    }
    return 1;
}

int ntn_insert_son (ntn* node, ntn* newNode){
    if (node == NULL) return 0;
    return ntl_insert(&(node->sons), ntl_new(newNode));
}

int ntn_remove_node (ntn* root, ntn* node){
    if (!root) return 0;
    if (!node) return 0;

    int result = 0;
    ntlist** l = &(root->sons);
    while ((result == 0) && (*l != NULL)){
        if (node == (*l)->node) {
            ntlist *aux = *l;
            *l = aux->next;
            aux->node = NULL;
            aux->next = NULL;
            free(aux);
            result = 1;
        } else {
            result = ntn_remove_node ((*l)->node, node);
        }
        l = &(*l)->next;
    }

    return result;
}

int _max(int a, int b)
{
    return (a > b) ? a : b;
}

int grado_childs(ntlist* childs)
{
    int count = 0;
    while(childs != NULL)
    {
        count = count +1;
        childs = childs->next;
    }
    return count;
}

int grado (ntn* root)
{
    if (root == NULL) return 0;
    int aux;
    int aux2;

    aux = grado_childs(root->sons);
    ntlist *l = root->sons;
    while (l != NULL)
    {
        aux2 = grado(l->node);
        l = l->next;
    }
    return 1+_max(aux,aux2);
}

void _en_nivel (ntn* node, int nivel, int actual, listint** auxl)
{
    if (node == NULL) return;

    if(nivel==actual)
    {
    ntlist *l = node->sons;
    while (l != NULL)
    {
        auxl->e = l->node->value;
        l = l->next;
    }
    _en_nivel(node->sons->next,nivel,actual,&(*auxl);
    }
    else
    {
    _en_nivel(node->sons,nivel,actual+1,&auxl);
    }
}

listint* en_nivel(ntn* root, int nivel)
{
    listint *list = newlist();
    _en_nivel(root,nivel,0,&list);
    return list;
}

int main()
{
    ntn* tree = ntn_new(1);
    ntn_insert_son (tree, ntn_new(2));


    printf("Hello world!\n");
    return 0;
}
