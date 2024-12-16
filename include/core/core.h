#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifndef CORE_H
#define CORE_H


    // string operations

    uint32_t size(char * s);
    void copystr(char **desStr, char *toCopyFromStr);

#endif