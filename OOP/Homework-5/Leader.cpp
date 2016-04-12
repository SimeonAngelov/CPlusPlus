#include "Leader.h"

std::string Leader::getDepartmentInfo() const
{
	return departmentInfo;
}

void Leader::setDepartmentInfo(std::string departmentInfo)
{
	this->departmentInfo = departmentInfo;
}

int Leader:: getEmployeeCount()const
{
	return employeeCount;
}
void Leader::setEmployeeCount(int emp)
{
	this->employeeCount = emp;
}