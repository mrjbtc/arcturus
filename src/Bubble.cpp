#include "Bubble.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * 
 * 
 * How It Works (Step-by-Step)
 * Let’s sort: [5, 1, 4, 2, 8]
 * 
 * Pass 1:
 * Compare and swap where needed:
 * 
 * Compare 5 and 1 → swap → [1, 5, 4, 2, 8]
 * 
 * Compare 5 and 4 → swap → [1, 4, 5, 2, 8]
 * 
 * Compare 5 and 2 → swap → [1, 4, 2, 5, 8]
 * 
 * Compare 5 and 8 → OK → [1, 4, 2, 5, 8]
 * 
 * 👉 8 is now in the correct position
 * 
 * Pass 2:
 * Compare 1 and 4 → OK
 * 
 * Compare 4 and 2 → swap → [1, 2, 4, 5, 8]
 * 
 * Compare 4 and 5 → OK
 * 
 * 👉 5 is now in place
 * 
 * Repeat until fully sorted:
 * Final array: [1, 2, 4, 5, 8]
 * 
 */ 
void Bubble::sort() {
    vector<int>& arr = Sort::arr;
    size_t size = arr.size();
    bool swapped;
    
    for (size_t i = 0; i < size - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;  // everything is sorted
        }
    }
}
