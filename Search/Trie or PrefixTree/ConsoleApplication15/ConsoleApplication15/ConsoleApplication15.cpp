// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
#include<unordered_map>
#include<iostream>
#include<limits>

using namespace std;

#include "Trie.h"


int main()
{
	Trie* t = new Trie();

	t->insert(string("maxmell"));
	t->insert(string("maxer"));
	t->insert(string("lombard"));

	cout << t->search(string("maxer")) <<endl;
	cout <<  t->search(string("maxe")) << endl;
	cout << t->startsWith(string("maxe")) << endl;

	return 0;
}

