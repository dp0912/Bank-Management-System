#include <iostream>
#include "Bank.h"

using namespace std;

void displayMenu()
{
    cout << "\n\n\t\t---------   Bank Management System   ----------\n"
         << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Account Details" << endl;
    cout << "6. Update Mobile Number" << endl;
    cout << "7. Exit" << endl;
    cout << "\nChoose an option: ";
}

int main()
{
    Bank bankAccount;
    int choice;
    string name;
    int accNumber;
    double initialBalance;
    double amount;
    string mobile;
    int pin, enteredPin;
    string oldMobile, newMobile;
    bool accountCreated = false;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Account Holder Name: ";
            cin >> name;
            cout << "\nEnter Account Number: ";
            cin >> accNumber;
            cout << "\nEnter Initial Balance: ";
            cin >> initialBalance;
            cout << "\nSet a 4-digit PIN: ";
            cin >> pin;
            cout << "\nEnter Mobile Number: ";
            cin >> mobile;
            bankAccount = Bank(name, accNumber, initialBalance, pin, mobile);
            cout << "\nAccount Created Successfully!" << endl;
            accountCreated = true;
            break;

        case 2:
            if (accountCreated)
            {
                cout << "\nEnter PIN: ";
                cin >> enteredPin;
                if (enteredPin == bankAccount.getPin())
                {
                    cout << "\nEnter Amount to Deposit: ";
                    cin >> amount;
                    bankAccount.deposit(amount);
                }
                else
                {
                    cout << "\nIncorrect PIN!" << endl;
                }
            }
            else
            {
                cout << "\nNo account found. Please create an account first." << endl;
            }
            break;

        case 3:
            if (accountCreated)
            {
                cout << "\nEnter PIN: ";
                cin >> enteredPin;
                if (enteredPin == bankAccount.getPin())
                {
                    cout << "\nEnter Amount to Withdraw: ";
                    cin >> amount;
                    bankAccount.withdraw(amount);
                }
                else
                {
                    cout << "\nIncorrect PIN!" << endl;
                }
            }
            else
            {
                cout << "\nNo account found. Please create an account first." << endl;
            }
            break;

        case 4:
            if (accountCreated)
            {
                cout << "\nEnter PIN: ";
                cin >> enteredPin;
                if (enteredPin == bankAccount.getPin())
                {
                    bankAccount.checkBalance();
                }
                else
                {
                    cout << "\nIncorrect PIN!" << endl;
                }
            }
            else
            {
                cout << "\nNo account found. Please create an account first." << endl;
            }
            break;

        case 5:
            if (accountCreated)
            {
                cout << "\nEnter PIN: ";
                cin >> enteredPin;
                if (enteredPin == bankAccount.getPin())
                {
                    bankAccount.displayAccountDetails();
                }
                else
                {
                    cout << "\nIncorrect PIN!" << endl;
                }
            }
            else
            {
                cout << "\nNo account found. Please create an account first." << endl;
            }
            break;

        case 6:
            if (accountCreated)
            {
                cout << "\nEnter PIN: ";
                cin >> enteredPin;
                if (enteredPin == bankAccount.getPin())
                {
                    cout << "\nEnter old mobile number: ";
                    cin >> oldMobile;
                    cout << "\nEnter new mobile number: ";
                    cin >> newMobile;
                    bankAccount.updateMobileNumber(oldMobile, newMobile);
                }
                else
                {
                    cout << "\nIncorrect PIN!" << endl;
                }
            }
            else
            {
                cout << "\nNo account found. Please create an account first." << endl;
            }
            break;

        case 7:
            cout << "\nExiting the system. Goodbye!" << endl;
            break;

        default:
            cout << "\nInvalid option. Please try again." << endl;
            break;
        }
    } while (choice != 7);

    return 0;
}
