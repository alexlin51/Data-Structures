#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

int main() {

	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };

	BST myTree;

	myTree.printInOrder();

	for (int i = 0; i != 16; i++) {
		cout << TreeKeys[i] << " ";
	}
	cout << endl;

	for (int i = 0; i != 16; i++) {
		myTree.addLeaf(TreeKeys[i]);
	}
	
	myTree.printInOrder();
	myTree.removeNode(100);


	bool test = myTree.doesExists(76);

	if (test == true) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}


	// lets see all the child and parent nodes.

	for (int i = 0; i != 16; i++) {
		myTree.printChildren(TreeKeys[i]);
	}
	
	cout << myTree.findSmallest() << endl;

	myTree.printInOrder();
	myTree.removeNode(50);
	
	for (int i = 0; i != 16; i++) {
		myTree.printChildren(TreeKeys[i]);
	}

	myTree.printInOrder();

	cout << endl;


}