//
//  Suffix.h
//  TestApp
//
//  Created by Manu Mathew on 15/8/17.
//  Copyright © 2017 Manu Mathew. All rights reserved.
//

#ifndef Suffix_h
#define Suffix_h


#include <string>
#include<iostream>

#include "End.h"

using namespace std;

class SuffixNode {
public:
	const static unsigned int Max_Child = 256;

	int start;
	End& end;
	int index;
	int depth;

	SuffixNode* link;
	SuffixNode* Child[Max_Child]; // children array. TODO. covert to hash
    
	//SuffixNode() {}
	SuffixNode(int iStart,End& iEnd):end(iEnd) {
		start = iStart;
		depth = 0;
		//end = iEnd;
	}

	static SuffixNode* createNode(int iStart, End& iEnd) {
		return new SuffixNode(iStart,iEnd);
	}

	std::string toString() const {

		return std::string("Node");
	}

	friend ostream& operator << (ostream& os, SuffixNode* sfx);
};

ostream& operator << (ostream& os, SuffixNode* sfx) {

	if (sfx == NULL) return os;
	os << "start=" << sfx->start << ", end=" << sfx->end.toString()<<", depth"<< sfx->depth << endl;

	// Do not pipe link as will end up in recursive infinum

	for (int i = 0; i < SuffixNode::Max_Child; ++i) {
		if (sfx->Child[i])
			cout << sfx->Child[i];
	}

}

#endif /* Suffix_h */
