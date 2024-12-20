#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdio.h>

typedef struct
{
    const char *path;
    FILE  *fptr;

} FileHandler;

#endif