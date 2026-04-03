#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> _current;
        searchCand(candidates, results, 0, target, _current);
        return results;
    }
private:
    void searchCand(vector<int>& candidates, vector<vector<int>>& results, int ptr, int target, vector<int>& current) {
        if (ptr >= candidates.size()) {
            return;
        }
        int v = candidates[ptr];
        int next = target - v;
        if (next == 0) {
            current.push_back(v);
            results.push_back(current);
            current.pop_back();
        } else {
            if (next > 0) {
                current.push_back(v);
                searchCand(candidates, results, ptr, next, current);
                current.pop_back();
            }
        }
        if (target > 0) {
            searchCand(candidates, results, ptr + 1, target, current);
        }
    }
};


//
//
// This version is very slow due to many push backs of vectors, think about the difference between forward and backward construction
// #include <vector>
// #include <iostream>
// using namespace std;
//
// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> result_ptr;
//         searchCand(candidates, result_ptr, 0, target, 0);
//         for (auto& res : result_ptr) {
//             for (auto& x : res) {
//                 x = candidates[x];
//             }
//         }
//         return result_ptr;
//     }
//
// private:
//     pair<int, int> searchCand(vector<int>& candidates, vector<vector<int>>& result_ptr, int ptr, int target, int current) {
//         int start_i = result_ptr.size() - 1; 
//         if (start_i == -1) {
//             start_i = 0;
//         }
//         if (ptr >= candidates.size()) {
//             return make_pair(start_i, start_i);
//         }
//         int v = candidates[ptr];
//         int next = current + v;
//         if (next == target) {
//             result_ptr.push_back({ptr});
//         } else {
//             if (next < target) {
//                 auto index_pair = searchCand(candidates, result_ptr, ptr, target, next);
//                 if (result_ptr.size() > 0) {
//                     if ((index_pair.second - index_pair.first) > 0) {
//                         for (int i = index_pair.first; i < index_pair.second; i++) {
//                             if (ptr <= result_ptr[i].back()) {
//                                 result_ptr[i].push_back(ptr);
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         if (current < target) {
//             searchCand(candidates, result_ptr, ptr + 1, target, current);
//         }
//         return make_pair(start_i, result_ptr.size());
//     }
// };

int main() {
    Solution sol;
    vector<int> test = {1, 2, 3};
    auto res = sol.combinationSum(test, 3);
    for (auto &cand : res) {
        cout << "[";
        for (int v : cand) {
            cout << v << ", ";
        }
        cout << "]" << endl;
    }
}


// #include <vector>
// #include <iostream>
// using namespace std;
//
// class Solution {
// public:
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         return searchCand(candidates, 0, target, 0);
//     }
// private:
//     vector<vector<int>> searchCand(vector<int>& candidates, int ptr, int target, int current) {
//         if (ptr >= candidates.size()) {
//             return {};
//         }
//         vector<vector<int>> bag;
//         int v = candidates[ptr];
//         int next = current + v;
//         if (next == target) {
//             bag.push_back({v});
//         } else {
//             if (next < target) {
//                 auto res = searchCand(candidates, ptr, target, next);
//                 if (res.size() > 0) {
//                     for (auto &cand : res) {
//                         cand.push_back(v);
//                         bag.push_back(cand);
//                     }
//                 }
//             }
//         }
//         if (current < target) {
//             auto res = searchCand(candidates, ptr + 1, target, current);
//             if (res.size() > 0) {
//                 for (auto &cand : res) {
//                     bag.push_back(cand);
//                 }
//             }
//         }
//         return bag;
//     }
// };
