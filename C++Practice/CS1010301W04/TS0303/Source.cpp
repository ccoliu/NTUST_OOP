//Name:¼B®a¦¨
//Date: 2022/3/16
//Last Update: 2022/3/17
//Problem statement: Input Output

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s)) //read line by line
	{
		string X;
		int M = 0, N = 0;
		char C;
		string c = "";
		string ans = "";
		stringstream ss(s);
		ss >> X >> M >> N >> C;
		C = s[s.length() - 1];
		int totalLen = X.length();
		int normLen = 0;
		for (int k = 0; k < X.length(); k++)
		{
			normLen++;
			if (X[k] == '.')
			{
				break;
			}
			ans += X[k];
		}
		int vantissaLen = totalLen - normLen; //get the length of vantissa
		if (N > 0)
		{
			ans += '.';
			if (vantissaLen >= N)
			{
				for (int j = 0; j < N; j++)
				{
					ans += X[j + normLen];
				}
			}
			else
			{
				for (int l = 0; l < vantissaLen; l++)
				{
					ans += X[l + normLen];
				}
				for (int j = 0; j < N - vantissaLen; j++)
				{
					ans += '0';
				}
			}
		}
		int ansLen = ans.length(); //if the length of result does not meet requirement, add char before the result.
		for (int p = 0; p < M - ansLen; p++)
		{
			ans = C + ans;
		}
		cout << ans << endl;
	}
}