#include "stdafx.h"

#include<vector>
#include<iostream>

using namespace std;

int bintree(int max, int count,int memo[]) {

	int ret = 0;

	if (max == count) {
		return 1;
	}

	if (max < count) {
		return 0;
	}

	if (memo[count] > 0) {
		return memo[count];
	}

	// add left child
	ret += bintree(max, count + 1,memo);
	ret += bintree(max, count + 2,memo);

	memo[count] = ret;

	return ret; // return total number of turns
}

int bt(int n) {

	int* memo = new int[n]; // This memo reduces the backtracking in the tree traversal. interesting
	int count = bintree(n, 0, memo);
	return count;
}

int main()
{
	cout << bt(3) << endl;
    return 0;
}