#include <stdexcept>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(

    const double initBalance,
    const double rate

) : Account(initBalance)

{
    // validity checking
    setInterestRate(rate);
}

void SavingsAccount::setInterestRate(const double rate)
{
    if (rate < 0.0 || rate > 1.0)
    throw std::invalid_argument("Interest rate should be between 0 and 1");

    else
    interestRate = rate;
}

const double SavingsAccount::getInterestRate() const
{
    return interestRate;
}

double SavingsAccount::calculateInterest() const
{
    // returns a double indicating the amount of interest earned by an account
    return (Account::getBalance() * getInterestRate());
}
