//

#ifndef BANKMANAGEMENTSYSTEM_BANKACCOUNTSYSTEM_H
#define BANKMANAGEMENTSYSTEM_BANKACCOUNTSYSTEM_H


#include <string>
#include <iostream>


void invalidInput(); //for input validation

class BankAccount {
    public:
    BankAccount() {
        accountNumber = "0";
        holderName = "Default";
        balance = 0.0;
    }
    //parameterized Constructor
    BankAccount(std::string accNum, std::string holder, double bal) {
        accountNumber = accNum;
        holderName = holder;
        balance = bal;
    }
    // Copy Constructor
    //Ensures deep copy of all member variables
    BankAccount(const BankAccount& other) {
        accountNumber = other.accountNumber;
        holderName = other.holderName;
        balance = other.balance;
    }
    //Copy Assignment Operator
    //Assigns one BankAccount object to another
    BankAccount& operator=(const BankAccount& other) {
        accountNumber = other.accountNumber;
        holderName = other.holderName;
        balance = other.balance;
        return *this;
    }
    //Destructor
    ~BankAccount() {

    }

    //Operator overload: +=
    //Adds money to the balance (used for deposits)
    BankAccount& operator+=(double amount) {
        if (amount > 0) {
            balance = balance + amount;
            std::cout << "Deposit Was Successful. \nUpdated Balance: $" << balance << std::endl;
        }
        else {
            std::cout << "Invalid Deposit Amount" << std::endl;
        }
        return *this;
    }

    //-Operator overload: -=
    //Subtracts money from the balance (used for withdrawals)
    BankAccount& operator-=(double amount) {
        if (amount > 0 && amount <= balance) {
            balance = balance - amount;
            std::cout << "Withdrawal Was Successful. \nUpdated Balance: $" << balance << std::endl;
        }
        else {
            std::cout <<"Withdrawal Failed. Insufficient Funds" << std::endl;
        }
        return *this;
    }

    //-Comparison Operators
    //If account numbers are the same, return true. Otherwise, return false
    bool operator==(const BankAccount &other) const {
        return accountNumber == other.accountNumber;
    }
    //If first selected account is less than second selected account, return true. Otherwise, return false
    bool operator<(const BankAccount &other) const {
        return balance < other.balance;
    }
    //If first selected account is greater than second selected account, return true. Otherwise, return false
    bool operator>(const BankAccount &other) const {
        return balance > other.balance;
    }

//Static Utility Functions
    //Prints account details
    static void printAccount(const BankAccount &account) {
        std::cout << "Account Number: " << account.accountNumber << std::endl;
        std::cout << "Holder Name: " << account.holderName << std::endl;
        std::cout << "Balance: $" << account.balance << std::endl;
    }
    static BankAccount createAccountFromInput();




    //Accessor(getters)
    std::string GetAccountNumber() const;
    std::string GetHolderName() const;
    double GetBalance() const;


private:
    //Variables
    std::string accountNumber;
    std::string holderName;
    double balance;
};
#endif