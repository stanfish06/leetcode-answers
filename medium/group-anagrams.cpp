#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> result;
        vector<string> strs_sorted;
        vector<int> argsort(n);
        iota(argsort.begin(), argsort.end(), 0);
        for (int i = 0; i < n; i++) {
            string word = strs[i];
            sort(word.begin(), word.end());
            strs_sorted.push_back(word);
        }
        sort(argsort.begin(), argsort.end(), [&strs_sorted](int i, int j) {return strs_sorted[i] < strs_sorted[j];});
        int root_i = -1;
        vector<string> bag;
        for (int i = 0; i < n; i++) {
            if (root_i < 0) {
                root_i = i;
                bag.push_back(strs[argsort[i]]);
            } else if (strs_sorted[argsort[i]] == strs_sorted[argsort[root_i]]) {
                bag.push_back(strs[argsort[i]]);
            } else {
                result.push_back(bag);
                bag.clear();
                root_i = i;
                bag.push_back(strs[argsort[i]]);
            }
        }
        if (!bag.empty()) {
            result.push_back(bag);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> test = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = sol.groupAnagrams(test);
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << ",";
        }
        cout << "]" << endl;
    }
}
