#include <iostream>
#include <cstdlib>
#include <vector>

#include "fenwick.h"

using namespace std;

void fenwickTree::updateTree(int index, int data) {

	// we are given an index, as well as data from this index in the recived list.
	int BITIndex = index + 1;

	while (BITIndex < size){
		BITree[BITIndex] += data;

		// After adding the index to sum, we need to move the index.
		// this is BIT manipuation, https://www.youtube.com/watch?v=uSFzHCZ4E-8 , 6:15 to understand.
		// adding is moving up into ancestors.
		BITIndex += BITIndex & (-BITIndex);
	}
	

}

fenwickTree::fenwickTree(vector<int> list) {

	// assumes that input list will not have 0 as first index, we will add that. 
	// copy old list as well
	size = list.size();
	BITree.resize(size + 1);
	Listing.resize(size);
	BITree[0] = NULL;
	for (int i = 0; i != size; i++) {
		BITree[i + 1] = 0;
		Listing[i] = list[i];
	}

	// we now have a BITree array with { NULL, 0, ...}
	// lets run update to each one.
	for (int i = 0; i != size; i++) {
		updateTree(i, list[i]);
	}

}

int fenwickTree::sum(int index) {
	// we will sum from 1st index to index given
	if (index >= size) {
		return 0;
	}

	int sum = 0;

	int BITIndex = index + 1;

	while (BITIndex > 0) {
		sum += BITree[BITIndex];
		
		// Now we need to traverse down the tree
		BITIndex -= BITIndex & (-BITIndex);
	}

	return sum;

}

int fenwickTree::sumRange(int index1, int index2) {
	if (index2 < index1) {
		return 0;
	}

	// we have to use the index previous for first value.
	int sum1 = sum(index1 - 1);
	int sum2 = sum(index2);

	return sum2 - sum1;

}

void fenwickTree::replace(int index, int data) {
	// make sure index works
	if (index >= size) {
		return;
	}

	int BITIndex = index + 1;
	int original = Listing[index];
	while (BITIndex < size) {
		BITree[BITIndex] -= original;
		BITree[BITIndex] += data;

		BITIndex += BITIndex & (-BITIndex);
	}

}

void fenwickTree::printTree() {
	for (int i = 0; i != size; i++) {
		cout << BITree[i + 1] << " ";
	}
}