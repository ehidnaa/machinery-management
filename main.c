#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "login.h"
#include "machine.h"

int main() {
    Login logins[MAX_USERS];    
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];

    // Load login credentials from file
    if (!loadLogins(logins)) {
        printf("Error loading login file\n");
        return 1;
    }

    Machine *head = loadMachinesFromFile("fleet.txt");
    if (!head) {
    printf("No machines loaded from file.\n");
    }

    // Ask for username and password
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    getPassword(password);

    // Validate login
    if (!validateLogin(logins, username, password)) {
        printf("Invalid credentials\n");
        return 1;
    }

    printf("Access granted\n");

    Machine *head = NULL;
    int choice;

    // Main menu loop
    do {
        printf("\n--- MENU ---\n");
        printf("1. Add Machine\n");
        printf("2. Show All Machines\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Read new machine and insert into list
                Machine *m = addMachineFromInput();
                if (m) {
                    head = addMachineSorted(head, m);
                    printf("Machine added.\n");
                } else {
                    printf("Error adding machine.\n");
                }
                break;
            }
            case 2:
                // Print all machines
                printMachines(head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    saveMachinesToFile(head, "fleet.txt");
    return 0;
}