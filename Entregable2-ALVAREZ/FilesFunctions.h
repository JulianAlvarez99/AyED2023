#ifndef FILESFUNCTIONS_H_INCLUDED
#define FILESFUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define t_elem char*

int File_Existance(const char *File);
t_elem Text_Lecture(char *File, t_elem str);
int txt_size(FILE* fp);
t_elem Ptr_Memory(long File_Size, FILE* fp);
t_elem File_lecture(t_elem Str, long File_Size ,FILE* fp);
t_elem Read_file(const t_elem File);

#endif // FILESFUNCTIONS_H_INCLUDED
