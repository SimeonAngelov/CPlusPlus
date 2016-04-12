#include "Stack.h"
#include <string>

char* reverseString(std::string &str)
{
	char* arr = new char[str.length()+1];
	for (size_t i = 0; i < str.length(); i++)
	{
		arr[i] = str[str.length() - i - 1];
	}
	arr[str.length()] = '\0';
	return arr;
}

void readString(char* str)
{
	Stack stack;

	//push everything in to stack
	int counter = 0;
	while (str[counter] != '\0')
	{
		stack.push(str[counter]);
	
		/*If ')' is encoutared pop it and then pop the string
		that should be processed and save it in str,
		until we meet '('. Then pop the integer.*/
		std::string str2 = "";
		if (str[counter] == ')'){
			//pop the ')'
			stack.pop();

			//read the string
			while (stack.top() != '(')
			{
				str2 += stack.top();
				stack.pop();
			}
			//pop the '(' and reverse the string
			stack.pop();
			char* stringArr = reverseString(str2);

			//read the integer using the asscci table 
			std::string intStr = "";
			while (stack.top() > 47 && stack.top() < 58)
			{
				intStr += stack.top();
				stack.pop();
			}
			//reverse the string and convert it to int
			char* intArr = reverseString(intStr);
			int stringCount = atoi(intArr);
			//push the string in to stack stringCount times
			for (int i = 0; i < stringCount;i++)
			{
				int count = 0;
				while (stringArr[count] != '\0')
				{
					stack.push(stringArr[count]);
					count++;
				}
			}
		}
		counter++;
	}

	stack.printStack();
}

int main()
{
	//read string 
	char buffer[100];
	std::cin.getline(buffer, 100);
	readString(buffer);
	

	return 0;
}
