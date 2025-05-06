#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "login.h"

// Read logins from login.txt
int loadLogins(Login logins[]) {
    FILE *file = fopen("login.txt", "r");
    if (!file) return 0;

    for (int i = 0; i < MAX_USERS; i++) {
        fscanf(file, "%s %s", logins[i].username, logins[i].password);
    }

    fclose(file);
    return 1;
}

// Check if we have this login
int validateLogin(Login logins[], const char *inputUser, const char *inputPass) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(logins[i].username, inputUser) == 0 && strcmp(logins[i].password, inputPass) == 0)
            return 1;
    }
    return 0;
}

// Hidden pass input
void getPassword(char *password) {
    struct termios oldt, newt;
    int ch, i = 0;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while ((ch = getchar()) != '\n' && i < PASSWORD_LEN - 1) {
        password[i++] = ch;
        printf("*");
    }
    password[i] = '\0';

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\n");
}
