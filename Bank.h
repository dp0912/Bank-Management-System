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
    Bank() : accountHolderName(""), accountNumber(0), balance(0.0), PIN(0), mobileNo("") {}

    Bank(string name, int accNumber, double initialBalance, int pin, string mobile)
        : accountHolderName(name), accountNumber(accNumber), balance(initialBalance), PIN(pin), mobileNo(mobile) {}

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

    void displayAccountDetails() const
    {
        cout << "\nAccount Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Mobile Number: " << mobileNo << endl;
    }

    void checkBalance() const
    {
        cout << "\nCurrent balance: $" << balance << endl;
    }

    int getPin() const
    {
        return PIN;
    }

    void updateMobileNumber(string oldMobile, string newMobile)
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
