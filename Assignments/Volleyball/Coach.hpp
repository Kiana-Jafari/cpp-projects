#ifndef COACH_HPP
#define COACH_HPP

#include "Person.hpp"

class Coach : public Person {

public:

    // constructors
    Coach() = default;
    Coach(
        const std::string&,
        const std::string&,
        const std::string&,
        const std::string&,
        const std::string&,
        const std::string&,
        int
    );

    // setter
    void setCoachID(int);

    // getter
    const int getCoachID() const;

private:

    int coachID;
};

#endif
