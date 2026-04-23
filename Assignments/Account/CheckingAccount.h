#include "Account.h"

#ifndef CHECKING_H
#define CHECHING_H

class CheckingAccount : public Account {

public:

    CheckingAccount(
        const double,
        const double
    );

    void setTransactionFee(const double);
    const double getTransactionFee() const;

    void credit(const double);
    void debit(const double);

private:

    double fee{0};
};

#endif
