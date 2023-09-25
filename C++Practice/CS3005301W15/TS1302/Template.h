//Name: ¼B®a¦¨
//Date: 2023/05/31
//Last Update: 2023/05/31
//Problem statement: Using template to implement Absolute value calculation

#pragma once
#include <iostream>
using namespace std;

template<typename T> //apply template with typename T
double absoluteValue(T a, T b) //function prototype with two Type T parameters and return a double value
{
	if (a > b) //if a is greater than b
	{
		return a - b; //return a - b
	}
	else return b - a; //else return b - a
}