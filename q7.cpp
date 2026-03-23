#include <iostream>
using namespace std;

class Account {
private:
    string accountHolder;
    double balance;

public:
    static string bankName;
    static float interestRate;

    // Constructor
    Account(string name, double bal) {
        accountHolder = name;
        balance = bal;
    }

    // Const function to show balance
    void showBalance() const {
        cout << accountHolder << "'s Balance: $" << balance << endl;
    }

    // Deposit function
    void deposit(double amount) {
        balance += amount;
        cout << accountHolder << " deposited $" << amount 
             << ". New Balance: $" << balance << endl;
    }

    // Function to show bank details (static members)
    static void showBankDetails() {
        cout << "Bank: " << bankName << ", Interest Rate: " << interestRate << "%" << endl;
    }
};

// Initialize static members
string Account::bankName = "Global Bank";
float Account::interestRate = 5.0;

int main() {
    cout << "Bank Accounts Demo\n\n";

    // Create 3 accounts
    Account acc1("Ali", 1000);
    Account acc2("Sara", 1500);
    Account acc3("Hamza", 2000);

    // Show initial balances
    acc1.showBalance();
    acc2.showBalance();
    acc3.showBalance();
    cout << endl;

    // Deposit money
    acc1.deposit(500);
    acc2.deposit(300);
    acc3.deposit(700);
    cout << endl;

    // Show updated balances using const function
    acc1.showBalance();
    acc2.showBalance();
    acc3.showBalance();
    cout << endl;

    // Show static bank details
    Account::showBankDetails();
    cout << "\nUpdating interest rate...\n";
    Account::interestRate = 6.5; // change static value

    // Show updated bank details
    Account::showBankDetails();

    return 0;
}
