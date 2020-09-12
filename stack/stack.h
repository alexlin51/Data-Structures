#ifndef STACK_H
#define STACK_H
#include "List.h"

class Stack {
private:

	List stackList;

public:

	Stack(); // creation of a list for stack
	void pop();
	void push(string data);
	void viewStack();
	int stackSize();

};


#endif