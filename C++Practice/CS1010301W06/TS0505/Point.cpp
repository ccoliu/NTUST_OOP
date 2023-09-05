#include "Point.h"

void Point::Set(int x, int y)
{
	pos[0] = x;
	pos[1] = y;
}

void Point::Move(int x, int y)
{
	pos[0] += x;
	pos[1] += y;
}

void Point::Rotate()
{
	int temp = pos[0];
	pos[0] = pos[1];
	pos[1] = -temp;
}

void Point::Reflect()
{
	pos[0] = -pos[0];
	pos[1] = -pos[1];
}

const int Point::GetHorizontal()
{
	return pos[0];
}

const int Point::GetVertical()
{
	return pos[1];
}

Point::Point()
{
	pos[0] = 0;
	pos[1] = 0;
}

Point Point::newPoint(Point& point)
{
	point.pos[0] = pos[0];
	point.pos[1] = pos[1];
	return point;
}

Point::~Point()
{
	
}