//Name:¼B®a¦¨
//Date: 2022/3/9
//Last Update: 2022/3/9
//Problem statement:Calculate big integer.

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct BigInt //created class BigInt
{
	string bigNum = "";
};

BigInt add(BigInt& lhs,BigInt& rhs)
{
	BigInt ans;
	ans.bigNum = "";
	vector<int> box;
	int leftLen = lhs.bigNum.length();
	int rightLen = rhs.bigNum.length();
	int maxLen = (leftLen >= rightLen) ? leftLen : rightLen;;
	int n = 0;
	int v = 0;
	reverse(lhs.bigNum.begin(), lhs.bigNum.end());
	reverse(rhs.bigNum.begin(), rhs.bigNum.end());
	for (int i = 0; i < maxLen; i++)
	{
		if (i >= rightLen) 
		{
			if (lhs.bigNum[i] >= 65 || lhs.bigNum[i] < 48) 
			{
				ans.bigNum = "Not a valid number, please try again."; //if the bigNum is not number, return error messages.
				return ans;
			}
			v = lhs.bigNum[i] - '0';
			v = v + n;
			n = v / 10;
			v = v % 10;
			box.push_back(v);
		}
		else if (i >= leftLen)
		{
			if (rhs.bigNum[i] >= 65 || rhs.bigNum[i] < 48) 
			{
				ans.bigNum = "Not a valid number, please try again."; //if the bigNum is not number, return error messages.
				return ans;
			}
			v = rhs.bigNum[i] - '0';
			v = v + n;
			n = v / 10;
			v = v % 10;
			box.push_back(v);
		}
		else
		{
			if (lhs.bigNum[i] >= 65 || rhs.bigNum[i] >= 65 || lhs.bigNum[i] < 48 || rhs.bigNum[i] < 48) 
			{
				ans.bigNum = "Not a valid number, please try again."; //if the bigNum is not number, return error messages.
				return ans;
			}
			else
			{
				v = ((lhs.bigNum[i] - '0') + (rhs.bigNum[i] - '0'));
				v = v + n;
				n = v / 10;
				v = v % 10;
				box.push_back(v);
			}
		}
	}
	if (n != 0) 
	{
		box.push_back(n);
	}
	for (int j = 0; j < box.size(); j++)
	{
		char c = box[j] + '0';
		if (j == 0)
		{
			ans.bigNum = c;
		}
		else
		{
			ans.bigNum = c + ans.bigNum;
		}
	}
	return ans;
}


int main()
{
	int T;
	while (cin >> T)
	{
		for (int i = 0; i < T; i++)
		{
			BigInt a, b;
			cin >> a.bigNum >> b.bigNum;
			BigInt result;
			result = add(a, b);
			cout << result.bigNum << endl;
		}
	}
}
