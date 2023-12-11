#ifndef CHARSET_H_INCLUDED
#define CHARSET_H_INCLUDED
#define MAX 256

typedef struct
{
char str[MAX];
char lenght;
} charset_t;

charset_t* charset_init(charset_t* , int );
void charset_free(charset_t* );
int charset_check(charset_t* , int , char );
void charset_add(charset_t* , char , int );
void charset_remove(charset_t* , char , int );
void charset_union(charset_t* , char* , int );
char charset_intersection(charset_t* , char* , int );
void charset_add_range (charset_t *,unsigned char , unsigned char , int );


#endif // CHARSET_H_INCLUDED
