# Hospital Patient Tracking System

## Overview

A complete in‑memory hospital management system where a central `Hospital` class owns and manages all wards, persons (patients, doctors, staff), and admissions. 

The system demonstrates:

- `Encapsulation` – medical records, prescriptions, bed occupancy.

- `Abstraction` – abstract Person base class with pure virtual getRole().

- `Inheritance` – Patient, Doctor, Staff derived from Person.

- `Composition` – Hospital owns Wards; Ward owns Beds; Patient owns Prescriptions.

- `Global search` – Hospital maintains lists of all persons for searching by name/ID.

---

## Class Design

1. `Person` (abstract)

- Private: `id` (string), `name` (string), `age` (int)
- Public: constructor, getters, virtual destructor, pure virtual `

---

2. `Patient` : public `Person`

- Private: `admissionDate` (string), `medicalRecord` (string), `vector<Prescription> prescriptions`
- Public: `addPrescription(const Prescription&)`, `getMedicalSummary()`, `discharge()`, `getPrescriptions() const`

---

3. `Doctor` : public `Person`
- Private: `specialization` (string), `employeeId` (string)
- Public: `writePrescription(Patient& patient, string medicine, string dosage, string date)`

---

4. `Staff` : public `Person`
- Private: `role` (string, e.g., "Nurse"), `shift` (string, e.g., "Day")
- Public: `transferPatient(Patient& patient, Ward& targetWard, int targetBedNumber)` – static method or staff action

---

5. `Prescription` (simple class)
- Private: `medicine`, `dosage`, `datePrescribed`, `doctorName`
- Public: constructor, getters (immutable)

---

6. `Bed`
- Private: `bedNumber` (int), `isOccupied` (bool), `assignedPatientId` (string, or pointer to Patient)
- Public: `assignPatient(const string& patientId)`, `discharge()`, `isFree()`, `getPatientId()`

---

7. Ward
- Private: `wardName` (string), `vector<Bed> beds` (composition)
- Public: `addBed(int bedNumber)`, `int findFreeBed()`, `bool admitPatient(const string& patientId, int bedNumber)`, `dischargePatient(int bedNumber)`, `getOccupancyReport()`

---

## Class Overview

| Class | Key Attributes (private) | Key Methods (public) |
|-------|--------------------------|----------------------|
| `Person` (abstract) | `id`, `name`, `age` | `getId()`, `getName()`, `getAge()`, `virtual getRole()` |
| `Patient` | `admissionDate`, `medicalRecord`, `vector<Prescription>` | `addPrescription()`, `getMedicalSummary()`, `discharge()` |
| `Doctor` | `specialization`, `employeeId` | `writePrescription(Patient&, medicine, dosage)` |
| `Staff` | `role` (e.g., "Nurse"), `shift` | `transferPatient(Patient&, Ward&, Bed&)` |
| `Prescription` | `medicine`, `dosage`, `date`, `doctorName` | Getters only (immutable) |
| `Bed` | `bedNumber`, `isOccupied`, `Patient* assignedPatient` | `assignPatient()`, `dischargePatient()`, `isFree()` |
| `Ward` | `wardName`, `vector<Bed>` (composition) | `getFreeBed()`, `admitToWard()`, `getOccupancyReport()` |

---

### Stage 1: Setup – Create Persons and a Ward

```cpp
// Create a doctor
Doctor drJones("D100", "Dr. Jones", 42, "Cardiology");
// Create a staff member (nurse)
Staff nurseLee("S200", "Nurse Lee", 29, "Nurse", "Morning");
// Create patients
Patient p1("P001", "John Doe", 58);
Patient p2("P002", "Mary Smith", 33);

// Create a ward with 3 beds
Ward cardioWard("Cardiology", 3);   // Constructor creates Bed objects internally
