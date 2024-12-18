#ifndef MANAGE_FILE_H
#define MANAGE_FILE_H

#include "core.h"
#include "file_handler.h"

// APP RELATED

void init_file(FileHandler *file, const char * path);
void write_file(FileHandler *file, const char * text, const char * mode);
char *read_file(FileHandler * file, const char * mode);
bool search_file(FileHandler *file, const char *mode, const char * item);

// USER RELATED

char * search_user_file(FileHandler *file, const char *mode, const char * username);

#endif