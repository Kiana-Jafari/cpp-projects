#include <iostream>
#include "Structures.h"

int ScaleGrade(const char letterGrade);
char LetterGrade(const double totalGrade);

void dropCourse(University& uni)
{
    // This function gets the studentID and course code and drops that course if not completed by the student.
    std::string stdID, ccode;
    bool isDroped{false};

    std::cout << "Enter the studentID: ";
    std::getline(std::cin, stdID);

    std::cout << "Enter the course code: ";
    std::getline(std::cin, ccode);

    for (size_t i{0}; i < uni.enrollmentCount; i++)
    {
        if (uni.enrollments.at(i).courseCode == ccode && uni.enrollments.at(i).studentID == stdID && uni.enrollments.at(i).isCompleted == false)
        {
            isDroped = true;

            uni.enrollmentCount -- ; // Decrease the number of enrollments

            for (size_t j{i}; j < uni.enrollmentCount; j++) // Remove enrollment
            {
                uni.enrollments.at(j).courseCode = uni.enrollments.at(j + 1).courseCode;
                uni.enrollments.at(j).studentID = uni.enrollments.at(j + 1).studentID;
                uni.enrollments.at(j).midtermGrade = uni.enrollments.at(j + 1).midtermGrade;
                uni.enrollments.at(j).finalGrade = uni.enrollments.at(j + 1).finalGrade;
                uni.enrollments.at(j).totalGrade = uni.enrollments.at(j + 1).totalGrade;
                uni.enrollments.at(j).letterGrade = uni.enrollments.at(j + 1).letterGrade;
                uni.enrollments.at(j).isCompleted = uni.enrollments.at(j + 1).isCompleted;
            }

            for (size_t j{0}; j < uni.courseCount; j++) // Decrease the number of enrollments of that course and increase the current capacity by one
            {
                if (uni.courses.at(j).courseCode == ccode)
                {
                    uni.courses.at(j).enrolledCount --; 
                    uni.courses.at(j).currentCapacity ++;

                    break;
                }
            }

            break;
        }
    }

    if (!isDroped)
    std::cout << "Can't drop a completed course.\n";
}

void updateGrades(University& uni)
{
    // This function gets the studentID and the course code and updates the grades of the student in that course.
    std::string stdID, ccode, mid, final;
    bool isFound{false};

    std::cout << "Enter the studentID: ";
    std::getline(std::cin, stdID);

    std::cout << "Enter the course code: ";
    std::getline(std::cin, ccode);

    std::cout << "Enter the midterm grade: ";
    std::getline(std::cin, mid);

    std::cout << "Enter the final grade: ";
    std::getline(std::cin, final);

    double midtermGrade{stod(mid)};
    double finalGrade{stod(final)};

    double totalGrade{(0.4 * midtermGrade + 0.6 * finalGrade)}; // Calculate total grade

    char letterGrade{LetterGrade(totalGrade)}; // Get the character equivalent

    for (size_t i{0}; i < uni.enrollmentCount; i++)
    {
        if (uni.enrollments.at(i).studentID == stdID && uni.enrollments.at(i).courseCode == ccode)
        {
            uni.enrollments.at(i).midtermGrade = midtermGrade;
            uni.enrollments.at(i).finalGrade = finalGrade;
            uni.enrollments.at(i).totalGrade = totalGrade;
            uni.enrollments.at(i).letterGrade = letterGrade;

            if (letterGrade == 'F') // Equivalent to `Fail`
            uni.enrollments.at(i).isCompleted = false;

            else
            uni.enrollments.at(i).isCompleted = true;

            break;
        }
    }
}

void computeGPA(University& uni)
{
    // This function gets a studentID and computes the GPA of that student among all completed courses.
    std::string stdID;
    double totalGrade{0.0};
    unsigned int totalCredits{0};
    bool isFound{false};

    std::cout << "Enter the studentID: ";
    std::getline(std::cin, stdID);

    for (size_t i{0}; i < uni.enrollmentCount; i++)
    {
        if (uni.enrollments.at(i).studentID == stdID && uni.enrollments.at(i).isCompleted)
        {
            isFound = true; // If any completed course is found

            char letter{uni.enrollments.at(i).letterGrade};
            int grade{ScaleGrade(letter)};

            std::string ccode{uni.enrollments.at(i).courseCode}; // Get the course code (completed course)

            for (size_t j{0}; j < uni.courseCount; j++)
            {
                if (uni.courses.at(j).courseCode == ccode)
                {   
                    totalGrade += (grade * uni.courses.at(j).creditHours);
                    totalCredits += uni.courses.at(j).creditHours;
                }
            }
        }
    }

    if (!isFound)
    {
        std::cout << "No courses have been finished yet or no passing grades exist.\n";
        return ;
    }

    double gpa{totalGrade / static_cast<double>(totalCredits)}; // Calculate GPA
    
    for (size_t i{0}; i < uni.studentCount; i++) // Update GPA of that student
    {
        if (uni.students.at(i).studentID == stdID)
        {
            uni.students.at(i).gpa = gpa;
            break;
        }
    }
}

int ScaleGrade(const char letterGrade)
{
    // This helper function gets the letter grade and returns its equivalent scaled grade.
    int grade;

    if (letterGrade == 'A') 
    grade = 4;

    else if (letterGrade == 'B')
    grade = 3;

    else if (letterGrade == 'C') 
    grade = 2;

    return grade;
}

char LetterGrade(const double totalGrade)
{
    // This helper function returns the letter grade based on the total grade.
    char letter;

    if (totalGrade >= 80 && totalGrade <= 100) 
    letter = 'A';

    else if (totalGrade >= 60 && totalGrade < 80) 
    letter = 'B';

    else if (totalGrade >= 40 && totalGrade < 60) 
    letter = 'C';

    else if (totalGrade >= 0 && totalGrade < 40) 
    letter = 'F';

    return letter;
}