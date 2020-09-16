#ifndef HEAP_H
#define HEAP_H

#include <vector>

class minHeap {
private:
	int size;
	int capacity;
	std::vector<int> heap;

	// these take in an index and return an index!
	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}

public:
	minHeap();
	minHeap(int capacity);
	void insert(int data);
	void heapify(int index);
	int poll();
	void printHeap();
	int findIndex(int data);
	int remove(int index);
};

#endif