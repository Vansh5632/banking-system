#include <iostream>
#include "AuthManager.h"

int main(){
    AuthManager auth;
    int authChoice;

    cout<<"==========================="<<endl;
    cout<<"welcome to gilhotra bank systems"<<endl;
    cout<<"============================"<<endl;
    cout<<"1. Register"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"Enter your choice:";
    cin>>authChoice;

    string username,password;

    cout<<"Enter username:";
    cin>>username;
    cout<<"Enter password:";
    cin>>password;

    if(authChoice == 1){
        auth.registerUser(username,password);
    }else if(authChoice == 2){
        if(!auth.loginUser(username,password)){
            cout<<"exiting program"<<endl;
            return 0;
        }
    }else{
        cout<<"Invalid choice"<<endl;
        return 0;
    }
}