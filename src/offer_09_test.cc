#include "offer_09.h"

#include "gtest/gtest.h"
#include "queue"

using std::string;

void testPattern(std::vector<string>& operations, std::vector<int> numbers) {
  std::queue<int> expected_queue;
  CQueue* c_queue;

  for (int i = 0; i < operations.size(); i++) {
    if (operations[i] == "CQueue") {
      c_queue = new CQueue();
    } else if (operations[i] == "appendTail") {
      expected_queue.push(numbers[i]);
      c_queue->appendTail(numbers[i]);
    } else if (operations[i] == "deleteHead") {
      auto actual = c_queue->deleteHead();
      if (expected_queue.size() > 0) {
        auto front = expected_queue.front();
        ASSERT_EQ(actual, front);
        expected_queue.pop();
      } else {
        ASSERT_EQ(actual, -1);
      }
    } else {
      std::cerr << "wrong input";

      delete c_queue;
      return;
    }
  }
  delete c_queue;
}

TEST(Examples, Example1) {
  std::vector<string> operations = {"CQueue", "appendTail", "deleteHead",
                                    "deleteHead", "deleteHead"};
  std::vector<int> numbers = {-1, 3, -1, -1, -1};

  testPattern(operations, numbers);
}

TEST(Examples, Example2) {
  std::vector<string> operations = {"CQueue",     "deleteHead", "appendTail",
                                    "appendTail", "deleteHead", "deleteHead"};
  std::vector<int> numbers = {-1, -1, 5, 2, -1, -1};

  testPattern(operations, numbers);
}

// Test the logic when the stack2 is empty
TEST(EdgeCases, stack2Empty) {
  std::vector<string> operations = {"CQueue",     "appendTail", "appendTail",
                                    "deleteHead", "deleteHead", "deleteHead",
                                    "appendTail", "deleteHead"};
  std::vector<int> numbers = {-1, 1, 2, -1, -1, -1, 3, -1};

  testPattern(operations, numbers);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}