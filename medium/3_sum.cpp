#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> solutions;
        for (int i = 0; i < n-2; i++) {
            int val_l = nums[i];
            if (i > 0) {
                if (val_l == nums[i - 1]) {
                    continue;
                }
            } 
            int ptr_mid = i + 1;
            int ptr_right = n - 1;
            while (ptr_mid < ptr_right) {
                int val_m = nums[ptr_mid];
                int val_r = nums[ptr_right];
                if (val_m + val_r == -val_l) {
                    vector<int> sol = {val_l, val_m, val_r};
                    solutions.push_back(sol);
                    ptr_mid++;
                    ptr_right--;
                    while(ptr_mid < ptr_right && nums[ptr_mid] == nums[ptr_mid - 1]) ptr_mid++;
                    while(ptr_mid < ptr_right && nums[ptr_right] == nums[ptr_right + 1]) ptr_right--;
                } else if (val_m + val_r > -val_l) {
                    ptr_right--;
                } else {
                    ptr_mid++;
                }
            }
        }
        return solutions;
    }
};

int main() {
    Solution sol;
    vector<int> test = {-1,0,1,2,-1,-4};
    vector<vector<int>> answer = sol.threeSum(test);
    for (const auto& num_vec : answer) {
        cout << "[";
        for (const auto& num : num_vec) {
            cout << num << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}
