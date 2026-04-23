#include <string>
#include "Account.h"

#ifndef SAVINGS_H
#define SAVINGS_H

class SavingsAccount : public Account {

public:

    SavingsAccount(
        const double,
        const double
    );

    void setInterestRate(const double);
    const double getInterestRate() const;

    double calculateInterest() const;

private:

    double interestRate{0};
};

#endif
