#include <vector>
#include <algorithm>
#include <iostream>

#include "MST.h"

using namespace std;

int mst(int nodes, int edges, int edgelist[][3], std::vector<pair < int, int > > &list)
{
    int totalweight = 0;
    int usedNodes = 0;
    int currentEdge = 0;
    int p1;
    int p2;
    int weight;

    unionFind data(nodes);

    // push in all the edge points into unionFind and vector
    vector < pair < int, pair < int, int > > > edgeTrack;
    for (int i = 0; i != edges; i++) {
        p1 = edgelist[i][1];
        p2 = edgelist[i][2];
        weight = edgelist[i][0];
        edgeTrack.push_back(make_pair(weight, make_pair(p1, p2)));

    }

    // sort vector into least to greatest
    sort(edgeTrack.begin(), edgeTrack.end());

    // algorithm to connect and track. 
    while ((usedNodes < nodes - 1) || (currentEdge < edges)) {
        p1 = edgeTrack[currentEdge].second.first;
        p2 = edgeTrack[currentEdge].second.second;
        weight = edgeTrack[currentEdge].first;

        if (data.findRoot(p1) != data.findRoot(p2)) {
            data.unify(p1, p2);
            totalweight += weight;
            usedNodes++;
            list.push_back(make_pair(p1, p2));
        }

        currentEdge++;
    }

    return totalweight;
}
