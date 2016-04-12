#include "processTextPGM.h"

int** processTextPGM::readTextPGM(string filename)
{
	cout << endl << filename << endl;
	string sub = filename.substr(strlen(filename.c_str()) - 4, 4);
	cout << sub <<endl;
	if (sub.compare(".ppm") == 0)
	{
		filename = filename.substr(0, strlen(filename.c_str()) - 4);
		string strPGM = "_pgm.pgm";
		filename.append(strPGM);
	}
	cout << filename;
	ifstream file(filename);
	checkFile(file);
	read(file);
	//save pixels in an array
	int** pixelArr = new int*[getHeight()];
	for (int i = 0; i < getHeight(); i++)
	{
		pixelArr[i] = new int[getWidth()];
	}
	int pixel;

	for (int i = 0; i < getHeight(); i++)
	{
		for (int j = 0; j < getWidth(); j++)
		{
			file >> pixel;
			if (pixel > getMaxValue() / 2)
			{
				pixel = 1;
			}
			else
			{
				pixel = 0;
			}
			pixelArr[i][j] = pixel;
		}
	}

	return pixelArr;
}

void processTextPGM::writeTextPGMtoPBM(string filename, int** arr, int width, int height)
{
	cout << endl << filename << endl;
	string sub = filename.substr(strlen(filename.c_str()) - 4, 4);
	cout << sub << endl;
	if (sub.compare(".ppm") == 0)
	{
		filename = filename.substr(0, strlen(filename.c_str()) - 4);
		string strPBM = "_pbm.pbm";
		filename.append(strPBM);
	}
	else if (sub.compare(".pgm") == 0)
	{
		filename = filename.substr(0, strlen(filename.c_str()) - 8);
		string strPBM = "_pbm.pbm";
		filename.append(strPBM);
	}
	cout << filename;
	ofstream file(filename);
	if (file.fail())
	{
		cerr << "Error opening file";
		return;
	}

	//enter magic number, width and height
	file << "P1\n";
	file << width << " " << height << "\n";

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			file << arr[i][j] << " ";
		}
		file << "\n";
	}
}