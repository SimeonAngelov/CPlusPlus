#include "Rectangle.h"
#include <iostream>

bool Rectangle::checkPoint(double x, double y)
{
	double bax = bx - ax;
	double bay = by - ay;
	double dax = dx - ax;
	double day = dy - ay;

	if ((x - ax) * bax + (y - ay) * bay < 0.0) return false;
	if ((x - bx) * bax + (y - by) * bay > 0.0) return false;
	if ((x - ax) * dax + (y - ay) * day < 0.0) return false;
	if ((x - dx) * dax + (y - dy) * day > 0.0) return false;

	return true;
}

void Rectangle::setData(double bx, double by, double dx, double dy)
{
	this->bx = bx;
	this->by = by;
	this->dx = dx;
	this->dy = dy;
	ax = dx;
	ay = by;
}

void Rectangle::translate(double x, double y)
{
	bx += x;
	dx += x;
	ax += x;

	by += y;
	dy += y;
	ay += y;
}

void Rectangle::printData() const
{
	std::cout << "RECTANGLE:  b1: " << bx << ", by: " <<
		by << " , dx: " << dx << "dy: " << dy << std::endl;
}