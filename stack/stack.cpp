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

void Stack::push(int data) {
	this->stackList.AddEnd(data);
}

void Stack::viewStack() {
	this->stackList.ViewList();
}

void Stack::stackSize() {
	this->stackList.ListSize();
}