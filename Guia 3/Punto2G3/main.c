#include <stdio.h>
#include <stdlib.h>

int prod_recursivo(int a, int b)
{
    if(b==0)
    {
        return 0;
    }
    else
        return(a+prod_recursivo(a,b-1));
}

int main()
{
    printf("%d\n",prod_recursivo(5,23));

    return 0;
}
