#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string shape;
	std::vector<Shape*> vec;

	std:: ifstream readFile("file.txt");
	if (readFile.fail())
	{
		std::cerr << "Error opening file";
	}
	while (!readFile.eof())
	{
		readFile>> shape;
		if (shape.compare("circle") == 0)
		{
			Circle circle;
			double centerX;
			double centerY;
			double radius;
			readFile >> centerX >> centerY >> radius;
			circle.setCenterX(centerX);
			circle.setCenterY(centerY);
			circle.setRadius(radius);
			vec.push_back(&circle);
		}
		else if (shape.compare("triangle") == 0)
		{
			double x1, x2, x3, y1, y2, y3;
			readFile >> x1 >> y1 >> x2 >> y2 >> x3 >>y3;
			Triangle triangle;
			triangle.setData(x1, y1, x2, y2, x3, y3);
			vec.push_back(&triangle);
		}
		else if (shape.compare("rect") == 0)
		{
			double bx, by, dx, dy;
			readFile >> bx >> by >> dx >> dy;
			Rectangle rect;
			rect.setData(bx,by,dx,dy);
			vec.push_back(&rect);
		}
		else if (shape.compare("group")==0)
		{
			//use shape to read "in"
			readFile >> shape;
			double vectorX, vectorY;
			//read the translation vector coordinates
			readFile >> vectorX >> vectorY; 

			//read until finding group again
			while (shape.compare("group") != 0)
			{
				//use shape to read "in"
				readFile >> shape;
				if (shape.compare("circle") == 0)
				{
					Circle circle;
					double centerX;
					double centerY;
					double radius;
					readFile >> centerX >> centerY >> radius;
					std::cout << centerX << " " << centerY << " " << radius << std::endl;
					circle.setCenterX(centerX);
					circle.setCenterY(centerY);
					circle.setRadius(radius);
					circle.translate(vectorX,vectorY);
					vec.push_back(&circle);
				}
				else if (shape.compare("triangle") == 0)
				{
					double x1, x2, x3, y1, y2, y3;
					readFile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
					Triangle triangle;
					triangle.setData(x1, y1, x2, y2, x3, y3);
					triangle.translate(vectorX, vectorY);
					vec.push_back(&triangle);
				}
				else if (shape.compare("rect") == 0)
				{
					double bx, by, dx, dy;
					readFile >> bx >> by >> dx >> dy;
					Rectangle rect;
					rect.setData(bx, by, dx, dy);
					rect.translate(vectorX, vectorY);
					vec.push_back(&rect);
				}
			}
		}
	}  

	for (int i = 0; i < vec.size(); i++)
	{
		vec[i]->printData();
		if (vec[i]->checkPoint(1.0, 1.0))
			std::cout << "      Point is in\n";
		else
			std::cout << "      Point is out\n";
	}
	
	return 0;
}
