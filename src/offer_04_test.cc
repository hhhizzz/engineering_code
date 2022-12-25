#include "offer_04.h"

#include <vector>

#include "gtest/gtest.h"

void TestPattern(std::vector<std::vector<int>>& input, int target,
                 bool expected) {
  Solution s;
  auto actual = s.findNumberIn2DArray(input, target);

  ASSERT_EQ(actual, expected);
}

TEST(Example, Example1) {
  std::vector<std::vector<int>> input = {{1, 4, 7, 11, 15},
                                         {2, 5, 8, 12, 19},
                                         {3, 6, 9, 16, 22},
                                         {10, 13, 14, 17, 24},
                                         {18, 21, 23, 26, 30}};
  int target = 5;
  bool expected = true;

  TestPattern(input, target, expected);
}

TEST(Example, Example2) {
  std::vector<std::vector<int>> input = {{1, 4, 7, 11, 15},
                                         {2, 5, 8, 12, 19},
                                         {3, 6, 9, 16, 22},
                                         {10, 13, 14, 17, 24},
                                         {18, 21, 23, 26, 30}};
  int target = 20;
  bool expected = false;

  TestPattern(input, target, expected);
}

TEST(EdgeCases, emptyMatrix) {
  std::vector<std::vector<int>> input = {};
  int target = 20;
  bool expected = false;

  TestPattern(input, target, expected);
}

TEST(EdgeCases, emptyRow) {
  std::vector<std::vector<int>> input = {
      {},
      {},
  };
  int target = 20;
  bool expected = false;

  TestPattern(input, target, expected);
}

TEST(EdgeCases, oneRow) {
  std::vector<std::vector<int>> input = {
      {-5},
  };
  int target = -5;
  bool expected = true;

  TestPattern(input, target, expected);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}