#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
};

class Account {
public:
    int accountNumber;
    double balance;
    vector<Transaction> history;

    Account(int accNo, double bal = 0) {
        accountNumber = accNo;
        balance = bal;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount));
            cout << "Amount Withdrawn Successfully!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void transfer(Account &receiver, double amount) {
        if (amount <= balance) {
            balance -= amount;
            receiver.balance += amount;

            history.push_back(Transaction("Transfer Sent", amount));
            receiver.history.push_back(Transaction("Transfer Received", amount));

            cout << "Transfer Successful!\n";
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    void displayTransactions() {
        cout << "\nTransaction History\n";
        for (auto t : history) {
            cout << t.type << " : Rs. " << t.amount << endl;
        }
    }

    void displayAccount() {
        cout << "\nAccount Number : " << accountNumber << endl;
        cout << "Balance : Rs. " << balance << endl;
    }
};

class Customer {
public:
    int customerID;
    string name;
    Account account;

    Customer(int id, string n, int accNo, double bal)
        : account(accNo, bal) {
        customerID = id;
        name = n;
    }

    void displayCustomer() {
        cout << "\nCustomer ID : " << customerID << endl;
        cout << "Customer Name : " << name << endl;
        account.displayAccount();
    }
};

int main() {

    Customer c1(101, "Suraj", 1001, 5000);
    Customer c2(102, "Rahul", 1002, 3000);

    int choice;
    double amount;

    do {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. View Account Details\n";
        cout << "5. View Transaction History\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            c1.account.deposit(amount);
            break;

        case 2:
            cout << "Enter Withdraw Amount: ";
            cin >> amount;
            c1.account.withdraw(amount);
            break;

        case 3:
            cout << "Enter Transfer Amount: ";
            cin >> amount;
            c1.account.transfer(c2.account, amount);
            break;

        case 4:
            c1.displayCustomer();
            break;

        case 5:
            c1.account.displayTransactions();
            break;

        case 6:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}