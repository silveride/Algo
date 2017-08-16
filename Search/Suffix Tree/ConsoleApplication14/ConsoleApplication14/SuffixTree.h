//
//  SuffixTree.h
//  TestApp
//
//  Created by Manu Mathew on 15/8/17.
//  Copyright © 2017 Manu Mathew. All rights reserved.
//

#ifndef SuffixTree_h
#define SuffixTree_h

// App Includes

#include "End.h"

class SuffixNode;
class Active;

// System includes
#include<string>

class SuffixTree {
    
    // Input
    char* input;
    size_t length;
    
    // Meta
    const char uniqueChar = '$';
    SuffixNode* root;
    Active* active;
	End end;
	unsigned int remainingSuffixCount = 0;

public:
    
    SuffixTree(std::string iStr)
    {

        
        // Convert the input to c-style string with proper ending
        input = new char[iStr.length()+2];
        strncpy_s(input, iStr.length()+1, iStr.c_str(), iStr.length());
        input[iStr.length()] = uniqueChar;
		input[iStr.length()+1] = '\0'; // for logging
        length = iStr.length()+1;
    }
    
    void build();
    void dft();
    bool validate();
    void printTree() const;
	void startPhase(int x);
	SuffixNode* selectNode(int i);
	char nextChar(int i);
	int diff(SuffixNode* node);
	SuffixNode* selectNode();
	void walkDown(int index);
	void dftTraverse(SuffixNode* tRoot, int tLen);
    
    std::string toString() const {
        
		return std::string("Tree input=" + std::string(input));
    }
};

#endif /* SuffixTree_h */
