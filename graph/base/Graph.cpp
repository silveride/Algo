

#include "Graph.h"

#include<iostream>
#include<queue>

using namespace std;


void GraphClass::read() {
	int nEdges;

	int x, y;

	cout << "Enter the total vertices and Edges" << endl;
	cin >> nvertices >> nEdges;

	for (int i = 0; i < nEdges; ++i) {
		cout << "Enter next x-y" << endl;
		cin >> x >> y;
		insertEdge(x, y,directed);
	}

}

void GraphClass::insertEdge(int x, int y,bool directed) {

	Edge* pNew = new Edge();

	// setup the values
	pNew->y = y;
	pNew->weight = 0;
	pNew->next = edges[x];
	edges[x] = pNew;
	degree[x]++;

	if (directed == false) { // bi directional, create a reverse node
		insertEdge(y, x, true);
	}
	else { // unidirectional
		++nedges;
	}

}


void GraphClass::print() {

	Edge* p;

	cout << "Graph Printing" << endl;
	cout << "Format [vertex]: outgoing edges," << endl;

	for (int i = 0; i < nvertices; ++i) {
		cout << i << ": ";

		p = edges[i];
		while (p != NULL) {
			cout << p->y << ",";
			p = p->next;
		}
		cout << endl;
	}
}

void GraphClass::initialize_search()
{
	for (int i = 0; i < nvertices; ++i) {
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}

void GraphClass::bfs(int start, FVPtr ptr_e, FVPtr ptr_l, FEPtr ptre)
{
	// ptr is the function pointer
	queue<int> q;

	int v; // present vertex
	int y; // present endpoint

	q.emplace(start);

	discovered[start] = true;

	while (!q.empty()) {

		// Get the first element in the level
		v = q.front();
		q.pop();

		if (ptr_e)
		ptr_e(v); // early vertex processing

		Edge* p = edges[v]; // Get all outgoing edges

		while (p != NULL) { // Add each edge

			y = p->y;
			processed[v] = true;

			if ((processed[y] == false) || directed) {
				ptre(v, y);
			}

			if (discovered[y] == false) {
				q.emplace(y);
				discovered[y] = true;
				parent[y] = v;
			}
			p = p->next;
		}

		ptr_l(v);
		
	}

}

void GraphClass::find_path(std::vector<int>& path, int start, int end)
{
	if (start == end || end == -1) {
		path.push_back(start);
	}
	else {
		find_path(path, start, parent[end]);
		path.push_back(end);
	}
}
