#pragma once
#include <iostream>
class boolVector
{
	bool* vec;
public:
	boolVector();
	~boolVector();
	boolVector(const boolVector&);

	boolVector& operator=(const boolVector& vec);
	int operator[](int pos) const;

	bool set(int pos);
	bool clear(int pos);

	void initializeVector();
	void printVector();
	bool checkPos(int pos, int param);
};