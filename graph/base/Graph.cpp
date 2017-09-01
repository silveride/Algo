
#include "stdafx.h"

#include "Graph.h"

#include<iostream>

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