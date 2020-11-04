#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#pragma once

//All required includes and the Node class

class Node {
public:
	int cost;  //cost to a node
	int from;  //the from node to this node
	bool checked;
	int h_index; //the index in heap for this node
	Node() : cost(9999), from(-1), checked(false), h_index(-1) {}
};
