#ifndef MENU_H
#define MENU_H

#define INPUT_SIZE 100

#include "user.h"
#include "expense.h"

void exec();
void display();
bool input(char mode, User* user);

void add_expense(User *user);
void view_expenses(User *user);
void update_expense(User *user);
void delete_expense(User *user);

ExpenseType map_type(char *expense_type);

#endif 