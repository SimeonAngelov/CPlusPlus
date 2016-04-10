#include <iostream>
#include <string.h>

using namespace std;

bool compareStrings(string wordToCompare, int n, int m, string **arr);

int main()
{
	//declare n x m matrix
	int n;
	int m;

	do
	{
		cout << "Enter n and then m: " << endl;
		cin >> n;
		cin >> m;
	} while (n <= 3 || n > m || m >= 100);

	//read t-number for the words to be found
	int t;
	cout << "Enter t: " << endl;
	cin >> t;

	//initialize matrix
	cout << "Initialize matrix: " << endl;
	string **arr = new string*[n];
	for (int row = 0; row < n; row++)
	{
		arr[row] = new string[m];
		for (int col = 0; col < m; col++)
		{
			cin >> arr[row][col];
		}
	}

	//Enter t words
	cout << "enter words to find" << endl;
	string wordToCompare;
	for (int i = 0; i < t; i++)
	{
		cin >> wordToCompare;
		bool areEqual = compareStrings(wordToCompare, n, m, arr);
		cout << wordToCompare << endl;
		if (areEqual)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

	}

	return 0;
}

bool compareStrings(string wordToCompare, int n, int m, string **arr)
{
	//compare string horizontally from left to right 
	bool areEqual = false;
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < m; col++)
		{
			string compareString = "";
			for (int i = col; i < m; i++)
			{
				compareString.append(arr[row][i]);
				areEqual = !wordToCompare.compare(compareString);
				if (areEqual)
				{
					return true;
				}
			}

		}
	}

	//compare string horizontally from right to left 
	for (int row = 0; row < n; row++)
	{
		for (int col = m - 1; col >= 0; col--)
		{
			string compareString = "";
			for (int i = col; i >= 0; i--)
			{
				compareString.append(arr[row][i]);
				areEqual = !wordToCompare.compare(compareString);
				if (areEqual)
				{
					return true;
				}
			}
		}
	}

	//compare string vertically from bottom to top 
	for (int col = 0; col < n; col++)
	{
		for (int row = n - 1; row >= 0; row--)
		{
			string compareString = "";
			for (int i = row; i >= 0; i--)
			{
				compareString.append(arr[i][col]);
				areEqual = !wordToCompare.compare(compareString);
				if (areEqual)
				{
					return true;
				}
			}
		}
	}

	//compare string vertically from top to bottom TESTED
	for (int col = 0; col < n; col++)
	{
		for (int row = 0; row < n; row++)
		{
			string compareString = "";
			for (int i = row; i < n; i++)
			{
				compareString.append(arr[i][col]);
				areEqual = !wordToCompare.compare(compareString);
				if (areEqual)
				{
					return true;
				}
			}
		}
	}

	return false;
}
