#include <cstdlib>
#include <iostream>

#include "stack.h"	

using namespace std;

Stack::Stack() {
	List stackList;
}

void Stack::pop() {
	this->stackList.DelEnd();
}

void Stack::push(string input) {
	this->stackList.AddEnd(input);
}

void Stack::viewStack() {
	this->stackList.ViewList();
}

int Stack::stackSize() {
	int size = this->stackList.ListSize();
	return size;
}
