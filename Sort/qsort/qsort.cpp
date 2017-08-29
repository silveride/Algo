

#include "stdafx.h"

#include <vector>


using namespace std;

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int partition(vector<int>& array, int l, int h) {

	int p = h;
	int firstHigh = l;

	for (int i = l; i < h; ++i) {

		if (array[i] < array[p]) {
			swap(array[i], array[firstHigh]);
			++firstHigh;
		}
	} // At the end all elements to left of firstHigh are lower to p

	swap(array[firstHigh], array[p]);

	return p;
}


void qsort(vector<int>& array, int l, int h) {

	int p; // pivot element

	if (h > l) { // low highere that high

		p = partition(array, l, h);
		qsort(array, l, p - 1);
		qsort(array, p + 1, h);

	}
}


void quickSort(vector<int>& array) {

	qsort(array, 0, array.size()-1);
}