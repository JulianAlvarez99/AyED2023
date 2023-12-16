#include "TDAPilas.h"
#include <time.h>

/*********************************************************************/
// copy stack
stack* stack_copy(stack* s)
{
    stack* aux = stack_new(stack_getmaxsize(s));
    while (!stack_isempty(s))
    {
        push(aux, pop(s));
    }

    stack* result = stack_new(stack_getmaxsize(s));
    while (!stack_isempty(aux))
    {
        push(s,top(aux));
        push(result, pop(aux));
    }

    return result;
}

int main()
{

    printf("OK!\n");

    stack* s = stack_new(10);
    srand(time(NULL));
    while (!stack_isfull(s))
    {
        int* aux = (int*)malloc(sizeof(int));
        *aux = rand()%100;
        push(s, aux);
    }

    stack* s2 = stack_copy(s);

    printf("\nPila 1\n");
    stack_print(s,print_elem);

    printf("\nPila 2\n");
    stack_print(s2,print_elem);

    printf("\n%d\n",stack_sum(s));

    stack_destroy(s);
    stack_destroy(s2);

    return EXIT_SUCCESS;
}
