#pragma once
class Shape
{
public:
	virtual bool checkPoint(double x, double y) = 0;
	virtual void translate(double,double) = 0;
	virtual void printData() const = 0;
};