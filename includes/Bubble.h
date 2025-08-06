#ifndef BUBBLE_H
#define BUBBLE_H

#include "Sort.h"

using namespace std;

namespace NS_SORTING {
    class Bubble : public Sort {
    public:
        vector<int>& arr = Sort::arr;
        
        Bubble (vector<int>& arr) : Sort(arr) {}
        
        void sort() override;
    };
}

#endif
