#include <string>

#ifndef PERSON_H
#define PERSON_H

class PersonInfo {

public:

    PersonInfo(
        const std::string&,
        const std::string&,
        const std::string&,
        const std::string&,
        const std::string&
    );

    void setName(const std::string&);
    void setAddress(const std::string&);
    void setCity(const std::string&);
    void setState(const std::string&);
    void setZIPcode(const std::string&);

    const std::string& getName() const;
    const std::string& getAddress() const;
    const std::string& getCity() const;
    const std::string& getState() const;
    const std::string& getZIPcode() const;

    std::string toString() const;

private:

    std::string name;
    std::string address;
    std::string city;
    std::string state;
    std::string ZIPcode;
};

#endif
