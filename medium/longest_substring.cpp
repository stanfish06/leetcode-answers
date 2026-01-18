#include<string>
#include<unordered_map>
using namespace std;

// Note1: do not frequently use map clear as it slows things down
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        size_t best_idx_l = 0;
        size_t best_idx_r = 1;
        size_t idx_l = 0; // inclusive
        size_t idx_r = 1; // exclusive
        // could replace with ansii array
        unordered_map<char, int> lookup;
        lookup[s[0]] = 0;
        while (idx_r < s.size()) {
            if (lookup.contains(s[idx_r]) && lookup[s[idx_r]] >= idx_l && lookup[s[idx_r]] < idx_r) {
                if ((idx_r - idx_l) > (best_idx_r - best_idx_l)) {
                    best_idx_r = idx_r;
                    best_idx_l = idx_l;
                }
                idx_l = lookup[s[idx_r]] + 1;
            } 
            lookup[s[idx_r]] = idx_r;
            idx_r++;
        }
        // last check after reaching the end
        if ((idx_r - idx_l) > (best_idx_r - best_idx_l)) {
            best_idx_r = idx_r;
            best_idx_l = idx_l;
        }
        return best_idx_r - best_idx_l;
    }
};
