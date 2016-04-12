#pragma once
#include <iostream>
class DoubleVector
{
private: 
	double* dataVector;
	int size;
public:
	DoubleVector();
	DoubleVector(int size);
	~DoubleVector();
	DoubleVector(const DoubleVector&);
	DoubleVector& operator=(const DoubleVector&);
	double operator[](int) const;
	DoubleVector& operator*= (double);
	DoubleVector operator* (double) const;
	DoubleVector& operator+=  (const DoubleVector&);
	DoubleVector operator+ (const DoubleVector&) const;
	void extendVector(int);
	DoubleVector  operator/ (double num) const;
	DoubleVector&  operator/= (double num);
	DoubleVector& operator -= (const DoubleVector&);
	DoubleVector operator- (const DoubleVector&) const;
	double operator% (const DoubleVector&);
	void initializeVector();
	void printVector();
};
