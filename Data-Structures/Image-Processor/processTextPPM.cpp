#include "processTextPPM.h"

int** processTextPPM::readPPM(string filename)
{

	ifstream file(filename.c_str());
	checkFile(file);
	read(file);
	//read pixels and then initialze array for the new grayscale pixels
	int r;
	int g;
	int b;
	int pixel;
	//initialize array here
	int** pixelArr = new int*[getHeight()];
	for (int i = 0; i < getHeight(); i++)
	{
		pixelArr[i] = new int[getWidth()];
	}

	//save new pixels in an array
	for (int i = 0; i < getHeight(); i++)
	{
		for (int j = 0; j < getWidth(); j++)
		{
			file >> r >> g >> b;
			pixel = (r + g + b) / 3;
			pixelArr[i][j] = pixel;	
		}
	}

	return pixelArr;
}
void processTextPPM::writeTextPPMtoPGM(string filename,int** arr, int width, int height)
{
	string str = filename.substr(0, strlen(filename.c_str()) - 4); 
	string strPGM = "_pgm.pgm";
	str.append(strPGM);
	ofstream file(str);

	if (file.fail())
	{
		cerr << "Error opening file";
		return;
	}

	//enter magic number, width and height and then max value for each pixel
	file << "P2\n";
	file << width << " " << height << "\n";
	file << "255\n";

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			file << arr[i][j] << " ";
		}
		file << "\n";
	}
}
void processTextPPM::generateHistogram(string filename,int** arr, int width, int height, int rgb)
{
	//read pixels and then initialze array for the new grayscale pixels with default value 0
	int* histogramRed = new int[256];
	for (int width = 0; width < 256; width++)
	{
		histogramRed[width] = 0;
	}

	//save new pixels in an array
	for (int i = 0; i < height; i++)
	{
		for (int j = rgb; j < width; j += 3)
		{
			histogramRed[arr[i][j]]++;
		}
	}

	//calculate percentage for each of the 0 - 255 pixels
	long long pixelNum = 0;
	for (int width = 0; width < 256; width++)
	{
		
		pixelNum += histogramRed[width];

	}
	int percentage = pixelNum / 100;

	for (int width = 0; width < 256; width++)
	{
		
		histogramRed[width] /= percentage;
	}

	//write to file
	string str = filename.substr(0, strlen(filename.c_str()) - 4);
	string strHistogram = " ";
	switch (rgb)
	{
	case(0) : strHistogram = "_histogram_red.ppm"; break;
	case(1) : strHistogram = "_histogram_green.ppm"; break;
	case(2) : strHistogram = "_histogram_blue.ppm"; break;
	}
	str.append(strHistogram);
	ofstream out(str);
	out << "P3\n" << "256 101\n" << "255\n";
	for (int i = 100; i >= 0; i--)
	{
		for (int j = 0; j < 256; j++)
		{
			switch (rgb)
			{
			case(0) :
			{
				if (histogramRed[j] >= i) out << 255 << " " << 0 << " " << 0 << " ";
				else out << 0 << " " << 0 << " " << 0 << " ";
				break;
			}
			case(1) :
			{
				if (histogramRed[j] >= i) out << 0 << " " << 255 << " " << 0 << " ";
				else out << 0 << " " << 0 << " " << 0 << " ";
				break;
			}
			case(2) :
			{
				if (histogramRed[j] >= i) out << 0 << " " << 0 << " " << 255 << " ";
				else out << 0 << " " << 0 << " " << 0 << " ";
				break;
			}
			}
		}
		out << "\n";
	}
}