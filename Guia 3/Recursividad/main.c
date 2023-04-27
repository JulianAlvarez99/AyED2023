#include <stdio.h>
#include <stdlib.h>

long factorial(long n)
{
    if(n == 0)
    {
        return 1;
    }
    else
        return n*factorial(n-1);
}

//MINIMO DE UN ARREGLO

int min (int a, int b)
{
    if(a < b)
    {
        return a;
    }
    else
        return b;
}

int array_min(int a[], int n)
{
    if(n==1)
    {
        return a[0];
    }
    else
        return min(a[n-1], array_min(a,n-1));
}


/*int main()
{
   int a[] = {3,4,1,5,8};

   printf("%d", array_min(a,5));

    return 0;
}*/


int str_length(char* s)
{
    if(*s == '\0')
    {
        return 0;
    }
    else
        return (1 + str_length(s+1));
}
/*
int main()
{
    char* s = {"Hola!"};

    int n = str_length(s);
    printf("%d",n);

    return 0;
}*/

void array_print(int* a, int n)
{
        if(n > 0)
        {
          array_print(a+1,n-1); //si se cambia de lugar el printf, ya sea arriba o abajo, cambia el orden de impresion
          printf("%d\n",*a);
        }
}

/*
int main ()
{
    int a[5] = {3,1,2,5,9};

    array_print(a,5);
    return 0;
}*/

/*
void _array_print(vector* v, int i)
{
    if(vector_size(v)>i)
    {
    printf("%d",vectgor_get(v,i));
    array_print(v,i+1);
    }
}

void array_print(vector* v)
{
    _array_print(v,0);
}
*/

int fibonacci (int f)
{
    int result = 1;
    if(f > 1)
    {
        result = fibonacci(f-1)+fibonacci(f-2);
    }
    return result;
}


/*void hanoi (int n, char o, char d, char aux)
{
    if(n > 0)
    {
        hanoi(n-1,o,aux,d);
        printf("%c -> %c\n", o,d);
        hanoi(n-1,aux,d,o);
    }
}*/

int hanoi (int n)
{
    if(n > 0)
    {
        return( hanoi(n-1) + 1 + hanoi(n-1));
    }
}

void hanoi_n(int n, int i)
{
    i--;
    if(n>0)
    {
    hanoi_n(n-1,i);
    printf("%d -> %d\n", i, hanoi(n-1));
    }
}

int main ()
{
    hanoi_n(64,64);
    return 0;
}

