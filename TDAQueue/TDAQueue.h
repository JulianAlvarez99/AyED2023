#ifndef TDAQUEUE_H_INCLUDED
#define TDAQUEUE_H_INCLUDED
#define t_elem void*
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node {
  t_elem value;
  struct queue_node *next;
} queue_node;

typedef struct queue {
  queue_node *head;
  queue_node *tail;
  int maxsize;
  int count;
} queue;

queue* queue_new (int maxsize);

void queue_free (queue* q);

int queue_getsize (queue* q);

int queue_getmaxsize (queue* q);

int queue_isfull (queue* q);

int queue_isempty (queue* q);

void enqueue (queue* q, t_elem elem);

t_elem dequeue (queue* q);

t_elem peek (queue* q);

void queue_print(queue* q , void prt (t_elem));

void print_elem (t_elem e);

queue* queue_copy (queue* q);

int queue_sum (queue* q);


#endif // TDAQUEUE_H_INCLUDED
