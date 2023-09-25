//Name: ¼B®a¦¨
//Date: 2023/5/24
//Last Update: 2023/5/24
//Problem statement: School and its derived classes demonstration

#include "School.h"

void School::admissions(float amount) //admission function that adds student amount
{
	if (amount > 0)	studentAmount += amount; //if amount is positive, add it to studentAmount
}

void School::dropouts(float amount) //dropout function that subtracts student amount
{
	if (amount > 0 && amount <= studentAmount) //if amount is positive and less than or equal to studentAmount
	{
		studentAmount -= amount; //subtract amount from studentAmount
	}
}

void School::transfer(float amount, School& toSchool) //transfer function that transfers student amount
{
	if (amount > 0 && amount <= this->studentAmount) //if amount is positive and less than or equal to studentAmount
	{
		this->dropouts(amount); //subtract amount from this school
		toSchool.admissions(amount); //add amount to the other school
	}
}

ostream& operator<<(ostream& os, const School& school) //friend ostream operator that prints out school information
{
	os << school.name << "\t" << school.studentAmount << "\t" << school.studentAmountNextYear; //print out school information
	return os; //return ostream
}