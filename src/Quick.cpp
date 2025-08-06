#include "Quick.h"
#include <iostream>
#include <vector>

using namespace std;

namespace NS_SORTING {
	void display(vector<int> arr, int i);
	/**
	 * 
	 * Quick Sort is a divide-and-conquer sorting algorithm that works by:
	 * Choosing a pivot element
	 * 
	 * Partitioning the array into two subarrays:
	 * ** Elements less than the pivot
	 * ** Elements greater than the pivot
	 * 
	 * Recursively sorting the subarrays
	 * 
	 * {10, 5, 8, 9, 1, 5, 6, 3, 0, 4};
	 * pivot = 4
	 * low = 0
	 */ 
	void Quick::sort() {
		vector<int>& arr = Sort::arr;
		Quick::quick(arr, 0, arr.size() - 1);
	}

	int Quick::sort(vector<int>& arr, int low, int high) {
		int pivot = arr[high];
		int i = low - 1;

		for (int idx = low; idx < high; idx++) {
			if (arr[idx] <= pivot) {
				swap(arr[++i], arr[idx]);
			}
		}
		swap(arr[i + 1], arr[high]);
		return (i + 1);
	}

	void Quick::quick(vector<int>& arr, int low, int high) {
		if (low < high) {
			int partitionIdx = Quick::sort(arr, low, high);
			Quick::quick(arr, low, partitionIdx - 1);
			Quick::quick(arr, partitionIdx + 1, high);
		}
	}

	void display(vector<int> arr, int i) {

		for (int item: arr) {
				cout << item << " ## ";
		}
		cout << endl;
	}
}

