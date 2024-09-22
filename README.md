# Bank Management System

## Description
This project is a simple Bank Management System implemented in C++. It allows users to create a bank account, deposit and withdraw money, check their balance, view account details, and update all account information. The system includes validation for user inputs to ensure data integrity.

## Features
- **Create Account**: Create a new bank account by providing the account holder's name, account number, initial balance, PIN, and mobile number.
- **Deposit**: Deposit a specified amount into the account after PIN validation.
- **Withdraw**: Withdraw a specified amount from the account after PIN validation.
- **Check Balance**: Check the current balance of the account after PIN validation.
- **View Account Details**: Display all account details including the account holder's name, account number, balance, and mobile number after PIN validation.
- **Update Account Info**: Update the entire account information including name, account number, initial balance, PIN, and mobile number after PIN validation.
- **Exit**: Exit the system.

## Getting Started

### Prerequisites
- A C++ compiler (e.g., g++, clang++)
- A text editor or IDE (e.g., VSCode, Code::Blocks)

### Usage
1. **Creating an Account**: Select option 1 from the menu. Enter the required details including account holder's name, account number, initial balance, PIN, and mobile number. The account will be created and stored in memory.
2. **Depositing Money**: Select option 2 from the menu. Enter your PIN and the amount to deposit.
3. **Withdrawing Money**: Select option 3 from the menu. Enter your PIN and the amount to withdraw.
4. **Checking Balance**: Select option 4 from the menu. Enter your PIN to view the current balance.
5. **Viewing Account Details**: Select option 5 from the menu. Enter your PIN to view account details.
6. **Updating Account Information**: Select option 6 from the menu. Enter your PIN and provide the new account details including name, account number, initial balance, PIN, and mobile number.
7. **Exiting**: Select option 7 to exit the program.

## Code Structure
- `main.cpp`: Contains the main program logic and user interface for the bank management system.
- `Bank.h`: Defines the Bank class with methods for managing bank account operations.

## Validation Rules
- **Account Holder Name**: Only alphabetic characters are allowed.
- **Account Number**: Must be numeric.
- **Initial Balance**: Must be zero or positive.
- **PIN**: Must be a 4-digit number.
- **Mobile Number**: Must be exactly 10 digits.


