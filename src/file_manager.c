#include "file_manager.h"

#include <stdio.h>

#include "core.h"

// APP RELATED

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

char *read_file(FileHandler * file, const char * mode)
{
    char *res = (char *)malloc(sizeof(char));
    const char * arr = {"r", "rb"};

    if(res == NULL)
    {
        printf("there was an error allocationg memory while reading the file\n");
        return NULL;
    }

    res[0] = '\0';

    if(indexOf_arr(arr, mode) == - 1) 
    {
        return;
    }

    file->fptr = fopen(file->path, mode);

    char buffer[256];
    while(fgets(buffer, 256, file->fptr))
    {
        concat_str(&res, buffer);
    }

    fclose(file->fptr);
    return res;
} 

bool search_file(FileHandler *file, const char *mode, const char * item)
{

}

// USER RELATED

char *search_user_file(FileHandler *file, const char *mode, const char * username)
{
    uint32_t index_underscore = 0;

    char *username_found = NULL;
    char *res = NULL;

    file->fptr = fopen(file->path, "r");

    char buffer[256];
    while(fgets(buffer, 256, file->fptr))
    {
        index_underscore = indexOf_str(buffer, '_');
        if(index_underscore == ((uint32_t) -1))
        {
            printf("error processing your information\n");
            return NULL;
        }
        username_found = substr(buffer, 0, index_underscore);
        if(comp_str(username_found,username))
        {
            res = (char *)malloc(size_str(buffer));
            if(res == NULL)
            {
                printf("error allocating memory for result\n");
                return NULL;
            }
            copy_str(&res, buffer);
            remove_str(res, '\n');
            free(username_found);
            fclose(file->fptr);
            return res;
        }
        free(username_found);
    }

    fclose(file->fptr);
    
    return NULL;
}