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
    string password; //declare password
    bool passwordisValid(); //declare passwordisValid
    void inputPassword(); //declare inputPassword
    string getPassword(); //declare getPassword
}

bool Authenticate::passwordisValid() //define passwordisValid
{
    if (password.length() < 8) //if password length is less than 8
    {
        return false; //return false
    }
    else //if password length is more than 8
    {
        bool hasNonLetter = false; //declare hasNonLetter
        for (int i = 0; i < password.length(); i++) //for loop
        {
            if (!isalpha(password[i])) //if character is not a letter
            {
                hasNonLetter = true; //hasNonLetter is true
            }
        }
        return hasNonLetter; //return hasNonLetter
    }
}

void Authenticate::inputPassword() //define inputPassword
{
    do
    {
        cout << "Enter your password (at least 8 characters " <<
            "and at least one non-letter)" << endl; //output information
        cin >> password; //input password
    } while (!passwordisValid()); //while password is not valid
}

string Authenticate::getPassword() //define getPassword
{
    return password; //return password
}
