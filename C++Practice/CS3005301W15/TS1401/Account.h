//Name: ¼B®a¦¨
//Date: 2023/05/31
//Last Update: 2023/05/31
//Problem statement: Create a class Account with two exceptions

#pragma once
#include <iostream>

class NegativeDeposit //NegativeDeposit exception class
{
public:
	NegativeDeposit() {}; //constructor
};

class InsufficientFunds //InsufficientFunds exception class
{
public:
	InsufficientFunds() {}; //constructor
};

class Account
{
private:
	double balance; //balance data member
public:
	Account() { balance = 0; } //default constructor
	Account(double initialDeposit) { balance = initialDeposit; } //constructor with initial deposit
	double getBalance() { return balance; } //return balance

	//returns new balance or -1 if error 
	double deposit(double amount)
	{
		if (amount > 0) balance += amount; //if amount is greater than 0, add amount to balance
		else
		{
			throw NegativeDeposit(); //else throw NegativeDeposit exception
			return -1; //return -1
		}
		return balance; //return balance
	}

	//return new balance or -1 if invalid amount 
	double withdraw(double amount)
	{
		if (amount > balance || amount < 0)
		{
			throw InsufficientFunds(); //if amount is greater than balance or amount is less than 0, throw InsufficientFunds exception
			return -1; //return -1
		}
		balance -= amount; //else subtract amount from balance
		return balance; //return balance
	}
};
