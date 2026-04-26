# 🩺 Hospital Patient Tracking System

## Overview

A hospital needs a software module to manage patient admissions, bed allocation, and basic medical records. The system tracks patients, doctors, and staff, assigns patients to beds within wards, and stores prescriptions for each patient. Doctors can issue prescriptions, staff can view ward occupancy, and patients can be discharged.

---

## OOP Concepts Covered

| Concept | How it appears |
|---------|----------------|
| **Class basics** | All entities are defined as classes with constructors, destructors, and member functions. |
| **Access members** | `private`, `protected`, `public` used appropriately. |
| **Encapsulation** | Data is hidden; public interfaces control access. Example: `Patient`'s medical history is private, modified only via `addPrescription()`. |
| **Composition** | `Ward` **owns** its `Bed` objects (if ward destroyed, beds destroyed). `Patient` **owns** its `Prescription` objects. |
| **Inheritance** | `Patient`, `Doctor`, `Staff` inherit from `Person` |

---

## Class Design

### Person (concrete base class)
- `protected:` `id` (string), `name` (string), `age` (int)
- `public:` Constructor with parameters, getters (`getId()`, `getName()`, `getAge()`), setter for `name` (if needed).

---

### Patient : public Person
- `private:` `admissionDate` (string), `medicalRecord` (string), `vector<Prescription>` prescriptions
- `public:` Constructor, `addPrescription()`, `getMedicalSummary()`, `discharge()` (clears medical record? or just flags). Accessor for prescriptions.

---

### Doctor : public Person
- `private:` `specialization` (string), `employeeId` (string)
- `public:` Constructor, getters/setters, `writePrescription(Patient&, medicine, dosage)` – creates Prescription and adds to patient.

---

### Staff : public Person
- `private:` `role` (string, e.g., "Nurse"), `shift` (string)
- `public:` Constructor, `transferPatient(Patient&, Ward&, Bed&)` – reassigns bed (needs access to Ward/Bed methods).

---

### Prescription
- `private:` `medicine`, `dosage`, `date`, `doctorName` (all const – set once)
- `public:` Constructor taking all fields, constant getters only (immutable).

---

### Bed
- `private:` `bedNumber` (int), `isOccupied` (bool), `assignedPatient` (Patient*)
- `public:` Constructor, `assignPatient(Patient&)`, `dischargePatient()`, `isFree()`, `getPatient()`.

---

### Ward
- `private:` `wardName` (string), `vector<Bed>` beds (composition – vector of objects, not pointers)
- `public:` Constructor (creates N beds), `getFreeBed()` returns index or pointer, `admitToWard(Patient&)`, `dischargePatient(Patient&)`, `getOccupancyReport()`.

---

## Example

### 1. Create Persons and Ward

```cpp
Doctor drJones("D100", "Dr. Jones", 42, "Cardiology");
Staff nurseLee("S200", "Nurse Lee", 29, "Nurse", "Morning");
Patient p1("P001", "John Doe", 58);
Patient p2("P002", "Mary Smith", 33);

Ward cardioWard("Cardiology", 3);   // creates 3 Bed objects inside
```

### 2. Admit Patients

```cpp
cardioWard.admitToWard(p1);   // success, first free bed
cardioWard.admitToWard(p2);   // success, second free bed
```

### 3. Doctor Writes Prescription

```cpp
drJones.writePrescription(p1, "Aspirin", "100mg once daily", "2025-04-01");
// Internally creates Prescription and calls p1.addPrescription()
```

### 4. Ward Occupancy Report

```cpp
cardioWard.getOccupancyReport();
```

### Output

```
Ward: Cardiology
Bed 1: Occupied by John Doe (admitted: 2025-04-01)
  Prescriptions: Aspirin 100mg once daily
Bed 2: Occupied by Mary Smith (admitted: 2025-04-01)
  No prescriptions
Bed 3: Free
```

### 5. Discharge Patient

```cpp
cardioWard.dischargePatient(p1);   // bed becomes free, patient record kept
```

---

## UML Class Diagram

```
┌─────────────┐
│   Person    │
│─────────────│
│ # id        │
│ # name      │
│ # age       │
│─────────────│
│ + getters   │
└─────────────┘
       ▲
       │ (inheritance)
   ┌───┴───┬─────────┐
   │       │         │
┌──┴──┐ ┌──┴──┐   ┌──┴──┐
│Patient│Doctor│   │Staff│
│──────││──────│   │─────│
│-admit││-spec │   │-role│
│-medRec││-empId │   │-shift│
│-presc ││      │   │     │
│[comp] ││      │   │     │
└──────┘└──────┘   └──────┘
   │
   │ composes (1..*)
   ▼
┌─────────────┐
│Prescription │
│─────────────│
│-medicine    │
│-dosage      │
└─────────────┘

┌──────┐     composes (1..*)     ┌─────┐
│ Ward │─────────────────────────│ Bed │
│──────│                         │─────│
│-name │                         │-num │
│-beds │                         │-occ │
└──────┘                         │-pat*│
                                 └─────┘
                                    │ associates (0..1)
                                    ▼
                                 Patient
```
