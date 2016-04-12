#pragma once
#include "Specialist.h"
class Leader : public Specialist
{
	Employee* arr;
	std::string departmentInfo;
	int employeeCount;
public:
	std::string getDepartmentInfo() const;
	void setDepartmentInfo(std::string);
	int getEmployeeCount()const;
	void setEmployeeCount(int);
};