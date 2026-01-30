#include<vector>
#include<iostream>
using namespace std;

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int sz = nums.size();
//         int l_idx = 0;
//         int r_idx = sz;
//         int rot_idx = 0;
//         int m_idx = 0;
//         while((r_idx - l_idx) > 0) {
//             m_idx = (r_idx + l_idx) / 2;
//             if (m_idx == 0) {
//                 break;
//             }
//             int a = nums[m_idx - 1];
//             int b = nums[m_idx];
//             if (b < a) {
//                 rot_idx = m_idx;
//                 break;
//             } else {
//                 if (m_idx == sz - 1) {
//                     break;
//                 }
//                 if (a >= nums[0]) {
//                     if (l_idx == m_idx - 1) {
//                         l_idx = m_idx;
//                     } else {
//                         l_idx = m_idx - 1; 
//                     }
//                 } else {
//                     if (r_idx == m_idx + 1) {
//                         r_idx = m_idx;
//                     } else {
//                         r_idx = m_idx + 1; 
//                     }
//                 }
//             }
//         }
//         int l_max = nums[0];
//         if (rot_idx > 0) {
//             l_max = nums[rot_idx - 1];
//         }
//         int r_max = nums[sz - 1];
//         int r_min = nums[rot_idx];
//         if (target < r_min) {
//             return -1;
//         }
//         if (target <= r_max) {
//             l_idx = rot_idx;
//             r_idx = sz;
//         } else if (target <= l_max) {
//             l_idx = 0;
//             r_idx = rot_idx;
//         } else {
//             return -1;
//         }
//         while((r_idx - l_idx) > 0) {
//             m_idx = (r_idx + l_idx) / 2;
//             if (nums[m_idx] == target) {
//                 return m_idx;
//             } else if (nums[m_idx] < target) {
//                 l_idx = m_idx + 1;
//             } else {
//                 r_idx = m_idx; 
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        int l_idx = 0;
        int r_idx = sz;
        while (r_idx - l_idx > 0) {
            int m_idx = (r_idx + l_idx) / 2;
            cout << m_idx << endl;
            if (nums[m_idx] == target) {
                return m_idx;
            }
            if (nums[m_idx] > nums[l_idx]) {
                if (target > nums[m_idx] || target < nums[l_idx]) {
                    l_idx = m_idx + 1;
                } else {
                    r_idx = m_idx;
                }
            } else {
                if (target > nums[sz - 1] || target < nums[m_idx]) {
                    r_idx = m_idx;
                } else {
                    l_idx = m_idx + 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> test = {7,8,1,2,3,4,5,6};
    cout << sol.search(test, 2) << endl;
}

