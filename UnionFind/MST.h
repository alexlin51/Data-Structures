#ifndef MST_H
#define MST_H

#include "unionfind.h"

#include <vector>
#include <algorithm>

int mst(int nodes, int edges, int edgelist[][3], std::vector<std::pair < int,int > > &list);

#endif
