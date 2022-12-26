#include <queue>
#include <vector>

#include "utility/tree_node.h"

using std::vector;

class Solution {
 public:
  vector<int> levelOrder(TreeNode* root) {
    std::queue<TreeNode*> q;
    std::vector<int> result;

    if (root == nullptr) {
      return result;
    }
    q.push(root);
    while (!q.empty()) {
      auto current = q.front();
      q.pop();
      result.push_back(current->val);

      if (current->left != nullptr) {
        q.push(current->left);
      }
      if (current->right != nullptr) {
        q.push(current->right);
      }
    }

    return result;
  }
};