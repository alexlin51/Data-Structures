#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <vector>

class unionFind {
	
private:
	int size; // size of this datastructure
	std::vector<int> sizeTracker; // array that tracked the size of roots
	std::vector<int> parent; // array that tracks the parent/root element
	int numGroups;	// holds the number of group

public:
	unionFind(int size); // constructor takes in the size and intializes all the rest of the structure
	int findRoot(int index); // takes in index and searches/returns root element
	bool isConnected(int p1, int p2); // takes in point 1 and point 2, returns if elements are connect/ are they same root
	int groupSize(int index); // returns size of group from index input
	int dataSize();	// returns size of the datastructure
	int groupsLeft(); // returns the number of groups left
	void unify(int p1, int p2); // connects the roots nodes two inputs to the smaller -> bigger

};

#endif