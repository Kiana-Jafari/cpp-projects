#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {

public:

    explicit Account(const double);

    // setter and getter
    void setBalance(const double);
    const double getBalance() const;

    void credit(const double);
    void debit(const double);

    bool isWithdrawn(const double);

private:

    double balance{0};
};

#endif
