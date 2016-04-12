#pragma once
#include "processTextFiles.h"

class processTextPGM : public processTextFiles
{
public:
	int** readTextPGM(string filename);
	void writeTextPGMtoPBM(string filename,int** arr, int width, int height);
};