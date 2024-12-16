#include "menu.h"

#include <stdio.h>
#include <stdlib.h>

void exec()
{
    uint8_t run = 1;
    User *user = NULL;

    while(user == NULL && run)
    {
        run = request_auth(&user);
    }

    while(run)
    {
        display();
        run = input_opt();
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

void input()
{
    char * text = (char *)malloc(sizeof(char) * INPUT_SIZE);
    while(1)
    {
        scanf("%s", text);

        if(size(text) < INPUT_SIZE)
        {
            break;
        }
        printf("\ninput's too long, try again\n");
    }
}

uint8_t input_opt()
{
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
            add_expense();
            break;
        case '2':
            view_expenses();
            break;
        case '3':
            update_expense();
            break;
        case '4':
            delete_expense();
            break;
        case 'q':
            return 0;
        default:
            printf("error processing operation \n");
            return 0;

        return 1;
        
    }
}

void add_expense()
{

}

void view_expenses()
{

}

void update_expense()
{

}

void delete_expense()
{

}