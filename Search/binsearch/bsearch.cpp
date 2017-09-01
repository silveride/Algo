

#include "stdafx.h"

#include "bsearch.h"

#include<vector>



using namespace std;


int bSearch(vector<int> array, int elem, int low, int high) {


	if (low > high) return -1;

	int middle = (low + high) / 2;

	if (array[middle] < elem) {

		return bSearch(array, elem, middle + 1, high);
	}
	else if (array[middle] > elem) {
		return bSearch(array, elem, low, middle - 1);
	}
	else {
		return  middle;
	}

	return -1;
}



int binSearch(vector<int>& array, int elem) {

	// Find middle and check
	return bSearch(array, elem,0,array.size()-1);


}