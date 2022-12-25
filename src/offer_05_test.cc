#include "offer_05.h"

#include <string>

#include "gtest/gtest.h"

void TestPattern(std::string input, std::string expected) {
  Solution s;
  auto actual = s.replaceSpace(input);

  ASSERT_EQ(actual, expected);
}

TEST(Example, Example1) { TestPattern("We are happy.", "We\%20are\%20happy."); }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}