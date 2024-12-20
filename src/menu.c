#include "menu.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <time.h>


#include "user_service.h"

#include "file_manager.h"
#include "expense.h"

void exec()
{
    system("clear");

    bool run = 1;
    User *user = NULL;

    while(user == NULL && run)
    {
        run = request_auth(&user);
    }

    while(run)
    {
        display();
        run = input(2, user);
    }
    return;
}

void display()
{
    printf("1- Add Expense\n");
    printf("2- View Expenses\n");
    printf("3- Update Expense\n");
    printf("4- Delete Expense\n");
    printf("q- Exit program\n");
}

bool input(char mode, User *user)
{
    if(mode == 1)
    {
        char *text = (char *)malloc(sizeof(char) * INPUT_SIZE);
        while(true)
        {
            scanf("%s", text);

            if(str_len(text) < INPUT_SIZE)
            {
                break;
            }
            printf("\ninput's too long, try again\n");
        }

        return 0;

    } else if(mode == 2){
        char op;
        while(1)
        {
            scanf(" %c", &op); // initial space to clear any whitespaces

            if((op <= '4' && op >= '1') || op == 'q')
            {
                break;
            }

            printf("please input one of these operations\n");

            while(getchar() != '\n'); // to clear the buffer (clear outputs like 100 and 1000)
        }

        switch(op)
        {
            case '1':
                add_expense(user);
                break;
            case '2':
                view_expenses(user);
                break;
            case '3':
                update_expense(user);
                break;
            case '4':
                delete_expense(user);
                break;
            case 'q':
                system("clear");
                return 0;
            default:
                printf("error processing operation \n");
                return 0;            
        }
        return 1;
    }
}

void add_expense(User *user)
{
    system("clear");
    if(user == NULL)
    {
        perror("user undefined\n");
        return;
    }

    char expense_type[100];
    unsigned int val;
    Expense *expense;
    srand(time(NULL));

    while(true)
    {
        printf("enter the expense's type: \n");
        scanf("%s", expense_type);

        if(str_len(expense_type) < INPUT_SIZE && str_len(expense_type) != 0)
        {
            printf("enter it's value: \n");
            scanf("%u", &val);
            // formula is: (rand %(max - min + 1)) + min
            expense->id = (rand() % 100) + 1; 
            expense->type = map_type(expense_type);
            printf("Mapped ExpenseType: %d\n", expense->type);
            expense->value = val;
            break;
        }

        printf("please enter max 100 characters");
    }

    return;
    char *path = "/";
    concat_str(&path, user->name);
    concat_str(&path, "/");

    
    create_directory(path);
    expense_to_directory(path, expense);

    free(expense_type);
    free(expense);
}

void view_expenses(User *user)
{
    system("clear");
    if(user == NULL)
    {
        perror("user undefined\n");
        return;
    }
}

void update_expense(User *user)
{
    system("clear");
    if(user == NULL)
    {
        perror("user undefined\n");
        return;
    }
}

void delete_expense(User *user)
{
    system("clear");
    if(user == NULL)
    {
        perror("user undefined\n");
        return;
    }
}


ExpenseType map_type(char *expense_type)
{
    // fix this crap it doesn't work a pointer of this type
    char *val = to_upper_str(expense_type);
    const char *expenseTypes[] = {
    "TRANSPORT",
    "FOOD",
    "GROCERIES",
    "RENT",
    "UTILITIES",
    "ENTERTAINMENT",
    "HEALTHCARE",
    "INSURANCE",
    "EDUCATION",
    "CLOTHING",
    "SAVINGS",
    "SUBSCRIPTIONS",
    "TRAVEL",
    "PERSONALCARE",
    "GIFTS",
    "TAXES",
    "LOANREPAYMENT",
    "MISCELLANEOUS",
    "OTHER"
    };


    size_t len = size_arr(expenseTypes);

    for(size_t i = 0; i < len; i++)
    {
        if(comp_str(val, expenseTypes[i]))
        {
            return (ExpenseType) i;
        }
    }
    return Other;
}