#include "num_vector.h"
#include "matrix_num.h"
#include <time.h>

// rellenar la matriz con numeros aleatorios
void fill_vector(num_vector* v, int max)
{
    int i = 0;
    float aux;
    i++;
    srand(time(NULL)+i);
    for (i = 0; i < v->vec->MAX_size; i++)
    {
        int auxi = rand() % max;
        //aux = (float)rand()/(float)(RAND_MAX/100);
        aux = auxi;
        num_vector_add(v, aux);
    }
}

num_vector* colapse_sum_rows(num_matrix* m)
{
    num_vector* result = num_vector_new(num_matrix_rows(m));
    int rows = num_matrix_rows(m),
        cols = num_matrix_columns(m);
    float acumulator = 0.0;

    for(int j = 0; j<cols; j++)
    {
        for(int i = 0; i<rows; i++)
        {
            acumulator += num_matrix_get(m,i,j);
        }
        num_vector_add(result,acumulator);
        acumulator = 0.0;
    }
    return result;
}
num_vector* colapse_sum_cols(num_matrix* m)
{
    num_vector* result = num_vector_new(num_matrix_rows(m));
    int rows = num_matrix_rows(m),
        cols = num_matrix_columns(m);
    float acumulator = 0.0;

    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            acumulator += num_matrix_get(m,i,j);
        }
        num_vector_add(result,acumulator);
        acumulator = 0.0;
    }
    return result;
}
num_vector* colapse_avg_rows(num_matrix* m)
{
    num_vector* result = colapse_sum_rows(m);
    int len = num_vector_size(result);

    for(int i = 0; i<len; i++)
    {
        num_vector_set(result,i,(num_vector_get(result,i))/num_matrix_rows(m));
    }
    return result;
}
num_vector* colapse_avg_cols(num_matrix* m)
{
    num_vector* result = colapse_sum_cols(m);
    int len = num_vector_size(result);

    for(int i = 0; i<len; i++)
    {
        num_vector_set(result,i,(num_vector_get(result,i))/num_matrix_columns(m));
    }
    return result;
}


num_matrix* num_matrix_sum(num_matrix* m1, num_matrix* m2)
{
    num_matrix* m3 = num_matrix_new(num_matrix_rows(m1),num_matrix_columns(m1));
    if((num_matrix_rows(m1) == num_matrix_rows(m2))&&(num_matrix_columns(m1) == num_matrix_columns(m2)))
    {
        int rows = num_matrix_rows(m1),
            cols = num_matrix_columns(m1);

        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                num_matrix_set(m3,i,j,(num_matrix_get(m1,i,j) + num_matrix_get(m2,i,j)));
            }
        }
    }
    else
    {
        num_matrix_free(m3);
    }
    return m3;
}

num_matrix* num_matrix_sumVec(num_matrix* m1, num_vector* v)
{
    num_matrix* m2 = num_matrix_new(num_matrix_rows(m1),num_matrix_columns(m1));
    if((num_matrix_columns(m1) == num_vector_size(v)))
    {
        int rows = num_matrix_rows(m1),
            cols = num_matrix_columns(m1);

        for(int i = 0; i<rows; i++)
        {
            for(int j = 0; j<cols; j++)
            {
                num_matrix_set(m2,i,j,(num_matrix_get(m1,i,j) + num_vector_get(v,j)));
            }
        }
    }
    else
    {
        num_matrix_free(m2);
    }
    return m2;
}

    void test_vector_float()
    {

        num_vector* a = num_vector_new(3);
        num_vector* b = num_vector_new(12);

        printf("\n\nInicio pruebas de vector de flotantes\n");
        fill_vector (a, 10);
        fill_vector (b, 10);

        printf("\nVector A\n");
        num_vector_print(a);
        printf("\nVector B\n");
        num_vector_print(b);

    }


    void fill_matrix(num_matrix* m, int max)
    {
        static int i = 0;
        float aux;
        i++;
        srand(time(NULL)+i);
        for (int i = 0; i < num_matrix_rows(m); i++)
        {
            for (int j = 0; j < num_matrix_columns(m); j++)
            {
                int auxi = rand() % max;
                //aux = (float)rand()/(float)(RAND_MAX/100);
                aux = auxi;
                num_matrix_set(m, i, j, aux);
            }
        }
    }

double determinante(num_matrix* m)
{
    double aux;
    double det = 1;
    int d = num_matrix_rows(m);
    for(int k=0; k<d-1; k++) //recorrer la diagonal
    {
        det*=(double)num_matrix_get(m,k,k);
        if(num_matrix_get(m,k,k)==0)
            return 0;
        else
        {
            for(int i=k+1; i<d; i++) //recorrer fila
            {
                aux = -num_matrix_get(m,i,k);
                for(int j=k; j<d; j++)
                {
                    num_matrix_set(m,i,j,(num_matrix_get(m,i,j) + aux * (num_matrix_get(m,k,j)/num_matrix_get(m,k,k))));
                }

            }
        }

    }
    det *= num_matrix_get(m,d-1,d-1);
    return abs(det);
}

    int main()
    {
        num_matrix* a = num_matrix_new(5, 4);
        num_matrix* b = num_matrix_new(5, 5);



        printf("\n\nInicio pruebas de matriz de flotantes\n");
        fill_matrix (a, 10);
        fill_matrix (b, 10);

        printf("\nMatriz A\n");
        num_matrix_print(a);
        printf("\nMatriz B\n");
        num_matrix_print(b);


        num_vector* vec = num_vector_new(4);
        printf("\n\nInicio pruebas de vector de flotantes\n");
        fill_vector (vec, 10);

        printf("\nVector A\n");
        num_vector_print(vec);

        /*num_vector* result_1 = colapse_avg_rows(a);
        num_vector* result_2 = colapse_avg_cols(a);

        printf("\nResultado del promedio de las columnas de cada fila\n");
        num_vector_print(result_1);
        printf("\nResultado del promedio de las filas de cada columna\n");
        num_vector_print(result_2);

        num_vector_free(result_1);
        num_vector_free(result_2);*/

        num_matrix* c = num_matrix_sumVec(a,vec);
        printf("\nMatriz suma con vector en cada fila\n");
        num_matrix_print(c);

        printf("\n\n Determinante de la matriz b: %f", determinante(b));


        num_matrix_free(a);
        num_matrix_free(b);
        num_vector_free(vec);
        num_matrix_free(c);

        //test_vector_float();
        return 0;
    }
