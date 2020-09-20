#include <iostream>
#include <cstdlib>
#include <vector>

#include "fenwick.h"

using namespace std;

int main() {

	vector<int> list;
	list.push_back(3);
	list.push_back(5);
	list.push_back(-1);
	list.push_back(8);
	list.push_back(-2);
	list.push_back(6);
	list.push_back(2);
	list.push_back(1);
	list.push_back(-5);
	list.push_back(-4);
	list.push_back(9);
	list.push_back(11);
	list.push_back(-3);
	list.push_back(-4);

	fenwickTree range(list);
	int print = range.sum(1);

	cout << print << endl;

	cout << "-------------------" << endl;

	range.printTree();

	cout << endl;

	range.replace(4, 9);

	range.printTree();

	print = range.sum(4);

	cout << endl;

	cout << print << endl;


	return 0;
}