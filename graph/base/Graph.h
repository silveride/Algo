#pragma once


#ifndef GRAPH_H
#define GRAPH_H

#define NULL 0

class GraphClass {
public:
	class Edge;
private:

	const static int maxV = 1000;

    
    // Graph Defines
    
	Edge* edges[maxV] = { NULL };
	int degree[maxV + 1] = { 0 };
	int nvertices;
	int nedges;
	bool directed;
    
    
    // Search defines
    bool processed[maxV+1];
    bool discovered[maxV+1];
    int parent[maxV+1];
    void initialiseSearch();

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
    
    int breathFirstSearch(int start);


};


#endif