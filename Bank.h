#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>

using namespace std;

class Bank
{
private:
    string accountHolderName;
    int accountNumber;
    double balance;
    int PIN;
    string mobileNo;

public:
    // Default constructor
    Bank() : accountHolderName(""), accountNumber(0), balance(0.0), PIN(0), mobileNo("") {}

    // Parameterized constructor
    Bank(string name, int accNumber, double initialBalance, int pin, string mobile)
        : accountHolderName(name), accountNumber(accNumber), balance(initialBalance), PIN(pin), mobileNo(mobile) {}

    // Function to deposit amount
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "\nDeposit successful! New balance: $" << balance << endl;
        }
        else
        {
            cout << "\nInvalid amount!" << endl;
        }
    }

    // Function to withdraw amount
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "\nWithdrawal successful! New balance: $" << balance << endl;
        }
        else
        {
            cout << "\nInvalid amount or insufficient funds!" << endl;
        }
    }

    // Function to display account details
    void displayAccountDetails() const
    {
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Mobile Number: " << mobileNo << endl;
    }

    // Function to check the current balance
    void checkBalance() const
    {
        cout << "\nCurrent balance: $" << balance << endl;
    }

    // Function to get the PIN
    int getPin() const
    {
        return PIN;
    }

    // Function to update the mobile number
    void updateMobileNumber(const string &oldMobile, const string &newMobile)
    {
        if (oldMobile == mobileNo)
        {
            mobileNo = newMobile;
            cout << "\nMobile number updated successfully!" << endl;
        }
        else
        {
            cout << "\nIncorrect old mobile number!" << endl;
        }
    }
};

#endif
