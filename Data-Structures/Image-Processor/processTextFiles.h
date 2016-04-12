#pragma once
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class processTextFiles
{
	int width;
	int height;
	int maxValue;
public:
	bool checkFile(ifstream& file);

	int getWidth();
	int getHeight();
	int getMaxValue();

	void setWidth(int width);
	void setHeight(int height);
	void setMaxValue(int maxValue);
	void read(ifstream& file);
};