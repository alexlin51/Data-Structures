#include <cstdlib>
#include <iostream>

#include "PQueue.h"

using namespace std;

PQueue::PQueue(int capacity) {
	minHeap temp(capacity);
	this->queue = temp;
}

void PQueue::enqueue(int data) {
	queue.insert(data);
}

int PQueue::dequeue() {
	int data = queue.poll();
	return data;
}

void PQueue::printQueue() {
	queue.printHeap();
}