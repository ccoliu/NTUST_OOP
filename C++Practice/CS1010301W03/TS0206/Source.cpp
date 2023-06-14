//Name:¼B®a¦¨
//Date: 2022/3/9
//Last Update: 2022/3/9
//Problem statement:Calculate tax.

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	double income;
	while (cin >> income) //flow control through incomes.
	{
		if (income < 750) 
		{
			cout << fixed << setprecision(2) << income * 0.01 << endl; //output the tax with corresponding income.
		}
		else if (income < 2250)
		{
			cout << fixed << setprecision(2) << 7.5 + (income - 750) * 0.02 << endl;
		}
		else if (income < 3750)
		{
			cout << fixed << setprecision(2) << 37.5 + (income - 2250) * 0.03 << endl;
		}
		else if (income < 5250)
		{
			cout << fixed << setprecision(2) << 82.5 + (income - 3750) * 0.04 << endl;
		}
		else if (income < 7000)
		{
			cout << fixed << setprecision(2) << 142.5 + (income - 5250) * 0.05 << endl;
		}
		else
		{
			cout << fixed << setprecision(2) << 230 + (income - 7000) * 0.06 << endl;
		}
	}
}