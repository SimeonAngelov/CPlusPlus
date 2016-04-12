#pragma once
#include <iostream>
class Stack
{
private:
	int topElement = 0;
	int capacity;
	char* storage;

public:
	Stack(int cap);
	Stack();
	~Stack();
	void push(char element);
	void pop();
	char top();
	void printStack();
};