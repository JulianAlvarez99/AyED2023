#include "FilesFunctions.h"

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

    fseek(fp, -1, SEEK_END);
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

    while(!feof(fp))
    {
    fscanf(fp,"%s%*c",Str);
    Read++;
    }

  /*  if (Read != File_Size)
    {
        printf("No se pudo leer todo el contenido del archivo.\n");
        fclose(fp);
        free(Str);
        return NULL;
    }*/
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
