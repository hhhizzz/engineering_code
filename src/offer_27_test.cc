#include "offer_27.h"

#include <iostream>
#include <optional>
#include <vector>

#include "gtest/gtest.h"

TEST(Examples, Example1) {
  std::vector<std::optional<int>> input_vec{4, 2, 7, 1, 3, 6, 9};
  std::vector<std::optional<int>> expected_vec{4, 7, 2, 9, 6, 3, 1};

  auto input = TreeNode::VecToTree(input_vec);
  auto expected = TreeNode::VecToTree(expected_vec);
  Solution s;

  auto actual = s.mirrorTree(input);

  ASSERT_TRUE(TreeNode::Compare(actual, expected));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}