#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TDAQueue.h"

int main()
{
    int maxsize = 10;
    queue* q = queue_new(maxsize);

    srand(time(NULL));

    while (!queue_isfull(q))
    {
        int* aux = (int*)malloc(sizeof(int));
        *aux = rand()%100;
        enqueue(q, aux);
    }

    printf("\n%d\n", queue_sum(q));

    queue* q2 = queue_copy(q);

    queue_print(q,print_elem);

    printf("\n\n");

    queue_print(q2,print_elem);



    queue_free(q);
    queue_free(q2);

    return 0;
}
