#pragma once

#include <iostream>
template<class T> class LinkedList
{
private:
	struct Node
	{
		Node* pNext;
		T data;
	};

	Node* head;
	Node* curr;
	Node* tmp;
public:
	LinkedList()
	{
		head = nullptr;
		curr = nullptr;
		tmp = nullptr;
	}
	void addData(T element)
	{
		Node* node = new Node;
		node->pNext = nullptr;
		node->data = element;
		
		if (head == nullptr)
		{
			head = node;
		}
		else
		{
			curr = head;
			while (curr->pNext != nullptr)
			{
				curr = curr->pNext;
			}
			curr->pNext = node;
		}
	}
	void removeElement(T element)
	{
		
		if (head->data == element)
		{
			tmp = head;
			head = head->pNext;
			delete tmp;
			return;
		}

		curr = head;
		tmp = head;
		while (curr->data != element)
		{
			if (curr->pNext == nullptr)
			{
				return;
			}
			tmp = curr;
			curr = curr->pNext;
		}
 		tmp->pNext = curr->pNext;
		delete curr;
	}
	void printList() const
	{
		curr = head;
		while (curr != nullptr)
		{
			std::cout << curr->data << std::endl;
			curr = curr->pNext;
		}

	}
};