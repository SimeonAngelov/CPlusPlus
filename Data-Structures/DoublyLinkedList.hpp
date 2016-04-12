#pragma once
#include <iostream>
template <class T> class DoublyLinkedList
{
private:
	struct Node{
		T data;
		Node* next;
		Node* prev;
	};

	Node* head;

public:
	DoublyLinkedList()
	{
		head = nullptr;

	}
	void addNode(T element)
	{
		Node* node = new Node;
		node->data = element;
		node->next = nullptr;

		if (head == nullptr)
		{
			node->prev = nullptr;
			head = node;
			return;
		}
		else
		{
			Node* tmp = head;
			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
			}
			tmp->next = node;
			node->prev = tmp;
		}
	}
	void removeNode(T element)
	{
		if (head->data == element && head->next == nullptr)
		{
			head = nullptr;
			return;
		}
		else if (head->data == element && head->next != nullptr)
		{
			Node* tmp = head->next;
			tmp->prev = nullptr;
			delete head;
			head = tmp;
			return;
		}

		Node* delNode = head;
		while (delNode->data != element)
		{
			if (delNode == nullptr)
				return;
			delNode = delNode->next;
		}

		if (delNode->next == nullptr)
		{
			Node* tmp = delNode->prev;
			tmp->next = nullptr;
			delete delNode;
			return;
		}

		//Correct prev pointer
		Node* tmp = delNode->next;
		tmp->prev = delNode->prev;

		//Correct next pointer
		Node* tmp2 = delNode->prev;
		tmp2->next = delNode->next;
	}
	void printList() const
	{
		if (head == nullptr)
			return;

		Node* tmp = head;
		while (tmp != nullptr)
		{
			std::cout << tmp->data << std::endl;
			tmp = tmp->next;
		}
	}
};
