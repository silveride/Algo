//
//  Active.h
//  TestApp
//
//  Created by Manu Mathew on 15/8/17.
//  Copyright © 2017 Manu Mathew. All rights reserved.
//

#ifndef Active_h
#define Active_h


#include "SuffixNode.h"

#include<string>



class Active {
public:
  
    Active(SuffixNode* node) {
        this->activeNode = node;
        activeLength = 0;
        activeEdge = -1;
    }

	SuffixNode* activeNode;
	int activeEdge;
	int activeLength;
    
    std::string toString() {
        
        return "Active activeNode=" + activeNode->toString() + ", activeLength=" + std::to_string(activeLength) + ", activeEdge="+ std::to_string(activeEdge);
    }
    
};

#endif /* Active_h */
