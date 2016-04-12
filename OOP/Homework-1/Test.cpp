#include "Owner.h"
#include "Cars.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool checkOwnerNameLength(string str) const
{
	bool valid = true;
	if (str.length() > 23)
	{
		valid = false;
	}
	return valid;
}

bool checkCarID(string ID) const
{
	bool valid = false;
	if (ID.length() != 1)
	{
		return valid;
	}
	else if (ID.compare("0") == 0 || ID.compare("1") == 0 || ID.compare("2") == 0 || ID.compare("3") == 0)
	{
		valid = true;
		return valid;
	}

	return valid;
}

bool checkRegistrationNum(string regNum) const
{
	if (regNum.length() != 4)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			if (regNum[i] < 48 || regNum[i] > 57)
			{
				return false;
			}
		}
	}
	return true;
}

bool checkExistingRegNum(string regNum, std::vector<Cars> carArr) const
{
	for (int i = 0; i < carArr.size(); i++)
	{
		if (regNum == carArr[i].getRegNum())
		{
			return false;
		}
	}
	return true;
}

string getMostPopularCar(std::vector<Cars> carArr) const
{
	int x;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	for (int i = 0; i < carArr.size(); i++)
	{
		x = std::stoi(carArr[i].getID());
		switch (x)
		{
		case 0: count1++; break;
		case 1: count2++; break;
		case 2: count3++; break;
		case 3: count4++; break;
		default: break;
		}
	}

	if (count1 >= count2 && count1 >= count3 && count1 >= count4)
	{
		return "Lamborghini Murcielago";
	}
	else if (count2 >= count1 && count2 >= count3 && count2 >= count4)
	{
		return "Mercedes AMG";
	}
	else if (count3 >= count1 && count3 >= count2 && count3 >= count4)
	{
		return "Pagani Zonda R";
	}
	else if (count4 >= count1 && count4 >= count3 && count4 >= count2)
	{
		return "Bugatti Veyron";
	}
}

int getAllCarsAveragePower(std::vector<Cars> carArr) const
{
	int count = 0;
	int averagePower = 0;
	for (int i = 0; i < carArr.size(); i++)
	{
		switch (std::stoi(carArr[i].getID()))
		{
		case 0: averagePower += 670; break;
		case 1: averagePower += 503; break;
		case 2: averagePower += 740; break;
		case 3: averagePower += 1020; break;
		default: break;
		}
		count++;
	}
	averagePower /= count;
	return averagePower;
}

vector<Owner> getOwnersCarsPower(std::vector<Cars> &carArr, std::vector<Owner> &owners) const
{

	bool ownerIsListed = false;
	bool found = false;
	for (int i = 0; i < carArr.size(); i++)
	{
		//check if owner is already in list
		for (int j = 0; j < owners.size(); j++)
		{
			//if owner is already in list add the cars power and break out of the loop
			if (owners[j].getName().compare(carArr[i].getOwner()) == 0)
			{
				ownerIsListed = true;
				switch (std::stoi(carArr[i].getID()))
				{
				case 0: owners[j].setCarsPower(670); break;
				case 1: owners[j].setCarsPower(503); break;
				case 2: owners[j].setCarsPower(730); break;
				case 3: owners[j].setCarsPower(1020); break;
				default: break;
				}
				found = true;
				break;
			}
			else
			{
				found = false;
			}
		}

		if (found)
		{
			break;
		}

		//if owner is not yet in list add him and add cars power
		owners.push_back(carArr[i].getOwnerTwo());
		switch (std::stoi(carArr[i].getID()))
		{
		case 0: owners[owners.size()-1].setCarsPower(670); break;
		case 1: owners[owners.size() - 1].setCarsPower(503); break;
		case 2: owners[owners.size() - 1].setCarsPower(730); break;
		case 3: owners[owners.size() - 1].setCarsPower(1020); break;
		default: break;
		}
	}

	return owners;
}

void addCarsToVector(Cars &car, Owner &own, std::vector<Cars> &carArr)
{
	//Enter car registration number
	string regNum;
	bool validNum = true;
	do
	{
		cout << "Enter car's registration number:" << endl;
		cin >> regNum;
		if (!checkExistingRegNum(regNum, carArr))
		{
			cout << "Number exists.Please try again." << endl;
		}
		validNum = checkRegistrationNum(regNum) && checkExistingRegNum(regNum, carArr);
	} while (!validNum);
	car.setRegNum(regNum);


	//Enter owner name
	string ownerName;
	do
	{
		cout << "Enter owner's name: " << endl;
		cin >> ownerName;
	} while (!checkOwnerNameLength(ownerName));
	own.setName(ownerName);
	car.setOwner(own);

	//Enter car id
	string id;
	do
	{
		cout << "Enter car's ID" << endl;
		cin >> id;
	} while (!checkCarID(id));
	car.setID(id);

	carArr.push_back(car);
}

void generateTextFile(std::vector<Cars> carArr, std::vector<Owner> owners)
{
	
	ofstream textFile;

	textFile.open("car-report.txt");
	textFile << "The most popular car is :" << getMostPopularCar(carArr) << endl;

	textFile << "Cars average power is :" << getAllCarsAveragePower(carArr) << endl;

	textFile << "Owners Cars: " << endl;
	for (int i = 0; i < owners.size(); i++)
	{
		textFile << "Owner: " << owners[i].getName() << endl;
		textFile << "Cars power: " << owners[i].getCarsPower() << endl;
	}

	textFile.close();
}


int main(){
	Cars car1;
	Owner own1;
	std::vector<Cars> carArr;
	std::vector<Owner> owners;
	string input;
	
	int carsNum;
	cout << "Enter how many cars you would like to enter:" << endl;
	cin >> carsNum;
	do
	{
		
		cout << "What would you like to do?" << endl
		    << "Press 1 to add the cars" << endl
			<< "Press 2 to Genearte text file" << endl
			<< "Press 3 to Generate binary file" << endl
			<< "Press 0 to exit" << endl;
		cin >> input;
		if (input.compare("1") == 0)
		{
			for (int i = 0; i < carsNum; i++)
			{
				addCarsToVector(car1, own1, carArr);
			}
		}
		else if (input.compare("2") == 0)
		{
			getOwnersCarsPower(carArr, owners);
			generateTextFile(carArr, owners);
		}
		else if (input.compare("3") == 0)
		{
			getOwnersCarsPower(carArr, owners);
			generateBinaryFile("db-save.dat", carArr);
		}
		else if (input.compare("0") == 0)
		{
			cout << "Have a nice day." << endl;
		}
		else 
		{
			cout << "No such command." << endl;
		}
	} while (input.compare("0") != 0);

	
	return 0;
}
