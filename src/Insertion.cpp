#include "Insertion.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * 
 * Imagine you're sorting playing cards in your hand:

 * You pick up cards one by one.
 * 
 * Each time, you place the new card in the correct spot among the cards you're already holding, shifting others if necessary.
 * 
 * This is exactly how insertion sort works.
 * 
 * 
 * 
 * 🔁 Step-by-Step Example
 * Given array: [5, 2, 4, 6, 1, 3]
 * 
 * Start from the second element (index 1) — treat the first element as "sorted".
 * 
 * Pass 1:
 * Compare 2 with 5 → insert before it
 * 
 * Result: [2, 5, 4, 6, 1, 3]
 * 
 * Pass 2:
 * Compare 4 with 5 → insert before 5
 * 
 * Result: [2, 4, 5, 6, 1, 3]
 * 
 * Pass 3:
 * 6 is already in place → [2, 4, 5, 6, 1, 3]
 * 
 * Pass 4:
 * Insert 1 before 2 → [1, 2, 4, 5, 6, 3]
 * 
 * Pass 5:
 * Insert 3 before 4 → [1, 2, 3, 4, 5, 6] 🎉
 * 
 */ 
void Insertion::sort() {
    vector<int>& arr = Sort::arr;
    
    size_t size = arr.size();
    for (size_t i = 1; i < size; ++i) {
        int item = arr[i]; // start from second item
        size_t x = i - 1; // previous index

        while (x >= 0 && arr[x] > item) {
			arr[x + 1] = arr[x];
        	x--;
        }
        arr[x + 1] = item;
    }
}