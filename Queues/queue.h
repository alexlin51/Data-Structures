#ifndef QUEUE_H
#define QUEUE_H
#include "List.h"

#include <string>

class Queue {
private:

	List stackList;

public:

	Queue(); // creation of a list for stack
	int size();
	bool isEmpty();
	int peek();
	void enqueue(int data);
	int dequeue();
	void showAll();

};


#endif