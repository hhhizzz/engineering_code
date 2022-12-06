#include <stack>

using std::stack;

/**
 * https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 */
class CQueue {
 private:
  stack<int> stack1_{};
  stack<int> stack2_{};

  void reloadStack2() {
    while (stack1_.size()) {
      auto temp = stack1_.top();
      stack1_.pop();
      stack2_.push(temp);
    }
  }

  int topStack2() {
    // If the stack2 has elements, just use it to return.
    auto result = stack2_.top();
    stack2_.pop();
    return result;
  }

 public:
  CQueue() {}

  void appendTail(int value) { stack1_.push(value); }

  int deleteHead() {
    // If the two stack is empty, return -1
    if (stack1_.size() == 0 && stack2_.size() == 0) {
      return -1;
    }
    if (stack2_.size() != 0) {
      // If there's elements in stack2, just pop from it
      return topStack2();
    } else {
      // Else reload all the elements from stack1 to stack2
      reloadStack2();
      // Now that there must be some elements in stack2, try to use
      return topStack2();
    }
  }
};