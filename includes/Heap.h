#ifndef HEAP_H
#define HEAP_H

#include "Sort.h"

using namespace std;

class Heap : public Sort {
private:
	void heapify();
public: 
	vector<int>& arr = Sort::arr;

	Heap (vector<int>& arr) : Sort(arr) {}

	void sort() override; 
};

#endif