#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
    private:
        double interestRate;
    public:
        SavingsAccount(string accNum,string name,double initialBalance,double rate);
        void addInterest();
};
#endif