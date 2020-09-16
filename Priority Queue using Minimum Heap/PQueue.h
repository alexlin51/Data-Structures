#ifndef PQUEUE_H
#define PQUEUE_H

#include "heap.h"

class PQueue{

private: 

	minHeap queue;
	

public:
	PQueue(int number);
	void enqueue(int data);
	int dequeue();
	void printQueue();

};

#endif PQUEUE_H