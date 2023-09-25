//Author: ¼B®a¦¨
//Date: 2023/4/26
//Last Modified: 2023/4/26
//Problem statement: This C++ header file defines a class Complex and its member functions and friend functions.

#include "PrimeNumber.h"

PrimeNumber::PrimeNumber() //default constructor with no arguments
{ 
	value = 1; //set value to 1
}

PrimeNumber::PrimeNumber(int _value)  //constructor with one argument int _value
{
	value = _value; //set value to _value
}

int PrimeNumber::get()  //member function get
{
	return value; //return value
}

PrimeNumber& PrimeNumber::operator++() //operator overloading ++ (prefix)
{
	int i = ++value; //increase value by 1
	while (true) { //loop until find a prime number
		bool isPrime = true; //set isPrime to true
		for (int j = 2; j < i; j++) { //loop from 2 to i-1
			if (i % j == 0) { //if i is divisible by j
				isPrime = false; //set isPrime to false
				break; //break the loop
			}
		}
		if (isPrime) { //if isPrime is true
			value = i; //set value to i
			return *this; //return this object
		}
		i++; //increase i by 1
	}
}

PrimeNumber PrimeNumber::operator++(int) //operator overloading ++ (postfix)
{ 
	PrimeNumber temp = *this; //create a new object temp
	++*this; //increase value by 1
	return temp; //return temp
}

PrimeNumber& PrimeNumber::operator--() //operator overloading -- (prefix)
{
	int i = --value; //decrease value by 1
	if (value == 2) { //if value is 2
		value = i; //set value to i
		return *this; //return this object
	}
	while (true) { //loop until find a prime number
		bool isPrime = true; //set isPrime to true
		for (int j = 2; j < i; j++) { //loop from 2 to i-1
			if (i % j == 0) { //if i is divisible by j
				isPrime = false; //set isPrime to false
				break; //break the loop
			}
		}
		if (isPrime) { //if isPrime is true
			value = i; //set value to i
			return *this; //return this object
		}
		i--; //decrease i by 1
	}
}

PrimeNumber PrimeNumber::operator--(int) { //operator overloading -- (postfix)
	PrimeNumber temp = *this; //create a new object temp;
	--*this; //decrease value by 1
	return temp; //return temp
}