# Parking Garage Management System

## Overview
This project is a **console-based Parking Garage Management System** designed for a **Basic Programming (BP / CS1)** course.
It simulates how a real Iranian-style multi-level parking garage operates.

The program manages:
- Vehicle parking and exit
- Spot availability and assignment
- Parking fee calculation
- Searching and sorting vehicles
- Saving and loading data from a file

This project focuses on **logic, control flow, arrays, file I/O, and modular design** — not UI frameworks.

---

## Learning Objectives
What will be covered in this project:
- Structured programming
- Working with arrays and structs/classes
- File input/output (text files)
- Searching and sorting algorithms
- Menu-driven program design
- Edge case handling
- Writing readable, maintainable code

---

## Program Concept (How It Works)
The parking garage:
- Has **multiple levels**
- Each level contains parking spots
- Each level supports a specific vehicle type (i.e. first level for Motorcycle, second one for the Cars, and the third one for the Truck)
- Vehicles are parked if a compatible spot is available
- When a vehicle exits, a fee is calculated based on time and type

All parked vehicles are stored in memory **and persisted to a text file**.

---

## Data Model

### Vehicle
| Field | Description |
|------|------------|
| License Plate | Unique identifier (string, e.g. `29D728IR63`) |
| Vehicle Type | Car / Motorcycle / Truck |
| Entry Time | Minutes since midnight (integer) |
| Level | Parking level number |
| Spot | Spot number |

### Parking Spot
| Field | Description |
|------|------------|
| Level | Level number |
| Spot Number | Spot index |
| Occupied | Boolean flag |

---

## Program Features (Step by Step)

### 1. Park a Vehicle
**What happens internally:**
1. User enters license plate and vehicle type
2. Program checks for duplicates
3. Program searches for the first compatible free spot
4. Entry time is recorded
5. Vehicle is stored in the array

**Failure cases handled:**
- Garage is full
- No compatible spot exists
- Duplicate license plate

---

### 2. Remove a Vehicle (Exit)
**Steps:**
1. User enters license plate
2. Vehicle is searched
3. Parking duration is calculated
4. Fee is calculated based on vehicle type
5. Spot is freed
6. Vehicle is removed from array

**Fee Rates (Example):**
| Vehicle Type | Rate per Hour |
|-------------|--------------|
| Car | $5 |
| Motorcycle | $3 |
| Truck | $8 |

---

### 3. Display All Parked Vehicles
Displays:
- License plate
- Vehicle type
- Entry time
- Level and spot number

Used for monitoring garage status.

---

### 4. Show Available Spots
Shows:
- Total free spots
- Free spots per level
- Free spots per vehicle type

Helps understand garage capacity in real time.

---

### 5. Search Vehicle
- Searches by license plate
- Displays all stored information if found
- Shows error message if not found

---

### 6. Save Data to File
- Saves all parked vehicles to a text file
- Each vehicle stored on a single line

**File Format:**
```
Plate Type EntryTime Level Spot
11B902|IR33 Car 540 2 15
87A315|IR44 Truck 615 1 4
```

---

### 7. Load Data From File
- Reads file at program startup or by menu option
- Rebuilds vehicle list
- Restores occupied spots correctly
- Ignores corrupted lines

---

### 8. Sort Vehicles
Sort options:
- By entry time (earliest first)
- By license plate (A–Z)
- By parking level

Sorting affects display only.

---

### 9. Exit Program
- Automatically saves all data
- Safely terminates program

---

## Sample Menu
```
=== Parking Garage Management ===
1. Park a vehicle
2. Remove a vehicle
3. Show all parked vehicles
4. Show available spots
5. Search vehicle by plate
6. Save data to file
7. Load data from file
8. Sort vehicles
9. Exit
```

---

## Test Cases

### Test Case 1: Normal Parking
**Input:**
- Plate: 44N637|IR88
- Type: Car
- Time: 540

**Expected Result:**
- Vehicle parked successfully
- Assigned to first free car spot

---

### Test Case 2: Duplicate Vehicle
**Input:**
- Plate: 44N637|IR88

**Expected Result:**
- Error message: Vehicle already exists

---

### Test Case 3: Vehicle Exit
**Input:**
- Plate: 12B365|IR94
- Exit time: 60

**Expected Result:**
- Duration: 60 minutes
- Fee: $5
- Spot freed

---

### Test Case 4: Search Not Found
**Input:**
- Plate: 53T482|IR66

**Expected Result:**
- Vehicle not found message

---

### Test Case 5: Load From File
**Input File:**
```
42D616|IR43 Car 500 1 3
68J321|IR67 Motorcycle 530 2 7
```

**Expected Result:**
- Vehicles loaded correctly
- Spots marked as occupied

---

## Constraints
- Maximum vehicles: 100
- Use arrays only (no STL containers)
- Text file persistence only
- Modular functions required
- Clean, readable code

---

## Bonus Extensions
- Different rates per level
- Edit parked vehicle info
- ASCII visualization of garage
- Input validation for time
