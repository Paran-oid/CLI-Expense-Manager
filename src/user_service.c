#include "user_service.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "file_manager.h"
#include "core.h"

bool request_auth(User ** user)
{
    char op;
    bool res;
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
            res = auth_login(user);
            break;
        case '2':
            auth_register(user);
            res = true;
            break;
        case 'q':
            res = false;
            break;
    }

    return res;
}

bool auth_login(User ** user)
{
    bool loggedIn = false;

    char *found_entity = NULL;
    char *username = NULL;
    char *password = NULL;

    char choice = 'N';

    *user =(User *) malloc(sizeof(User));
    if(*user == NULL)
    {
        printf("there was an error allocationg memory\n");
        return;
    }

    (*user)->name = (char *) malloc(USERNAME_LIMIT);
    (*user)->password = (char *) malloc(PASSWORD_LIMIT);

    if((*user)->name == NULL || (*user)->password == NULL)
    {
        printf("there was an error allocationg memory for using properties\n");
        return;
    }


    FileHandler *f = (FileHandler*) malloc(sizeof(FileHandler));
    init_file(f, "../data/users.txt");
    while(1)
    {
        printf("enter your username\n");
        if(scanf("%49s", (*user)->name) == 1)
        {
            found_entity = search_user_file(f, "r", (*user)->name);
            if(found_entity != NULL)
            {
                username = substr(found_entity, 0, indexOf_str(found_entity, '_'));
                if(comp_str(username,(*user)->name))
                {
                printf("enter your password\n");
                if(scanf("%49s", (*user)->password) == 1)
                {
                    // fix size issue here
                    password = substr(found_entity, indexOf_str(found_entity, '_') + 1, size_str(found_entity) - 1);
                    printf("user entered password %s | with size %d \n", (*user)->password, size_str((*user)->password));
                    printf("user's pass %s | with size %d\n", password, size_str(password));
                    printf("are the same?\n%d", comp_str((*user)->password, password));
                    if(comp_str((*user)->password,password))
                    {
                        loggedIn = true;
                        break;
                    }
                    printf("uncorrect password\n");
                    free(password);
                }
                free(username);
                free(found_entity);
                }

            } else {
                printf("couldn't find your username\n");
            }
             
            if(!loggedIn)
            {
                printf("do you want to retry?(y/n)(\n");
                if(scanf(" %c", &choice) == 1)
                {
                    if(to_upper(choice) != 'Y')
                    {
                        free((*user)->name);
                        (*user)->name = NULL;
                        (*user)->password = NULL;
                        break;
                    }
                }
            }
        }
    }

    system("clear");
    if((*user)->name == NULL)
    {
        printf("please authenticate in order to continue\n");
        sleep(2);
        return 0;
    } else {
        printf("welcome %s\n", (*user)->name);
        sleep(2);
        return 1;
    }
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
                if(size_str((*user)->name) <= USERNAME_LIMIT && size_str((*user)->password) <= PASSWORD_LIMIT)
                {
                    break;
                }
            }

        }

        printf("invalid input(s)\n");
    }

    system("clear");
    printf("welcome %s\n", (*user)->name);

    FileHandler *f = (FileHandler *) malloc(sizeof(FileHandler));
    init_file(f, "../data/users.txt");
    
    char * full_data = (char *) malloc(1);
    full_data[0] = '\0';

    concat_str(&full_data, (*user)->name);
    concat_str(&full_data,  "_");
    concat_str(&full_data, (*user)->password);

    write_file(f, full_data, "w");    
    sleep(1);
    system("clear");

    free(full_data);
    free(f->fptr);
    free(f);
}