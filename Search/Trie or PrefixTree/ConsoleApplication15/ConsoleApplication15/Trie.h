#pragma once


#include "Node.h"

#include<string>

class Trie {

	// The root node
	Node* root;

public:

	Trie() {
		root = new Node();
	}

	void insert(std::string& word);
	bool search(std::string& word);
	Node* searchPrefix(std::string& word);
	bool startsWith(std::string& prefix);

};
