#include <stdexcept>
#include <sstream>
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(
    
    const double initBalance,
    const double transactionFee

) : Account(initBalance)

{
    // validity checking
    setTransactionFee(transactionFee);
}

void CheckingAccount::setTransactionFee(const double transactionFee)
{
    if (transactionFee < 0)
    throw std::invalid_argument("Transaction fee should be positive");

    else
    fee = transactionFee;
}

const double CheckingAccount::getTransactionFee() const
{
    return fee;
}

void CheckingAccount::credit(const double amount)
{
    double value{amount - fee};
    Account::credit(value);
}

void CheckingAccount::debit(const double amount)
{
    if (Account::isWithdrawn(amount))
    {
        Account::debit(amount);
        Account::setBalance(Account::getBalance() - fee);
    }

    else
    throw std::invalid_argument("Debit amount exceeded account balance.");
}
