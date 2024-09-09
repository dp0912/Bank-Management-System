#include <iostream>
#include <cctype> // for isalpha, isdigit
#include <string>

#include "Bank.h"

using namespace std;

// Helper functions for validation
bool isValidName(const string &name)
{
    for (char c : name)
    {
        if (!isalpha(c))
        {
            return false;
        }
    }
    return true;
}

bool isValidAccountNumber(const string &accNumber)
{
    for (char c : accNumber)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

bool isValidMobileNumber(const string &mobile)
{
    if (mobile.length() != 10)
    {
        return false;
    }
    for (char c : mobile)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

bool isValidBalance(double balance)
{
    return balance >= 0;
}

bool isValidPin(int pin)
{
    return pin >= 1000 && pin <= 9999;
}

void displayMenu()
{
    cout << "\n\n\t\t---------   Bank Management System   ----------\n"
         << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Account Details" << endl;
    cout << "6. Update Account Info" << endl; // Updated menu option
    cout << "7. Exit" << endl;
    cout << "\nChoose an option: ";
}

int main()
{
    Bank bankAccount;
    int choice;
    string name;
    string accNumber;
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
            // Validate Account Holder Name
            do
            {
                cout << "\nEnter Account Holder Name: ";
                cin >> name;
                if (!isValidName(name))
                {
                    cout << "\nInvalid name! Only alphabetic characters are allowed. Please try again." << endl;
                }
            } while (!isValidName(name));

            // Validate Account Number
            do
            {
                cout << "\nEnter Account Number: ";
                cin >> accNumber;
                if (!isValidAccountNumber(accNumber))
                {
                    cout << "\nInvalid account number! Only digits are allowed. Please try again." << endl;
                }
            } while (!isValidAccountNumber(accNumber));

            // Validate Initial Balance
            do
            {
                cout << "\nEnter Initial Balance: ";
                cin >> initialBalance;
                if (!isValidBalance(initialBalance))
                {
                    cout << "\nInvalid balance! It must be zero or a positive number. Please try again." << endl;
                }
            } while (!isValidBalance(initialBalance));

            // Validate PIN
            do
            {
                cout << "\nSet a 4-digit PIN: ";
                cin >> pin;
                if (!isValidPin(pin))
                {
                    cout << "\nInvalid PIN! It must be a 4-digit number. Please try again." << endl;
                }
            } while (!isValidPin(pin));

            // Validate Mobile Number
            do
            {
                cout << "\nEnter Mobile Number: ";
                cin >> mobile;
                if (!isValidMobileNumber(mobile))
                {
                    cout << "\nInvalid mobile number! It should be a 10-digit number. Please try again." << endl;
                }
            } while (!isValidMobileNumber(mobile));

            // Convert account number from string to integer
            int accountNumber;
            accountNumber = 0;
            for (char c : accNumber)
            {
                accountNumber = accountNumber * 10 + (c - '0');
            }

            bankAccount = Bank(name, accountNumber, initialBalance, pin, mobile);
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
                    // Update entire account information
                    do
                    {
                        cout << "\nEnter New Account Holder Name: ";
                        cin >> name;
                        if (!isValidName(name))
                        {
                            cout << "\nInvalid name! Only alphabetic characters are allowed. Please try again." << endl;
                        }
                    } while (!isValidName(name));

                    do
                    {
                        cout << "\nEnter New Account Number: ";
                        cin >> accNumber;
                        if (!isValidAccountNumber(accNumber))
                        {
                            cout << "\nInvalid account number! Only digits are allowed. Please try again." << endl;
                        }
                    } while (!isValidAccountNumber(accNumber));

                    do
                    {
                        cout << "\nEnter New Initial Balance: ";
                        cin >> initialBalance;
                        if (!isValidBalance(initialBalance))
                        {
                            cout << "\nInvalid balance! It must be zero or a positive number. Please try again." << endl;
                        }
                    } while (!isValidBalance(initialBalance));

                    do
                    {
                        cout << "\nEnter New 4-digit PIN: ";
                        cin >> pin;
                        if (!isValidPin(pin))
                        {
                            cout << "\nInvalid PIN! It must be a 4-digit number. Please try again." << endl;
                        }
                    } while (!isValidPin(pin));

                    do
                    {
                        cout << "\nEnter New Mobile Number: ";
                        cin >> mobile;
                        if (!isValidMobileNumber(mobile))
                        {
                            cout << "\nInvalid mobile number! It should be a 10-digit number. Please try again." << endl;
                        }
                    } while (!isValidMobileNumber(mobile));

                    int newAccountNumber = 0;
                    for (char c : accNumber)
                    {
                        newAccountNumber = newAccountNumber * 10 + (c - '0');
                    }

                    bankAccount = Bank(name, newAccountNumber, initialBalance, pin, mobile);
                    cout << "\nAccount Information Updated Successfully!" << endl;
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
