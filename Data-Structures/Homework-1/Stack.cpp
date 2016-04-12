#include "Stack.h"

Stack::Stack(int cap)
{
	capacity = cap;
	storage = new char[cap];
}

Stack::Stack()
{
	capacity = 4;
	storage = new char[4];
}

Stack::~Stack()
{
	delete[] storage;
}

void Stack::push(char element)
{
	//resize array if size is not enough
	if (topElement == capacity)
	{
		char * newStorage = new char[capacity*2];
		for (int i = 0; i < capacity; i++)
		{
			newStorage[i] = storage[i];
		}
		newStorage[topElement] = element;
		delete[] storage;
		this->storage = newStorage;
		capacity *= 2;
	}
	else
	{
		storage[topElement] = element;
	}

	topElement++;
}

char Stack::top()
{
	return storage[topElement - 1];
}

void Stack::pop()
{
	if (capacity < 1)
	{

	}
	else
	{
		topElement--;
	}

}

void Stack::printStack()
{
	for (size_t i = 0; i < topElement; i++)
	{
		std::cout << storage[i];
	}
}