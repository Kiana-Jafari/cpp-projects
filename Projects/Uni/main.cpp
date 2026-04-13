#include <iostream>
#include "Structures.h"
#include "Create.h"
#include "Preprocess.h"
#include "Display.h"

int main()
{
    std::string option;
    University uni;

    std::cout << R"(
    === University Course Registration System ===

    This program is a university course registration system and is able to do the following:

    1. Register Students
    2. Display Registered Students
    3. Add Courses
    4. Display Courses
    5. Enroll Student in Courses
    6. Display Enrolled Students
    7. Record and Update Grades
    8. Compute GPA
    9. Drop Course
    10. Display Transcript
    
    Enter the option you want by typing its number. 
    For instance, if you want to drop a course, simply type "9";
    Feel free to play around and test the options!
    )";
    std::cout << "\n";
    
    while (true)
    {
        std::cout << "Enter an option: ";
        std::getline(std::cin, option);

        if (option == "exit")
        break;

        else if (option == "1")
        registerStudents(uni);

        else if (option == "2")
        displayStudents(uni);

        else if (option == "3")
        addCourse(uni);

        else if (option == "4")
        displayCourses(uni);

        else if (option == "5")
        enrollStudent(uni);

        else if (option == "6")
        displayEnrolledCourses(uni);

        else if (option == "7")
        updateGrades(uni);

        else if (option == "8")
        computeGPA(uni);

        else if (option == "9")
        dropCourse(uni);

        else if (option == "10")
        displayTranscript(uni);
    }
}