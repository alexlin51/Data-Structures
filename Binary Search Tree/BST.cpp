#include <iostream>

#include "BST.h"

using namespace std;

BST::BST() {
	// we want to make sure the root pointer is null
	root = NULL;
}

BST::node* BST::createLeaf(int data) {
	// generate the new node and intialize the values
	node* n = new node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void BST::addLeaf(int data) {
	// run checks and call the private functions
	addLeafRecur(data, root);
}

void BST::addLeafRecur(int data, BST::node* ptr) {
	// if tree is empty
	if (root == NULL) {
		root = createLeaf(data);
	}
	// we need to compare otherwise
	else if (data < ptr->data) {
		if (ptr->left != NULL) {
			// traverse down left pointer
			addLeafRecur(data, ptr->left);
		}
		// if there isnt a node there, we create a node at the left side with data
		else {
			ptr->left = createLeaf(data);
		}
	}
	else if (data > ptr->data) {
		if (ptr->right != NULL) {
			// traverse down right pointer
			addLeafRecur(data, ptr->right);
		}
		else {
			ptr->right = createLeaf(data);
		}
	}
	else {
		cout << data << " has already been added to tree." << endl;
	}

}

void BST::printInOrder() {
	printInOrderRecur(root);
}

void BST::printInOrderRecur(BST::node* ptr) {
	// recursively move through tree
	if (root != NULL) {
		if (ptr->left != NULL) {
			printInOrderRecur(ptr->left);
		}
		cout << ptr->data << " ";
		if (ptr->right != NULL) {
			printInOrderRecur(ptr->right);
		}
	}
	else {
		cout << "Tree is empty." << endl;
	}
}

BST::node* BST::returnNode(int data) {
	// if empty root
	if (root == NULL) {
		node* ptr = NULL;
		return ptr;
	}
	return returnNodeRecur(data, root);
}

BST::node* BST::returnNodeRecur(int data, BST::node* ptr) {
	if (data < ptr->data) {
		// traverse left
		if (ptr->left != NULL) {
			return returnNodeRecur(data, ptr->left);
		}
		else {
			node* ptr = NULL;
			return ptr;
		}
	}
	else if (data > ptr->data) {
		// traverse right
		if (ptr->right != NULL) {
			return returnNodeRecur(data, ptr->right);
		}
		else {
			node* ptr = NULL;
			return ptr;
		}
	}
	else {
		// data is the same, we return this pointer
		return ptr;
	}
}

bool BST::doesExists(int data) {
	node* ptr = returnNode(data);
	if (ptr == NULL) {
		return false;
	}
	else {
		return true;
	}
}

int BST::returnRootData() {
	if (root == NULL) {
		return -1;
	}
	else {
		return root->data;
	}
}

void BST::printChildren(int data) {
	node* ptr = returnNode(data);

	if (ptr != NULL) {
		cout << "Parent Node = " << ptr->data << endl;

		if (ptr->left == NULL) {
			cout << "Left Child = NULL" << endl;
		}
		else {
			cout << "Left Child = " << ptr->left->data << endl;
		}

		if (ptr->right == NULL) {
			cout << "Right Child = NULL" << endl;
		}
		else {
			cout << "Right Child = " << ptr->right->data << endl;
		}
 
	}
	else {
		cout << "Key does not exist." << endl;
	}
}

int BST::findSmallest() {
	return findSmallestRecur(root);
}

int BST::findSmallestRecur(BST::node* ptr) {
	if (root == NULL) {
		cout << "Tree is empty. No small value returned.";
		return -1;
	}
	else {
		if (ptr->left != NULL) {
			return findSmallestRecur(ptr->left);
		}
		else {
			return ptr->data;
		}
	}
}

void BST::removeRoot() {
	node* delPtr;
	int matchData = root->data;
	int smallestInRight;

	// case no children
	if (root->right == NULL && root->left == NULL) {
		delPtr = root;
		delete delPtr;

		cout << "The root node containing " << matchData << " was removed." << endl;
		cout << "The new root is now " << root->data << "." << endl;
	}
	else if (root->left == NULL && root->right != NULL) {
		delPtr = root;
		root = root->right;
		delete delPtr;
	
		cout << "The root node containing " << matchData << " was removed." << endl;
		cout << "The new root is now " << root->data << "." << endl;

	}
	else if (root->left != NULL && root->right == NULL) {
		delPtr = root;
		root = root->left;
		delete delPtr;
		
		cout << "The root node containing " << matchData << " was removed." << endl;
		cout << "The new root is now " << root->data << "." << endl;
	}
	else {
		smallestInRight = findSmallestRecur(root->right);
		removeNodeRecur(smallestInRight, root);
		root->data = smallestInRight;

		cout << "The root node containing " << matchData << " was removed." << endl;
		cout << "The new root is now " << root->data << "." << endl;
	}
}

void BST::removeMatch(BST::node* parent, BST::node* child, bool choice) {

	if (root != NULL) {
		node* delPtr;
		int matchData = child->data;
		int smallestInRight;

		// case no children
		if (child->right == NULL && child->left == NULL) {
			delPtr = child;
			
			if (choice == true) {
				parent->left = NULL;
			}
			else {
				parent->right = NULL;
			}

			delete delPtr;
			cout << "The node containing " << matchData << " was removed." << endl;

		}
		else if (child->left == NULL && child->right != NULL) {
			delPtr = child;

			if (choice == true) {
				parent->left = child->right;
			}
			else {
				parent->right = child->right;
			}

			child->right = NULL;
			delete delPtr;
			cout << "The node containing " << matchData << " was removed." << endl;
		}
		else if (child->left != NULL && child->right == NULL) {
			delPtr = child;

			if (choice == true) {
				parent->left = child->left;
			}
			else {
				parent->right = child->left;
			}

			child->left = NULL;
			delete delPtr;
			cout << "The node containing " << matchData << " was removed." << endl;
		}
		else {
			smallestInRight = findSmallestRecur(child->right);
			removeNodeRecur(smallestInRight, child);
			child->data = smallestInRight;

		}

	}

}

void BST::removeNode(int data) {
	removeNodeRecur(data, root);
}

void BST::removeNodeRecur(int data, BST::node* parent) {
	if (root == NULL) {
		cout << "Cannot remove from empty tree." << endl;
		return;
	}
	else {
		if (root->data == data) {
			removeRoot();
		}
		else {
			if (data < parent->data && parent->left != NULL) {
				// traverse left
				if (parent->left->data == data) {
					removeMatch(parent, parent->left, true);
				}
				else {
					removeNodeRecur(data, parent->left);
				}
			}
			else if (data > parent->data && parent->right != NULL) {
				// traverse right
				if (parent->right->data == data) {
					removeMatch(parent, parent->right, false);
				}
				else {
					removeNodeRecur(data, parent->right);
				}
			}
			else {
				cout << "Data is not in tree." << endl;
			}
		}
	}
}

void BST::removeTree(node* ptr) {
	if (ptr != NULL) {
		if (ptr->left != NULL) {
			removeTree(ptr->left);
		}
		if (ptr->right != NULL) {
			removeTree(ptr->right);
		}

		cout << "Deleted node with data = " << ptr->data << endl;
		delete ptr;
	}
}

BST::~BST() {
	removeTree(root);
}