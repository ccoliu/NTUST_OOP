//Name:¼B®a¦¨
//Date: 2022/3/22
//Last Update: 2022/3/22
//Problem statement: Create Point class and demonstrate.

#ifndef Point_H
#define Point_H
#include <iostream>
using namespace std;

class Point // created class point
{
private: //this class has two variable, vertical (represents x) and horizontal (represents y)
	int vertical;
	int horizontal;

public:
	Point() //we set vertical and horizontal to 0 first
	{
		vertical = 0;
		horizontal = 0;
	}

	void Set(int vertical, int horizontal);
	void Move(int x, int y);
	void Rotate();
	int RetrieveVertical() const { return vertical; } //this function returns x value
	int RetrieveHorizontal() const { return horizontal; } //this function returns y value
};

#endif //Point_H