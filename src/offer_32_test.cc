#include "offer_32.h"

#include <vector>

#include "gtest/gtest.h"

void TestPattern(TreeNode* input_tree, const std::vector<int>& expected) {
  Solution s;
  auto actual = s.levelOrder(input_tree);

  EXPECT_EQ(actual, expected);
}

TEST(Examples, Example1) {
  TreeNode* input_tree = new TreeNode(3);
  input_tree->left = new TreeNode(9);
  input_tree->right = new TreeNode(20);
  input_tree->right->left = new TreeNode(15);
  input_tree->right->right = new TreeNode(7);

  std::vector<int> expected = {3, 9, 20, 15, 7};
  TestPattern(input_tree, expected);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}