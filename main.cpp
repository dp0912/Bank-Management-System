#include <iostream>
#include "Bank.h"

using namespace std;

void displayMenu()
{
    cout << "Bank Management System" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Account Details" << endl;
    cout << "6. Exit" << endl;
    cout << "Choose an option: ";
}

int main()
{
    Bank bankAccount;
    int choice;
    string name;
    int accNumber;
    double initialBalance;
    double amount;
    bool accountCreated = false;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Account Holder Name: ";
            cin >> name;
            cout << "Enter Account Number: ";
            cin >> accNumber;
            cout << "Enter Initial Balance: ";
            cin >> initialBalance;
            bankAccount = Bank(name, accNumber, initialBalance);
            cout << "Account Created Successfully!" << endl;
            accountCreated = true;
            break;

        case 2:
            if (accountCreated)
            {
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                bankAccount.deposit(amount);
            }
            else
            {
                cout << "No account found. Please create an account first." << endl;
            }
            break;

        case 3:
            if (accountCreated)
            {
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                bankAccount.withdraw(amount);
            }
            else
            {
                cout << "No account found. Please create an account first." << endl;
            }
            break;

        case 4:
            if (accountCreated)
            {
                bankAccount.checkBalance();
            }
            else
            {
                cout << "No account found. Please create an account first." << endl;
            }
            break;

        case 5:
            if (accountCreated)
            {
                bankAccount.displayAccountDetails();
            }
            else
            {
                cout << "No account found. Please create an account first." << endl;
            }
            break;

        case 6:
            cout << "Exiting the system. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}
