
#ifndef CORE_H
#define CORE_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

    // STRING SECTION

    size_t size_str(const char * s);
    void copy_str(char **desStr, const char *toCopyFromStr);
    bool comp_str(const char *str1,const char *str2);   
    void concat_str(char **str, const char *addedStr);
    uint32_t indexOf_str(const char *str, const char item);
    char *substr(char *str, size_t start, size_t length);
    void strip_str(char * s);
    void remove_str(char *s, char item);

    // CHAR SECTION

    char to_upper(const char c);
    bool is_upper(const char c);
    char to_lower(const char c);
    bool is_lower(const char c);

    // ARRAY SECTION

    size_t size_arr(const char ** arr);
    uint32_t indexOf_arr(const char ** arr, const char * item);

#endif