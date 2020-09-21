#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#include "AVL.h"

using namespace std;

int balanceTree::max(int a, int b) {
	return (a >= b) ? a : b;
}

int balanceTree::height(node* point) {
	if (point == NULL) {
		return 0;
	}
	else {
		return point->height;
	}
}

balanceTree::node* balanceTree::createLeaf(int data) {
	node* n = new node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	n->height = 1;

	return n;
}

int balanceTree::findBalanceFactor(node* spot) {
	if (spot == NULL) {
		return 0;
	}
	else {
		return (height(spot->left) - height(spot->right));
	}
}

balanceTree::node* balanceTree::rotateRight(node* point) {
	node* traveler = point->left;
	point->left = traveler->right;
	traveler->right = point;

	point->height = max(height(point->left), height(point->right)) + 1;
	traveler->height = max(height(traveler->left), height(traveler->right)) + 1;

	return traveler;
}

balanceTree::node* balanceTree::rotateLeft(node* point) {
	node* traveler = point->right;
	point->right = traveler->left;
	traveler->left = point;

	point->height = max(height(point->left), height(point->right)) + 1;
	traveler->height = max(height(traveler->left), height(traveler->right)) + 1;

	return traveler;
}

balanceTree::node* balanceTree::addEntry(int data, node* point) {

	if (point == NULL) {
		return createLeaf(data);
	}
	
	if (data < point->data) {
		// traverse left side
		point->left = addEntry(data, point->left);
	}
	else if (data > point->data) {
		point->right = addEntry(data, point->right);
	}
	else {
		// no same number in this tree I guess.
		return point;
	}

	// balancing portion, as this pulls out, things should balance out.
	point->height = max(height(point->left), height(point->right)) + 1;
	bf = findBalanceFactor(point);


	// if portion for balance factor
	if (bf > 1) {
		// the left side if bigger
		// we have 2 situtaions for both
		if (data < point->left->data) {
			//this is the case where Leftleft
			return rotateRight(point);
		}
		else if (data > point->left->data) {
			// this is the left right case
			point->left = rotateLeft(point->left);
			return rotateRight(point);
		}
	}
	if (bf < -1) {
		// the right side of bigger
		if (data > point->right->data) {
			// this is the right right case
			return rotateLeft(point);
		}
		else if (data < point->right->data) {
			// this is the right left case
			point->right = rotateRight(point->right);
			return rotateLeft(point);
		}
	}
	return point;
}

balanceTree::balanceTree(vector<int> list) {
	root = NULL;

	for (int i = 0; i != list.size(); i++) {
		root = addEntry(list[i], root);
	}
}

void balanceTree::printRecur(node* point) {
	if (point != NULL) {
		printRecur(point->left);
		cout << point->data << " ";
		printRecur(point->right);
	}
}

void balanceTree::printOrder() {
	if (root != NULL) {
		printRecur(root);
	}
}

void balanceTree::add(int data) {
	root = addEntry(data, root);
}