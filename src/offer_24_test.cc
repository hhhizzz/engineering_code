#include "offer_24.h"

#include <vector>

#include "gtest/gtest.h"
#include "utility/list_node.h"

void testPattern(const std::vector<int>& input) {
  Solution s;
  auto input_head = ListNode::Build(input);

  auto actual_head = s.reverseList(input_head);
  auto actual = ListNode::ToVec(actual_head);

  std::vector<int> expected(input);
  std::reverse(expected.begin(), expected.end());

  ASSERT_EQ(actual, expected);
}

TEST(Examples, Example1) {
  std::vector<int> input = {1, 2, 3, 4, 5};

  testPattern(input);
}

TEST(EdgeCases, ZeroInput) {
  std::vector<int> input = {};

  testPattern(input);
}

TEST(EdgeCases, oneInput) {
  std::vector<int> input = {1};

  testPattern(input);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}