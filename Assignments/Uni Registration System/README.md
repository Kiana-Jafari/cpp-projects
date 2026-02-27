# 🎓 Mini Project: University Course Registration System

In this project, we're going to builf a console-based system that manages:

- Students
- Courses
- Enrollments
- Grade Calculation

---

### Core Structures

1. **Date**: A data type that stores the birth information of the studetns, namely: 
    - `day` | integer
    - `month` | integer
    - `year` | integer

2. **Course**: Data type with the following features: 
    - `courseCode` | string 
    - `courseName` | string 
    - `creditHours (units)` | integer 
    - `capacity` | integer 
    - `enrolledCount` | integer

*Note:* `enrolledCount` says "How many students are currently enrolled in that specific course."

3. **Student**: A structure that has:
    - `studentID` | string
    - `fullName` | string
    - `birthDate` | *Date*
    - `major` | string
    - `gpa` | double

4. **Enrollment**: A container that stores
    - `studentID` | string
    - `courseCode` | string
    - `midtermGrade` | double
    - `finalGrade` | double
    - `totalGrade` | double
    - `letterGrade` | char
    - `isCompleted` | bool

5. **University**: A structure that stores an array of 200 students, 100 courses, and 500 enrollments, with additional features:

    - `studentCount` | integer
    - `courseCount` | integer
    - `enrollmentCount` | integer

*Note:* `enrollmentCount` is "The total number of enrollment records in the entire university."

---

## 🧩 What This Program Should Be Able To Do

1. Register Students
    - Add new students
    - Validate unique studentID
    - Store their academic data

2. Create Courses
    - Add course with capacity
    - Prevent over-enrollment
    - Track current enrolled count

3. Enroll Student in Course </br>
    When enrolling:
    - Check student exists
    - Check course exists
    - Check capacity not full
    - Prevent duplicate enrollment
    - Increase enrolledCount

4. Record Grades
    - Input midterm + final
    - Compute totalGrade
    - Convert to letterGrade
    - Mark enrollment as completed

5. Compute GPA </br>
    For each student:
    - Look through all enrollments
    - Only count completed courses
    - Multiply totalGrade by creditHours
    - Divide by total credit hours

6. Drop Course
    - Remove enrollment
    - Decrease enrolledCount
    - Prevent dropping completed courses

7. Display Transcript </br>
    For a student:
    - List all completed courses
    - Show grades
    - Show GPA

---

## 🎬 Full Simulation Example (From Start to Finish)

**Step 1 — Add Courses** </br>
Add two courses:

**Course 1**
|courseCode|courseName|creditHours|capacity|enrolledCount|
|----------|----------|-----------|--------|-------------|
|CS101|Programming Fundamentals|3|2|0|

---

**Course 2**
|courseCode|courseName|creditHours|capacity|enrolledCount|
|----------|----------|-----------|--------|-------------|
|CS201|Data Structures|4|1|0|

Note that now, **courseCount = 2**

---

**Step 2 — Add Students**

**Student 1**
|studentID|fullName|major|gpa|
|---------|--------|-----|---|
|240465135|Edward Richardson|Computer Engineering|0.0|

**Student 2**
|studentID|fullName|major|gpa|
|---------|--------|-----|---|
|239615704|Sara Ferguson|Computer Science|0.0|

Now, studentCount = 2

---

**Step 3 — Enroll Students**

Enroll 240465135 in CS101

System checks if: </br>

    - Student exists
    - Course exists
    - enrolledCount < capacity

Create enrollment:

|studentID|courseCode|midtermGrade|finalGrade|isCompleted|
|---------|----------|------------|----------|-----------|
|240465135|CS101|0|0|false|

Update:

- CS101.enrolledCount = 1
- enrollmentCount = 1

---

Enroll 239615704 in CS101

- Check the above conditions

update:

- CS101.enrolledCount = 2
- enrollmentCount = 2

Now CS101 is **FULL**.

---

Try enrolling 239615704 in CS101 again:

System checks: </br>
Duplicate enrollment → reject

---

Enroll 239615704 in CS201

- Check the capacity

update:

- CS201.enrolledCount = 1
- enrollmentCount = 3

Now CS201 is FULL.

```
studentCount = 2
courseCount = 2
enrollmentCount = 3
```

---

**Step 4 — Record Grades**

Now semester ends.

Record grades for 240465135 in CS101 & CS201:

|studentID|courseCode|midtermGrade|finalGrade|totalGrade|letterGrade|isCompleted|
|---------|----------|------------|----------|----------|-----------|-----------|
|240465135|CS101|80|90|86|A|true|
|240465135|CS201|70|80|76|B|true|

*NOTE:* 0.4 of the total grade is given to the midterm, and the remaining ratio, 0.6, is given to the final grade.

---

**Step 5 — Calculate GPA for 240465135**

Now the system:

1. Loops through all enrollments
2. Finds enrollments where:

```
enrollment.studentID == "240465135"
AND isCompleted == true
```

Found:
- CS101 → 3 credits → grade 86
- CS201 → 4 credits → grade 76

If using 4.0 scale example:

```
A = 4.0
B = 3.0
```

GPA calculation:

```
(4.0 × 3 credits) + (3.0 × 4 credits)
= 12 + 12
= 24

Total credits = 7

GPA = 24 / 7 = 3.43
```

update:

student.gpa = 3.43
