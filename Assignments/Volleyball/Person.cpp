#include "Person.hpp"
#include <string>

// constructor
Person::Person(
    const std::string& firstName,
    const std::string& lastName,
    const std::string& fatherName,
    const std::string& phoneNumber,
    const std::string& address,
    const std::string& nationalID
)

{
    this->firstName = firstName;
    this->lastName = lastName;
    this->fatherName = fatherName;
    this->phoneNumber = phoneNumber;
    this->address = address;
    this->nationalID = nationalID;
}

// setters
void Person::setFirstName(const std::string& firstName) { this->firstName = firstName; }
void Person::setLastName(const std::string& lastName) { this->lastName = lastName; }
void Person::setFatherName(const std::string& fatherName) { this->fatherName = fatherName; }
void Person::setPhoneNumber(const std::string& phoneNumber) { this->phoneNumber = phoneNumber; }
void Person::setAddress(const std::string& address) { this->address = address; }
void Person::setNationalID(const std::string& nationalID) { this->nationalID = nationalID; }

// getters
const std::string& Person::getFirstName() const { return firstName; }
const std::string& Person::getLastName() const { return lastName; }
const std::string& Person::getFatherName() const { return fatherName; };
const std::string& Person::getPhoneNumber() const { return phoneNumber; }
const std::string& Person::getAddress() const { return address; }
const std::string& Person::getNationalID() const { return nationalID; }
