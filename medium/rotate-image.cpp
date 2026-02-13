#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int n_layers = n / 2;
        for (int i = 0; i < n_layers; i++) {
            int width = n - i * 2;
            for (int r = 0; r < (width - 1); r++) {
                int j = i;
                int k = i;
                int dj = 0;
                int dk = 1;
                int n_moved = 0;
                int next = matrix[j][k];
                while(!(j == i + 1 && k == i)) {
                    if (n_moved == width - 1) {
                        if (dk == 1) {
                            dj = 1;
                            dk = 0;
                        } else if (dj == 1) {
                            dj = 0;
                            dk = -1;
                        } else if (dk == -1) {
                            dj = -1;
                            dk = 0;
                        }
                        n_moved = 0;
                    }
                    int next_new = matrix[j + dj][k + dk];
                    matrix[j + dj][k + dk] = next;
                    next = next_new;
                    j += dj;
                    k += dk;
                    n_moved++; 
                }
                matrix[i][i] = next;
            }
        }
    }
    void rotate2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> test = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.rotate2(test);
    int n = test.size();
    for (int i = 0; i < n; i++) {
        cout << "[";
        for (int j = 0; j < n; j++) {
            cout << test[i][j] << ",";
        }
        cout << "]" << endl;
    }
}
