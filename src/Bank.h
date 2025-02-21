#ifndef BANK_H
#define BANK_H
#include <iostream>
#include <vector>
#include <fstream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

class Bank{
    private:
        vector<Account*> accounts;
    public:
        ~Bank();
        void createAccount();
        Account* findAccount(const string &accNum);
        void depositMoney();
        void withdrawMoney();
        void checkBalance();
        void loadAccounts();
        void saveAccounts();
};

#endif
