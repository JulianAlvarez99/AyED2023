#include <stdio.h>
#include <stdlib.h>

#define t_ntn_elem int
#define t_queue_elem ntn*

typedef struct _ntn
{
    t_ntn_elem value;
    ntlist *sons;
} ntn;

typedef struct _ntlist
{
    ntn *node;
    struct _ntlist *next;
} ntlist;

int queue_iseven(queue* q)
{
    if(!q) return 0;

    int lenght = queue_getsize(q);
    int result = 0;
    ntn* node = NULL;

    for(int i = 0; i<lenght; i++)
    {
        node = (ntn*)dequeue(q);
        if((node->value % 2) == 0)
        {
            result++;
        }
        enqueue(q,node);
    }
    if(result == lenght)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int primer_nivel_par(ntn* root)
{
    if(!root) return -1;

    int lvl = 0;
    if((root->value % 2) != 0)
    {
        queue* nodes_bus = queue_new();
        int parents_count = 0;
        int is_even = 0;

        enqueue(nodes_bus,root);
        parents_count = queue_getsize(nodes_bus);
        while(!queue_isempty(nodes_bus))
        {
            root = (ntn*)dequeue(nodes_bus);
            parents_count--;
            ntlist* aux_list = root->sons;
            while(aux_list != NULL)
            {
                enqueue(nodes_bus,aux_list->node);
                aux_list = aux_list->next;
            }
            if(parents_count == 0)
            {
                lvl++;
                parents_count = queue_getsize(nodes_bus);
                if(queue_iseven(nodes_bus))
                {
                    queue_free(nodes_bus);
                    is_even = 1;
                }
            }
        }
        if(is_even == 0)
        {
            lvl = -1;
        }
    }
    return lvl;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
