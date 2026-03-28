#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        _findKthLargest(nums, 0, nums.size() - 1, k - 1);
        return nums[k - 1];
    }

private:
    pair<int,int> findPivot(vector<int>& nums, int lo, int hi) {
        int pivot_l_idx = lo;
        int pivot_r_idx = lo;
        int pivot = nums[hi];
        // not the best approach, todo, think about how to advance with 3 pointers so limit total iterations
        for (int j = lo; j < hi; j++) {
            if (nums[j] > pivot) {
                swap(nums[j], nums[pivot_l_idx]);
                pivot_l_idx++;
                pivot_r_idx++;
            } 
        }
        for (int j = pivot_l_idx; j < hi; j++) {
            if (nums[j] == pivot) {
                swap(nums[j], nums[pivot_r_idx]);
                pivot_r_idx++;
            } 
        }
        swap(nums[hi], nums[pivot_r_idx]);
        return make_pair(pivot_l_idx, pivot_r_idx);
    }
    void _findKthLargest(vector<int>& nums, int lo, int hi, int k) {
        if (lo > k || hi < k) {
            return;
        }
        auto pivots = findPivot(nums, lo, hi);
        if (k >= pivots.first && k <= pivots.second) {
            return;
        } else if (k > pivots.second) {
            return _findKthLargest(nums, pivots.second + 1, hi, k);
        } else {
            return _findKthLargest(nums, lo, pivots.first - 1, k);
        }
    }
};

int main() {
    Solution sol;
    vector<int> test = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    int res = sol.findKthLargest(test, 20);
    cout << res << endl;
}
