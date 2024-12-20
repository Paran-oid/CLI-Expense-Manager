#include "core.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

// STRING SECTION

size_t str_len(const char * s)
{
    size_t res = 0;
    while(s[res] != '\0')
    {
        res++;
    }
    return res;
}

void copy_str(char **desStr, const char *toCopyFromStr)
{
    size_t len = str_len(toCopyFromStr);

    if(*desStr == NULL || len > str_len(*desStr))
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
    if(str_len(str1) != str_len(str2)){return false;}

    size_t i = 0;
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

    int n = str_len(*str) +  str_len(addedStr);
    char *s = realloc(*str ,n + 1);


    if(s == NULL)
    {
        printf("memory allocation failed \n");
        return;
    }

    for(size_t i = 0; i < str_len(*str); i++)
    {
        s[i] = (*str)[i];
    }

    size_t k = 0;

    for(size_t i = str_len(*str); i < n; i++)
    {
        s[i] = addedStr[k++];
    }

    s[n] = '\0';

    *str = s;
}

size_t indexOf_str(const char *str, const char item)
{
    if(str == NULL)
    {
        return SIZE_MAX;
    }

    for(size_t i = 0; i < str_len(str); i++)
    {
        if(str[i] == item)
        {
            return i;
        }
    }

    return SIZE_MAX;
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
    if(s == NULL)
    {
        return;
    }
    
    size_t l = 0, r = str_len(s) - 1;
    
    while(s[l] == ' ')
    {
        l++;
    }

    while(r > l && s[r] == ' ')
    {
        r--;
    }

    size_t new_len = r - l + 1;
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

char *to_upper_str(char *s)
{
    size_t n = str_len(s);
    char *res = (char *)malloc(sizeof(char) * (n + 1));


    if(res == NULL)
    {
        perror("there was an error allocating memory \n");
        return;
    }

    size_t i = 0;
    char *ptr = s;
    while(*ptr != '\0')
    {
        res[i] = to_upper(ptr[i]);
        i++;
        ptr++;
    }

    res[i] = '\0';  
    printf("res is %s \n", res);
    return res;
}

char *to_lower_str(char *s)
{
    size_t n = str_len(s);
    char *res = malloc(sizeof(char) * (n + 1));

    if(res == NULL)
    {
        perror("there was an error allocating memory \n");
        return;
    }

    size_t i = 0;
    char *ptr = s;
    while(*ptr != '\0')
    {
        res[i] = to_lower(ptr[i]);
        i++;
        ptr++;
    }

    res[i] = '\0';
    return res; 
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
    size_t res = 0;
    while(arr[res] != NULL)
    {
        res++;
    }
    return res;
}

size_t indexOf_arr(const char ** arr, const char * item)
{
    size_t index = 0;
    while(arr[index] != NULL)
    {
        if(comp_str(arr[index], item) == true)
        {
            return index;
        }
        index++;
    }
    return SIZE_MAX;
}

size_t rindexOf_arr(const char ** arr, const char * item)
{
    size_t index = 0;
    size_t res = 0;
    
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

void *mem_set(void *ptr, int value, size_t len)
{
    unsigned char * p = (unsigned char *)ptr;
    unsigned char val = (unsigned char) value;

    while(len)
    {
        *p = val;
        p++;
        len--;
    }

    return p;
}