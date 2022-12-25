#include "offer_58.h"

#include <string>

#include "gtest/gtest.h"

void TestPattern(std::string input, int k, std::string expected) {
  Solution s;
  auto actual = s.reverseLeftWords(input, k);

  ASSERT_EQ(actual, expected);
}

TEST(Examples, Example1) { TestPattern("abcdefg", 2, "cdefgab"); }

TEST(Examples, Example2) { TestPattern("lrloseumgh", 6, "umghlrlose"); }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}