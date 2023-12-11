#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "FilesFunctions.h"

int main()
{
    sll_node_t *head = NULL;
    t_elem str = NULL;


   /* t_elem element[50] = {"perro","pera","bicicleta","manzana","gato","globo","leon","lima","pintura","pintura",
                         "perro","pintura","lima","lapiz","computadora","pelota","platano","cama","perro",
                         "perro","pintura","pintura","maiz","gato","bicicleta","gato","bicicleta","gato",
                         "perro","perro","lima","cebolla","gato","gato","pantalla","caja","pajaro",
                         "perro","bicicleta","pavo","reloj","lima","pala","gato","loro","frasco","gato","lampara","lima","cepillo"};*/


    str = Read_file("entregable2_TEXTO.txt");

    for(int i =0; i<100; i++)
    {
    sll_add_first(&head, &str[i]);
    }

    sll_print(head);
    getc(stdin);

    sll_print2(head);

    free(head);
    free(str);


    return 0;
}
