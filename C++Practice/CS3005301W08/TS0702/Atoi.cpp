//Name:¼B®a¦¨
//Date: 2023/4/13
//Last Update: 2023/4/13
//Problem statement: Class Atoi to convert a string to an integer

#include "Atoi.h"

Atoi::Atoi() {
	beTrans = ""; // default value
}

Atoi::Atoi(string s) {
	beTrans = s; // default value set to s
}

void Atoi::SetString(string s) {
	beTrans = s; // default value set to s
}

const string Atoi::GetString() {
	return beTrans; //return the string
}

int Atoi::Length() {
	return (beTrans[0] == '-' ? beTrans.length() - 1 : beTrans.length()); //return the length of the string
}

bool Atoi::IsDigital() {
	for (int i = 0; i < beTrans.length(); i++) { //check if the string is digital
		if (beTrans[i] < '0' || beTrans[i] > '9') //if the character is not a digit
		{
			if (i == 0 && beTrans[i] == '-') { //if the character is a negative sign, ignore it
				continue;
			}
			return false;
		}
	}
	return true; //if all the characters are digits, return true
}

int Atoi::StringToInteger() {
	int result = 0; //initialize the result
	bool isNegative = false; //initialize the sign
	for (int i = 0; i < beTrans.length(); i++) { //check if the string is digital
		if (i == 0 && beTrans[i] == '-') //check if the string is negative
		{
			isNegative = true; //if the string is negative, set the sign to negative
			continue;
		}
		result = result * 10 + (beTrans[i] - '0'); //if the character is a digit, add it to the result
	}
	return (isNegative ? -result : result); //if the string is negative, return the negative result, else return the positive result
}