#pragma once
#include <iostream>
template <class T> class Sorted
{
	int capacity;
	int size;
	T* arr;
public:
	Sorted();
	~Sorted();
	Sorted(const Sorted& vec);

	void add(T& element);
	void remove(T& element);
	void print();
	void BubbleSort();
	Sorted<T>& operator= (const Sorted<T>& vec);
};

template<class T> Sorted<T>::Sorted()
{
	capacity = 4;
	size = 0;
	arr = new T[capacity];
}
template<class T> Sorted<T>::~Sorted()
{
	delete[] arr;
}
template<class T> Sorted<T>::Sorted(const Sorted& vec)
{
	capacity = vec.capacity;
	size = vec.size;
	T* tmpArr = new T[capacity];
	for (int i = 0; i < vec.size; i++)
	{
		tmpArr[i] = vec.arr[i];
	}
	arr = tmpArr;
}

template<class T> void Sorted<T>::add(T& element)
{
	if (size > 127) return;

	size++;
	/*if elements are more than the capacity, double the capacity
	by first creating a new array, the copying the old one into the new,
	deleting the old array and setting the pointer to the new array
	*/
	if (size > capacity)
	{
		T* newArr = new T[capacity * 2];
		for (int i = 0; i < capacity; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
		capacity *= 2;
	}

	arr[size - 1] = element;
	this->BubbleSort();
}
template<class T> void Sorted<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}
template<class T> void Sorted<T>::remove(T& element)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == element)
		{
			index = i;
		}
	}

	//check if the element exists in the array
	if (index < 0) return;

	//make a new array and copy all the except the one to be removed
	T* newArr = new T[capacity];
	for (int i = 0; i < index; i++)
	{
		newArr[i] = arr[i];
	}

	for (int i = index + 1; i < size; i++)
	{
		newArr[i - 1] = arr[i];
	}
	size--;
	delete[] arr;
	arr = newArr;
}
template<class T> void Sorted<T>::BubbleSort()
{
	int i, j, flag = 1;    // set flag to 1 to start first pass
	int temp;             // holding variable
	int numLength = this->size;
	for (i = 1; (i <= numLength) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (numLength - 1); j++)
		{
			if (this->arr[j + 1] > this->arr[j])      // ascending order simply changes to <
			{
				temp = this->arr[j];             // swap elements
				this->arr[j] = this->arr[j + 1];
				this->arr[j + 1] = temp;
				flag = 1;               // indicates that a swap occurred.
			}
		}
	}
	return;   //arrays are passed to functions by address; nothing is returned
}
template<class T> Sorted<T>& Sorted<T>::operator= (const Sorted<T>& vec)
{
	this->size = vec.size;
	this->capacity = vec.capacity;
	T* newArr = new T[size];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = vec.arr[i];
	}
	this->arr = newArr;

	return *this;
}

