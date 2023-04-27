#include <stdio.h>
#include <stdlib.h>

float Exp_recursivo(int base, int exp)
{
    if(exp == 0)
    {
        return 1;
    }
    if(exp>0)
    {
        return(base*Exp_recursivo(base,exp-1));
    }
    else
    {
        return(1.0/base*Exp_recursivo(base,exp+1));
    }
}

int main()
{
    float resultado = 0;

    resultado = Exp_recursivo(6,3);

    printf("El resultado es %d\n",(int)resultado);

    resultado = Exp_recursivo(2,0);

    printf("El resultado es %d\n",(int)resultado);

    resultado = Exp_recursivo(2,-5);

    printf("El resultado es %0.4f\n",resultado);
    return 0;
}
