#include <iostream>
#include <cstdlib>
#include <string>

#include "hashtable.h"

using namespace std;

hashtable::hashtable() {
	// we need to initialize our array
	for (int i = 0; i != tableSize; i++) {
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->color = "empty";
		HashTable[i]->next = NULL;
	}
}

int hashtable::Hash(std::string key) {
	// This function is meant to turn any string into a int for our hash table
	// This has to be consistent!

	// lets add up the askey values for a simple version
	int size = key.length();
	int count = 0;

	for (int i = 0; i != size; i++) {
		count += (int)key[i];
	}

	return (count % tableSize);
}

std::string hashtable::findPair(std::string name) {
	int value = Hash(name);
	item* tracker = HashTable[value];
	item* returner = NULL;
	int indexNum = numItemsIndex(value);

	for (int i = 0; i != indexNum; i++) {
		if (tracker->name == name) {
			returner = tracker;
		}
		tracker = tracker->next;
	}

	//now that we found the name location
	if (returner == NULL) {
		std::string error = "Error";
		return error;
	}
	else {
		return returner->color;
	}

}

void hashtable::addItem(std::string name, std::string color) {

	if (findPair(name) == "Error") {
		//we need to has the key name!
		int index = Hash(name);

		if (HashTable[index]->name == "empty") {
			HashTable[index]->name = name;
			HashTable[index]->color = color;
		}
		else {
			item* tracker = HashTable[index];
			while (tracker->next != NULL) {
				// we want to end up on the node right before the end. 
				tracker = tracker->next;
			}
			// so now our position is ready to add another node after
			item* n = new item;
			n->color = color;
			n->name = name;
			n->next = NULL;
			tracker->next = n;

		}
	}
	else {
		cout << "Name already exists!" << endl;
	}
	
}

int hashtable::numItemsIndex(int index) {
	// empty case
	if (HashTable[index]->name == "empty") {
		return 0;
	}
	// this is if there is something inside
	int counter = 1;
	item* tracker = HashTable[index];
	while (tracker->next != NULL) {
		tracker = tracker->next;
		counter++;
	}
	return counter;
}

void hashtable::printTable() {
	int itemsWithin;
	cout << "------------------------- " << endl;
	for (int i = 0; i != tableSize; i++) {
		itemsWithin = numItemsIndex(i);
		cout << "HashTable[" << i << "]:" << endl;
		cout << "Name: " << HashTable[i]->name << endl;
		cout << "Color: " << HashTable[i]->color << endl;
		cout << "Holds: " << itemsWithin << " items" << endl;
		cout << "------------------------- " << endl;
	}
}

void hashtable::printItemsinIndex(int index) {
	item* tracker = HashTable[index];
	if (tracker->name == "empty") {
		cout << "------------------------- " << endl;
		cout << "HashTable[" << index << "] has no entries." << endl;
		cout << "------------------------- " << endl;
	}
	else {
		cout << "------------------------- " << endl;
		cout << "HashTable[" << index << "]" << endl;
		cout << "1. " << tracker->name << " -- " << tracker->color << endl;
		while (tracker->next != NULL) {
			cout << index + 2 << ". " << tracker->name << " -- " << tracker->color << endl;
			tracker = tracker->next;
		}
		cout << "------------------------- " << endl;
	}

}

void hashtable::remove(std::string name) {
	int value = Hash(name);
	item* p1;
	item* p2;
	item* p3;

	// Case where bucket is empty
	if (numItemsIndex(value) == 0) {
		cout << "There is no entry with name, " << name << endl;
	}

	// Case where only 1 item is in bucket with matching name;
	if (numItemsIndex(value) == 1 && HashTable[value]->name == name) {
		HashTable[value]->name = "empty";
		HashTable[value]->color = "empty";
	}

	// Case where there is a match in first item, but there are more items in list. 
	if (numItemsIndex(value) > 1 && HashTable[value]->name == name) {
		p1 = HashTable[value]->next;
		HashTable[value]->name = p1->name;
		HashTable[value]->color = p1->color;
		HashTable[value]->next = p1->next;
		delete p1;
		p1 = NULL;

	}

	// Case where bucket has items but first item is not the match
	if (numItemsIndex(value) > 1 && HashTable[value]->name != name) {
		// no match
		if (findPair(name) == "Error") {
			return;
		}
		// match is found
		else {
			// iterate to the spot
			p2 = HashTable[value];
			p3 = HashTable[value];
			while (p3->next->name != name) {
				p3 = p3->next;
			}
			while (p2->name != name) {
				p2 = p2->next;
			}
			// so now p2 is on the spot
			// p3 is previous to spot
			if (p2->next != NULL) {
				p1 = p2->next;
				// p1 is after spot
				p3->next = p1;
				delete p2;
				p2 = NULL;
			}
			else {
				delete p2;
				p3->next = NULL;
			}
		}
	}
}