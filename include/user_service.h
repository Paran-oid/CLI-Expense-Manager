#ifndef USER_SERVICE_H
#define USER_SERVICE_H

#include "core.h"
#include "user.h"
#include "user_service.h"

#define USERNAME_LIMIT 30
#define PASSWORD_LIMIT 20

bool request_auth(User ** user);

bool auth_login(User ** user);
void auth_register(User ** user);

void encrypt(char *pass);
void decrypt(char *pass);

#endif