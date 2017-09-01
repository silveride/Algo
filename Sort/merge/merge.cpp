



#include "merge.h"
#include "stdafx.h"


#include<vector>




using namespace std;

void merge(vector<int>& array, int low, int mid, int high) {

	
	vector<int> first;
	vector <int> second;

	for (int fi = low; fi <= mid; ++fi) {
		first.push_back(array[fi]);
	}
	for (int fi = mid+1; fi <= high; ++fi) {
		second.push_back(array[fi]);
	}

	// Cross merge
	int f = 0, s = 0;
	
	while (f < first.size() && s < second.size()) {
		if (first[f] > second[s]) {
			array[low++] = first[f++];
		}
		else {
			array[low++] = second[s++];
		}
	}

	while (f < first.size()) { array[low++] = first[f++]; }
	while (s < second.size()) { array[low++] = second[s++]; }
	
}


void mSort(vector<int>& array, int low, int high) {

	if (low >= high) return; // base of recursion

	int middle = (low + high) / 2;

	mSort(array, low, middle);
	mSort(array, middle + 1, high);
	merge(array, low, middle, high);
}


void mergeSort(vector<int>& array) {

	mSort(array, 0, array.size()-1); // first recursion
}
