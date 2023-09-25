//Name:¼B®a¦¨
//Date: 2022/3/22
//Last Update: 2022/3/22
//Problem statement: Create Fraction class and demonstrate.

#ifndef Fraction_H
#define Fraction_H
#include <iostream>
#include <iomanip>
using namespace std;

class Fraction //created class fraction
{
private:
	int	numerator; //set up two variable which is numerator and denominator respectively.
	int denominator;
public:
	void setNumerator(int nu);
	void setDenominator(int de);
	void getDouble();
	void outputReducedFraction();

};

#endif //Fraction_H