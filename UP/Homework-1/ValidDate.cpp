#include<iostream>

using namespace std;
int main()
{
	bool isValid = false;
	bool year = true;
	bool month = true;
	bool day = true;
	int yearValue;
	int monthValue;
	int dayValue;

	cout << "Enter day :";
	cin >> dayValue;

	cout << "Enter month: ";
	cin >> monthValue;

	cout << "Enter year: ";
	cin >> yearValue;

	//check if year, day and month are a valid number
	if (yearValue < 0)
	{
		year = false;
	}

	if (monthValue <= 0 || monthValue > 12)
	{
		month = false;
	}

	if (dayValue < 1 || dayValue > 31)
	{
		day = false;
	}

	//check for leap year
	else if (monthValue == 2 && yearValue % 4 != 0 && dayValue == 29)
	{
		day = false;
	}

	//check for 30th february
	else if (monthValue == 2 && dayValue == 30){
		day = false;
	}

	//check if month has less than 31 days
	else if ((monthValue == 2 || monthValue == 4
		|| monthValue == 6 || monthValue == 9
		|| monthValue == 11) && dayValue == 31)
	{
		day = false;
	}

	if (day && year && month)
	{
		isValid = true;
	}

	if (isValid)
	{

		dayValue -= 1;
		if (dayValue == 0)
		{
			monthValue -= 1;

			if (monthValue == 0)
			{
				cout << 31 << " " << 12 << " " << yearValue - 1;
			}
			else if (monthValue == 4 || monthValue == 6 || monthValue == 9 || monthValue == 11)
			{
				cout << 30 << " " << monthValue << " " << yearValue;
			}
			else if (monthValue == 2 && yearValue % 4 != 0)
			{
				cout << 28 << " " << monthValue << " " << yearValue;
			}
			else if (monthValue == 2 && yearValue % 4 == 0)
			{
				cout << 29 << " " << monthValue << " " << yearValue;
			}
			else
			{
				cout << 31 << " " << monthValue << " " << yearValue;
			}
		}
		else
		{
			cout << dayValue << " " << monthValue << " " << yearValue;
		}
	}
	else
	{
		cout << "not valid";
	}

	return 0;
}
