//Name:¼B®a¦¨
//Date: 2023/3/28
//Last Update: 2023/3/28
//Problem statement: Bank Account Demonstration

#include <iostream>
#include "BankAccount.h"

using namespace std;

int main() {
	BankAccount bankAccount1(200), bankAccount2, bankAccount3(-100);
	cout << BankAccount::getAllMoneyInBank() << endl;
	bankAccount1.withdraw(100);
	cout << bankAccount1.getBalance() << endl;
	cout << BankAccount::getAllMoneyInBank() << endl;
	bankAccount2.save(50);
	cout << bankAccount2.getBalance() << endl;
	cout << BankAccount::getAllMoneyInBank() << endl;
}
