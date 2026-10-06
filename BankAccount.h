/*
Name: Aiden Sinclair
Date: October 3, 2026
Purpose: Operator Overload Lab
Description:
This header file defines the BankAccount class.
The class demonstrates the Rule of Three, operator overloading,
and static utility functions.
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double* balance;

public:
    // Default constructor
    BankAccount();

    // Parameterized constructor
    BankAccount(std::string number, std::string name, double initialBalance);

    // Rule of Three
    BankAccount(const BankAccount& other);
    BankAccount& operator=(const BankAccount& other);
    ~BankAccount();

    // Getters
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    // Setter
    void setAccountHolderName(std::string name);

    // Original deposit and withdrawal functions
    void deposit(double amount);
    bool withdraw(double amount);

    // Arithmetic assignment operators
    BankAccount& operator+=(double amount);
    BankAccount& operator-=(double amount);

    // Comparison operators
    bool operator==(const BankAccount& other) const;
    bool operator<(const BankAccount& other) const;
    bool operator>(const BankAccount& other) const;

    // Static utility functions
    static void printAccount(const BankAccount& account);
    static BankAccount createAccountFromInput();
};

#endif
