#ifndef EXPENSE_H
#define EXPENSE_H

typedef enum ExpenseType
{
    Transport,
    Food,
    Groceries,
    Rent,
    Utilities,
    Entertainment,
    Healthcare,
    Insurance,
    Education,
    Clothing,
    Savings,
    Subscriptions,
    Travel,
    PersonalCare,
    Gifts,
    Taxes,
    LoanRepayment,
    Miscellaneous,
    Other
} ExpenseType;

typedef struct Expense
{
    int id;
    float value;
    ExpenseType type;
} Expense;

#endif
