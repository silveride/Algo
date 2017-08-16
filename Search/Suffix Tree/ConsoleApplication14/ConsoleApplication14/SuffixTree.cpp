//
//  SuffixTree.cpp
//  TestApp
//
//  Created by Manu Mathew on 15/8/17.
//  Copyright © 2017 Manu Mathew. All rights reserved.
//

#include "stdafx.h"

#include "SuffixTree.h"
#include "active.h"

#include <iostream>
#include <string>
#include<exception>

using namespace std;



void SuffixTree::build()
{
	// Create the Root node and set it to NULL
	root = SuffixNode::createNode(1,*( new End(0)));

	// Create and initialise the active node
	active = new Active(root);
	end.end = -1;

	for (int i = 0; i < length; ++i) {
		startPhase(i);
	}
	cout << "Finished" << endl;
	// Todo: DFT and update nodes

	dft();

}

void SuffixTree::startPhase(int i) {

	SuffixNode* lastCreatedInternalNode = NULL;

	// Increment the end point
	end.end++;


	// Each phase starts with an increment in offset
	remainingSuffixCount++;

	// Phase starts
	while (remainingSuffixCount > 0) {

		// Check the root char and see if there is a node with that char
		if (active->activeLength == 0) {

			if (selectNode(i) != NULL) { // This means there is an edge going with the input char. case 3
				active->activeEdge = selectNode(i)->start;
				active->activeLength++;
				break;
			}
			else { // No edge going out, create one
				root->Child[input[i]] = SuffixNode::createNode(i, end);
				remainingSuffixCount--;
			}

		}
		else { // So we are in the middle somewhere. Check next char to see if they are same
			try {
				char ch = nextChar(i);
				//if next character is same as current character then do a walk down. This is again a rule 3 extension and
				//trick 2 (show stopper).
				if (ch == input[i]) {
					//if lastCreatedInternalNode is not null means rule 2 extension happened before this. Point suffix link of that node
					//to selected node using active point.
					//TODO - Could be wrong here. Do we only do this if when walk down goes past a node or we do it every time.
					if (lastCreatedInternalNode != NULL) {
						lastCreatedInternalNode->link = selectNode();
					}
					//walk down and update active node if required as per rules of active node update for rule 3 extension.
					walkDown(i);
					break;
				}
				else {
					//next character is not same as current character so create a new internal node as per 
					//rule 2 extension.
					SuffixNode* node = selectNode();
					int oldStart = node->start;
					node->start = node->start + active->activeLength;
					//create new internal node
					SuffixNode* newInternalNode = SuffixNode::createNode(oldStart, *(new End(oldStart + active->activeLength - 1)));

					//create new leaf node
					SuffixNode* newLeafNode = SuffixNode::createNode(i, this->end);

					//set internal nodes child as old node and new leaf node.
					newInternalNode->Child[input[newInternalNode->start + active->activeLength]] = node;
					newInternalNode->Child[input[i]] = newLeafNode;
					newInternalNode->index = -1;
					active->activeNode->Child[input[newInternalNode->start]] = newInternalNode;

					//if another internal node was created in last extension of this phase then suffix link of that
					//node will be this node.
					if (lastCreatedInternalNode != NULL) {
						lastCreatedInternalNode->link = newInternalNode;
					}
					//set this guy as lastCreatedInternalNode and if new internalNode is created in next extension of this phase
					//then point suffix of this node to that node. Meanwhile set suffix of this node to root.
					lastCreatedInternalNode = newInternalNode;
					newInternalNode->link = root;

					//if active node is not root then follow suffix link
					if (active->activeNode != root) {
						active->activeNode = active ->activeNode->link;
					}
					//if active node is root then increase active index by one and decrease active length by 1
					else {
						active->activeEdge = active->activeEdge + 1;
						active->activeLength--;
					}
					remainingSuffixCount--;
				}
			}
			catch (exception e) {
				//this happens when we are looking for new character from end of current path edge. Here we already have internal node so
				//we don't have to create new internal node. Just create a leaf node from here and move to suffix new link.
				SuffixNode* node = selectNode();
				node->Child[input[i]] = SuffixNode::createNode(i, end);
				if (lastCreatedInternalNode != NULL) {
					lastCreatedInternalNode->link = node;
				}
				lastCreatedInternalNode = node;
				//if active node is not root then follow suffix link
				if (active->activeNode != root) {
					active->activeNode = active->activeNode->link;
				}
				//if active node is root then increase active index by one and decrease active length by 1
				else {
					active->activeEdge = active->activeEdge + 1;
					active->activeLength--;
				}
				remainingSuffixCount--;
			}
		}
	}
}

void SuffixTree::walkDown(int index) {
	SuffixNode* node = selectNode();
	//active length is greater than path edge length.
	//walk past current node so change active point.
	//This is as per rules of walk down for rule 3 extension.
	if (diff(node) < active->activeLength) {
		active->activeNode = node;
		active->activeLength = active->activeLength - diff(node);
		active->activeEdge = node->Child[input[index]]->start;
	}
	else {
		active->activeLength++;
	}
}

char SuffixTree::nextChar(int i) {
	SuffixNode* node = selectNode();

	// Means the node contains the char to be compared with.
	if (diff(node) >= active->activeLength) {
		return input[active->activeNode->Child[input[active->activeEdge]]->start + active->activeLength];
	}

	if (diff(node) + 1 == active->activeLength) {
		if (node->Child[input[i]] != NULL) {
			return input[i];
		}
	}
	else { // Moving to next node as active node
		active->activeNode = node;
		active->activeLength = active->activeLength - diff(node) - 1;
		active->activeEdge = active->activeEdge + diff(node) + 1;
		return nextChar(i);
	}

	// This means that we are after the last char
	bad_alloc b_al;
	throw b_al;
}

int SuffixTree::diff(SuffixNode* node) {
	return node->end.end - node->start; // number of chars in this branch
}



SuffixNode* SuffixTree::selectNode() {
	return active->activeNode->Child[input[active->activeEdge]]; // the child stores as per char.
}


SuffixNode* SuffixTree::selectNode(int i) {
	return active->activeNode->Child[input[i]]; // the child stores as per char.
}

// DFT evaluation of nodes.
void SuffixTree::SuffixTree::dft() {
    // Traversse down
	dftTraverse(root,0);
	// Keep Depth


	// length- depth = node count
}

void SuffixTree::dftTraverse(SuffixNode* tRoot, int tLen) {

	bool found = false;
	int len = 0;

	// For each valid child
	for (auto& node : tRoot->Child) {
		if (node) { // found a slot
			len = node->end.end - node->start+1; // start= end means one char
			dftTraverse(node, len);
			found = true;
		}
	}

	if (!found) { // last node
		tRoot->depth = length - tLen;
	}
}

bool SuffixTree::validate()
{
    return true;
}

void SuffixTree::printTree() const
{
	cout << toString() << endl;

	for (int i = 0; i < SuffixNode::Max_Child; ++i) {
		if (root->Child[i])
			cout << root->Child[i]; 
	}
    
	cout.flush();
}

