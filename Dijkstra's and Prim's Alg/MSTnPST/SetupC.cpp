#include "SetupC.h"

int loadGraph(vector<list<pair<int, int>>>& V, int type) {
	vector<list<pair<int, int>>> graph;
	string line = "";

	//load file
	ifstream inStream("graph.txt");

	// if file loaded
	if (inStream.is_open()) {
		//read header of file
		getline(inStream, line);
		int start = 0;

		//empty file check
		if (line.size() == 0) {
			inStream.close();
			return -1;
		}

		//file header : the start node, how many nodes, how many edges
		//should implement check to verify format !!!!!!!
		start = stoi(line);
		getline(inStream, line);
		int nodes = 0;
		nodes = stoi(line);
		getline(inStream, line);
		int edges = 0;
		edges = stoi(line);

		//cout << start << " " << nodes << " " << edges << endl;
		//checking if nodes are in file 
		if (nodes > 0) {

			//set nodes : add a position for each node
			//should implement check to verify node count is accurate to what is listed !!!!!!!
			for (int i = 0; i < nodes; i++) {
				list<pair<int, int>> a;
				graph.push_back(a);
			}

			//populate nodes : checking each nodes edges
			for (int i = 0; i < edges; i++) {
				getline(inStream, line);
				istringstream ss(line);
				//line should be 3 integers (start node, destination node, distance) : should implement check for format
				int index = 0;
				int dest = 0;
				int dist = 0;
				ss >> index;
				ss >> dest;
				ss >> dist;

				//cout << index << " " << dest << " " << dist << endl;
				//create the edge
				pair<int, int> p;
				p.first = dest;
				p.second = dist;
				graph[index].push_back(p);

				//if type 2 its prims implementation and need to add return edge
				if (type == 2) {
					p.first = index;
					graph[dest].push_back(p);
				}
			}
			inStream.close();

			V = graph;
			return start;
		}
		else {
			cout << "nodes listed as 0" << endl;
			inStream.close();
			return -1;
		}
	}
	else
		cout << "unable to open file" << endl;
	return -1;
	//return graph;
}

void buildTable(vector<list<pair<int, int>>> graph, vector<Node> &table, int start) {
	//builds table
	int j = 0;
	for (auto i : graph) {
		Node a;
		a.h_index = j;
		table.push_back(a);
		j++;
	}

	//Set proper start 
	table[0].cost = table[start].cost;
	table[0].from = table[start].from;
	table[0].h_index = table[start].h_index;
	table[start].cost = 0;
	table[start].from = start;
	table[start].h_index = 0;
}

void buildHeap(vector<list<pair<int, int>>> graph, vector<int>& heap, int start)
{
	//build heap
	int j = 0;
	for (auto i : graph) {
		int a = j;
		heap.push_back(a);
		j++;
	}

	//Set proper start
	int swap = heap[0];
	heap[0] = heap[start];
	heap[start] = swap;
}