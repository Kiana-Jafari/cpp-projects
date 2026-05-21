#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

class Person {

public:

    // default & parameterized constructors
    Person() = default;
    Person(
        const std::string&,
        const std::string&,
        const std::string&,
        const std::string&,
        const std::string&,
        const std::string&
    );

    // setters
    void setFirstName(const std::string&);
    void setLastName(const std::string&);
    void setFatherName(const std::string&);
    void setPhoneNumber(const std::string&);
    void setAddress(const std::string&);
    void setNationalID(const std::string&);

    // getters
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getFatherName() const;
    const std::string& getPhoneNumber() const;
    const std::string& getAddress() const;
    const std::string& getNationalID() const;

private:

    std::string firstName;
    std::string lastName;
    std::string fatherName;
    std::string phoneNumber;
    std::string address;
    std::string nationalID;

};

#endif
