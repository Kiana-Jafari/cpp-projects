#include "Coach.hpp"

Coach::Coach(
    const std::string& firstName,
    const std::string& lastName,
    const std::string& fatherName,
    const std::string& phoneNumber,
    const std::string& address,
    const std::string& nationalID,
    int coachID

) : Person(firstName, lastName, fatherName, phoneNumber, address, nationalID)

{
    this->coachID = coachID;    
}

// setter
void Coach::setCoachID(int coachID) { this->coachID = coachID; }

// getter
const int Coach::getCoachID() const { return coachID; }
