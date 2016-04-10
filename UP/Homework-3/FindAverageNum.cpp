#include <iostream>

using namespace std;

int main()
{
	//read n
	int n = 0;
	while (n <= 2 || n >= 1024)
	{
		cout << "Enter n \n";
		cin >> n;
	}

	int* arr = new int[n];

	//read n numbers
	for (int i = 0; i < n; i++)
	{
		cout << "Enter number " << i << endl;
		cin >> arr[i];
	}

	int sum = 0;

	//find average
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	int average = sum / n;
	cout << average << endl;

	//print all bigger nums than the average
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > average)
		{
			cout << arr[i] << ",";
		}
	}

	return 0;
}
