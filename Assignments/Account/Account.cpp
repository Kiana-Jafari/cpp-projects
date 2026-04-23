#include <stdexcept>
#include "Account.h"

Account::Account(const double accountBalance)
{
    // validity checking
    setBalance(accountBalance);
}

void Account::setBalance(const double accountBalance)
{
    if (accountBalance < 0)
    throw std::invalid_argument("Balance should be greater that or equal to 0");

    else
    balance = accountBalance;
}

const double Account::getBalance() const
{
    return balance;
}

void Account::credit(const double amount)
{
    balance += amount;
}

void Account::debit(const double amount)
{
    if (balance == 0)
    throw std::runtime_error("Current balance is 0. Can't withdraw money from the account.");

    if (amount > balance)
    throw std::invalid_argument("Debit amount exceeded account balance.");

    else
    balance -= amount;
}

bool Account::isWithdrawn(const double amount)
{
    if (amount > balance || balance == 0)
    return false;

    else
    return true;
}
