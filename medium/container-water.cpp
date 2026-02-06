#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left_idx = 0;
        int right_idx = n - 1;
        int left_height = height[left_idx];
        int right_height = height[right_idx];
        bool move_left = left_height < right_height;
        int best_volume = min(left_height, right_height) * (right_idx - left_idx); 
        while (left_idx < right_idx) {
            if (move_left) {
                left_idx++;
            } else {
                right_idx--;
            }
            if (right_idx == left_idx) {
                break;              
            } else {
                int new_left_height = height[left_idx];
                int new_right_height = height[right_idx];
                if (new_left_height < left_height || new_right_height < right_height) {
                    continue;
                }
                left_height = new_left_height;
                right_height = new_right_height;
                int volume = min(left_height, right_height) * (right_idx - left_idx);  
                if (volume > best_volume) {
                    best_volume = volume;
                }
                move_left = left_height < right_height;
            }                      
        }
        return best_volume;
    }
};
