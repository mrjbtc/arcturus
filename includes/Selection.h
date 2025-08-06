#ifndef SELECTION_H
#define SELECTION_H

#include "Sort.h"

using namespace std;

namespace NS_SORTING {
    class Selection : public Sort {
    public:
        vector<int>& arr = Sort::arr;
        
        Selection (vector<int>& arr) : Sort(arr) {}
        
        void sort() override;
    };
}

#endif
