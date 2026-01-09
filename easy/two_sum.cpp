// Two Sum
/*
 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 You may assume that each input would have exactly one solution, and you may not use the same element twice.               
 You can return the answer in any order.
*/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        int idx1 = 0;
        int idx2 = 0;
        lookup[target - nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (lookup.contains(nums[i])) {
                idx1 = i;
                idx2 = lookup[nums[i]];
            }
            lookup[target - nums[i]] = i;
        }
        return {idx1, idx2};
    }
};
