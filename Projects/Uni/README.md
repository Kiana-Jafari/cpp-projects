# 🎓 Mini Project: University Course Registration System

In this project, we're going to build a console-based system that manages:

- Students
- Courses
- Enrollments
- Grade Calculation

This project heavily relies on using `<array>` library, an STL container, `structs`, and modularization.

---

### Core Structures

1. **Date**: A data type that stores the birth information of the students, namely: 
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

## What This Program Is Able To Do

---

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

## Run The Program

Compile the program on terminal using command line `g++ *.cpp -o program`
and run it using `./program.exe` to see how it works.

---

This project is especially interesting to me, since it deals with data and is the fundamental of creating Databases that store data. It also shows working with tabular data using primary and foreign keys.