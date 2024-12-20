#ifndef MANAGE_FILE_H
#define MANAGE_FILE_H

#include "core.h"
#include "file_handler.h"
#include "expense.h"

// APP RELATED
void init_file(FileHandler *file, const char * path);
void write_file(FileHandler *file, const char * text, const char * mode);
char *read_file(FileHandler * file, const char * mode);
bool search_file(FileHandler *file, const char *mode, const char * item);

bool create_directory(const char *path);
bool check_directory(const char *path);

// USER RELATED
char * search_user_file(FileHandler *file, const char *mode, const char * username);
bool expense_to_directory(const char* path, Expense *expense);

#endif