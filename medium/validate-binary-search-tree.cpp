/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool tree2vec(TreeNode* root, int& prev, bool& has_prev) {
        if (root == nullptr) {
            return true;
        }
        bool left = tree2vec(root->left, prev, has_prev);
        if (!left) {
            return false;
        } else {
            if (has_prev) {
                if (root->val <= prev) {
                    return false;
                };
            }
            prev = root->val;
            has_prev = true;
            bool right = tree2vec(root->right, prev, has_prev);
            return right;
        }
    }
    bool isValidBST(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return true;
        }
        int prev = 0;
        bool has_prev = false;
        return tree2vec(root, prev, has_prev);
    }
};

int main() {
    TreeNode n1(0);
    TreeNode n2(-1);

    n1.left = &n2;

    Solution sol;
    cout << sol.isValidBST(&n1) << endl;
}
