#ifndef STACK_H
#define STACK_H
#include "List.h"

#include <string>

class Stack {
private:

	List stackList;

public:

	Stack(); // creation of a list for stack
	void pop();
	void push(std::string data); // interesting, we need to add the string data here first.
	void viewStack();
	int stackSize();
	std::string peek();

};


#endif