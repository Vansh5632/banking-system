#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account {
    protected:
        string name;
        string accountNumber;
        double balance;
    public:
        Account(string accNum,string name,double intialBalance);

        void deposit(double amount);
        virtual bool withdraw(double amount); 
        void displayAccount() const;

        string getAccountNumber() const {return accountNumber;}
        double getBalance() const {return balance;}
}