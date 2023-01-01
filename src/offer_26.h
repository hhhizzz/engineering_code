#include "utility/tree_node.h"

class Solution {
 private:
  bool nodeCheck(TreeNode* A, TreeNode* B) {
    if (B == nullptr) {
      return true;
    } else if (A == nullptr) {
      return false;
    }

    if (A->val == B->val) {
      return nodeCheck(A->left, B->left) && nodeCheck(A->right, B->right);
    }
    return false;
  }

 public:
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (A == nullptr || B == nullptr) {
      return false;
    }

    if (nodeCheck(A, B)) {
      return true;
    }

    return isSubStructure(A->left, B) || isSubStructure(A->right, B);
  }
};