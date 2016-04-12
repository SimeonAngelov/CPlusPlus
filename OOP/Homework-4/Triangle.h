#pragma once
#include "Shape.h"

class Triangle: public Shape
{
	double x1;
	double y1;

	double x2;
	double y2;
	
	double x3;
	double y3;
public:
	void setData(double, double, double, double, double,double);
	double getX1() const;
	double getX2() const;
	double getX3() const;
	double getY1() const;
	double getY2() const;
	double getY3() const;

	bool checkPoint(double x, double y);
	void translate(double x, double y);
	void printData() const;
	double sign(double x1, double y1, double x2, double y2, double x3, double y3);
};