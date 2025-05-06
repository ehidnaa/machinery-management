// main.c
#include <stdio.h>
#include <string.h>
#include "login.h"

int main() {
    Login logins[MAX_USERS];
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];

    if (!loadLogins(logins)) {
        printf("Error loading login file\n");
        return 1;
    }

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    getPassword(password);

    if (validateLogin(logins, username, password)) {
        printf("Access granted\n");
        // Здесь позже будет меню
    } else {
        printf("Invalid credentials\n");
    }

    return 0;
}