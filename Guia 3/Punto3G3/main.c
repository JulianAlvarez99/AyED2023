#include <stdio.h>
#include <stdlib.h>

int fibonacci (int f)
{
    if((f == 1) || (f == 2))
    {
        return 1;
    }
    else
    {
        return fibonacci(f-1)+fibonacci(f-2);
    }
}

int fibonacci2(int n)
{
    if (n == 0)
        return 0;
    else
        {if (n == 1)
        {
            return 1;
        }
        else
            return (fibonacci2(n-1) + fibonacci2(n-2));
        }
}

int main()
{
    for(int i = 0; i<10; i++)
    {
    printf("%d -> %d\n",i,fibonacci2(i));
    }
    printf("\n");
    for(int i = 15; i>0; i--)
    {
    printf("%d -> %d\n",i,fibonacci(i));
    }

    return 0;
}
