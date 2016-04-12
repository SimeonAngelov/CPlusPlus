#include "DoubleVector.h"
DoubleVector::DoubleVector()
{
	size = 0;
	dataVector = NULL;
}

DoubleVector::DoubleVector(int vecSize)
{
	this->size = vecSize;
	this->dataVector = new double[vecSize];
	initializeVector();
}

void DoubleVector::initializeVector()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter coordinate " << i << std::endl;
		std::cin >> this->dataVector[i];
	}
}

DoubleVector::DoubleVector(const DoubleVector& doubleVec)
{
	this->size = doubleVec.size;
	double* newArr = new double[size];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = doubleVec.dataVector[i];
	}
	this->dataVector = newArr;
}

DoubleVector::~DoubleVector()
{
	delete[] dataVector;
}

double DoubleVector::operator[](int position) const
{
	if (position < 0 || position >= size)
	{
		return 0;
	}
	else
	{
		return this->dataVector[position];
	}
}

DoubleVector& DoubleVector::operator*=(double num)
{
	for (int i = 0; i < size; i++)
	{
		dataVector[i] = dataVector[i] * num;
	}

	return *this;
}

DoubleVector DoubleVector::operator*(double num) const
{
	DoubleVector newVec(*this);
	newVec *= num;
	return newVec;
}

/*extend vector by fitst copying all the elements
from the current vector and then adding zeros for 
all the other elements until reaching desired size

Note:if (*this) accesses a false index it returns 0,
because of the operator[] predifinition
*/
void DoubleVector::extendVector(int vectorSize)
{
	double* newArr = new double[vectorSize];
	for (int i = 0; i < vectorSize; i++)
	{
		newArr[i] = (*this)[i];
	}

	delete[] dataVector;

	dataVector = newArr;
}
/* If the first vector is smaller than the second,
 we extend it with trailing zeros using the extendVector()
 method.
 If the second vector is smaller, the operator[] predifiniton 
 returns 0, if the accessed index is false, so we don't need
 to expand the second vector */
DoubleVector& DoubleVector:: operator+=(const DoubleVector& vec)
{
	if (this->size < vec.size)
	{
		extendVector(vec.size);
	}
	for (int i = 0; i < this->size; i++)
	{
		this->dataVector[i] += vec[i];
	}

	return *this;
}

DoubleVector DoubleVector:: operator+ (const DoubleVector& vec) const
{
	DoubleVector newVec(*this);
	newVec += vec;
	return newVec;
}

DoubleVector& DoubleVector:: operator= (const DoubleVector& vec)
{
	this->size = vec.size;
	double* arr = new double[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = vec.dataVector[i];
	}
	this->dataVector = arr;

	return *this;
}

DoubleVector& DoubleVector:: operator/= (double num)
{
	for (int i = 0; i < size; i++)
	{
		dataVector[i] = dataVector[i] / num;
	}

	return *this;
}

DoubleVector DoubleVector:: operator/ (double num) const
{
	DoubleVector newVec(*this);
	newVec /= num;
	return newVec;
}

DoubleVector& DoubleVector::operator-= (const DoubleVector& vec)
{
	if (this->size < vec.size)
	{
		extendVector(vec.size);
	}
	for (int i = 0; i < this->size; i++)
	{
		this->dataVector[i] -= vec[i];
	}

	return *this;
}

DoubleVector DoubleVector:: operator- (const DoubleVector& vec) const
{
	DoubleVector newVec(*this);
	newVec -= vec;
	return newVec;
}

double DoubleVector::operator%(const DoubleVector& vec)
{
	double scalarProduct = 0;
	if (this->size < vec.size)
	{
		extendVector(vec.size);
	}
	for (int i = 0; i < this->size; i++)
	{
		scalarProduct += this->dataVector[i] * vec[i];
	}

	return scalarProduct;
}

void DoubleVector::printVector()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "Coordinate [" << i <<"] : "<< dataVector[i] << std::endl;
		
	}
}