#include <string>

#include "Package.h"
#include "Person.h"

#ifndef OVERNIGHT_H
#define OVERNIGHT_H

class OvernightPackage : public Package {

public:

    OvernightPackage(
        const PersonInfo&,
        const PersonInfo&,
        const double,
        const double,
        const double,
        const double,
        const double,
        const double
    );

    void setFeePerWeight(const double);
    const double getFeePerWight() const;

    double calculateCost() const;

    std::string toString() const;

private:

    double feePerWight{0};

};

#endif
