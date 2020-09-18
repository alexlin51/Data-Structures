#ifndef BST_H
#define BST_H

class BST {
private:
	
	struct node {
		int data;
		node* left;
		node* right;
	};

	node* root;
	void addLeafRecur(int key, node* ptr);
	void printInOrderRecur(node* ptr);
	node* returnNodeRecur(int data, node* ptr);
	node* createLeaf(int data);	// generate the new node and intialize the values
	node* returnNode(int data);	// will return a pointer if node exists, otherwise NULL
	int findSmallestRecur(node* ptr);
	void removeNodeRecur(int data, node* parent);
	void removeRoot(); // remove the root node
	void removeMatch(node* parent, node* child, bool choose); // remove the matched node
	void removeTree(node* ptr);

public:
	BST(); // we want to make sure the root pointer is null
	~BST(); // deconstructor
	void addLeaf(int key); // run checks and call the private functions
	void printInOrder(); // will print the tree in order...
	bool doesExists(int data); // return boolean if node exists.
	int returnRootData(); // return the root data
	void printChildren(int data); // print the children values of data spot
	int findSmallest(); // returns the smallest 
	void removeNode(int data); // wil remove the node with this data

};

#endif