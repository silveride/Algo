#pragma once

/**/

#include <iostream>

#define H_DEBUG

#ifdef H_DEBUG

#define H_LOG(str) cout<<str<<endl;

#elif

#define H_LOG(str)  ;

#endif
	


class Heap {

	const static size_t max_queue = 256;

	// Strucure
	int  queue[max_queue];
	int queue_size;


	void bubbleUp(int index);
	void bubbleDown(int index);

public:

	// operations
	Heap();
	int indexParent(int n);
	int indexYoungChild(int n);
	void insertElement(int elem);
	int deleteMax();

	void heapSort(std::vector<int>& result);

	void print();


};