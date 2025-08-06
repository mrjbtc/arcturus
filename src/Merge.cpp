#include "Merge.h"
#include <iostream>
#include <vector>
#include <thread>
#include <functional>

using namespace std;
/**
 * 
 * Merge Sort is a Divide and Conquer algorithm:
 *  Divide the array into two halves.
 *  Sort each half recursively.
 *  Merge the sorted halves back together.
 * 
 *  [5, 2, 4, 7, 1, 3, 6]
 *  Split → [5, 2, 4] and [7, 1, 3, 6]
 * 
 *  Keep splitting → until 1 element per part
 * 
 *  Merge and sort at each level → until fully sorted
 * 
 */

namespace NS_SORTING { 
    void Merge::sort() {
        vector<int>& arr = Sort::arr;
    	Merge::sort(arr, 0, arr.size() - 1);
    }

    /**
     * 
     *  Keep deviding the array until only one left.
     */ 
    void Merge::sort(vector<int>& arr, size_t left, size_t right) {
        if (left >= right) {
            return;
        }
        size_t mid = (left + right) / 2;
        
        thread leftThread(
            static_cast<void (Merge::*)(vector<int>&, size_t, size_t)>(&Merge::sort), // explicitly point to exact Merge::sort overloaded method
            this, ref(arr), left, mid
        );
        thread rightThread(
            static_cast<void (Merge::*)(vector<int>&, size_t, size_t)>(&Merge::sort), // explicitly point to exact Merge::sort overloaded method
            this, ref(arr), mid + 1, right
        );

        leftThread.join();
        rightThread.join();
        

        //Merge::sort(ref(arr), left, mid);
        //Merge::sort(ref(arr), mid + 1, right);
        // merging two arrays and sorting them.
        Merge::merge(arr, left, mid, right);
    }

    void Merge::merge(vector<int>& arr, size_t left, size_t mid, size_t right) {
        // temp vector for first half (left) and second half (right)
        vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
        vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

        size_t leftIdx = 0, rightIdx = 0, combinedIdx = left;
        size_t leftSize = leftArr.size(), righSize = rightArr.size();

        // merging left and right array
        while (leftIdx < leftSize && rightIdx < righSize) {
            if (leftArr[leftIdx] <= rightArr[rightIdx]) {
                arr[combinedIdx++] = leftArr[leftIdx++];
                continue;
            }
            arr[combinedIdx++] = rightArr[rightIdx++];
        }
        // merging the remainder items
        while (leftIdx < leftSize) {
            arr[combinedIdx++] = leftArr[leftIdx++];
        }
        while (rightIdx < righSize) {
            arr[combinedIdx++] = rightArr[rightIdx++];
        }
    }
}