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
	// we are able to keep this root like this because it will always return the root
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

int balanceTree::smallest(node* pointer) {
	while (pointer->left != NULL) {
		return smallest(pointer->left);
	}
	return pointer->data;
}

int balanceTree::findSmallest() {
	return smallest(root);
}

int balanceTree::largest(node* pointer) {
	while (pointer->right != NULL) {
		return largest(pointer->right);
	}
	return pointer->data;
}

int balanceTree::findLargest() {
	return largest(root);
}

bool balanceTree::containsRecur(int data, node* point) {
	if (point == NULL) {
		return false;
	}
	
	if (data < point->data) {
		return containsRecur(data, point->left);
	}
	else if (data > point->data) {
		return containsRecur(data, point->right);
	}
	else {
		return true;
	}

}

bool balanceTree::contains(int data) {
	return containsRecur(data, root);
}

balanceTree::node* balanceTree::minValue(node* p) {
	node* trav = p;

	while (trav->left != NULL) {
		trav = trav->left;
	}

	return trav;
}

balanceTree::node* balanceTree::deleteEntry(int data, node* point) {
	if (point == NULL) {
		return point;
	}

	if (data < point->data) {
		//traverse left
		point->left = deleteEntry(data, point->left);
	}
	else if (data > point->data) {
		//travese right
		point->right = deleteEntry(data, point->right);
	}
	else {
		// this is the equal spot!
		
		// lets first check for a single child case or no child case
		if (point->left == NULL || point->right == NULL) {
			node* traveler;
			if (point->left == NULL) {
				traveler = point->right;
			}
			else {
				traveler = point->left;
			}

			// if no children
			if (traveler == NULL) {
				traveler = point;
				point = NULL;
			}
			else {
				*point = *traveler;
			}
			free(traveler);

		}
		else {
			// this is a double child case
			node* traveler = minValue(point->right);
			point->data = traveler->data;

			point->right = deleteEntry(traveler->data, point->right);

		}
	}

	if (point == NULL) {
		return point;
	}


	// balancing portion, as this pulls out, things should balance out.
	point->height = max(height(point->left), height(point->right)) + 1;
	bf = findBalanceFactor(point);


	// if portion for balance factor
	if (bf > 1) {
		// the left side if bigger
		// we have 2 situtaions for both
		if (findBalanceFactor(point->left) >= 0) {
			//this is the case where Leftleft
			return rotateRight(point);
		}
		else if (findBalanceFactor(point->left) < 0) {
			// this is the left right case
			point->left = rotateLeft(point->left);
			return rotateRight(point);
		}
	}
	if (bf < -1) {
		// the right side of bigger
		if (findBalanceFactor(point->right) <= 0) {
			// this is the right right case
			return rotateLeft(point);
		}
		else if (findBalanceFactor(point->right) > 0) {
			// this is the right left case
			point->right = rotateRight(point->right);
			return rotateLeft(point);
		}
	}
	return point;
}

void balanceTree::remove(int data) {
	bool exists = contains(data);
	if (exists) {
		deleteEntry(data, root);
	}
}