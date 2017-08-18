// i-heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Heap.h"



int main()
{
	Heap h;

	for (int i = 0; i < 10; i++) {
		h.insertElement(i);
	}

	h.print();

	h.deleteMax();

	h.print();
	return 0;
}

