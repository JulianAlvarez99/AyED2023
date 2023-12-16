#include "TDAQueue.h"


queue_node* _queue_node_new(t_elem elem)
{
    queue_node* new_node = (queue_node*)malloc(sizeof(queue_node));

    if(new_node != NULL)
    {
        new_node->value = elem;
        new_node->next = NULL;
    }
    return new_node;
}

queue* queue_new (int maxsize)
{
    queue* aux = (queue*)malloc(sizeof(queue));
    if(aux != NULL)
    {
        aux->head = NULL;
        aux->tail = NULL;
        aux->count = 0;
        aux->maxsize = maxsize;
    }
    return aux;
}

void _node_free(queue_node** h)     /**LIBERA UN NODO Y SE REAPUNTA AL SIGUIENTE NODO**/
{
    if(*h != NULL)
    {
        queue_node* aux = *h;
        aux = (*h)->next;
        free(*h);
        *h = aux;
    }
}

void queue_free (queue* q)
{
    _node_free(&q->head);
}

int queue_getsize (queue* q)
{
    return q->count;
}

int queue_getmaxsize (queue* q)
{
    return q->maxsize;
}

int queue_isfull (queue* q)
{
    return(q->count == q->maxsize);
}

int queue_isempty (queue* q)
{
    return(q->count == 0);
}

void enqueue (queue* q, t_elem elem)
{
    if(q != NULL)
    {
        queue_node* newNode = _queue_node_new(elem);

        if(queue_isempty(q))
        {
            q->head = newNode;
            q->tail = newNode;
        }
        else
        {
            q->tail->next = newNode;
            q->tail = q->tail->next;
        }
        q->count++;
    }
}

t_elem dequeue (queue* q)
{
    t_elem erased;

    if(q != NULL)
    {
        erased = peek(q);
        queue_free(q);
        q->count--;
    }
    return erased;
}

t_elem peek (queue* q)
{
    return q->head->value;
}

void print_elem (t_elem e)
{
    printf("%d ", *(int*)e);
}

void queue_print(queue* q, void prt(t_elem))
{
    queue* aux = queue_new(queue_getmaxsize(q));
    while (!queue_isempty(q))
    {
        prt(peek(q));
        enqueue(aux, dequeue(q));
    }

    while (!queue_isempty(aux))
    {
        enqueue(q, dequeue(aux));
    }
    queue_free(aux);
}

queue* queue_copy (queue* q)
{
    queue* aux = queue_new(queue_getmaxsize(q));
    while (!queue_isempty(q))
    {
        enqueue(aux, dequeue(q));
    }

    queue* result = queue_new(queue_getmaxsize(aux));
    while (!queue_isempty(aux))
    {
        enqueue(q, peek(aux));
        enqueue(result, dequeue(aux));
    }
    queue_free(aux);
    return result;
}

int queue_sum (queue* q)
{
    queue* aux = queue_new(queue_getmaxsize(q));
    while (!queue_isempty(q))
    {
        enqueue(aux, dequeue(q));
    }

    int result = 0;
    while (!queue_isempty(aux))
    {
        result += *(int*)peek(aux);
        enqueue(q, dequeue(aux));
    }
    queue_free(aux);
    return result;
}

