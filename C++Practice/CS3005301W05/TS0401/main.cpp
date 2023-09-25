//Name:¼B®a¦¨
//Date: 2022/3/22
//Last Update: 2022/3/22
//Problem statement: Create Point class and demonstrate.

#include <iostream>
#include "Point.h"
using namespace std;

int main(void) { //demonstrate the point class here.
	Point point; //create class point

	point.Set(0, 5); //set point to x = 0, y = 5
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl; //get point data

	point.Move(1, 2); //move point by (1,2)
	cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl; //get point data
	for (int i = 0; i < 4; i++) {
		point.Rotate(); //rotate point by 90 degree
		cout << point.RetrieveVertical() << " " << point.RetrieveHorizontal() << endl; //get point data
	}

	return 0;
}