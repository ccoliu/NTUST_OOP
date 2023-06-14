//Name:¼B®a¦¨
//Date: 2023/3/28
//Last Update: 2023/3/28
//Problem statement: Month class demonstration

#include "Month.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor sets the month to January (1)
Month::Month()
{
	month = 1;
}

// Constructor that takes three characters representing the first three letters of the month name, and sets the month accordingly
Month::Month(char first, char second, char third)
{
	month = 1;
	if (first == 'J')
	{
		if (second == 'a')
		{
			month = 1;
		}
		else if (second == 'u')
		{
			if (third == 'n') month = 6;
			else if (third == 'l') month = 7;
		}
	}
	else if (first == 'F' && second == 'e' && third == 'b') month = 2;
	else if (first == 'M')
	{
		if (second == 'a')
		{
			if (third == 'r') month = 3;
			else if (third == 'y') month = 5;
		}
	}
	else if (first == 'A')
	{
		if (second == 'p')
		{
			if (third == 'r') month = 3;
		}
		if (second == 'u')
		{
			if (third == 'g') month = 8;
		}
	}
	else if (first == 'S' && second == 'e' && third == 'p') month = 9;
	else if (first == 'O' && second == 'c' && third == 't') month = 10;
	else if (first == 'N' && second == 'o' && third == 'v') month = 11;
	else if (first == 'D' && second == 'e' && third == 'c') month = 12;
}

// Constructor that takes integer monthInt, and sets the month to it.
Month::Month(int monthInt)
{
	month = ((monthInt < 1 || monthInt > 12) ? 1 : monthInt);
}


Month::~Month()
{
}

// User inputs integer x to set month to it.
void Month::inputInt()
{
	int x;
	cin >> x;
	month = ((x < 1 || x > 12) ? 1 : x);
}

// User inputs three characters representing the first three letters of the month name, and sets the month accordingly
void Month::inputStr()
{
	char first, second, third;
	cin >> first;
	cin >> second;
	cin >> third;
	month = 1;
	if (first == 'J')
	{
		if (second == 'a')
		{
			month = 1;
		}
		else if (second == 'u')
		{
			if (third == 'n') month = 6;
			else if (third == 'l') month = 7;
		}
	}
	else if (first == 'F' && second == 'e' && third == 'b') month = 2;
	else if (first == 'M')
	{
		if (second == 'a')
		{
			if (third == 'r') month = 3;
			else if (third == 'y') month = 5;
		}
	}
	else if (first == 'A')
	{
		if (second == 'p')
		{
			if (third == 'r') month = 3;
		}
		if (second == 'u')
		{
			if (third == 'g') month = 8;
		}
	}
	else if (first == 'S' && second == 'e' && third == 'p') month = 9;
	else if (first == 'O' && second == 'c' && third == 't') month = 10;
	else if (first == 'N' && second == 'o' && third == 'v') month = 11;
	else if (first == 'D' && second == 'e' && third == 'c') month = 12;
}

//output the month in integer
void Month::outputInt()
{
	cout << month;
}

//output the month in string form
void Month::outputStr()
{
	//created array of month
	string months[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	cout << months[month - 1]; //output the month in string (index = month - 1)
}

//return the next month
Month Month::nextMonth()
{
	return Month(month + 1);
}
