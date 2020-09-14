#include <iostream>
#include <sstream>
#include <string>

#include "BFS.h"

using namespace std;

int main() {
	int neighbors[12][4] = { {1, 2, -1, -1}, 
							 {10, 2, 0, -1}, 
							 {0, 1, 5, 3}, 
							 {3, -1, -1, -1}, 
							 {2, 6, 7, -1}, 
							 {5, -1, -1, -1}, 
							 {5, 8, -1, -1}, 
							 {9, 7, -1, -1},
							 {12, 10, 8, -1}, 
							 {11, 9, 1, -1},	
							 {12, 10, -1, -1}, 
							 {11, 9, -1, -1} };

	int startpoint = 0;
	int endpoint = 9;

	int arr[20] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };	getPath(arr, neighbors, startpoint, endpoint);

	for (int i = 0; i != 20; i++) {
		if (i == 0) {
			cout << arr[i] << "\n";
		}
		else {
			if (arr[i] != -1) {
				cout << arr[i] << "\n";
			}
		}
	}

	

}