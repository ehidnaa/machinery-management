#ifndef LOGIN_H
#define LOGIN_H

#define MAX_USERS 3
#define USERNAME_LEN 20
#define PASSWORD_LEN 20

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
} Login;

int loadLogins(Login logins[]);
int validateLogin(Login logins[], const char *inputUser, const char *inputPass);
void getPassword(char *password);

#endif