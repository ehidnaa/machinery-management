#ifndef MACHINE_H
#define MACHINE_H

#define MAX_STR 100

// Enum for machine types
typedef enum {
    TRACTOR, EXCAVATOR, ROLLER, CRANE, MIXER
} MachineType;

// Enum for number of breakdowns
typedef enum {
    NEVER, LESS_THAN_THREE, LESS_THAN_FIVE, MORE_THAN_FIVE
} BreakdownCount;

// Structure representing a machine
typedef struct Machine {
    char chassisNumber[MAX_STR];
    char make[MAX_STR];
    char model[MAX_STR];
    int year;
    float cost;
    float valuation;
    int mileage;
    int nextService;
    char ownerName[MAX_STR];
    char ownerEmail[MAX_STR];
    char ownerPhone[MAX_STR];
    MachineType type;
    BreakdownCount breakdowns;
    struct Machine *next;
} Machine;

// Insert machine in sorted order by chassis number
Machine* addMachineSorted(Machine *head, Machine *newMachine);

// Input machine details from user
Machine* addMachineFromInput();

// Display all machines
void printMachines(Machine *head);

#endif