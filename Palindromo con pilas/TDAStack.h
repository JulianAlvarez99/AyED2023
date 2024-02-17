#ifndef TDASTACK_H_INCLUDED
#define TDASTACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define t_elem void*

typedef struct stack_node {
  t_elem value;
  struct stack_node *next;
} stack_node;

typedef struct stack {
  stack_node *head;
  int maxsize;
  int count;
} stack;

stack* stack_new(int maxsize);

void stack_free(stack* s);

int stack_getsize(stack* s);

int stack_getmaxsize(stack* s);

void push(stack* s, t_elem elem);

t_elem pop(stack* s);

t_elem top(stack* s);

int stack_isempty(stack* s);

int stack_isfull(stack* s);

void stack_print(stack* s, void prt (t_elem));

void print_elem (t_elem e);

void stack_destroy(stack* s);

int stack_sum(stack* s);

stack* stack_copy(stack* s);

#endif // TDASTACK_H_INCLUDED
