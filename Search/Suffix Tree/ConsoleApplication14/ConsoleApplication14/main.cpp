//
//  main.cpp
//  TestApp
//
//  Created by Manu Mathew on 15/8/17.
//  Copyright © 2017 Manu Mathew. All rights reserved.
//



int main(int argc, const char * argv[]) {
    // Construct the suffix tree
    
    string testString = "mississipi";
    SuffixTree suffixTree(testString);
    
    cout<< suffixTree.toString() << endl;
    
    suffixTree.build();
    suffixTree.dft();
    suffixTree.validate();
    suffixTree.printTree();
    
    
    return 0;
}
