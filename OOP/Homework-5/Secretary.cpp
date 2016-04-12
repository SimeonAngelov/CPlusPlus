#include "Secretary.h"	
#include <iostream>

void Secretary::setLanguages(int languagesCount)
{
	for (int i = 0; i < languagesCount; i++)
	{
		std::string language;
		std::cin >> language;
		languages.push_back(language);
	}
}

void Secretary::printLanguages() const
{
	for (int i = 0; i < languages.size(); i++)
	{
		std::cout << languages[i] << "\n";
	}
}

