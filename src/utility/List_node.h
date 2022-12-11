#pragma once

#include <vector>

struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x) : val(x) { this->next = nullptr; }

  static ListNode* Build(const std::vector<int>& input) {
    auto pre_head = new ListNode(-1);
    auto pre = pre_head;
    for (auto item : input) {
      auto current = new ListNode(item);
      pre->next = current;
      pre = current;
    }
    auto head = pre_head->next;
    delete pre_head;
    return head;
  }
};

#pragma endregion