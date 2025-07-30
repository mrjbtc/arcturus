#ifndef SORT_H
#define SORT_H

#include <vector>

using namespace std;

class Sort {

private:
    Sort();

protected:
    vector<int>& arr;

public:
    Sort(vector<int>& arr) : arr(arr){}

    virtual void sort() = 0;  // pure virtual function
    virtual ~Sort() = default;
};

#endif