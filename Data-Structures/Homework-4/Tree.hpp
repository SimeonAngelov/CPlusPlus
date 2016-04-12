#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <string>

class Tree{
	struct Node
	{
		int val;
		std::vector<Node*> children;
		std::string tupleName;
	};
	Node* root;
	void destroyTree(Node* node)
	{
		if (node != nullptr)
		{
			for (size_t i = 0; i < node->children.size(); i++)
			{
				destroyTree(node->children[i]);
				delete node;
			}
		}
	}
public:
	Node* getRoot()
	{
		return root;
	}
	Tree()
	{
		root = nullptr;
	}
	~Tree()
	{
		destroyTree(root);
	}

	/*The function looks for the symbols":
	"(" - if it is encountered it reads a number and
	creates a new node and adds it to the stack. The node that
	is always on the top of the stack is the node we add the children to.
	If we encounter "}" then we are done with it and pop it from the stack.
	"*/
	void readEntry(std::string str)
	{
		std::stack<Node*> nodes;
		int index = 0;
		
		while (str.size() > index)
		{
			//if "("is read advace to the nubmer with index++
			if (str[index] == '(')
			{
				index++;

				//read the number
				std::string num;
				while (str[index] < 58 && str[index] > 47)
				{
					num += str[index];
					if (str[index + 1] < 58 && str[index + 1] > 47)
						index++;
					else 
						break;
				}
				//set the node value with the number
				Node* tmp = new Node;
				tmp->val = atoi(num.c_str());

				//If tree is empty add a root,
				//otherwise add a child to the current node.
				if (root == nullptr)
				{
					root = tmp;
				}
				else
				{
					nodes.top()->children.push_back(tmp);
				}

				nodes.push(tmp);
					
				//read " " and "{" and move to next charachter
				index+= 3;
			}
			//if "}" is read then we are done with it and pop it from the stack
			else if (str[index] == '}')
			{
				nodes.pop();
				index++;
			}
			else
			{
				//if none of the above symbols are encountered skip the symbol
				index++;
			}
		}
	}
	void insertionSort(std::vector<Node*> arr, int size)
	{
		std::string tmp;
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j > 0; j--)
			{
				int a = atoi(arr[j]->tupleName.c_str());
				int b = atoi(arr[j - 1]->tupleName.c_str());
				if (a < b)
				{
					tmp = arr[j - 1]->tupleName;
					arr[j - 1]->tupleName = arr[j]->tupleName;
					arr[j]->tupleName = tmp;
				}
			}
		}
	}
	/*Use AHU algorithm to determine if trees are isomorphic.
	Assign "10" value to all the leafes, the when comming back from
	the recursion sort the names of all the leaves concatenate them and
	give the parent the concatenated name + "1" at the beggining and "0" at the end*/
	void assignKnutTuples(Node* node)
	{
		if (node->children.size() == 0)
		{
			node->tupleName = "10";
		}
		else
		{
			for (size_t i = 0; i < node->children.size(); i++)
			{
				assignKnutTuples(node->children[i]);
			}

			insertionSort(node->children, node->children.size());

			for (size_t i = 0; i < node->children.size(); i++)
			node->tupleName += node->children[i]->tupleName;

			node->tupleName = "1" + node->tupleName + "0";
		}
	}
};
