#include "Account.h"

Account::Account(string accNum,string name,double initialBalance) {
    accountNumber = accNum;
    this->name = name;
    balance = initialBalance;
}

void Account::deposit(double amount) {
    if(amount>0){
        balance += amount;
        cout<<"Deposit of $"<<amount<<" successful\n"<<" | New balance: $"<<balance<<endl;
    }else{
        cout<<"Invalid deposit amount\n";
    }
}

bool Account::withdraw(double amount){
    if(amount>0 && balance-amount>=0){
        balance -= amount;
        cout<<"Withdrawal of $"<<amount<<" successful\n"<<" | New balance: $"<<balance<<endl;
        return true;
    }else{
        cout<<"Invalid withdrawal amount\n";
        return false;
    }
}

void Account::displayAccount() const {
    cout<<"Account Number: "<<accountNumber<<endl;
    cout<<"Account Holder: "<<name<<endl;
    cout<<"Balance: $"<<balance<<endl;
}