// lt-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<string>
#include<iostream>
#include<vector>

using namespace std;


class KMPMatcher {
public:


	int KMPMatch(string text, string pattern) {
		// Create Lookup Table

		int* lookupTable = new int[pattern.size()];

		makeLookUpTable(pattern, lookupTable);

		printTable(lookupTable, pattern.size());

		// Match the pattern
		for (int iT = 0, iP = 0; iT < text.size() && iP < pattern.size();) {

			if (iP == 0 && pattern[iP] != text[iT]) {
				iT++;
			}
			else if (pattern[iP] == text[iT]) {
				// Continue match
				++iP; ++iT;

				if (iP >= pattern.size()) {
					return iT - iP;
				}
			}
			else {
				iP = lookupTable[iP-1];
			}
		}

		return -1;
	}

	void printTable(int vec[],int size) {

		for (int i = 0; i < size; ++i) {
			cout << vec[i] << " ";
		}

		cout << endl;
	}

	void makeLookUpTable(string str, int vec[]) {

		if (str.size() < 2) return;

		vec[0] = 0;

		for (int i = 1, j = 0; i < str.size();) {
			if (str[i] == str[j]) {
				vec[i] = j + 1;
				++i;
				++j;
			}
			else {
				if (j > 0) {
					j = vec[j - 1];
				}
				else {
					vec[i] = 0;
					++i;
				}

			}
		}
	}
};


int main()
{
	//string str = "abcdabca";

	//int arr[100];

	//makeLookUpTable(str, arr);

	//for (int i = 0; i < str.size(); ++i) {
	//	cout << arr[i];
	//}

	//cout.flush();


	KMPMatcher kmpMatcher;
	string text = "abcxabcdabcdabcy";
	string pattern = "abcdabcy";

	cout << "searching :" << pattern << "in :" << text << endl;

	cout << kmpMatcher.KMPMatch(text, pattern) << endl;

    return 0;
}

