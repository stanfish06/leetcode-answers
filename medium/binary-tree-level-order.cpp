#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
using NodeLev = pair<TreeNode*, int>;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      queue<NodeLev> buf;
      vector<vector<int>> result;
      if (root == nullptr) {
        return result;
      }
      buf.push(make_pair(root, 1));
      while (!buf.empty()) {
        NodeLev& node = buf.front();
        int val = node.first->val;
        int level = node.second;
        if (level > result.size()) {
          result.push_back({val});
        } else {
          result[level-1].push_back(val);
        }
        if (node.first->left != nullptr) {
            buf.push(make_pair(node.first->left,level+1));
        }
        if (node.first->right != nullptr) {
            buf.push(make_pair(node.first->right,level+1));
        }
        buf.pop();
      }
      return result;
    }
};
