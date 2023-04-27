#include <stdio.h>
#include <stdlib.h>

int sum_recursiva (int a)
{
    if(a==0)
    {
        return 0;
    }
    else
        return(a+sum_recursiva(a-1));
}

int main()
{
    printf("La suma de los n primeros numeros naturales es: %d \n", sum_recursiva(9));
    return 0;
}
