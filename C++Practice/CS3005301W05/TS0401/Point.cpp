//Name:¼B®a¦¨
//Date: 2022/3/22
//Last Update: 2022/3/22
//Problem statement: Create Point class and demonstrate.

#include "Point.h"

void Point::Set(int vertical, int horizontal) //this function is to set the point to the datas that user put in
{
	this->vertical = vertical;
	this->horizontal = horizontal;
}

void Point::Move(int x, int y) //this function move point by x and y pixels
{
	this->vertical += x;
	this->horizontal += y;
}
void Point::Rotate() //this function rotate the point to another quadrant (90 degree)
{
	int temp = this->vertical;
	this->vertical = this->horizontal;
	this->horizontal = -temp;
}
