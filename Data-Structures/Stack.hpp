#pragma once
#include <iostream>
template<class T> class Stack
{
private:
	int topElement = 0;
	int capacity;
	T* storage;

public:
	Stack(int cap)
	{
		capacity = cap;
		storage = new T[cap];
	}
	Stack()
	{
		capacity = 4;
		storage = new T[4];
	}
	~Stack()
	{
		delete[] storage;
	}
	void push(T element)
	{
		{
			//resize array if size is not enough
			if (topElement == capacity)
			{
				T * newStorage = new T[capacity * 2];
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
	}
	void pop()
	{
		if (capacity < 1)
		{

		}
		else
		{
			topElement--;
		}

	}
	T top() const
	{
		return storage[topElement - 1];
	}
	//for testing purposes
	void printStack() const
	{
		for (size_t i = 0; i < topElement; i++)
		{
			std::cout << storage[i];
		}
		std::cout << std::endl;
	}
};