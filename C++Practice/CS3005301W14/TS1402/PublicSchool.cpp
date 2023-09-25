//Name: ¼B®a¦¨
//Date: 2023/5/24
//Last Update: 2023/5/24
//Problem statement: School and its derived classes demonstration

#include "PublicSchool.h"

void PublicSchool::apply_growth() //PublicSchool's unique growth function
{
	studentAmountNextYear += studentAmountNextYear * growing_rate; //add studentAmountNextYear by studentAmountNextYear * growing_rate
}

void PublicSchool::dropouts(float amount) //PublicSchool's unique dropout function
{
	if (amount > 0 && amount <= studentAmount) //if amount is positive and less than or equal to studentAmount
	{
		studentAmount -= amount; //subtract amount from studentAmount
		if (amount > 100) //if amount is greater than 100
		{
			studentAmountNextYear -= studentAmountNextYear * 0.05; //subtract studentAmountNextYear by studentAmountNextYear * 0.05
		}
	}
}