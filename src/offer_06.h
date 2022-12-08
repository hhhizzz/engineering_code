#include <stack>
#include <vector>

#include "utility/List_node.h"

using std::stack;
using std::vector;

/**
 * https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
*/
class Solution {
 public:
  vector<int> reversePrint(ListNode* head) {
    stack<int> s;
    auto current = head;
    while (current != nullptr) {
      s.push(current->val);
      current = current->next;
    }

    vector<int> result;
    result.reserve(s.size());
    while (s.size() != 0) {
      result.push_back(s.top());
      s.pop();
    }
    return result;
  }
};