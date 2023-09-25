//Author: ¼B®a¦¨
//Date: 2023/05/02
//Last Update: 2023/05/02
//Problem statement: Demonstrating namespace Authenticate to let user enter username and password

#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace Authenticate //under namespace Authenticate
{
	string username; //declare username
	bool usernameisValid(); //declare usernameisValid
	void inputUserName(); //declare inputUserName
	string getUserName(); //declare getUserName
}

bool Authenticate::usernameisValid() //define usernameisValid
{
	if (username.length() != 8) //if username length is not 8
	{
		return false; //return false
	}
	else //if username length is 8
	{
		bool containNonLetter = false; //declare containNonLetter
		for (int i = 0; i < username.length(); i++) //for loop
		{
			if (!isalpha(username[i])) //if character is not a letter
			{
				containNonLetter = true; //containNonLetter is true
			}
		}
		return !containNonLetter; //return not containNonLetter
	}
}

void Authenticate::inputUserName()
{
	do
	{
		cout << "Enter your username (8 letters only)" << endl; //output information
		cin >> username; //input username
	} while (!usernameisValid()); //while username is not valid
}

string Authenticate::getUserName() //define getUserName
{
	return username; //return username
}