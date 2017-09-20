#pragma once
#include<algorithm>

class Node {
public:
	int val;
	Node* left;
	Node* right;
	int height;
	int size;

	Node(int v) : val(v), left(NULL), right(NULL),height(0), size(0) {}

	void setHeight() { 
		if (left == NULL &&  right == NULL) 
			height = 0;
		else 
			height = 1 + std::max(left ? left->height:0, right?right->height:0); 
	}

	int getHeight() { return height; }

	void setSize() { 
		if (left == NULL &&  right == NULL)
			size = 0;
		else
			size = 1 + std::max(left ? left->size : 0, right ? right->size : 0);
	}
	int getSize(int x) { return size; }
};



class AvTree {

	Node * root;

	Node* rotateRight(Node* node);
	Node* rotateLeft(Node* node);
	Node* insertIn(Node* node, int val);
	int height(Node* nd) {
		if (!nd) return 0;
		return nd->height;
	}
	

public:
	AvTree() : root(NULL) {}

	void insert(int val);
	void printTree(Node* node);
	//bool isPresent(int val);
	//bool remove(int val);
};

