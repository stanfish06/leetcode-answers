#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        int prefix_last = 1;
        int suffix_last = 1;
        for (int i = 0; i < n; i++) {
            result[i] *= prefix_last;
            result[n - 1 - i] *= suffix_last;
            prefix_last = nums[i] * prefix_last;
            suffix_last = nums[n - 1 - i] * suffix_last;
        }
        return result;
    }
};
