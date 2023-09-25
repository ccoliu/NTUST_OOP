//Name:¼B®a¦¨
//Date: 2022/3/22
//Last Update: 2022/3/22
//Problem statement: Create Fraction class and demonstrate.

#include "Fraction.h"
#include <numeric>

int gcd(int a, int b) //we need to find the greatest common factor to make fraction reduced.
{
	int t; //set t as temp

	while (b != 0) //loop until b equals to 0 
	{
		t = b; 
		b = a % b;
		a = t;
	}

	return a;
}

void Fraction::setNumerator(int nu)
{
	this->numerator = nu; // set numerator to the designated integer nu
}

void Fraction::setDenominator(int de)
{
	this->denominator = de; //set denominator to the designed integer de
}

void Fraction::getDouble()
{
	if (this->numerator % this->denominator == 0) //if numerator can be divided by denominator in integer form, we output originated form
	{
		cout << (this->numerator) / (this->denominator) << endl;
	}
	else //else we output the form in the float form (with 6 vantissas)
	{
		cout << fixed << setprecision(6) << (double)(this->numerator) / (double)(this->denominator) << endl;
	}
}

void Fraction::outputReducedFraction()
{
	if (this->numerator % this->denominator == 0) //if numerator can be divided by denominator in integer form, we output the result
	{
		cout << (this->numerator) / (this->denominator) << endl;
	}
	else //else we get the numbers divided by greatest common factor to get reduced fraction
	{
		cout << (this->numerator) / gcd(this->numerator, this->denominator) << "/";
		cout << (this->denominator) / gcd(this->numerator, this->denominator) << endl;
	}
}



