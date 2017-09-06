// grph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Graph.h"

#include<vector>


using namespace std;

int main()
{

	GraphClass gclass(false);

	gclass.read();

	gclass.print();

	gclass.initialize_search();

	gclass.bfs(0, GraphClass::process_vertex_early, GraphClass::process_vertex_late, GraphClass::process_edge);

	vector<int> path;

	gclass.find_path(path, 0, 2); // Make sure the graph is constructed like this

    return 0;
}

