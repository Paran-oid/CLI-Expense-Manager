#include "core.h"

uint32_t size(char * s)
{
    uint32_t res = 0;
    while(s[res] != '\0')
    {
        res++;
    }
    return res;
}

void copystr(char **desStr, char *toCopyFromStr)
{
    uint32_t i = 0;

    if(size(toCopyFromStr) > size(*desStr))
    {
        free(*desStr);
        *desStr = (char *) malloc(sizeof(char) * (size(*desStr) + 1));
        if(*desStr == NULL)
        {
            printf("Memory allocation failed for copying the string\n");
            return;
        }
    }

    while(toCopyFromStr[i] != '\0')
    {
        *desStr[i] = toCopyFromStr[i];
    } 
}