#ifndef INSERTION_H
#define INSERTION_H

#include "Sort.h"

using namespace std;

class Insertion : public Sort {
public:
    vector<int>& arr = Sort::arr;
    
    Insertion (vector<int>& arr) : Sort(arr) {}

    void sort() override;
};

#endif
