#include <iostream>
#include <cstdlib>
#include <string>


#ifndef HASHTABLE_H
#define HASHTABLE_H

class hashtable {

private:
	// constant tableSize
	static const int tableSize = 10;
	// item structure holds basic data components.
	struct item {
		std::string name;
		std::string color;
		item* next;
	};

	// this array element holds the linked lists data structure!
	item* HashTable[tableSize];

	int Hash(std::string key);	// create unique hash function.

public:

	hashtable(); // intialize table size 
	void addItem(std::string name, std::string color); // adding item to the list.
	int numItemsIndex(int index); // returns the number of item in an index
	void printTable(); 
	void printItemsinIndex(int index); // prints out all items within bucket
	std::string findPair(std::string name);
	void remove(std::string name);

};


#endif