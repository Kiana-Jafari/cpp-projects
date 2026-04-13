#include <iostream>
#include "Structures.h"

void displayCourses(const University& uni)
{
    // This function displays all existed courses.
    if (uni.courseCount == 0)
    {
        std::cout << "No courses have been added yet.\n";
        return ;
    }

    std::cout 
        << "| Course Name" 
        << " | Credit Hours" 
        << " | Course Code" 
        << " | Number of enrollments" 
        << " | Capacity" 
        << " | Current Capacity\n";

    for (size_t i{0}; i < uni.courseCount; ++i)
    
    std::cout 
        << "| " << uni.courses.at(i).courseName << "  " 
        << " | " << uni.courses.at(i).courseCode << "  "
        << " | " << uni.courses.at(i).creditHours << "  "
        << " | " << uni.courses.at(i).capacity << "  "
        << " | " << uni.courses.at(i).enrolledCount << "  "
        << " | " << uni.courses.at(i).currentCapacity << "\n";
}

void displayStudents(const University& uni)
{
    // This function displays the registered students info.
    if (uni.studentCount == 0)
    {
        std::cout << "No students registered yet.\n";
        return ;
    }

    std::cout 
        << "| Full Name"
        << " | StudentID"
        << " | Major"
        << " | GPA\n";

    for (size_t i{0}; i < uni.studentCount; ++i)
    
    std::cout 
        << "| " << uni.students.at(i).fullName << "  "
        << " | " << uni.students.at(i).studentID << "  "
        << " | " << uni.students.at(i).major << "  "
        << " | " << uni.students.at(i).gpa << "\n";
}

void displayEnrolledCourses(const University& uni)
{
    // This function gets the studentID and displays all enrolled courses of that student.
    std::string stdID;

    if (uni.enrollmentCount == 0)
    {
        std::cout << "No courses have been taken yet.\n";
        return ;
    }

    std::cout << "Enter the StudentID: ";
    std::getline(std::cin, stdID);

    std::cout 
        << "| StudentID"
        << " | Course Code"
        << " | Final Grade"
        << " | Midterm Grade"
        << " | Total Grade"
        << " | Letter Grade"
        << " | Has Completed the Course\n";

    for (size_t i{0}; i < uni.enrollmentCount; ++i)
    {
        if (uni.enrollments.at(i).studentID == stdID)
        
        std::cout
            << "| " << uni.enrollments.at(i).studentID << "   "
            << " | " << uni.enrollments.at(i).courseCode << "   "
            << " | " << uni.enrollments.at(i).midtermGrade << "   " 
            << " | " << uni.enrollments.at(i).finalGrade << "   " 
            << " | " << uni.enrollments.at(i).totalGrade << "   " 
            << " | " << uni.enrollments.at(i).letterGrade << "   " 
            << std::boolalpha << uni.enrollments.at(i).isCompleted << "\n";
    }
}

void displayTranscript(const University& uni)
{
    // This function gets the studentID and prints all completed courses and achieved grades.
    bool isFound{false};
    std::string stdID;
    double gpa;
    
    std::cout << "Enter the studentID: ";
    std::getline(std::cin, stdID);

    std::cout 
        << "| Course Code"
        << " | Midterm Grade"
        << " | Final Grade"
        << " | Total Grade"
        << " | Letter Grade\n";
    
        for (size_t i{0}; i < uni.enrollmentCount; ++i)
    {
        if (uni.enrollments.at(i).studentID == stdID && uni.enrollments.at(i).isCompleted)
        {
            isFound = true;

            std::cout
                << "| " << uni.enrollments.at(i).courseCode << "   "
                << " | " << uni.enrollments.at(i).midtermGrade << "   "
                << " | " << uni.enrollments.at(i).finalGrade << "   "
                << " | " << uni.enrollments.at(i).totalGrade << "   "
                << " | " << uni.enrollments.at(i).letterGrade << "\n";

            for (size_t j{0}; j < uni.studentCount; ++j)
            {
                if (uni.students.at(j).studentID == stdID)
                {
                    gpa = uni.students.at(j).gpa;
                    break;
                }
            }            
        }
    }

    std::cout << "Current GPA: " << gpa << "\n";

    if (!isFound)
    std::cout << "No courses have been finished yet or no passing grades exist.\n";
}