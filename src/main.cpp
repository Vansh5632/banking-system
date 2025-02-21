#include <iostream>
#include "AuthManager.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main() {
    // Authentication Step
    AuthManager auth;
    int authChoice;
    
    cout << "===================================" << endl;
    cout << "  Welcome to Simple Banking System " << endl;
    cout << "===================================" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice: ";
    cin >> authChoice;

    string username, password;
    
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (authChoice == 1) {
        auth.registerUser(username, password);
    } else if (authChoice == 2) {
        if (!auth.loginUser(username, password)) {
            cout << "Exiting program!" << endl;
            return 0;
        }
    } else {
        cout << "Invalid choice! Exiting program." << endl;
        return 0;
    }

    // Account Testing
    SavingsAccount mySavings("S12345", "Alice", 1000.0, 5.0);
    CheckingAccount myChecking("C67890", "Bob", 500.0, 200.0);

    cout << "\nTesting Savings Account:\n";
    mySavings.deposit(200);
    mySavings.addInterest();
    mySavings.withdraw(500);
    mySavings.displayAccount();

    cout << "\nTesting Checking Account:\n";
    myChecking.deposit(100);
    myChecking.withdraw(700);
    myChecking.displayAccount();

    return 0;
}
