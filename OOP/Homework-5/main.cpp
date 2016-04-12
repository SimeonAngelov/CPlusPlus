#include "Director.h" 
#include "Employee.h"
#include "Leader.h"
#include "Secretary.h"
#include "Specialist.h"
#include <iostream>

int calculateSalary(Director& director, Secretary &secretary,
					int employeeNum)
{
	int totalSalary = 0;
	for (int i = 0; i < employeeNum; i++)
	{
		totalSalary += director.getEmployees()[i].getPayment();
	}

	totalSalary += director.getPayment();
	totalSalary += secretary.getPayment();

	return totalSalary;
}

void initializeEmployees(int employeeNum, Employee* employes,
	Employee* nonSpecialists, Specialist* specialists, Leader* leaders,
	int employeeCount, int specialistCount, int leaderCount)
{
	std::string name;
	std::string egn;
	std::string address;
	std::string department;
	int payment;

	int counter = 0;
	//initialize employees non specialists
	std::cout << "Enter data for non-specialists: \n";
	for (int i = 0; i < employeeCount; i++)
	{
			Employee employee;
			std::cout << "Enter name: \n";
			std::cin >> name;
			std::cout << "Enter address \n";
			std::cin >> address;
			std::cout << "Enter egn: \n";
			std::cin >> egn;
			std::cout << "Enter payment: \n";
			std::cin >> payment;
			std::cout << "Enter department: \n";
			std::cin >> department;
			employee.setData(name,address,egn,payment,department);
			employes[counter] = employee;
			nonSpecialists[i] = employee;
			counter++;
	}

	std::cout << "Enter data for specialists: \n";
	//initialize employees specialists
	for (int i = 0; i < specialistCount; i++)
	{
		Specialist specialist;
		std::string specialization;
		std::cout << "Enter specialization \n";
		std::cin >> specialization;
		specialist.setSpecialization(specialization);

		std::cout << "Enter name: \n";
		std::cin >> name;
		std::cout << "Enter address \n";
		std::cin >> address;
		std::cout << "Enter egn: \n";
		std::cin >> egn;
		std::cout << "Enter payment: \n";
		std::cin >> payment;
		std::cout << "Enter department: \n";
		std::cin >> department;

		specialist.setData(name,address,egn,payment,department);
		employes[counter] = specialist;
		specialists[i] = specialist;
		counter++;
	}

	std::cout << "Enter data for leaders: \n";
	//initialize employees leaders
	for (int i = 0; i < leaderCount; i++)
	{
		Leader leader;
		std::string departmentInfo;
		std::cout << "Enter departmentInfo \n";
		std::cin >> departmentInfo;
		leader.setDepartmentInfo(departmentInfo);
		std::cout << "Enter name: \n";
		std::cin >> name;
		std::cout << "Enter address \n";
		std::cin >> address;
		std::cout << "Enter egn: \n";
		std::cin >> egn;
		std::cout << "Enter payment: \n";
		std::cin >> payment;
		std::cout << "Enter department: \n";
		std::cin >> department;
		leader.setData(name, address, egn, payment, department);
		employes[counter] = leader;
		leaders[i] = leader;
		counter++;
	}
}

bool checkCompany(int employeeCount, int specialistCount,
	int leaderCount, int employeesNonSpecialists, int specialists,
	int leaders)
{
	//determine if employees non-specialists are enough
	if (employeesNonSpecialists > employeeCount)
	{
		std::cout << "Too few employes non-specialists.\n";
		return false;
	}

	//determine if specialists are enough
	if (specialists > specialistCount)
	{
		std::cout << "Too few specialists.\n";
		return false;
	}

	//determine if leaders are enough
	if (leaders > leaderCount)
	{
		std::cout << "Too few leaders.\n";
		return false;
	}

	std::cout << "It can be done! \n";
	return true;
}

template <class T> void sort(T* num,int employeeNum)
{
	int i, j, flag = 1;    // set flag to 1 to start first pass
	T temp;             // holding variable
	int numLength = employeeNum;
	for (i = 1; (i <= numLength) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (numLength - 1); j++)
		{
			if (num[j + 1].getPayment() < num[j].getPayment())      // ascending order simply changes to <
			{
				temp = num[j];             // swap elements
				num[j] = num[j + 1];
				num[j + 1] = temp;
				flag = 1;               // indicates that a swap occurred.
			}
		}
	}
	return;   //arrays are passed to functions by address; nothing is returned
}

