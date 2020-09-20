#ifndef FENWICK_H
#define FENWICK_H

#include <vector>

class fenwickTree {
private:

	int size;
	std::vector<int> BITree;
	std::vector<int> Listing;

	void updateTree(int index, int data);

public:

	fenwickTree(std::vector<int> list);
	int sum(int index); // return the sum from beginning.
	int sumRange(int index1, int index2);
	void replace(int index, int data);
	void printTree();

};

#endif