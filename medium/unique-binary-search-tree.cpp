#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        int n_trees = 0;
        for (int i = 0; i < n / 2; i++) {
            int n_left = i;
            int n_right = n - n_left - 1;
            n_trees += numTrees(n_left) * numTrees(n_right);
        } 
        n_trees *= 2;
        if (n % 2 == 1) {
            int n_half = numTrees((n - 1) / 2);
            n_trees += n_half * n_half;
        }
        return n_trees;
    }
};

int main() {
    Solution sol;
    cout << sol.numTrees(4) << endl;
    // cout << sol.numTrees(1) << endl;
}
