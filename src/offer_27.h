#include "utility/tree_node.h"

class Solution {
 public:
  TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) {
      return root;
    }

    auto left_temp = mirrorTree(root->right);
    auto right_temp = mirrorTree(root->left);

    root->left = left_temp;
    root->right = right_temp;

    return root;
  }
};