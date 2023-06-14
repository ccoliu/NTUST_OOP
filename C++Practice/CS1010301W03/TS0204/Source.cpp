//Name:¼B®a¦¨
//Date: 2022/3/9
//Last Update: 2022/3/9
//Problem statement:Print Standard Format.

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	while (cin >> T)
	{
		vector<string> names;
		vector<string> salary;
		vector<string> award;
		string name;
		string s;
		string a;
		int maxLen = 0;
		int maxS = 0;
		int maxA = 0;
		for (int i = 0; i < T; i++)
		{
			cin >> name >> s >> a;
			int len = name.length();
			int sLen = s.length();
			int aLen = a.length();
			maxLen = max(maxLen, len); //record the max length of name,salary and award at the same time.
			maxS = max(maxS, sLen);
			maxA = max(maxA, aLen);
			names.push_back(name);
			salary.push_back(s);
			award.push_back(a);
		}
		for (int j = 0; j < T; j++) 
		{
			for (int k = 0; k < maxLen - names[j].length(); k++) 
			{
				cout << " ";
			}
			cout << names[j] << "|";
			for (int l = 0; l < maxS - salary[j].length() + 2; l++) //output the enough space before the data needed to be sent.
			{
				cout << " ";
			}
			cout << salary[j] << "|";
			for (int m = 0; m < maxA - award[j].length() + 2; m++)
			{
				cout << " ";
			}
			cout << award[j] << endl;
		}
	}
}