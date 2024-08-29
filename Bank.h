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

public:
    Bank() : accountHolderName(""), accountNumber(0), balance(0.0) {}

    Bank(string name, int accNumber, double initialBalance)
        : accountHolderName(name), accountNumber(accNumber), balance(initialBalance) {}

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful! New balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid amount!" << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful! New balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid amount or insufficient funds!" << endl;
        }
    }

    void displayAccountDetails() const
    {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    void checkBalance() const
    {
        cout << "Current balance: $" << balance << endl;
    }
};

#endif
