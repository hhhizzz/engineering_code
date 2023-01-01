#include "offer_26.h"

#include "gtest/gtest.h"

using std::nullopt;

void TestPattern(std::vector<std::optional<int>>& input_a,
                 std::vector<std::optional<int>>& input_b, bool expected) {
  auto tree_a = TreeNode::VecToTree(input_a);
  auto tree_b = TreeNode::VecToTree(input_b);

  Solution s;
  auto actual = s.isSubStructure(tree_a, tree_b);

  ASSERT_EQ(actual, expected);
}

TEST(Examples, Example1) {
  std::vector<std::optional<int>> input_a{1, 2, 3};
  std::vector<std::optional<int>> input_b{3, 1};

  TestPattern(input_a, input_b, false);
}

TEST(Examples, Example2) {
  std::vector<std::optional<int>> input_a{3, 4, 5, 1, 2};
  std::vector<std::optional<int>> input_b{4, 1};

  TestPattern(input_a, input_b, true);
}

TEST(EdgeCases, LongTree) {
  std::vector<std::optional<int>> input_a{1,       2,       nullopt, 3,
                                          nullopt, nullopt, nullopt, 4};
  std::vector<std::optional<int>> input_b{3, 4};

  TestPattern(input_a, input_b, true);
}

TEST(EdgeCases, LongTreeRight) {
  std::vector<std::optional<int>> input_a{1,       nullopt, 2, nullopt,
                                          nullopt, nullopt, 3};
  std::vector<std::optional<int>> input_b{2, nullopt, 3};

  TestPattern(input_a, input_b, true);
}

TEST(EdgeCases, LongTreeFalse) {
  std::vector<std::optional<int>> input_a{1,       2,       nullopt, 3,
                                          nullopt, nullopt, nullopt, 4};
  std::vector<std::optional<int>> input_b{3, nullopt, 4};

  TestPattern(input_a, input_b, false);
}

TEST(EdgeCases, LongTreeRightFalse) {
  std::vector<std::optional<int>> input_a{1,       nullopt, 2, nullopt,
                                          nullopt, nullopt, 3};
  std::vector<std::optional<int>> input_b{1, 2};

  TestPattern(input_a, input_b, false);
}

TEST(EdgeCases, MatchOneNodeThenFallback) {
  std::vector<std::optional<int>> input_a{4, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<std::optional<int>> input_b{4, 8, 9};

  TestPattern(input_a, input_b, true);
}

TEST(EdgeCases, GapNode) {
  std::vector<std::optional<int>> input_a{1, 0, 1, -4, -3};
  std::vector<std::optional<int>> input_b{1, -4};

  TestPattern(input_a, input_b, false);
}

TEST(EdgeCases, EmptyTree) {
  std::vector<std::optional<int>> input_a{1,       2,       nullopt, 3,
                                          nullopt, nullopt, nullopt, 4};
  std::vector<std::optional<int>> input_b{};

  TestPattern(input_a, input_b, false);
}

TEST(EdgeCases, DoubleEmpty) {
  std::vector<std::optional<int>> input_a{};
  std::vector<std::optional<int>> input_b{};

  TestPattern(input_a, input_b, false);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}