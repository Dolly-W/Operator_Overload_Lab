#include <iostream>
#include <vector>
#include <string>
#include <limits>

class BankAccount {
public:
    //Default Constructor
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
    //Mutators(setter)
    void SetAccountHolderName(std::string name);
    void Deposit(double amount);
    void Withdraw(double amount);

    //Accessor(getters)
    std::string GetAccountNumber() const;
    std::string GetHolderName() const;
    double GetBalance() const;
    void Display() const;

private:
    //Variables
    std::string accountNumber;
    std::string holderName;
    double balance;
};
//Accessors
std::string BankAccount::GetAccountNumber() const {
    return accountNumber;
}
std::string BankAccount::GetHolderName() const {
    return holderName;
}
double BankAccount::GetBalance() const {
    return balance;
}
//Display all Account Details
void BankAccount::Display() const {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Holder Name: " << holderName << std::endl;
    std::cout << "Balance: " << balance << std::endl;
}
//Mutators
void BankAccount::SetAccountHolderName(std::string name) {
    holderName = name;
}

void BankAccount::Deposit(double amount) {
        balance = balance + amount;
        std::cout << "Deposit Was Successful. \nUpdated Balance: $" << balance << std::endl;
}

void BankAccount::Withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance = balance - amount;
        std::cout << "Withdrawal Was Successful. \nUpdated Balance: $" << balance << std::endl;
    }
    else {
        std::cout << "Withdrawal Failed. Insufficient Funds" << std::endl;
    }
}
//Function for input Validation
void invalidInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


int main () {
    std::vector<BankAccount> accounts;
    int choice;

    do {
        //Menu Options
        std::cout << "~~Welcome to the Bank Management System~~" << std::endl;
        std::cout << "1) Create an Account" << std::endl;
        std::cout << "2) Deposit Money" << std::endl;
        std::cout << "3) Withdrawal Money" << std::endl;
        std::cout << "4) Display all Accounts" << std::endl;
        std::cout << "5) Exit" << std::endl;

        while (true) {
            std::cout << "Enter Choice: ";
            std::cin >> choice;
            //Input Validation if user inputs letters
            if (std::cin.fail()) {
                invalidInput();
                std::cout << "Invalid Input, Please Enter A Number" << std::endl;
            }
            //Input Validation if input number less than 1
            else if (choice < 1 || choice > 5) {
                invalidInput();
                std::cout << "Invalid Input, Please Enter A Number Between 1-5" << std::endl;
            }
            else {
                //clear input
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }

        switch (choice) {
            case 1: {
                std::string accNum;
                std::string holder;
                double bal;

                std::cout << "Enter Account Number: " << std::endl;
                getline(std::cin, accNum);

                std::cout << "Enter Account Holder Name: " << std::endl;
                getline(std::cin, holder);

                while (true) {
                    std::cout << "Enter Initial Balance: " << std::endl;
                    std::cin >> bal;
                    //Input Validation if user inputs letters
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    //Input Validation if user inputs number less than 1
                    else if (bal <= 0) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number Greater Than 0" << std::endl;
                    }
                    else {
                        //clear input
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }
                accounts.push_back(BankAccount(accNum, holder, bal));
                break;
            }
            case 2: {
                //If no accounts exist
                if (accounts.empty()) {
                    std::cout << "No Accounts Exist Yet, Please Create One" << std::endl;
                    break;
                }
                int accountChoice;
                while (true) {
                    std::cout << "Select An Account: " << std::endl;
                    for (int i = 0; i < accounts.size(); i++) {
                        std::cout << i + 1 << ") " << accounts[i].GetAccountNumber() << " - " << accounts[i].GetHolderName() << std::endl;
                    }
                    std::cout << "Enter Choice: " << std::endl;
                    std::cin >> accountChoice;
                    //Input validation if user inputs letters
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    //Input Validation if user inputs number less than 1
                    else if (accountChoice < 1) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number Greater Than 0" << std::endl;
                    }
                    //Input validation if user inputs number outside of scope
                    else if (accountChoice > accounts.size()) {
                        invalidInput();
                        std::cout << "Invalid Input, Account Doesn't Exist" << std::endl;
                    }
                    else {
                        //clear input
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }
                double amount;
                while (true) {
                    std::cout << "Enter Deposit Amount: " << std::endl;
                    std::cin >> amount;
                    //input validation if user inputs letters
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    //input validation if user inputs number less than 1
                    else if (amount <= 0) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter An Amount Greater Than 0" << std::endl;
                    }
                    else {
                        //clear input
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }
                //Adds deposit amount into selected account
                accounts[accountChoice - 1].Deposit(amount);
                break;
            }
            case 3: {
                //Input validation if no accounts have been created
                if (accounts.empty()) {
                    std::cout << "No Accounts Exist Yet, Please Create One" << std::endl;
                    break;
                }
                int accountChoice;
                while (true) {
                    std::cout << "Select An Account: " << std::endl;
                    for (int i = 0; i < accounts.size(); i++) {
                        std::cout << i + 1 << ") " << accounts[i].GetAccountNumber() << " - " << accounts[i].GetHolderName() << std::endl;
                    }
                    std::cout << "Enter Choice: " << std::endl;
                    std::cin >> accountChoice;
                    //Inputs validation if user inputs letters
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    //Input validation if user inputs number less than 1
                    else if (accountChoice < 1) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number Greater Than 0" << std::endl;
                    }
                    //Input Validation if user inputs number outside of scope
                    else if (accountChoice > accounts.size()) {
                        invalidInput();
                        std::cout << "Invalid Input, Account Doesn't Exist" << std::endl;
                    }
                    else {
                        //clear input
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }
                double amount;
                while (true) {
                    std::cout << "Enter Withdrawal Amount: " << std::endl;
                    std::cin >> amount;
                    //input validation if user inputs letters
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    //input validation if user inputs number less than 1
                    else if (amount < 1) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter An Amount Greater than 0" << std::endl;
                    }
                    else {
                        //clear input
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        break;
                    }
                }
                //removes withdrawal amount from selected account
                accounts[accountChoice - 1].Withdraw(amount);
                break;
            }
            case 4: {
                //Input validation if no account has been created
                if (accounts.empty()) {
                    std::cout << "No Accounts Exist Yet, Please Create One" << std::endl;
                    break;
                }
                //display all accounts
                for (int i = 0; i < accounts.size(); i++) {
                    std::cout << "Account " << i + 1 << ":" << std::endl;
                    accounts[i].Display();
                }
                break;
            }
            case 5:
                std::cout << "Exiting Program..." << std::endl;
                break;
            default:
                std::cout << "Invalid Input, Please Try Again" << std::endl;
        }
    }
    while (choice != 5);
    return 0;
}