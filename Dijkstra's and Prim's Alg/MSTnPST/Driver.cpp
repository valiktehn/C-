
//HW4A: Dijkstra's algorithm with HEAP
//HW4B: Use the same design for Prim's algorithm
//For each x->y edges, also create a y->x edge with the same weight
//HW4A Due: Friday Oct. 2; HW4B Due: Tuesday, Oct. 6
//Complexity: O((N+E) log N)

//sets graph, table, heap
#include "SetupC.h"
//Shortest Path and MST Algorithms
#include "Dijkstra.h"
//Printing functions
#include "CoutO.h"
//Necessary Includes for operations
#include "Includes.h"

int main() {
	// type 1 = Shortest Path, type 2 = Shortest Tree
	int type = 1;

	// Build the input graph from file
	vector<list<pair<int, int>>> graph;
	int start = loadGraph(graph, type);
	
	//cout << "starts@" << start << endl;
	//cout << graph;
	
	if (start == -1 || graph.size() == 0) {
		cout << "graph size 0, file not opened, or file empty error" << endl;
		return -1;
	}

	// Build the table
	vector<Node> table;
	buildTable(graph, table, start);

	// Build the heap
	vector<int> heap;
	buildHeap(graph, heap, start);

	//cout << table;
	//cout << heap;
	if (type == 1) {
		Path(graph, table, heap);//HW4A
		printPaths(table, start);
	}
	else if (type == 2) {
		MST(graph, table, heap);//HW4B
		printPrims(table);
	}
	//cout << table;
	//cout << heap;
}