# Machinery Fleet Management System

This is a C language project developed for the *Advanced Procedural Programming* module at ATU Galway.  
The application helps manage a fleet of machinery using a password-protected interface and a linked list database.

## Features

- **Login system** with hidden password input (reads from `login.txt`)
- **Linked list** used to store machinery data
- **Load and save** machine data from/to `fleet.txt`
- **Menu options** include:
  1. Add a new machine
  2. Display all machines
  3. Display a specific machine (by chassis number)
  4. Update a machine’s details
  5. Delete a machine
  6. Generate a report (`report.txt`) with all machines
- All data is **saved automatically** on exit
- Code is modular and commented in English

## File Overview

| File         | Purpose                                   |
|--------------|-------------------------------------------|
| `main.c`     | Main program with menu and logic flow     |
| `machine.c`  | Functions for managing machine data       |
| `machine.h`  | Header file for machine structure         |
| `login.c`    | Login system (reads from file)            |
| `login.h`    | Header for login system                   |
| `fleet.txt`  | Stores all machinery                      |
| `login.txt`  | Stores login credentials                  |
| `report.txt` | Output report of all machines             |

## Example Logins

```
admin1 pass01  
admin2 pass02  
admin3 pass03
```

## Compilation

To compile the project:

```bash
gcc main.c machine.c login.c -o fleetApp
```

## Running the Program

```bash
./fleetApp
```

## Student Information

- **Name:** Mariia Chalyk  
- **Student ID:** G00437444  
- **Course:** Software Development  
- **Module:** Advanced Procedural Programming  
- **Lecturer:** Martin Hynes
