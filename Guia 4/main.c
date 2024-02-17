#include <stdio.h>
#include <stdlib.h>
#define t_elem int
#include <time.h>

/********************************************************************/
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

/**********************************************************************/


/** PUNTO 1 **/

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


/** PUNTO 2 **/

sll_node_t* sll_merge_sorted(sll_node_t* head1, sll_node_t* head2){
    sll_node_t* result = NULL;

    if (head2 == NULL) {
        result = head1;
    } else if (head1 == NULL) {
        result = head2;
    } else { //(head1 != NULL && head2 != NULL)
        if (head1->value < head2->value) {
            result = head1;
            result->next = sll_merge_sorted(head1->next, head2);
        } else {
            result = head2;
            result->next = sll_merge_sorted(head1, head2->next);
        }
    }
    return result;
}

/** PUNTO 3 **/

t_elem sll_check_sort(sll_node_t** head)
{
    int result = 0;

    if(*head != NULL)
    {
        sll_node_t* aux = *head;

        aux = (*head)->next;

        if((*head)->value < aux->value)
        {
            sll_check_sort(&(*head)->next);
            result = 1;
        }
    }
    return result;
}

/** PUNTO 4 **/

sll_node_t* sll_invert_order(sll_node_t* head)
{

    sll_node_t* prev = NULL;
    sll_node_t* current = head;
    sll_node_t* next = NULL;

    if(head != NULL)
    {
        while(current!= 0)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        //head = prev;
    }
    return prev;
}

void sll_print(sll_node_t *head)
{
    if(head==NULL)
    {
        printf("\n");
    }
    else{
        printf("%d ",head->value);
        sll_print(head->next);
    }
}

/***** PUNTO 6 Dada una SSL de números enteros, obtener el valor mínimo******/
sll_node_t* sll_min_value(sll_node_t* head)
{
    sll_node_t* aux = head;
    if(head!=NULL)
    {
        sll_node_t* min = sll_min_value(head->next);
        if((min != NULL) && (min->value < aux->value))
        {
            aux = min;
        }
    }
     return aux;
}

/*** PUNTO 7 Dividir una SSL de números enteros en 2 listas una con los números pares y otra con los impares. ***/

void sll_even_odd(sll_node_t* head, sll_node_t** even, sll_node_t** odd)
{
    if(head != NULL)
    {
        if(head->value%2 == 0)
        {
            *even = head;
            sll_even_odd(head->next,&(*even)->next,odd);
        }
        else
        {
            *odd = head;
            sll_even_odd(head->next,even,&(*odd)->next);
        }
    }
}

/***PUNTO 8 Recibir una SSL cuyo elemento es otra SSL de números enteros, obtener valor máximo del promedio máximo de las sub listas. ***/
#define t_list_elem void* 
/**MUCHO MUY IMPORTANTE, CON EL TIPO DE ELEMENTO COMO PUNTERO A VOID PUEDO MANEJAR CUALQUIER TIPO DE DATO ***/

typedef struct _sll
{
    t_list_elem value;
    struct _sll *next;
}sll;


float sll_Avg_list(sll* head)
{
    if(!head) return 0;
    
    int sum = 0;
    int elements = 0;
    
    while(head != NULL)
    {
        sum += *((int*)head->value);
        elements++;
        head = head->next;
    }
  return sum/elements;
}

float sll_MaxAvg_of_sublist(sll** head)
{
    if(!(*head)) return 0;

    sll *aux_list = *head;
    float max = 0.0;
    float witness = 0.0;

    while(aux_list != NULL)
    {
        witness = sll_Avg_list((sll*)aux_list->value);
        if(witness > max)
        {
		max = witness;
	}
	aux_list = aux_list->next;
    }
return max;
}

int main()
{
    srand(time(NULL));
    sll_node_t *new_list = NULL;
    //sll_node_t *min = NULL;

    sll_node_t* even = (sll_node_t*)malloc(sizeof(sll_node_t));
    sll_node_t* odd = (sll_node_t*)malloc(sizeof(sll_node_t));

    for(int i = 0; i<20; i++)
    {
        sll_add_first(&new_list,rand()%100);
    }

    sll_print(new_list);

    //new_list = sll_invert_order(new_list);
   // min = sll_min_value(new_list);
    //printf("\n%d\n\n",min->value);

    sll_even_odd(new_list,&even,&odd);
    sll_print(even);
    sll_print(odd);

    free(new_list);
    free(even);
    free(odd);
    getc(stdin);
    return 0;
}
