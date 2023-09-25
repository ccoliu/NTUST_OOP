//Name:¼B®a¦¨
//Date: 2022/3/15
//Last Update: 2022/3/15
//Problem statement: Occurrenc Counting

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	int N[100];
	int count[100];
	int rec = 0;
	bool find = false;
	int add = 0;
	for (int i = 0; i < 100; i++)
	{
		N[i] = INT_MAX;
		count[i] = 0;
	}
	while (cin >> t)
	{
		for (int j = 0; j < rec; j++)
		{
			if (N[j] == t) //to find if the requested N is in the array
			{
				find = true;
				add = j;
			}
		}
		if (!find) //if we didn't find the requested N, we put it into our array.
		{
			N[rec] = t;
			count[rec] = 1;
			rec++;
		}
		else { //if we did find it in array, add the count by 1.
			count[add]++;
			find = false;
		}
	}
	for (int k = 0; k < rec-1; k++) //sort the data in descend order.
	{
		for (int l = 0; l < rec - k - 1; l++)
		{
			if (N[l] < N[l + 1])
			{
				int temp = N[l];
				N[l] = N[l + 1];
				N[l + 1] = temp;
				int temp2 = count[l];
				count[l] = count[l + 1];
				count[l + 1] = temp2;
			}
		}
	}
	cout << "N\tcount" << endl;
	for (int m = 0; m < rec; m++)
	{
		cout << N[m] << '\t' << count[m] << endl;
	}
}