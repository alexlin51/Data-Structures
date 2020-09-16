#include <iostream>

#include "PQueue.h"

using namespace std;


int main() {

	int capacity = 20;

	PQueue organizer(capacity);

	for (int i = 19; i != -1; i--) {
		organizer.enqueue(i);
	}
	
	organizer.printQueue();

	cout << endl;

	int removed;
	cout << "| ";
	for (int i = 0; i != 20; i++) {
		// priority queue so this one is built around removing the smallest number first!
		removed = organizer.dequeue();
		cout << removed << " ";
	}
	cout << "|";

}