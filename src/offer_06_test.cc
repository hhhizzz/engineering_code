#include "offer_06.h"

#include "gtest/gtest.h"
#include "utility/list_node.h"

void testPattern(std::vector<int>& input_vector) {
  Solution s;

  auto input = ListNode::Build(input_vector);

  auto result = s.reversePrint(input);
  std::reverse(input_vector.begin(), input_vector.end());

  ASSERT_EQ(result, input_vector);
}

TEST(Examples, Example1) {
  auto input_vector = std::vector<int>{1, 3, 2};

  testPattern(input_vector);
}

TEST(MyCases, case1) {
  auto input_vector = std::vector<int>{1, 3, 2, 4};

  testPattern(input_vector);
}

TEST(MyCases, case2) {
  auto input_vector = std::vector<int>{1};

  testPattern(input_vector);
}

TEST(MyCases, case3) {
  auto input_vector = std::vector<int>{1, 3};

  testPattern(input_vector);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}