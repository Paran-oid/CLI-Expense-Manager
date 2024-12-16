#include "file_manager.h"

#include <stdio.h>

void init_file(FileHandler *file, const char * path)
{
    file->path = path;
    file->fptr = fopen(file->path, "r");
    if(file->fptr == NULL)
    {
        printf("failed to allocate memory for the file\n");
        return;
    }
    fclose(file->fptr);
}

void write_file(FileHandler *file, const char * text)
{
    file->fptr = fopen(file->path, "w");

    fprintf(file->fptr ,"%s\n", text);
    fclose(file->fptr);
}