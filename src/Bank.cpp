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

Account* Bank::findAccount(const string &accNum){
    for(auto account : accounts){
        if(account->getAccountNumber() == accNum){
            return account;
        }
    }
    return nullptr;
}

void Bank::depositMoney(){
    string accNum;
    double amount;
    cout<<"Enter account number: ";
    cin>>accNum;
    Account *account = findAccount(accNum);
    if(account == nullptr){
        cout<<"Account not found"<<endl;
        return;
    }
    cout<<"Enter amount to deposit: ";
    cin>>amount;
    account->deposit(amount);
    saveAccounts();
    cout<<"Amount deposited successfully"<<endl;
}

void Bank::withdrawMoney(){
    string accNum;
    double amount;
    cout<<"Enter account number: ";
    cin>>accNum;
    Account *account = findAccount(accNum);
    if(account == nullptr){
        cout<<"Account not found"<<endl;
        return;
    }
    cout<<"Enter amount to withdraw: ";
    cin>>amount;
    if(account->withdraw(amount)){
        saveAccounts();
        cout<<"Amount withdrawn successfully"<<endl;
    }else{
        cout<<"Insufficient balance"<<endl;
    }
}

void Bank::checkBalance(){
    string accNum;
    cout<<"Enter account number: ";
    cin>>accNum;
    Account *account = findAccount(accNum);
    if(account == nullptr){
        cout<<"Account not found"<<endl;
        return;
    }
    account->displayAccount();
}
void Bank::saveAccounts(){
    ofstream file("accounts.txt");
    if(file.is_open()){
        for(auto account : accounts){
            file<<account->getAccountNumber()<<endl;
            file<<account->getBalance()<<endl;
        }
        file.close();
    }else{
        cout<<"Error saving accounts"<<endl;
    }
}
void Bank::loadAccounts(){
    ifstream file("accounts.txt");
    if(file.is_open()){
        string accNum;
        double balance;
        while(file>>accNum>>balance){
            Account *account = new Account(accNum,"",balance);
            accounts.push_back(account);
        }
        file.close();
    }else{
        cout<<"Error loading accounts"<<endl;
    }
}
