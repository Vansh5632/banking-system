#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account{
    private:
        double overdraftLimit;
    public:
        CheckingAccount(string accNum,string name,double initialBalance,double overdraftLimit);
        bool withdraw(double amount) override;
};

#endif