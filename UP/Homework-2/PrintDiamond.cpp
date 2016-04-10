#include <iostream> 

//Pass 1 for even and 0 for odd
void printBottomPart(int even, int n)
{
	for (int row = n / 2 - 1; row >= 0; row--)
	{
		for (int col = 0; col < n; col++)
		{
			if (col + even >= (n / 2 - row) && col <= (n / 2 + row))
			{
				std::cout << col + 1;
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}
void printTopPart(int even, int n)
{
	if (n % 2 == 0){
		for (int row = 0; row + even <= n / 2; row++)
		{
			for (int col = 0; col < n; col++)
			{
				if (col + even >= (n / 2 - row) && col <= (n / 2 + row))
				{
					std::cout << col + 1;
				}
				else
				{
					std::cout << " ";
				}
			}
			std::cout << std::endl;
		}
	}
}

int main()
{
	int n;
	std::cout << "Enter n:";
	std::cin >> n;

	if (n % 2 == 0){
		printTopPart(1, n);
		printBottomPart(1, n);
	}
	else {
		printTopPart(0, n);
		printBottomPart(0, n);
	}
	return 0;
}
