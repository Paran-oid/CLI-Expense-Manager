#include "core.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

// STRING SECTION

size_t size_str(const char * s)
{
    uint32_t res = 0;
    while(s[res] != '\0')
    {
        res++;
    }
    return res;
}

void copy_str(char **desStr, const char *toCopyFromStr)
{
    size_t len = size_str(toCopyFromStr);

    if(*desStr == NULL || len > size_str(*desStr))
    {
        free(*desStr);
        *desStr = (char *) malloc((len + 1) * sizeof(char));
        if(*desStr == NULL)
        {
            printf("Memory allocation failed for copying the string\n");
            return;
        }
    }

        for(size_t i = 0; i < len; i++)
        {
            (*desStr)[i] = toCopyFromStr[i];
        }

        (*desStr)[len] = '\0';

}

bool comp_str(const char * str1,const char * str2)
{
    if(size_str(str1) != size_str(str2)){return false;}

    unsigned int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str1[i] != str2[i])
        {
            return false;
        }
        i++;
    }
    return true;
}

void concat_str(char ** str, const char * addedStr)
{
    if (str == NULL || *str == NULL || addedStr == NULL)
    {
        printf("Invalid pointer passed.\n");
        return;
    }

    int n = size_str(*str) +  size_str(addedStr);
    char *s = realloc(*str ,n + 1);


    if(s == NULL)
    {
        printf("memory allocation failed \n");
        return;
    }

    for(uint32_t i = 0; i < size_str(*str); i++)
    {
        s[i] = (*str)[i];
    }

    uint32_t k = 0;

    for(uint32_t i = size_str(*str); i < n; i++)
    {
        s[i] = addedStr[k++];
    }

    s[n] = '\0';

    *str = s;
}

uint32_t indexOf_str(const char *str, const char item)
{
    if(str == NULL)
    {
        return (uint32_t)-1;
    }

    for(size_t i = 0; i < size_str(str); i++)
    {
        if(str[i] == item)
        {
            return i;
        }
    }

    return (uint32_t)-1;
}

char *substr(char *str, size_t start, size_t length)
{
    char *res = (char *) malloc(length + 1);
    if(res == NULL)
    {
        printf("memory allocation failed\n");
        return NULL;
    }

    for(size_t i = 0; i < length; i++)
    {
        res[i] = str[start + i];
    }

    res[length] = '\0';
    return res;
}

void strip_str(char * s)
{
    uint32_t l = 0, r = size_str(s) - 1;
    
    while(s[l] == ' ' && s[l] != '\0')
    {
        l++;
    }

    while(r > l && s[r] == ' ')
    {
        r--;
    }

    uint32_t new_len = r - l + 1;
    for(size_t i = 0; i < new_len; i++)
    {
        s[i] = s[l + i];
    }

    s[new_len] = '\0';   
}

void remove_str(char *s, char item)
{
    if(s == NULL)
    {
        return;
    }

    char *src = s, *dst = s;
    while(*src){
        if(*src != item)
        {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

// CHAR SECTION

char to_upper(const char c)
{
    if(!('a' <= c && c <= 'z'))
    {
        return c;
    }

    return c - 32;
}

bool is_upper(const char c)
{
    if(c >= 'A' && c <= 'Z')
    {
        return true;
    }
    return false;
}

char to_lower(const char c)
{
    if(!('A' <= c && c <= 'Z'))
    {
        return c;
    }

    return c + 32;
}

bool is_lower(const char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return true;
    }
    return false;
}

// ARRAY SECTION

size_t size_arr(const char ** arr)
{
    uint32_t count = 0;
    while(arr[count] != NULL)
    {
        count++;
    }
    return count;
}

uint32_t indexOf_arr(const char ** arr, const char * item)
{
    uint32_t index = 0;
    while(arr[index] != NULL)
    {
        if(comp_str(arr[index], item) == true)
        {
            return index;
        }
        index++;
    }
    return -1;
}

uint32_t rindexOf_arr(const char ** arr, const char * item)
{
    uint32_t index = 0;
    uint32_t res = 0;
    
    while(arr[index] != NULL)
    {
        if(comp_str(arr[index], item) == true)
        {
            res = index;
        }
        index++;
    }
    return res;
}