#include <vector>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#include "heap.h"

using namespace std;

minHeap::minHeap() {
	size = 0;
	this->capacity = 20;
	this->heap.resize(20);
}

minHeap::minHeap(int capacity) {
	size = 0;
	this->capacity = capacity;
	this->heap.resize(capacity);
}

// Insert into the minHeap
void minHeap::insert(int data) {

	int input = data;
	// Make sure there is still space in the heap
	if (size >= capacity) {
		cout << "Heap is full!" << endl;
		return;
	}

	// Increse the amount of elements in the heap
	size++;

	// Insert the data at the end
	int current = size - 1;
	heap[current] = input;

	// Fix the min heap property
	// Moves the element up until i >= parent or root
	while (current != 0 && heap[parent(current)] > heap[current]) {
		swap(heap[current], heap[parent(current)]);
		current = parent(current);
	}
}

// Heapify function that bubbles down from top
void minHeap::heapify(int index) {

	//seting variables;
	int l = left(index);
	int r = right(index);
	int smallest = index;

	// bubble down only
	if ((l < size) && (heap[l] < heap[smallest])) {
		smallest = l;
	}
	if ((r < size) && (heap[r] < heap[smallest])) {
		smallest = r;
	}

	// swap portion
	if (smallest != index) {
		swap(heap[index], heap[smallest]);
		heapify(smallest);
	}

}


// Polls smallest/root data node
int minHeap::poll() {
	// Check if the heap is empty
	if (size == 0) {
		cout << "No items in heap!" << endl;
		return -1;
	}
	// size 1 heap
	else if (size == 1) {
		// we do not need to run heapify function
		size--;
		return heap[0];
	}
	// normal case
	else {
		int data = heap[0];
		size--;
		heap[0] = heap[size];
		heapify(0);
		return data;
	}

}

// printing data
void minHeap::printHeap() {
	cout << " | ";
	for (int i = 0; i != size; i++) {
		cout << heap[i] << " ";
	}
	cout << "|";
}

int minHeap::findIndex(int data) {
	int index = -1;
	for (int i = 0; i != size; i++) {
		if (heap[i] == data) {
			return i;
		}
	}

	return index;
}

int minHeap::remove(int index) {
	// Check if the heap is empty
	if (size == 0) {
		cout << "No items in heap!" << endl;
		return -1;
	}
	else if (index >= size) {
		cout << "Index not in heap!" << endl;
		return -1;
	}
	// size 1 heap
	else if (size == 1 && index == 0) {
		// we do not need to run heapify function
		size--;
		return heap[0];
	}
	// normal case
	else {
		int data = heap[index];
		size--;
		heap[index] = heap[size];
		heapify(index);
		return data;
	}
}
