//Author: ¼B®a¦¨
//Date: 2023/05/02
//Last Update: 2023/05/02
//Problem statement: Demonstrating namespace Authenticate to let user enter username and password

#include <iostream>
#include "password.h"
#include "user.h"
using namespace Authenticate; // for Authenticate namespace
using namespace std;
int main()
{
	inputUserName(); // input username under user.h
	inputPassword(); // input password under password.h
	cout << "Your username is " << getUserName() <<
		" and your password is: " << getPassword() << endl; // output username and password
	return 0;
}