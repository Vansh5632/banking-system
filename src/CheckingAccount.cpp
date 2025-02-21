#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(string accNum,string name,double initialBalance,double overdraftLimit):Account(accNum,name,initialBalance){
    overdraftLimit = overdraftLimit;
}

bool CheckingAccount::withdraw(double amount){
    if(amount>0 && amount<=balance+overdraftLimit){
        balance -= amount;
        cout<<"Withdrawal of $"<<amount<<" successful"<<endl;
        return true;
    }
    else{
        cout<<"Withdrawal of $"<<amount<<" unsuccessful"<<endl;
        return false;
    }
}
