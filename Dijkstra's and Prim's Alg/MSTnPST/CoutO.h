#include "Includes.h"

#pragma once

//All printing related functions

void printPaths(vector<Node> table, int start);
void printPrims(vector<Node> table);
ostream& operator<<(ostream& str, vector<list<pair<int, int>>> V);
ostream& operator << (ostream& str, vector<Node> table);
ostream& operator << (ostream& str, vector<int> heap);