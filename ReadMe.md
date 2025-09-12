# Bank Account Management System

A C++ class for representing banking functions in a simple bank management system.

## Data Dictionary

| Attribute       | Data Type      | Description                        |
|-----------------|----------------|------------------------------------|
| `accountNumber` | `std::string`  | Unique account identifier.         |
| `holderName`    | `std::string`  | Name of the account holder.        |
| `balance`       | `double`       | Current balance of the account.    |

## Method List

| Method Signature                        | Return Type   | Description                                                                  | 
|-----------------------------------------|---------------|------------------------------------------------------------------------------|
|`BankAccount()`                          | (Constructor) | Default constructor.                                                         |
|`BankAccount(accNum, holder, bal)`       | (Constructor) | Parameterized constructor.                                                   |
|`GetAccountNumber() const`               | `std::string` | Gets the account's number.                                                   |
|`GetHolderName() const`                  | `std::string` | Gets the account holder's name.                                              |
|`GetBalance() const`                     | `double`      | Gets the current balance on the account.                                     |
|`Display() const`                        | `void`        | Prints all account information.                                              |
|`SetAccountHolderName(std::string name)` | `void`        | Sets the account holder's name.                                              |
|`Deposit(double amount)`                 | `void`        | Adds inputted amount to the balance. Prints confirmation message.            |
|`Withdraw(double amount)`                | `void`        | Subtracts inputted amount from balance. Prints a success or failure message. |













