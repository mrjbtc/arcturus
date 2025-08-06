#ifndef MERGE_H
#define MERGE_H

#include "Sort.h"

using namespace std;

namespace NS_SORTING {
    class Merge : public Sort {
    private:
        void sort(vector<int>& arr, size_t left, size_t right);
        void merge(vector<int>& arr, size_t left, size_t mid, size_t right);
        
    public:
        vector<int>& arr = Sort::arr;
        
        Merge (vector<int>& arr) : Sort(arr) {}
        
        void sort() override;
    };
}

#endif
