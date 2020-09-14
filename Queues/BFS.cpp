#include <cstdlib>
#include <iostream>

#include "BFS.h"	

using namespace std;

void getPath(int* path, int connects[12][4], int start, int end) {

	const int nodes = 12;

	int prevList[nodes];
	Queue algoQueue;
	algoQueue.enqueue(start);
	bool visited[nodes] = { false };
	visited[start] = true;

	int prev[12] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	while (algoQueue.isEmpty() == false) {
		int node = algoQueue.dequeue();
		for (int i = 0; i != 4; i++) {
			int next = connects[node][i];
			if (next != -1) {
				if (visited[next] == false) {
					algoQueue.enqueue(next);
					visited[next] = true;
					prev[next] = node;
				}
			}
		}

	}

	// prev should be set up after this algorithm

	int pathcreate[20] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int counter = 0;
	for (int i = end; i != -1; i = prev[i]) {
		pathcreate[counter] = i;
		counter++;
	}

	//now we have the path back, we need to reverse to back from start to top;

	int startPos = -1;
	for (int i = 0; i != 20; i++) {
		if (pathcreate[i] == start && startPos == -1) {
			startPos = i;
			break;
		}
	}

	// startpos set

	for (int i = 0; i != startPos + 1; i++) {
		path[i] = pathcreate[startPos - i];
	}
}