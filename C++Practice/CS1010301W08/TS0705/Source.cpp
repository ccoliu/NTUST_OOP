#include <iostream>
#include <string>
using namespace std;
string s = "VUCD";
string tab[4][4] = {
	{"V","U","C","D"},
	{"U","C","D","VU"},
	{"C","D","VU","UU"},
	{"D","VU","UU","CU"}
};


int main()
{
	int T;
	cin >> T;
	cout << "COWCULATIONS OUTPUT" << endl;
	for (int i = 0; i < T; i++)
	{
		string a, b;
		cin >> a >> b;
		string result = "";
		for (int i = 0; i < 3; i++)
		{
			char op;
			cin >> op;

			if (op == 'A')
			{
				string carry = "";
				for (int i = b.length() - 1, j = a.length() - 1; i >= 0 && j >= 0; i--, j--)
				{
					string temp = tab[s.find(b[i])][s.find(a[j])];
					if (carry != "")
					{
						for(int i=0;i<carry.length();i++)
						{
							char temp1 = temp[0];
							temp.erase(0, 1);
							temp = tab[s.find(temp1)][s.find(carry[i])] + temp;
						}
						b[i] = temp[0];
						temp.erase(0,1);
						carry = temp;
					}
					else
					{
						b[i] = temp[0];
						temp.erase(0,1);
						carry = temp;
					}
				}
				if (carry != "")
				{
					b = carry + b;
				}
			}
			if (op == 'R')
			{
				b.erase(b.end() - 1);
				b = 'V' + b;
			}
			if (op == 'L')
			{
				b += 'V';
			}
			if (op == 'N')
			{
				continue;
			}
		}
		string hypo;
		cin >> hypo;
		while (b.length() < 8)
		{
			b = 'V' + b;
		}
		if (hypo == b)
		{
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	cout << "END OF OUTPUT" << endl;
}