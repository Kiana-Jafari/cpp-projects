#include <iostream>
#include "Structures.h"

void addCourse(University& uni)
{
    // This function creates and adds courses to the uni system.
    std::string units, size;

    if (uni.courseCount == uni.courses.max_size())
    {
        std::cout << "Reached maximum number of courses.\n";
        return ;
    }

    std::cout << "Enter the course name: ";
    std::getline(std::cin, uni.courses.at(uni.courseCount).courseName);

    std::cout << "Enter the course code: ";
    std::getline(std::cin, uni.courses.at(uni.courseCount).courseCode);

    std::cout << "Enter the course capacity: ";
    std::getline(std::cin, size);

    std::cout << "Enter the course credit hours: ";
    std::getline(std::cin, units);

    uni.courses.at(uni.courseCount).capacity = stoi(size);
    uni.courses.at(uni.courseCount).currentCapacity = stoi(size);
    uni.courses.at(uni.courseCount).creditHours = stoi(units);
    
    uni.courses.at(uni.courseCount).enrolledCount = 0; // Set `enrolledCount` equal to 0 for each new-created course

    uni.courseCount ++; // Increment total courses

    std::cout << "Course added successfully!\n";
}

void registerStudents(University& uni)
{
    // This function gets a student's info and stores it in the uni structure.
    std::string day, month, year;

    if (uni.studentCount == uni.students.max_size())
    {
        std::cout << "Reached maximum. Can't register students anymore.\n";
        return ;
    }

    std::cout << "Enter the student's full name: ";
    std::getline(std::cin, uni.students.at(uni.studentCount).fullName);

    std::cout << "Enter their studentID: ";
    std::getline(std::cin, uni.students.at(uni.studentCount).studentID);

    std::cout << "Enter their birth's day: ";
    std::getline(std::cin, day);

    std::cout << "their birth's month: ";
    std::getline(std::cin, month);

    std::cout << "and their birth's year: ";
    std::getline(std::cin, year);

    std::cout << "Enter their major: ";
    std::getline(std::cin, uni.students.at(uni.studentCount).major);

    uni.students.at(uni.studentCount).birthDate.day = stoi(day);
    uni.students.at(uni.studentCount).birthDate.month = stoi(month);
    uni.students.at(uni.studentCount).birthDate.year = stoi(year);

    uni.students.at(uni.studentCount).gpa = 0.0;

    uni.studentCount ++; // Increment total students

    std::cout << "Student registered successfully!\n";
}

void enrollStudent(University& uni)
{
    // This function gets the information of a student and enrolls them in courses.
    std::string stdID, ccode;
    bool isFound{false}, isPresent{false};

    if (uni.enrollmentCount == uni.enrollments.max_size())
    {
        std::cout << "Reached maximum number of enrollments. Can't enroll students anymore.\n";
        return ;
    }

    std::cout << "Enter the studentID: ";
    std::getline(std::cin, stdID);

    std::cout << "Enter the course code: ";
    std::getline(std::cin, ccode);

    for (size_t i{0}; i < uni.studentCount; i++)
    {
        if (uni.students.at(i).studentID == stdID) // Check whether this student exists
        {
            isFound = true;

            for (size_t j{0}; j < uni.courseCount; j++)
            {
                if (uni.courses.at(j).courseCode == ccode) // Check whether the course exists
                {
                    isPresent = true;

                    // Check for duplicates (i.e. if the student already enrolled in this course)
                    for (size_t k{0}; k < uni.enrollmentCount; k++)
                    {
                        if (uni.enrollments.at(k).studentID == stdID && uni.enrollments.at(k).courseCode == ccode)
                        {
                            std::cout << "This course has already been taken by the student.\n";
                            return ;
                        }
                    }

                    if (uni.courses.at(j).enrolledCount > uni.courses.at(j).capacity) // Check whether the course is full
                    {
                        std::cout << "Course is full.\n";
                        return ;
                    }

                    // Enroll the student
                    uni.enrollments.at(uni.enrollmentCount).courseCode = ccode;
                    uni.enrollments.at(uni.enrollmentCount).studentID = stdID;
                    uni.enrollments.at(uni.enrollmentCount).midtermGrade = 0.0;
                    uni.enrollments.at(uni.enrollmentCount).finalGrade = 0.0;
                    uni.enrollments.at(uni.enrollmentCount).totalGrade = 0.0;
                    uni.enrollments.at(uni.enrollmentCount).letterGrade = '-';
                    uni.enrollments.at(uni.enrollmentCount).isCompleted = false;

                    uni.enrollmentCount ++;

                    uni.courses.at(j).enrolledCount ++;

                    uni.courses.at(j).currentCapacity --;

                    std::cout << "Successfully enrolled \"" << stdID << "\" in course \"" << ccode << "\"!\n";

                    break;
                }
            }

            break;
        }
    }

    if (!isFound)
    {
        std::cout << "Student not found.\n";
        return ;
    }

    if (!isPresent)
    {
        std::cout << "Course not found.\n";
        return ;
    }
}