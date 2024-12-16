#ifndef MENU_H
#define MENU_H

#define INPUT_SIZE 100

#include <stdint.h>
#include "user.h"

void exec();
void display();

uint8_t input_opt();
void input();

void add_expense();
void view_expenses();
void update_expense();
void delete_expense();

#endif 