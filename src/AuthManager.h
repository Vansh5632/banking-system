#ifndef AUTH_MANAGER_H
#define AUTH_MANAGER_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class AuthManager{
    public:
        bool registerUser(const string &username,const string &password);
        bool loginUser(const string &username,const string &password);

};

#endif
