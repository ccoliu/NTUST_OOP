//Name:¼B®a¦¨
//Date: 2022/3/8
//Last Update: 2022/3/8
//Problem statement: string processing.

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "";
	while (cin >> s)
	{
		int len = s.length(); //get the length of the string first.
		int n = 0;
		while (n * n < len)
		{
			n++;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i + j * n < len)
				{
					cout << s[i + j * n]; //find laws and output the string vertically.
				}
			}
			cout << endl;
		}
	}
}
