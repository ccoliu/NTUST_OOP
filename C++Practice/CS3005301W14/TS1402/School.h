#pragma once
#include <iostream>
#include <string>
using namespace std;

class School
{
protected:
	string name = 0;
	int studentAmount = 0;
	int studentAmountNextYear = 0;
public:
	School(string name, int studentAmount) : name(name), studentAmount(studentAmount), studentAmountNextYear(studentAmount) {};
	void admissions(float amount);
	virtual void dropouts(float amount);
	void transfer(float amount, School& toSchool);
	friend ostream& operator<< (ostream& os, const School& school);
};

#include "PrivateSchool.h"
#include "PublicSchool.h"