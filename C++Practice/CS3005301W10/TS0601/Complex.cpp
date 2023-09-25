//Author: ¼B®a¦¨
//Date: 2023/4/26
//Last Modified: 2023/4/26
//Problem statement: This C++ header file defines a class Complex and its member functions and friend functions.

#include "Complex.h"
#include <sstream>
#include <math.h>

Complex::Complex() //constructor with no arguments
{
	realValue = 0; //set real part to 0
	imaginaryValue = 0; //set imaginary part to 0
}

Complex::Complex(double r) //constructor with one argument double r
{
	realValue = r; //set real part to r
	imaginaryValue = 0; //set imaginary part to 0
}

Complex::Complex(double r, double i) //constructor with two arguments double r and double i
{
	realValue = r; //set real part to r
	imaginaryValue = i; //set imaginary part to i
}

double Complex::real() //member function real
{
	return realValue; //return real part
}

double Complex::imag() //member function imag
{
	return imaginaryValue; //return imaginary part
}

double Complex::norm() //member function norm
{
	return sqrt(realValue * realValue + imaginaryValue * imaginaryValue); //return norm
}

double real(Complex c) //friend function real
{
	return c.realValue; //return real part
}

double imag(Complex c) //friend function imag
{
	return c.imaginaryValue; //return imaginary part
}

double norm(Complex c) //friend function norm
{
	return sqrt(c.realValue * c.realValue + c.imaginaryValue * c.imaginaryValue); //return norm
}

Complex Complex::operator+(Complex c) //operator + overloading (Complex + Complex)
{
	return Complex(realValue + c.realValue, imaginaryValue + c.imaginaryValue); //return Complex
}

Complex Complex::operator-(Complex c) //operator - overloading (Complex - Complex)
{
	return Complex(realValue - c.realValue, imaginaryValue - c.imaginaryValue); //return Complex
}

Complex Complex::operator*(Complex c) //operator * overloading (Complex * Complex)
{
	return Complex(realValue * c.realValue - imaginaryValue * c.imaginaryValue, realValue * c.imaginaryValue + imaginaryValue * c.realValue); //return Complex
}

Complex Complex::operator/(Complex c) //operator / overloading (Complex / Complex)
{
	Complex up = *this * Complex(c.realValue, -c.imaginaryValue); //the Complex which will be divided will multiply the conjugate of the Complex which will divide
	double down = c.realValue * c.realValue + c.imaginaryValue * c.imaginaryValue; //the denominator
	return Complex(up.realValue / down, up.imaginaryValue / down); //return Complex
}

Complex operator+(double d, Complex c) //operator + overloading (double + Complex)
{
	return Complex(d + c.realValue, c.imaginaryValue); //return Complex
}

Complex operator-(double d, Complex c) //operator - overloading (double - Complex)
{
	return Complex(d - c.realValue, -c.imaginaryValue); //return Complex
}

Complex operator* (double d, Complex c) //operator * overloading (double * Complex)
{
	return Complex(d * c.realValue, d * c.imaginaryValue); //return Complex
}

Complex operator/ (double d, Complex c) //operator / overloading (double / Complex)
{
	Complex up = d * Complex(c.realValue, -c.imaginaryValue); //the Complex which will be divided will multiply the conjugate of the Complex which will divide
	double down = c.realValue * c.realValue + c.imaginaryValue * c.imaginaryValue; //the denominator
	return Complex(up.realValue / down, up.imaginaryValue / down); //return Complex
}

bool operator== (Complex c1, Complex c2) //operator == overloading (Complex == Complex)
{
	return (c1.realValue == c2.realValue) && (c1.imaginaryValue == c2.imaginaryValue); //return true if c1 == c2, otherwise return false
}

ostream& operator<<(ostream& strm, const Complex& c) //operator << overloading
{
	strm << c.realValue << " + " << c.imaginaryValue << "*i"; //output the realValue and imaginaryValue of the Complex
	return strm; //return ostream
}

istream& operator>>(istream& strm, Complex& c) //operator >> overloading
{
	string s; //string to store the input
	getline(strm, s); //read whole line
	istringstream iss(s); //istringstream to read the string
	string s1, s2, s3, s4; //string s1, s2 ,s3, s4 are the stray array that Complex class will not use
	iss >> s1 >> s2 >> c.realValue >> s3 >> c.imaginaryValue >> s4; //read the string
	return strm; //return istream
}