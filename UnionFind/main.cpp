#include <iostream>
#include <string>
#include <vector>

#include "MST.h"

using namespace std;

int main(){

	int nodes = 10;
	int edges = 18;
	int edgelist[18][3] = { {1, 0, 4},
							{5, 4, 3},
							{4, 3, 6},
							{2, 6, 9},
							{0, 5, 9},
							{4, 7, 5},
							{6, 8, 7},
							{1, 8, 0},
							{4, 4, 1},
							{2, 0, 1},
							{5, 8, 1},
							{2, 1, 3},
							{2, 1, 2},
							{11, 1, 7},
							{1, 7, 2},
							{6, 2, 5},
							{4, 2, 6},
							{1, 5, 6} };

	vector< pair <int, int> > list;

	int data = mst(nodes, edges, edgelist, list);

	cout << data << endl;

	for (int i = 0; i != list.size(); i++) {
		cout << list[i].first << " | " << list[i].second << endl;
	}
}