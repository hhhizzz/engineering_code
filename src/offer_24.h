#include <stack>
#include <vector>

#include "utility/list_node.h"

/**
 * https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    std::stack<ListNode*> s;
    ListNode pre_head_item(-1);
    ListNode* pre_head = &pre_head_item;

    auto current = head;
    while (current != nullptr) {
      s.push(current);
      current = current->next;
    }

    current = pre_head;
    while (!s.empty()) {
      auto next = s.top();
      s.pop();
      current->next = next;
      current = next;
    }
    current->next = nullptr;

    return pre_head->next;
  }
};