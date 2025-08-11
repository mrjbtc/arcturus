#include <iostream>
#include "Heap.h"

using namespace std;

namespace NS_SORTING {

	/**
	 * 
	 * Rebuild array into max heap = root or arr[0] is the MAX
	 */ 
	void Heap::heapify(vector<int> &arr, size_t size, size_t nodeIdx) {

		size_t largest = nodeIdx;
		size_t left = (2 * nodeIdx) + 1; // (2*i)+1
		size_t right = (2 * nodeIdx) + 2; // (2*i)+2

		// if largest is left index
		if (left < size && arr[left] > arr[largest]) {
			largest = left;
		}

		// if largest is right index
		if (right < size && arr[right] > arr[largest]) {
			largest = right;
		}

		if (largest != nodeIdx) {
			swap(arr[nodeIdx], arr[largest]);

			// recursive heapify
			Heap::heapify(arr, size, largest);
		}

	}


	void Heap::sort() {
		vector<int>& arr = Sort::arr;
		size_t size = sizeof(arr)/sizeof(arr[0]);
		
		// Max heap = root or arr[0] is the greatest
		for (int i = (size / 2-1); i >= 0; i--) {
			Heap::heapify(arr, size, i);	
		}

		// move the MAX arr[0] to the end and heapify until it's sorted.
		for (int i = size - 1; i > 0; i--) {
			swap(arr[0], arr[i]);
			Heap::heapify(arr, i, 0);
		}
		
	}

	void Heap::printArr(vector<int>& arr) {
		for (int item: arr) {
			cout << item << " ";
		}
		cout << endl;
	}

}