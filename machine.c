#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "machine.h"

// Вставка по порядку (по chassis number)
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

// Печать всех машин
void printMachines(Machine *head) {
    Machine *current = head;
    while (current) {
        printf("Chassis: %s | Make: %s | Model: %s\n", current->chassisNumber, current->make, current->model);
        current = current->next;
    }
}