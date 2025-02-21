#include "SavingsAccount.h"
SavingsAccount::SavingsAccount(string accNum,string name,double initialBalance,double rate)
    : Account(accNum,name,initialBalance) {
        interestRate = rate;

    }        

void SavingsAccount::addInterest() {
    double interest = balance * interestRate;
    deposit(interest);
    cout << "Interest of " << interest << " added to account " << accountNumber << endl;
}