#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> intervals_merged;
        sort(
            intervals.begin(), 
            intervals.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        });
        vector<int> interval_tmp;
        for (int i = 0; i < intervals.size(); i++) {
            if (interval_tmp.empty()) {
                interval_tmp = intervals[i];
            } else {
                if (interval_tmp[1] >= intervals[i][0]) {
                    if (interval_tmp[1] < intervals[i][1]) {
                        interval_tmp[1] = intervals[i][1];
                    }
                } else {
                    intervals_merged.push_back(interval_tmp);
                    interval_tmp = intervals[i];
                }
            }
        }
        intervals_merged.push_back(interval_tmp);
        return intervals_merged;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{74,78},{61,63},{46,50},{51,54},{50,50},{60,64},{39,42},{25,27},{91,95},{14,16},{85,85},{5,7},{45,46},{45,49},{66,66},{73,73},{25,26},{25,26},{45,48},{67,67},{63,65},{82,84},{90,92},{47,49},{3,4},{1,5},{64,66},{73,77},{90,94},{20,21},{84,87},{48,49},{80,80},{85,85},{53,55},{21,23},{31,34},{71,75},{62,65},{8,9},{32,33},{7,8},{20,22},{57,57},{51,53},{18,21},{71,75},{49,50},{44,45},{28,31},{38,42},{15,17},{4,7},{48,52},{9,10},{37,38},{69,70},{89,89},{28,29},{52,52},{75,76},{20,21},{90,94},{49,53},{56,59},{84,85},{79,83},{20,21},{90,93},{55,59},{76,80},{40,41},{40,41},{36,39},{79,82},{0,4},{11,11},{1,4},{42,44},{40,40},{32,36},{48,50},{76,77},{0,1},{89,91},{65,68},{51,53},{64,67},{90,92},{11,15},{92,96},{23,24},{36,37},{9,9},{79,80},{80,83},{26,27},{75,79},{2,4},{20,23},{34,36},{61,63}};
    vector<vector<int>> intervals_merged = sol.merge(intervals);
    for (const auto& elem : intervals_merged) {
        cout << "[";
        for (const auto& val : elem) {
            cout << val << ",";
        }
        cout << "]" << endl;
    }
}
