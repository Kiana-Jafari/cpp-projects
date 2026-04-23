#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main()
{
    Account account1{500.0};
    std::cout 
    << "Balance set to $" << account1.getBalance() 
    << "\n\n";

    // ------------

    double value{-100};

    try
    {
        Account account2{value};
        std::cout << "Balance set to $" << account2.getBalance();
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // ------------

    account1.credit(200.0);
    std::cout 
    << "Account 1 balance after depositing: $" 
    << account1.getBalance() << "\n\n";

    // ------------

    account1.debit(300.0);
    std::cout
    << "Account 1 balance after withdrawing money: $"
    << account1.getBalance() << "\n\n";

    try
    {
        account1.debit(800.0);
        std::cout
        << "Account 1 balance after withdrawing money: $"
        << account1.getBalance();
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // ------------

    SavingsAccount s1{1000.0, 0.05};
    std::cout
    << "initial balance: $" << s1.getBalance()
    << "\ninterest rate: $" << s1.getInterestRate()
    << "\ncalculated interest: $" << s1.calculateInterest();

    s1.credit(s1.calculateInterest());

    std::cout
    << "\n\nbalance after adding calculated interest: $" 
    << s1.getBalance() << "\n\n";

    s1.debit(200.0);

    std::cout
    << "Balance after withdrawing: $" 
    << s1.getBalance() << "\n\n";

    // ------------

    CheckingAccount c1{500.0, 2.0};
    c1.credit(100.0);

    std::cout 
    << "New balance after applying transaction fee: $"
    << c1.getBalance();

    // ------------

    c1.debit(50.0);
    std::cout 
    << "\n\nNew balance after withdrawing money: (with transaction fee): $"
    << c1.getBalance() << "\n\n";

    // ------------

    try
    {
        c1.debit(1000.0);
        std::cout 
        << "\n\nBalance after withdrawing money: (with transaction fee): $"
        << c1.getBalance() << "\n\n";
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // ------------

    SavingsAccount s2{1000.0, 0.03};

    s2.credit(s2.calculateInterest());

    std::cout 
    << "Expected balance: $" 
    << s2.getBalance() << "\n\n";

    // ------------

    s2.setBalance(500.0);
    s2.setInterestRate(0.1);
    s2.credit(100); // Balance = $600

    std::cout 
    << "Balance after deposit: $" 
    << s2.getBalance() << "\n\n";

    s2.debit(50); // Balance = $550
    
    std::cout
    << "Balance after withdrawal: $"
    << s2.getBalance() << "\n\n";

    // ------------
    CheckingAccount c2{300.0, 1};
    c2.credit(50.0);

    std::cout 
    << "Balance after deposit: $"
    << c2.getBalance() << "\n\n";

    c2.debit(100);

    std::cout 
    << "Balance after deposit: $"
    << c2.getBalance() << "\n\n";

    try
    {
        c2.debit(300);
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Current balance: $" << c2.getBalance();
}   
