#include <iostream>

#include "unionfind.h"

using namespace std;

unionFind::unionFind(int size) {
	// ensure the size is not less than zero
	if (size <= 0) {
		cout << "Cannot create a size 0 Unionfind Structure" << endl;
	}
	else {
		// intialize the two arrays systems
		this->numGroups = size;
		this->sizeTracker.resize(size);
		this->parent.resize(size);

		//fill the arrays with the necessary inital values. 
		for (int i = 0; i != size; i++) {
			this->sizeTracker[i] = 1;
			this->parent[i] = i;
		}

	}

}

int unionFind::findRoot(int index) {
	// find the root value
	int root = index;
	while (root != parent[root]) {
		root = this->parent[root];
	}

	// we can use this time to also path compress in order to take advantage of the amortized time complexity
	while (index != root) {
		int temp = this->parent[index];
		this->parent[index] = root;
		index = temp;
	}

	return root;

}

bool unionFind::isConnected(int p1, int p2) {
	int root1 = findRoot(p1);
	int root2 = findRoot(p2);

	if (root1 != root2) {
		return false;
	}
	else {
		return true;
	}
}

int unionFind::groupSize(int index) {
	int root = findRoot(index);
	int data = this->sizeTracker[root];
	return data;
}

int unionFind::dataSize() {
	return this->size;
}

int unionFind::groupsLeft() {
	return this->numGroups;
}

void unionFind::unify(int p1, int p2) {
	// We need to combine two groups wow!
	int root1 = findRoot(p1);
	int root2 = findRoot(p2);

	if (root1 != root2) {
		if (sizeTracker[root1] < sizeTracker[root2]) {
			sizeTracker[root2] += sizeTracker[root1];
			parent[root1] = root2;
		}
		else {
			sizeTracker[root1] += sizeTracker[root2];
			parent[root2] = root1;
		}

		this->numGroups--;
	}
	else {
		cout << "Nodes already in the same group!" << endl;
	}
}