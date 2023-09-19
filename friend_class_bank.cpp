#include <iostream>
#include <string>

using std::string;

using std::cout;
using std::endl;

class BankManager; // Forward declaration

class BankAccount {
    string accountHolder;
    double balance;

    public:
    BankAccount(const string& holder, double initialBalance) : accountHolder(holder), balance(initialBalance) {}

    void Print_Info(){
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balnce: $ " << balance << endl;
    }

    // Declaring BankManager class as a friend

    friend class BankManager;
};

class BankManager {
public:
    // The BankManager can change the balance of a BankAccount
    static void UpdateBalance(BankAccount& account, double newBalance) {
        account.balance = newBalance;
    }

    
};

int main() {
    BankAccount account1("John Doe", 1000.0);
    account1.Print_Info();

    BankManager::UpdateBalance(account1, 1500.0); // The BankManager updates the balance
    account1.Print_Info();

    return 0;
}