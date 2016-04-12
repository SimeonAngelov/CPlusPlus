#include "Circle.h"
#include <iostream>

double Circle::getCenterX() const
{
	return centerX;
}

double Circle::getCenterY() const
{
	return centerY;
}

void Circle::setCenterX(double centerX)
{
	this->centerX = centerX;
}

void Circle::setCenterY(double centerY)
{
	this -> centerY = centerY;
}

void Circle::setRadius(double radius)
{
	this->radius = radius;
}

double Circle::getRadius() const
{
	return radius;
}

bool Circle::checkPoint(double x, double y)
{
	if ((x - centerX)*(x - centerX) + (y - centerY)*(y - centerY) < radius*radius)
		return true;

	return false;
}

void Circle::translate(double x, double y)
{
	centerX += x;
	centerY += y;
}

void Circle::printData() const
{
	std::cout << "CIRCLE:   Center x: " << centerX << ", center y: " <<
		centerY << " , radius: " << radius << std::endl;
}