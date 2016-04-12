#include "boolVector.h"

boolVector::boolVector()
{
	vec = new bool[32];
	initializeVector();
}

boolVector::~boolVector()
{
	delete[] vec;
}

boolVector::boolVector(const boolVector& newVec)
{
	bool* arr = new bool[32];
	for (int i = 0; i < 32; i++)
	{
		arr[i] = newVec.vec[i];
	}
	this->vec = arr;
}

boolVector& boolVector::operator=(const boolVector& newVec)
{
	bool* arr = new bool[32];
	for (int i = 0; i < 32; i++)
	{
		arr[i] = newVec.vec[i];
	}
	this->vec = arr;

	return*this;
}

int boolVector::operator[](int position) const
{
	if (position < 0 || position > 31)
	{
		return -1;
	}
	else
	{
		return this->vec[position];
	}
}

bool boolVector::set(int pos)
{
	if (pos < 0 || pos > 31)
	{
		return false;
	}

	vec[pos] = 1;
	return true;
}

bool boolVector::clear(int pos)
{
	if (pos < 0 || pos >31)
	{
		return false;
	}

	vec[pos] = 0;
	return true;
}

void boolVector::initializeVector()
{
	for (int i = 0; i < 32; i++)
	{
		std::cout << "Enter coordinate " << i << std::endl;
		std::cin >> vec[i];
	}
}

void boolVector::printVector()
{
	for (int i = 0; i < 32; i++)
	{
		std::cout << "Coordinate [" << i << "] : " << vec[i] << std::endl;

	}
}