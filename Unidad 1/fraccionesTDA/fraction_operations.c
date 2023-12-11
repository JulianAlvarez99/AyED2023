#include <stdio.h>
#include <stdlib.h>
#include "fraction_operations.h"

fraccion_t* Fraccion_Ini(fraccion_t* f)
{
    f=(fraccion_t*)malloc(sizeof(fraccion_t)*3);
    if(f==NULL)
    {
        printf("ERROR DE RESERVA DE MEMORIA");
        exit(-12);
    }
    for(int i = 0; i<2; i++)
    {
        printf("Ingrese el numerador de la fraccion #%d: ",i);
        scanf("%d",&f[i].numerador);
        printf("Ingrese el denominador de la fraccion #%d: ",i);
        scanf("%d",&f[i].denominador);
    }
    return f;
}

void imprimirFraccion(fraccion_t* f, int i)
{
    printf("%d/%d", f[i].numerador, f[i].denominador);
}

fraccion_t* Fracciones_Sum(fraccion_t* f)
{
    f[2].denominador = f[0].denominador * f[1].denominador;
    f[2].numerador = (( f[2].denominador/f[0].denominador)*f[0].numerador) + (( f[2].denominador/f[1].denominador)*f[1].numerador);
    return f;
}

fraccion_t* Fracciones_Rest(fraccion_t* f)
{
    f[2].denominador = f[0].denominador * f[1].denominador;
    f[2].numerador = (( f[2].denominador/f[0].denominador)*f[0].numerador - ( f[2].denominador/f[1].denominador)*f[1].numerador);
    return f;
}

fraccion_t* Fracciones_Multi(fraccion_t* f)
{
    f[2].numerador = f[0].numerador * f[1].numerador;
    f[2].denominador = f[0].denominador * f[1].denominador;
    return f;
}

fraccion_t* Fracciones_Div(fraccion_t* f)
{
    f[2].numerador = f[0].numerador * f[1].denominador;
    f[2].denominador = f[0].denominador * f[1].numerador;
    return f;
}

fraccion_t* Fracciones_Simp(fraccion_t* f)
{
    int aux = 0;

    if(f[2].numerador == f[2].denominador)
    {
        f[2].numerador = 1;
        f[2].denominador = 1;
    }
    else
    {
        aux = mcd(f);
        f[2].numerador = f[2].numerador / aux;
        f[2].denominador = f[2].denominador / aux;
    }
    return f;
}

//Funcion Maximo comun Divisor
int mcd(fraccion_t* f)
{
    int multiplo = 10;
    int resto_1 = 1;
    int resto_2 = 1;
    int resto_total = 1;

    while(resto_total != 0)
    {
        resto_1 = (unsigned int)f[2].numerador % multiplo;
        resto_2 = f[2].denominador % multiplo;

        resto_total = resto_1 + resto_2;

        if(resto_total != 0)
        {
            multiplo--;
        }
    }
    return multiplo;
}

int Fracciones_cmp(fraccion_t* f)
{
    float aux_1 = ((float)f[0].numerador/(float)f[0].denominador);
    float aux_2 = ((float)f[1].numerador/(float)f[1].denominador);
    int cmp = 0;

    if(aux_1-aux_2==0)
    {
        cmp = 0;
    }
    if(aux_1 > aux_2)
    {
        cmp = 1;
    }
    if(aux_2 > aux_1)
    {
        cmp = -1;
    }
    return cmp;
}
