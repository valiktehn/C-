#include "Includes.h"


#pragma once

//Container building functions

int loadGraph(vector<list<pair<int, int>>>& V, int type);
void buildTable(vector<list<pair<int, int>>> graph, vector<Node>& table, int start);
void buildHeap(vector<list<pair<int, int>>> graph, vector<int>& heap, int start);