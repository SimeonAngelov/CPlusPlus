#include<iostream>

int main()
{
	int n;
	std::cout << "Enter N:";
	std::cin >> n;
	unsigned long long automorphicNum = 1, tmp;
	int numOfDigits;

	//The outter cicle executes until n automorphic numbers are found.
	//If an automorphic number is found n is decremented by 1.
	//The inner cicle counts the digits of the number. If the number has 1 digit
	//numOfDigits becomes 10 and we check if the last digit 
	//of n^2 is the same with %numOfDigits,
	//if n has two digits numOfDigits becomes 100 and we check 
	//if the last two digits are the same and so on.
	while (n != 0)
	{
		
		numOfDigits = 1;
		tmp = automorphicNum;
		while (tmp != 0)
		{
			numOfDigits *= 10;
			tmp /= 10;
		}
		if (((automorphicNum*automorphicNum) % numOfDigits) == automorphicNum)
		{
			std::cout << automorphicNum << endl;
			n--;
		}
		automorphicNum++;
	}

	return 0;
}