void printCheapestTeam(Employee* employes, Specialist* specialists,
	Leader* leaders,int employeeNum, int specialistNum, int leaderNum)
{
	sort(employes, employeeNum);
	sort(specialists, specialistNum);
	sort(leaders, leaderNum);

	for (int i = 0; i < employeeNum; i++)
	{
		std::cout << employes[i].getName() << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < specialistNum; i++)
	{
		std::cout << specialists[i].getName() << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < leaderNum; i++)
	{
		std::cout << leaders[i].getName() << std::endl;
	}
}

int main()
{
	std::string name;
	std::string egn;
	std::string address;
	std::string department;
	int payment;
	Director director;
	Secretary secretary;
	Employee* nonSpecialists;
	Specialist* specialists;
	Leader* leaders;
	Employee* employes;

	/* ask how many non-specialists, specalist and leader the user
	 * would like and initialize the three arrays for the three 
	 * employee types.Then make one array with all employes for the 
	 * director array with the size of the non-specialists + 
	 * specialists + leaders. */
	int employeeCount = 0;
	int specialistCount = 0;
	int leaderCount = 0;

	std::cout << "How many non-specialists would you like? \n";
	std::cin >> employeeCount;
	nonSpecialists = new Employee[employeeCount];

	std::cout << "How many specialists would you like? \n";
	std::cin >> specialistCount;
	specialists = new Specialist[specialistCount];

	std::cout << "How many leaders would you like? \n";
	std::cin >> leaderCount;
	leaders = new Leader[leaderCount];

	int employeeNum = employeeCount + specialistCount + leaderCount;
	employes = new Employee[employeeNum];
	director.setEmployeeCount(employeeNum);

	initializeEmployees(employeeNum, employes,
		nonSpecialists,specialists,leaders, employeeCount, 
		specialistCount, leaderCount);

	//---------------------------------------------------

	//Fill in data first for secretary and the director
	std::cout << "Fill in details for secretary: \n";
	std::cout << "Enter name: \n";
	std::cin >> name;
	std::cout << "Enter address \n";
	std::cin >> address;
	std::cout << "Enter egn: \n";
	std::cin >> egn;
	std::cout << "Enter payment: \n";
	std::cin >> payment;
	std::cout << "Enter department: \n";
	std::cin >> department;
	secretary.setData(name, address, egn, payment, department);

	std::cout << "How many languages would you like? \n";
	int languagesCount = 0;
	std::cin >> languagesCount;
	secretary.setLanguages(languagesCount);

	std::cout << "Fill in details for director: \n";
	std::cout << "Enter name: \n";
	std::cin >> name;
	std::cout << "Enter address \n";
	std::cin >> address;
	std::cout << "Enter egn: \n";
	std::cin >> egn;
	std::cout << "Enter payment: \n";
	std::cin >> payment;
	std::cout << "Enter department: \n";
	std::cin >> department;
	director.setData(name, address, egn, payment, department);

	director.setSecretary(secretary);
	director.setEmployes(employes, director.getEmployeeCount());

	//----------------------------------------------------

	/* calculate total salary of employes without check if a
	 * company could be made or not and without choosing the 
	 * cheapest team*/
	std::cout << "total salary of all employees is: " <<
		calculateSalary(director,secretary,employeeNum) << 
		std::endl;
	
	//-----------------------------------------------------

	//check if a company can be made of existing employees
	int nonSpecialistsRequired;
	std::cout << "How many employes non-specialist must we have? \n";
	std::cin >> nonSpecialistsRequired;

	int specialistsRequired;
	std::cout << "How many specialists must we have? \n";
	std::cin >> specialistsRequired;

	int leadersRequired;
	std::cout << "How many leaders must we have? \n";
	std::cin >> leadersRequired;

	checkCompany(employeeCount, specialistCount, leaderCount,
		nonSpecialistsRequired, specialistsRequired, leadersRequired);

	//-------------------------------------------------------

	printCheapestTeam(employes, specialists, leaders, employeeCount,
		specialistCount, leaderCount);

	delete[]  nonSpecialists;
	delete[] specialists;
	delete[] leaders;
	delete[] employes;

	return 0;
}