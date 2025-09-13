/*

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?


Solution: Making sure it's less than O(n2)
	[1] In a single loop, check both ends simultaneously. From left to right and right to left.
	[2] Get the difference with target and each items in the vector: left to right and vise versa.
	[3] If the index of the difference is not equal to the current item then we have our missing partner.

*/

#include "TwoSum.h"
#include <iostream>

using namespace std;

namespace NS_TWO_SUM {
	vector<int> Solution::twoSum(vector<int>& nums, int target){

		vector<int> indexes;
        int len = nums.size();
        int left_i = 0;
        int right_i = len-1;

        while (left_i < len && right_i > 0) {

            // left to right
            auto left_it = find(nums.begin(), nums.end(), (target - nums[left_i]));
            if (left_it != nums.end()) {
                int index = left_it - nums.begin();
                if (index != left_i) {
                    indexes.push_back(index);
                    indexes.push_back(left_i);
                    break;
                }
            }

            // right to left
            auto right_it = find(nums.begin(), nums.end(), (target - nums[right_i]));
            if (right_it != nums.end()) {
                int index = right_it - nums.begin();
                if (index != right_i) {
                    indexes.push_back(index);
                    indexes.push_back(right_i);
                    break;
                }
            }

            left_i++;
            right_i--;
        }
        sort(indexes.begin(), indexes.end());
        return indexes;
	}

	void test() {
		unique_ptr<Solution> solution = make_unique<Solution>();

		vector<int> nums, output, results;
		int target;

		// Test case 1
		nums = {2,7,11,15}; target = 9; output = {0, 1};
		results = solution->twoSum(nums, target);
		cout << ((results == output) ? "PASS" : "FAILED") << endl;

		// Test case 2
		nums = {3,2,4}; target = 6; output = {1, 2};
		results = solution->twoSum(nums, target);
		cout << ((results == output) ? "PASS" : "FAILED") << endl;

		// Test case 3
		nums = {3,3}; target = 6; output = {0,1};
		results = solution->twoSum(nums, target);
		cout << ((results == output) ? "PASS" : "FAILED") << endl;

	}
}