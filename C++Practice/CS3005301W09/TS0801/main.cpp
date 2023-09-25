#include <iostream>
#include <string>
#include <vector>
#include "Polynomial.h"
using namespace std;

int main()
{
	Polynomial empty;
	double one[] = { 1 };
	Polynomial One(one, 1);
	double quad[] = { 3, 0, 1, 0, 3 };
	double cubic[] = { 8 };
	Polynomial q(quad, 5); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
	Polynomial p = q;  // test copy constructor
	Polynomial r;
	r = q;             //test operator=
	cout << r.mySize() << endl;
	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	r[0] = 100;
	c[1] = 5;
	for (int i = 0; i < c.mySize(); i++)
	{
		cout << "term with degree " << i << " has coefficient " << c[i] << endl;
	}
	return 0;
}