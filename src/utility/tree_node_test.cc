#include "tree_node.h"

#include "gtest/gtest.h"

TEST(BuildTree, BuildVector) {
  std::vector<std::optional<int>> input{1, std::nullopt, 3};
  auto actual = TreeNode::BuildTree(input);

  ASSERT_EQ(actual->val, 1);
  ASSERT_EQ(actual->left, nullptr);
  ASSERT_EQ(actual->right->val, 3);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}