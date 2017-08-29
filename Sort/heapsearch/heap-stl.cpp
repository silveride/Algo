// ConsoleApplication16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<algorithm>
#include<iostream>
#include<vector>


using namespace std;

int main()
{
	vector<int> testVec = { 1,7,3,2,9 };

	for (auto& x : testVec) {
		cout << x << endl;
	}

	make_heap(testVec.begin(), testVec.end());


	for (auto&x : testVec) {
		cout << x << endl;
	}
	


    return 0;
}

