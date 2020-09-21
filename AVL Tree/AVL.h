#ifndef AVL_H
#define AVL_H

#include <vector>
#include <string>


// Alright, lets build a balanced binary tree
class balanceTree {
private:
	// let's first establish a struct system
	struct node {
		int data;
		int height;
		node* left;
		node* right;
	};

	int bf;
	node* root;

	node* createLeaf(int data);
	int max(int a, int b);
	node* addEntry(int data, node* parent);
	int findBalanceFactor(node* n);
	node* rotateRight(node* point);
	node* rotateLeft(node* point);
	void printRecur(node* point);
	int height(node* point);

public:

	balanceTree(std::vector<int> list);
	void printOrder();
	void add(int data);

};

#endif