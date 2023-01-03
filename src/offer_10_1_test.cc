#include "offer_10_1.h"

#include "gtest/gtest.h"

int expected[101];

void TestPattern(int input) {
  Solution s;
  auto actual = s.fib(input);

  for (int i = 0; i < 101; i++) {
    if (i < 2) {
      expected[i] = i;
    } else {
      expected[i] = (expected[i - 1] + expected[i - 2]) % 1000000007;
    }
  }

  ASSERT_EQ(actual, expected[input]);
}

TEST(Examples, Example1) { TestPattern(2); }
TEST(Examples, Example2) { TestPattern(5); }

TEST(MyCases, Case1) { TestPattern(8); }

TEST(MyCases, AllCases) {
  for (int i = 0; i <= 100; i++) {
    TestPattern(i);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}