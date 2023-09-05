//Name:¼B®a¦¨
//Date: 2022/3/30
//Last Update: 2022/3/30
//Problem statement: Creating student records

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct
{
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

int search(vector<StRec> record, string first, string last, string ph)
{
	for (int i = 0; i < record.size(); i++)
	{
		if (record[i].firstName == first && record[i].lastName == last && record[i].phone == ph)
		{
			return i;
		}
	}
	return -1;
}

bool phoneCheck(string ph)
{
	for (int i = 0; i < ph.length(); i++)
	{
		if (isdigit(ph[i]) == false)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	vector<StRec> record;
	string method;
	while (cin >> method)
	{
		if (method == "\n") continue;
		if (method == "insert")
		{
			string first = "", last = "", ph = "";
			cin >> first >> last >> ph;
			if (first.length() > 25 || last.length() > 30 || ph.length() > 15 || phoneCheck(ph) == false)
			{
				cout << "Input Error" << endl;
				continue;
			}
			if (record.size() >= 10 || search(record, first, last, ph) != -1)
			{
				cout << "Insert Error" << endl;
				continue;
			}
			StRec newAdd;
			strcpy(newAdd.firstName, first.c_str());
			strcpy(newAdd.lastName, last.c_str());
			strcpy(newAdd.phone, ph.c_str());
			record.push_back(newAdd);
		}
		else if (method == "delete")
		{
			string first, last, ph;
			cin >> first >> last >> ph;
			if (first.length() > 25 || last.length() > 30 || ph.length() > 15 || phoneCheck(ph) == false)
			{
				cout << "Input Error" << endl;
				continue;
			}
			int flag = search(record, first, last, ph);
			if (flag == -1)
			{
				cout << "Delete Error" << endl;
			}
			else record.erase(record.begin() + flag);
		}
		else if (method == "search")
		{
			string first, last, ph;
			cin >> first >> last >> ph;
			if (first.length() > 25 || last.length() > 30 || ph.length() > 15 || phoneCheck(ph) == false)
			{
				cout << "Input Error" << endl;
				continue;
			}
			int flag = search(record, first, last, ph);
			if (flag == -1)
			{
				cout << "Search Error" << endl;
			}
			else cout << flag << endl;
		}
		else if (method == "print")
		{
			if (record.size() == 0)
			{
				cout << "Print Error" << endl;
				continue;
			}
			for (int i = 0; i < record.size(); i++)
			{
				cout << record[i].firstName << " " << record[i].lastName << " " << record[i].phone << endl;
			}
		}
		else
		{
			string str;
			getline(cin, str);
			cout << "Input Error" << endl;
		}
	}
}