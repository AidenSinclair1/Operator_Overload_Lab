/*
Name: Aiden Sinclair
Date: October 3, 2026
Purpose: Operator Overload Lab
Description:
This program demonstrates the Rule of Three, operator overloading,
and static utility functions using a BankAccount class.
*/

#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "BankAccount.h"

using namespace std;


// ========================================
// Find an account by account number
// ========================================
int findAccount(const vector<BankAccount>& accounts,
                const string& accountNumber) {

    for (int i = 0; i < accounts.size(); i++) {

        if (accounts[i].getAccountNumber() == accountNumber) {
            return i;
        }
    }

    return -1;
}


// ========================================
// Main
// ========================================
int main() {

    vector<BankAccount> accounts;

    int choice;

    do {

        cout << "\n========================================\n";
        cout << "      Bank Account Management System\n";
        cout << "        Operator Overload Lab\n";
        cout << "========================================\n";

        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Deposit Money (+ = Operator)\n";
        cout << "4. Withdraw Money (- = Operator)\n";
        cout << "5. Compare Two Accounts\n";
        cout << "6. Copy an Account\n";
        cout << "7. Change Account Holder Name\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        // Validate menu input
        if (cin.fail()) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please enter a number.\n";

            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        // ========================================
        // CREATE ACCOUNT
        // ========================================
        switch (choice) {

            case 1: {

                BankAccount newAccount =
                    BankAccount::createAccountFromInput();

                // Check for duplicate account number
                if (findAccount(accounts,
                                newAccount.getAccountNumber()) != -1) {

                    cout << "An account with that number already exists.\n";
                    break;
                }

                accounts.push_back(newAccount);

                cout << "\nAccount created successfully!\n";

                break;
            }


            // ========================================
            // DISPLAY ALL ACCOUNTS
            // ========================================
            case 2: {

                if (accounts.empty()) {

                    cout << "\nNo accounts have been created.\n";

                    break;
                }

                cout << "\n========== All Accounts ==========\n";

                for (const BankAccount& account : accounts) {

                    BankAccount::printAccount(account);

                    cout << "---------------------------------\n";
                }

                break;
            }


            // ========================================
            // DEPOSIT USING +=
            // ========================================
            case 3: {

                string accountNumber;
                double amount;

                cout << "\nEnter account number: ";
                getline(cin, accountNumber);

                int index =
                    findAccount(accounts, accountNumber);

                if (index == -1) {

                    cout << "Account not found.\n";

                    break;
                }

                cout << "Enter deposit amount: ";
                cin >> amount;

                if (cin.fail() || amount <= 0) {

                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(),
                        '\n'
                    );

                    cout << "Invalid deposit amount.\n";

                    break;
                }

                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n'
                );

                // Use overloaded += operator
                accounts[index] += amount;

                cout << "\nDeposit successful!\n";

                cout << "New balance: $"
                     << accounts[index].getBalance()
                     << endl;

                break;
            }


            // ========================================
            // WITHDRAW USING -=
            // ========================================
            case 4: {

                string accountNumber;
                double amount;

                cout << "\nEnter account number: ";
                getline(cin, accountNumber);

                int index =
                    findAccount(accounts, accountNumber);

                if (index == -1) {

                    cout << "Account not found.\n";

                    break;
                }

                cout << "Enter withdrawal amount: ";
                cin >> amount;

                if (cin.fail() || amount <= 0) {

                    cin.clear();
                    cin.ignore(
                        numeric_limits<streamsize>::max(),
                        '\n'
                    );

                    cout << "Invalid withdrawal amount.\n";

                    break;
                }

                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n'
                );

                // Check sufficient funds before using -=
                if (amount > accounts[index].getBalance()) {

                    cout << "Withdrawal failed. "
                         << "Insufficient funds.\n";

                    break;
                }

                // Use overloaded -= operator
                accounts[index] -= amount;

                cout << "\nWithdrawal successful!\n";

                cout << "New balance: $"
                     << accounts[index].getBalance()
                     << endl;

                break;
            }


            // ========================================
            // COMPARE TWO ACCOUNTS
            // ========================================
            case 5: {

                if (accounts.size() < 2) {

                    cout << "\nYou need at least two accounts "
                         << "to compare them.\n";

                    break;
                }

                string firstNumber;
                string secondNumber;

                cout << "\nEnter first account number: ";
                getline(cin, firstNumber);

                cout << "Enter second account number: ";
                getline(cin, secondNumber);

                int firstIndex =
                    findAccount(accounts, firstNumber);

                int secondIndex =
                    findAccount(accounts, secondNumber);

                if (firstIndex == -1 ||
                    secondIndex == -1) {

                    cout << "One or both accounts were not found.\n";

                    break;
                }

                BankAccount& first =
                    accounts[firstIndex];

                BankAccount& second =
                    accounts[secondIndex];


                // Demonstrate ==
                if (first == second) {

                    cout << "\nThe two accounts have "
                         << "the same account number.\n";

                } else {

                    cout << "\nThe two accounts have "
                         << "different account numbers.\n";
                }


                // Demonstrate <
                if (first < second) {

                    cout << "The first account has "
                         << "a smaller balance.\n";

                } else if (first > second) {

                    cout << "The first account has "
                         << "a larger balance.\n";

                } else {

                    cout << "The two accounts have "
                         << "the same balance.\n";
                }

                break;
            }


            // ========================================
            // COPY ACCOUNT
            // ========================================
            case 6: {

                if (accounts.empty()) {

                    cout << "\nThere are no accounts to copy.\n";

                    break;
                }

                string accountNumber;

                cout << "\nEnter account number to copy: ";
                getline(cin, accountNumber);

                int index =
                    findAccount(accounts, accountNumber);

                if (index == -1) {

                    cout << "Account not found.\n";

                    break;
                }

                // Demonstrate copy constructor
                BankAccount copiedAccount(accounts[index]);

                cout << "\nAccount successfully copied!\n";

                cout << "\nOriginal Account:\n";
                BankAccount::printAccount(accounts[index]);

                cout << "\nCopied Account:\n";
                BankAccount::printAccount(copiedAccount);

                cout << "\nThe copy has its own dynamically "
                     << "allocated balance.\n";

                break;
            }


            // ========================================
            // CHANGE NAME
            // ========================================
            case 7: {

                string accountNumber;
                string newName;

                cout << "\nEnter account number: ";
                getline(cin, accountNumber);

                int index =
                    findAccount(accounts, accountNumber);

                if (index == -1) {

                    cout << "Account not found.\n";

                    break;
                }

                cout << "Enter new account holder name: ";
                getline(cin, newName);

                accounts[index].setAccountHolderName(newName);

                cout << "Account holder name updated successfully!\n";

                break;
            }


            // ========================================
            // EXIT
            // ========================================
            case 8:

                cout << "\nThank you for using the "
                     << "Bank Account Management System.\n";

                break;


            // ========================================
            // INVALID OPTION
            // ========================================
            default:

                cout << "Invalid choice. "
                     << "Please select 1-8.\n";
        }

    } while (choice != 8);


    return 0;
}
