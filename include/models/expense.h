#ifndef EXPENSE_H
#define EXPENSE_H

typedef enum ExpenseType
{
    Transport,
    Food,
    Groceries
} ExpenseType;

typedef struct Expense
{
    int id;
    float value;
    ExpenseType type;
} Expense;

#endif