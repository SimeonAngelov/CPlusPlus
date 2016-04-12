#pragma once
#include "Shape.h"

class Circle: public Shape
{
	double centerX;
	double centerY;
	double radius;
public:
	double getCenterX() const;
	double getCenterY() const;
	double getRadius() const;

	void setCenterY(double);
	void setCenterX(double);
	void setRadius(double);

	bool checkPoint(double x, double y);
	void translate(double x, double y);
	void printData() const;
};