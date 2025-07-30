#ifndef QUICK_H
#define QUICK_H

#include "Sort.h"

using namespace std;

class Quick : public Sort {
public:
    vector<int>& arr = Sort::arr;
    
    Quick (vector<int>& arr) : Sort(arr) {}
    
    void sort() override;
    int sort(vector<int>& arr, int low, int high);
    void quick(vector<int>& arr, int low, int high);
};

#endif
