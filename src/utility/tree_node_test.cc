#include "tree_node.h"

#include "gtest/gtest.h"

TEST(BuildTree, FromVector) {
  std::vector<std::optional<int>> input{1, std::nullopt, 3};
  auto actual = TreeNode::VecToTree(input);

  ASSERT_EQ(actual->val, 1);
  ASSERT_EQ(actual->left, nullptr);
  ASSERT_EQ(actual->right->val, 3);
}

TEST(TreeCompare, CompareFunction) {
  std::vector<std::optional<int>> input1_vec{1, std::nullopt, 3};
  std::vector<std::optional<int>> input2_vec{1, std::nullopt, 3};

  auto input1 = TreeNode::VecToTree(input1_vec);
  auto input2 = TreeNode::VecToTree(input2_vec);

  ASSERT_EQ(TreeNode::Compare(input1, input2), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}