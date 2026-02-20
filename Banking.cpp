#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
public:
    string name;
    double balance;
    vector<string> transactions;

    Account(string n, double b) {
        name = n;
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back("Deposited: " + to_string(amount));
    }

    void withdraw(double amount) {
        if(amount <= balance) {
            balance -= amount;
            transactions.push_back("Withdrawn: " + to_string(amount));
        } else {
            cout << "Insufficient Balance\n";
        }
    }

    void showDetails() {
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transactions:\n";
        for(string t : transactions)
            cout << t << endl;
    }
};

int main() {
    string name;
    double initial;
    cout << "Enter Customer Name: ";
    cin >> name;
    cout << "Enter Initial Balance: ";
    cin >> initial;

    Account acc(name, initial);

    int choice;
    do {
        cout << "1. Deposit\n2. Withdraw\n3. Show Details\n4. Exit\nChoice: ";
        cin >> choice;

        double amount;
        if(choice == 1) {
            cout << "Enter Amount: ";
            cin >> amount;
            acc.deposit(amount);
        }
        else if(choice == 2) {
            cout << "Enter Amount: ";
            cin >> amount;
            acc.withdraw(amount);
        }
        else if(choice == 3) {
            acc.showDetails();
        }

    } while(choice != 4);

    return 0;
}