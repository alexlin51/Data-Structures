#include <cstdlib>
#include <iostream>

#include "List.h"	// made sure to include the headerfile!

using namespace std;

List::List() {
	// initialize all the pointers to NULL
	head = NULL;
	current = NULL;
}

int List::ListSize() {
	int counter = 0;
	current = head;
	if (current->next != NULL) {
		counter = 1;
		while (current->next != NULL) {
			current = current->next;
			counter++;
		}
	}

	return counter;
}

int List::DataPos(int data) {
	int counter = 0;
	current = head;
	if (head != NULL) {
		while (current->data != data) {
			current = current->next;
			counter++;
		}
	}
	return counter;
}

void List::AddEnd(int data) {
	nodePtr n = new node;
	n->next = NULL;
	n->data = data;

	// general case
	if (head != NULL) {
		current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		// this has reached the end of the list
		current->next = n;
		n->prev = current;
	}
	else {		// first case
		n->prev = NULL;
		head = n;
	}
}

void List::DelEnd() {
	if (head != NULL) {
		nodePtr delPtr = NULL;
		current = head;
		while (current->next != NULL) {
			current = current->next;
		}
		// if head
		if (current->prev == NULL) {
			delPtr == current;
			current == NULL;
			head == NULL;
		}
		else {
			delPtr = current;
			current = current->prev;
			current->next = NULL;
		}
		delete delPtr;
		delPtr = NULL;
	}
}

bool List::InsertNode(int data, int position) {
	int listsize = ListSize();
	int inferedsize = position + 1;
	if (inferedsize <= listsize) {
		// case 0
		if (position == 0) {
			current = head;
			nodePtr n = new node;
			n->next = current;
			n->data = data;
			n->prev = NULL;
			head = n;
			current->prev = n;
		}
		// case end
		else if (inferedsize == listsize) {
			current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			//we are on the last entry
			nodePtr n = new node;
			n->data = data;
			nodePtr traveler = current;
			current = traveler->prev;
			current->next = n;
			n->prev = current;
			n->next = traveler;
			traveler->prev = n;
			traveler = NULL;
		}
		// case normal
		else {
			current = head;
			nodePtr n = new node;
			n->data = data;
			for (int i = 0; i != position; i++) {
				current = current->next;
			}
			nodePtr traveler = current->prev;
			traveler->next = n;
			n->prev = traveler;
			n->next = current;
			current->prev = n;
			traveler = NULL;
		}
		return true;
		cout << "Position Added";
	}
	else {
		cout << "Position not available";
		return false;
	}
}

bool List::PullNode(int position) {
	int listsize = ListSize();
	int inferedsize = position + 1;
	if (inferedsize <= listsize) {
		// case 1;
		if (position == 0) {
			nodePtr delPtr = NULL;
			delPtr = head;
			head = delPtr->next;
			current = head;
			head->prev = NULL;
			delete delPtr;
			delPtr = NULL;
		}
		// case end;
		else if (inferedsize == listsize) {
			DelEnd();
		}
		// case norm;
		else {
			nodePtr delPtr = NULL;
			nodePtr traveler = NULL;
			current = head;
			for (int i = 0; i != position; i++) {
				current = current->next;
			}
			delPtr = current;
			current = delPtr->prev;
			traveler = delPtr->next;
			current->next = traveler;
			traveler->prev = current;
			delete delPtr;
			traveler = NULL;
			delPtr = NULL;
		}
		cout << "Deleted position";
		return true;
	}
	else {
		cout << "Position not available";
		return false;
	}
}

void List::ViewList() {
	current = head;
	while (current->next != NULL) {
		cout << current->data;
		cout << " - ";
		current = current->next;
	}
	cout << current->data;
}
