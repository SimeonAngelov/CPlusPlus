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
	bool tmp = checkPos(pos, 1);
	return tmp;
}

bool boolVector::clear(int pos)
{
	bool tmp = checkPos(pos, 0);
	return tmp;
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

bool boolVector::checkPos(int pos, int param)
{
	if (pos < 0 || pos > 31)
	{
		return false;
	}
	vec[pos] = param;
	return true;
}
