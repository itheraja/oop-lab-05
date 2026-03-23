#include <iostream>
using namespace std;

// Branch Class
class Branch {
public:
    string branchName;
    string city;

    Branch() {}
    Branch(string name, string c) {
        branchName = name;
        city = c;
    }

    void display() const {
        cout << "Branch: " << branchName << ", City: " << city << endl;
    }
};

// Account Class
class Account {
private:
    string accountHolder;
    double balance;
    Branch branch; // Aggregation: Account "has-a" Branch

public:
    static string bankName;
    static float interestRate;

    // Constructor
    Account(string holder, double bal, Branch b) {
        accountHolder = holder;
        balance = bal;
        branch = b;
    }

    // Const function to show balance
    void showBalance() const {
        cout << accountHolder << "'s Balance: $" << balance << endl;
    }

    // Static function to update interest rate
    static void updateInterestRate(float newRate) {
        interestRate = newRate;
        cout << "Interest rate updated to " << interestRate << "% for all accounts." << endl;
    }

    // Display full account info
    void display() const {
        cout << "\nAccount Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
        branch.display();
        cout << "Bank: " << bankName << ", Interest Rate: " << interestRate << "%" << endl;
        cout << "-----------------------------\n";
    }
};

// Initialize static members
string Account::bankName = "Global Bank";
float Account::interestRate = 5.0;

int main() {
    cout << "Bank Accounts and Branches Demo\n\n";

    // Create Branches
    Branch b1("Main Branch", "Karachi");
    Branch b2("City Branch", "Lahore");
    Branch b3("Central Branch", "Islamabad");

    // Create array of Account objects
    Account accounts[3] = {
        Account("Ali", 1000, b1),
        Account("Sara", 2000, b2),
        Account("Hamza", 1500, b3)
    };

    // Display all accounts
    for (int i = 0; i < 3; i++) {
        accounts[i].display();
    }

    // Show balances using const function
    cout << "\nShowing balances using const function:\n";
    for (int i = 0; i < 3; i++) {
        accounts[i].showBalance();
    }

    // Update interest rate for all accounts
    cout << "\nUpdating interest rate to 6.5%...\n";
    Account::updateInterestRate(6.5);

    // Display again after interest update
    for (int i = 0; i < 3; i++) {
        accounts[i].display();
    }

    return 0;
}
