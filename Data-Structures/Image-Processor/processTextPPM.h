#pragma once
#include "processTextFiles.h"

class processTextPPM : public processTextFiles
{
public:
	int** readPPM(string filename);
	void writeTextPPMtoPGM(string filename,int** arr, int width, int height);
	void generateHistogram(string filename,int** arr, int width, int height, int rgb);
};