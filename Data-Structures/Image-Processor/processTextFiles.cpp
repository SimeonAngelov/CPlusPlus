#include "processTextFiles.h"

int processTextFiles::getHeight()
{
	return height;
}

int processTextFiles::getWidth()
{
	return width;
}

int processTextFiles::getMaxValue()
{
	return maxValue;
}

void processTextFiles::setHeight(int height)
{
	this->height = height;
}

void processTextFiles::setWidth(int width)
{
	this->width = width;
}

void processTextFiles::setMaxValue(int maxValue)
{
	this->maxValue = maxValue;
}

bool processTextFiles::checkFile(ifstream &file)
{
	if (file.fail())
	{
		cerr << "Error opening file";
		return false;
	}

	return true;
}

void processTextFiles::read(ifstream& file)
{
	//read magicNum
	string magicNum;
	file >> magicNum;


	//read all the comments 
	string qlline;
	getline(file, qlline);
	char c = '#';
	while (c == '#')
	{
		file >> c;
		
		if (c == '#')
		{
			getline(file, qlline);
			continue;
		}
		else
		{
			int put = file.tellg();
			file.seekg(put - 3); //return the pointer 3 positions backwards so it can read the width again
			break;
		}
	}

	//read the height and width
	int width;
	int height;
	file >> width >> height;
	setHeight(height);
	setWidth(width);
	

	//read max value
	int maxValue;
	file >> maxValue;
	setMaxValue(maxValue);
	
}
