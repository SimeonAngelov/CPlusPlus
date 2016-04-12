#pragma once
#include "Employee.h"
#include "Secretary.h"
class Director: public Employee
{
	Secretary secretary;
	Employee* employees;
	int employeeCount;
public:
	void setSecretary(Secretary secretary);
	void setEmployes(Employee* employees,int);
	Employee* getEmployees() const;

	int getEmployeeCount() const;
	void setEmployeeCount(int);
};