#include "Includes.h"

using namespace std;

#pragma once

//Dijkstra's and Prim's Algorithms

void Path(vector<list<pair<int, int>>>& graph, vector<Node>& Table, vector<int>& heap);
void MST(vector<list<pair<int, int>>>& graph, vector<Node>& table, vector<int>& heap);
