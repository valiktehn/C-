#include "CoutO.h"

//Displays the results of Shortest Path
void printPaths(vector<Node> table, int start) {
	int count = 0;
	for (auto i : table) {
		if (count == start) {
			cout << "cost from " << start << " to " << count << " is : " << i.cost << "  from node is " << i.from << "  Path : " << start << endl;
			count++;
			continue;
		}
		cout << "cost from " << start << " to " << count << " is : " << i.cost << "  from node is " << i.from << "  Path : " << count;
		while (i.from != start) {
			if (i.from == -1)
				break;
			cout << " <- " << i.from;
			i = table[i.from];
		}
		cout << " <- " << start << endl;
		count++;
	}
}

//sample screenshot for Prim's algorithm; 1 2 3 is the same as 2 1 3
//1 2 3
//2 0 4
//3 5 2
//4 5 1
//5 1 2
//The overall cost is 12.

//Displays results for Prim's Shortest Tree
void printPrims(vector<Node> table) {
	int j = 0;
	int sum = 0;
	for (auto i : table) {
		cout << j << " " << i.from << " " << i.cost << endl;
		sum += i.cost;
		j++;
	}
	cout << "The overall cost is " << sum << "." << endl;
}

//cout overload for graph: vector of list of pair 
ostream& operator<<(ostream& str, vector<list<pair<int, int>>> V) {

	for (auto i : V) {
		for (auto j : i) {
			str << "(" << j.first << "," << j.second << ") ";
		}
		str << endl;
	}

	return str;
}

//cout overload for table: vector of node
ostream& operator << (ostream& str, vector<Node> table) {
	for (auto i : table) {
		str << i.cost << " " << i.from << " " << i.checked << " " << i.h_index << endl;
	}
	str << endl;
	return str;
}

//cout overload for heap: vector of int
ostream& operator << (ostream& str, vector<int> heap) {
	for (auto i : heap) {
		str << i << " ";
	}
	str << endl;
	return str;
}

/*
The following screenshot might not be a correct run.  It shows the required output format.

//sample screenshot for Dijkstra's algorithm
cost from 0 to 0 is : 0  from node is 0  Path: 0
cost from 0 to 1 is : 7  from node is 2  Path: 1<-2<-0
cost from 0 to 2 is : 4  from node is 0  Path: 2<-0
cost from 0 to 3 is : 10  from node is 1  Path: 3<-1<-2<-0
cost from 0 to 4 is : 14  from node is 3  Path: 4<-3<-1<-2<-0
cost from 0 to 5 is : 9  from node is 1  Path: 5<-1<-2<-0
*/

/*
//sample input file graph.txt
0 //source code
6 //# of nodes in graph
12 //# of edges in graph
0 5 16//an edge from node 0 to node 5 with a weight (cost) of 16
0 4 15
0 2 4
0 3 12
0 1 9
1 3 3
1 5 2
2 3 14
2 1 3
3 4 4
4 5 1
5 3 2
*/


/*
//sample screenshot for Prim's algorithm; 1 2 3 is the same as 2 1 3
1 2 3
2 0 4
3 5 2
4 5 1
5 1 2
The overall cost is 12.
*/