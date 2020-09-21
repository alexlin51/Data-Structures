#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#include "AVL.h"

using namespace std;

int main() {
	const int size = 10;

	int array[size] = { 50, 32, 36, 30, 28, 26, 70, 73, 68, 62 };

	vector<int> list;

	for (int i = 0; i != size; i++) {
		list.push_back(array[i]);
	}

	balanceTree plant(list);
	plant.add(1);

	plant.printOrder();

	cout << endl;

	cout << plant.findLargest() << " | " << plant.findSmallest() << endl;

	bool contains = plant.contains(33);


	if (contains) {
		cout << "Does Exists!" << endl;
	}
	else {
		cout << "Doesn't Exists!" << endl;
	}

	plant.remove(50);

	plant.printOrder();


}