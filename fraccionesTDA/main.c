#include <stdio.h>
#include <stdlib.h>
#include "fraction_operations.h"


int main() {

int test = 0;

    fraccion_t* fracciones = NULL;
    fracciones = Fraccion_Ini(fracciones);
    fracciones = Fracciones_Sum(fracciones);
    imprimirFraccion(fracciones,0);
    printf(" + ");
    imprimirFraccion(fracciones,1);
    printf(" = ");
    imprimirFraccion(fracciones,2);
    printf(" = ");

    fracciones = Fracciones_Simp(fracciones);
    imprimirFraccion(fracciones,2);

    test = Fracciones_cmp(fracciones);
    printf("\n\n Si da 0 las fracciones son iguales, 1 si A>B o -1 si A<B = %d\n", test);

    free(fracciones);

    return 0;
}
