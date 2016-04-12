#pragma once
#include "Employee.h"
#include <vector>
class Secretary : public Employee
{
	std::vector<std::string> languages;
public:
	void setLanguages(int);
	void printLanguages() const;
};