#ifndef HEAP_H
#define HEAP_H

#include "Sort.h"

using namespace std;

namespace NS_SORTING {
	class Heap : public Sort {
	private:
		static void heapify(vector<int> &arr, size_t size, size_t nodeIdx);
	public: 
		vector<int>& arr = Sort::arr;

		Heap (vector<int>& arr) : Sort(arr) {}

		void sort() override;
		static void printArr(vector<int>& arr);
	};
}

#endif