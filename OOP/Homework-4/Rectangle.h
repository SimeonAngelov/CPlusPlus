#pragma once
#include "Shape.h"
class Rectangle: public Shape
{
	double bx;
	double by;

	double dx;
	double dy;

	double ax;
	double ay;
public: 
	bool checkPoint(double x, double y);
	void setData(double,double,double,double);
	void translate(double x, double y);
	void printData() const;

};