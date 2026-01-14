#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n_uniq = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) {
                nums[n_uniq] = nums[i];
                n_uniq++;
            }
        }
        return n_uniq;
    }
};
