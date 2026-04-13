#pragma once

#include <cstddef>
#include <array>
#include <string>

const size_t MAX_STUDENTS{200};
const size_t MAX_COURSES{100};
const size_t MAX_ENROLLMENTS{500};

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    std::string studentID;
    std::string fullName;
    Date birthDate;
    std::string major;
    double gpa;
};

struct Course {
    std::string courseCode;
    std::string courseName;
    int creditHours;
    int capacity;
    int currentCapacity;
    int enrolledCount;
};

struct Enrollment {
    std::string studentID;
    std::string courseCode;
    double midtermGrade;
    double finalGrade;
    double totalGrade;
    char letterGrade;
    bool isCompleted;
};

struct University {
    std::array<Student, MAX_STUDENTS> students{};
    std::array<Course, MAX_COURSES> courses{};
    std::array<Enrollment, MAX_ENROLLMENTS> enrollments{};
    unsigned int studentCount{0};
    unsigned int courseCount{0};
    unsigned int enrollmentCount{0};
};