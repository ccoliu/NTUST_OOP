//Name:¼B®a¦¨
//Date: 2022/3/23
//Last Update: 2022/3/23
//Problem statement: Basic number operator

#include <iostream>
using namespace std;

int cycle(int num, int times)
{
	if (num == 1) // If num is 1, the cycle is complete, so return the number of iterations
	{
		return times;
	}
	else if (num % 2 == 0) // If num is even, divide it by 2 and continue the cycle
	{
		return cycle(num / 2, times + 1);
	}
	else // If num is odd, multiply it by 3 and add 1, and continue the cycle
	{
		return cycle(num * 3 + 1, times + 1);
	}
}

int main()
{
	int i, j;
	while (cin >> i >> j) // Keep reading pairs of integers i and j until there is no more input
	{
		int maxcycle = 0; // Initialize the maximum cycle length to 0
		if (i <= j) // If i is less than or equal to j, iterate from i to j
		{
			for (int a = i; a <= j; a++)
			{
				maxcycle = max(maxcycle, cycle(a, 1)); // Find the cycle length of a, and update the maximum if it is greater than the current maximum
			}
		}
		else // If i is greater than j, iterate from i to j backwards
		{
			for (int a = i; a >= j; a--)
			{
				maxcycle = max(maxcycle, cycle(a, 1)); // Find the cycle length of a, and update the maximum if it is greater than the current maximum
			}
		}
		cout << i << " " << j << " " << maxcycle << endl; // Print the original values of i and j, and the maximum cycle length
	}
}