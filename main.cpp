#include <iostream>
#include <vector>

// Sorting
#include "Bubble.h"
#include "Selection.h"
#include "Insertion.h"
#include "Merge.h"
#include "Heap.h"
#include "Quick.h"

// ...
#include "Fibonacci.h"
#include "LinkedList.h"
#include "BinaryTree.h"

// leetcode
#include "AddTwoNumbers.h"
#include "ReverseNodesInKGroup.h"
#include "TwoSum.h"

// Meta puzzles
#include "Cafeteria.h"
#include "DirectorOfPhotography.h"
#include "Kaitenzushi.h"

#include <thread>
#include <functional>

using namespace std;

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
	vector<int> arr = {10,15,8,11,3,6}; // random_n(100);

	unique_ptr<NS_SORTING::Sort> s = make_unique<NS_SORTING::Heap>(arr);
	
	cout << "Original" << endl;
	NS_SORTING::Heap::printArr(arr);
	
	s->sort();
	
	cout << "Sorted" << endl;
	NS_SORTING::Heap::printArr(arr);
	*/

	// NS_FIBONACCI::test();

	// NS_ADD_TWO_NUMBERS::test();

	// NS_BinaryTree::test();

	// NS_REVERSE_NODE_K_GROUP::test();

	// NS_LinkedList::test();

	// NS_CAFETERIA::test();

	// NS_DIRECTOR_OF_PHOTOGRAPHY::test();

	// NS_KAITENZUSHI::test();
	
	 NS_TWO_SUM::test();


	return 0;
}

