#include "Employee.h"
#include <iostream>

void Employee::setData(std::string name, std::string address,
	std::string egn, int payment, std::string department)
{
	this->name = name;

	this->address = address;

	this->egn = egn;

	this->payment = payment;

	this->department = department;
}

int Employee::getPayment() const
{
	return payment;
}

std::string Employee::getName() const
{
	return name;
}

std::string Employee::getAddress() const
{
	return address;
}

std::string Employee::getEgn() const
{
	return egn;
}

std::string Employee::getDepartment() const
{
	return department;
}