#include "Person.h"
#include "Package.h"

#ifndef TWODAY_H
#define TWODAY_H

class TwoDayPackage : public Package {

public:

    TwoDayPackage(
        const PersonInfo&,
        const PersonInfo&,
        const double,
        const double,
        const double,
        const double,
        const double,
        const double
    );

    void setFlatFee(const double);
    const double getFlatFee() const;

    double calculateCost() const;

    std::string toString() const;

private:

    double flatFee{0};
};

#endif
