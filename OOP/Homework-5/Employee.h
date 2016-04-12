#pragma once
#include <string>
class Employee
{
	std::string name;
	std::string address;
	std::string egn;
	int payment;
	std::string department;
public:
	void setData(std::string name, std::string address,
		std::string egn, int payment, std::string department);

	int getPayment() const;
	std::string getName() const;
	std::string getAddress() const;
	std::string getEgn() const;
	std::string getDepartment() const;
};