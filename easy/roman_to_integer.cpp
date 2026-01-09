#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> lookup = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int res_sum = 0;
        int cur_val = 0;
        int nxt_val = 0;
        for(int i = 0; i < s.size(); i++) {
            cur_val = lookup[s[i]];
            if (i == s.size() - 1) {
                res_sum += cur_val;
                continue;
            }
            nxt_val = lookup[s[i+1]];
            if (nxt_val > cur_val && nxt_val <= cur_val * 10) {
                res_sum += nxt_val - cur_val;
                i++;
            } else {
                res_sum += cur_val;
            }
        };
        return res_sum;
    }
};
