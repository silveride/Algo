
#include "stdafx.h"

#include "At.h"

#include<iostream>

using namespace std;


Node* AvTree::rotateLeft(Node * node)
{
	Node*  newNode = node->right;
	node->right = newNode->left;
	newNode->left = node;
	node->setHeight();
	node->setSize();
	newNode->setHeight();
	newNode->setSize();
	return newNode;
}

Node * AvTree::rotateRight(Node * node)
{
	Node* newNode = node->left;
	node->left = newNode->right;
	newNode->right = node;

	// Adjust height and size
	node->setHeight();
	node->setSize();
	newNode->setHeight();
	newNode->setSize();
	return newNode;
}

// Height adjusted insertion.
Node* AvTree::insertIn(Node* node, int val) {

	if (!node) {
		node = new Node(val);
		return node; 
	}

	if (node->val > val) {
		node->left = insertIn(node->left, val);
	}
	else {
		node->right = insertIn(node->right, val);
	}

	int balance = (height(node->left) - height(node->right));

	if ( balance >= 1) {// left unbalanced
		
		// If left of left node has more nodes comopared to right, rotate right straight. rule
		if (height(node->left->left) >= height(node->left->right)) {
			root = rotateRight(root);
		}
		else {

			// If right has more, rotate left to bring more nodes and rotate right.
			root->left = rotateLeft(root->left);
			root = rotateRight(root);
		}
	}
	else if (balance <= -1) {
		// If left of left node has more nodes comopared to right, rotate right straight. rule
		if (height(node->right->right) >= height(node->right->left)) {
			node = rotateLeft(node);
		}
		else {

			// If right has more, rotate left to bring more nodes and rotate right.
			node->right = rotateRight(node->right);
			node = rotateLeft(node);
		}
	}
	else {
		node->setHeight();
		node->setSize();
	}
	return node;
}

void AvTree::printTree(Node* node)
{
	// traverse and print
	if (node) return;
	printTree(node->left);
	cout << node->val << endl;

	printTree(node->right);


}

void AvTree::insert(int val)
{
	root = insertIn(root, val);

}
