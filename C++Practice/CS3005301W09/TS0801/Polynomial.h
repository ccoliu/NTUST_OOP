//Name:¼B®a¦¨
//Date:2023/4/19
//Last Update:2023/4/20
//Problem statement:Polynomial Class Demonstration

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#pragma once

class Polynomial
{
private:
	double* coefficient = nullptr; //private double coefficient
	int size = 0; //private int size
public:
	~Polynomial(); //destructor
	Polynomial(); //default constructor
	Polynomial(double a); //constructor with double a
	Polynomial(double* param, int size); //constructor with double* param and int size
	Polynomial(const Polynomial& poly); //copy constructor

	int mySize() { return size; } //return size
	friend double evaluate(const Polynomial& poly, const double& var); //friend function evaluate

	Polynomial& operator=(const Polynomial& poly); //overload operator=
	double& operator[](int idx); //overload operator[]
	Polynomial operator+(const Polynomial& poly); //overload operator+ (Polynomial + Polynomial)
	Polynomial operator-(const Polynomial& poly); //overload operator- (Polynomial - Polynomial)
	Polynomial operator*(const Polynomial& poly); //overload operator* (Polynomial * Polynomial)
	Polynomial operator+(const double& a); //overload operator+ (Polynomial + double)
	Polynomial operator-(const double& a); //overload operator- (Polynomial - double)
	Polynomial operator*(const double& a); //overload operator* (Polynomial * double)
	friend Polynomial operator+ (const double& a,Polynomial& poly); //friend function operator+ (double + Polynomial)
	friend Polynomial operator- (const double& a, Polynomial& poly); //friend function operator- (double - Polynomial)
	friend Polynomial operator* (const double& a, const Polynomial& poly); //friend function operator* (double * Polynomial)
	void clear_zero() //clear the zero
	{
		for (int i = size - 1; !coefficient[i]; i--, size--);
	}
};