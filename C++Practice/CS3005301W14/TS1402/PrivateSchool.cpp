//Name: ¼B®a¦¨
//Date: 2023/5/24
//Last Update: 2023/5/24
//Problem statement: School and its derived classes demonstration

#include "PrivateSchool.h"

void PrivateSchool::dropouts(float amount) //PrivateSchool's unique dropout function
{
	if (amount > 0 && amount <= studentAmount) //if amount is positive and less than or equal to studentAmount
	{
		studentAmount -= amount; //subtract amount from studentAmount
		if (dropout_wave) studentAmountNextYear -= 100; //if dropout_wave is not 0, subtract 100 from studentAmountNextYear
		dropout_wave++; //increment dropout_wave
	}
}

