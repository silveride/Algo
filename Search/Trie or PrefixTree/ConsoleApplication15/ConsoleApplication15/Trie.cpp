
#include "stdafx.h"

#include "Trie.h"
#include "Node.h"

#include<iostream>


using namespace std;

void Trie::insert(std::string& word) {

	Node* node = root;

	// go through each char and trace from roo
	for (auto& a : word) {
		if (!node->links[a - 'a']) { // move to next one
			node->put(a, new Node());
		}

		// Traverse to next node.
		node = node->links[a - 'a'];
	}

	node->setEnd();
}

// search if the word is present
bool Trie::search(std::string& word) {
	Node* node = searchPrefix(word);

	return node != NULL && node->isEnd();
}
Node* Trie::searchPrefix(std::string& word) {
	Node * node = root;

	for (auto& x : word) {
		if (node->links[x - 'a']) {
			node = node->links[x - 'a'];
		}
		else {
			return NULL;
		}
	}

	return node;
}
bool Trie::startsWith(string& prefix) {

	return searchPrefix(prefix) != NULL;
}
