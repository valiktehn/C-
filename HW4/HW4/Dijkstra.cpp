#include "Dijkstra.h"

//Dijkstra's SP
void Path(vector<list<pair<int, int>>>& graph, vector<Node>& Table, vector<int>& heap) {
	//checking for proper size heap
	if (heap.size() < 2) {
		return;
	}

	//function proper
	while (!heap.empty()) {
		//set head to top of min heap
		int head = heap[0];

		//cout << "head " << head << endl;
		//cout << Table;
		//cout << "heap before " << heap << endl;
		
		//top of heap now visited
		Table[head].checked = true;

		//remove top of heap and replace with farthest right node 
		heap[0] = heap[heap.size() - 1];
		Table[heap[0]].h_index = 0;
		heap.pop_back();

		//cout << "heap a pop " << heap << endl;
		
		//heapify
		int hpos = 0;
		//Min Heap Check:
		//pass head node to proper place in min heap (check head is < left or < right then swap until head is > left and > right)
		while (hpos < heap.size() - 1 && heap.size() != 0) {
			int left = hpos * 2 + 1;
			int right = hpos * 2 + 2;
			//left doesn't exist break (implies this for right)
			if (left > heap.size() - 1) {
				break;
			}
			//right doesn't exist (just check left)
			else if (right > heap.size() - 1) {
				//swap current node with left child if parent larger
				if (Table[heap[left]].cost < Table[heap[hpos]].cost) {
					int tmpa = heap[hpos];
					heap[hpos] = heap[left];
					heap[left] = tmpa;
					Table[heap[hpos]].h_index = hpos;
					Table[heap[left]].h_index = left;
					hpos = left;
					break;
				}
				else
					break;
			}
			//both exist check both
			else {
				//swap current node with left child if parent larger
				if (Table[heap[left]].cost <= Table[heap[right]].cost && Table[heap[left]].cost < Table[heap[hpos]].cost) {
					int tmpa = heap[hpos];
					heap[hpos] = heap[left];
					heap[left] = tmpa;
					Table[heap[hpos]].h_index = hpos;
					Table[heap[left]].h_index = left;
					hpos = left;
					continue;
				}
				//swap current node with right child if parent larger
				else if (Table[heap[right]].cost < Table[heap[left]].cost && Table[heap[right]].cost < Table[heap[hpos]].cost) {
					int tmpa = heap[hpos];
					heap[hpos] = heap[right];
					heap[right] = tmpa;
					Table[heap[hpos]].h_index = hpos;
					Table[heap[right]].h_index = right;
					hpos = right;
					continue;
				}
				//current node is smallest in terms of children
				else
					break;
			}
		}


		//cout << "heap after " << heap << endl;
		//checking the path cost to each child of head
		for (auto branch : graph[head]) {
			//cout << branch.first;
			//check if visited 
			//check if current run shorter then stored if so change
			if (Table[branch.first].cost > branch.second + Table[head].cost) {
				Table[branch.first].cost = branch.second + Table[head].cost;
				Table[branch.first].from = head;
				//cout << " to " << branch.second + Table[head].cost << " ";
				//move to new position if applicable
				int pos = Table[branch.first].h_index; //position var of child
				while (pos != 0) {
					float posf = pos;
					int parent = ceil(posf / 2) - 1; // parent calcuation
					//heap check: if parent is greater swap 
					if (Table[heap[parent]].cost > Table[heap[pos]].cost) {
						int tmp = heap[parent];
						heap[parent] = heap[pos];
						heap[pos] = tmp;
						Table[heap[parent]].h_index = parent;
						Table[heap[pos]].h_index = pos;
					}
					//no need to continue
					else
						break;
					//on to next check
					pos = parent;
				}
			}
			//}
			//cout << endl;
		}
	}
}

void MST(vector<list<pair<int, int>>>& graph, vector<Node>& table, vector<int>& heap) {
	//checking for proper size heap
	if (heap.size() < 2) {
		return;
	}

	//function proper : until every node checked
	while (!heap.empty()) {
		//checking head
		int head = heap[0];
		//top of heap now visited
		table[head].checked = true;

		//remove top of heap  and replace with farthest bottom right node 
		heap[0] = heap[heap.size() - 1];
		table[heap[0]].h_index = 0;
		heap.pop_back();

		int hpos = 0;
		//Min Heap Check:
		//pass head node to proper place in min heap (check head is < left or < right then swap until head is > left and > right)
		while (hpos < heap.size() - 1 && heap.size() != 0) {
			int left = hpos * 2 + 1;
			int right = hpos * 2 + 2;
			//left doesn't exist break (implies this for right)
			if (left > heap.size() - 1) {
				break;
			}
			//right doesn't exist (just check left)
			else if (right > heap.size() - 1) {
				//swap current node with left child if parent larger
				if (table[heap[left]].cost < table[heap[hpos]].cost) {
					int tmpa = heap[hpos];
					heap[hpos] = heap[left];
					heap[left] = tmpa;
					table[heap[hpos]].h_index = hpos;
					table[heap[left]].h_index = left;
					hpos = left;
					break;
				}
				else
					break;
			}
			else {
				//swap current node with left child if parent larger
				if (table[heap[left]].cost <= table[heap[right]].cost && table[heap[left]].cost < table[heap[hpos]].cost) {
					int tmpa = heap[hpos];
					heap[hpos] = heap[left];
					heap[left] = tmpa;
					table[heap[hpos]].h_index = hpos;
					table[heap[left]].h_index = left;
					hpos = left;
					continue;
				}
				//swap current node with right child if parent larger
				else if (table[heap[right]].cost < table[heap[left]].cost && table[heap[right]].cost < table[heap[hpos]].cost) {
					int tmpa = heap[hpos];
					heap[hpos] = heap[right];
					heap[right] = tmpa;
					table[heap[hpos]].h_index = hpos;
					table[heap[right]].h_index = right;
					hpos = right;
					continue;
				}
				//current node is smallest in terms of children
				else
					break;
			}
		}

		//checking the path cost to each child of head
		for (auto branch : graph[head]) {
			//check if visited 
			if (table[branch.first].checked == false) {
				//check if current run shorter then stored if so change
				if (table[branch.first].cost > branch.second) {
					table[branch.first].cost = branch.second;
					table[branch.first].from = head;

					//move to new position if applicable
					int pos = table[branch.first].h_index;
					while (pos != 0) {
						float posf = pos;
						int parent = ceil(posf / 2) - 1; // parent calc
						//heap check: if parent is greater swap 
						if (table[heap[parent]].cost > table[heap[pos]].cost) {
							int tmp = heap[parent];
							heap[parent] = heap[pos];
							heap[pos] = tmp;
							table[heap[parent]].h_index = parent;
							table[heap[pos]].h_index = pos;
						}
						//parent is not greater break
						else
							break;
						// check next
						pos = parent;
					}
				}
			}
		}
	}
}