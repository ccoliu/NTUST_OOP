//Name:¼B®a¦¨
//Date: 2022/3/30
//Last Update: 2022/3/30
//Problem statement: Creating student records

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Define a structure to hold student records
typedef struct
{
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

// Function to search for a student record
int search(vector<StRec> record, string first, string last, string ph)
{
	for (int i = 0; i < record.size(); i++)
	{
		// Compare the first name, last name, and phone number to find the record
		if (record[i].firstName == first && record[i].lastName == last && record[i].phone == ph)
		{
			return i; // Return the index of the record if found
		}
	}
	return -1; // Return -1 if the record is not found
}

// Function to check if a phone number consists of digits only
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
	vector<StRec> record; // create a vector of StRec objects named record
	string method;
	while (cin >> method) // loop while there is input from the standard input stream
	{
		if (method == "\n") continue;
		if (method == "insert")
		{
			string first = "", last = "", ph = "";
			cin >> first >> last >> ph;
			if (first.length() > 25 || last.length() > 30 || ph.length() > 15 || phoneCheck(ph) == false)
			{
				cout << "Input Error" << endl; //if the entry does not meet requirement, return error
				continue;
			}
			if (record.size() >= 10 || search(record, first, last, ph) != -1)
			{
				cout << "Insert Error" << endl; //print error if record is full
				continue;
			}
			StRec newAdd;
			strcpy(newAdd.firstName, first.c_str());
			strcpy(newAdd.lastName, last.c_str());
			strcpy(newAdd.phone, ph.c_str());
			record.push_back(newAdd); //add new class to vector
		}
		else if (method == "delete")
		{
			string first, last, ph;
			cin >> first >> last >> ph;
			if (first.length() > 25 || last.length() > 30 || ph.length() > 15 || phoneCheck(ph) == false)
			{
				cout << "Input Error" << endl; //if the entry does not meet requirement, return error
				continue;
			}
			int flag = search(record, first, last, ph);
			if (flag == -1)
			{
				cout << "Delete Error" << endl; //if cant find the data, print error
			}
			else record.erase(record.begin() + flag); //else delete the data
		}
		else if (method == "search")
		{
			string first, last, ph;
			cin >> first >> last >> ph;
			if (first.length() > 25 || last.length() > 30 || ph.length() > 15 || phoneCheck(ph) == false)
			{
				cout << "Input Error" << endl; //if the entry does not meet requirement, return error
				continue;
			}
			int flag = search(record, first, last, ph);
			if (flag == -1)
			{
				cout << "Search Error" << endl; //if cant find the data, print error
			}
			else cout << flag << endl; //else print the index of data
		}
		else if (method == "print")
		{
			if (record.size() == 0)
			{
				cout << "Print Error" << endl; //if there is empty in record, print error
				continue;
			}
			for (int i = 0; i < record.size(); i++)
			{
				cout << record[i].firstName << " " << record[i].lastName << " " << record[i].phone << endl; //else print out all the datas in the vector
			}
		}
		else
		{
			string str;
			getline(cin, str);
			cout << "Input Error" << endl; //if the method is not in the range, output error
		}
	}
}