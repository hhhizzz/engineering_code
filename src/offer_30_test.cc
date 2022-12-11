#include "offer_30.h"

#include <limits.h>

#include <utility>
#include <vector>

#include "gtest/gtest.h"

void testPattern(const std::vector<std::pair<std::string, int>>& input,
                 const std::vector<int>& expected) {
  MinStack* min_stack = nullptr;

  for (int i = 0; i < input.size(); i++) {
    auto operation = input[i].first;
    if (operation == "MinStack") {
      min_stack = new MinStack();
    } else if (operation == "push") {
      auto input_value = input[i].second;
      min_stack->push(input_value);
    } else if (operation == "getMin") {
      auto actual = min_stack->min();
      ASSERT_EQ(actual, expected[i]);
    } else if (operation == "pop") {
      min_stack->pop();
    } else if (operation == "top") {
      auto actual = min_stack->top();
      ASSERT_EQ(actual, expected[i]);
    }
  }

  delete min_stack;
}

std::vector<int> buildExpected(
    const std::vector<std::pair<std::string, int>>& input) {
  // Use the most understandable way to build result
  std::vector<int> expected(input.size());
  std::vector<int> mock_stack = {};

  for (int i = 0; i < input.size(); i++) {
    auto operation = input[i].first;

    int result = INT_MIN;
    if (operation == "push") {
      auto input_value = input[i].second;
      mock_stack.push_back(input_value);
    } else if (operation == "getMin") {
      if (mock_stack.size() <= 0) {
        std::cerr << "unexpected behaivor, cannot get min from empty stack";
        return {};
      }
      result = INT_MAX;
      for (auto item : mock_stack) {
        if (item < result) {
          result = item;
        }
      }
    } else if (operation == "pop") {
      if (mock_stack.size() <= 0) {
        std::cerr << "unexpected behaivor, cannot pop from an empty stack";
        return {};
      }
      mock_stack.pop_back();
    } else if (operation == "top") {
      if (mock_stack.size() <= 0) {
        std::cerr << "unexpected behaivor, the stack is empty";
        return {};
      }
      result = mock_stack[mock_stack.size() - 1];
    }
    expected[i] = result;
  }

  return expected;
}

TEST(TestTests, TestBuildExpected) {
  std::vector<std::pair<std::string, int>> input = {
      {"MinStack", INT_MIN}, {"push", -2},        {"push", 0},
      {"push", -3},          {"getMin", INT_MIN}, {"pop", INT_MIN},
      {"top", INT_MIN},      {"getMin", INT_MIN}};

  std::vector<int> expected = {INT_MIN, INT_MIN, INT_MIN, INT_MIN,
                               -3,      INT_MIN, 0,       -2};

  auto actual = buildExpected(input);

  ASSERT_EQ(actual, expected);
}

TEST(Examples, Example1) {
  std::vector<std::pair<std::string, int>> input = {
      {"MinStack", INT_MIN}, {"push", -2},        {"push", 0},
      {"push", -3},          {"getMin", INT_MIN}, {"pop", INT_MIN},
      {"top", INT_MIN},      {"getMin", INT_MIN}};

  testPattern(input, buildExpected(input));
}

TEST(EdgeCases, MinInTheBottom) {
  std::vector<std::pair<std::string, int>> input = {
      {"MinStack", INT_MIN}, {"push", -3},        {"push", 2},
      {"push", -1},          {"getMin", INT_MIN}, {"pop", INT_MIN},
      {"top", INT_MIN},      {"getMin", INT_MIN}};

  testPattern(input, buildExpected(input));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}