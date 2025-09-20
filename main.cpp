#include <iostream>
#include <vector>
#include <string>
#include <limits>


//Function for input Validation
void invalidInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



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
    //Prompts the user for account information
    static BankAccount createAccountFromInput () {
        std::string accNum;
        std::string holder;
        double bal;

        std::cout << "Enter Account Number: " << std::endl;
        std::getline(std::cin, accNum);

        std::cout << "Enter Account Holder Name: " << std::endl;
        std::getline(std::cin, holder);

        //Input validation for initial balance
        while (true) {
            std::cout << "Enter Initial Balance: " << std::endl;
            std::cin >> bal;
            if (std::cin.fail()) {
                invalidInput();
                std::cout << "Invalid Input, Please Enter A Number" << std::endl;
            }
            else if (bal <= 0) {
                std::cout << "Invalid Input, Please Enter A Number Greater Than 0" << std::endl;
            }
            else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

        }
        //Returns a new BankAccount objected from inputed data
        return BankAccount(accNum, holder, bal);
    }


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



int main () {
    std::vector<BankAccount> accounts; //Stores all bank accounts
    int choice;

    do {
        //Menu Options
        std::cout << "~~Welcome to the Bank Management System~~" << std::endl;
        std::cout << "1) Create an Account" << std::endl;
        std::cout << "2) Deposit Money" << std::endl;
        std::cout << "3) Withdrawal Money" << std::endl;
        std::cout << "4) Display all Accounts" << std::endl;
        std::cout << "5) Compare Accounts" << std::endl;
        std::cout << "6) Exit" << std::endl;

        while (true) {
            std::cout << "Enter Choice: ";
            std::cin >> choice;
            //Input Validation if user inputs letters
            if (std::cin.fail()) {
                invalidInput();
                std::cout << "Invalid Input, Please Enter A Number" << std::endl;
            }
            //Input Validation if input number less than 1
            else if (choice < 1 || choice > 6) {
                invalidInput();
                std::cout << "Invalid Input, Please Enter A Number Between 1-6" << std::endl;
            }
            else {
                //clear input
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
        }

        switch (choice) {
            case 1: {
                accounts.push_back(BankAccount::createAccountFromInput());
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
                accounts[accountChoice - 1] += amount;
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
                accounts[accountChoice - 1] -= amount;
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
                    BankAccount::printAccount(accounts[i]);
                }
                break;
            }
            case 5: {//Compares two accounts
                if (accounts.empty()) {
                    std::cout << "No Accounts Exist Yet, Please Create One" << std::endl;
                    break;
                }
                if (accounts.size() < 2) {
                    std::cout << "Need At Least Two Accounts To Compare" << std::endl;
                    break;
                }

                int acc1;
                int acc2;

                while (true) {
                    //First account selection
                    std::cout << "Select First Account: " << std::endl;
                    for (int i = 0; i < accounts.size(); i++) {
                        std::cout << i + 1 << ") " << accounts[i].GetAccountNumber() << " - " << accounts[i].GetHolderName() << std::endl;
                    }
                    std::cin >> acc1;

                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    else if (acc1 < 1) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number Greater Than 0" << std::endl;
                    }
                    else if (acc1 > accounts.size()) {
                        invalidInput();
                        std::cout << "Invalid Input, Account Doesn't Exist" << std::endl;
                    }
                    else {
                        break;
                    }
                }
                while (true) {
                    //Second account selection
                    std::cout << "Select Second Account: " << std::endl;
                    for (int i = 0; i < accounts.size(); i++) {
                        std::cout << i + 1 << ") " << accounts[i].GetAccountNumber() << " - " << accounts[i].GetHolderName() << std::endl;
                    }
                    std::cin >> acc2;
                    if (std::cin.fail()) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number" << std::endl;
                    }
                    else if (acc2 < 1) {
                        invalidInput();
                        std::cout << "Invalid Input, Please Enter A Number Greater Than 0" << std::endl;
                    }
                    else if (acc2 > accounts.size()) {
                        invalidInput();
                        std::cout << "Invalid Input, Account Doesn't Exist" << std::endl;
                    }
                    else {
                        break;
                    }
                }
                //-Overload operators to compare accounts
                //If account numbers are the name
                if (accounts[acc1 -1] == accounts[acc2 - 1]) {
                    std:: cout << "Account " << acc1 << " and " << acc2 << " have the same account number" << std::endl;
                }
                else {
                    //If account numbers are different
                    std::cout << "Account " << acc1 << " and " << acc2 << " have different account numbers" << std::endl;
                }
                //If first selected account has lower balance than second selected account
                if (accounts[acc1 - 1] < accounts[acc2 - 1]) {
                    std::cout << "Account " << acc1 << " has a lower balance than Account " << acc2 << std::endl;
                }
                //If first selected account has greater balance than second account
                else if (accounts[acc1 - 1] > accounts[acc2 - 1]) {
                    std::cout << "Account " << acc1 << " has a higher balance than Account " << acc2 << std::endl;
                }
                else {
                    //If both selected accounts have same balance
                    std::cout << "Both accounts have the same balance" << std::endl;
                }
                break;
            }
            case 6:
                std::cout << "Exiting Program..." << std::endl;
                break;
            default:
                std::cout << "Invalid Input, Please Try Again" << std::endl;
        }
    }
    while (choice != 6);
    return 0;
}