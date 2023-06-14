//Name:¼B®a¦¨
//Date: 2023/3/28
//Last Update: 2023/3/28
//Problem statement: Bank Account Demonstration

// This is a class called BankAccount used to store account information.
class BankAccount {
private:
	int balance; // Record the balance of the account.
	static int total; // Record the total amount of money the bank holds.

public:
	// Default constructor that sets the balance to 0.
	BankAccount() {
		balance = 0;
	}

    // Constructor that sets the balance to the input amount and adds it to the bank's total.
    BankAccount(int input) {
        balance = input;
        total += input;
    }

    // Withdraws the specified amount from the account and subtracts it from the bank's total.
    void withdraw(int output) {
        balance -= output;
        total -= output;
    }

    // Deposits the specified amount into the account and adds it to the bank's total.
    void save(int input) {
        balance += input;
        total += input;
    }

    // Returns the balance of the account.
    int getBalance() {
        return balance;
    }

    // Returns the total amount of money the bank holds.
    static int getAllMoneyInBank() {
        return total;
    }

};

int BankAccount::total = 0; // Initialize the static member variable 'total' to 0.