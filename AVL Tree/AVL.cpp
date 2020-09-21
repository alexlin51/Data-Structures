#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#include "AVL.h"

using namespace std;

int balanceTree::max(int a, int b) {
	return (a >= b) ? a : b;
}

balanceTree::node* balanceTree::createLeaf(int data) {
	node* n = new node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	n->height = 1;
	n->bf = 0;
	
	return n; 
}

int balanceTree::findBalanceFactor(node *spot) {
	if (spot == NULL) {
		return 0;
	}
	else {
		return (spot->left->height - spot->right->height);
	}
}

void balanceTree::addEntry(int data, node* point) {
	if (root == NULL) {
		root = createLeaf(data);
		return;
	}

	if (point == NULL) {
		point = createLeaf(data);
	}
	else if (data < point->data) {
		// traverse left side
		addEntry(data, point->left);
	}
	else if (data > point->data) {
		addEntry(data, point->right);
	}
	else {
		// no same number in this tree I guess.
		return; 
	}

	// balancing portion, as this pulls out, things should balance out.
	point->height = max(point->left->height, point->right->height) + 1;
	point->bf = findBalanceFactor(point);


	// if portion for balance factor
	if (point->bf > 1) {
		// the left side if bigger
		// we have 2 situtaions for both
		if (data < point->left->data) {
			//this is the case where Leftleft

		}
		else if (data > point->left->data) {
			// this is the left right case

		}
	}
	if (point->bf < 1) {
		// the right side of bigger
		if (data > point->right->data) {
			// this is the right right case

		}
		else if (data < point->right->data){
			// this is the right left case

		}
	}
}

balanceTree::balanceTree(vector<int> list) {

	for (int i = 0; i != list.size(); i++) {
		addEntry(list[i], root);
	}
}