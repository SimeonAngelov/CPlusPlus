#include "Triangle.h"
#include <iostream>

bool Triangle::checkPoint(double x, double y)
{
    bool b1, b2, b3;

    b1 = sign(x,y, x1,y1, x2,y2) < 0.0f;
    b2 = sign(x,y, x2,y2, x3,y3) < 0.0f;
    b3 = sign(x,y, x3,y3, x1,y1) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

double Triangle::sign(double x1, double y1, double x2, double y2, double x3, double y3)
{
	return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}

void Triangle::setData(double x1, double y1, double x2, double y2, double x3,double y3)
{
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->y1 = y1;
	this->y2 = y2;
	this->y3 = y3;

}

double Triangle::getX1() const
{
	return x1;
}
double Triangle::getX2() const
{
	return x2;
}
double Triangle::getX3() const
{ 
	return x3;
}
double Triangle::getY1() const
{
	return y1;
}
double Triangle::getY2() const
{
	return y2;
}
double Triangle::getY3() const
{
	return y3;
}

void Triangle::translate(double x, double y)
{
	x1 += x;
	x2 += x;
	x3 += x;
	
	y1 += y;
	y2 += y;
	y3 += y;
}

void Triangle::printData() const
{
	std::cout << "TRIANGLE:  x1: " << x1 << ", y1: " <<
		y1 << ", x2: " << x2 << ", y2: " << y2 << ", x3: " <<
		x3 << " , y3: " << y3 << std::endl;
}