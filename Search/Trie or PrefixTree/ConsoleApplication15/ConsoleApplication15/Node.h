#pragma once

#ifndef Node_H
#define Node_H

// Represents a node within a trie [ Check drive lt folder]

class Trie;

class Node {
	// Max number of alphabets in english
	const static unsigned int Max_Length = 26;

	// links going out per alphabet.
	Node* links[Max_Length] = { NULL };

	// Is this the final node in a chain
	bool is_end;

public:

	Node():is_end(false) {

	}

	bool contains(char ch) const {
		return links[ch - 'a']; // offseting to be within 0-26
	}

	Node* get(char ch) {
		return links[ch - 'a'];
	}

	void put(char ch, Node* node) {
		links[ch - 'a'] = node;
	}

	void setEnd() {
		is_end = true;
	}

	bool isEnd() const {
		return is_end;
	}

	friend class Trie;
};

#endif