#include <string>
#include <sstream>
#include "Person.h"

PersonInfo::PersonInfo(
    const std::string& name,
    const std::string& address,
    const std::string& city,
    const std::string& state,
    const std::string& ZIPcode
)

{
    this->name = name;
    this->address = address;
    this->city = city;
    this->state = state;
    this->ZIPcode = ZIPcode;
}

// Setters
void PersonInfo::setName(const std::string& name)
{
    this->name = name;
}

void PersonInfo::setAddress(const std::string& address)
{
    this->address = address;
}

void PersonInfo::setCity(const std::string& city)
{
    this->city = city;
}

void PersonInfo::setState(const std::string& state)
{
    this->state = state;
}

void PersonInfo::setZIPcode(const std::string& ZIPcode)
{
    this->ZIPcode = ZIPcode;
}

// Getters
const std::string& PersonInfo::getName() const
{
    return name;
}

const std::string& PersonInfo::getAddress() const
{
    return address;
}

const std::string& PersonInfo::getCity() const
{
    return city;
}

const std::string& PersonInfo::getState() const
{
    return state;
}

const std::string& PersonInfo::getZIPcode() const
{
    return ZIPcode;
}

std::string PersonInfo::toString() const
{
    std::stringstream output;

    output
    << "\nfull name: " << getName()
    << "\naddress: " << getAddress()
    << "\ncity: " << getCity()
    << "\nstate: " << getState()
    << "\nZIP code: " << getZIPcode();

    return output.str();
}
