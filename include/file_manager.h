#ifndef MANAGE_FILE_H
#define MANAGE_FILE_H

#include "core.h"
#include "file_handler.h"

void init_file(FileHandler *file, const char * path);
void write_file(FileHandler *file, const char * text);

#endif