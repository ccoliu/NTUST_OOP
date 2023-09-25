//Name:¼B®a¦¨
//Date:2023/4/19
//Last Update:2023/4/20
//Problem statement:Polynomial Class Demonstration

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Polynomial.h"
using namespace std;

Polynomial::~Polynomial() //destructor
{
	delete[] coefficient; //delete the coefficient
	coefficient = nullptr; //set coefficient to nullptr
}

Polynomial::Polynomial() //default constructor
{
	coefficient = new double(0.0); //set coefficient to 0
}

Polynomial::Polynomial(double a) //constructor
{
	coefficient = new double(a); //set coefficient to a
}

Polynomial::Polynomial(double* param, int sz) //array constructor
{
	size = sz; //set size to sz
	coefficient = new double[size] {0}; //set coefficient to 0
	for (int i = 0; i < size; i++) 
	{
		coefficient[i] = param[i]; //set coefficient to param
	}
}

Polynomial::Polynomial(const Polynomial& poly) //copy constructor
{
	this->~Polynomial(); //delete the coefficient first
	size = poly.size; //set size to poly.size
	coefficient = new double[size] {}; //set coefficient to 0
	for (int i = 0; i < size; i++)
	{
		coefficient[i] = poly.coefficient[i]; //set coefficient to poly.coefficient
	}
}

Polynomial& Polynomial::operator=(const Polynomial& poly) //overload operator=
{
	this->~Polynomial(); //delete the coefficient first
	size = poly.size; //set size to poly.size
	coefficient = new double[size] {0}; //set coefficient to 0
	for (int i = 0; i < poly.size; i++) 
	{
		coefficient[i] = poly.coefficient[i]; //set coefficient to poly.coefficient
	}
	return *this; //return the result
}

double& Polynomial::operator[](int idx)
{
	Polynomial result = *this; //set result to this
	if (idx < 0) //if idx is less than 0
	{
		exit(1); //exit the program
	}
	else if (idx >= size) //if idx is greater than or equal to size
	{
		double* temp = new double[idx + 1] {0}; //set temp to 0
		for (int i = 0; i < size; i++)
		{
			temp[i] = coefficient[i]; //set temp to coefficient
		}
		delete[] result.coefficient; //delete the coefficient
		result.coefficient = temp; //set coefficient to temp
		size = idx + 1; //set size to idx + 1
	}
	return coefficient[idx]; //return the result
}

Polynomial Polynomial::operator+(const Polynomial& poly) //overload operator+ (Polynomial + Polynomial)
{
	Polynomial result; //set result to empty polynomial
	result.size = max(size, poly.size); //set result.size to the max of size and poly.size
	result.coefficient = new double[result.size] {}; //set result.coefficient to 0
	if (size >= poly.size) //if size is greater than or equal to poly.size
	{
		for (int i = 0; i < poly.size; i++)
		{
			result.coefficient[i] = coefficient[i] + poly.coefficient[i]; //set result.coefficient to coefficient + poly.coefficient
		}
		for (int i = poly.size; i < size; i++)
		{
			result.coefficient[i] = coefficient[i]; //set result.coefficient to coefficient
		}
	}
	else //if size is less than poly.size
	{
		for (int i = 0; i < size; i++)
		{
			result.coefficient[i] = coefficient[i] + poly.coefficient[i]; //set result.coefficient to coefficient + poly.coefficient
		}
		for (int i = size; i < poly.size; i++)
		{
			result.coefficient[i] = poly.coefficient[i]; //set result.coefficient to poly.coefficient
		}
	}
	result.clear_zero(); //clear the zero
	return result; //return the result
}

Polynomial Polynomial::operator-(const Polynomial& poly) //overload opeator- (Polynomial - Polynomial)
{
	Polynomial result; //set result to empty polynomial
	result.size = max(size, poly.size); //set result.size to the max of size and poly.size
	result.coefficient = new double[result.size] {}; //set result.coefficient to 0
	if (size >= poly.size) //if size is greater than or equal to poly.size
	{
		for (int i = 0; i < poly.size; i++) 
		{
			result.coefficient[i] = coefficient[i] - poly.coefficient[i]; //set result.coefficient to coefficient - poly.coefficient
		}
		for (int i = poly.size; i < size; i++)
		{
			result.coefficient[i] = coefficient[i]; //set result.coefficient to coefficient
		}
	}
	else //if size is less than poly.size
	{
		for (int i = 0; i < size; i++)
		{
			result.coefficient[i] = coefficient[i] - poly.coefficient[i]; //set result.coefficient to coefficient - poly.coefficient
		}
		for (int i = size; i < poly.size; i++)
		{
			result.coefficient[i] = -1 * poly.coefficient[i]; //set result.coefficient to -1 * poly.coefficient
		}
	}
	result.clear_zero(); //clear the zero
	return result; //return the result
}

Polynomial Polynomial::operator*(const Polynomial& poly) //overload operator* (Polynomial * Polynomial)
{
	Polynomial result; //set result to empty polynomial
	result.size = size + poly.size; //set result.size to size + poly.size
	result.coefficient = new double[result.size] {}; //set result.coefficient to 0
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < poly.size; j++)
		{
			result.coefficient[i + j] += coefficient[i] * poly.coefficient[j]; //set result.coefficient to coefficient * poly.coefficient
		}
	}
	result.clear_zero(); //clear the zero
	return result; //return the result
}


Polynomial Polynomial::operator+ (const double& a) //overload operator+ (Polynomial + double constant)
{
	Polynomial result = *this; //set result to this
	result[0] += a; //set result[0] to result[0] + a
	result.clear_zero(); //clear the zero
	return result; //return the result
}

Polynomial Polynomial::operator- (const double& a) //overload operator- (Polynomial - double constant)
{
	Polynomial result = *this; //set result to this
	result[0] -= a; //set result[0] to result[0] - a
	result.clear_zero(); //clear the zero
	return result; //return the result
}

Polynomial Polynomial::operator* (const double& a) //overload operator* (Polynomial * double constant)
{
	Polynomial result = *this; //set result to this
	for (int i = 0; i < size; i++)
	{
		result.coefficient[i] = (result.coefficient[i] * a); //each coefficient is multiplied by a
	}
	result.clear_zero(); //clear the zero
	return result; //return the result
}

Polynomial operator+ (const double& a, Polynomial& poly) //overload operator+ (double constant + Polynomial)
{
	Polynomial result = poly; //set result to poly
	result = poly + a; //set result to poly + a
	return result; //return the result
}

Polynomial operator- (const double& a, Polynomial& poly) //overload operator- (double constant - Polynomial)
{
	Polynomial result = poly; //set result to poly
	result = (poly * -1.0f); //set result to poly * -1.0f
	result = result + a; //set result to result + a
	return result; //return the result
}

Polynomial operator* (const double& a,const Polynomial& poly) //overload operator* (double constant * Polynomial)
{
	Polynomial result; //set result to empty polynomial
	result = poly; //set result to poly
	for (int i = 0; i < poly.size; i++)
	{
		result.coefficient[i] = result.coefficient[i] * a; //each coefficient is multiplied by a
	}
	result.clear_zero(); //clear the zero
	return result; //return the result
}

double evaluate(const Polynomial& poly, const double& var) //evaluate the polynomial
{
	double result = 0; //set result to 0
	for (int i = 0; i < poly.size; i++)
	{
		result += poly.coefficient[i] * pow(var,i); //set result to result + coefficient * var^i
	}
	return result; //return the result
}