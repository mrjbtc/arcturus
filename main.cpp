#include <iostream>
#include <vector>
#include <chrono>

#include "Bubble.h"
#include "Selection.h"
#include "Insertion.h"
#include "Merge.h"
#include "Quick.h"
#include "Fibonacci.h"
#include "LinkedList.h"
#include "AddTwoNumbers.h"
#include "BinaryTree.h"

#include <thread>
#include <functional>

using namespace std;
using namespace std::chrono;

vector<int> random_n(size_t limit=10000) {
    vector<int> n;
    srand(time(0));
    for (size_t i = 0; i < limit; i++) {
        n.push_back(rand());
    }
    return n;
}

int main () {

	// Sorting Algorithm i.e Bubble, Insertion, Merge, Quick, and Selection
	/*
	vector<int> arr = random_n();
	auto start_s_clock = steady_clock::now();
	cout << "[Dataset size]: " << arr.size() << endl;

	unique_ptr<NS_SORTING::Sort> s = make_unique<NS_SORTING::Merge>(arr);
	s->sort();
	for (int val: arr) {
	    cout << val << " ";
	}

	auto end_s_clock = steady_clock::now();
	auto clock_diff = end_s_clock - start_s_clock;
	cout << endl << "[Duration]: " << duration <double, milli> (clock_diff).count() << " ms" << endl;
	*/

	
	// NS_FIBONACCI::test();

	// NS_ADD_TWO_NUMBERS::test();

	// NS_BinaryTree::test();

	return 0;
}

