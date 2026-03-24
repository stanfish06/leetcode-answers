// TODO: do it in recursive approach

#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<int> marked;
        int n = prerequisites.size();
        vector<vector<int>> nei(numCourses);
        for (int i = 0; i < n; i++) {
            const auto& prereq = prerequisites[i];
            nei[prereq[0]].push_back(prereq[1]); 
        }
        stack<pair<int,int>> buf;
        for (int i = 0; i < n; i++) {
            const auto& prereq = prerequisites[i];
            if (visited[prereq[0]] == 2) {
                continue;
            }
            buf.push(make_pair(0,prereq[0]));
            pair<int,int> prev = make_pair(-1,-1);
            while (!buf.empty()) {
                pair<int,int> next = buf.top();
                if (visited[next.second] == 1) {
                    if (prev.first > next.first) {
                        visited[prev.second] = 2;
                        prev = next;
                        buf.pop();
                        continue;
                    } else {
                        return false;
                    }
                }
                if (prev.first != -1) {
                    // siblings
                    if (prev.first >= next.first) {
                        visited[prev.second] = 2;
                    }
                }
                visited[next.second] = 1;
                marked.push_back(next.second);
                prev = next;
                bool bottom = true;
                const auto& neighbors = nei[next.second];
                for (auto nn : neighbors) {
                    if (visited[nn] != 2) {
                        buf.push(make_pair(next.first + 1, nn));
                        bottom = false;
                    }
                }
                if (bottom) {
                    visited[next.second] = 2;
                    buf.pop();
                }
            }
            for (int m : marked) {
                if (visited[m] == 1) visited[m] = 2;
            }
            marked.clear();
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> test = {{1,4},{2,4},{3,1},{3,2}};
    bool result = sol.canFinish(5, test);
    if (result) {
        cout << "yes" << endl;
    }
}
