/*
Name: Aiden Sinclair
Date: October 3, 2026
Purpose: Operator Overload Lab
Description:
This file contains the implementation of the BankAccount class.
It demonstrates the Rule of Three, operator overloading,
and static utility functions.
*/

#include "BankAccount.h"
#include <iostream>

using namespace std;


// ==============================
// Default Constructor
// ==============================
BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = "";
    balance = new double(0.0);
}


// ==============================
// Parameterized Constructor
// ==============================
BankAccount::BankAccount(string number, string name, double initialBalance) {
    accountNumber = number;
    accountHolderName = name;

    if (initialBalance < 0) {
        initialBalance = 0;
    }

    balance = new double(initialBalance);
}


// ==============================
// Copy Constructor
// Rule of Three
// ==============================
BankAccount::BankAccount(const BankAccount& other) {
    accountNumber = other.accountNumber;
    accountHolderName = other.accountHolderName;

    // Deep copy of the dynamically allocated balance
    balance = new double(*other.balance);
}


// ==============================
// Copy Assignment Operator
// Rule of Three
// ==============================
BankAccount& BankAccount::operator=(const BankAccount& other) {

    // Prevent assigning an object to itself
    if (this != &other) {
        accountNumber = other.accountNumber;
        accountHolderName = other.accountHolderName;

        // Copy the actual value instead of the pointer
        *balance = *other.balance;
    }

    return *this;
}


// ==============================
// Destructor
// Rule of Three
// ==============================
BankAccount::~BankAccount() {
    delete balance;
    balance = nullptr;
}


// ==============================
// Get Account Number
// ==============================
string BankAccount::getAccountNumber() const {
    return accountNumber;
}


// ==============================
// Get Account Holder Name
// ==============================
string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}


// ==============================
// Get Balance
// ==============================
double BankAccount::getBalance() const {
    return *balance;
}


// ==============================
// Set Account Holder Name
// ==============================
void BankAccount::setAccountHolderName(string name) {
    accountHolderName = name;
}


// ==============================
// Deposit
// ==============================
void BankAccount::deposit(double amount) {

    if (amount > 0) {
        *balance += amount;
    }
}


// ==============================
// Withdraw
// ==============================
bool BankAccount::withdraw(double amount) {

    if (amount <= 0) {
        return false;
    }

    if (amount > *balance) {
        return false;
    }

    *balance -= amount;
    return true;
}


// ==============================
// += Operator
// ==============================
BankAccount& BankAccount::operator+=(double amount) {

    if (amount > 0) {
        *balance += amount;
    }

    return *this;
}


// ==============================
// -= Operator
// ==============================
BankAccount& BankAccount::operator-=(double amount) {

    if (amount > 0 && amount <= *balance) {
        *balance -= amount;
    }

    return *this;
}


// ==============================
// == Operator
// ==============================
bool BankAccount::operator==(const BankAccount& other) const {

    return accountNumber == other.accountNumber;
}


// ==============================
// < Operator
// ==============================
bool BankAccount::operator<(const BankAccount& other) const {

    return *balance < *other.balance;
}


// ==============================
// > Operator
// ==============================
bool BankAccount::operator>(const BankAccount& other) const {

    return *balance > *other.balance;
}


// ==============================
// Static printAccount Function
// ==============================
void BankAccount::printAccount(const BankAccount& account) {

    cout << "Account Number: "
         << account.accountNumber << endl;

    cout << "Account Holder: "
         << account.accountHolderName << endl;

    cout << "Balance: $"
         << account.getBalance() << endl;
}


// ==============================
// Static createAccountFromInput
// Function
// ==============================
BankAccount BankAccount::createAccountFromInput() {

    string number;
    string name;
    double initialBalance;

    cout << "\nEnter account number: ";
    getline(cin, number);

    cout << "Enter account holder name: ";
    getline(cin, name);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    while (cin.fail() || initialBalance < 0) {
        cin.clear();
        cin.ignore(10000, '\n');

        cout << "Invalid balance. Enter a valid balance: ";
        cin >> initialBalance;
    }

    cin.ignore(10000, '\n');

    return BankAccount(number, name, initialBalance);
}
