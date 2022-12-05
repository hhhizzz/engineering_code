#include "1_two_sum.h"

#include <algorithm>
#include <iostream>

#include "gtest/gtest.h"

void testPattern(std::vector<int>& nums, int target,
                 std::vector<int>& expected) {
  Solution s;
  auto result = s.twoSum(nums, target);

  sort(result.begin(), result.end());

  // Expect equality.
  EXPECT_EQ(result, expected);
}

TEST(Error, UnknownBehavior) {
  std::vector<int> nums = {1, 2, 3, 4};
  int target = 1000;
  std::vector<int> result = {};

  testPattern(nums, target, result);
}

TEST(Examples, Example1) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> result = {0, 1};

  testPattern(nums, target, result);
}

TEST(Examples, Example2) {
  std::vector<int> nums = {3, 2, 4};
  int target = 6;
  std::vector<int> result = {1, 2};

  testPattern(nums, target, result);
}

TEST(Examples, Example3) {
  std::vector<int> nums = {3, 3};
  int target = 6;
  std::vector<int> result = {0, 1};

  testPattern(nums, target, result);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
