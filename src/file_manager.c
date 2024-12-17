#include "file_manager.h"

#include <stdio.h>

#include "core.h"

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

void write_file(FileHandler *file, const char * text, const char * mode)
{
    const char *arr[] = {"w", "a"};

    if(indexOf_arr(arr, mode) == -1)
    {
        printf("unauthorized mode\n");
        return;
    }
         
    file->fptr = fopen(file->path, mode);

    if(file->fptr == NULL)
    {
        printf("couldn't open file at: %s", file->path);
        return;
    }

    fprintf(file->fptr, "%s\n", text);
    fclose(file->fptr);
}

/*
void read_file(FileHandler * file, const char * mode)
{
    const char * arr = {"r", "rb"};

    if(indexOf(arr, mode) == - 1) 
    {
        return;
    }

    file->fptr = fopen(file->path, mode);

    char c;
    
} 
*/