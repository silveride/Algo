#pragma once


#ifndef GRAPH_H
#define GRAPH_H

class GraphClass {

	class Edge;

	const static int maxV = 1000;

	Edge* edges[maxV] = { NULL };
	int degree[maxV + 1] = { 0 };
	int nvertices;
	int nedges;
	bool directed;

public:
	class Edge {
	public:
		int y;
		int weight;
		struct Edge * next;
	};


	GraphClass(bool dir = false): directed(dir), nvertices(0), nedges(0) {
		for (auto& x : edges) { x = 0; }
		for (auto& x : degree) { x = 0; }
	}

	void read();
	void insertEdge(int x, int y, bool directed);
	void print();


};


#endif