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

    // Load machines from file
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

    int choice;

    // Main menu loop
    do {
        printf("\n--- MENU ---\n");
        printf("1. Add Machine\n");
        printf("2. Show All Machines\n");
        printf("3. Display One Machine by Chassis Number\n");
        printf("4. Update Machine by Chassis Number\n");
        printf("5. Delete Machine by Chassis Number\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
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
                printMachines(head);
                break;

            case 3: {
                char chassis[MAX_STR];
                printf("Enter chassis number to search: ");
                scanf("%s", chassis);
                displayMachineByChassis(head, chassis);
                break;
            }

            case 4: {
                char chassis[MAX_STR];
                printf("Enter chassis number to update: ");
                scanf("%s", chassis);
                updateMachineByChassis(head, chassis);
                break;
            }

            case 5: {
                char chassis[MAX_STR];
                printf("Enter chassis number to delete: ");
                scanf("%s", chassis);
                head = deleteMachineByChassis(head, chassis);
                break;
            }

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);

    // Save machines to file before exiting
    saveMachinesToFile(head, "fleet.txt");

    return 0;
}