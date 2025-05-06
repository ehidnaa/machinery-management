#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "machine.h"

// Insert machine in linked list sorted by chassis number
Machine* addMachineSorted(Machine *head, Machine *newMachine) {
    if (!head || strcmp(newMachine->chassisNumber, head->chassisNumber) < 0) {
        newMachine->next = head;
        return newMachine;
    }

    Machine *current = head;
    while (current->next && strcmp(current->next->chassisNumber, newMachine->chassisNumber) < 0) {
        current = current->next;
    }

    newMachine->next = current->next;
    current->next = newMachine;
    return head;
}

// Display all machines in the list
void printMachines(Machine *head) {
    if (!head) {
        printf("No machines in the system.\n");
        return;
    }

    Machine *current = head;
    while (current) {
        printf("\n--- Machine ---\n");
        printf("Chassis: %s\n", current->chassisNumber);
        printf("Make: %s\n", current->make);
        printf("Model: %s\n", current->model);
        printf("Year: %d\n", current->year);
        printf("Cost: %.2f\n", current->cost);
        printf("Valuation: %.2f\n", current->valuation);
        printf("Mileage: %d\n", current->mileage);
        printf("Next Service: %d\n", current->nextService);
        printf("Owner: %s\n", current->ownerName);
        printf("Email: %s\n", current->ownerEmail);
        printf("Phone: %s\n", current->ownerPhone);
        printf("Type: %d\n", current->type);
        printf("Breakdowns: %d\n", current->breakdowns);
        current = current->next;
    }
}

// Read machine details from user input
Machine* addMachineFromInput() {
    Machine *m = malloc(sizeof(Machine));
    if (!m) return NULL;

    printf("Enter Chassis Number: ");
    scanf("%s", m->chassisNumber);
    printf("Enter Make: ");
    scanf("%s", m->make);
    printf("Enter Model: ");
    scanf("%s", m->model);
    printf("Enter Year: ");
    scanf("%d", &m->year);
    printf("Enter Cost: ");
    scanf("%f", &m->cost);
    printf("Enter Current Valuation: ");
    scanf("%f", &m->valuation);
    printf("Enter Mileage: ");
    scanf("%d", &m->mileage);
    printf("Enter Next Service Mileage: ");
    scanf("%d", &m->nextService);
    printf("Enter Owner Name: ");
    scanf(" %[^\n]", m->ownerName);
    printf("Enter Owner Email: ");
    scanf("%s", m->ownerEmail);
    printf("Enter Owner Phone: ");
    scanf("%s", m->ownerPhone);

    int typeChoice;
    printf("Enter Machine Type (0-Tractor,1-Excavator,2-Roller,3-Crane,4-Mixer): ");
    scanf("%d", &typeChoice);
    m->type = typeChoice;

    int breakdowns;
    printf("Breakdowns this year (0-Never, 1-<3, 2-<5, 3->5): ");
    scanf("%d", &breakdowns);
    m->breakdowns = breakdowns;

    m->next = NULL;
    return m;
}

// Save all machines to file
void saveMachinesToFile(Machine *head, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Could not open file for saving.\n");
        return;
    }

    Machine *current = head;
    while (current) {
        fprintf(file, "%s|%s|%s|%d|%.2f|%.2f|%d|%d|%s|%s|%s|%d|%d\n",
            current->chassisNumber,
            current->make,
            current->model,
            current->year,
            current->cost,
            current->valuation,
            current->mileage,
            current->nextService,
            current->ownerName,
            current->ownerEmail,
            current->ownerPhone,
            current->type,
            current->breakdowns
        );
        current = current->next;
    }

    fclose(file);
}

// Load machines from file into linked list
Machine* loadMachinesFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    Machine *head = NULL;
    char line[512];

    while (fgets(line, sizeof(line), file)) {
        Machine *m = malloc(sizeof(Machine));
        if (!m) continue;

        sscanf(line, "%[^|]|%[^|]|%[^|]|%d|%f|%f|%d|%d|%[^|]|%[^|]|%[^|]|%d|%d",
            m->chassisNumber,
            m->make,
            m->model,
            &m->year,
            &m->cost,
            &m->valuation,
            &m->mileage,
            &m->nextService,
            m->ownerName,
            m->ownerEmail,
            m->ownerPhone,
            (int*)&m->type,
            (int*)&m->breakdowns
        );

        m->next = NULL;
        head = addMachineSorted(head, m);
    }

    fclose(file);
    return head;
}

// Display a machine with the given chassis number
void displayMachineByChassis(Machine *head, const char *chassis) {
    Machine *current = head;
    while (current) {
        if (strcmp(current->chassisNumber, chassis) == 0) {
            printf("\n--- Machine Found ---\n");
            printf("Chassis: %s\n", current->chassisNumber);
            printf("Make: %s\n", current->make);
            printf("Model: %s\n", current->model);
            printf("Year: %d\n", current->year);
            printf("Cost: %.2f\n", current->cost);
            printf("Valuation: %.2f\n", current->valuation);
            printf("Mileage: %d\n", current->mileage);
            printf("Next Service: %d\n", current->nextService);
            printf("Owner: %s\n", current->ownerName);
            printf("Email: %s\n", current->ownerEmail);
            printf("Phone: %s\n", current->ownerPhone);
            printf("Type: %d\n", current->type);
            printf("Breakdowns: %d\n", current->breakdowns);
            return;
        }
        current = current->next;
    }
    printf("Machine not found.\n");
}

// Update a machine's details by chassis number
void updateMachineByChassis(Machine *head, const char *chassis) {
    Machine *current = head;
    while (current) {
        if (strcmp(current->chassisNumber, chassis) == 0) {
            printf("Machine found. Updating...\n");

            printf("Enter new valuation: ");
            scanf("%f", &current->valuation);
            printf("Enter new mileage: ");
            scanf("%d", &current->mileage);
            printf("Enter new next service mileage: ");
            scanf("%d", &current->nextService);
            printf("Enter new owner email: ");
            scanf("%s", current->ownerEmail);

            printf("Machine updated.\n");
            return;
        }
        current = current->next;
    }
    printf("Machine not found.\n");
}