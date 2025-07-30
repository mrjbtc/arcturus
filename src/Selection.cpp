#include "Selection.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 *  
 * 
 * How It Works (Step-by-Step)
 * Given an array: [5, 2, 4, 1, 3]
 * Pass 1:
 * Find the smallest number in [5, 2, 4, 1, 3] → 1
 * 
 * Swap it with the first element → [1, 2, 4, 5, 3]
 * 
 * Pass 2:
 * Find the smallest in [2, 4, 5, 3] → 2
 * 
 * Already in correct place → [1, 2, 4, 5, 3]
 * 
 * Pass 3:
 * Find the smallest in [4, 5, 3] → 3
 * 
 * Swap with 4 → [1, 2, 3, 5, 4]
 * 
 * Pass 4:
 * Find the smallest in [5, 4] → 4
 * 
 * Swap with 5 → [1, 2, 3, 4, 5]
 * 
 * Now it’s sorted!
 * 
 */ 
void Selection::sort() {
    vector<int>& arr = Sort::arr;
	size_t size = arr.size();
    
    for (size_t i = 0; i < size - 1; ++i) {
    	size_t minIdx = i;
        for (size_t j = i+1; j < size; ++j) {
            if (arr[j] < arr[minIdx]) {
            	minIdx = j;
            }
        }
        std::swap(arr[i], arr[minIdx]);
    }
}