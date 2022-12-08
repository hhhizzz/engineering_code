#include <algorithm>
#include <stack>

/**
 * https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/
*/
class MinStack {
 private:
  std::stack<int> storage_{};
  std::stack<int> min_{};

 public:
  MinStack() {}

  void push(int x) {
    storage_.push(x);
    if (min_.size() == 0) {
      min_.push(x);
    } else {
      min_.push(std::min(min_.top(), x));
    }
  }

  void pop() {
    storage_.pop();
    min_.pop();
  }

  int top() { return storage_.top(); }

  int min() { return min_.top(); }
};
