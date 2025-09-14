/*

You're trying to open a lock. The lock comes with a wheel which has the integers from 1 to N
arranged in a circle in order around it (with integers 1 and N adjacent to one another). The wheel is initially pointing at 1.

It takes 1 second to rotate the wheel by 1 unit to an adjacent integer in either direction, and it takes no time to select an integer once the wheel is 
pointing at 1.

The lock will open if you enter a certain code. The code consists of a sequence of M integers, the ith of which is C1.
Determine the minimum number of seconds required to select all M of the code's integers in order.

Constraints

3 <= N <= 50,000,000
1 <= M <= 1,000
1 <= Ci <= N

#########################################

Sample test case #1
N = 3
M = 3
C = [1, 2, 3]
Expected Return Value = 2

#########################################

Sample test case #2
N = 10
M = 4
C = [9, 4, 4, 8]
Expected Return Value = 11

#########################################

Sample Explanation

In the first case, there are 3 integers on the lock, and the sequence of integers to be selected is [1,2,3].
One optimal way to enter the code is: select 1 -> rotate to 2 (1 second) -> select 2 -> rotate to 3 (1 second) -> select 3.
The total time taken is 1 + 1 = 2 seconds.

In the second case, the lock consists of the integers 1 through 10, and the sequence to be selected is [9,4,4,8]. 
One optimal way to enter the code is: rotate from 1 backwards to  9 (2 seconds) -> select 9 -> rotate towards to 4(5 seconds) 
-> select 4 twice -> rotate forwards 8 (4 seconds) -> select 8. The total time taken is 2 + 5 + 4 = 11 seconds.


Solution:
	[1] Loop through the code combination C.
	[2] Calculate the left (counter clockwise), and right (clockwise) distance; the smallest will be used.
	[3] Formula for distance are;
		counter clockwise: FROM minus Ci
		clockwise:         Ci minus FROM

		if the difference is negative, ADD N.
	[4] Move the starting point (FROM) to next Ci.
*/

#include "RotaryLock.h"
#include <iostream>

using namespace std;

namespace NS_ROTARY_LOCK {

	long long getMinCodeEntryTime(int N, int M, vector<int> C) {

		long long ctr = 0;
		int left_distance = 0;
		int right_distance = 0;
		int from = 1; // starting point

		for (int c: C) {
			
			left_distance = from - c;
			right_distance = c - from;

			// making sure left and right distance are positive.
			if (left_distance < 0) {
				left_distance += N; 
			}

			if (right_distance < 0) {
				right_distance += N; 
			}

			if (left_distance < right_distance) {
				ctr += left_distance;
				from = c;
				continue;
			}

			ctr += right_distance;
			from = c;
		}
	
		return ctr;
	}

	void test() {

		int N, M;
		vector<int> C;
		long long output;

		// Test case #1
		N = 3;
		M = 3;
		C = {1, 2, 3};
		output = 2;

		cout << (output == getMinCodeEntryTime(N, M, C) ? "PASS" : "FAILED") << endl;

		// Test case #2
		N = 10;
		M = 4;
		C = {9, 4, 4, 8};
		output = 11;

		cout << (output == getMinCodeEntryTime(N, M, C) ? "PASS" : "FAILED") << endl;

	}
}
