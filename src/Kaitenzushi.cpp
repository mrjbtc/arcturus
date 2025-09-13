
/*

There are N dishes in a row on a kaiten belt, with the ith dish being of type Di. 
Some dishes may be of the same type as one another.

You're very hungry, but you'd also like to keep things interesting. The N dishes will arrive in front of you, 
one after another in order, and for each one you'll eat it as long as it isn't the same type as any of the previous K dishes you've eaten. 
You eat very fast, so you can consume a dish before the next one gets to you. Any dishes you choose not to eat as they pass will be eaten by others.

Determine how many dishes you'll end up eating.

Please take care to write a solution which runs within the time limit.

Constraints
1 <= N <= 500,000
1 <= K <= N
1 <= Di <= 1,000,000

##################################################

Sample test case #1
N = 6
D = [1, 2, 3, 3, 2, 1]
K = 1
Expected Return Value = 5

##################################################

Sample test case #2
N = 6
D = [1, 2, 3, 3, 2, 1]
K = 2
Expected Return Value = 4

##################################################

Sample test case #3
N = 7
D = [1, 2, 1, 2, 1, 2, 1]
K = 2
Expected Return Value = 2


Sample Explanation
In the first case, the dishes have types of [1, 2, 3, 3, 2, 1] so you'll eat the first 3 dishes, 
skip the next one as it's another type-3 dish, and then eat the last 2. 

In the second case, you won't eat a dish if it has the same type as either of the previous 2 dishes you've eaten. After eating the first, second, and third dishes, 
you'll skip the fourth and fifth dishes as they're each the same type as one of the last 2 dishes that you've eaten. You'll then eat the last dish, consuming 4 dishes total.

In the third case, once you eat the first two dishes you won't eat any of the remaining dishes.

Solutions: This is O(n).
	[1] Loop through N.
	[2] Data structures for storing previous dish;
		map - key/value pairs where key is the dish and value is boolean. 
			- If no longer within the range K, then set to false.
			- And it's O(1).
		deque - Double ended queue where each dish will be push at the right end.
			  - While the left end is no longer within the range K, hence, remove it.
	[3] Increment counter for each dish, and save it to deque as previous with the range of K.
	[4] At the same time insert the current dish into the map and set it to true.
	[5] If the current dish is already in previous, decrement the counter.
	[6] Remove the out of range distance K in the deque, as well as set it to false in the map.



	NOTE: deque should be enough for this solution however, finding item within dequeue is resource intensive.
		  Therefore optimizing it with map, which is O(1). See line 98.


*/

#include "Kaitenzushi.h"
#include <iostream>
#include <deque>
#include <map>

using namespace std;

namespace NS_KAITENZUSHI {

	int getMaximumEatenDishCount(int N, vector<int> D, int K) {
		
		int count = 0, size = 0, current_dish;
		map<int, bool> m_previous;
		deque<int> d_previous;
		bool isPrevious = false;
  

		for(int i = 0; i < N; i++) {
			
		  	current_dish = D[i];
			count++;

			//if (isPrevious && find(previous.begin(), previous.end(), current_dish) != previous.end()) {
			if (isPrevious && m_previous[current_dish] == true) {
				count--;
			} else {
				d_previous.push_back(current_dish);
				m_previous[current_dish] = true;
       			size++;
			}
			
			if(size > K && isPrevious) {
				m_previous[d_previous.front()] = false;
				d_previous.pop_front();
        		size--;
			}
			isPrevious = true;
		}

		return count;
	}

	void test() {
		int N, K, count = 0;
		vector<int> D;

		// Test case 1
		N = 6;
		D = {1, 2, 3, 3, 2, 1};
		K = 1;

		count = getMaximumEatenDishCount(N, D, K);
		cout << ((count == 5) ? "PASS" : "FAILED")<< endl;

		// Test case 2
		N = 6;
		D = {1, 2, 3, 3, 2, 1};
		K = 2;

		count = getMaximumEatenDishCount(N, D, K);
		cout << ((count == 4) ? "PASS" : "FAILED") << endl;

		// Test case 3
		N = 7;
		D = {1, 2, 1, 2, 1, 2, 1};
		K = 2;
		count = getMaximumEatenDishCount(N, D, K);
		cout << ((count == 2) ? "PASS" : "FAILED") << endl;
	}
}

