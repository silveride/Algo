// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



#include "SuffixTree.h"

#include <iostream>
#include <string>


using namespace std;

int main()
{
	string testString = "xx";
	SuffixTree suffixTree(testString);

	suffixTree.build();
	suffixTree.dft();
	suffixTree.validate();
	suffixTree.printTree();

    return 0;
}

