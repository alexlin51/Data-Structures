#ifndef LIST_H
#define LIST_H

#include <string>


class List {
private:   // private can only be accesssed by the public functions.
	// We need a node structure
	struct node {
		int data;	// unique data for each.
		// double linked list so we need pointers to next and previous node.
		node* next;
		node* prev;
	};

	// every time we type nodePtr, it creates a struct node pointer
	typedef struct node* nodePtr;

	// we need the pointers for overall list movement
	nodePtr head;
	nodePtr current;

public:   // Where all the functions can be created to access and manipulate private data.
	List();	// constructor function to create initial values to pointers
	void AddEnd(int data);	// add node to end of list
	void DelEnd(); // delete node from end of list
	bool InsertNode(int data, int position); // insert node into specific location
	bool PullNode(int position); // deletes specific Node with data type;
	void ViewList(); // prints out ordered list
	int ListSize();	//returns length of list
	int DataPos(int data); // returns data position in list of data query
	int Last();
	int First();
};


#endif