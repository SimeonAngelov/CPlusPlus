#include <iostream>

using namespace std;

bool checkPrime(int n)
{
	if (n == 1 || n == 0) return false;
	bool isPrime = true;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			isPrime = false;
		}	
	}

	return isPrime;
}

int main(){
	cout << "Enter n: \n";
	int n;
	cin >> n;
	
	cout << "Enter m: \n";
	int m;
	cin >> m;


	int sumOfPrimeDivisers = 0;
	//itterate througn [n,m]
	for (int i = n; i <= m; i++)
	{
		int sumOfDivisors = 0;
		//find sum of divisor with inner loop
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				sumOfDivisors += j;
			}
		}
		if (checkPrime(sumOfDivisors)){
			sumOfPrimeDivisers++;
		}
	}
	cout << "Sum of Prime divisors is: " << sumOfPrimeDivisers;
		return 0;
}
