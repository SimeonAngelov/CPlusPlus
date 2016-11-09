#include <string>
#include <vector>
#include "processTextFiles.h"
#include "processTextPPM.h"
#include "processTextPGM.h"
#include "processBinaryFilesPPM.h"

using namespace std;

void readEntry(int argc, char* argv[], vector<string> &operations, vector<string> &files)
{
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			operations.push_back(argv[i]);
		}
		else
		{
			files.push_back(argv[i]);
		}

	}
}

int main(int argc, char* argv[])
{
	
	vector<string> operations;
	vector<string> files;
	processTextPPM factory;
	processTextPGM factory2;
	
	readEntry(argc, argv, operations, files);
	/*operations.push_back("--histogram=red");
	operations.push_back("--histogram=blue");
	operations.push_back("--histogram=green");


	files.push_back("snail.ascii.ppm");
	files.push_back("blackbuck.ascii.ppm");*/
	for (int j = 0; j < files.size(); j++)
	{
		for (int i = 0; i < operations.size(); i++)
		{
			string str = files[j].substr(strlen(files[j].c_str()) - 3, 3);

			
			if (operations[i].compare("--grayscale") == 0 && str.compare("ppm") == 0)
			{
				int** arr = factory.readPPM(files[j]);
				factory.writeTextPPMtoPGM(files[j], arr, factory.getWidth(), factory.getHeight());
			}
			else if (operations[i].compare("--monochrome") == 0 && (str.compare("ppm") == 0 || str.compare("pgm") == 0))
			{
				if (str.compare("pgm") != 0)
				{
					int** arr = factory.readPPM(files[j]);
					factory.writeTextPPMtoPGM(files[j], arr, factory.getWidth(), factory.getHeight());
				}
				int** arr2 = factory2.readTextPGM(files[j]);
				factory2.writeTextPGMtoPBM(files[j], arr2, factory2.getWidth(), factory2.getHeight());
			}
			else if (operations[i].compare("--histogram=red") == 0 && (str.compare("ppm") == 0))
			{
				int** arr = factory.readPPM(files[j]);
				factory.generateHistogram(files[j],arr, factory.getWidth(), factory.getHeight(), 0);
			}
			else if (operations[i].compare("--histogram=blue") == 0 && str.compare("ppm") == 0)
			{
				int** arr = factory.readPPM(files[j]);
				factory.generateHistogram(files[j], arr, factory.getWidth(), factory.getHeight(), 2);
			}
			else if (operations[i].compare("--histogram=green") == 0 && str.compare("ppm") == 0)
			{
				int** arr = factory.readPPM(files[j]);
				factory.generateHistogram(files[j], arr, factory.getWidth(), factory.getHeight(), 1);
			}
		}
	}

	return 0;
}
