#ifndef MACHINE_H
#define MACHINE_H

#define MAX_STR 100

typedef enum {
    TRACTOR, EXCAVATOR, ROLLER, CRANE, MIXER
} MachineType;

typedef enum {
    NEVER, LESS_THAN_THREE, LESS_THAN_FIVE, MORE_THAN_FIVE
} BreakdownCount;

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

Machine* addMachineSorted(Machine *head, Machine *newMachine);
void printMachines(Machine *head);

#endif