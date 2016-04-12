#pragma once
#include "Employee.h"	
class Specialist : public Employee
{
	std::string specialization;
public:
	void setSpecialization(std::string);
	std::string getSpecialization() const;
};
