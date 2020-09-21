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
		int bf;
	};

	node* root;

	node* createLeaf(int data);
	int max(int a, int b);
	void addEntry(int data, node* parent);
	int findBalanceFactor(node *n);
	
public:

	balanceTree(std::vector<int> list);

};

#endif