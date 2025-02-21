#include <iostream>
#include "AuthManager.h"
#include "Bank.h"

using namespace std;

int main() {
    AuthManager auth;
    Bank bank;
    bank.loadAccounts();

    int authChoice;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> authChoice;

    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (authChoice == 1) {
        auth.registerUser(username, password);
    } else if (authChoice == 2) {
        if (!auth.loginUser(username, password)) return 0;
    } else {
        return 0;
    }

    int choice;
    while (true) {
        cout << "\n1. Create Account\n2. Deposit Money\n3. Withdraw Money\n4. Check Balance\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: bank.createAccount(); break;
            case 2: bank.depositMoney(); break;
            case 3: bank.withdrawMoney(); break;
            case 4: bank.checkBalance(); break;
            case 5: return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
}
