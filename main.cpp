#include <iostream>
#include <vector>
#include "Bubble.h"
#include "Selection.h"
#include "Insertion.h"
#include "Merge.h"
#include "Quick.h"
#include "Fibonacci.h"
#include "LinkedList.h"
#include "AddTwoNumbers.h"
#include <cfloat>
#include <climits>

using namespace std;

void testAddTwoNumbers() {
	
	// test case 1
	ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3))); // [2, 4, 3]
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4))); // [5, 6, 4]

    // test case 2
    //ListNode* l1 = new ListNode(0);
    //ListNode* l2 = new ListNode(0);

    // test case 3
    // [9,9,9,9,9,9,9]
    // [9,9,9,9]
    // ListNode* l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))));
    // ListNode* l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9))));

    ListNode* res = test(l1, l2);
    printListNodes(res);
    delete res;
}

int main () {

	// Sorting Algorithm i.e Bubble, Insertion, Merge, Quick, and Selection
	/*
	vector<int> arr = {10, 5, 8, 9, 1, 5, 6, 3, 0, 4};
	unique_ptr<Sort> s = make_unique<Bubble>(arr);
	s->sort();
	for (int val: arr) {
	    cout << val << " ";
	}
	cout << endl;
	*/
	
	// Fibonacci
	// Fibonacci Fibonacci(15);

	// Add two numbers 
	// testAddTwoNumbers();
	
	
	return 0;
}

