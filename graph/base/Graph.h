#pragma once


#ifndef GRAPH_H
#define GRAPH_H


#define NULL 0
#include<iostream>
#include<vector>

typedef void (*FVPtr)(int v);
typedef void(*FEPtr)(int e1, int e2);

class GraphClass {
>>>>>>> c8a71f55fb5185a7018e6dab2288c4883a835822

class GraphClass {
public:
	class Edge;
private:

	const static int maxV = 1000;


    
    // Graph Defines
    
	// Graph memebers
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

	// BFS members
	bool processed[maxV+1];
	bool discovered[maxV+1];
	int parent[maxV + 1];

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


	// Graph
	void read();
	void insertEdge(int x, int y, bool directed);
	void print();
    
    int breathFirstSearch(int start);

	// BFS
	void initialize_search();
	void bfs(int start, FVPtr ptr_e, FVPtr ptr_l, FEPtr ptre);
	void find_path(std::vector<int>& path, int start, int end);

	static void process_vertex_early(int x) {
		std::cout << "Early:" << x << std::endl;
	}
	static void process_vertex_late(int x) {
		std::cout << "Late:" << x << std::endl;
	}
	static void process_edge(int x, int y) {
		std::cout << "Edge:" << x <<"-"<<y<< std::endl;
	}

};


#endif