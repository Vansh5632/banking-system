#include "Bank.h"

Bank::~Bank(){
    for(auto account : accounts){
        delete account;
    }
        
}

void Bank::createAccount(){
    string name,accNum,type;
    double initialBalance;

    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter account number: ";
    cin>>accNum;
    cout<<"Enter initial balance: ";
    cin>>initialBalance;
    cout<<"Enter account type (Savings/Current): ";
    cin>>type;

    Account *account = nullptr;
    if(type == "Savings"){
        double interestRate;
        cout<<"Enter interest rate: ";
        cin>>interestRate;
        account = new SavingsAccount(accNum,name,initialBalance,interestRate);
    }else if(type == "Current"){
        double overdraftLimit;
        cout<<"Enter overdraft limit: ";
        cin>>overdraftLimit;
        account = new CheckingAccount(accNum,name,initialBalance,overdraftLimit);
    }else{
        cout<<"Invalid account type"<<endl;
        return;
    }
    accounts.push_back(account);
    saveAccounts();
    cout<<"Account created successfully"<<endl;
}
