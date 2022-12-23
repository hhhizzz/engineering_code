#include "offer_35.h"

#include <utility>
#include <vector>

#include "gtest/gtest.h"

TEST(RandomNode, BuildTest) {
  std::vector<std::pair<int, int>> input = {
      {7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};
  auto head = Node::BuildNode(input);

  auto output = Node::ToVec(head);

  ASSERT_EQ(input, output);
}

template <typename S>
void TestPatternInner(const std::vector<std::pair<int, int>>& input) {
  S s;
  auto head = Node::BuildNode(input);

  auto another_head = s.copyRandomList(head);
  auto output = Node::ToVec(another_head);

  ASSERT_EQ(input, output);
}

void TestPattern(const std::vector<std::pair<int, int>>& input) {
  TestPatternInner<method1::Solution>(input);
  TestPatternInner<method2::Solution>(input);
}

TEST(Examples, Example1) {
  std::vector<std::pair<int, int>> input = {
      {7, -1}, {13, 0}, {11, 4}, {10, 2}, {1, 0}};

  TestPattern(input);
}

TEST(Examples, Example2) {
  std::vector<std::pair<int, int>> input = {{1, 1}, {2, 1}};

  TestPattern(input);
}

TEST(Examples, Example3) {
  std::vector<std::pair<int, int>> input = {{3, -1}, {3, 0}, {3, -1}};

  TestPattern(input);
}

TEST(EdgeCases, NullPointer) {
  std::vector<std::pair<int, int>> input = {};

  TestPattern(input);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}