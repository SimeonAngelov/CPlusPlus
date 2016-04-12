#include <string>
#include <iostream>

//return number of words which start with str
int searchPrefix(int start, int end, std::string* names, std::string str)
{
	int counter = 0;
	std::string tmp;
	for (size_t i = start; i <= end; i++)
	{
		/*if the searched prefix is longer than the word itself don't do anything
		compare it to the other words prefixes otherwise and increment counter
		if we have a match*/
		if (str.size() <= names[i].size())
		{
			tmp = names[i].substr(0, str.size());
			if (tmp.compare(str) == 0)
			{
				counter++;
			}
		}
	}
	return counter;
}

void insertionSort(std::string* names, int size)
{
	std::string tmp;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j > 0; j--)
			{
				if (names[j].compare(names[j - 1]) < 0)
				{
					tmp = names[j - 1];
					names[j - 1] = names[j];
					names[j] = tmp;
				}
			}
		}
	
}

void processData()
{
	int N, T, Q;
	//read T (number of inputs)
	std::cout << "Enter T: ";
	std::cin >> T;

	for (size_t i = 0; i < T; i++)
	{
		//read N (number of names)
		do
		{
			std::cout << "Enter N: ";
			std::cin >> N;
		} while (N > 1000000);
		
		//read Q (number of requests)
		do
		{
			std::cout << "Enter Q: ";
			std::cin >> Q;
		} while (Q > 500000);

		//read names
		std::cout << "Enter names: ";
		std::string* arr = new std::string[N];
		for (size_t j = 0; j < N; j++)
		{
			do
			{
				std::cin >> arr[j];
			} while (arr[j].size() > 8);
			
		}

		//sort names array
		insertionSort(arr, N);

		//read requests
		std::string tmp;
		int start = 0, end = N - 1;
		for (size_t k = 0; k < Q; k++)
		{
			std::cout << "Enter request: ";
			std::cin >> tmp;
			
			if (tmp.compare("ENTER") == 0)
			{
				std::cin >> start >> end;
			}
			else if (tmp.compare("QUERY") == 0)
			{
				std::string prefix;
				std::cin >> prefix;
				//search for prefix(es)
				std::cout << searchPrefix(start, end, arr, prefix) << std::endl;
			}
		}
	}
}

int main()
{
	processData();
	return 0;
}
