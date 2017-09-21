// ConsoleApplication19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<iostream>
#include<unordered_map>
#include<map>

using namespace std;

struct List {
	int key; // key on map.
	int val;
	struct List* next, *prev;
	List(int ikey, int ival) : key(ikey), val(ival),next(NULL),prev(NULL) {}
	List() :key(0), val(0), next(NULL), prev(NULL) {}
};

struct PointNode {
	List* ptr;
	PointNode() : ptr(NULL) {}
};

class LRUCache {
	int cap;
	int in_cache;
	// Cyclic list

	List* head;
	List* last;
	map<int, PointNode> pointMap;


public:
	LRUCache(int capacity) : cap(capacity), head(NULL),last(NULL), in_cache(0) {
		// create the 
	}

	int get(int key) {
		// search the list
		List* thead = head;
		List* node = pointMap[key].ptr;

		if ( node == NULL) {
			return-1;
		}
		else {
			// in list
			// re-balance list. no count change
			// eject node

			if (node == head) return head->val;

			touchNode(node);
		}
		return node->val;
	}

	void put(int key, int value) {

		List* node = pointMap[key].ptr;

		if (node != NULL) {
			node->val = value;

			if (node == head) return;

			touchNode(node);
		}
		else { // Create node
			node = new List(key, value);
			node->next = head;
			node->prev = NULL;
			if (head) {
				head->prev = node;
			}
			else {
				last = node;
			}
			head = node;

			if (in_cache >= cap) {
				pointMap[last->key].ptr = NULL;
				if (last->prev)
					last->prev->next = NULL;
				List* temp = last;
				last = last->prev;
				delete temp;
			}
			else {
				++in_cache;
			}

		}

		// add to key table
		pointMap[key].ptr = node;

	}

	void touchNode(List* node) {

		if (node->prev)
		node->prev->next = node->next;

		if (node->next)
			node->next->prev = node->prev;
		else // next to last node
			if (head != last)
				last = node->prev;
		// attach the node to head and eject last one if over capacity
		node->next = head;
		head->prev = node;
		node->prev = NULL;
		head = node;

	}
};


/*

LRUCache cache = new LRUCache( 2  capacity );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

*/

int main()
{

	LRUCache& cache = *(new LRUCache(2));
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3); // no more two
	cout << cache.get(2) << endl;
	cache.put(4, 4);
	cout << cache.get(1) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;

    return 0;
}

