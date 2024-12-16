#include "user_service.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

uint8_t request_auth(User ** user)
{
    char op;
    while(1)
    {
        printf("you have to login/register\n");
        printf("1- login\n");
        printf("2- register\n");
        printf("q- quit\n");

        scanf(" %c", &op);

        if(op == '1' || op == '2' || op == 'q')
        {
            break;
        }

        printf("\nplease enter a valid input\n");

        while(getchar() != '\n');
    }

    switch(op)
    {
        case '1':
            auth_login(user);
            break;
        case '2':
            auth_register(user);
            break;
        case 'q':
            return 0;
    }

    return 1;
}

void auth_login(User ** user)
{

}

void auth_register(User ** user)
{
    *user = (User *) malloc(sizeof(User));
    if(*user == NULL)
    {
        printf("error allocationg memory to user\n");
        return;
    }


    (*user)->name = (char *) malloc(sizeof(char) * USERNAME_LIMIT);
    (*user)->password = (char *) malloc(sizeof(char) * PASSWORD_LIMIT);

    if((*user)->name == NULL || (*user)->password == NULL)
    {
        free(*user);
        printf("there was an error allocating memory\n");
        return;
    }

    while(1)
    {
        printf("enter your username: \n");
        if(scanf("%49s",(*user)->name) == 1)
        {
            printf("enter your password: \n");
            if(scanf("%s", (*user)->password) == 1)
            {
                if(size((*user)->name) <= USERNAME_LIMIT && size((*user)->password) <= PASSWORD_LIMIT)
                {
                    break;
                }
            }

        }

        printf("invalid input(s)\n");
    }

    system("clear");
    printf("welcome %s\n", (*user)->name);
    sleep(1);
    system("clear");
}