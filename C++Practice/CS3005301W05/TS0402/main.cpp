//Name:¼B®a¦¨
//Date: 2022/3/22
//Last Update: 2022/3/22
//Problem statement: Create Fraction class and demonstrate.

#include <iostream>
#include "Fraction.h"
using namespace std;

int main() //demonstrate the fraction class.
{
	Fraction f1, f2; //created two fraction classes f1, f2.
	f1.setNumerator(4); //set numerator to 4
	f1.setDenominator(2); //set demominator to 2
	f1.getDouble(); //output result (in this case we can divided in integer so we just output the original form)
	f1.outputReducedFraction(); //output reduced result (should be 2/1, but we can ignore the denominator)

	f2.setNumerator(20); //set numerator to 20
	f2.setDenominator(60); //set demominator to 60
	f2.getDouble(); // output result (the output should be in float form because we cannot divided in integer form)
	f2.outputReducedFraction(); //output reduced result (the result should be 1/3)
}