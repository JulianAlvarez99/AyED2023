#ifndef FRACTION_OPERATIONS_H_INCLUDED
#define FRACTION_OPERATIONS_H_INCLUDED

typedef struct
{
int numerador;
int denominador;

}fraccion_t;

fraccion_t* Fraccion_Ini(fraccion_t* f);
void imprimirFraccion(fraccion_t* f, int i);
fraccion_t* Fracciones_Sum(fraccion_t* f);
fraccion_t* Fracciones_Rest(fraccion_t* f);
fraccion_t* Fracciones_Multi(fraccion_t* f);
fraccion_t* Fracciones_Div(fraccion_t* f);
fraccion_t* Fracciones_Simp(fraccion_t* f);
int mcd(fraccion_t* f);
int Fracciones_cmp(fraccion_t* f);




#endif // FRACTION_OPERATIONS_H_INCLUDED
