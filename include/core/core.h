
#ifndef CORE_H
#define CORE_H

#include <stdbool.h>
#include <stdint.h>

    // string operations

    uint32_t size_str(const char * s);
    void copy_str(char **desStr, const char *toCopyFromStr);
    bool comp_str(const char *str1,const char *str2);   
    void concat_str(char **str, const char *addedStr);

    uint32_t size_arr(const char ** arr);
    uint32_t indexOf_arr(const char ** arr, const char * item);

#endif