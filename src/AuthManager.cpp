#include "AuthManager.h"

bool AuthManager::registerUser(const string &username,const string& password){
    ofstream file("data/user.txt",ios::app);
    if(!file){
        cout<<"Error opening file"<<endl;
        return false;
    }
    file<<username<<" "<<password<<endl;
    file.close();

    cout<<"registration successful"<<endl;
    return true;
}

bool AuthManager::loginUser(const string &username,const string &password){
    ifstream file("data/user.txt");
    if(!file){
        cout<<"Error opening file"<<endl;
        return false;
    }
    string storedUser,storedPass;
    while(file>>storedUser>>storedPass){
        if(storedUser==username && storedPass==password){
            file.close();
            cout<<"login successful"<<endl;
            return true;
        }
    }
    file.close();
    cout<<"Invalid username or password"<<endl;
    return false;
}