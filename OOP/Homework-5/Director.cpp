#include "Director.h"

void Director::setSecretary(Secretary secretary)
{
	this->secretary = secretary;
}

void Director::setEmployes(Employee* employees, int employeeCount)
{
	/*Employee** arr = new Employee*[employeeCount];
	for (int i = 0; i < employeeCount; i++)
	{
		arr[i] = &employees[i];
	}

	delete[] employees;
*/
	this->employees = employees;
}

Employee* Director::getEmployees() const
{
	return employees;
}

int Director::getEmployeeCount() const
{
	return employeeCount;
}
void Director::setEmployeeCount(int emp)
{
	this->employeeCount = emp;
}