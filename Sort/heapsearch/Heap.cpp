#include "stdafx.h"

#include "Heap.h"

using namespace std;

Heap::Heap(): queue_size(0) {
	H_LOG("Initialising Heap..")
}

int Heap::indexParent(int n) {
	if (n == 0) return -1; // root parent

	return (n -1 ) / 2;
}

int Heap::indexYoungChild(int n) {
	return n * 2 + 1;
}

void Heap::bubbleUp(int n) {
	
	int pIndex = indexParent(n);

	if (pIndex == -1) return; //base condition

	// swap if greater. O(1)
	if (queue[n] > queue[pIndex]) {

		int tmp = queue[n];
		queue[n] = queue[pIndex];
		queue[pIndex] = tmp;

		bubbleUp(pIndex);
	}
}

void Heap::insertElement(int elem) {
	H_LOG("Inserting element" << elem << " on queue_size:" << queue_size);

	// Insert back track
	queue[queue_size] = elem;
	bubbleUp(queue_size); // O(lg n) . Only traversing up one branch.
	queue_size++;
}

void Heap::bubbleDown(int index) {

	int child = indexYoungChild(index);

	int min_index = index;
	// The two leafs
	for (int i = 0; i <= 1; ++i) {

		if (child + i < queue_size) {
			min_index = (queue[min_index] > queue[child + i] ? min_index : child + i);
		}
	}

	if (min_index != index) {
		int temp = queue[min_index];
		queue[min_index] = queue[index];
		queue[index] = temp;
		bubbleDown(min_index);
	}
	
}


int Heap::deleteMax() {

	// Remove the top most element

	int ret = queue[0];

	queue[0] = queue[queue_size - 1];

	bubbleDown(0);

	queue_size--;

	return ret;
}

void Heap::heapSort(std::vector<int>& result) {

}

void Heap::print() {

	cout << "Printing queue of size" <<queue_size<< endl;

	// print the array order. good for debuggin.
	for (int i = 0; i < queue_size; ++i) {
		cout << queue[i] << endl;
	}

}