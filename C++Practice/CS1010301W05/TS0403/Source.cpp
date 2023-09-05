//Name:¼B®a¦¨
//Date: 2022/3/23
//Last Update: 2022/3/23
//Problem statement: Find greatest common division of two numbers

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) // If b is 0, then a is the GCD
	{
		return a;
	}
	return gcd(b, a % b); // Otherwise, find the GCD of b and a%b (the remainder when a is divided by b)
}

// The main function reads two integers from input until there is no more input, and
// then calls the gcd function with these two integers, and prints the result.
int main()
{
	int a, b;
	while (cin >> a >> b) // Keep reading two integers at a time from input until there is no more input
	{
		cout << gcd(a, b) << endl; // Find the GCD of a and b, and print it to output followed by a newline character
	}
	return 0; // Return 0 to indicate successful completion of program
}