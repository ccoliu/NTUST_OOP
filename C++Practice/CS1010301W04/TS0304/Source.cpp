//Name:¼B®a¦¨
//Date: 2022/3/16
//Last Update: 2022/3/17
//Problem statement: CPU Bit Growth

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int year;
	const int START = 4;
	while (cin >> year)
	{
		double grow = pow(2, (year - 1900) / 10);
		double now = grow * START; //current value is the growth multiplies the bits from the start
		long long index = 1;
		for (double i = 0; i < now; index++)
		{
			i += log2(index); //as the variable i adds the log of index, it will be more close to the bit now.
		}
		cout << index - 2 << endl; //finally, minus 2 for the value of start
	}
}