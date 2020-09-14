#include <cstdlib>
#include <iostream>

#include "queue.h"	

using namespace std;

Queue::Queue() {
	List stackList;
}

int Queue::size() {
	return this->stackList.ListSize();
}

bool Queue::isEmpty() {
	if (this->stackList.ListSize() == 0) {
		return true;
	}
	else {
		return false;
	}
}

int Queue::peek() {
	return this->stackList.First();
}

void Queue::enqueue(int data) {
	this->stackList.AddEnd(data);
}

int Queue::dequeue() {
	int data = stackList.First();
	this->stackList.PullNode(0);
	return data;

}

void Queue::showAll() {
	this->stackList.ViewList();
}