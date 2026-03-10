#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        visited[i][j] = true;
        if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == '1') {
            dfs(i - 1, j, m, n, grid, visited);
        }
        if (i + 1 < m && !visited[i + 1][j] && grid[i + 1][j] == '1') {
            dfs(i + 1, j, m, n, grid, visited);
        }
        if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == '1') {
            dfs(i, j - 1, m, n, grid, visited);
        }
        if (j + 1 < n && !visited[i][j + 1] && grid[i][j + 1] == '1') {
            dfs(i, j + 1, m, n, grid, visited);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n_cc = 0;  
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(i, j, m, n, grid, visited);
                    n_cc++;
                }
            }
        }
        return n_cc;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> test = {{'1','0','1','1','1'},{'1','1','1','0','1'}};
    int res = sol.numIslands(test);
    cout << res << endl;
}
