#include <stdio.h>
#include <stdlib.h>
#define t_elem char*

typedef struct sll_node
{
    t_elem value;
    struct sll_node* next;

} sll_node_t;


sll_node_t* sll_new_node(t_elem element)
{
    sll_node_t* new_node = (sll_node_t*)malloc(sizeof(sll_node_t));

    if (new_node != NULL)
    {
        new_node->value = element;
        new_node->next = NULL;
    }

    return new_node;
}


void sll_add_first(sll_node_t** head, t_elem element)
{
    sll_node_t* aux = sll_new_node(element);
    aux->next = *head;
    *head = aux;
}


int sll_remove_element5(sll_node_t** head, t_elem element)
{
    int result = 0;
    if (*head != NULL)
    {
        result += sll_remove_element5(&(*head)->next, element);
        if ((*head)->value == element)
        {
            sll_node_t* aux = *head;
            *head = (*head)->next;
            aux->next = NULL;
            free(aux);
            result++;
        }
    }
    return result;
}

void sll_remove_repeated(sll_node_t ** head)
{
    int result = 0;
    if(*head != NULL)
    {
        result += sll_remove_element5(&(*head)->next, (*head)->value);
        sll_remove_repeated(&(*head)->next);
    }
    printf("%d",result); //IMPRIME ENTEROS EN FILA EN EL ORDEN EN QUE FUERON TIPEADOS, LO QUE IMPRIME SON LA CANTIDAD DE VECES QUE SE REPITEN CADA PALABRA
}

int _sll_search_repeated(sll_node_t** head, t_elem element)
{
    int result = 0;
    if (*head != NULL)
    {
        result += _sll_search_repeated(&(*head)->next, element);
        if ((*head)->value == element)
        {
            result++;
        }
    }
    return result;
}

int sll_search_repeated(sll_node_t ** head)
{
    int result = 0;

    if(*head != NULL)
    {
       result += _sll_search_repeated(&(*head)->next, (*head)->value);
       sll_search_repeated(&(*head)->next);
    }

  return result;
}

/*void sll_print(sll_node_t *head, int count)
{
    if(head==NULL)
    {
        printf("\n");
    }
    else{
        printf("%s ",head->value);
        count++;
        if(count == 5)
        {
            printf("\n");
            count = 0;
        }
        sll_print(head->next,count);
    }
}*/

void sll_print(sll_node_t *head)
{
    if(head==NULL)
    {
        printf("\n");
    }
    else{
        printf("%s ",head->value);
        sll_print(head->next);
    }
}

void sll_print2(sll_node_t *head)
{
    if(head==NULL)
    {
        printf("\n");
    }
    else{
        printf("%s ==> %d repeticiones\n",head->value, sll_search_repeated(&head));
        sll_print2(head->next);
    }
}

/*********************/
int File_Existance(const char *File)
{
    FILE *fp = NULL;
    fp = fopen(File,"r");
    if(fp == NULL)
    {
        perror("Error: \n");
        exit(1);
    }
    fclose(fp);
    return 0;
}

t_elem Text_Lecture(char *File, t_elem str)
{
    FILE *fp;

    fp = fopen(File,"r");
    File_Existance(File);

    fscanf(fp,"%s",str);
    fclose(fp);
    return str;
}

int txt_size(FILE* fp)
{
    long length = 0;

    fseek(fp, -2, SEEK_END);
    length = ftell(fp);
    rewind(fp);

    return length;
}

t_elem Ptr_Memory(long File_Size, FILE* fp)
{
    t_elem ptr = NULL;

    ptr = (t_elem) malloc(File_Size * sizeof(t_elem));
    if (ptr == NULL)
    {
        perror("No se pudo reservar memoria.\n");
        fclose(fp);
        return (NULL);
    }
    return ptr;
}

t_elem File_lecture(t_elem Str, long File_Size ,FILE* fp)
{
   int Read = 0;

    Read = fread(Str, sizeof(char), File_Size, fp);
    if (Read != File_Size)
    {
        printf("No se pudo leer todo el contenido del archivo.\n");
        fclose(fp);
        free(Str);
        return NULL;
    }
    return Str;
}

t_elem Read_file(const t_elem File)
{
    t_elem Str = NULL;
    long File_Size = 0;

    File_Existance(File);

    FILE* fp = NULL;
    fp = fopen(File,"r");
    File_Size = txt_size(fp);   // Obtener el tamaño del archivo

    Str = Ptr_Memory(File_Size,fp); // Reservar memoria para almacenar el Str del archivo

    Str = File_lecture(Str,File_Size,fp); // Leer el Str del archivo

    Str[File_Size] = '\0';// Agregar un terminador de cadena al final del Str

    fclose(fp);
    return Str;
}

/*********************/

int main()
{
    sll_node_t *head = NULL;
    t_elem str = NULL;
    int length = 0;

   /* t_elem element[50] = {"perro","pera","bicicleta","manzana","gato","globo","leon","lima","pintura","pintura",
                         "perro","pintura","lima","lapiz","computadora","pelota","platano","cama","perro",
                         "perro","pintura","pintura","maiz","gato","bicicleta","gato","bicicleta","gato",
                         "perro","perro","lima","cebolla","gato","gato","pantalla","caja","pajaro",
                         "perro","bicicleta","pavo","reloj","lima","pala","gato","loro","frasco","gato","lampara","lima","cepillo"};*/


    str = Read_file("entregable2_TEXTO.txt");
    length = sizeof(str)/sizeof(t_elem);


    for(int i =0; i<length; i++)
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
